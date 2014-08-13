//
//  account.h
//  cis2252_final_project
//
//  Created by thomas j. elward on 8/10/14.
//  Copyright (c) 2014 tje. All rights reserved.
//

#ifndef __cis2252_final_project__account__
#define __cis2252_final_project__account__

#include <iostream>
#include <string>
#include "cart.h"

class account : public cart

{
    
public:
    account();
    account(int accountNumber, const std::string& accountName, double accountBalance);
    //account(account const &);
    ~account();
    void setAccountNumber(int accountNumber);
    int getAccountNumber() const;
    
    void setAccountBalance(double accountBalance);
    double getAccountBalance() const;
    
    void setAccountName(const std::string& accountName);
    std::string getAccountName() const;
    
    void addToCart(food);
    void removeFromCart(food);
    double getTotal() const;
    void toString();
    
private:
    double accountBalance;
    int accountNumber;
//  std::string accountName;
    char accountName[15];
    cart userCart;
    cart * const cartPtr = &userCart;
};

#endif /* defined(__cis2252_final_project__account__) */

