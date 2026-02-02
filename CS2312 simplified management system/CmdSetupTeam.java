public class CmdSetupTeam extends RecordedCommand {
    private String teamName;
    private String headName;
    private Employee e;
    private Team team;
    @Override
    public void execute(String[] cmdParts) {
        try {
            if (cmdParts.length < 3) {throw new ExInsufficientArguments();}
            Company company = Company.getInstance();
            headName = company.findEmployee(cmdParts[2]).getName();
            e = company.findEmployee(cmdParts[2]);
            if (company.canFindTeam(cmdParts[1])) {throw new ExTeamAlreadyExist();} 
            teamName = cmdParts[1];
            team = company.createTeam(teamName, headName);
            e.AddThisRole(team);
            e.addTeamHeadRole(team);
            
            addUndoCommand(this);
            clearRedoList();
    
            System.out.println("Done.");
        } catch (ExInsufficientArguments e) {
            System.out.println(e.getMessage());
        } catch (ExEmployeeNotFound e) {
			System.out.println(e.getMessage());
		} catch (ExTeamAlreadyExist e) {
            System.out.println(e.getMessage());
        } catch (ExEmployeeAlreadyJoinThisTeam e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void undoMe() {
        Company company = Company.getInstance();
        company.removeTeam(team);
        e.removeRole(team);
        e.removeTeamHeadRole(team);
        addRedoCommand(this);
    }

    @Override
    public void redoMe() {
        try {
            Company company = Company.getInstance();
            team = company.createTeam(teamName, headName);
            e.AddThisRole(team);
            e.addTeamHeadRole(team);
        } catch (ExEmployeeAlreadyJoinThisTeam e) {
            System.out.println(e.getMessage());
        }
        addUndoCommand(this);
    }

}
