//
//  Sort_BinBucket.cpp
//  SortingTechniques
//
//  Created by Nulyaka on 2/8/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

struct NodeBin {
    
    int data;
    NodeBin *next;
};

int findMax (std::vector<int> &myArray) {
    
    int max = INT_MIN;
    
    for (int i(0); i < myArray.size(); ++i) {
        
        if (max < myArray.at(i)) { max = myArray.at(i); }
    }
    
    return max;
}

// max-avg-min O(n)
// stable, not adaptive, extra memory needed (array of max element size)
void SortCount (std::vector<int> &myArray) {
    
    std::vector<NodeBin*> tempArr (10, nullptr);
    
    int numOfPasses(0), maxElement = findMax(myArray);
    
    while (maxElement) {
        
        numOfPasses++;
        maxElement = maxElement / 10;
    }
    
    for (int pass(1), divisor(1); pass <= numOfPasses; ++pass, divisor *= 10) {
        
        for (auto &el: myArray) {
            
            int lastDigits = (el / divisor) % 10;
            
            if (tempArr.at(lastDigits) == nullptr) {
                
                tempArr.at(lastDigits) = new NodeBin;
                tempArr.at(lastDigits)->data = el;
                tempArr.at(lastDigits)->next = nullptr;
            }
            else {
                
                NodeBin *curr = tempArr.at(lastDigits);
                
                while (curr->next != nullptr) { curr = curr->next; }
                curr->next = new NodeBin;
                curr->next->data = el;
                curr->next->next = nullptr;
            }
        }
        
        int myArrayIdx(0);
        
        for (auto &el: tempArr) {
            
            NodeBin *curr = el;
            
            while (curr != nullptr) {
                
                myArray.at(myArrayIdx++) = curr->data;
                
                NodeBin *de_alloc = curr;
                curr = curr->next;
                
                delete de_alloc;
                de_alloc = nullptr;
            }
            el = nullptr;
        }
    }
}

int main (void) {
    
    std::vector<int> myArray {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    
    SortCount(myArray);
    
    for (const auto &el: myArray) { std::cerr << el << ' '; }
}
