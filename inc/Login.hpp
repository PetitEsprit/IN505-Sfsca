#ifndef LOGIN_HPP
# define LOGIN_HPP
# include <fstream>
# include "Grade.hpp"

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
		static string const error_msg[];
		int		errcode;
		fstream	fd;
		string	username;
		string	password;
		string	hash;
		Grade	*history;

		// Returns true if the file exists
		bool	fileExists(string path);

		// Load user file history which contains all grades
		void	loadHistory();

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

		// Returns an error message based on the last error
		string	getErrorMessage();
};

#endif