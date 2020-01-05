#ifndef LOGIN_HPP
# define LOGIN_HPP
# include <fstream>
# include <list>
# include "Grade.hpp"

enum e_login_errcode
{
	SUCCESS,
	NOT_LOGGED,
	LOGGED,
	USER_NOT_EXIST,
	USER_EXIST,
	USER_LEN,
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
		int				errcode;
		fstream			fd;
		string			username;
		string			password;
		string			hash;
		list <Grade>	history;
		size_t			size;

		// Returns true if the file exists
		bool	fileExists(string path);

		// Returns the hash of the history
		string	getHistoryHash();

		// Load user file history which contains all grades
		void	loadHistory();

		// Returns true if the password is secure
		bool	checkPassword(string password);

	public:
		Login();
		~Login();
	
		// Create a new user, returns 0 on success
		int		create(string username, string password);

		// Log in to a user, returns 0 on success
		int		login(string username, string password);

		// Log out, returns 0 on success
		int		logout();

		// Returns true if user is logged
		bool	isLogged();

		// Returns the username
		string	getUsername();

		// Returns an error message based on the last error
		string	getErrorMessage();

		// Add a new grade between 0.0 and 10.0 if user is connected
		void	addEntry(float grade);

		// Get grades average for current user
		float	getAverage();

		// Get grades for current user
		list <Grade>	&getHistory();
};

#endif
