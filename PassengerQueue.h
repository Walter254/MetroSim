/*
 * PassengerQueue.h
 *
 * Comp 15
 * October 2021
 *
 * Created by: Walter Wagude, October 2021
 *
 * Notes:Interface of PassengerQueue class. It includes relevant 
 * member functions and variables such as enqueue and dequeue that are 
 * essential in making the simulation work properly.
 * 
 */

#ifndef _PASSENGERQUEUE_H_
#define _PASSENGERQUEUE_H_

#include <iostream>
#include <vector>
#include "Passenger.h"

class PassengerQueue {
    public:
        //Returns, but does not remove, the element at the front of the queue
        Passenger front();
        //Removes the element at the front of the queue
        void dequeue();
        //Inserts a new passenger at the end of the queue
        void enqueue(const Passenger &passenger);
        //Returns the number of elements in the queue
        int size();
        // returns passenger at the given index
        Passenger Passenger_At(int idx);
        /*
        * Prints each Passenger in the PassengerQueue to the given output
        * stream from front to back, with no spaces in between and no trailing
        * newline. For example:
        * [1 , 1->2][2 , 1->3][3 , 2->3][4 , 2->3]
        */
        void print(std::ostream &output);
        // add name of the station and number.
        void addName(std::string name_station, int num_stations);
        // return the name of the station
        std::string station_name();
    private:
        //vector of type Passenger
        std::vector<Passenger>Passenger_Queue;
        
        //member variables 
        std::string station_Name;
        int num_station;
    
};

#endif
