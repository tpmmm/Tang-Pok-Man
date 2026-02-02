import java.util.ArrayList;

public class Employee implements Comparable<Employee> {
    private String name;
    private int annualLeaves;

    public Employee(String n, int yle) {
        name = n;
        annualLeaves = yle;
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
}
