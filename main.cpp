//
//  main.cpp
//  cis2252_final_project
//
//  Created by thomas j. elward on 8/6/14.
//  Copyright (c) 2014 tje. All rights reserved.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int menu();

int main()
{
    unsigned int menuChoice;
    menuChoice = menu();
    
    
}

int menu() {
    unsigned int choice;
    cout << "Welcome to the store" << endl;
    cout << "1.) Enter customer ID" <<endl;
    cout << "2.) Send a request file" << endl;
    cout << "3.) view invoice" << endl;
    cout << "4.) process order" << endl;
    cout << "5.) quit" <<endl;
    cin >> choice;
    return choice;
}