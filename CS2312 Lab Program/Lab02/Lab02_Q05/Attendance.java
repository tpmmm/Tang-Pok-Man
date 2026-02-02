import java.io.*;
import java.util.Scanner;

public class Attendance {

	private int[] students;
	private int[] attendees;

	public Attendance() throws FileNotFoundException {
		students = new int[20];
		attendees = new int[20];
		Scanner sStudents = new Scanner(new File("StudentList.txt"));
		Scanner sAttendees = new Scanner(new File("AttendanceLog.txt"));
        while(sStudents.hasNext()) {
            for (int i = 0; i < 20; i++) {
                students[i] = sStudents.nextInt();
            }
        }
        while(sAttendees.hasNext()) {
            for (int i = 0; i < 20; i++) {
                attendees[i] = sAttendees.nextInt();
            }
        }




		sStudents.close();
		sAttendees.close();
	}

	public boolean isPresent(int id) {
        for (int s = 0; s < 20; s++) {
            if (attendees[s] == id) {
                return true;
            }
        }
        return false;
	}

	public boolean belongToClass(int id) {
        for (int s = 0; s < 20; s++) {
            if (students[s] == id) {
                return true;
            }
        }
        return false;
	}

	// public void listAbsentees() {
	// 	System.out.println("List of absentees:");

	// }

	// public void listWalkIn() {
	// 	System.out.println("List of walk-in students:");


	// }

}