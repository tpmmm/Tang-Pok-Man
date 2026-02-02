public class Employee {

    private String name;
    private int salary;
    private int annualLeaves;
    public Employee(String n, int s, int al) {
        name=n; salary=s; annualLeaves=al;
    }

    public String getName() {return name;}

    public void addSalary(int inc) {salary+=inc;}
    @Override
    public String toString() {
        return name + " ($"+salary+", "+annualLeaves+" days)";
     }
}