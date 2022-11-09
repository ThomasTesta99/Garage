#ifndef Stack_h
#define Stack_h

#include<iostream>
#include<string>
using namespace std;

struct Car{
    string liscense;
    int moves=0;
    char code;
    Car() {}
    Car(const Car& car){liscense = car.liscense; code = car.code; moves = car.moves;}
    Car(string liscense){ this->liscense = liscense;}
    Car(string liscense, char code){ this->liscense = liscense; this->code = code;}
    Car(string liscense, char code, int moves){ this->liscense = liscense; this->code = code; this->moves=moves;}

};

class Stack{
private:
    Car spaces[10];
    int top=-1;
public:
    Stack() {}
    Car pop(bool);
    bool push(const Car&);
    int search(string liscense);
    bool isEmpty();
    bool isFull();
    Car peek();
    int getTop(){return top;};
};

#endif
