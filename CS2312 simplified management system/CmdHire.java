public class CmdHire extends RecordedCommand {
    String name;
    int annualLeaves;
    Employee e;

    @Override
    public void execute(String[] cmdParts) {
        try {
            if (cmdParts.length < 3) {throw new ExInsufficientArguments();}
            if (Integer.parseInt(cmdParts[2]) < 0 || Integer.parseInt(cmdParts[2]) > 300) {
                throw new ExALOutOfbound();
            }
            Company company = Company.getInstance();
            name = cmdParts[1];
            if (company.canFindEmployee(name)) {
                throw new ExEmployeeAlreadyExist();
            }
            annualLeaves = Integer.parseInt(cmdParts[2]);
            e = company.createEmployee(name, annualLeaves);
    
            addUndoCommand(this);
            clearRedoList();
            
            System.out.println("Done.");
        } catch (ExInsufficientArguments e) {
            System.out.println(e.getMessage());
        } catch (ExALOutOfbound e) {
            System.out.println(e.getMessage());
        } catch (ExEmployeeAlreadyExist e) {
            System.out.println(e.getMessage());
        }
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
