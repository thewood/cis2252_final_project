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
#include "inventory.h"
#include "account.h"


using namespace std;

int enterChoice();
void outputLine(int , string, double);
const std::string currentDate();
void batchRequests();
vector<account> loadAccounts();

enum choices { REQUEST = 1, INVOICE = 2, PROCESS = 3, INVEN_CONTROLS = 4, END = 5 };
enum comms { ADD = 1, REMOVE, CARTREPORT, CHECKOUT, CREDIT };

int main()
{
    //inventory storesUp;
    //storesUp.toString();
    
    
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
    inventory storesUp;
    
    string requestPath;
    cin >> requestPath;
    if (requestPath == "exit") {
        exit(3);
    }
    ifstream inOut;
    inOut.open( requestPath.c_str() );
    while (inOut.fail()) {
        if (requestPath == "exit") {
            exit(3);
        }
        inOut.clear();
        cerr << "File not found"<< endl << "please enter the absolute file path"<<endl<<"> ";
        cin >> requestPath;
        inOut.open(requestPath.c_str());
    }
    vector<account> accounts = loadAccounts();
    //cart myCart;
    vector<string> commands;
    string line;
    
    
    //adds each line to a vector for processing
    while (std::getline(inOut, line)) {
        commands.push_back(line);
    }
    
    for (int i=0; i<commands.size(); i++) {
        
        //work space variables
        string newCommand;
        int accountNumber;
        string foodToAdd;
        int qtyToAdd;
        
        //finding locations split by different delimiters
        size_t commandLocation = commands[i].find_first_of(":");
        size_t accountLocation = commands[i].find_first_of(",");
        size_t foodLocation = commands[i].find_last_of(",");
        
        
        //parsing the commands
        newCommand = commands[i].substr(0,commandLocation);
        accountNumber = stoi(commands[i].substr(commandLocation +1, accountLocation - commandLocation -1));
        foodToAdd = commands[i].substr(accountLocation +1, foodLocation - accountLocation -1);
        qtyToAdd = stoi(commands[i].substr(foodLocation+1));
        
        
        
//        switch (newCommand) {
//         
//            default:
//                cerr << "Incorrect choice!"<< endl << "> ";
//                break;
//        }
        
        
        food workingFood(foodToAdd,qtyToAdd);
        for ( int i = 0; i < accounts.size(); ++i){
            
            if (accountNumber == accounts[i].getAccountNumber()) {
                double test = storesUp.searchForPrice(workingFood.getFoodName());
                workingFood.setFoodCost(storesUp.searchForPrice(workingFood.getFoodName()));
                accounts[i].addToCart(workingFood);
                cout << endl << endl << test <<endl;
            }
        }
    }
    
    
    
    inOut.close();
    
}

vector<account> loadAccounts() {
    
    vector<account> acc;
    std::ifstream inOut("/Users/tj/Documents/cis2252/cis2252_final_project/cis2252_final_project/backend/CUSTOMERS.TXT",
                        std::ios::in);
    if (!inOut) {
        std::cerr << "CUSTOMER FILE MISSING SHOULD BE LOCATED IN ./backend/ SUBDIRECTORY FROM WHICH PROGRAM WAS EXECUTED"
        << std::endl;
        exit (EXIT_FAILURE);
    }
    std::string buffer;
    while (std::getline(inOut, buffer)) {
        
        
        //finding locations split by different delimiters
        size_t accountNumberLocation = buffer.find_first_of(":");
        size_t creditLocation = buffer.find_last_of(",");
        
        account currentAccount( stoi(buffer.substr(0,accountNumberLocation)),
                         (buffer.substr(accountNumberLocation +1, creditLocation - accountNumberLocation -1)),
                         stod(buffer.substr(creditLocation+1)));
        
        acc.push_back(currentAccount);
    }
    inOut.close();
    return acc;
}

