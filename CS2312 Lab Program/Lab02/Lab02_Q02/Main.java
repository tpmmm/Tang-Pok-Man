import java.util.*;
public class Main {

	public static void main(String[] args) {
		
        
        System.out.print("Input the width of the multiplication table (2-10): ");
        System.out.println();
		
        Scanner scannerObj = new Scanner(System.in);		
		int width, height;
        width = scannerObj.nextInt();

		System.out.print("Input the height of the multiplication table (2-10): ");
        System.out.println();
        
        height = scannerObj.nextInt();
        scannerObj.close();

        for(int i = 0; i < height; i++) 
        {
            System.out.printf("%5d", i+1);
            System.out.print("|");
            for(int j = 1; j < width; j++)
            {
                System.out.printf("%5d", (i+1)*(j+1));
                System.out.print("|");
            }
            System.out.println();
        }
		/* Notes to students:
			1.  We need a Scanner object to get user input (like Lab01-Q1 in Lab01.pdf Page 3):
			- Add the import statement at the beginning: import java.util.*;
			- Declare a scanner object: Scanner [object variable name];
			- Create a scanner object as: new Scanner(System.in);
			- To read an integer, we call the .nextInt() method: [scanner object].nextInt();
			- Close the scanner object: [scanner object].close();

	 		2.  Learn from Q1: System.out.printf("%5d", x); // Show x, "%" means a field,
								// right aligned, width=5, 
								// d means decimal 
		*/ 

		
	}
}

