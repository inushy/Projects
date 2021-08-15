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

public class Destination        //Creates Destination class
{
    //Instance variables
    private String dName;
    private int mileage;
    private int offSeasonMileage;
    private int mileUpgrade;
    private int startMonth;
    private int endMonth;
    private boolean isUpgraded;

    //Constructor
    public Destination()
    {
        dName = "";
        mileage = 0;
        offSeasonMileage = 0;
        mileUpgrade = 0;
        startMonth = 1;
        endMonth = 2;
        isUpgraded = false;
    }

    //Parametrized constructor
    public Destination(String dName, int mileage, int offSeasonMileage, int mileUpgrade, int startMonth, int endMonth)
    {
        this.dName = dName;
        this.mileage = mileage;
        this.offSeasonMileage = offSeasonMileage;
        this.mileUpgrade = mileUpgrade;
        this.startMonth = startMonth;
        this.endMonth = endMonth;
        this.isUpgraded = false;
    }

    //Our getter, setters
    public String getdName()
    {
        return dName;
    }

    public void setdName(String dName)
    {
        this.dName = dName;
    }

    public int getMileage()
    {
        return mileage;
    }

    public void setMileage(int mileage)
    {
        this.mileage = mileage;
    }

    public int getOffSeasonMileage()
    {
        return offSeasonMileage;
    }

    public void setOffSeasonMileage(int offSeasonMileage)
    {
        this.offSeasonMileage = offSeasonMileage;
    }

    public int getMileUpgrade()
    {
        return mileUpgrade;
    }

    public void setMileUpgrade(int mileUpgrade)
    {
        this.mileUpgrade = mileUpgrade;
    }

    public int getStartMonth()
    {
        return startMonth;
    }

    public void setStartMonth(int startMonth)
    {
        this.startMonth = startMonth;
    }

    public int getEndMonth()
    {
        return endMonth;
    }

    public void setEndMonth(int endMonth)
    {
        this.endMonth = endMonth;
    }

    public boolean getIsUpgraded()
    {
        return isUpgraded;
    }

    public void setIsUpgraded(boolean isUpgraded)
    {
        this.isUpgraded = isUpgraded;
    }
}