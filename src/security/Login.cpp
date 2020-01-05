#include <cctype>
#include <iostream>
#include <stdio.h>
#include "Login.hpp"
#include "sha512.hpp"

Login::Login() : errcode(0) {}

Login::~Login()
{
	this->logout();
}

string const Login::error_msg[] =
{
	"",
	"L'utilisateur n'est pas connecté",
	"L'utilisateur est déjà connecté",
	"L'utilisateur n'existe pas",
	"L'utilisateur existe déjà",
	"Le nom de l'utilisateur doit au moins contenir 4 charactères",
	"Le mot de passe contient des caractères illégaux",
	"Le mot de passe doit contenir au moins un chiffre, une majuscule, une minuscule et un caractère spécial",
	"Le mot de passe doit faire au minimum 10 caractères",
	"Les mots de passes ne correspondent pas",
	"Le fichier de données est corrompu",
	"Le nom de l'utilisateur ne doit pas contenir de caractères spéciaux",
	"Nom d'utilisateur ou mot de passe invalide"
};

bool Login::fileExists(string path)
{
	ifstream file(path.c_str());
	return (file.is_open());
}

string Login::getHistoryHash()
{
	string s;

	s = sha512sum(hash + password);
	for (Grade& g : history)
		s = sha512sum(s + to_string(g.getTimestamp() + g.getGrade()));
	return (s);
}

void Login::loadHistory()
{
	string	history_hash;
	string	s;
	float	g;
	int		t, r;

	r = 0;
	getline(fd, history_hash);
	while (getline(fd, s) && (r = sscanf(s.c_str(), "%d,%f", &t, &g)) == 2)
		history.push_back(Grade(g, t));
	if (r < 0 || !fd.eof() || history_hash.compare(getHistoryHash()))
		errcode = CORRUPT_FILE;
	else
		errcode = SUCCESS;
	size = history.size();
	cout << history.size() << endl;
}

bool Login::checkPassword(string password)
{
	if (password.length() < 10)
		return !(errcode = WEAK_PASS_LEN);
	bool digit = 0, up = 0, low = 0, special = 0;
	unsigned int i = 0;

	while (i < password.length())
	{
		if (isdigit(password[i]))
			digit = 1;
		else if (isupper(password[i]))
			up = 1;
		else if (islower(password[i]))
			low = 1;
		else if (isprint(password[i]) && !isspace(password[i]))
			special = 1;
		else
			break ;
		++i;
	}
	if (i < password.length())
		return !(errcode = ILLEGAL_PASS);
	if (digit && up && low && special)
		return (1);
	return !(errcode = WEAK_PASS);
	
}

int Login::create(string username, string password)
{
	string path;
	string hash;

	if (this->isLogged())
		return (errcode = LOGGED);
	if (username.length() < 4)
		return (errcode = USER_LEN);
	if (fileExists(path = "data/" + username + ".dat"))
		return (errcode = USER_EXIST);
	if (username.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_-") != string::npos)
		return (errcode = USER_SPECIAL);
	if (!checkPassword(password))
		return (errcode);
	fd.open(path, fstream::out);
	hash = sha512sum(username + password);
	fd << hash << endl;
	fd << sha512sum(hash + password) << endl;
	fd.close();
	return (errcode = SUCCESS);
}

int Login::login(string username, string password)
{
	string path;

	if (this->isLogged())
		return (errcode = LOGGED);
	if (!fileExists(path = "data/" + username + ".dat"))
		return (errcode = INVALID_LOGIN);
	fd.open(path, fstream::in | fstream::out);	
	this->username = username;
	this->password = password;
	if (!getline(fd, this->hash) || this->hash.length() != 128
		|| this->hash.find_first_not_of("abcdefABCDEF01234567890") != string::npos)
		errcode = CORRUPT_FILE;
	else if (this->hash.compare(sha512sum(username + password)))
		errcode = INVALID_LOGIN;
	else
		loadHistory();
	if (errcode)
	{
		fd.close();
		this->username = "";
		this->password = "";
		this->hash = "";
		history.clear();
	}
	else
		errcode = SUCCESS;
	return (errcode);
}

int Login::logout()
{
	if (!this->isLogged())
		return (errcode = NOT_LOGGED);
	fd.clear();
	fd.seekp(0, ios_base::end);
	for (Grade& g : history)
		if (size)
			--size;
		else
			fd << g.getTimestamp() << ',' << g.getGrade() << endl;
	fd.seekp(129, ios_base::beg);
	fd << getHistoryHash();
	fd.close();
	username = "";
	password = "";
	hash = "";
	history.clear();
	return (errcode = SUCCESS);
}

bool Login::isLogged()
{
	return (fd.is_open());
}

string Login::getUsername()
{
	return (username);
}

string Login::getErrorMessage()
{
	return (error_msg[errcode]);
}

void Login::addEntry(float grade)
{
	if (!this->isLogged())
		return ;
	history.push_back(Grade(grade));
}

float Login::getAverage()
{
	double	n;
	size_t	total;

	total = history.size();
	n = 0;
	for (Grade& g : history)
		n += g.getGrade();
	return (total ? n / total : 0);
}

list <Grade>	&Login::getHistory()
{
	return (history);
}
