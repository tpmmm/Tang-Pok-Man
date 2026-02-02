public class CmdListLeaves implements Command {
    private Employee e;
    public void execute() {
        Company.getInstance().listLeaves();
    }
    @Override
    public void execute(String[] cmdParts) {
        try {
            Company company = Company.getInstance();
            e = company.findEmployee(cmdParts[1]);
            company.listLeavesForEmployee(e);

        } catch (ExEmployeeNotFound e) {
			System.out.println(e.getMessage());
		}
    }


}
