//
//  Sort_Merge_Iterative.cpp
//  SortingTechniques
//
//  Created by Nulyaka on 2/8/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>

void merge (std::vector<int> &myArray, int low, int mid, int high);

// max-avg-min O(n * log(n))
// stable, not adaptive, extra memory needed (an array of n size)
void SortMerge (std::vector<int> &myArray) {
    
    int arrSize = (int)myArray.size();
    int pass(2);
    int low, mid, high;
    
    while (pass <= arrSize) {
        
        for (int i(0); i + pass - 1 < myArray.size(); i += pass) {
            
            low = i;
            high = i + pass - 1;
            mid = (low + high) / 2;
            
            merge(myArray, low, mid, high);
        }
        
        pass *= 2;
    }
    
    if (pass / 2 < arrSize) {
        merge(myArray, 0, pass/2 - 1, arrSize - 1);
    }
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
    
    for (const auto &el: myArray) { std::cout << el << ' '; }
}
