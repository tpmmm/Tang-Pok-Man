import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {

		Scanner in = new Scanner(System.in);

		System.out.print("Please input the file pathname: ");
		String filepathname = in.nextLine();
		
		Scanner inFile = null;
        try {
            inFile = new Scanner(new File(filepathname));
            String cmdLine1 = inFile.nextLine();
            String[] cmdLine1Parts = cmdLine1.split("\\|");
            System.out.println("\n> "+cmdLine1);
            SystemDate.createTheInstance(cmdLine1Parts[1]);
            
            while (inFile.hasNext())		
            {
                String cmdLine = inFile.nextLine().trim();
                
                if (cmdLine.equals("")) continue;  
    
                System.out.println("\n> "+cmdLine);
                
                String[] cmdParts = cmdLine.split("\\|"); 
                
                if (cmdParts[0].equals("hire"))
                    (new CmdHire()).execute(cmdParts);
                if (cmdParts[0].equals("listEmployees"))
                    (new CmdListEmployees()).execute(cmdParts);
                if (cmdParts[0].equals("undo"))
                    RecordedCommand.undoOneCommand();
                if (cmdParts[0].equals("redo"))
                    RecordedCommand.redoOneCommand();
                if (cmdParts[0].equals("startNewDay"))
                    (new CmdStartNewDay()).execute(cmdParts);
                if (cmdParts[0].equals("setupTeam"))
                    (new CmdSetupTeam()).execute(cmdParts);
                if (cmdParts[0].equals("listTeams"))
                    (new CmdListTeams()).execute(cmdParts);
                if (cmdParts[0].equals("addTeamMember"))
                    (new CmdAddTeamMember()).execute(cmdParts);
                if (cmdParts[0].equals("listAllRoles"))
                    (new CmdListAllRoles()).execute(cmdParts);
                if (cmdParts[0].equals("listTeamMembers"))
                    (new CmdListTeamMembers()).execute(cmdParts);
                if (cmdParts[0].equals("applyLeave"))
                    (new CmdApplyLeave()).execute(cmdParts);
                if (cmdParts[0].equals("listLeaves")) {
                    if (cmdParts.length == 1)
                        (new CmdListLeaves()).execute();
                    else
                        (new CmdListLeaves()).execute(cmdParts);
                }

            }
        } catch (FileNotFoundException e) {
            System.out.println("File not found.");
        } catch (InputMismatchException e) {
            System.out.println("File content problem. Program terminated.");
        }
        finally {
            if (inFile!=null) //If it has been opened successfully, close it
            inFile.close();
            in.close();
        }
	}
}
