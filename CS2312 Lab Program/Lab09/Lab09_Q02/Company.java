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
}
