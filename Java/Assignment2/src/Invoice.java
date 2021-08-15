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
public class Invoice //Creates Invoice Class
{
    //Instance Variables
    private String partnum;
    private String partname;
    private int quantity;
    private double priceperitem;
    //Constructor with Parameters
    public Invoice(String partnum, String partname, int quantity, double priceperitem)
    {
        this.partnum = partnum;
        this.partname = partname;
        this.quantity = quantity;
        this.priceperitem = priceperitem;
    }
    //Empty Constructor
    public Invoice()
    {
    }
    //getter setter method for all instance variables
    public String getPartnum()
    {
        return partnum;
    }
    public void setPartnum(String partnum)
    {
        this.partnum = partnum;
    }
    public String getPartname()
    {
        return partname;
    }
    public void setPartname(String partname)
    {
        this.partname = partname;
    }
    public int getQuantity()
    {
        return quantity;
    }
    public void setQuantity(int quantity)
    {
        //If the quanity is not positive then it sets to 0
        if (quantity < 0)
            this.quantity = 0;
    }
    public double getPriceperitem()
    {
        return priceperitem;
    }
    public void setPriceperitem(double priceperitem)
    {
        //If the price per item is not positive then it sets to 0.0
        if (priceperitem < 0.0)
            this.priceperitem = 0.0;
    }
    //Created method that calculates the Invoice Amount
    public double getInvoiceAmount(double price, int qty)
    {
        double total = price * qty;
        return total;
    }
}