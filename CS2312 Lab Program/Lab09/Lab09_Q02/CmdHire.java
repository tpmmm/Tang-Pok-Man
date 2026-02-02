public class CmdHire extends RecordedCommand {
    String name;
    int annualLeaves;
    Employee e;

    @Override
    public void execute(String[] cmdParts) {
        Company company = Company.getInstance();
        name = cmdParts[1];
        annualLeaves = Integer.parseInt(cmdParts[2]);
        e = company.createEmployee(name, annualLeaves);

        addUndoCommand(this);
		clearRedoList();
        
		System.out.println("Done.");
    }

    @Override
    public void undoMe() {
        Company company = Company.getInstance();
        company.removeEmployee(e);
        addRedoCommand(this);
    }

    @Override
    public void redoMe() {
        Company company = Company.getInstance();
        company.addEmployee(e);
        addUndoCommand(this);
    }

}
