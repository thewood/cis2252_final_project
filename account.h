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

class account {
    
public:
    explicit account();
    account(int accountNumber, const std::string& accountName, double accountBalance);
    ~account();
    void setAccountNumber(int accountNumber);
    int getAccountNumber();
    
    void setAccountBalance(double accountBalance);
    double getAccountBalance();
    
    void setAccountName(std::string accountName);
    std::string getAccountName();
    
    
private:
    double accountBalance;
    int accountNumber;
    std::string accountName;
    
};

#endif /* defined(__cis2252_final_project__account__) */

