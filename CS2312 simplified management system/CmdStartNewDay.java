public class CmdStartNewDay extends RecordedCommand {
    String prevDay = SystemDate.getInstance().toString();
    String newDay;
    @Override
    public void execute(String[] cmdParts) {
        newDay = cmdParts[1];
        SystemDate.updateDate(newDay);

        addUndoCommand(this);
		clearRedoList();

        System.out.println("Done.");
    }

    @Override
    public void undoMe() {
        SystemDate.updateDate(prevDay);        
        addRedoCommand(this);
    }

    @Override
    public void redoMe() {
        SystemDate.updateDate(newDay);
        addUndoCommand(this);
    }

}
