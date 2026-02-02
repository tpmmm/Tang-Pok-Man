
public class Customer {
    private int totalMoney;
    public Customer(int m) {
        totalMoney = m;
    }

    public int getAmount() {
        return totalMoney;
    }

    public void spend(int value) {
        totalMoney -= value;
    }

}
