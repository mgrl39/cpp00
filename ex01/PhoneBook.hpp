#pragma once

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];

	public:
		PhoneBook();
		void	add_contact();
		void	search_contacts();
};
