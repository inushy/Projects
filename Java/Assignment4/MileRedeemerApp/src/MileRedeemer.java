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

import java.io.IOException;                                 //Imports IOException library
import java.util.ArrayList;                                 //Imports ArrayList library
import java.util.Comparator;                                //Imports Comparator library
import java.util.Scanner;                                   //Imports Scanner library
import java.util.Arrays;                                    //Imports Array library

class MileageComparator implements Comparator<Destination>  //Comparator class to sort the array's
{
    @Override
    public int compare(Destination d1, Destination d2)
    {
        return (d2.getMileage() - d1.getMileage());
    }
}

public class MileRedeemer                                   //Mile Redeemer class
{
    private Destination[] destinationArray;                 //An array that holds destination objects
    private int remainingMiles = 0;

    public void readDestinations(Scanner fileScanner) throws IOException  //reads the txt file and stores in destinationArray
    {
        ArrayList<Destination> destinationList = new ArrayList<Destination>();  //Stores the created destinations after reading from
                                                                                // the file into an Array List
        //Instance variables
        String destinationRecord;
        String[] record;
        String[] subStrings;

        //Loops through the file, parses each line and stores destinations into destinationList
        while(fileScanner.hasNext())
        {
            destinationRecord = fileScanner.nextLine();
            subStrings = destinationRecord.split(";", 5); //Splits the destination Strings by ";"
            record = subStrings[4].split("-", 2);   //Splits the month integers by "-"
            destinationList.add(new Destination(
                    subStrings[0], // name
                    Integer.parseInt(subStrings[1]), // mileage
                    Integer.parseInt(subStrings[2]), // offSeasonMileage
                    Integer.parseInt(subStrings[3]), // mileUpgrade
                    Integer.parseInt(record[0]), // startMonth
                    Integer.parseInt(record[1]) // endMonth
                )
            );
        }

        //converts to a normal, fixed-length array of object and sorts using comparator
        this.destinationArray = (Destination[]) destinationList.toArray(new Destination[destinationList.size()]);
        Arrays.sort(this.destinationArray, new MileageComparator());
    }

    //Prints cityNames from destinationArray
    public String[] getCityNames()
    {
        ArrayList<String> cityNames = new ArrayList<String>();

        //Loops through the destinationArray to get cityNames
        for (int i = 0; i < this.destinationArray.length; i++)
        {
            Destination currentDest = this.destinationArray[i];
            cityNames.add(currentDest.getdName());
        }

        //Converts cityNames to an Array and sorts it
        String[] finalCityNames = cityNames.toArray(new String[cityNames.size()]);
        Arrays.sort(finalCityNames);
        return finalCityNames;
    }

    //Uses redemption algorithm to pick out destinations as well as upgrade if any
    public String[] redeemMiles(int miles, int month)
    {
        int currentMiles = miles;
        ArrayList<String> resultStrings = new ArrayList<>();
        ArrayList<Destination> chosenDestinations = new ArrayList<>();
        ArrayList<Destination> destinations = new ArrayList<>(Arrays.asList(destinationArray));
        Destination maxDestination;
        do
        {
            maxDestination = null;
            Destination currDest;
            int maxMiles = 0;
            //Loops through the destinations to find the max cost
            for (int i = 0; i < destinations.size(); i++)
            {
                currDest = destinations.get(i);
                int cost = getCostOfDestinationByMonth(month, currDest);

                //If the cost is in the budget and is higher than the max cost, then replace max cost
                if (cost <= currentMiles)
                {
                    if (cost > maxMiles)
                    {
                        maxMiles = cost;
                        maxDestination = currDest;
                    }
                }
            }
            //If new destination found, then add to chosen destinations and update the current Miles
            if (maxDestination != null)
            {
                chosenDestinations.add(maxDestination);
                destinations.remove(maxDestination);
                currentMiles -= maxMiles;
            }
        } while (maxDestination != null);

        remainingMiles = currentMiles;
        //Upgrades destinations
        chosenDestinations = upgradeDestinations(chosenDestinations);

        //Construct strings for chosenDestinations
        if (chosenDestinations.isEmpty())
        {
            resultStrings.add(("*** Your client has not accumulated enough Frequent Flyer Miles ***"));
        }
        else
        {
            for (Destination d : chosenDestinations)
            {
                resultStrings.add("* A trip to " + d.getdName() + " in " + (d.getIsUpgraded() ? "First" : "Economy") + " Class");
            }
        }

        return resultStrings.toArray(new String[resultStrings.size()]);
    }

    public int getRemainingMiles()
    {
        return remainingMiles;
    }

    //Returns the mileage of the destination based on the month of travel
    private int getCostOfDestinationByMonth(int month, Destination destination)
    {
        boolean isOffSeason = destination.getStartMonth() <= month && destination.getEndMonth() >= month;
        if (isOffSeason)
        {
            return destination.getOffSeasonMileage();
        }
        else
        {
            return destination.getMileage();
        }
    }

    //Upgrades the chosenDestination if remaining budget allows
    private ArrayList<Destination> upgradeDestinations(ArrayList<Destination> destinations)
    {
        for (Destination d : destinations)
        {
            if (d.getMileUpgrade() <= remainingMiles)
            {
                d.setIsUpgraded(true);
                remainingMiles -= d.getMileUpgrade();
            }
        }

        return destinations;
    }
}
