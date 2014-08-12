//
//  food.cpp
//  cis2252_final_project
//
//  Created by thomas j. elward on 8/6/14.
//  Copyright (c) 2014 tje. All rights reserved.
//

#include <fstream>
#include <iomanip>
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

food::food( const string& foodName, int quantity) : foodCost(0.00)
{
    setFoodName(foodName);
    setFoodQuantity(quantity);
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

void food::toString() {

    std::cout << "food name: " << this->getFoodName() << std::endl
    << "quantity: " << this->getFoodQuantity() << std::endl
    << "cost per: " << this->getFoodCost() << std::endl;
}

double food::getFoodCost() const {
    if (foodCost <= 0.00){
//        ifstream inOut("/Users/tj/Documents/cis2252/cis2252_final_project/cis2252_final_project/backend/INVENTORY.TXT",ios::in | ios::out);
//        if (!inOut) {
//            cerr << "INVENTORY FILE MISSING SHOULD BE LOCATED IN ./backend/ SUBDIRECTORY FROM WHICH PROGRAM WAS EXECUTED"<< endl;
//            exit (EXIT_FAILURE);
//        }
//        string buffer;
//        int array_size = 0;
//        while (std::getline(inOut, buffer)) {
//            ++array_size;
//        }
//        
//        inOut.close();
    }
    return foodCost;
}

double food::getTotalFoodCost() const {
    return (foodCost * foodQuantity);
}