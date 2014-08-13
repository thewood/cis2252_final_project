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
#include <vector>

#include "food.h"


class cart {
public:
    cart();
    ~cart();

    cart * returnCartPointer();
    void addToCart(food::food, int quantity);
    void addToCart(food::food);
    
    double getCartTotal() const;
    
    void clearCart();
    void toString();
    
private:
    
    food foodItem();
    //account currentAccount();
    cart * cartPointer;
    std::vector<food> cartContents;
    std::vector<food> * const cartPtr = &cartContents;
    int foodQty;
    double cartTotal;

    
};

#endif /* defined(__cis2252_final_project__cart__) */

