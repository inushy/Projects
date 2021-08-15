/**********************************************************
 *                                                        *
 *  CSCI 470/502        Assignment 4         Summer 2021  *
 *                                                        *
 *  Developer(s):  Anushka Verma                          *
 *                                                        *
 *  Section:  01                                          *
 *                                                        *
 *  Due Date/Time:  07/12/2021 11:59 PM                   *
 *                                                        *
 *  Purpose:  A Java consoled app to help a travel agent  *
 *            present travel destination options to       *
 *            clients.                                    *
 *                                                        *
 **********************************************************/

import java.io.IOException;                                     //Imports IOException library
import java.util.Scanner;                                       //Imports Scanner library
import java.io.File;                                            //Imports IO library

public class MileRedeemerApp                                    //Creates the MileRedeemerApp class
{
    private static String response = "";
    public static void main(String[] args) throws IOException   //Main method
    {
        String filename;                                        //Instance variables
        Scanner keyScan = new Scanner(System.in);               //Creates a new scanner
        System.out.print("Please Enter The File Name You Are Looking For: ");   //Prompt's the user to input filename
        filename = keyScan.nextLine();

        Scanner destinationSpots = new Scanner (new File(filename));    //Creates a new scanner
        MileRedeemer mra = new MileRedeemer();                          //Creates a object to call methods into main
        mra.readDestinations(destinationSpots);                         //Calls the readDestination method
        System.out.println("---------------------------------------------------------------");
        System.out.println("     WELCOME TO THE JAVA AIRLINES MILES REDEMPTION APP     ");
        System.out.println("---------------------------------------------------------------");
        destinationSpots.close();

        System.out.println(" ");                                        //Creates a new line
        System.out.println("List of destination cities your client can travel to:");
        System.out.println(" ");
        String[] places = mra.getCityNames();                           //Calls the getCityNames method
        for (String citySpots : places)
        {
            System.out.println(citySpots);                              //Prints the cityNames
        }

        System.out.println(" ");                                        //Creates a new line
        response = "";
        do {
            response = "";
            System.out.println("---------------------------------------------------------------");
            System.out.print("Please enter your client's accumulated Frequent Flyer Miles: ");
            int miles = Integer.parseInt(keyScan.nextLine());          //User inputs the number of miles they have accumulated
            System.out.println(" ");                                   //Creates a new line

            System.out.print("Please enter your client's month of departure (1-12): ");
            int month = Integer.parseInt(keyScan.nextLine());          //User inputs the number of month they plan to depart
            System.out.println(" ");                                   //Creates a new line

            String [] results = mra.redeemMiles(miles, month);         //Prints the remaining miles the user has left
            for (String s : results)
            {
                System.out.println(s);
            }
            System.out.println(" ");                                    //Creates a new line
            System.out.println("Your client's remaining Frequent Flyer Miles: " + mra.getRemainingMiles());     //Prints the remaining miles after
                                                                                                                //user inputs their miles
            System.out.println("---------------------------------------------------------------");
            System.out.print("Do you want to continue? ");
            response = keyScan.nextLine();                              //Uses the string response we initially created to get a
                                                                        //response input of the user
        } while(response.toLowerCase().equals("y") || response.toLowerCase().equals("yes"));    //deals with lowercase and uppercase y, Yes, etc.

        System.out.println("-----------------------------------------------------------------------");
        System.out.println("     THANK YOU FOR USING THE JAVA AIRLINES MILES REDEMPTION APP     ");
        System.out.println("-----------------------------------------------------------------------");
        keyScan.close();
    }
}
