public class ExLeaveOverlapped extends Exception {
    private LeaveRecord overlappedLeave;
    
    public ExLeaveOverlapped(LeaveRecord r) {
        super("Leave overlapped: The leave period " + r.getStartDay().toString() + " to " + 
              r.getEndDay().toString() + " [" + r.getType() + "] is found!");
        this.overlappedLeave = r;
    }
    
    public ExLeaveOverlapped(String message) {
        super(message);
    }
    
    public LeaveRecord getOverlappedLeave() {
        return overlappedLeave;
    }
}
