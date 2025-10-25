/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 07:50:31 by meghribe          #+#    #+#             */
/*   Updated: 2025/10/25 07:50:49 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	ft_toupper_args(int argc, char *argv[], std::string *msg)
{
	int	i;
	int	j;

	i = 1;
	*msg = "";
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			*msg += std::toupper(argv[i][j++]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	std::string	msg;

	msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (argc > 1)
		ft_toupper_args(argc, argv, &msg);
	std::cout << msg << std::endl;
	return (0);
}
