import java.util.ArrayList;
import java.util.Collections;

public class Employee implements Comparable<Employee> {
    private String name;
    private int annualLeaves;
    private ArrayList<Team> allRoles;
    private ArrayList<Team> teamHeads;
    private ArrayList<LeaveRecord> allLeaveRecords;
    private boolean takenBL;
    private int sickLeave;

    public Employee(String n, int yle) {
        name = n;
        annualLeaves = yle;
        allRoles = new ArrayList<>();
        allLeaveRecords = new ArrayList<>();
        teamHeads = new ArrayList<>();
        takenBL = false;
        sickLeave = 135;
    }
    public String getName() {return name;}
    public static Employee searchEmployee(ArrayList<Employee> list, String nameToSearch) {
        /*search the arrayList for the employee with the given name */
        for (Employee e: list) {
            if (e.getName().equals(nameToSearch)) {
                return e;
            }
        }
        return null;
    }
    @Override
    public int compareTo(Employee another) {return this.name.compareTo(another.name);}

    public String toString() {
        return name + " (Entitled Annual Leaves: " + annualLeaves + " days)";
    }

    public void AddThisRole(Team newRole) throws ExEmployeeAlreadyJoinThisTeam {
        for (Team t: allRoles) {
            if (t.getName().equals(newRole.getName())) {
                throw new ExEmployeeAlreadyJoinThisTeam();
            }
        }
        this.allRoles.add(newRole);
        Collections.sort(allRoles);
    }

    public void removeRole (Team t) {
        allRoles.remove(t);
    }

    public void listAllRoles() {
        if (allRoles.size() == 0) {
            System.out.println("No role");
        } else{
            for (Team t: allRoles) {
                if (t.getTeamHeadName().equals(this.name)) {
                    System.out.println(t.getName() + " (Head of Team)");
                } else {
                    System.out.println(t.getName());
                }
            }
        }
    }

    public void addLeaveRecord(LeaveRecord r) {
        this.allLeaveRecords.add(r);
        Collections.sort(allLeaveRecords);
    }

    public void removeLeaveRecord(LeaveRecord r) {
        this.allLeaveRecords.remove(r);
    }

    public void deductAL(int d) {
        annualLeaves -= d;
    }

    public void deductSL(int d) {
        sickLeave -= d;
    } 

    public ArrayList<LeaveRecord> getRecords() {
        return this.allLeaveRecords;
    }

    public void checkOverlappingLeave(Day startDay, Day endDay) throws ExLeaveOverlapped {
        for (LeaveRecord r : allLeaveRecords) {
            r.overlaps(startDay, endDay);
        }
    }

    public void checkValidForAL(int leaveDays) throws ExNotTakeBLYet {
        if (!takenBL && annualLeaves - leaveDays < 7) {
            throw new ExNotTakeBLYet(annualLeaves);
        }
    }
    public void checkBalanceOfLeaves(String leaveType, int d) throws ExInsufficientBalanceOfLeave, ExInsufficientBalanceOfSL {
        if (leaveType.equals("AL") || leaveType.equals("BL")) {
            if (annualLeaves < d) {
                throw new ExInsufficientBalanceOfLeave(annualLeaves);
            }
        }
        if (leaveType.equals("SL")) {
            if (d > sickLeave) {
                throw new ExInsufficientBalanceOfSL(sickLeave);
            }
        }

    }
    public void AddAL(int daysDifference) {
        this.annualLeaves += daysDifference;
    }
    public void AddSL(int daysDifference) {
        this.sickLeave += daysDifference;
    }

    public void markTakenBL() {
        this.takenBL = true;
    }

    public boolean hasTakenBL() {
        return this.takenBL;
    }

    public void resetTakenBL() {
        this.takenBL = false;
    }
    public void checkDaysForAL(int daysDifference) throws ExInvalidDaysForAL {
        if (daysDifference > 6) {
            throw new ExInvalidDaysForAL();
        }    
    }
    public void checkDaysForBL(int daysDifference) throws ExInvalidDaysForBL {
        if (daysDifference < 7) {
            throw new ExInvalidDaysForBL();
        }
    }
    public void addTeamHeadRole(Team team) {
        teamHeads.add(team);
    }
    public void removeTeamHeadRole(Team team) {
        teamHeads.remove(team);
    }
    public int checkNumOfTeamHeads() {
        return teamHeads.size();
    }
    public Team getTeamHeadAt(int index) {
        return teamHeads.get(index);
    }
    public void checkAlreadyApplyLeave(Day startDay, Day endDay) throws ExLeaveOverlapped {
        for (LeaveRecord r : allLeaveRecords) {
            r.overlaps(startDay, endDay);
        }
    }
}
