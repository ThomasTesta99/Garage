#include"Garage.h"

bool Garage::garageOperations(){
    int laneNumber = 0;
    bool isFound = false;
    ifstream carList;
    carList.open("ParkingGarage.txt");
    if(!carList){
        return 0;
    }
    string liscense;
    char code;
    while(!carList.eof() && carList >> code >> liscense){
        Car car(liscense, code);
        if(car.code == 'A'){
            if(!arrive(car)){
                cout << "Garage is full!" << endl;
                continue;
            }
        }
        else if(car.code == 'D'){
            isFound = false;
            if(lane1.search(car.liscense) != -2){
                laneNumber = 1;
                isFound = true;
            }
            else if(lane2.search(car.liscense) != -2){
                laneNumber = 2;
                isFound = true;
            }
            if(isFound){
                depart(car, laneNumber);//person got in car and is leaving
            }
            else{
                cout << "Wrong garage. Your car " << car.liscense << " is not here." << endl;
            }
        }
    }
    carList.close();
    return 1;
}

bool Garage::arrive(const Car& car){
    if(!lane1.isFull()){
        cout << "The car " << car.liscense << " is arriving into the Lane1" << endl;
        lane1.push(car);
        return 1;
    }
    else if(!lane2.isFull()){
        cout << "The car " << car.liscense << " is arriving into the Lane2" << endl;
        lane2.push(car);
        return 1;
    }
    return 0;
}

bool Garage::depart(const Car& car, int laneNumber){
    int carIndex=0, carTop=0, movedCars=0;
    if(laneNumber == 1){
        carIndex = lane1.search(car.liscense);
        if(carIndex == lane1.getTop()){
            lane1.pop(0);
            return 1;
        }
        else{
            carTop = lane1.getTop();
            while(carTop != carIndex){
                if(!lane2.isFull()){
                    lane2.push(lane1.pop(1));
                    movedCars++;
                }
                else{
                    street.push(lane1.pop(1));
                    movedCars++;
                }
                carTop--;
            }
            Car leavingCar(lane1.pop(0));
            cout << "The car " << leavingCar.liscense << " is departing. It was moved " << leavingCar.moves << " times." << endl;
            while(movedCars != 0){
                if(!street.isEmpty()){
                    lane1.push(street.pop(1));
                }
                else{
                    lane1.push(lane2.pop(1));
                }
                movedCars--;
            }
            return 1;
        }
    }
    else if(laneNumber == 2){
        carIndex = lane2.search(car.liscense);
        if(carIndex == lane1.getTop()){
            lane2.pop(0);
            return 1;
        }
        else{
            carTop = lane2.getTop();
            while(carTop != carIndex){
                if(!lane1.isFull()){
                    lane1.push(lane2.pop(1));
                    movedCars++;
                }
                else{
                    street.push(lane2.pop(1));
                    movedCars++;
                }
                carTop--;
            }
            Car leavingCar(lane2.pop(0));
            cout << "The car " << leavingCar.liscense << " is departing. It was moved " << leavingCar.moves << " times." << endl;
            while(movedCars != 0){
                if(!street.isEmpty()){
                    lane2.push(street.pop(1));
                }
                else{
                    lane2.push(lane1.pop(1));
                }
                movedCars--;
            }
            return 1;
        }
    }
    return 0;
}
