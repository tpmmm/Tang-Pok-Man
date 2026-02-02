public class AgeGroupCounter extends Counter {
    private int lowerBound;
    private int upperBound;
    public AgeGroupCounter(int a1, int a2) {
		lowerBound = a1;
        upperBound = a2;
	}
	
	public void countData(Record r) {
		if (r.getAge() >= lowerBound && r.getAge() <= upperBound)
			super.countData(r);
	}
    public String toString(){
	    return String.format("[Age %d to %d] Count = %d", lowerBound, upperBound, super.getCount());
    }
     
}