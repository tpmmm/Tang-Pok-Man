public class ExEmployeeAlreadyJoinThisTeam extends Exception {
    public ExEmployeeAlreadyJoinThisTeam() {super("The employee has joined the team already!");} 
    public ExEmployeeAlreadyJoinThisTeam(String message) {super(message);}
}