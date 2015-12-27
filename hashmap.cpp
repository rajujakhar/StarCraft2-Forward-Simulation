/*This file has been written as part of forward simulation of Star Craft 2 game
This program reads the data from input csv files and stores them in a map with key, value pair

Author : Raju Ram
Last Modified : 27th Dec 2015
Version : 1.0

*/

#include "Building.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>


int main()
{

	Building b1;	

	// Create a map whos key is a string and value is an object of class Building
	std::map<std::string,Building> map1;	
	char delim = ',';
	std::string line,attr;

	std::ifstream file_;
	file_.open("techtrees.csv");

	// Read the entire line
	while(getline(file_, line)) {
		
		// The following if condition has been written to ignore the lines in techtress.csv which starts with #
		if(line.front() != '#') {
			// convert the line into stringstream
			std::stringstream s1(line);
			
			// save the string before delim into string attr
			getline(s1, attr, delim);
			b1.name = attr;
			getline(s1, attr, delim);
			b1.mineral_req = std::stod(attr);
			getline(s1, attr, delim);
			b1.vespene_req = std::stod(attr);
			getline(s1, attr, delim);
			b1.build_time = std::stoi(attr);
			getline(s1, attr, delim);
			b1.supply_cost = std::stoi(attr);
			getline(s1, attr, delim);
			b1.supply_provided = std::stoi(attr);
			getline(s1, attr, delim);
			b1.start_energy= std::stod(attr);
			getline(s1, attr, delim);
			b1.max_energy= std::stod(attr);
			getline(s1, attr, delim);
			b1.race = attr;
			getline(s1, attr, delim);
			b1.produced_by =attr;
			getline(s1, attr, delim);
			b1.dependency = attr;

			// insert the entry into map1
			map1.insert(std::pair<std::string,Building>(b1.name, b1));
		}

	}	

	file_.close();

	// In the following way we can print the contents of map 
	std::cout << "Name of the Building" << "  -->  " << "# Mineral required\n";
	for( auto it = map1.begin(); it != map1.end(); ++it)	{

	std::cout <<  it->first  << " 	-->	 "  <<  (*it).second.mineral_req << "\n";

	}

	// If we want to access 'produced_by' attribute of a building we can do it the following way
	std::cout << "\n\n\nprobe is produced by" << (map1.find("probe")->second).produced_by <<"\n\n"; 
 

}

