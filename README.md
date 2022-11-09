# Garage
Garage Simulation implented with stacks.

The program reads from an input file a code and liscense number, 'A' for arrive and 'D' for depart.  If the code is 'D', the program will search the garage to see if the car is present.  If it is, the cars in front of the target car are moved to other lanes until the target car is free to go.  Then those cars are plced back in their original lane.  If the code is 'A', the car is placed in an open lane.  If there are no spots, then the car is turned away.
