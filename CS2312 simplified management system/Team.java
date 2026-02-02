import java.util.ArrayList;
import java.util.Collections;

public class Team implements Comparable<Team> {
    private String teamName;
    private Employee head;
    private ArrayList<Employee> teamMembers;
    private Day dateSetUp;
    private ArrayList<String> actingHeads;
    
    public Team(String n, Employee hd) {
        teamMembers = new ArrayList<>();
        teamName = n;
        head = hd;
        teamMembers.add(hd);
        actingHeads = new ArrayList<>();
        dateSetUp = SystemDate.getInstance().clone();
    }

    public String getName() {
        return this.teamName;
    }

    public String getTeamHeadName() {
        return head.getName();
    }

    public static void list(ArrayList<Team> list)
    {
    //Learn: "-" means left-aligned
    System.out.printf("%-30s%-10s%-13s\n", "Team Name", "Leader", "Setup Date");
    for (Team t : list)
    System.out.printf("%-30s%-10s%-13s\n", t.teamName, t.head.getName(), t.dateSetUp); //display t.teamName, etc..
    }

    @Override
    public int compareTo(Team another) { return this.teamName.compareTo(another.teamName);}

    public static void listMembers(ArrayList<Team> allTeams) {
        for (Team t: allTeams) {
            System.out.println(t.teamName+":");
            for (Employee e: t.teamMembers) {
                if (t.getTeamHeadName().equals(e.getName())) {
                    System.out.println(e.getName() + " (Head of Team)");
                } else {
                    System.out.println(e.getName());
                }
            }
            if (t.actingHeads.size() > 0) {
                System.out.println("Acting heads:");
                ArrayList<String> sortedHeads = new ArrayList<>(t.actingHeads);
                Collections.sort(sortedHeads, (s1, s2) -> {
                    String date1 = s1.substring(0, s1.indexOf(" to"));
                    String date2 = s2.substring(0, s2.indexOf(" to"));
                    Day d1 = new Day(date1);
                    Day d2 = new Day(date2);
                    return d1.compareTo(d2);
                });
                for (String s : sortedHeads) {
                    System.out.println(s);
                }
            }
            System.out.println();
        }

    }

    public void addTeamMember(Employee newMember) throws ExEmployeeAlreadyJoinThisTeam {
        for (Employee e: teamMembers) {
            if (e.getName().equals(newMember.getName())) {
                throw new ExEmployeeAlreadyJoinThisTeam();
            }
        }     
        this.teamMembers.add(newMember);
        Collections.sort(teamMembers);
    }

    public void removeMember(Employee e) {
        this.teamMembers.remove(e);
    }

    public void addActingHead(Employee actingHead, Day start, Day end) {
        String entry = start.toString() + " to " + end.toString() + ": " + actingHead.getName();
        if (!this.actingHeads.contains(entry)) {
            this.actingHeads.add(entry);
        }
    }

    public void removeActingHead(Employee actingHead, Day start, Day end) {
        String entry = start.toString() + " to " + end.toString() + ": " + actingHead.getName();
        while (this.actingHeads.remove(entry)) {
        }
    }

    public String getActingHeadOverlap(Employee e, Day otherStart, Day otherEnd) {
        for (String entry : actingHeads) {
            String suffix = ": " + e.getName();
            if (entry.endsWith(suffix)) {
                String dates = entry.substring(0, entry.length() - suffix.length()).trim();
                String[] parts = dates.split(" to ");
                if (parts.length == 2) {
                    Day s = new Day(parts[0]);
                    Day ed = new Day(parts[1]);
                    if (otherStart.compareTo(ed) <= 0 && otherEnd.compareTo(s) >= 0) {
                        return dates; 
                    }
                }
            }
        }
        return null;
    }

    public boolean hasMember(Employee e) {
        for (Employee m : teamMembers) {
            if (m.getName().equals(e.getName())) return true;
        }
        return false;
    }
}
