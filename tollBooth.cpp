//COMSC-210 | Lab 32 | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <deque>
#include "Car.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //Include the random seed generator
    srand(time(0));
    //Declare the car deque lsit
    deque<Car> carList;
    //Start the initial queue
    carList.push_back(Car());
    carList.push_front(Car());
    //Print the queue
    cout << "Initial queue:" << endl;
    for (int i = 0; i < carList.size(); i++)
    {
        cout << setw(5);
        carList[i].print();
    }
    //Start the loop where cars are being paid or joining lanes
    int i = 0;
    while(!carList.empty() && i < 50)
    {
        Car newCar = Car();
        string str = "Test";
        cout << "Time: " << i++ << " Operation: " << str << ": ";
        newCar.print();
        cout << endl;
    }

    return 0;
}