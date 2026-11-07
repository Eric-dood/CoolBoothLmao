//COMSC-210 | Lab 32 | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <deque>
#include "Car.h"
using namespace std;

int main()
{
    deque<Car> carList;
    //Start the initial queue
    carList.push_back(Car());
    carList.push_front(Car());
    cout << "Initial queue:" << endl;
    for (int i = 0; i < carList.size(); i++)
    {
        cout << setw(5);
        carList[i].print();
    }
    while(!carList.empty())
    {
        
    }

    return 0;
}