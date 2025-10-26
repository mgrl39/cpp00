/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 07:50:49 by meghribe          #+#    #+#             */
/*   Updated: 2025/10/26 07:50:50 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int		nbr_contacts;

	public:
		PhoneBook();
		int		add_contact();
		void	search_contacts();
};
