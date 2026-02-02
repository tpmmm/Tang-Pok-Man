
public class ExNotTakeBLYet extends Exception {
    public ExNotTakeBLYet(int remainingDays) {
        super("The annual leave is invalid.\n"+
                "The current balance is "+remainingDays+" days only.\n"+
                "The employee has not taken any block leave yet.\n"+
                "The employee can take at most "+(remainingDays - 7)+" days of non-block annual leave\n"+
                "because of the need to reserve 7 days for a block leave.");
    }
}
