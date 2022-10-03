#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

int main() 
{
    string username, password, un, pw;
    int userChoice;
    bool verify;
    
    cout << "--------------------------------" << endl;
    cout << "Hello! Welcome to the Login Test\n--------------------------------\nWhat would you like to do today?";
    do 
    {
        cout << "\n\n1. Login\n2. Register\n3. Quit" << endl << endl;
        cout << "User Choice: ";
        cin >> userChoice;
    
        //acting as a gate to let users into the content or not
        switch(userChoice)
        {    
            //case 1 is for logging in, it checks the files in the system and if it has the file with the username and password it lets the user through. If it doesnt have the file it terminates (for right now)
            case 1: 
            {
                
                do 
                {
                    cout << "\nPlease enter your username: ";
                    cin >> username;
                    cout << "\nPlease enter your password: ";
                    cin >> password;
                    
                    ifstream read(username +".txt");
                    getline(read,un);
                    getline(read,pw);
                    
                    if(un == username && pw == password)
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n\nThere is no " << username << " currently in the system";
                        
                        verify = true;
                    }
                }
                while(verify);
                    
                    
                
                
            }
            break;
            //case 2 is to create a new user and inpute their data onto a file to be read later
            case 2:
            cout << "\n\nPlease enter a Username with no spaces: ";
            cin >> username;
            cout << "\nPlease enter a Password with no spaces: ";
            cin >> password;
            {
                ofstream file;
                file.open(username + ".txt");
                file << username << endl << password;
                cout << "\n\nWelcome " << username << "!" << endl;
                break;   
            }
            //terminates the programe 
            case 3:
            cout << "Goodbye!";
            return 0;
            
            //entered wrong input
            default: 
            cout << "You have entered an incorrect option, please try again";
            verify = true; 
        } 
        
    }
    while(verify);
    
    //CONTENT!!!!
    cout << "\n\nWelcome to your dashboard!";
    cout << "\n\nThere are no new messages for you " << username;
}