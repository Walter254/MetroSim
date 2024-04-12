/*
 * main.cpp
 *
 * Comp 15 
 *
 * Created by:
 *        Walter Wagude - October 2021
 *
 * Driver code for the train simulation (MetroSim).
 
 * Notes: Depending on the number of commands given on command line, this code
 * calls the appropriate MetroSim function.
 * Testing:
 *     All the functions used in this code are already tested in unit_test.h
 *     and the remainder was tested on the command line
 * Edge Cases:
        If the user types less than three arguments or more than four on
        command line.
        If the file passed in does not open
        All the edge cases have been handled accordingly
 *
 */
 

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"
#include "Passenger.h"
#include "PassengerQueue.h"


using namespace std;

int main(int argc, char *argv[])
{
    //In the case that the user has less arguments on the command line
    if (argc < 3){
        cerr << "Usage: ./MetroSim stationsFile outputFile" <<
                 " [commandsFile]" << endl;
        exit(EXIT_FAILURE);
    }
    
    string filename;
    filename = argv[1];
    //open file
    ifstream input_file;
    input_file.open(filename);
    //In the case that the file does not open
    if (not input_file.is_open()){
        cerr << "Error: could not open file "
             << filename << endl;
        exit(EXIT_FAILURE);
    }
    //create an instance of MetroSim and initialize it
    MetroSim Train_Simulation = MetroSim(input_file);
    //if reading commands from cin on terminal
    if (argc == 3){
        Train_Simulation.cin_command(argv);
    }else if (argc == 4){
        Train_Simulation.get_command(argv); //if reading commands from a file
        
    }else{
        cerr << "Usage: ./MetroSim stationsFile outputFile" <<
                 " [commandsFile]" << endl;
        exit(EXIT_FAILURE);
    }
    //close file
    input_file.close();
    return 0;
}
