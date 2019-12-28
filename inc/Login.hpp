#ifndef LOGIN_HPP
# define LOGIN_HPP
#include <fstream>
# include <string>

using namespace std;

enum e_login_errcode
{
	SUCCESS,
	NOT_LOGGED,
	LOGGED,
	USER_NOT_EXIST,
	USER_EXIST,
	ILLEGAL_PASS,
	WEAK_PASS,
	WEAK_PASS_LEN,
	PASS_NOT_MATCH,
	CORRUPT_FILE,
	USER_SPECIAL,
	INVALID_LOGIN
};

class Login
{
	private:
		int errcode;
		static string const error_msg[];
		fstream fd;
		string username;
		string password;
		string hash;

		// Returns true if the file exists
		bool fileExists(string path);

		// Returns true if the password is secure
		bool	checkPassword(string password);

	public:
		Login();
		~Login();
	
		// Create a new user, returns -1 on error
		int		create(string username, string password);

		// Log in to a user, returns -1 on error
		int		login(string username, string password);

		// Log out, returns -1 on error
		int		logout();

		// Returns true if user is logged
		bool	isLogged();

		// Change an user password, returns -1 on error
		int		changePassword(string new_password);

		// Returns the username
		string	getUsername();

		// Returns the hash
		string	getHash();

		// Returns an error message based on the last error
		string	getErrorMessage();
};

#endif
