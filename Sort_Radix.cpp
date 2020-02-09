//
//  Sort_BinBucket.cpp
//  SortingTechniques
//
//  Created by Nulyaka on 2/8/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>

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
    
    int tempArrSize = findMax(myArray) + 1;
    std::vector<NodeBin*> tempArr (tempArrSize, nullptr);
    
    for (auto &el: myArray) {
        
        if (tempArr.at(el) == nullptr) {
            
            tempArr.at(el) = new NodeBin;
            tempArr.at(el)->data = el;
            tempArr.at(el)->next = nullptr;
        }
        else {
            
            NodeBin *curr = tempArr.at(el);
            
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

int main (void) {
    
    std::vector<int> myArray {11, 11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    
    SortCount(myArray);
    
    for (const auto &el: myArray) { std::cerr << el << ' '; }
}
