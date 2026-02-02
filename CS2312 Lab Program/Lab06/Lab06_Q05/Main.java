import java.util.*;
import java.io.*;

public class Main{

	public static void main(String [] args) throws FileNotFoundException
	{	
		Scanner in = new Scanner(System.in);
		
		System.out.print("Please input the file pathname of each team: ");
		String input = in.nextLine();
		ArrayList<Team> teams;
		teams = new ArrayList<Team>();
		Scanner pathScanner = new Scanner(input);
		
		while (pathScanner.hasNext()) {
			String filepathname = pathScanner.next();
			Team t = new Team(filepathname);
			teams.add(t);
		}
		pathScanner.close();
		// System.out.printf(
		// 	"\nThere are %d members in the team: %s\n\n", 
		// 	t.getMemberCount(), t.getStringOfAllMembers()); //call Team methods to get the results: getMemberCount, getStringOfAllMembers
		
		// System.out.println("Messages for team contacts: ");
		// t.printTeamContactMessages(); //call Team method: printTeamContactMessages
		
		// System.out.print("Enter new leader: ");
		// String newLeaderName = in.nextLine();
		// t.changeLeader(newLeaderName);
		// System.out.printf("\nResult: %s", t.getStringOfAllMembers());
		System.out.println("Listing of teams:");
		for (int i = 0; i < teams.size(); i++) {
            Team t = teams.get(i);
            System.out.printf("[Team %d] %d members: %s\n", (i + 1), t.getMemberCount(), t.getStringOfAllMembers());
        }
		System.out.print("Enter a name for searching: ");
		String name = in.nextLine();
		boolean found = false;
		for (int i = 0; i < teams.size(); i++) {
            Team t = teams.get(i);
            Member m = t.findMember(name);
            if (m != null) {
                System.out.printf("Result: %s is %s in Team %d\n", name, m.getRoleDescription(), (i + 1));
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Result: Not found");
        }
		in.close();
	}
}
