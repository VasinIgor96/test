#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool LogIn(fstream &file, string path, string login, string password)
{
    string line, data = login + ' ' + password;
    file.open(path, ios::in);
    if (file.is_open())
    {
        bool exitloop = true;
        int counter = 0;
        string buf;
        while (getline(file, line, '\n') || exitloop)
        {
            buf += line;
            counter++;
            cout << "Counter: " << counter << endl;
            if (line == data)
            {
                cout << "If.." << endl;
                file.close();
                return true;
                exitloop = false;
                break;
            }
            else
            {
                cout << "else.." << endl;                
            }
        }
        cout << buf << endl;
    }
    else
    {
        cout << "Error opening file" << endl;
        return false;
    }
    file.close();
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
    if (LogIn(file, path, login, password))
    {
        cout << "You are in" << endl;
    }
    else
    {
        cout << "wrong login or password" << endl;
    }
	return 0;
}