/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 08:09:08 by meghribe          #+#    #+#             */
/*   Updated: 2025/10/25 08:58:54 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

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

int	main(int argc, char *argv[])
{
	std::string	order;

	print_welcome();
	while (order != "EXIT")
	{
		print_available_orders();
		order = "EXIT";
	}
	return (0);
}
