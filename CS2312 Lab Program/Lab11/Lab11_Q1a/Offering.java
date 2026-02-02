import java.util.ArrayList;

public class Offering {

    private String semID;

    public Offering(String semID) {
        this.semID = semID;
    }

    public static Offering find(ArrayList<Offering> allOfferings, String s) {
        for (Offering o: allOfferings) {
            if (o.semID.equals(s)) {
                return o;
            }
        }
        return null;
    }

}
