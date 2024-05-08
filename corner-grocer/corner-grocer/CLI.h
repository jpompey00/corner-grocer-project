#ifndef CLI_H
#define CLI_H


#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <iomanip>
#include "cornerGrocerBackend.h"


class CLI
{
public:
	CornerGrocerBackend cgb;
	void mainMenu(); //starting menu


private:
	void m_findItem();//menu option 1
	void m_itemPurchaseFrequency(std::map<std::string, int> t_groceryMap); //menu option 2
	void m_itemHistogram(std::map<std::string, int> t_groceryMap); //menu option 3
	void m_exitProgram(); //menu option 4
	void m_printMainMenuOptions();
	void m_printSpacing();
	bool active = true;

};

#endif // !CLI_H