/*
 * Passenger.cpp
 *
 * Comp 15 
 *
 * Edited and updated by:
 *        Walter Wagude - October 2021
 *
 * Notes:Implementation of the print function in Passenger header file, the print 
 * function prints the information about the instance of the passenger.
 * Edge cases: No edge cases or errors encounted
 *
 */

#include <iostream>
#include <string>
#include "Passenger.h"

/*
*Print function
*Parameters: outputfile
*return: Nothing
*purpose: print a passenger's information
*/
void Passenger::print(std::ostream &output)
{
        output << "["<< id <<", "<< from <<"->" << to << "]";
}
