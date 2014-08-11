//
//  inventory.h
//  cis2252_final_project
//
//  Created by thomas j. elward on 8/6/14.
//  Copyright (c) 2014 tje. All rights reserved.
//

#ifndef __cis2252_final_project__inventory__
#define __cis2252_final_project__inventory__

#include <iostream>
#include <string>
#include "food.h"

class inventory {
public:
    explicit inventory();
    inventory(food);
    ~inventory();
    
    void setFoodQty( std::string, int);
    void setFoodPrice ( double price);
    void setFoodName ( std::string);
    
    std::string getFoodName() const;
    int getFoodQuantity() const;
    double getFoodPrice() const;
    
    
private:
    
    std::string foodNames;
    int foodQty;
    double foodPrice;
};

#endif /* defined(__cis2252_final_project__inventory__) */

