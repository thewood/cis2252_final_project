//
//  food.h
//  cis2252_final_project
//
//  Created by thomas j. elward on 8/6/14.
//  Copyright (c) 2014 tje. All rights reserved.
//

#ifndef __cis2252_final_project__food__
#define __cis2252_final_project__food__

#include <iostream>
#include <string>

class food {

public:
    food();
    food (const std::string & );// int = 0, double = 0.0
    food (const std::string & , int);
    food( const std::string &, int, double);
    ~food();
    void setFoodQuantity(int quantity);
    void setFoodName(const std::string &);
    void setFoodCost(double cost);
    double getFoodCost() const;
    double getTotalFoodCost() const;
    std::string getFoodName() const;
    int getFoodQuantity() const;
    void toString();
    
private:
    //std::string foodName;
    char foodName[10];
    int foodQuantity;
    double foodCost;
};

#endif /* defined(__cis2252_final_project__food__) */

