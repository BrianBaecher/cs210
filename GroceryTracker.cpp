#include "GroceryTracker.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream> // file stream
#include <limits>
#include <cctype> // to use toupper()
#include <iomanip> // to format histogram w/ setw


GroceryTracker::GroceryTracker(){
    itemFrequencyMap = std::map<std::string, int>();
}
GroceryTracker::~GroceryTracker(){};

void GroceryTracker::parseInputFile(const std::string inputFileName){
    std::ifstream inFS;

    //try open input file
    inFS.open(inputFileName);
    //check if working
    if(!inFS.is_open()){
        std::cout << "input file is not open!" << std::endl;
        return;
    }
    //try to start parsing
    std::string line;
    while(std::getline(inFS, line)){

        if(itemFrequencyMap.find(line) != itemFrequencyMap.end()){
            //meaning the line's item exists as key in map
            itemFrequencyMap[line] += 1;
        }
        else{
            //item doesn't exist as key in map, create it
            //give key a value of 1, since it's the first entry
            itemFrequencyMap.insert(std::make_pair(line, 1));
        }
    }
    //close input file stream once while loop is complete
    inFS.close();

    //now that the file's been read, and our map has all the values,
    //I'm going to handle the output file within this function too
    std::ofstream outFS;

    outFS.open("frequency.dat");

    if(outFS.is_open()){
        for(auto& pair : itemFrequencyMap){
            outFS << pair.first << ", " << pair.second << '\n';
        }
    }
    else{
        std::cout << "output file is not open!";
    }

    outFS.close();

}

int GroceryTracker::getFrequency(const std::string itemInput){
    if(itemFrequencyMap.find(itemInput) != itemFrequencyMap.end()){
        //item exists in map
        int value = itemFrequencyMap[itemInput];
        return value;
    }
    else{
        //item doesn't exist in map, bad input/search
        std::cout << "No results found for " << itemInput << std::endl;
        //use -1 as error code
        return -1;
    }
    
}

void GroceryTracker::printPurchaseList(){
    for(const auto& currentPair : itemFrequencyMap){
        std::cout << currentPair.first << " " << currentPair.second << std::endl;
    }
}

void GroceryTracker::printHistogram(){
    int itemNameCol = 0;

    for(const auto& pair : itemFrequencyMap){
        if(pair.first.size() > itemNameCol){
            itemNameCol = pair.first.size();
        }
    }

    for(const auto& currentPair : itemFrequencyMap){
        std::cout << std::setw(itemNameCol) << std::right << currentPair.first << " ";
        std::string dashes;
        char dashChar = '-';
        for(int i = 0; i < currentPair.second; i++){
            dashes += dashChar;
        }
        std::cout << dashes << std::endl;
    }
}

void GroceryTracker::inputHandler(){

    bool is_running = true;

    while(is_running){
    //print options
    std::cout << "\n1. Search for item by name.\n"
    << "2. Print a list with all items and their frequency.\n"
    << "3. Print a histogram showing frequency of each item.\n"
    << "4. Exit program.\n";

    bool answerValid = false;

    while(!answerValid){
    int answer;
    if(std::cin >> answer){
        if(answer >= 1 && answer <= 4){
            answerValid = true;
        }
        else{
            std::cout << "invalid selection" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    else{
        std::cout << "invalid input" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    switch (answer)
    {
    case 1:{
        std::cout << "Enter item name" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string item;
        std::getline(std::cin, item);

        //all entries from file have init cap,
        //so capitalize first char of item or match will not be found

        std::string capitalizedItem = item;

        //trying this operation on an empty string will cause errors,
        //so adding a check to ensure that item is not empty.
        if(!capitalizedItem.empty()){
            capitalizedItem[0] = std::toupper(capitalizedItem[0]);
        }

        int amount = getFrequency(capitalizedItem);

        if(amount != -1){
            std::cout << capitalizedItem << " " << amount << std::endl;
        }

        break;
    }
    case 2:
        printPurchaseList();
        break;
    
    case 3:
        printHistogram();
        break;
    
    case 4:
        std::cout << "Goodbye." << std::endl;
        is_running = false;
        return;
        break;
    //default should never get fired, as a result of the checks on the int value passed to answer
    default:
        break;
    }
    }
    }
}

