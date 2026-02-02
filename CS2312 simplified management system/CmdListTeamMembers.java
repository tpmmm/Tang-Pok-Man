public class CmdListTeamMembers implements Command {

    @Override
    public void execute(String[] cmdParts) {
        Company.getInstance().listTeamMembers();
    }
     
}