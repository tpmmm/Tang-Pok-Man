
public class ExInvalidDaysForBL extends Exception {
    public ExInvalidDaysForBL() {
        super("To apply annual leave for 6 days or less, you should use the normal Annual Leave (AL) type.");
    }
}
