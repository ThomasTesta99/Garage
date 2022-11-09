#include "Stack.h"

Car Stack::pop(bool isMovingLanes){
    Car tempCar(spaces[top].liscense, spaces[top].code, spaces[top].moves);
    if(top == -1){
        return Car();
    }
    else{
        if(isMovingLanes){//check if it lane swaps
            tempCar.moves++;
        }
        top--;
        return tempCar;
    }
}

bool Stack::push(const Car& car){
    if(top == 9){//this is already checked in garage method arrive, but it can be called outside that so it should be             checked aagain
        return 0;
    }
    top++;
    spaces[top] = car;
    return 1;
}

bool Stack::isEmpty(){
    if(top == -1)
        return true;
    return false;
}

bool Stack::isFull(){
    if(top == 9)
        return true;
    return false;
}

int Stack::search(string Liscense){
    int carIndex = -2;//not found in this lane or empty
    if(top == -1){
        return carIndex;//list is empty
    }
    for(int i=0; i<top; i++){
        if(spaces[i].liscense == Liscense){
            carIndex = i;
            return carIndex;
        }
    }
    return carIndex;
}

Car Stack::peek(){
    Car tempCar(spaces[top].liscense, spaces[top].code);
    return tempCar;
}
