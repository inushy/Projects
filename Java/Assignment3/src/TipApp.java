/**********************************************************
 *                                                        *
 * CSCI 470/502        Assignment 3        Summer 2020    *
 *                                                        *
 * Developer(s): Anushka Verma                            *
 *                                                        *
 * Section: 01                                            *
 *                                                        *
 * Due Date/Time: 07/02/2021 11:59 PM                     *
 *                                                        *
 * Purpose: A Java consoled app that helps to calculate   *
 *          Tips.                                         *
 *                                                        *
 **********************************************************/
import java.util.Scanner; //Importing The Scanner Library
public class TipApp
{
    public static TipCalculator tip = new TipCalculator(); //Creates A Static Object, Because A Non Static Variable
                                                           //Object Cannot Be Reffered From A Static Context
                                                           //For Example, Line 67 Won't Work If Line 20 Is Not Static
    public static void main(String[] args) //main method
    {
        Scanner sc = new Scanner(System.in); //Creates A Scanner
        boolean getTotalBill = true; //Checks If The Total Bill Is True
        while (getTotalBill) //Then It Loops Using The While Loop
        {
            calculateTips(); //Calls The CalculateTips() Method
            System.out.print("Another bill? (y/n): "); //Gets User Input
            String response = sc.nextLine();
            System.out.println(" "); //A New Line Gets Printed
            // Only If User Responds With A Lowercase n Or An Uppercase N
            if (response.equals("n") || response.equals("N"))
            {
                System.out.println("Goodbye!"); //Then It Ends The Program
                getTotalBill = false;
            } // Elsewhere, If User Inputs Lowercase y Or An Uppercase Y
              //Then The Program Continues To Work
        }
    }
    public static void calculateTips() //CalculateTips() Method
    {
        Scanner sc1 = new Scanner(System.in); //Creates A Scanner

        //Instance Variables
        double billAmount;
        int tipPerc;
        int partySize;
        System.out.print("*** Tip Calculator *** \n\n"); //Prints The Title Of The Program
        boolean test = true; //Checks If The Test Is True
        do //A Do While Loop Used to Validate The User Input
        {
            try
            {
                //Gets User Input
                System.out.print("Enter the bill amount: ");
                billAmount = Double.parseDouble(sc1.next()); //Converts String To A Double
                if (billAmount < 0) //If The Bill Amount Is Less Than 0
                {
                    System.out.print("Please enter a valid bill amount.\n\n"); //Then It Prints Out Error Message
                }
                tip.setBillAmount(billAmount); //Else, It Sets The Bill Amount
            }
            catch (NumberFormatException ne)
            {
                System.out.print("Please enter a valid bill amount. \n\n");
                sc1.next();
            }
        }
        while (test != true); //Ends The Loop When THe Condition Is Not True
        do //A Do While Loop Used to Validate The User Input
        {
            try
            {
                //Gets User Input
                System.out.print("Enter your desired tip percentage (20 is 20%): ");
                tipPerc = Integer.parseInt(sc1.next()); //Converts String To A Int
                if (tipPerc < 0) //If The Tip Percentage Is Less Than 0
                {
                    System.out.print("Please enter a valid tip percentage. \n\n"); //Then It Prints Out Error Message
                }
                tip.setTipPerc(tipPerc); //Else, It Sets The Tip Percentage
            }
            catch (NumberFormatException ne)
            {
                System.out.print("Please enter a valid tip percentage. \n\n");
                System.out.print("Enter your desired tip percentage (20 is 20%): ");
                sc1.next();
            }
        }
        while (test != true); //Ends The Loop When THe Condition Is Not True
        do //A Do While Loop Used to Validate The User Input
        {
            try
            {
                //Gets User Input
                System.out.print("Enter the size of your party: ");
                partySize = Integer.parseInt(sc1.next()); //Converts String To A Int
                if (partySize < 1) //If The Party Size Is Less Than 1
                {
                    System.out.print("Please enter a valid party size. \n\n"); //Then It Prints Out Error Message
                    sc1.next();
                }
                System.out.println(" "); //A New Line Gets Printed
                tip.setPartySize(partySize); //Else, It Sets The Party Size
            }
            catch (NumberFormatException ne)
            {
                System.out.print("Please enter a valid party size. \n\n");
                sc1.next();
            }
        }
        while (test != true); //Ends The Loop When THe Condition Is Not True

        //Prints Output
        System.out.print("*** Your Bill ***\n\n");
        System.out.printf("Bill Amount: $%.2f\n", tip.getBillAmount());
        System.out.print("Tip Percentage: " + tip.getTipPerc() + "%\n");
        System.out.print("Party Size: " + tip.getPartySize() + "\n\n");
        System.out.printf("Total Bill (with Tip): $%.2f\n", tip.getTotalBill());
        System.out.printf("Share for Each Individual: $%.2f\n\n", tip.getIndividualShare());
    }
}
