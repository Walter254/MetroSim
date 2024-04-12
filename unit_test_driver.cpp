
/*
unit_test_driver.cpp
Matt Russell
COMP15 2020 Summer
Updated 12/16/2020

This file is used as the driver for unit testing.

The 'tests' map will be auto-populated in the form:

    { "test_name", test_name }

Where "test_name" maps to the associated test function in unit_tests.h.
*/

#include <map>
#include <string>
#include <iostream>
#include "unit_tests.h"

typedef void (*FnPtr)();

int main(int argc, char **argv) {

    /* will be filled in by the unit_test script */
    std::map<std::string, FnPtr> tests {
	{ "Test_Print_Function", Test_Print_Function },
	{ "Test_front_functionPQ", Test_front_functionPQ },
	{ "Test_dequeue_functionPQ", Test_dequeue_functionPQ },
	{ "Test_enqueue_functionPQ", Test_enqueue_functionPQ },
	{ "Test_size_functionPQ", Test_size_functionPQ },
	{ "Test_Passenger_At_functionPQ", Test_Passenger_At_functionPQ },
	{ "Test_print_functionPQ", Test_print_functionPQ },
	{ "Test_MetroSim_Constructor_functionMS", Test_MetroSim_Constructor_functionMS },
	{ "Test_Terminate_Simulation_functionMS", Test_Terminate_Simulation_functionMS },
	{ "Test_print_stations_functionMS", Test_print_stations_functionMS },
	{ "Test_get_command_functionMS", Test_get_command_functionMS },

    };

    /* first argument to main() is the string of a test function name */
    if (argc <= 1) {
        std::cout << "No test function specified. Quitting" << std::endl;
        return 1;
    }

    /* extract the associated fn pointer from "tests", and run the test */
    FnPtr fn = tests[argv[1]];
    fn();

    return 0;
}
