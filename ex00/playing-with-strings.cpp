/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:09:24 by meghribe          #+#    #+#             */
/*   Updated: 2025/08/10 13:30:02 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

# define DEFAULT_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

/*
void	convertAndPrint(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			std::cout << (char)std::toupper(argv[i][j++]);
		i++;
	}
}*/

std::string convert(int argc, char *argv[])
{
	std::string args;
	int		i;

	args = "";
	i = 1;
	while (i < argc)
	{
		args += argv[i];
		i++;
	}
	return (args);
}

int	main(int argc, char *argv[])
{
	//std::cout << convert(argc, argv);
	std::cout << (argc < 2 ? DEFAULT_MSG : convert(argc, argv)) << std::endl;
	return (0);
	/*
	if (argc < 2)
		std::cout << DEFAULT_MSG;
	else
		convertAndPrint(argc, argv);
		*/
	return (std::cout << std::endl, 0);
}
