//
//  account.cpp
//  cis2252_final_project
//
//  Created by thomas j. elward on 8/10/14.
//  Copyright (c) 2014 tje. All rights reserved.
//

#include <string>
#include "account.h"


using namespace std;

account::account() : accountName(""), accountBalance(0.00), accountNumber(0)
{
    cart userCart;
    cart * const cartPtr = &userCart;

}

//account::account(account const &buffer){
//    setAccountBalance(buffer.getAccountBalance());
//    setAccountName(buffer.getAccountName());
//    setAccountNumber(buffer.getAccountNumber());
//}

account::account(int accountNumber, const string & accountName, double accountBalance) {
    
    setAccountBalance(accountBalance);
    setAccountName(accountName);
    setAccountNumber(accountNumber);
    cart userCart;
    //cart * const cartPtr = &userCart;

}


account::~account(){ }

void account::setAccountBalance(double balance) {
    accountBalance = balance;
}

double account::getAccountBalance() const {
    return accountBalance;
}

void account::setAccountNumber(int accountNum) {
    accountNumber = accountNum;
}

int account::getAccountNumber() const {
    return accountNumber;
}

void account::setAccountName(const std::string& accName){
    int len = (int)accName.size();
    len = ( len < 15 ? len : 14 );
    accName.copy( accountName, len);
    accountName[len] = '\0';
    //accountName = accName;
}

std::string account::getAccountName() const {
    return accountName;
}

void account::addToCart(food::food food){
    userCart.addToCart(food);
}
