#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool LogIn(File datafile, string path, string login, string password)
{
    string login, password;

    string line, data = this->getLogin() + ' ' + this->getPassword();
    datafile.open(path, ios::in);
    if (datafile.is_open())
    {
        bool exitloop = true;
        while (getline(datafile, line, '\n') && exitloop)
        {
            if (line == data)
            {
                datafile.close();
                cout << "You are in" << endl;
                return true;
                exitloop = false;
                break;
            }
        }
    }
    else
    {
        cout << "Error opening file" << endl;
        return false;
    }
    datafile.close();
    cout << "Wrong login or password" << endl;
    return false;
}


int main()
{
	fstream file;
    string path = "file.txt";
    string login, password;
    cout << "Enter login: ";
    cin >> login;
    cout << "Enter password: ";
    cin >> password;
    LogIn(file, path, login, password);
   /* if (LogIn(file, path, login, password))
    {
        cout << "You are in" << endl;
    }
    else
    {
        cout << "wrong login or password" << endl;
    }*/
	return 0;
}