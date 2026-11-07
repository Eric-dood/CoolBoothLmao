//COMSC-210 | Lab 32 | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <deque>
#include "Car.h"
using namespace std;

int main()
{
    deque<Car> carList;
    for (int i = 0; i < NR_MANUFACTURERS; i++)
        carList.push_back(Car());
    return 0;
}