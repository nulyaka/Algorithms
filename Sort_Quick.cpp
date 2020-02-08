//
//  Sort_Quick.cpp
//  SortingTechniques
//
//  Created by Nulyaka on 2/7/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

// Partition Exchange Sort
// Selection Exchange Sort

#include <iostream>
#include <vector>
#include <random>

// for random pivot selection
int getRandomInRange(int from, int to)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(from, to); // define the range
    
    return distr(eng);
}

int partition(std::vector<int> &myArray, int low_arg, int high_arg) {
    
    int pivotIdx = getRandomInRange(low_arg, high_arg);
    std::swap(myArray.at(low_arg), myArray.at(pivotIdx));
    
    int pivot = myArray.at(low_arg);
    int low = low_arg, high = high_arg;
    
    int arrSize = (int)myArray.size();
    
    do {
        
        do { low++; }
        while (myArray.at(low) <= pivot && low < arrSize - 1);
        
        while (myArray.at(high) > pivot) { high--; }
        
        if(low < high){ std::swap(myArray.at(low), myArray.at(high)); }
        
    } while(low < high);
    
    std::swap(myArray.at(low_arg), myArray.at(high));
    
    return high;
}

// max O(n^2)
// avg-min O(n * log(n))
void SortQuick(std::vector<int> &myArray, int low_arg = 0, int high_arg = INT_MIN) {
    
    if (low_arg == 0 && high_arg == INT_MIN) {
        high_arg = (int)myArray.size() - 1;
    }
    else if (low_arg >= high_arg) { return; }
    
    int middle;
    
    if(low_arg < high_arg) {
        
        middle = partition(myArray, low_arg, high_arg);
        SortQuick(myArray, low_arg, middle - 1);
        SortQuick(myArray, middle + 1, high_arg);
    }
}

int main (void) {
    
    std::vector<int> myArray {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    
    SortQuick(myArray);
    
    for (const auto &el: myArray) { std::cout << el << ' '; }
}
