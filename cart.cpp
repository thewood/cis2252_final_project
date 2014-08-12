//
//  cart.cpp
//  cis2252_final_project
//
//  Created by thomas j. elward on 8/6/14.
//  Copyright (c) 2014 tje. All rights reserved.
//


#include <iostream>
#include <string>
#include "food.h"
#include "cart.h"

using namespace std;

cart::cart(){
    
}

cart::cart(account::account currentUser){
    setCurrentAccount(currentUser);
}

cart::~cart(){
    
}

void cart::addToCart(food::food food, int qty) {
    food.setFoodQuantity(qty);
    cartTotal = cartTotal + (food.getFoodCost() * food.getFoodQuantity());
    cartContents.push_back(food);
}

void cart::addToCart(food::food food) {
    cartTotal = cartTotal + (food.getFoodCost() * food.getFoodQuantity());
    cartContents.push_back(food);
}

void cart::setCurrentAccount(account::account userAccount) {
    currentAccount() = userAccount;
}

double cart::getCartTotal() const {
    double cartTotal = 0.00;
    for (int i=0; i < cartContents.size(); i++){
        cartTotal = cartTotal + (cartContents[i].getFoodQuantity() * cartContents[i].getFoodCost());
    }
    return cartTotal;
}