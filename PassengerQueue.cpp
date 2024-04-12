/*
 * Passenger.cpp
 *
 * Comp 15 
 *
 * Created by:
 *        Walter Wagude - October 2021
 *
 * Notes:Implementation of the PassengerQueue.h file. One of the private member
 * variables is the Passenger_Queue, which is a vector of Passengers and vector
 * is a library with implemented functions - so most of these functions call 
 * the vector functions.
 * For Example:
 *     The function dequeue, calls a erase function from the vector library and
 *     that helps to remove the lement at the front of the list
 * Edge Cases:
        No edge cases or errors encountered
 *
 */


#include "PassengerQueue.h"
#include "Passenger.h"

// for the print function
#include <iostream>
#include <vector>

using namespace std;

/*
*front
*Parameters: None
*return: Nothing
*purpose: Returns, but does not remove, the element at the front of the queue
*/
Passenger PassengerQueue::front(){
    return Passenger_Queue.front();

}

/*
*dequeue
*Parameters: None
*return: Nothing
*purpose: Removes the element at the front of the queue
*/
void PassengerQueue::dequeue(){
    Passenger_Queue.erase(Passenger_Queue.begin());

}

/*
*enqueue
*Parameters: a passengerto be inserted into the queue
*return: Nothing
*purpose: Inserts a new passenger at the end of the queue
*/
void PassengerQueue::enqueue(const Passenger &passenger){
    Passenger_Queue.push_back(passenger);

}

/*
*size
*Parameters: None
*return: size of the passengerqueue
*purpose: Returns the number of elements in the queue
*/
int PassengerQueue::size(){
    return Passenger_Queue.size();

}

/*
*Passenger_At
*Parameters: index of a passenger in passenger queue
*return: Passenger at the given index
*purpose: returns passenger at the given index
*/
Passenger PassengerQueue::Passenger_At(int idx){
    return Passenger_Queue.at(idx);
}

/*
*Print
*Parameters: output file
*return: Nothing
*purpose:Prints each Passenger in the PassengerQueue to the given output
*        stream from front to back, with no spaces in between and no trailing
*        newline. For example:
*        [1 , 1 - >2][2 , 1 - >3][3 , 2 - >3][4 , 2 - >3]
*/
void PassengerQueue::print(ostream &output){
    for (int i = 0;i < size(); i++){
        Passenger_Queue.at(i).print(output);
    }

}

/*
*addName
*Parameters: name of stations and the number ofthat stationin list
*return: Nothing
*purpose: add name of the station and number.
*/
void PassengerQueue::addName(string name_station, int num_stations){
    station_Name = name_station;
    num_station = num_stations;
    
}

/*
*station_name
*Parameters: None
*return: name of the station
*purpose: return the name of the station
*/
string PassengerQueue::station_name(){
    return station_Name;
}
