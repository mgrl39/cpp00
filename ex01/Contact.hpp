#include <string>

class Contact 
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		Contact(const std::string &_firstName, 
			const std::string &_lastName,
			const std::string &_nickname,
			const std::string &_phoneNumber,
			const std::string &_darkestSecret);
};
