/**********************************************************
 *                                                        *
 * CSCI 470/502        Assignment 2        Summer 2020    *
 *                                                        *
 * Developer(s): Anushka Verma                            *
 *                                                        *
 * Section: 01                                            *
 *                                                        *
 * Due Date/Time: 06/25/2021 11:59 PM                     *
 *                                                        *
 * Purpose: Familiarizing myself with Java Classes and    *
 *          Objects.                                      *
 *                                                        *
 **********************************************************/
import java.text.DecimalFormat; //importing the DecimalFormat Library
public class InvoiceTest
{
    public static void main(String[] args) //main method
    {
        Invoice i1 = new Invoice("HB-19-2012", "Hammer", 10, 15); //Params for the Invoice 1
        System.out.println("Invoice #1"); //Prints out the Invoice Number
        System.out.println(); // This creates space in between the line

        //Prints details
        System.out.printf("%29s\n", "Part No.: " + i1.getPartnum()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%25s\n", "Part Name: " + i1.getPartname()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%21s\n", "Quantity: " + i1.getQuantity()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%23s\n", "Item Price: " + i1.getPriceperitem()) ;
        System.out.println(); // This creates space in between the line
        DecimalFormat aFormat = new DecimalFormat("$#,###,##0.00"); // This is used here to help with formatting the decimal values
        System.out.print("Invoice Subtotal: ");
        System.out.printf("%s\n", aFormat.format(i1.getInvoiceAmount(i1.getPriceperitem(), i1.getQuantity()))); //Prints The Subtotal
        System.out.println(); // This creates space in between the line
        System.out.println("*********************************");
        Invoice i2 = new Invoice("SC-35-4300", "Phillips Head Screwdriver", 0, 35); //Params for the Invoice 2
        System.out.println("Invoice #2"); //Prints out the Invoice Number
        System.out.println(); // This creates space in between the line

        //Prints details
        System.out.printf("%29s\n", "Part No.: " + i2.getPartnum()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%44s\n", "Part Name: " + i2.getPartname()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%20s\n", "Quantity: " + i2.getQuantity()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%23s\n", "Item Price: " + i2.getPriceperitem()) ;
        System.out.println(); // This creates space in between the line
        DecimalFormat aFormat1 = new DecimalFormat("$#,###,##0.00"); // This is used here to help with formatting the decimal values
        System.out.print("Invoice Subtotal: ");
        System.out.printf("%s\n", aFormat1.format(i2.getInvoiceAmount(i2.getPriceperitem(), i2.getQuantity()))); //Prints The Subtotal
        System.out.println(); // This creates space in between the line
        System.out.println("*********************************");
        Invoice i3 = new Invoice("AB-23-4312", "Cordless Drill", 10, 189); //Params for the Invoice 3
        System.out.println("Invoice #3"); //Prints out the Invoice Number
        System.out.println(); // This creates space in between the line

        //Prints each details for the current Invoice
        System.out.printf("%29s\n", "Part No.: " + i3.getPartnum()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%33s\n", "Part Name: " + i3.getPartname()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%21s\n", "Quantity: " + i3.getQuantity()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%24s\n", "Item Price: " + i3.getPriceperitem()) ;
        System.out.println(); // This creates space in between the line
        DecimalFormat aFormat2 = new DecimalFormat("$#,###,##0.00"); // This is used here to help with formatting the decimal values
        System.out.print("Invoice Subtotal: ");
        System.out.printf("%s\n", aFormat2.format(i3.getInvoiceAmount(i3.getPriceperitem(), i3.getQuantity()))); //Prints The Subtotal
        System.out.println(); // This creates space in between the line
        System.out.println("*********************************");
        Invoice i4 = new Invoice("LT-12-1342", "Light Switch", 30, 0); //Params for the Invoice 4
        System.out.println("Invoice #4"); //Prints out the Invoice Number
        System.out.println(); // This creates space in between the line

        //Prints each details for the current Invoice
        System.out.printf("%29s\n", "Part No.: " + i4.getPartnum()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%31s\n", "Part Name: " + i4.getPartname()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%21s\n", "Quantity: " + i4.getQuantity()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%22s\n", "Item Price: " + i4.getPriceperitem()) ;
        System.out.println(); // This creates space in between the line
        DecimalFormat aFormat3 = new DecimalFormat("$#,###,##0.00"); // This is used here to help with formatting the decimal values
        System.out.print("Invoice Subtotal: ");
        System.out.printf("%s\n", aFormat3.format(i4.getInvoiceAmount(i4.getPriceperitem(), i4.getQuantity()))); //Prints The Subtotal
        System.out.println(); // This creates space in between the line
        System.out.println("*********************************");
        Invoice i5 = new Invoice("CS-04-5340", "Carpenter's Square", 20, 100); //Params for the Invoice 5
        System.out.println("Invoice #5"); //Prints out the Invoice Number
        System.out.println(); // This creates space in between the line

        //Prints each details for the current Invoice
        System.out.printf("%29s\n", "Part No.: " + i5.getPartnum()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%37s\n", "Part Name: " + i5.getPartname()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%21s\n", "Quantity: " + i5.getQuantity()) ;
        System.out.println(); // This creates space in between the line
        System.out.printf("%24s\n", "Item Price: " + i5.getPriceperitem()) ;
        System.out.println(); // This creates space in between the line
        DecimalFormat aFormat4 = new DecimalFormat("$#,###,##0.00"); // This is used here to help with formatting the decimal values
        System.out.print("Invoice Subtotal: ");
        System.out.printf("%s\n", aFormat4.format(i5.getInvoiceAmount(i5.getPriceperitem(), i5.getQuantity()))); //Prints The Subtotal
        System.out.println(); // This creates space in between the line
        System.out.println("*********************************");
    }
}