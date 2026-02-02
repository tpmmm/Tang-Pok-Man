public class PowerAdvantageAccount extends Account {
    private SavingsAccount savingsAC;
    private CreditCardAccount creditCardAC;

    public PowerAdvantageAccount(String ano, SavingsAccount sa, CreditCardAccount cr) {
        super(ano);
        savingsAC = sa;
        creditCardAC = cr;
    }
    @Override
    public double getTotal() {
        return savingsAC.getTotal() + creditCardAC.getTotal();
    }
    @Override
    public String toString() {
         return "Power Advantage A/C Number: "+getAccountNumber()+" Balance: $"+String.format("%.2f", getTotal())+
				"\n 1."+savingsAC+
				"\n 2."+creditCardAC;
    }

}
