public abstract class LeaveRecord implements Comparable<LeaveRecord> {
    private Day startDay;
    private Day endDay;

    @Override
    public int compareTo(LeaveRecord another) {
        return this.startDay.compareTo(another.startDay);
    }

    public LeaveRecord(Day d1, Day d2) {
        startDay = d1;
        endDay = d2;
    }

    public Day getStartDay() {
        return startDay;
    }
    public Day getEndDay() {
        return endDay;
    }

    public abstract String getType();

    public boolean overlaps(Day otherStart, Day otherEnd) throws ExLeaveOverlapped {
        if (otherStart.compareTo(endDay) <= 0 && otherEnd.compareTo(startDay) >= 0) {
            throw new ExLeaveOverlapped(this);
        }
        return false;
    }

    public int getDaysCount() {
        return startDay.daysDifference(endDay);
    }

}
