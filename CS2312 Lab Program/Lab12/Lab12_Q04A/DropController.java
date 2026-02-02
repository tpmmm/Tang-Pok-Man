import java.util.List;

public class DropController {
	
	private List<Course> courseList;

	public DropController(List<Course> list) {
		courseList = list;
	}

	public void printCourses() {
		System.out.print("Course List: ");
		for(Course c : courseList) {
			System.out.printf("[%s] ",c);
		}
		System.out.println();
	}
	
	public void process(Course c) {
		/* PLACE YOUR CODE HERE */

		// if(!(courseList.contains(c))){
		// 	return;
		// }


		// for(Course p : c.getPreRequisites()){
		// 	courseList.remove(p);
		// }

		// courseList.add(c);
		courseList.remove(c);
	}
}
