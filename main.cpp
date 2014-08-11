//
//  main.cpp
//  cis2252_final_project
//
//  Created by thomas j. elward on 8/6/14.
//  Copyright (c) 2014 tje. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

int enterChoice();
void outputLine(int , string, double);


//enum choices { LOGIN = 1, REQUEST = 2, INVOICE = 3, PROCESS = 4, END = 5 };
enum choices { REQUEST = 1, INVOICE = 2, PROCESS = 3, END = 4 };

int main()
{
          //file processing mockup
    ifstream inOut("/Users/tj/Documents/cis2252/cis2252_final_project/cis2252_final_project/backend/CUSTOMERS.TXT",ios::in);
//    ifstream inOut("./backend/CUSTOMERS.TXT",ios::in);

    if (!inOut) {
        cerr << "File not found"<< endl;
        exit (EXIT_FAILURE);
    }
    
    int account;
    string name;
    double balance;
    
    cout << left << setw(10) << "Account" <<setw(13) <<"number" << "balance" <<endl << fixed<< showpoint;
    
    while (inOut >> account >> name >> balance) {
        outputLine (account,name, balance);
    }
    
    
    int menuChoice;

    while ( ( menuChoice = enterChoice()) != END ) {
        switch (menuChoice) {
            /*case LOGIN:
                cout << "please enter your user id number: ";
                int userID;
                cin >> userID;
                
                break; */

            case REQUEST:
                cout << "please enter the txt file to import for processing: ";
            //    string requestPath;
            //    getline(cin, requestPath);
                break;
            case INVOICE:
                cout <<"processing transactions and updating inventory please wait...";
                break;
            case PROCESS:
                cout << "doing work please wait while reciept is printed to screen";
                break;
            default:
                cerr << "Incorrect choice!"<<endl;
                break;
        }
        
    }
    
}


void outputLine(int account, string name, double balance) {
    cout << left << setw(10) << account << setw(13) << name << setw(7) << setprecision(2) << right << balance <<endl;
}

int enterChoice() {
    cout << "Welcome to the store" << endl;
//    cout << "1.) Enter customer ID" <<endl;
    cout << "1.) Send a request file" << endl;
    cout << "2.) view invoice" << endl;
    cout << "3.) process order" << endl;
    cout << "4.) quit" <<endl;
    int choice;
    cin >> choice;
    return choice;
}