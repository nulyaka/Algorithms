//
//  sort-shell.cpp
//  sort
//
//  Created by Nulyaka on 2/8/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>

// max-avg-min O(n * log(n))
// stable, not adaptive, no extra memory needed (comparisons only)
void SortShell (std::vector<int> &myArray) {
    
    int arrSize = (int)myArray.size();
    int gap = arrSize / 2;
    
    while (gap >= 1) {
        
        for (int Idx(gap); Idx < arrSize; ++Idx) {
            
            int temp = myArray.at(Idx);
            int prevIdx = Idx - gap;
            
            while (prevIdx >= 0 && myArray.at(prevIdx) > temp) {
                
                myArray.at(prevIdx + gap) = myArray.at(prevIdx);
                prevIdx = prevIdx - gap;
            }
            myArray.at(prevIdx + gap) = temp;
        }
        
        gap /= 2;
    }
}

int main (void) {
    
    std::vector<int> myArray {11, 11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    
    SortShell(myArray);
    
    for (const auto &el: myArray) { std::cerr << el << ' '; }
}
