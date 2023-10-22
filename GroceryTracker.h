#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map> // map object to store keys and values
#include <string> 

class GroceryTracker
{
private:
    /* data */
    std::map<std::string, int> itemFrequencyMap;

    //option 1
    int getFrequency(const std::string itemInput);

    //option 2
    void printPurchaseList();

    //option 3
    void printHistogram();

public:
    GroceryTracker(/* no args */);
    ~GroceryTracker();

    void parseInputFile(const std::string inputFileName);

    //input process
    void inputHandler();
};

#endif