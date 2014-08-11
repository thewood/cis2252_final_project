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
#include "food.h"

class cart {
public:
    explicit cart();
    ~cart();
    void setFoodQty( std::string, int);
    double getCartTotal();
    
private:
    
    std::string foodNames;
    int foodQty;
    double cartTotal;
    
    
};

#endif /* defined(__cis2252_final_project__cart__) */

