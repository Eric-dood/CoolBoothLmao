//COMSC-210 | Lab 32 | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <deque>
#include "Car.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void printQueue(deque<Car> q);

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
    printQueue(carList);
    //Start the loop where cars are being paid or joining lanes
    int i = 0;
    //Do a while loop until the queue list is empty
    while(!carList.empty() && ++i)
    {
        //Do a random check to either join a lane or pay a car
        if (!(rand() % 2))
        {
            Car newCar = Car();
            cout << "Time: " << i << " Operation: Joined lane: ";
            newCar.print();
            carList.push_back(newCar);
        }
        else
        {
            Car oldCar = carList.front();
            cout << "Time: " << i << " Operation: Car paid: ";
            oldCar.print();
            carList.pop_front();
        }
        cout << "Queue:" << endl;
        printQueue(carList);
    }

    return 0;
}

void printQueue(deque<Car> q)
{
    if (q.empty()) cout << setw(10) << "Empty.";
    else
    {
        for (int i = 0; i < q.size(); i++)
        {
            cout << setw(5);
            q[i].print();
        }
    }
    cout << endl;
}