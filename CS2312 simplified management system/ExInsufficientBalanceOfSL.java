public class ExInsufficientBalanceOfSL extends Exception {
    public ExInsufficientBalanceOfSL(int SL) {
        super("Insufficient balance of sick leaves. "+SL+" days left only!");
    }
    
}