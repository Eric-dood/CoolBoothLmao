//COMSC-210 | Lab 32 | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <deque>
#include "Car.h"
#include <cstdlib>
#include <ctime>
using namespace std;

//Global constants
const int MAX_LANES = 4;

//Function prototypes
void printQueue(deque<Car> q[], int size = MAX_LANES);
/*
Specifically the printQueue() function because it's used twice in main(), I wanted to have
some versatility in the code a little just in case.
*/

//Define the main() function
int main()
{
    //Include the random seed generator
    srand(time(0));
    //Declare the car deque lsit
    deque<Car> carList[4];
    //Start the initial queue
    for (int i = 0; i < MAX_LANES; i++)
    {
        carList[i].push_back(Car());
        carList[i].push_front(Car());
    }
    //Print the queue
    cout << "Initial queue:" << endl;
    printQueue(carList);
    //Start the loop where cars are being paid or joining lanes
    //But first, define the count and choice variables
    int i = 0, choice = 0;
    //Do a while loop until the queue list is empty
    while(!carList.empty() && ++i)
    {
        //Set the choice variable to be between 0 and 100 (inclusive)
        choice = (rand() % 101);
        //Do a random check to either join a lane or pay a car
        if (choice <= 45) //Joining lanes (45% chance)
        {
            //Define newCar, which is a new car that'll be added to the deque list
            Car newCar = Car();
            //Print the information
            cout << "Time: " << i << " Operation: Joined lane: ";
            newCar.print();
            //Use push_back to add the new car to the list
            carList.push_back(newCar);
        }
        else //Cars paid (55% chance)
        {
            //Define oldCar, which is the front element from the deque list
            Car oldCar = carList.front();
            //Print the information
            cout << "Time: " << i << " Operation: Car paid: ";
            oldCar.print();
            //Use pop_front to remove the front element from the list
            carList.pop_front();
        }
        //Print the current queue list
        cout << "Queue:" << endl;
        printQueue(carList);
    }

    return 0;
}

//Define printQueue()
void printQueue(deque<Car> q[], int size = MAX_LANES)
{
    //If the queue list is empty, just print out "Empty" to signify the empty list
    if (q.empty()) cout << setw(10) << "Empty.";
    //Otherwise go through the entirety of the list and print it as usual
    else
    {
        //Use a range-based loop to go through all of the cars from the queue
        for (int i = 0; i < q.size(); i++)
        {
            //Use setw() to leave in some small space after each car
            cout << setw(5);
            //Print the element
            q[i].print();
        }
    }
    //Leave extra space
    cout << endl;
}