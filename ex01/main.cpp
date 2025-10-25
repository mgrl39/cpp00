/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 08:09:08 by meghribe          #+#    #+#             */
/*   Updated: 2025/10/25 11:39:02 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void	print_welcome(void)
{
	std::string	welcome;

	welcome = "\e[0;31m░█▀█░█░█░█▀█░█▀█░█▀▀░█▀▄░█▀█░█▀█░█░█\n\
░█▀▀░█▀█░█░█░█░█░█▀▀░█▀▄░█░█░█░█░█▀▄\n\
░▀░░░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀░░▀▀▀░▀▀▀░▀░▀\n\e[0m";
	std::cout << welcome << std::endl;
}

void	print_available_orders(void)
{
	std::string	order_list;

	order_list = "\e[1;33mORDERS \e[0;32m▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰\n";
	order_list += "\e[1;32mADD\e[0m: save a new contact\n";
	order_list += "\e[1;32mSEARCH\e[0m: display a specific contact\n";
	order_list += "\e[1;32mEXIT\e[0m: the program quits\n";
	order_list += "\e[0;32m▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰▰\n\e[0m";
	std::cout << order_list << std::endl;
}

void	add(void)
{
}

void	search(void)
{
}

void	order_loop(void)
{
	PhoneBook	phoneBook;
	std::string	order;

	print_available_orders();
	std::cout << "\e[1;33m>\e[0m ";
	while (std::getline(std::cin, order))
	{
		if (order == "EXIT")
			break ;
		if (order == "ADD")
			phoneBook.add_contact();
		else if (order == "SEARCH")
			search();
		else
			order = "";
		print_available_orders();
		std::cout << "\e[1;33m>\e[0m ";
	}
	std::cout << "\e[1;33m> > > > > > BYEEE\e[0m " << std::endl;
}

int	main(void)
{
	print_welcome();
	order_loop();
	return (0);
}
