public class ExInvalidDate extends Exception {
    public ExInvalidDate(String systemDate) {
        super("Wrong Date. Leave start date must not be earlier than the system date (" + systemDate + ")!");
    }
}
