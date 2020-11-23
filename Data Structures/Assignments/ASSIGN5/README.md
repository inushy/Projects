### CSCI 340 - Data Structures and Algorithm Analysis

# CSCI340 - Parking Garage

The _Scratchemup Parking Garage_ contains a single lane that holds up to ten cars. Cars arrive at the south end of the garage and leave from the north end. If a customer arrives to pick up a car that is not the northernmost, all cars to the north of the car moved out, the car is driven out, and the other cars are restored in the same original order.

Write a program in C++ (**parking.cc**) that reads a group of input lines. Each line contains an **A** for **arrival** or a **D** for **departure**, which is terminated by a **:**, and a **license plate number**, which is terminated by a **:**. The program should print a message each time a car arrives or departs. When a car arrives, the message should specify when the garage is full. If there is no room for a car, the car simply leaves. When a car departs, the message should include the number of times the car was moved within the garage, including the departure itself but not the arrival.

For a departure, you need to check if the car is in the garage. If it’s not, print an error message and ignore the departure. When a car arrives and if the garage is not full, create a **C/C++ structure object** for the car that contains the `id number` (*starts with 1*), the `license plate number`, and the `number of times the car was moved` within the garage (*with initial value 0*), and insert this structure object in a **STL deque** container. When a car departs, delete the corresponding structure object from the deque.

To save the original ordering of the cars that are moved out from the deque to open the way for a departing car, define a **STL stack** container to temporarily put the moved cars in the stack, and after the departing car, retrieve all cars from the stack back to the deque into their original positions.