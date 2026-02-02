public class fire extends RecordedCommand{
    private Employee e;
    private int place;
    private String name;

    @Override
    public void execute(String[] cmdParts) {
        Company company = Company.getInstance();
        e = company.findEmployee(cmdParts[1]);
        name = company.findName(cmdParts[1]);
        place = company.findEmployeePlace(cmdParts[1]);

        company.fire(place);
        addUndoCommand(this);
        clearRedoList();

        System.out.println("Done.");
    }

    @Override
	public void undoMe()
	{
        Company company = Company.getInstance();
		company.addEmployee(e);
		addRedoCommand(this);
	}
	
	@Override
	public void redoMe()
	{
        Company company = Company.getInstance();
        place = company.findEmployeePlace(name);
		company.fire(place);
		addUndoCommand(this);
    }
}
