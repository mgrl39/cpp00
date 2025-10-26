/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 07:50:39 by meghribe          #+#    #+#             */
/*   Updated: 2025/10/26 11:59:23 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

/*
 * Returns 1 if phone_number empty or is not only numbers
 * Returns 0 if phone_number is only numbers
 */
int 	phone_verify_if_all_numbers(std::string phone_number)
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
int	loop_data_saver(std::string var_name, std::string *var)
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
	Contact		new_contact;
	new_contact.set_first_name(first_name);
	new_contact.set_last_name(last_name);
	new_contact.set_nickname(nickname);
	new_contact.set_phone_number(phone_number);
	new_contact.set_darkest_secret(darkest_secret);
	if (this->nbr_contacts != 8)
	{
		this->contacts[this->nbr_contacts % 8] = new_contact;
		if (this->nbr_contacts >= 0 && this->nbr_contacts < 8)
			this->nbr_contacts++;
		last_contact_updated = nbr_contacts;
	}
	else if (nbr_contacts == 8)
	{
		if (last_contact_updated == 8)
			last_contact_updated = 0;
		this->contacts[this->last_contact_updated % 8] = new_contact;
		last_contact_updated++;
	}
	return (0);
}

PhoneBook::PhoneBook()
{
	this->nbr_contacts = 0;
}

PhoneBook::~PhoneBook()
{
}

int		PhoneBook::get_last_contact_updated(void)
{
		return (this->last_contact_updated);
}

void	PhoneBook::set_last_contact_updated(int last_contact_updated)
{
	this->last_contact_updated = last_contact_updated;
}

int		PhoneBook::get_nbr_contacts(void)
{
		return (this->nbr_contacts);
}

Contact	PhoneBook::get_contact(int index)
{
		return (this->contacts[index]);
}
