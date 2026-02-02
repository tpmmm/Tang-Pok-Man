public class ExAssigningOnLeaveEmployee extends Exception {
    public ExAssigningOnLeaveEmployee(Employee e, LeaveRecord r) {
        super(e.getName() + " is on leave during " + r.getStartDay().toString() + " to " + r.getEndDay().toString() + " [" + r.getType() + "]!");
    }
}
