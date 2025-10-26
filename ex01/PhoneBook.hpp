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
