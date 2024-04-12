#include <cassert>
#include "Passenger.h"
#include "PassengerQueue.h"
#include "MetroSim.h"
#include <fstream>

/********************************************************************\
*                       Passenger test                     *
\********************************************************************/

/*
* Test if the print function works correctly
*/
void Test_Print_Function()
{
    //initialize passenger with values
    Passenger test = Passenger(1,2,3);
    test.print(std::cout);
}

/********************************************************************\
*                       PassengerQueue tests                       *
\********************************************************************/
/*
* Insert passengers in the passengerqueue and check if the front passenger
* in the cout is the passenger enqueued the last.
*/
void Test_front_functionPQ()
{
    //initialize passenger with values
    Passenger P_test = Passenger(1,2,3);
    Passenger P_test2 = Passenger(4,5,6);
    //declare an instance of passengerqueue
    PassengerQueue PQ_test;
    //insert passengers in passengerqueue
    PQ_test.enqueue(P_test);
    PQ_test.enqueue(P_test2);
    
    assert(PQ_test.front().id == PQ_test.Passenger_At(0).id);
    PQ_test.print(std::cout);
    
}

/*
* insert passengers into the PassengerQueue then call the dequeue function and
* check in cout if the front element is removed.
*/
void Test_dequeue_functionPQ()
{
    //initialize passenger with values
    Passenger P_test = Passenger(1,2,3);
    Passenger P_test2 = Passenger(4,5,6);
    //declare an instance of passengerqueue
    PassengerQueue PQ_test;
    //insert passengers in passengerqueue
    PQ_test.enqueue(P_test);
    PQ_test.enqueue(P_test2);
    //remove the front passenger from list
    PQ_test.dequeue();
    assert(PQ_test.size() == 1);
    PQ_test.print(std::cout);
}

/*
* insert passengers into the PassengerQueue using the enqueue function then
* check if the size of the passengerqueue corresponds to the passengers added.
*/
void Test_enqueue_functionPQ()
{
    //initialize passenger with values
    Passenger P_test = Passenger(1,2,3);
    Passenger P_test2 = Passenger(4,5,6);
    //declare an instance of passengerqueue
    PassengerQueue PQ_test;
    //insert passengers in passengerqueue
    PQ_test.enqueue(P_test);
    PQ_test.enqueue(P_test2);
    //check that the size corresponds with the number of added elements
    assert(PQ_test.size() == 2);
    
    PQ_test.print(std::cout);
}

/*
* check if the size of the passengerqueue corresponds to the passengers added.
*/
void Test_size_functionPQ()
{
    //initialize passenger with values
    Passenger P_test = Passenger(1,2,3);
    Passenger P_test2 = Passenger(4,5,6);
    //declare an instance of passengerqueue
    PassengerQueue PQ_test;
    //insert passengers in passengerqueue
    PQ_test.enqueue(P_test);
    PQ_test.enqueue(P_test2);
    //check that the size corresponds with the number of added elements
    assert(PQ_test.size() == 2);
    
    //PQ_test.print(std::cout);
}

/*
* check if the passenger added at the front of the list is same as passenger at
* index 0, hence test if passengerAt function works.
*/
void Test_Passenger_At_functionPQ()
{
    //initialize passenger with values
    Passenger P_test = Passenger(1,2,3);
    Passenger P_test2 = Passenger(4,5,6);
    //declare an instance of passengerqueue
    PassengerQueue PQ_test;
    //insert passengers in passengerqueue
    PQ_test.enqueue(P_test);
    PQ_test.enqueue(P_test2);
    //check passenger at o index's id with passenger at the front's id.
    assert(PQ_test.front().id == PQ_test.Passenger_At(0).id);
    //PQ_test.print(std::cout);
    
}

/*
* add elements into the list using enqueue function then call print function to
* cout the elements in terminal.
* check if the format is right
*/
void Test_print_functionPQ()
{
    //initialize passenger with values
    Passenger P_test = Passenger(1,2,3);
    Passenger P_test2 = Passenger(4,5,6);
    //declare an instance of passengerqueue
    PassengerQueue PQ_test;
    //insert passengers in passengerqueue
    PQ_test.enqueue(P_test);
    PQ_test.enqueue(P_test2);
    //check that the size corresponds with the number of added elements
    assert(PQ_test.size() == 2);
    //print elements
    PQ_test.print(std::cout);
}

/********************************************************************\
*                       MetroSim tests                               *
\********************************************************************/

/*
* creates an instance of MetroSim and passes in a file of stations to create
* the stations. Checks if the function is able to read from file
*/
void Test_MetroSim_Constructor_functionMS()
{
    std::string filename;
    filename = "stations.txt";
    
    std::ifstream input_file;
    //open file
    input_file.open(filename);
    MetroSim Train_Simulation = MetroSim(input_file);
    input_file.close();

}

/*
* Test the destructor of MetroSim, creates an instance of MetroSim then
* constructs it. After that, I call the Terminate_Simulation function and
* checks the terminal for the message that is suupposed to be printed  when 
* the program is terminated
*/
void Test_Terminate_Simulation_functionMS()
{
    std::string filename;
    filename = "stations.txt";
    
    std::ifstream input_file;
    
    input_file.open(filename);
    MetroSim Train_Simulation = MetroSim(input_file);
    input_file.close();
    
    Train_Simulation.Terminate_Simulation();

}

/*
* This is an important test because I use the print stations function to debug
* a lot of my code. After creating an instance of MetroSim and constructing it,
* I call the print function to see whether the stations print correctly
*/
void Test_print_stations_functionMS()
{
    std::string filename;
    filename = "stations.txt";
    
    std::ifstream input_file;
    
    input_file.open(filename);
    MetroSim Train_Simulation = MetroSim(input_file);
    input_file.close();
    
    Train_Simulation.print_stations(std::cout);

}

/*
* Instead of testing each function from MetroSim.cpp, I decided to create a
* a function called get_command that uses all the other functions. Either calls
* the functions or calls a function that calls the other function, If this
* function works- it is a great indication that the other functions also work
* This function also makes work easier for main.cpp
*/
void Test_get_command_functionMS()
{
    std::string filename;
    filename = "stations.txt";
    
    std::ifstream input_file;
    
    input_file.open(filename);
    
    //code to test an edge case! the cerr prints right
    // if (not input_file.is_open()) {
    //         std::cerr << "Error: could not open file "
    //              << filename << std::endl;
    //         // return 1;   // non-zero return from main means error
    // }
    MetroSim Train_Simulation = MetroSim(input_file);
    // create commands to pass to get_command function
    char *commands[] = {"./the_MetroSim","stations.txt",
                       "output.txt","test_commands.txt"};
    
    //std::cerr << "here1" << std::endl; - debugging code
    Train_Simulation.get_command(commands);
    // print stations to terminal
    Train_Simulation.print_stations(std::cout);
    input_file.close();
}
