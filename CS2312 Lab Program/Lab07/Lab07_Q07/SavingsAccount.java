public class SavingsAccount extends Account{
    private double balance;
    public SavingsAccount(String ano, double bal) {
        super(ano);
        balance = bal;
    }
    @Override
    public double getTotal() {
        return balance;
    }
    @Override
    public String toString() {
        return "Savings A/C Number: "+getAccountNumber()+
		" Balance: $"+String.format("%.2f",balance);

    }
}
