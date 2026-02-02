public class LeaveRecord_AL extends LeaveRecord {
    private String type;
    public LeaveRecord_AL(Day d1, Day d2, String t) {
        super(d1, d2);
        type = t;
    }
    public String getType() {
        return type;
    }
}
