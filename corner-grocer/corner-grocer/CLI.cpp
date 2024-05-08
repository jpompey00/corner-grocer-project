#include "CLI.h"

void CLI::mainMenu() {

	cgb.createGroceryMap();
	//welcome message

	std::string input;

	//display options

	while (active){

		int selection;

		std::getline(std::cin, input);
		std::stringstream ss(input);
		//maybe define the map here



		//checks if the correct value was inputted
		while (!(ss >> selection) || selection > 4 || selection < 1) {

			std::cout << "Wrong" << std::endl; //TODO: fix this message
			std::getline(std::cin, input);

			//need to clear the string stream before retrying
			ss.clear(); //clears the flags it raised
			ss.str(""); //emptied the string
			ss << input; //set the new input to the string stream
		}



		switch (selection) {
		case 1:
			std::cout << "option 1" << std::endl;
			m_findItem();

		case 2:
			std::cout << "option 2" << std::endl;
			//item purchase frequency
			m_itemPurchaseFrequency(cgb.getGroceryMap());

		case 3: 
			//item histogram
			std::cout << "option 3" << std::endl;
			m_itemHistogram(cgb.getGroceryMap());

		case 4:
			std::cout << "option 4" << std::endl;
			m_exitProgram();
		}
	}

}





void CLI::m_findItem() {
	//prompt them to look for an item
	std::string input;


	std::string itemToFind;

	std::getline(std::cin, input);

	std::stringstream ss(input);

	//checks if the value is only a string and not a digit
	while (!(ss >> itemToFind) || 
		std::find_if(itemToFind.begin(),itemToFind.end(), std::isdigit)!=itemToFind.end()) {

		std::cout << "Invalid Input" << std::endl; //TODO: fix this message
		std::getline(std::cin, input);

		//need to clear the string stream before retrying
		ss.clear(); //clears the flags it raised
		ss.str(""); //emptied the string
		ss << input; //set the new input to the string stream
	}
	
	//changes the input to a normalized format to check in the map.
	itemToFind[0] = toupper(itemToFind[0]);
	std::transform(itemToFind.begin() + 1, itemToFind.end(),
		itemToFind.begin() + 1, ::tolower);


	if (cgb.getGroceryMap().count(itemToFind) == 1) {
		std::cout << itemToFind << ": " << cgb.getGroceryMap().at(itemToFind) << std::endl;
	}
	else {
		std::cout << "item not found" << std::endl;
	}

}


void CLI::m_itemPurchaseFrequency(std::map<std::string, int> groceryMap) {
	
	std::map < std::string, int>::iterator it;
	
	for (it = groceryMap.begin(); it != groceryMap.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}

}

void CLI::m_itemHistogram(std::map<std::string, int> groceryMap) {
	std::map < std::string, int>::iterator it;

	for (it = groceryMap.begin(); it != groceryMap.end(); it++) {
		std::cout << it->first << " ";
		std::cout << std::setfill('*') << std::setw(it->second) << '*';

		//for (int i = 0; i < it->second; i++) {
		//	std::cout << "*";
		//}
		std::cout << std::endl;
	}
}

void CLI::m_exitProgram() {
	active = false;
}