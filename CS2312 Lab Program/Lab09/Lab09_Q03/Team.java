import java.util.ArrayList;

public class Team implements Comparable<Team> {
    private String teamName;
    private Employee head;
    private Day dateSetUp;
    
    public Team(String n, Employee hd) {
        teamName = n;
        head = hd;
        dateSetUp = SystemDate.getInstance().clone();
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
}
