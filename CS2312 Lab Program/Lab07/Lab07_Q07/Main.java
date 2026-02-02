import java.util.*;
import java.io.*;

public class Main{
	
	//Add the method called findAccount
	private static Account findAccount(ArrayList<Account> list, String ano) {
        for (Account a : list) {
            if (a.getAccountNumber().equals(ano)) {
                return a;
            }
        }
        return null;
    }
	
	public static void main(String [] args) throws FileNotFoundException
	{	
		
		Scanner in = new Scanner(System.in);
		
		System.out.print("Please input the file pathname: ");
		String filepathname = in.nextLine();
		
		ArrayList<Account> acs = new ArrayList<>();
		
		Scanner infile = new Scanner(new File(filepathname));
		
		while (infile.hasNextLine()) {
			String line = infile.nextLine();
			Scanner lineScanner = new Scanner(line);
			String ano = lineScanner.next();
			switch (ano.charAt(0)) {
				case '0': case '1': case '2': case '3': case '4': case '5':
				{
					double balance = lineScanner.nextDouble();
					acs.add(new SavingsAccount(ano, balance));
					break;
				}
				case '6': case '7': case '8':
				{
					double balance = lineScanner.nextDouble();
					double creditLimit = lineScanner.nextDouble();
					acs.add(new CreditCardAccount(ano, balance, creditLimit));
					break;
				}
				case '9':
				{
					String sav_no = lineScanner.next();
					String cred_no = lineScanner.next();
					Account sav = findAccount(acs, sav_no);
					Account cred = findAccount(acs, cred_no);
					if (sav instanceof SavingsAccount && cred instanceof CreditCardAccount) {
						acs.add(new PowerAdvantageAccount(ano, (SavingsAccount) sav, (CreditCardAccount) cred));
					}
				}
				default:
					break;
			}
			lineScanner.close();
		}
		
		infile.close();
		System.out.print("\nInput an account number to search: ");
		
		String target = in.next();
		Account result = findAccount(acs, target);
		
		
		if (result!=null)
			System.out.println("\n[Result]\n"+result);
		else
			System.out.println("\n[Result]\nThe account is not found.");
			
		in.close();
	}
}
