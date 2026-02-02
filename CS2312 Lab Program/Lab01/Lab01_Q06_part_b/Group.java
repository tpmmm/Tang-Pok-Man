public class Group {
    private Customer[] cList;
    private int n;

    public Group() {
        cList = new Customer[10];
        n = 0;
    }

    public void add(Customer c) {
        cList[n] = c;
        n++;
    }

    public void spend(int value) {
        for (int i = 0; i < n; i++) {
            cList[i].spend(value / n);
        }
    }
}