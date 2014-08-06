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
    void setFoodQuantity();
    void setFoodName();
    void setFoodCost();
    double getFoodCost();
    std::string getFoodName();
    unsigned int getFoodQuantity();
    
private:
    std::string foodName;
    unsigned int foodQuantity;
    double foodCost;
};