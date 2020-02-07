//
//  Sort_Insertion.cpp
//  SortingTechniques
//
//  Created by Nulyaka on 2/7/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <vector>

// max-avg O(n^2), min O(n)
// adaptive, stable, no extra memory needed(comparisons only)
void SortInsertion (std::vector<int> &myArray) {
    
    int lastIdx = int(myArray.size()) - 1;
    int lastEl, currIdx;
    
    for (int i(1); i < myArray.size(); ++i) {
        
        currIdx = i - 1;
        lastEl = myArray.at(lastIdx);
        
        while (currIdx > - 1 && myArray.at(currIdx) > lastEl) {
            
            myArray.at(currIdx + 1) = myArray.at(currIdx);
            currIdx--;
        }
        myArray.at(currIdx + 1) = lastEl;
    }
}
