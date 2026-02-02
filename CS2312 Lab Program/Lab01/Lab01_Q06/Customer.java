public class Customer {
    private int totalMoney;

    public Customer(int m) 
    {
        this.totalMoney = m;
    }
    public void pay(int p)
    {
        this.totalMoney -= p;
    }
    public int getAmount()
    {
        return totalMoney;
    }
}
