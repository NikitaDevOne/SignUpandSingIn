#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Registration()
{
    ofstream mainFile;
    ofstream fileDataOut;
    ifstream fileDataIn("userData.txt");

    string numberUsers[10000];

    string userEmail;
    string userName;
    string userPassword;

    bool isRegistred = true;

    cout << "\t\t\tRegistration\n";

    cout << "\tEnter email: ";
    cin >> userEmail;

    for (int i = 0;!fileDataIn.eof(); i++)
    {
        getline(fileDataIn, numberUsers[i]);

        if (numberUsers[i] == userEmail)
        {
            isRegistred = false;
        }
    }

    if (!isRegistred)
    {
        cout << "\tThis email is already taken!\n\n\n";

        return "This email is already taken";
    }
    else
    {
        fileDataOut.open("userData.txt", ios::app);

        fileDataOut << userEmail << endl;

        userEmail += ".txt";

        mainFile.open(userEmail);

        cout << "\tEnter name: ";
        cin >> userName;

        mainFile << userName << endl;

        if (mainFile.is_open())
        {
            cout << "\tEnter password: ";
            cin >> userPassword;

            mainFile << userPassword << endl;
            cout << "\t\t\tRegistration completed successfully!\n\n\n";

            return userName, userPassword;
        }

        fileDataOut.close();
        fileDataIn.close();
        mainFile.close();
    }
}

void Logged()
{
    ofstream fileOut;

    int choice;
    string userName;
    string userEmail;
    string userPassword;
    string name, password;

    cout << "\t\t\tLogged\n";
    cout << "\tEnter email: ";
    cin >> userEmail;

    userEmail += ".txt";

    ifstream fileIn(userEmail);
    
    if (fileIn.is_open())
    {
        cout << "\tEnter name: ";
        cin >> userName;

        cout << "\tEnter password: ";
        cin >> userPassword;

        getline(fileIn, name);
        getline(fileIn, password);
        
        if (name == userName && password == userPassword)
        {
            cout << "\t\t\tLogged in\n";
            cout << "\t\t\t1.Reset password\n";
  
            cout << "Choice: ";
            cin >> choice;

            if (choice == 1)
            {
                fileOut.open(userEmail);
                fileOut.seekp(0,ios::cur);

                cout << "\tEnter new password: ";
                cin >> userPassword;

                fileOut << userName << endl << userPassword;
                cout << "\t\t\tPassword successfully changed\n\n";
            }
            else
            {
                cout << "\t\t\tThis feature is not available\n\n";
            }
        }
        else
        {
            cout << "\t\t\tIncorrect data!\n\n";
        }
    }
    else
    {
        cout << "\t\t\tThis account does not exist\n\n";
    }

    fileIn.close();
    fileOut.close();
}


int main()
{
    int choice = 0;

    do
    {
        cout << "\t\t\tMain menu\n";
        cout << "\t\t\t1.Registration\n\t\t\t2.Logged\n";

        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Registration();
        }
        else if (choice == 2)
        {
            Logged();
        }
        else
        {
            cout << "\t\t\tThis feature is not available\n\n";
        }
    } while (choice == 1 || choice == 2);
}
