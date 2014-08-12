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
#include <time.h>
#include <vector>
#include <algorithm>


#include "cart.h"
#include "food.h"



using namespace std;

int enterChoice();
void outputLine(int , string, double);
const std::string currentDate();
void batchRequests();


//enum choices { LOGIN = 1, REQUEST = 2, INVOICE = 3, PROCESS = 4, END = 5 };
enum choices { REQUEST = 1, INVOICE = 2, PROCESS = 3, INVEN_CONTROLS = 4, END = 5 };

int main()
{
    /*
    //file processing mockup
    ifstream inOut("/Users/tj/Documents/cis2252/cis2252_final_project/cis2252_final_project/backend/CUSTOMERS.TXT",ios::in);

    
    // this didn't seem to work
    //    ifstream inOut(".\backend\\CUSTOMERS.TXT",ios::in);

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
    
    */
    int menuChoice;

    while ( ( menuChoice = enterChoice()) != END ) {
        switch (menuChoice) {
            
            case REQUEST:
                cout << "please enter the txt file to import for processing" << endl << "(exit will exit)"
                    << endl << "> ";
                batchRequests();

                break;
            case INVOICE:
                cout <<"processing transactions and updating inventory please wait..."<< endl;

                break;
            case PROCESS:
                cout << "doing work please wait while reciept is printed to screen"<< endl;

                break;
            case INVEN_CONTROLS:
                cout << "loading inventory controls" << endl;
                break;
            default:
                cerr << "Incorrect choice!"<< endl << "> ";
                break;
        }
        
    }
    
}


void outputLine(int account, string name, double balance) {
    cout << left << setw(10) << account << setw(13) << name << setw(7) << setprecision(2) << right << balance <<endl;
}

int enterChoice() {
    cout << "Welcome to the store! " << endl << "today is: " << currentDate()<< endl;
    cout << "1.) Send a request file" << endl;
    cout << "2.) view invoice" << endl;
    cout << "3.) process order" << endl;
    cout << "4.) inventory controls" << endl;
    
    cout << "5.) quit" <<endl << "> ";
    int choice;
    cin >> choice;
    return choice;
}

const std::string currentDate() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now); //pointing
    //extract just the date from the system time
    strftime(buf, sizeof(buf), "%x", &tstruct);
    return buf;
}

void batchRequests() {
    string requestPath;
    cin >> requestPath;
    if (requestPath == "exit") {
        exit(3);
    }
    ifstream f;
    f.open( requestPath.c_str() );
    while (f.fail()) {
        if (requestPath == "exit") {
            exit(3);
        }
        f.clear();
        cerr << "File not found"<< endl << "please enter the absolute file path"<<endl<<"> ";
        cin >> requestPath;
        f.open(requestPath.c_str());
    }
    cart myCart;
    vector<string> commands;
    string line;
    
    
    //adds each line to a vector for processing
    while (std::getline(f, line)) {
        commands.push_back(line);
    }
    
    for (int i=0; i<commands.size(); i++) {

        //debugging purposes
		cout << commands[i] << '\n';
        
        //work space variables
        string newCommand;
        string foodToAdd;
        int qtyToAdd;
        
        //finding locations split by different delimiters
        size_t commandLocation = commands[i].find_first_of(":");
        size_t foodLocation = commands[i].find_first_of(",");
        
        
        //parsing the commands
        newCommand = commands[i].substr(0,commandLocation);
        foodToAdd = commands[i].substr(commandLocation +1, foodLocation - commandLocation -1);
        qtyToAdd = stoi(commands[i].substr(foodLocation+1));

        cout <<newCommand<< endl << foodToAdd << endl << qtyToAdd <<endl;
	}
    
    
    
    
    
    f.close();
    
}
