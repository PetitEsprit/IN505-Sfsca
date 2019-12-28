#include <iostream>
#include "Login.hpp"
#include "System.hpp"

#define HELP_MSG "Type \"exit\", \"quit\" or \"q\" to quit the program"

bool	want_exit(string s)
{
	return (!s.compare("exit") || !s.compare("quit") || !s.compare("q"));
}

void	wait_enter()
{
	cout << "Press enter to continue...";
	cin.get();
	cin.get();
}

void	test_register()
{
	Login	lg;
	string	user, pass;
	int		r = -1;

	do
	{
		cout << "\033[2J\033[1;1H";
		if (!user.compare("help"))
			cout << HELP_MSG;
		if (lg.getErrorMessage().empty())
			cout << endl << endl;
		else
			cout << "error: " << lg.getErrorMessage() << endl << endl;
		cout << "new username: ";
		cin >> user;
		if (want_exit(user))
			break ;
		cout << "new password: ";
		cin >> pass;
	} while ((r = lg.create(user, pass)));
	if (!r)
	{
		cout << "Account created!\n";
		wait_enter();
	}
}

void	test_login()
{
	Login	lg;
	string	user, pass;

	do
	{
		cout << "\033[2J\033[1;1H";
		if (!user.compare("help"))
			cout << HELP_MSG;
		if (lg.getErrorMessage().empty())
			cout << endl << endl;
		else
			cout << "error: " << lg.getErrorMessage() << endl << endl;
		cout << "username: ";
		cin >> user;
		if (want_exit(user))
			break ;
		cout << "password: ";
		cin >> pass;
	} while (lg.login(user, pass));
	if (lg.isLogged())
	{
		cout << "Logged successfully!\n";
		cout << "Welcome, " << lg.getUsername() << "!\n";
		lg.logout();
		wait_enter();
	}
}

int		main()
{
	System sfsca;
	string s;

	do
	{
		if (!s.compare("1"))
			test_register();
		else if (!s.compare("2"))
			test_login();
		else if (!s.compare("3"))
			sfsca.run();
		cout << "\033[2J\033[1;1H";
		if (!s.compare("help"))
			cout << HELP_MSG;
		cout << "Type an option:\n\n";
		cout << " 1 - Register a new user\n";
		cout << " 2 - Login as an existing user\n";
		cout << " 3 - Launch sfsca\n";
		cout << "\n > ";
		cin >> s;
	} while (!want_exit(s));
	return 0;
}
