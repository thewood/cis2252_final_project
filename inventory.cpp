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
                        std::ios::in | std::ios::binary);
    if (!inOut) {
        std::cerr << "INVENTORY FILE MISSING SHOULD BE LOCATED IN ./backend/ SUBDIRECTORY FROM WHICH PROGRAM WAS EXECUTED"
        << std::endl;
        exit (EXIT_FAILURE);
    }
    //binary part can't get to work or spews random info
//    cost per: 1.72321e-259
//    food name: bread,100,5.00
//    bagel,100\330F
//quantity: 1644834864
//    cost per: 1.39838e-76
//    food name: ,.50
//    onion,100,.50
//    cucum\330F
//quantity: 774647856
//    cost per: 1.88755e+219
//    food name: ber,100,.65
//    pickle,100,.\330F
//quantity: 1801677168
//    cost per: 2.834e-86
//    food buff;
//    inOut.read(reinterpret_cast < char * > (&buff), sizeof(food));
//
//    while (inOut && !inOut.eof()){
//        if (buff.getFoodQuantity() != 0) {
//            
//        }
//        buff.toString();
//        inOut.read(reinterpret_cast < char * > (&buff), sizeof(food));
//    }
//    
    std::string buffer;
    while (std::getline(inOut, buffer)) {
        
        //finding locations split by different delimiters
        size_t foodLocation = buffer.find_first_of(",");
        size_t quantityLocation = buffer.find_last_of(",");
        
        food currentFood( buffer.substr(0,foodLocation),
                         stoi(buffer.substr(foodLocation +1, quantityLocation - foodLocation -1)),
                         stod(buffer.substr(quantityLocation+1)));
        
        currentInventory.push_back(currentFood);
        //std::cout << currentFood.getFoodName();

    }
    currentInventory.shrink_to_fit();
    
    
    
    inOut.close();
    inventorySize = (int)currentInventory.size();
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
    saveInventory();
}

int inventory::getInventorySize() const {
    return inventorySize;
}

void inventory::addItem(){
    std::string name;
    int quantity;
    double cost;
    std::cout <<"please enter the name for the new item" << std::endl << "> ";
    std::cin >> name;
    std::cout <<"please enter the quantity" << std::endl << "> ";
    std::cin >> quantity;
    std::cout <<"please enter the cost of the new item" << std::endl << "> ";
    std::cin >> cost;
    food newItem(name,quantity,cost);
    currentInventory.push_back(newItem);
    
}

void inventory::report() {
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\ncontents in inventory" << std::endl;
    std::cout << std::left << std::setw(10)
    << "Item:" << std::setw(16)
    << "Quantity:" << std::setw(11) << std::setprecision(3)
    << "Price:" <<std::endl;

    for ( int i = 0; i < currentInventory.size(); ++i){
        std::cout << std::left << std::setw(10) << currentInventory[i].getFoodName()
            << std::setw(16) << currentInventory[i].getFoodQuantity()
            << std::setw(11) << std::setprecision(2) << std::fixed << std::showpoint
            << currentInventory[i].getFoodCost() << std::endl;
    }
    
}

void inventory::indvReport() {
    bool success = 1;
    std::cout << "please enter an item you wish to search for " << std::endl << "> ";
    std::string input ("");
    std::cin >> input;
    for (int i = 0; i < currentInventory.size(); ++i) {
        if (currentInventory[i].getFoodName().compare(input) == 0) {
            success = 1;
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::left << std::setw(10)
            << "Item:" << std::setw(16)
            << "Quantity:" << std::setw(11) << std::setprecision(2) << std::right
            << "Price:" <<std::endl;
            std::cout << std::left << std::setw(10) << currentInventory[i].getFoodName()
            << std::setw(16) << currentInventory[i].getFoodQuantity()
            << std::setw(11) << std::setprecision(2) << std::right << std::fixed << std::showpoint
            << currentInventory[i].getFoodCost() << "\n\n\n\n\n\n\n\n" << std::endl;
        }
    }

}

void inventory::toString() {
    //std::cout << "contents in inventory" << std::endl;
    for ( int i = 0; i < currentInventory.size(); ++i){

        std::cout << "food name: " << currentInventory[i].getFoodName()
            << std::endl
            << "quantity: " << currentInventory[i].getFoodQuantity() << std::endl
            << "cost per: " << currentInventory[i].getFoodCost() << std::endl;
        
    }
}

std::string inventory::getFoodName() const{
    return foodName;
}

double inventory::searchForPrice(const std::string &foodName) {
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

void inventory::saveInventory() {
    
    
    //this was the binary write code....
    //possibly worked was probably wrong though i kept reading that data files are not very portable
    //since im not in windows....i wasn't sure it would be the best
    
//    std::fstream outInventory
//        ("/Users/tj/Documents/cis2252/cis2252_final_project/cis2252_final_project/backend/maininventory.dat", std::ios::in | std::ios::out | std::ios::binary);
//    if (!outInventory) {
//        std::cerr << "file error" << std::endl;
//        exit (EXIT_FAILURE);
//    }
//    
//    for (int j = 0; j < currentInventory.size(); j++) {
// //       std::string buffer (currentInventory[j].getFoodName());
////        std::cout << sizeof(currentInventory[j])<< std::endl;
//        food buff = *new food(currentInventory[j].getFoodName(),currentInventory[j].getFoodQuantity(),currentInventory[j].getFoodCost());
//        outInventory.write( reinterpret_cast < const char * > (&buff), sizeof(buff));
//  //      delete &buff;
//    }
//    outInventory.close();
    
    
    
    std::ofstream outPutFile("/Users/tj/Documents/cis2252/cis2252_final_project/cis2252_final_project/backend/MAININVENTORY.TXT",
                        std::ios::in | std::ios::binary);
    if (!outPutFile) {
        std::cerr << "INVENTORY FILE MISSING SHOULD BE LOCATED IN ./backend/ SUBDIRECTORY FROM WHICH PROGRAM WAS EXECUTED"
        << std::endl;
        exit (EXIT_FAILURE);
    }
    for (int j= 0; j < currentInventory.size(); ++j) {
        outPutFile << currentInventory[j].getFoodName() <<',' << currentInventory[j].getFoodQuantity() << ',' << currentInventory[j].getFoodCost() << std::endl;
    }
    
}