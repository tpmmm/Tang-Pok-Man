import java.util.ArrayList;

public class Offering {

    private String semID;
    private ArrayList<Student> sList;

    public Offering(String semID) {
        this.semID = semID;
        sList = new ArrayList<>();
    }

    public static Offering find(ArrayList<Offering> allOfferings, String s) {
        for (Offering o: allOfferings) {
            if (o.semID.equals(s)) {
                return o;
            }
        }
        return null;
    }

    public static void listStudents(ArrayList<Offering> allOfferings) {
        for (Offering o: allOfferings) {
            o.list();
        }
    }

    private void list() {
        String line = this.semID+": ";
        line += Student.collectIDs(sList);
        System.out.println(line);
    }

    public void addStudens(Student student) {
        sList.add(student);
   }

}
