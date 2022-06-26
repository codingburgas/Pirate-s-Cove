#include "json/json.h"
#include "json/value.h"
#include "json/md5.h"
#include <regex>

char error;

void downloadJson(std::wstring email)
{

	std::ofstream fout(L"items.json", std::ios::binary);
	std::wstring url = L"https://piratescove.maxprogress.bg/inc/api.php?email=" + email;
	HINTERNET hopen = InternetOpen(L"MyAppName", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (hopen)
	{
		DWORD flags = INTERNET_FLAG_DONT_CACHE;
		if (url.find(L"http://") == 0)
			flags |= INTERNET_FLAG_SECURE;
		HINTERNET hinternet = InternetOpenUrl(hopen, url.c_str(), NULL, 0, flags, 0);
		if (hinternet)
		{
			char buf[1024];
			DWORD received = 0;
			while (InternetReadFile(hinternet, buf, sizeof(buf), &received))
			{
				if (!received) break;
				fout.write(buf, received);
			}
			InternetCloseHandle(hinternet);
		}
		InternetCloseHandle(hopen);
	}
}

Json::Value readJson()
{
	ifstream file("items.json");
	Json::Value actualJson;
	Json::Reader reader;

	reader.parse(file, actualJson);

	return actualJson;
}

string to_string(Json::Value c)
{
	ostringstream ss;
	ss << c;
	return ss.str();
}

bool checkPassword(string password)
{
	Json::Value json = readJson();

	string hashPassword = to_string(json["password"]);

	hashPassword = hashPassword.substr(1, hashPassword.size() - 2);

	if (md5(password) == hashPassword) {
		return true;
	}

	return false;
}

bool is_email_valid(const std::string& email)
{
	// define a regular expression
	const std::regex pattern
	("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	// try to match the string with the regular expression
	return std::regex_match(email, pattern);
}

void errorForSignup(char error) 
{
	switch (error)
	{
		case 'e':
		{
			cout << "Your email does not meet the requirements" << endl;
			break;
		}
		case 't':
		{
			cout << "This email is already taken" << endl;
			break;
		}
		case 'l':
		{
			cout << "Your password should be with more than 3 characters" << endl;
			break;
		}
		case 'p':
		{
			cout << "Your passwords does not match" << endl;
			break;
		}
		default:
		{
			cout << "Sign Up" << endl;
			break;
		}
	}
}

void errorsForLogin(char error)
{
	switch (error)
	{
		case 'i':
		{
			cout << "Invalid login!" << endl;
			break;
		}
		default:
		{
			cout << "Log In" << endl;
			break;
		}
	}
}

void login()
{
	remove("items.json");
	while (true) {
		system("cls");

		errorsForLogin(error);

		error = ' ';

		wstring email;

		cout << "Your email: ";
		wcin >> email;

		string emailStr(email.begin(), email.end());

		downloadJson(email);

		string password;

		cout << "Your password: ";
		cin >> password;

		cout << endl;

		if (checkPassword(password))
		{
			cout << "You have logged successfully!";
			remove("items.json");
			break;
		} else {
			error = 'i';
		}

		remove("items.json");
	}
}

void signup()
{
	while (true) {
		system("cls");
		wstring email;

		errorForSignup(error);

		cout << "Your email: ";
		wcin >> email;

		string emailStr(email.begin(), email.end());

		downloadJson(email);
		Json::Value json = readJson();

		string emailJson = to_string(json["email"]);

		emailJson = emailJson.substr(1, emailJson.size() - 2);

		if (is_email_valid(emailStr)) {

			if (emailStr != emailJson) {
				string password;

				cout << "Your password: ";
				cin >> password;

				string repassword;

				cout << "Your password: ";
				cin >> repassword;

				if (password.length() > 3 && repassword.length() > 3) {

					password = md5(password);
					repassword = md5(repassword);

					string link = "https://piratescove.maxprogress.bg/inc/create.inc.php?email=" + emailStr + "&password=" + password;

					wstring temp = wstring(link.begin(), link.end());

					LPCWSTR newLink = temp.c_str();

					if (password == repassword) {
						ShellExecute(0, 0, newLink, 0, 0, SW_SHOW);
						login();
						break;
					}
					else
						error = 'p';
				}
				else
					error = 'l';
			}
			else
				error = 't';
		} else
			error = 'e';
		

	}
}