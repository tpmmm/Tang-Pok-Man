public class Main {

	public static void main(String[] args) {
		SystemDate.createTheInstance("01-Jan-2025");

		Company co = Company.getInstance();
		co.createEmployee("Bob", 30);
		co.createEmployee("John", 30);
		co.createEmployee("Grace", 30);

		co.createTeam("Customer Relationship Team", "Bob");
		co.createTeam("Strategic Planning Team", "John");

		SystemDate.getInstance().set("01-Feb-2025"); // set system date to 1/2/2025
		co.createTeam("Clerical Support Team", "Grace");

		co.listTeams();
	}
}
