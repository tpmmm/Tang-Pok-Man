import java.util.ArrayList;

public class Company {
    private ArrayList<Employee> allEmployees;
    private Company() {
        allEmployees = new ArrayList<>();
    }
    private static Company instance = new Company();
    public static Company getInstance() {return instance;}
    public void listEmployee() {
        for (Employee e: allEmployees) {
            System.out.println(e.toString());
        }
    }
    public Employee findEmployee(String name) {
        for (Employee e: allEmployees) {
            if (e.getName().equals(name)) {
                return e;
            }
        }
        return null;
    }
    public int findAnnualLeaves(String name) {
        for (Employee e: allEmployees) {
            if (e.getName().equals(name)) {
                return e.getAL();
            }
        }
        return 0;
    }
    public void addEmployee(Employee e) {
        allEmployees.add(e);
    }
}
