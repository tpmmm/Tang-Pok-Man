public class CmdSetupTeam extends RecordedCommand {
    private String teamName;
    private String head;
    private Team team;
    @Override
    public void execute(String[] cmdParts) {
        Company company = Company.getInstance();
        teamName = cmdParts[1];
        head = cmdParts[2];
        team = company.createTeam(teamName, head);

        addUndoCommand(this);
        clearRedoList();

        System.out.println("Done.");
    }

    @Override
    public void undoMe() {
        Company company = Company.getInstance();
        company.removeTeam(team);
        addRedoCommand(this);
    }

    @Override
    public void redoMe() {
        Company company = Company.getInstance();
        company.createTeam(teamName, head);
        addUndoCommand(this);
    }

}
