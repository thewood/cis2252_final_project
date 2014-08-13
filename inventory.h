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
#include <vector>
#include "food.h"

class inventory {
public:
    inventory();
    ~inventory();
    
    void setFoodQty( const std::string &, int);
    void setFoodPrice ( double price);
    void setFoodName ( const std::string &);
    void toString();
    void addItem();
    void saveInventory();
    
    std::string getFoodName() const;
    
    int getFoodQuantity() const;
    int getInventorySize() const;
    
    void report();
    void indvReport();
    
    double searchForPrice(const std::string &);
    
private:
    
    std::vector <food> currentInventory;
    char foodName[10];
    
    food foodItem;
    int foodQty;
    int inventorySize;
    double foodPrice;
};

#endif /* defined(__cis2252_final_project__inventory__) */

