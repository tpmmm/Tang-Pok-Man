public class LeaveRecord_NL extends LeaveRecord {
    private String type;
    public LeaveRecord_NL(Day d1, Day d2, String t) {
        super(d1, d2);
        type = t;
    }
    public String getType() {
        return type;
    }
}
