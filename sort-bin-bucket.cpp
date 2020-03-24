//
//  sort-bin-bucket.cpp
//  sort
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
void SortBinBucket (std::vector<int> &myArray) {
    
    int tempArrSize = findMax(myArray) + 1;
    std::vector<NodeBin*> tempArr (tempArrSize, nullptr);
    
    for (auto &el: myArray) {
        
        NodeBin *temp = new NodeBin;
        temp->data = el;
        temp->next = nullptr;
        
        if (tempArr.at(el) == nullptr) {
            
            tempArr.at(el) = temp;
        }
        else {
            
            NodeBin *curr = tempArr.at(el);
            
            while (curr->next != nullptr) { curr = curr->next; }
            curr->next = temp;
        }
    }
    
    int myArrayIdx(0);
    
    for (auto &el: tempArr) {
        
        if (el != nullptr) {
            
            myArray.at(myArrayIdx++) = el->data;
            
            NodeBin *curr = el->next;
            
            while (curr != nullptr) {
                
                myArray.at(myArrayIdx++) = curr->data;
                
                NodeBin *de_alloc = curr;
                curr = curr->next;
                
                delete de_alloc;
                de_alloc = nullptr;
            }
            
            delete el;
            el = nullptr;
        }
    }
}

int main (void) {
    
    std::vector<int> myArray {11, 11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    
    SortBinBucket (myArray);
    
    for (const auto &el: myArray) { std::cerr << el << ' '; }
}
