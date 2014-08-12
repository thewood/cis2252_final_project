//
//  food.cpp
//  cis2252_final_project
//
//  Created by thomas j. elward on 8/6/14.
//  Copyright (c) 2014 tje. All rights reserved.
//

#include <string>
#include "food.h"

using namespace std;

food::food() : foodName(""), foodQuantity(0), foodCost(0.00)
{
    
}

food::food(const string& foodName) : foodQuantity(0), foodCost(0.00)
{
    setFoodName(foodName);
}

food::food ( const string& foodName, int quantity, double foodPrice)
{
    setFoodName(foodName);
    setFoodCost(foodPrice);
    setFoodQuantity(quantity);
}

food::~food(){
    
}


void food::setFoodName(string name){
    foodName = name;
}

string food::getFoodName() const {
    return foodName;
}

void food::setFoodQuantity(int quantity) {
    foodQuantity = quantity;
}

int food::getFoodQuantity() const {
    return foodQuantity;
}

void food::setFoodCost(double cost) {
    foodCost = cost;
}

double food::getFoodCost() const {
    return foodCost;
}

double food::getTotalFoodCost() const {
    return (foodCost * foodQuantity);
}