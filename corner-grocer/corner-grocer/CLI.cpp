#include "CLI.h"

void CLI::mainMenu() {

	cgb.createGroceryMap();
	std::cout << "Welcome to the Corner Grocer Application" << std::endl;

	std::string input;

	while (active){
		//The main menu options
		m_printMainMenuOptions();


		int selection;

		std::getline(std::cin, input);
		std::stringstream ss(input);

		//checks if the the value is an integer between 1 and 4
		while (!(ss >> selection) || selection > 4 || selection < 1) {

			std::cout << "Please Enter a Valid Input" << std::endl; 
			std::getline(std::cin, input);

			//need to clear the string stream before retrying
			ss.clear(); //clears the flags it raised
			ss.str(""); //emptied the string
			ss << input; //set the new input to the string stream
		}


		//the logic of the main menu using a switch statement
		switch (selection) {
		case 1: //Finding the Entered Item
			m_findItem();
			break;

		case 2: //Printing the freqeuncy of the items
			m_itemPurchaseFrequency(cgb.getGroceryMap());
			break;

		case 3: //Printing A histogram of the Items
			m_itemHistogram(cgb.getGroceryMap());
			break;

		case 4: //Exits the Program
			m_exitProgram();
			break;
		}
	}

}





void CLI::m_findItem() {
	std::cout << "Please Enter an Item Name to Search: " << std::endl;

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
		std::cout << std::endl;
		std::cout << itemToFind << ": " << cgb.getGroceryMap().at(itemToFind) << std::endl;
	}
	else {
		std::cout << std::endl;
		std::cout << "item not found" << std::endl;
	}

	m_printSpacing();
}


void CLI::m_itemPurchaseFrequency(std::map<std::string, int> groceryMap) {
	std::cout << "Printing the Item Frequency";
	m_printSpacing();


	//iterates through the map and returns each K/V pair
	std::map < std::string, int>::iterator it;
	
	for (it = groceryMap.begin(); it != groceryMap.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}

	m_printSpacing();

}

void CLI::m_itemHistogram(std::map<std::string, int> groceryMap) {
	std::cout << "Printing Histogram of Purchased Items";
	m_printSpacing();


	//loops through the map and returns the K/V pairs as Keys and a number of stars
	std::map < std::string, int>::iterator it;

	for (it = groceryMap.begin(); it != groceryMap.end(); it++) {
		std::cout << it->first << " ";
		std::cout << std::setfill('*') << std::setw(it->second) << '*';
		std::cout << std::endl;
	}

	m_printSpacing();
}

void CLI::m_exitProgram() {
	std::cout << "Exiting Program";
	m_printSpacing();


	//exits the program
	active = false;
}

void CLI::m_printMainMenuOptions() {
	//printing the options to the console
	std::cout << std::endl << std::setfill('=') << std::setw(40) << "=" << std::endl;
	std::cout << "Please Select an option" << std::endl
		<< "1. Find Item" << std::endl
		<< "2. Item Purchase Frequency" << std::endl
		<< "3. Item Historgram" << std::endl
		<< "4. Exit Program" << std::endl;
	std::cout << std::setfill('=') << std::setw(40) << "=" << std::endl
		<< std::endl;
}

void CLI::m_printSpacing() {
	std::cout << std::endl;
	system("pause");
	std::cout << std::endl;
}