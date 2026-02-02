public class Shop {
    private int profit;

    public Shop(int p)
    {
        this.profit = p;
    }
    public Shop earn(Customer c, int e)
    {   
        c.pay(e);
        return new Shop(this.profit += e);
    }
    public int getProfit()
    {
        return profit;
    }
}
