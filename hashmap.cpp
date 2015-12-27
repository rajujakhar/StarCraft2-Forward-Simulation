/*This file has been written as part of forward simulation of Star Craft 2 game
This program reads the data from input csv files and stores them in a map with key, value pair

Author : Raju Ram
Last Modified : 28th Dec 2015
Version : 1.1

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
	std::map<std::string,Building> unit_map_Protoss, unit_map_Zerg, unit_map_Terran, building_map_Protoss, building_map_Zerg, building_map_Terran;
	char delim = ',';
	bool isUnit=true,isProtoss=true, isZerg=false, isTerran=false;
	std::string line,attr,blank("blank");

	std::ifstream file_;
	file_.open("techtrees.csv");

	// Read the entire line
	while(getline(file_, line)) {

		if(isUnit) { 
				if(line.substr(0,10) =="#buildings")
				{
					std::cout <<" line.substr(0,10): " << line.substr(0,10) << "\n";
					isUnit = false;
				}
			}
		if(isProtoss && !isUnit) {		
				if(line.substr(0,10) == "#  Zerg  #")
				{
					std::cout <<" line.substr(0,10): " << line.substr(0,10) << "\n";
					isProtoss = false;
					isZerg= true;
					isUnit = true;	
				}
			}
		if(isZerg && !isUnit) {	
				if(line.substr(0,10) == "# Terran #")
				{
					std::cout <<" line.substr(0,10): " << line.substr(0,10) << "\n";
					isZerg= false;
					isTerran = true;
					isUnit = true;
				}
			}	
				
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
			if(attr == "") attr = blank;	
			b1.dependency = attr;


			// insert the entry into map
			if(isProtoss) {
				if(isUnit)
					unit_map_Protoss.insert(std::pair<std::string,Building>(b1.name, b1));
				else 
					building_map_Protoss.insert(std::pair<std::string,Building>(b1.name, b1));
			}

			else if(isZerg) {
				if(isUnit)
					unit_map_Zerg.insert(std::pair<std::string,Building>(b1.name, b1));
				else 
					building_map_Zerg.insert(std::pair<std::string,Building>(b1.name, b1));
			}

			else {
				if(isUnit)
					unit_map_Terran.insert(std::pair<std::string,Building>(b1.name, b1));
				else 
					building_map_Terran.insert(std::pair<std::string,Building>(b1.name, b1));
			}
		}

	}	

	file_.close();

	// In the following way we can print the contents of map 
	std::cout << "Name of the Unit for Protoss" << "  -->  " << "# Mineral required\n";
	for( auto it = unit_map_Protoss.begin(); it != unit_map_Protoss.end(); ++it)	{

	std::cout <<  it->first  << " 	-->	 "  <<  (*it).second.mineral_req << "\n";

	}

	std::cout << "Name of the Building for Protoss" << "  -->  " << "# Mineral required\n";
	for( auto it = building_map_Protoss.begin(); it != building_map_Protoss.end(); ++it)	{

	std::cout <<  it->first  << " 	-->	 "  <<  (*it).second.mineral_req << "\n";

	}

	/*
	std::cout << "Name of the Unit for Zerg" << "  -->  " << "# Mineral required\n";
	for( auto it = unit_map_Zerg.begin(); it != unit_map_Zerg.end(); ++it)	{

	std::cout <<  it->first  << " 	-->	 "  <<  (*it).second.mineral_req << "\n";

	}

	std::cout << "Name of the Building for Zerg" << "  -->  " << "# Mineral required\n";
	for( auto it = building_map_Zerg.begin(); it != building_map_Zerg.end(); ++it)	{

	std::cout <<  it->first  << " 	-->	 "  <<  (*it).second.mineral_req << "\n";

	}

	std::cout << "Name of the Unit for Terran" << "  -->  " << "# Mineral required\n";
	for( auto it = unit_map_Terran.begin(); it != unit_map_Terran.end(); ++it)	{

	std::cout <<  it->first  << " 	-->	 "  <<  (*it).second.mineral_req << "\n";

	}

	std::cout << "Name of the Building for Terran" << "  -->  " << "# Mineral required\n";
	for( auto it = building_map_Terran.begin(); it != building_map_Terran.end(); ++it)	{

	std::cout <<  it->first  << " 	-->	 "  <<  (*it).second.mineral_req << "\n";

	} */

	// If we want to access 'produced_by' attribute of a building we can do it the following way
	//std::cout << "\n\n\nprobe is produced by" << (unit_map_Protoss.find("probe")->second).produced_by <<"\n\n"; 
 

}

