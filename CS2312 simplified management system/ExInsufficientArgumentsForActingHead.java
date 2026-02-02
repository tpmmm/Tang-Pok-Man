
public class ExInsufficientArgumentsForActingHead extends Exception {
    public ExInsufficientArgumentsForActingHead(String n) {
        super("Missing input:  Please provide the acting head for " + n);
    }
}
