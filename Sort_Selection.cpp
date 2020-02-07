//
//  Sort_Selection.cpp
//  SortingTechniques
//
//  Created by Nulyaka on 2/7/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <vector>

// max-avg-min O(n^2)
// not adaptive, not stable, no extra memory needed(comparisons only)
// minimal amount of swaps
void SortSelection (std::vector<int> &myArray) {
    
    int minIdx;
    
    for (int it(0); it < myArray.size(); ++it) {
        
        minIdx = it;
        
        for (int currIdx(it); currIdx < myArray.size(); ++currIdx) {
            
            if (myArray.at(currIdx) < myArray.at(minIdx)) {
                
                minIdx = currIdx;
            }
        }
        std::swap(myArray.at(it), myArray.at(minIdx));
    }
}
