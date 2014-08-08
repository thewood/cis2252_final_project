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

#endif /* defined(__cis2252_final_project__food__) */

class food {
public:
    
    food(std::string name, int = 0, double = 0.0);
    
    void setFoodQuantity(int quantity);
    void setFoodName(std::string name);
    void setFoodCost(double cost);
    double getFoodCost() const;
    std::string getFoodName() const;
    int getFoodQuantity() const;
    
private:
    std::string foodName;
    int foodQuantity;
    double foodCost;
};