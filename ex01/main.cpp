/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 08:09:08 by meghribe          #+#    #+#             */
/*   Updated: 2025/10/26 12:01:44 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

int	loop_data_saver(std::string var_name, std::string *var);
int 	phone_verify_if_all_numbers(std::string phone_number);

static void	print_welcome(void)
{
	std::string	welcome;

	welcome = "\e[0;31m░█▀█░█░█░█▀█░█▀█░█▀▀░█▀▄░█▀█░█▀█░█░█\n\
░█▀▀░█▀█░█░█░█░█░█▀▀░█▀▄░█░█░█░█░█▀▄\n\
░▀░░░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀░░▀▀▀░▀▀▀░▀░▀\n\e[0m";
	std::cout << welcome << std::endl;
}

static void	print_available_orders(void)
{
	std::string	order_list;

	order_list = "\e[1;33mORDERS \e[0;32m▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰\n";
	order_list += "\e[1;32mADD\e[0m: save a new contact\n";
	order_list += "\e[1;32mSEARCH\e[0m: display a specific contact\n";
	order_list += "\e[1;32mEXIT\e[0m: the program quits\n";
	order_list += "\e[0;32m▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰\n\e[0m";
	std::cout << order_list << std::endl;
}

static void	draw_column_name(std::string name, bool truncate)
{
	if (truncate)
		name = name.length() > 10 ? (name.substr(0, 9) + ".") : name;
	std::cout << "|" << std::right << std::setw(10) << name;
}

static int	show_specific_contact(PhoneBook phoneBook, int nbr_contacts)
{
	std::string	hola;

	(void)nbr_contacts;
	(void)phoneBook;
	return (0);
}

static int	show_phonebook_contacts(PhoneBook phoneBook)
{
	int	nbr_contacts;
	Contact	actual_contact;

	nbr_contacts = phoneBook.get_nbr_contacts();
	if (nbr_contacts == 0)
	{
		std::cout << "There are no contacts" << std::endl;
		return (0);
	}
	int	i;
	int	j;

	i = 0;
	while (i++ < 4)
		std::cout << "|" << "==========";
	std::cout << "|" << std::endl;
	draw_column_name("INDEX", false);
	draw_column_name("FIRST NAME", false);
	draw_column_name("LAST NAME", false);
	draw_column_name("NICKNAME", false);
	std::cout << "|" << std::endl;
	j = -1;
	while (++j < nbr_contacts)
	{
		std::cout << "|" << std::right << std::setw(10) << (j + 1);
		actual_contact = phoneBook.get_contact(j);
		draw_column_name(actual_contact.get_first_name(), true);
		draw_column_name(actual_contact.get_last_name(), true);
		draw_column_name(actual_contact.get_nickname(), true);
		std::cout << "|" << std::endl;
	}
	while (--i)
		std::cout << "|" << "----------";
	std::cout << "|" << std::endl;
	std::cout << std::endl;
	if (show_specific_contact(phoneBook, nbr_contacts) == 1)
		return (1);
	return (0);
}

static void	order_loop(void)
{
	PhoneBook	phoneBook;
	std::string	order;

	print_available_orders();
	std::cout << "\e[1;33m>\e[0m ";
	while (std::getline(std::cin, order))
	{
		if (order == "EXIT")
			break ;
		if (order == "ADD" && phoneBook.add_contact())
				break ;
		else if (order == "SEARCH" && show_phonebook_contacts(phoneBook))
				break ;
		print_available_orders();
		std::cout << "\e[1;33m>\e[0m ";
	}
	std::cout << "\e[1;33m> > > > > > BYEEE\e[0m " << std::endl;
}

int	main(void)
{
	return (print_welcome(), order_loop(), 0);
}
