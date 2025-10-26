/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 07:50:39 by meghribe          #+#    #+#             */
/*   Updated: 2025/10/26 09:21:06 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

/*
 * Returns 1 if phone_number empty or is not only numbers
 * Returns 0 if phone_number is only numbers
 */
static int 	phone_verify_if_all_numbers(std::string phone_number)
{
	int	i;

	if (phone_number.length() <= 0)
		return (1);
	i = 0;
	while (phone_number[i] != '\0')
	{
		if (std::isdigit(phone_number[i++]))
			continue ;
		std::cout << "only numbers" << std::endl;
		return (1);
	}
	return (0);
}

/* 
 * Function to not be repeating the same in add_contact.
 * This one checks if its EOF or empty.
 * If the string is empty, alerts that cannot be empty and asks again the
 * content of the variable.
 * If is EOF we return 1 as FAIL.
 * If everything OK is 0
 */
static int	loop_data_saver(std::string var_name, std::string *var)
{
	while (1)
	{
		std::cout << "\e[1;33m";
		std::cout << var_name;
		std::cout <<  ">\e[0m ";
		std::getline(std::cin, *var);
		if (std::cin.fail())
		{
			if (std::cin.eof())
				std::cout << std::endl;
			std::cin.clear();
			std::cout << "\e[1;31mFAIL\e[0m" << std::endl;
			return (1);
		}
		if ((*var).length() == 0)
		{
			std::cout << "cannot be empty..." << std::endl;
			continue ;
		}
		break ;
	}
	return (0);
}

// Returns 1 if fails
// Returns 0 if success
// A saved contact can’t have empty fields
int	PhoneBook::add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	if (loop_data_saver("FIRST NAME", &first_name) == 1)
		return (1);
	if (loop_data_saver("LAST NAME", &last_name) == 1)
		return (1);
	if (loop_data_saver("NICKNAME", &nickname) == 1)
		return (1);
	do {
		if (loop_data_saver("PHONE NUMBER", &phone_number) == 1)
			return (1);
	}
	while (phone_verify_if_all_numbers(phone_number));
	if (loop_data_saver("DARKEST SECRET", &darkest_secret) == 1)
		return (1);
	Contact	new_contact(first_name, last_name, nickname,\
		phone_number, darkest_secret);
	// TODO: SAVE CONTACTS
	this->contacts[this->nbr_contacts % 8] = new_contact;
	if (nbr_contacts >= 0 && nbr_contacts < 8)
		nbr_contacts++;
	return (0);
}

static void	draw_column_name(std::string name)
{
	std::cout << "|" << std::right << std::setw(10) << name;
}

void	PhoneBook::search_contacts()
{
	if (this->nbr_contacts == 0)
	{
		std::cout << "There are no contacts" << std::endl;
		return ;
	}
	int	i;
	int	j;

	i = 0;
	while (i++ < 4)
		std::cout << "|" << "==========";
	std::cout << "|" << std::endl;
	draw_column_name("INDEX");
	draw_column_name("FIRST NAME");
	draw_column_name("LAST NAME");
	draw_column_name("NICKNAME");
	std::cout << "|" << std::endl;
	j = -1;
	while (++j < this->nbr_contacts)
	{
		std::cout << "|" << std::right << std::setw(10) << (j + 1);
		// TODO: HERE IS WHERE WE NEED THE GETTERS :/
		draw_column_name(this->contacts[j].get_first_name());
		draw_column_name(this->contacts[j].get_last_name());
		draw_column_name(this->contacts[j].get_nickname());
		std::cout << "|" << std::endl;
	}
	while (--i)
		std::cout << "|" << "----------";
	std::cout << "|" << std::endl;
	std::cout << std::endl;
}

PhoneBook::PhoneBook()
{
	this->nbr_contacts = 0;
}
