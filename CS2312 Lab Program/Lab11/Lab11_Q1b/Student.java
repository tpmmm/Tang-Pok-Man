import java.util.ArrayList;
import java.util.Collections;

public class Student {
    private String id;
    private ArrayList<Offering> studies;
    public Student(String id) {
        this.id = id;
        this.studies = new ArrayList<>();
    }
    public void takeCourse(Course course, String semID) {
        Offering o = course.findOffering(semID);
        this.studies.add(o);
        o.addStudens(this);
    }

    public boolean hasBeenClassmateOf(Student s2) {
        return Collections.disjoint(this.studies, s2.studies) == false;
    }
    // public boolean hasBeenClassmateOf(Student s2) {
    //     for (Offering o: this.studies) {
    //         if (s2.hasTaken(o)) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // private boolean hasTaken(Offering oTest) {
    //     return this.studies.contains(oTest);
    // }
    public static String collectIDs(ArrayList<Student> sList) {
        String line = "";
        for (Student s: sList) {
            line += s.id + " ";
        }
        return line;
    }
}
