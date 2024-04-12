/*
 * MetroSim.cpp
 *
 * Comp 15 
 *
 * Created by:
 *        Walter Wagude - October 2021
 *
 * Notes:Implementation of the MetroSim.h file. Themain two functions are the
 * get_command and cin_command functions. The get_command function takes in a 
 * file then reads from it. It then calls the other functions in accordance
 * with the commands from the file. The cin_command on the other hand just 
 * takes in the commands then calls the other functions in accordance with the
 * commands from cin - terminal.
 * Testing:
 *     I tested the get_command function in unit_test.h and because it uses, 
 *     the other functions, tested the other functions indirectly.
 * Edge Cases:
        If a passenger boards the train at a station and departs at the same 
        station. My programs works in a way such that the passenger is added
        on the train but does not alight until the train loops back to that 
        station.
 *
 */

#include "MetroSim.h"
#include "Passenger.h"
#include "PassengerQueue.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
*constructor
*Parameters: file of stations
*return: Nothing
*purpose: Read data from the file
*/
MetroSim::MetroSim(ifstream &stations){
    //start at station 1
    num_stations = 1;
    curr_station = 1;
    string name_station;
    //create an instance of PQ- Station
    PassengerQueue current_station;
    // read from file and get number of stations from the file
    getline(stations, name_station);
    current_station.addName(name_station, num_stations);
    //get all the stations from the file
    while (!stations.eof()){
        Station.push_back(current_station);
        Train.push_back(current_station);
        
        num_stations++;
        getline(stations, name_station);
        current_station.addName(name_station, num_stations);
    }
    print_stations(cout);
    
}

/*
*Terminate_Simulation
*Parameters: None
*return: None
*purpose: acts as a destructor - clears upmemory used by MetroSim
*/
void MetroSim::Terminate_Simulation(){
    Station.clear();
    cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
    
}

/*
*print_stations
*Parameters: output file
*return: nothing
*purpose: print the list of stations
*/
void MetroSim::print_stations(ostream &output){
    output << "Passengers on the train: {";
    for (int i = 0; i < num_stations - 1; i++){
        Train[i].print(output);
    }
    output << "}" << endl;
    
    for (size_t i = 0; i < Station.size(); i++){
        if ((int) i == curr_station - 1){
            output << "TRAIN: ";
        }else{
            output << "       ";
        }
        output << "[" << i + 1 << "] " << Station[i].station_name() << " {";
                                          Station[i].print(output);
        output << "}" << endl;
    }
    
}

/*
*Move_Train
*Parameters: None
*return: Nothing
*purpose: Move the train to the next station
*/
void MetroSim::Move_Train(){
    Add_Passenger_T();
    go_back();
    
}

/*
*Add_Passenger_T
*Parameters:None
*return:Nothing
*purpose: Adds a passenger on the train
*/
void MetroSim::Add_Passenger_T(){
    while (Station.at(curr_station-1).size() != 0){
        Passenger temporary = Station.at(curr_station-1).front();
        int Departure = temporary.to;
        
        Train[Departure - 1].enqueue(temporary);
        Station.at(curr_station - 1).dequeue();
    }
    
}

/*
*Add_Passenger_S
*Parameters: passenger and their id
*return: Nothing
*purpose: Add passenger to a Station
*/
void MetroSim::Add_Passenger_S(Passenger passenger, int Arrival){
    Station[Arrival - 1].enqueue(passenger);
    print_stations(cout);

}

/*
*Remove_Passenger
*Parameters: output file
*return: Nothing
*purpose: Remove passenger from the train then print to output file
*/
void MetroSim::Remove_Passenger(ostream &output){
    while (Train.at(curr_station - 1).size() != 0){
        output << "Passenger ";
        output << Train.at(curr_station - 1).front().id;
        output << " left train at station ";
        output << Station.at(curr_station - 1).station_name() << endl;
        
        Train.at(curr_station - 1).dequeue();
    }
    print_stations(cout);
    
}

/*
*go_back
*Parameters:None
*return:Nothing
*purpose: Once the train gets to the last station, it loops to the first
*station
*/
void MetroSim::go_back(){
    curr_station++;
    if (curr_station == num_stations){
        curr_station = 1;
    }
    
}

/*
*get_command
*Parameters: files passed into the program
*return: Nothing
*purpose: print user interface to terminal
*/
void MetroSim::get_command(char *argv[]){
    int id = 1;
    int Departure;
    int Arrival;
    
    ofstream outputtxt(argv[2]);
    ifstream commands(argv[3]);
    
    string input1;
    string input2;
    
    bool done = false;
    
    while (done == false){
        cout << "Command? ";
        commands >> input1;
        if (input1 == "p"){
            commands >> Arrival;
            commands >> Departure;
            
            Passenger temp(id, Arrival, Departure);
            Add_Passenger_S(temp, Arrival);
            id++;
        } else if (input1 == "m"){
            commands >> input2;
            if (input2 == "m"){
                Move_Train();
                Remove_Passenger(outputtxt);
            }else{
                Terminate_Simulation();
                done = true;
            }
        }
    }
    
}

/*
*cin_command
*Parameters:files passed into the program
*return: Nothing
*purpose: print out user interface to terminal
*/
void MetroSim::cin_command(char *argv[]){
    int id = 1;
    int Departure;
    int Arrival;
    string first_com;
    string second_com;

    ofstream outputtxt(argv[2]);
    
    bool done = false;
    
    while (done == false){
        cout << "Command? ";
        cin >> first_com;
        if (first_com == "m"){
            cin >> second_com;
            if (second_com == "m"){
                Move_Train();
                Remove_Passenger(outputtxt);
            }else{
                Terminate_Simulation();
                done = true;
            }
        } else if (first_com == "p"){
            cin >> Arrival >> Departure;
            Passenger temp(id, Arrival, Departure);
            Add_Passenger_S(temp, Arrival);
            id++;
        }
    }
}