#include "cornerGrocerBackend.h"



void CornerGrocerBackend::createGroceryMap() {

	
	std::ifstream inFS;
	std::string value;
	std::string fileName = "CS210_Project_Three_Input_File.txt";
	
	//opens the filestream
	inFS.open(fileName);

	//check incase the file cannot be opened.
	if (inFS.is_open() == false) {
		std::cout << "Coult not open " << fileName << std::endl;
		return;
	}

	//goes through each line of the file and adds it to the groceryMap.
	//If the key is already in the map, adds 1 to the value
	while (inFS.fail() == false) {
		inFS >> value;
		if (m_groceryMap.count(value) == 0) {
			m_groceryMap.emplace(value, 1);
		}
		else {
			m_groceryMap.at(value) = m_groceryMap.at(value) + 1;
		}
	}
	//if the file has left the loop before the end of file, returns an error message
	if (inFS.eof() == false) {
		std::cout << "Failure before end of file." << std::endl;
	}

	//closes the filestream
	inFS.close();
	

	//creates backupfile
	m_createBackup();
	
}


std::map<std::string, int> CornerGrocerBackend::getGroceryMap() {
	return m_groceryMap;
}



void CornerGrocerBackend::m_createBackup() {

	//opens the output filestream in the specified folder
	std::ofstream outFS;
	std::string path = "backups/frequency.dat";
	outFS.open(path);

	//if the file cant be opened, displays error message
	if (!outFS.is_open()) {
		std::cout << "Coult not open file at " << path << std::endl;
		return;
	}


	//iterates through the map made, outputting it to the output file stream.
	std::map < std::string, int>::iterator it;
	for (it = m_groceryMap.begin(); it != m_groceryMap.end(); it++) {

		outFS << it->first << " " << it->second << std::endl;
	}

	//closes the file
	outFS.close();
}