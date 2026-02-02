public class ExEmployeeNotInThisTeam extends Exception {
    public ExEmployeeNotInThisTeam(Employee e, Team t) {
        super("Employee ("+e.getName()+") not found for "+t.getName()+"!");
    }
}
