public class CreditCardAccount extends Account {
    private double balance;
	private double creditLimit;
	public CreditCardAccount(String ano, double bal, double climit) {
		super(ano);
		balance = bal;
		creditLimit = climit;
	}
	@Override
	public double getTotal() {
		return -balance;
	}
	@Override
	public String toString() 
	{
		return "Credit Card A/C Number: "+getAccountNumber()+
				" Balance: $"+String.format("%.2f",balance)+
				" Credit limit: $"+String.format("%.2f",creditLimit);
	}
}
