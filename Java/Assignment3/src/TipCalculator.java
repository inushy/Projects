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
public class TipCalculator //Creates TipCalculator Class
{
    //Instance Variables
    private double billAmount;
    private int tipPerc;
    private int partySize;
    //Constructor With Parameters
    public TipCalculator(double billAmount, int tipPerc, int partySize)
    {
        this.billAmount = 0; //Defaults Bill Amount To 0
        this.tipPerc = 20; //Defaults Tip Percentage To 20
        this.partySize = 1; //Defaults Party Size To 1
    }
    //Empty Constructor
    public TipCalculator()
    {
    }
    //getter setter method for all instance variables
    public double getBillAmount()
    {
        return billAmount;
    }
    public void setBillAmount(double amount)
    {
        this.billAmount = amount;
    }
    public int getTipPerc()
    {
        return tipPerc;
    }
    public void setTipPerc(int tip)
    {
        this.tipPerc = tip;
    }
    public int getPartySize()
    {
        return partySize;
    }
    public void setPartySize(int size)
    {
        this.partySize = size;
    }
    //Created method that calculates the Total Bill Amount
    public double getTotalBill()
    {
        return (getBillAmount() + ((getBillAmount() * getTipPerc()) / 100)); //It will calculate the Tip
                                                                             //(based on the bill amount user inputs) and then adds the
                                                                             //total bill amount to get the Grand Total which will be bill
                                                                             //amount + tip.
    }
    //Created method that calculates the Total Share Amount
    public double getIndividualShare()
    {
        return ((getTotalBill()) / (getPartySize())); // The Grand Total Gets Divided By The Party Size
    }
}