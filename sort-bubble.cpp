//
//  sort-bubble.cpp
//  sort
//
//  Created by Nulyaka on 2/7/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//
#include <vector>

// max-avg O(n^2), min O(n)
// adaptive, stable, no extra memory needed (comparisons only)
void sortBubble (std::vector<int> &myArray) {
    
    bool sorted = true;
    int arrSize = int(myArray.size());
    
    for (int i(0); i < arrSize - 1; ++i) {
        
        for (int j(0); j < arrSize - i - 1; ++j) {
            
            if (myArray.at(j) > myArray.at(j + 1)) {
                
                std::swap(myArray.at(j), myArray.at(j + 1));
                sorted = false;
            }
        }
        if (sorted) { break; }
    }
}
