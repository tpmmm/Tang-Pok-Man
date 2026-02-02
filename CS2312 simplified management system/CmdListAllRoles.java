public class CmdListAllRoles implements Command {
    private Employee e;
    @Override
    public void execute(String[] cmdParts) {
        try {
            if (cmdParts.length < 2) {throw new ExInsufficientArguments();}
            Company company = Company.getInstance();
            e = company.findEmployee(cmdParts[1]);
            e.listAllRoles();
        
        } catch (ExInsufficientArguments e) {
            System.out.println(e.getMessage());
        } catch (ExEmployeeNotFound e) {
			System.out.println(e.getMessage());
		}
    } 
    
}
