import java.util.ArrayList;

public class Course {
    private String code;
    private ArrayList<Offering> allOfferings;

    public Course(String code) {
        this.code = code;
        this.allOfferings = new ArrayList<>();
    }

    public void addOffering(String semID) {
        Offering o = new Offering(semID);
        this.allOfferings.add(o);
    }

    public Offering findOffering(String semID) {
        return Offering.find(allOfferings, semID);
    }

    public void listStudents() {
        Offering.listStudents(allOfferings);
    }
}
