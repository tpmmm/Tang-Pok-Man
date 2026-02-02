import java.io.*; //For file I/O
import java.util.*;

public class Table2dMxSumRowCol 
{

	//(1) Add the instance field, nums, for the 2D array here
	// (Answer is in Given_Code.txt!!)
    private int[][] nums;
	private int[] MaxRC;
	
	//Constructor
	public Table2dMxSumRowCol(String filepathname) throws FileNotFoundException //learn exceptions later
	{
		//Part I. Create the 2D array
		// (2) nums = ____________ 
		// (Answer is in Given_Code.txt!!)
        nums = new int[10][10];
		
		//Part II. Perform file reading and insert values into the 2D array
		Scanner inFile;
		inFile = new Scanner(new File(filepathname)); //(3) construct the scanner object for file reading
		// (Answer is in Given_Code.txt!!)
		// 
		//
		// (4) read the file until the end and add values 
		// (Answer is in Given_Code.txt!!)
        while(inFile.hasNext())
        {
            int row, col, value;
            row = inFile.nextInt();
            col = inFile.nextInt();
            value = inFile.nextInt();
            nums[row][col] = value;

        }
		//
		//
		inFile.close();
	}
	
	//
	//Other methods 
	//  (See Given_Code.txt!!)
	//
	public void print() 
    {
		/* For each row, we print the columns in that row.

		   Note: row and column are easily mixed up.
			To avoid careless mistake, readability is important.
			Use meaningful variable names like row,col or r,c, or y,x etc. 
			Do not use i,j. 
		*/

		for (int row=0; row<10; row++) 
		{
			for (int col=0; col<10; col++)
			{
				System.out.print("\t"+nums[row][col]); //separated by tabs
			}
			System.out.println();
		}
	}	
	
    //Return the maximum sum among the rows
	public int getRowSumMax(){
		//Your task: implement this method
        int max = 0;
        for (int r = 0; r < 10; r++)
        {
            int sum = 0;
            for (int c = 0; c < 10; c++)
            {
                sum += nums[r][c];
            }
            if (sum > max) 
            {
                max = sum;
            }
        }		
		return max; //This is temporary!!  You may finish this method in next step.
	}

    //Return the maximum sum among the rows
	public int getColSumMax(){
		//Your task: implement this method
        int max = 0;
        for (int c = 0; c < 10; c++)
        {
            int sum = 0;
            for (int r = 0; r < 10; r++)
            {
                sum += nums[r][c];
            }
            if (sum > max) 
            {
                max = sum;
            }
        }
		return max;//This is temporary!!  You may finish this method in next step.
	}

	public void printAllRowsOfMax() {
		int position = 0;
		int max = -1;
		MaxRC = new int[20];
		for (int r = 0; r < 10; r++)
        {
			int sum = 0;
            for (int c = 0; c < 10; c++)
            {
				sum += nums[r][c];
            }
            if (sum > max) 
            {
				position = 0;
				max = sum;
				MaxRC = new int[20];
				MaxRC[position] = r;
            }
			else if (sum == max) 
			{
				position++;
				MaxRC[position] = r;
			}

		}

		System.out.print(" (row ");
		for (int i = 0; i <= position; i++) 
		{
			if (i > 0) {
				System.out.print(",");
			}
			System.out.print(MaxRC[i]);
		}
		System.out.println(")");
	}

	public void printAllColsOfMax() {
		int position = 0;
		int max = -1;
		MaxRC = new int[20];
		for (int c = 0; c < 10; c++)
        {
			int sum = 0;
            for (int r = 0; r < 10; r++)
            {
				sum += nums[r][c];
            }
            if (sum > max) 
            {
				position = 0;
				max = sum;
				MaxRC = new int[20];
				MaxRC[position] = c;
            }
			else if (sum == max) 
			{
				position++;
				MaxRC[position] = c;
			}

		}
		System.out.print(" (col ");
		for (int i = 0; i <= position; i++) 
		{
			if (i > 0) {
				System.out.print(",");
			}
			System.out.print(MaxRC[i]);
		}
		System.out.print(")");
	}

}
