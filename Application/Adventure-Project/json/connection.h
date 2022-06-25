#include "json/json.h"
#include "json/value.h"
#include "json/md5.h"

void downloadJson(std::wstring email)
{

	std::ofstream fout(L"C:/Users/bojko/source/repos/test/test/json/items.json", std::ios::binary);
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
	ifstream file("C:/Users/bojko/source/repos/test/test/json/items.json");
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

void login()
{
	while (true) {
		system("cls");
		remove("json/items.json");
		std::wstring email;

		cout << "Your email: ";
		wcin >> email;

		downloadJson(email);

		string password;

		cout << "Your password: ";
		cin >> password;

		cout << endl;

		if (checkPassword(password))
		{
			cout << "You have login succesfuly";
			break;
		}
		else
			cout << "Access denied";

		remove("json/items.json");
	}
}

void signup()
{

}