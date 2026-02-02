public class exchangeSalaries extends RecordedCommand {
    private Employee e1;
    private Employee e2;
    private int e1PrevSalary;
    private int e2PrevSalary;

    @Override
    public void execute(String[] cmdParts) {
        Company company = Company.getInstance();
        e1 = company.findEmployee(cmdParts[1]);
        e2 = company.findEmployee(cmdParts[2]);
        e1PrevSalary = company.findSalary(cmdParts[1]);
        e2PrevSalary = company.findSalary(cmdParts[2]);

        e1.exchangeSalaries(e2PrevSalary);
        e2.exchangeSalaries(e1PrevSalary);
        addUndoCommand(this);
        clearRedoList();

        System.out.println("Done.");
    }

    @Override
    public void undoMe()
    {
        e1.exchangeSalaries(e1PrevSalary);
        e2.exchangeSalaries(e2PrevSalary);
        addRedoCommand(this);
    }

    @Override 
    public void redoMe()
    {
        e1.exchangeSalaries(e2PrevSalary);
        e2.exchangeSalaries(e1PrevSalary);
        addUndoCommand(this);        
    }
    
}