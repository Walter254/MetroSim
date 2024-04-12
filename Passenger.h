/*
 * Passenger.h
 *
 * Comp 15
 * October 2021
 *
 * This code was provided to me - I did not edit it but implemented the
 * print function on the .cpp file
 *
 * Notes:Interface of Passenger struct that includes relevant 
 * member functions and variables such as
 * Passenger(int newId, int arrivalStation, int departureStation)
 * that creates an instance of Passenger and initializes it 
 * with the given arguments.
 */
 
#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        void print(std::ostream &output);

};

#endif
