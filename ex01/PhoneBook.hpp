#pragma once

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];

	public:
		PhoneBook();
		int	add_contact();
		void	search_contacts();
};
