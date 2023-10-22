#include "GroceryTracker.h"
#include <iostream>
#include <memory>

int main(){
    auto myGroceryTracker = std::make_unique<GroceryTracker>();
    myGroceryTracker->parseInputFile("CS210_Project_Three_Input_File.txt");
    myGroceryTracker->inputHandler();
}