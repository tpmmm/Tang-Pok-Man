public class ExALOutOfbound extends Exception {
    public ExALOutOfbound() {super("Out of range (Entitled Annual Leaves should be within 0-300)!");} 
    public ExALOutOfbound(String message) {super(message);}
}   

