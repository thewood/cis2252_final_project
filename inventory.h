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

#endif /* defined(__cis2252_final_project__inventory__) */

class inventory {
public:
    explicit inventory();
    void addFoodQty( std::string, int);
    

private:
    
    std::string foodNames;
    int foodQty;

};