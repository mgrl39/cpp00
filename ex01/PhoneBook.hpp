/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 07:50:49 by meghribe          #+#    #+#             */
/*   Updated: 2025/10/26 10:26:17 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int		nbr_contacts;
		int		last_contact_updated;

	public:
		PhoneBook();
		~PhoneBook();
		void	set_last_contact_updated(int last_contact_updated);
		int		get_last_contact_updated(void);
		int		get_nbr_contacts(void);
		Contact get_contact(int index);
		int		add_contact();
};
