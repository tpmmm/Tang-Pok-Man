public class ExInsufficientBalanceOfLeave extends Exception {
    public ExInsufficientBalanceOfLeave(int annualLeaves) {
        super("Insufficient balance of annual leaves. "+annualLeaves+" days left only!");
    }
    
}
