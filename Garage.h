#ifndef Garage_h
#define Garage_h

#include"Stack.h"
#include<fstream>

class Garage{
private:
    Stack lane1;
    Stack lane2;
    Stack street;
public:
    Garage() {}
    bool garageOperations();
    bool arrive(const Car&);
    bool depart(const Car&, int);
};

#endif /* Garage_h */
