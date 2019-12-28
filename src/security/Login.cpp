#include <cctype>
#include <iostream>
#include "Login.hpp"
#include "sha512.hpp"

string const Login::error_msg[] =
{
	"",
	"L'utilisateur n'est pas connecté",
	"L'utilisateur est déjà connecté",
	"L'utilisateur n'existe pas",
	"L'utilisateur existe déjà",
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

Login::Login() : errcode(0) {}

Login::~Login()
{
	if (this->isLogged())
		fd.close();
}

int Login::create(string username, string password)
{
	string path;

	if (this->isLogged())
		return (errcode = LOGGED);
	if (fileExists(path = "data/" + username + ".dat"))
		return (errcode = USER_EXIST);
	if (username.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_-") != string::npos)
		return (errcode = USER_SPECIAL);
	if (!checkPassword(password))
		return (-1);
	fd.open(path, fstream::out);
	fd << sha512sum(username + password) << endl;
	fd.close();
	return (errcode = SUCCESS);
}

int Login::login(string username, string password)
{
	string hash;
	string path;

	if (this->isLogged())
		return (errcode = LOGGED);
	if (!fileExists(path = "data/" + username + ".dat"))
		return (errcode = INVALID_LOGIN);
	fd.open(path, fstream::in | fstream::out);
	getline(fd, hash);
	if (hash.length() != 128
		|| hash.find_first_not_of("abcdefABCDEF01234567890") != string::npos)
		errcode = CORRUPT_FILE;
	else if (hash.compare(sha512sum(username + password)))
		errcode = INVALID_LOGIN;
	else
	{
		this->username = username;
		this->password = password;
		this->hash = hash;
		errcode = SUCCESS;
	}
	if (errcode)
		fd.close();
	return (errcode);
}

int Login::logout()
{
	if (!this->isLogged())
		return (errcode = NOT_LOGGED);
	fd.close();
	this->username = "";
	this->password = "";
	this->hash = "";
	return (errcode = SUCCESS);
}

bool Login::isLogged()
{
	return (fd.is_open());
}

int Login::changePassword(string new_password)
{
	if (!this->isLogged())
		return (errcode = NOT_LOGGED);
	(void)new_password;
	return (errcode = SUCCESS);
}

string Login::getUsername()
{
	return (username);
}

string Login::getHash()
{
	return (hash);
}

string Login::getErrorMessage()
{
	return (error_msg[errcode]);
}
