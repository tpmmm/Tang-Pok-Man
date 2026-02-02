public class CmdAddTeamMember extends RecordedCommand {
    private Employee e;
    private Team team;
    private String teamName;
    private String employeeName;
    @Override
    public void execute(String[] cmdParts) {
        try {
            if (cmdParts.length < 3) {throw new ExInsufficientArguments();}
            Company company = Company.getInstance();
            employeeName = cmdParts[2];
            teamName = cmdParts[1];
            e = company.findEmployee(employeeName);
            team = company.findTeam(teamName);
            team.addTeamMember(e);
            e.AddThisRole(team);

            addUndoCommand(this);
            clearRedoList();

            System.out.println("Done.");

        } catch (ExInsufficientArguments e) {
            System.out.println(e.getMessage());
        } catch (ExEmployeeNotFound e) {
			System.out.println(e.getMessage());
		} catch (ExTeamNotFound e) {
            System.out.println(e.getMessage());
        } catch (ExEmployeeAlreadyJoinThisTeam e) {
            System.out.println(e.getMessage());
        }

    }

    @Override
    public void undoMe() {
        team.removeMember(e);
        e.removeRole(team);
        addRedoCommand(this);
    }

    @Override
    public void redoMe() {
        try {
            Company company = Company.getInstance();
            e = company.findEmployee(employeeName);
            team = company.findTeam(teamName);
            team.addTeamMember(e);
            e.AddThisRole(team);
            addUndoCommand(this);
        } catch (ExEmployeeAlreadyJoinThisTeam e) {
            System.out.println(e.getMessage());
        } catch (ExEmployeeNotFound e) {
            System.out.println(e.getMessage());
        } catch (ExTeamNotFound e) {
            System.out.println(e.getMessage());
        }
    }
}