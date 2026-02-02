public class LeaveRecord_SL extends LeaveRecord {
    private String type;
    public LeaveRecord_SL(Day d1, Day d2, String t) {
        super(d1, d2);
        type = t;
    }
    public String getType() {
        return type;
    }
}
