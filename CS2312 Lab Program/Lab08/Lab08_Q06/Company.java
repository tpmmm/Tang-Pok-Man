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
    public int findSalary(String name) {
        for (Employee e: allEmployees) {
            if (e.getName().equals(name)) {
                return e.getSalary();
            }
        }
        return 0;
    }
    public String findName(String name) {
        for (Employee e: allEmployees) {
            if (e.getName().equals(name)) {
                return e.getName();
            }
        }
        return null;
    }
    public int findEmployeePlace(String name) {
        int p = 0;
        for (Employee e: allEmployees) {
            if (e.getName().equals(name)) {
                return p;
            }
            p++;
        }
        return 0;
    }
    public void fire(int p) {
        allEmployees.remove(p);
    }
    public void addEmployee(Employee e) {
        allEmployees.add(e);
    }
}
