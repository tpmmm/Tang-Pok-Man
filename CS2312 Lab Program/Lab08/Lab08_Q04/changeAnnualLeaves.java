public class changeAnnualLeaves extends RecordedCommand {
    private Employee e;
    private int annualLeaves;
    private int preAL;

    @Override
    public void execute(String[] cmdParts) {
        Company company = Company.getInstance();
        e = company.findEmployee(cmdParts[1]);
        preAL = company.findAnnualLeaves(cmdParts[1]);
        annualLeaves = Integer.parseInt(cmdParts[2]);

        e.changeAnnualLeaves(annualLeaves);
        addUndoCommand(this);
        clearRedoList();

        System.out.println("Done.");
    }

    @Override
	public void undoMe()
	{
		e.changeAnnualLeaves(preAL);;
		addRedoCommand(this);
	}
	
	@Override
	public void redoMe()
	{
		e.changeAnnualLeaves(annualLeaves);;
		addUndoCommand(this);
    }
}