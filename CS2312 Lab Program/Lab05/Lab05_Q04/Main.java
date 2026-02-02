

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner in = new Scanner(System.in);
		System.out.print("Please enter the filename: ");
		String filepathname = in.next();
		PersonnelOffice po = new PersonnelOffice();
		po.loadEmployeeData(filepathname);
		System.out.println("\nTotal count: " + po.getTotal() + " records.\n");
		po.report();
		System.out.print("\nEnter percentage for rasing salary: ");
		double percentage = in.nextDouble();
		po.raiseAllSalaries(percentage);
		po.report();
		in.close();
	}
}
