//
//  inventory.cpp
//  cis2252_final_project
//
//  Created by thomas j. elward on 8/6/14.
//  Copyright (c) 2014 tje. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

#include "inventory.h"
#include "food.h"

inventory::inventory(){
    //upon construction load the inventory file
    
    std::ifstream inOut("/Users/tj/Documents/cis2252/cis2252_final_project/cis2252_final_project/backend/MAININVENTORY.TXT",
                        std::ios::in);
    if (!inOut) {
        std::cerr << "INVENTORY FILE MISSING SHOULD BE LOCATED IN ./backend/ SUBDIRECTORY FROM WHICH PROGRAM WAS EXECUTED"
        << std::endl;
        exit (EXIT_FAILURE);
    }
    
    std::string buffer;
    while (std::getline(inOut, buffer)) {
        
        //finding locations split by different delimiters
        size_t foodLocation = buffer.find_first_of(",");
        size_t quantityLocation = buffer.find_last_of(",");
        
        food currentFood( buffer.substr(0,foodLocation),
                         stoi(buffer.substr(foodLocation +1, quantityLocation - foodLocation -1)),
                         stod(buffer.substr(quantityLocation+1)));
       // currentFood.toString();
        currentInventory.push_back(currentFood);
        

    }
    currentInventory.shrink_to_fit();
    
    inOut.close();
    inventorySize = currentInventory.size();
}

inventory::~inventory(){
//    
//    std::fstream output_file("/Users/tj/Documents/cis2252/cis2252_final_project/cis2252_final_project/backend/INVENTORY.dat", std::ios::out | std::ios::binary);
////    //std::ostream_iterator<food> output_iterator(output_file, "\n");
////    //std::copy(currentInventory.begin(), currentInventory.end(), output_iterator);
////    for(std::vector<food>::const_iterator i = currentInventory.begin(); i != currentInventory.end(); ++i) {
////        output_file.write( reinterpret_cast< const char *> ( &i), sizeof(currentInventory));
////    }
    
    //code to save the inventory here
}

int inventory::getInventorySize() const {
    return inventorySize;
}

void inventory::toString() {
    std::cout << "contents in inventory" << std::endl;
    for ( int i = 0; i < currentInventory.size(); ++i){

        std::cout << "food name: " << currentInventory[i].getFoodName()
            << std::endl
            << "quantity: " << currentInventory[i].getFoodQuantity() << std::endl
            << "cost per: " << currentInventory[i].getFoodCost() << std::endl;
        
    }
}
double inventory::getFoodPrice(std::string foodName) const{

    for ( int i = 0; i < currentInventory.size(); ++i){
        std::cout << currentInventory[i].getFoodName() << foodName << std::endl;
        if (currentInventory[i].getFoodName() == foodName){
            
            return currentInventory[i].getFoodCost();
        }
    }
    // iterator to vector element:
    return 0.00;
}

std::string inventory::getFoodName() const{
    return foodNames;
}

double inventory::searchForPrice(std::string foodName) {
    double stupid = 0.00;

        for (int j = 0; j < currentInventory.size(); j++) {
            std::cout <<std::endl<<"comparing:::" << currentInventory[j].getFoodName()<< std::endl<< " with "<< foodName;
            if (currentInventory[j].getFoodName() == foodName) {
                std::cout<<" we have a match: " <<currentInventory[j].getFoodCost()<<std::endl;
                stupid = currentInventory[j].getFoodCost();
            }
        }
    
    return stupid;
}