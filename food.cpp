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

food::food ( string foodName, int quantity, double foodPrice)
{
    setFoodName(foodName);
    
}

void food::setFoodName(string name){
    foodName = name;
}

string food::getFoodName() {
    return foodName;
}

void food::setFoodQuantity(int quantity) {
    foodQuantity = quantity;
}

int food::getFoodQuantity() {
    return foodQuantity;
}

void food::setFoodCost(double cost) {
    foodCost = cost;
}

double food::getFoodCost() {
    return foodCost;
}