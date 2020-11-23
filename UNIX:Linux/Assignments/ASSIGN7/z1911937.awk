#!/bin/bash

#     Anushka Verma
#     Course: CSCI Linux 330
#     Assignment 7
#     DUE: 11/06/20

#     PURPOSE: This assignment should give you experience using awk to generate reports from input data.

# command line: awk -f z1911937.awk salesdb

BEGIN{                                                                  #Used To Create Header For Report
   FS = ":"                                                             #Field Separator
   pdCount = 1                                                          #Product Count
   personCount = 1                                                      #Person Count
}
{
    switch(NF){
        case 3:
            people[personCount] = $0                                    #Person's Information
            personCount++
            break
        case 4:
            product[pdCount] = $0                                       #Product's Information
            pdCount++
            break
        case 5:
            split(product[$2], pDetails, ":")
            sales[$5] += ($3 * pDetails[4])
            break
    }
}  #Ends The Begin Function

END{
    print "=============================================================="
    print "                  Welcome To No-op Computing!                 "  #Displays The Program's Name 
    
    n = asorti(sales, sortedIndexes, "@val_num_desc")                       #Sort Function For The Indexes
    
    print "=============================================================="
    print "Name                      Position                Sales Amount"  #Displays The Title
    print "=============================================================="
    for (i = 1; i <=n; i++)                                                 #The For Loop For The Order Of Sales
    {
         split(people[sortedIndexes[i]],person,":")                         #Separates The Data
         split(person[2], name, " ")                                        #Separates The Names And Adds A Comma Between First And Second Name
         printf "%-25s %-13s %22.2f \n", name[2] ", " name[1], person[3], sales[sortedIndexes[i]]  #Prints Out The Final Output After Being Sorted
    }
   print "=============================================================="
} #Ends The End Function