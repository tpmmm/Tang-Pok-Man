import java.util.ArrayList;
import java.util.Collections;

public class Company {
    private ArrayList<Employee> allEmployees;
    private ArrayList<Team> allTeams;
    private static Company instance = new Company();
    private Company() {
        allEmployees = new ArrayList<>();
        allTeams = new ArrayList<>();
    }

    public static Company getInstance() {
        return instance;
    }
    public void listTeams() {Team.list(allTeams);}

    public void listTeamMembers() {
        Team.listMembers(allTeams);
    }

    public ArrayList<Team> getAllTeams() {
        return allTeams;
    }

    public Employee createEmployee(String n, int yle) {
        Employee e = new Employee(n, yle);
        allEmployees.add(e);
        Collections.sort(allEmployees); // allEmployees
        return e; // the return value is useful for later undoable command.
    }

    public Team createTeam(String tn, String n) {
        Employee e = Employee.searchEmployee(allEmployees, n);
        Team t = new Team(tn, e);
        allTeams.add(t);
        Collections.sort(allTeams); // allTeams
        return t; // the return value is useful for later undoable command.
    }

    public void removeTeam(Team t) {
        allTeams.remove(t);
    }

    public void addEmployee(Employee e) {
        allEmployees.add(e);
        Collections.sort(allEmployees);
    }

    public void removeEmployee(Employee e) {
        allEmployees.remove(e);
    }

    public void listEmployee() {
        for (Employee e: allEmployees) {
            System.out.println(e.toString());
        }
    }

    public Employee findEmployee(String name) throws ExEmployeeNotFound {
        for (Employee e: allEmployees) {
            if (e.getName().equals(name)) {
                return e;
            }
        }
        throw new ExEmployeeNotFound();
    }

    public Team findTeam(String teamName) throws ExTeamNotFound {
        for (Team t: allTeams) {
            if (t.getName().equals(teamName)) {
                return t;
            }
        }
        throw new ExTeamNotFound();
    } 

    public boolean canFindTeam(String teamName) throws ExTeamAlreadyExist {
        for (Team t: allTeams) {
            if (t.getName().equals(teamName)) {
                throw new ExTeamAlreadyExist();
            }
        }
        return false;
    }

    public boolean canFindEmployee(String name) throws ExEmployeeAlreadyExist {
        for (Employee e: allEmployees) {
            if (e.getName().equals(name)) {
                throw new ExEmployeeAlreadyExist();
            }
        }
        return false;
    }

    public void listLeaves() {
        for (Employee e: allEmployees) {
            System.out.println(e.getName()+":");
            if (e.getRecords().size() == 0) {
                System.out.println("No leave record");
            } else {
                for (LeaveRecord r: e.getRecords()) {
                    System.out.println(r.getStartDay().toString()+" to "+r.getEndDay()+" ["+r.getType()+"]");
                }
            }
        }
    }

    public void listLeavesForEmployee(Employee e) {
        if (e.getRecords().size() == 0) {
            System.out.println("No leave record");
        } else {
            for (LeaveRecord r: e.getRecords()) {
                System.out.println(r.getStartDay().toString()+" to "+r.getEndDay()+" ["+r.getType()+"]");
            }
        }
    }
}
