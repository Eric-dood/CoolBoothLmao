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
const int PAID_CHANCE = 46, JOIN_CHANCE = 39, SHIFT_CHANCE = 15;

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
    int count = 0, choice = 0;
    int empty = 0;
    bool lane_emptied[MAX_LANES];
    //Do a while loop until the queue list is empty
    while (++count <= 20 && (empty < MAX_LANES))
    {
        cout << "Time: " << count << endl;
        for (int i = 0; i < MAX_LANES; i++)
        {
            cout << "Lane " << i+1 << ": ";
            if (!carList[i].empty())
            {
                //Set the choice variable to be between 0 and 100 (inclusive)
                choice = (rand() % 101);
                //Do a random check to either join a lane or pay a car
                if (choice <= PAID_CHANCE) //Cars paid (46% chance)
                {
                    //Define oldCar, which is the front element from the deque list
                    Car oldCar = carList[i].front();
                    //Print the information
                    cout << "Paid: ";
                    oldCar.print();
                    //Use pop_front to remove the front element from the list
                    carList[i].pop_front();
                }
                else if (choice > PAID_CHANCE && choice <= (100-JOIN_CHANCE)) //Joining lanes (39% chance)
                {
                    //Define newCar, which is a new car that'll be added to the deque list
                    Car newCar = Car();
                    //Print the information
                    cout << "Joined: ";
                    newCar.print();
                    //Use push_back to add the new car to the list
                    carList[i].push_back(newCar);
                }
                else //Switching lanes
                {
                    cout << "Switched: ";
                    Car shiftCar = carList[i].back();
                    int lane;
                    while (lane != i)
                    {
                        lane = rand() % MAX_LANES;
                        carList[lane].push_back(shiftCar);
                        carList[i].pop_back();
                        break;
                    }
                }
            }
            else
            {
                if (!lane_emptied[i])
                {
                    empty += 1;
                    lane_emptied[i] = true;
                }
                cout << "Empty" << endl;
            }
            //Leave extra space
        }

        //Print the current queue list
        if (empty < MAX_LANES) printQueue(carList);
        else cout << "All lanes have been emptied." << endl;
    }

    return 0;
}

//Define printQueue()
void printQueue(deque<Car> q[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Lane " << i+1 << " Queue:" << endl;
        //If the queue list is empty, just print out "Empty" to signify the empty list
        if (q[i].empty()) cout << setw(10) << "Empty." << endl;
        //Otherwise go through the entirety of the list and print it as usual
        else
        {
            //Use a range-based loop to go through all of the cars from the queue
            for (auto j : q[i])
            {
                //Use setw() to leave in some small space after each car
                cout << setw(5);
                //Print the element
                j.print();
            }
        }
    }
    //Leave extra space
    cout << endl;
}