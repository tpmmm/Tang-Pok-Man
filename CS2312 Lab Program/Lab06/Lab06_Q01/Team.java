import java.util.*;
import java.io.*;

public class Team{
	
	//Instance data field
	private Member[] allMembers;
	
	//Constructor	
	public Team(String filepathname) throws FileNotFoundException
	{
		Scanner inFile = new Scanner(new File(filepathname));
		int tot = inFile.nextInt(); //Read from file: nextInt();
		inFile.nextLine();
		allMembers = new Member[tot];
		for (int i = 0; i < tot; i++) {
			allMembers[i] = new Member(inFile.next());
		}
		inFile.close();
	}
	
	//Return total count of members (simply allMembers.length)
	public int getMemberCount()
	{
		return this.allMembers.length;
	}
	
	//Return a string of listing of all members
	public String getStringOfAllMembers()
	{
		String result="";
		for (Member m: allMembers) //loop for each member
				result+= m.getName()+" ";// allMembers[i].getName()+" ";
		result=result.trim(); //.trim() is for removing leading and trailing spaces 
		return result;
	}

	//Display team contact messages
	public void printTeamContactMessages()
	{
		String allNames=getStringOfAllMembers(); //obtains a string like: "Helena Peter Mary Paul"
		for (Member m: allMembers) //loop for each member
		{
			String name_i=m.getName(); //e.g. "Helena"
			System.out.print("Dear " + name_i);
			String teammates = allNames.replace(name_i, ""); //e.g. "Peter Mary Paul". Use a trick: create a string based on allNames, but remove name_i: allNames.replace(name_i, "");
			System.out.println(",  please contact your teammates: " + teammates); //teammates
		}
	}	
}
