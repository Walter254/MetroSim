/*
 * MetroSim.h
 *
 * Comp 15
 * October 2021
 *
 * Created by: Walter Wagude, October 2021
 *
 * Notes: Interface of MetroSim class. It includes relevant 
 * member functions and variables such as Move_Train() that are 
 * essential in navigating the simulation on the command line. This is
 * basically a helper class for main.cpp. A lot of functions take in commands 
 * or files as parameters because they are either called in main where a file 
 * is passed into them or within other functions where commands are passed into
 * them
 * 
 */
 
#ifndef _METROSIM_H_
#define _METROSIM_H_

#include <iostream>
#include <vector>
#include <string>

#include "Passenger.h"
#include "PassengerQueue.h"

class MetroSim
{
public:
    //constructor
    MetroSim(std::ifstream &stations);
    //terminate simulation
    void Terminate_Simulation();
    //print list of Stations
    void print_stations(std::ostream &output);
    //move train/passengerqueues
    void Move_Train();
    // add passenger to Train based on their departure
    void Add_Passenger_T();
    // add passenger to Station 
    void Add_Passenger_S(Passenger passenger, int Arrival);
    //remove passenger from PassengerQueue based on Arrival
    void Remove_Passenger(std::ostream &output);
    //go back to first station once at the last station
    void go_back();
    //get command prompt and print the simulation
    void get_command(char *argv[]);
    //get cin prompt
    void cin_command(char *argv[]);
    

private:
    //vectors of type PassengerQueue
    std::vector <PassengerQueue> Train;
    std::vector <PassengerQueue> Station;
    //keeps track of current station the train is at
    int curr_station;
    //keeps track of number of trains
    int num_stations;
    

};

#endif
