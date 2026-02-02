public class Cat extends Animal {
    public Cat(String n) {super(n);}
    @Override
    public int getRunSpeed() {
        return 5;
    }
    @Override
    public String getMyName() {
        return getName();
    }

    public void chase(Runnable target) {
        if (this.getRunSpeed() > target.getRunSpeed()) {
            System.out.printf("%s Catches %s\n", this.getMyName(), target.getMyName());
        } else {
            System.out.printf("%s Cannot Catch %s\n", this.getMyName(), target.getMyName());

        }
    }
}