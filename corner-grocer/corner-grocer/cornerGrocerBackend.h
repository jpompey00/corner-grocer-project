#ifndef CORNERGROCERBACKEND_H
#define CORNERGROCERBACKEND_H



#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

class CornerGrocerBackend
{
public : 
	std::map<std::string, int> getGroceryMap();
	void createGroceryMap();
	

private:

	void m_createBackup();
	std::map<std::string, int> m_groceryMap;
};

#endif // !CORNERGROCERBACKEND_H