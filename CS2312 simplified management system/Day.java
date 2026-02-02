public class Day implements Cloneable, Comparable<Day> {
	
	private int year;
	private int month;
	private int day;
    private static final String MonthNames = "JanFebMarAprMayJunJulAugSepOctNovDec";

	//Constructor
	public Day(String sDay) {
        set(sDay);
	}
	
	// check if a given year is a leap year
	static public boolean isLeapYear(int y)
	{
		if (y%400==0)
			return true;
		else if (y%100==0)
			return false;
		else if (y%4==0)
			return true;
		else
			return false;
	}
	static public boolean valid(int y, int m, int d)
	{
		if (m<1 || m>12 || d<1) return false;
		switch(m){
			case 1: case 3: case 5: case 7:
			case 8: case 10: case 12:
					 return d<=31; 
			case 4: case 6: case 9: case 11:
					 return d<=30; 
			case 2:
					 if (isLeapYear(y))
						 return d<=29; 
					 else
						 return d<=28; 
		}
		return false;
	}

	// Return a string for the day like dd MMM yyyy
    @Override
	public String toString() {		
		return day+"-"+ MonthNames.substring((month-1)*3,(month)*3) + "-"+ year;
	}

    public void set(String sDay) {
        String[] sDayParts = sDay.split("-");
        this.day = Integer.parseInt(sDayParts[0]);
        this.year = Integer.parseInt(sDayParts[2]);
        this.month = MonthNames.indexOf(sDayParts[1])/3+1;
    }
    @Override
    public Day clone() {
        Day copy = null;
        try {
            copy = (Day) super.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return copy;
    }

	@Override
	public int compareTo(Day another) {
		int thisDay = this.year*1000+this.month*100+this.day;
		int anotherDay = another.year*1000+another.month*100+another.day;
		return Integer.compare(thisDay, anotherDay);
	}

	public boolean isEndOfAMonth() 
	{
		if (valid(year,month,day+1))
			return false;
		else
			return true;
	}

	public Day next() 
	{
		if (isEndOfAMonth()) {
			month += 1;
			day = 1;
			return new Day(this.toString());
		}
		this.day += 1;
		return new Day(this.toString());
	}

	public int daysDifference(Day another) {
		int count = 0;
		Day current = this.clone();
		while (current.compareTo(another) <= 0) {
			count++;
			if (current.compareTo(another) == 0) break;
			current = current.next();
		}
		return count;
	}

}
