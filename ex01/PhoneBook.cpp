#include "PhoneBook.hpp"
#include <iostream>

/*
static void	value_saver(std::string msg, std::string *value)
{
	std::cout << "\e[1;33m";
	std::cout << msg << ">\e[0m ";
	while (std::getline(std::cin, *value))
	{
		break ;
		std::cout << "\e[1;33m";
		std::cout << msg << ">\e[0m ";
	}
	std::cout << std::endl;
}
*/

void	PhoneBook::add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	// TODO: A saved contact can’t have empty fields
	std::cout << "\e[1;33mFIRST NAME >\e[0m "; 
	std::getline(std::cin, first_name);
	//std::getline(std::cin, first_name);
	std::cout << "\e[1;33mLAST NAME >\e[0m "; 
	std::getline(std::cin, last_name);
	std::cout << "\e[1;33mNICKNAME >\e[0m "; 
	std::getline(std::cin, nickname);
	std::cout << "\e[1;33mPHONE NUMBER >\e[0m "; 
	std::getline(std::cin, phone_number);
	std::cout << "\e[1;33mDARKEST SECRET >\e[0m "; 
	std::getline(std::cin, darkest_secret);

	Contact	new_contact(first_name, last_name, nickname,\
		phone_number, darkest_secret);

}

void	PhoneBook::search_contacts()
{

}

PhoneBook::PhoneBook()
{
}
