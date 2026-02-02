import java.util.*;

import java.io.*;

public class Team {
	
	//Instance data field
	private ArrayList<Member> allMembers;
	//Constructor	
	public Team(String filepathname) throws FileNotFoundException
	{
		Scanner inFile = new Scanner(new File(filepathname));
		int tot = inFile.nextInt(); //Read from file: nextInt();
		inFile.nextLine();
		allMembers = new ArrayList<Member>();
		for (int i = 0; i < tot; i++) {
			String name = inFile.next();
			char roleType = inFile.next().charAt(0); //Read a string of one character and get that character: inFile.next().charAt(0);			
			Role r;		
			if (roleType=='l')	r = new RLeader(); //create a RLeader role object: new RLeader();
			else if (roleType=='n')	r = new RNormalMember(); //create a RNormalMember role object: new RNormalMember();
			else r = new RDisappeaered();
			allMembers.add(new Member(name, r)); // Create a member object: new ;
		}
		inFile.close();
	}
	
	//Return total count of members (simply allMembers.length)
	public int getMemberCount()
	{
		return this.allMembers.size();
	}
	
	//Return a string of listing of all members
	public String getStringOfAllMembers()
	{
		String result="";
		for (Member m: allMembers) //loop for each member
				result+= m.getNameAndRole()+" ";// allMembers[i].getName()+" ";
		result=result.trim(); //.trim() is for removing leading and trailing spaces 
		return result;
	}

	//Display team contact messages
	public void printTeamContactMessages()
	{
		for (Member m: allMembers)
		{
			String name_i = m.getName(); //e.g. "Helena"
			System.out.print("Dear " + name_i + ",  ");
			String msg = m.getRole().genTeamContactMsg(this); // allMembers[i].getRole().genTeamContactMsg(this);
			System.out.println(msg); // msg
		}
	}	

	public Member getLeader()
	{
		for (Member m: allMembers)
			if (m.getRole() instanceof RLeader) //checking:  allMembers[i].getRole() instanceof RLeader
				return m;
		return null; //not found
	}	

	public String getStringOfNormalMembers()
	{
		String result="";
		for (Member m: allMembers)
			if (m.getRole() instanceof RNormalMember)
				result+= m.getNameAndRole()+" ";
		result=result.trim(); //.trim() is for removing leading and trailing spaces 
		return result;
	}

	public Member findMember(String name) {
		for (Member m: allMembers) {
			if (m.getName().equals(name)) {
				return m;
			}
		}
		return null;
	}

	public void changeLeader(String newLeaderName) {
		Member originalLeader = getLeader();
		originalLeader.setRole(new RNormalMember());
		findMember(newLeaderName).setRole(new RLeader());
	}

}
