//
//  cart.h
//  cis2252_final_project
//
//  Created by thomas j. elward on 8/6/14.
//  Copyright (c) 2014 tje. All rights reserved.
//

#ifndef __cis2252_final_project__cart__
#define __cis2252_final_project__cart__

#include <iostream>
#include <string>
#include <vector>

#include "food.h"
#include "account.h"


class cart {
public:
    explicit cart();
    cart(account::account);
    ~cart();
    //void setFoodQty( std::string, int);
    
    void addToCart(food::food, int quantity);
    void addToCart(food::food);
    
    void setCurrentAccount(account::account);
    
    double getCartTotal() const;
    
private:
    
    food foodItem();
    account currentAccount();
    
    std::vector<food> cartContents;
    std::string foodNames;
    int foodQty;
    double cartTotal;
    
    
};

#endif /* defined(__cis2252_final_project__cart__) */

