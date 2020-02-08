//
//  Sort_Count.cpp
//  SortingTechniques
//
//  Created by Nulyaka on 2/8/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>

int findMax (std::vector<int> &myArray) {
    
    int max = INT_MIN;
    
    for (int i(0); i < myArray.size(); ++i) {
        
        if (max < myArray.at(i)) { max = myArray.at(i); }
    }
    
    return max;
}

// max-avg-min O(n)
// not stable, not adaptive, extra memory needed (array of max element size)
void SortCount (std::vector<int> &myArray) {
    
    int tempArrSize = findMax(myArray) + 1;
    std::vector<int> tempArr (tempArrSize, 0);
    
    for (const auto &el: myArray) { tempArr.at(el)++; }
    
    int myArrayIdx(0), tempArrIdx(0);
    for (auto &el: tempArr) {
        
        while (el--) { myArray.at(myArrayIdx++) = tempArrIdx; }
        tempArrIdx++;
    }
}

int main (void) {
    
    std::vector<int> myArray {11, 13, 7, 12, 16, 16, 9, 24, 5, 10, 3};
    
    SortCount(myArray);
    
    // for (const auto &el: myArray) { std::cerr << el << ' '; }
}
