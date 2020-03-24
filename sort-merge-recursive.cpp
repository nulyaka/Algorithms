//
//  sort-merge-recursive.cpp
//  sort
//
//  Created by Nulyaka on 2/8/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>

void merge (std::vector<int> &myArray, int low, int mid, int high);

// max-avg-min O(n * log(n))
// stable, not adaptive, extra memory needed (an array of n size, stack of log(n) size)
void SortMerge (std::vector<int> &myArray, int low_arg = 0, int high_arg = INT_MIN) {
    
    if (low_arg == 0 && high_arg == INT_MIN) {
        high_arg = (int)myArray.size() - 1;
    }
    else if (low_arg >= high_arg) { return; }
    
    int middle;
    
    middle = (low_arg + high_arg) / 2;
    SortMerge(myArray, low_arg, middle);
    SortMerge(myArray, middle + 1, high_arg);
    merge(myArray, low_arg, middle, high_arg);
}

void merge (std::vector<int> &myArray, int low, int mid, int high) {
    
    int firstIt = low, secondIt = mid + 1;
    
    std::vector<int> temp;
    
    while (firstIt <= mid && secondIt <= high) {
        
        if (myArray.at(firstIt) <= myArray.at(secondIt)) {
            
            temp.push_back(myArray.at(firstIt));
            firstIt++;
        }
        else {
            
            temp.push_back(myArray.at(secondIt));
            secondIt++;
        }
    }
    
    while (firstIt <= mid) {
        temp.push_back(myArray.at(firstIt));
        firstIt++;
    }
    while (secondIt <= high) {
        temp.push_back(myArray.at(secondIt));
        secondIt++;
    }
    
    for (int i(low), j(0); i <= high; ++i, ++j) {
        myArray.at(i) = temp.at(j);
    }
}


int main (void) {
    
    std::vector<int> myArray {5, 2, 4, 9, 8, 6, 1, 3, 7};
    
    SortMerge(myArray);
    
    for (const auto &el: myArray) { std::cerr << el << ' '; }
}
