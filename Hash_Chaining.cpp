//
//  Hash_Chaining.cpp
//  Hashing Techniques
//
//  Created by Nulyaka on 2/9/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>

struct Node {
    
    int data;
    Node* next;
};


// Hashing, Chaining by last digit
// loading factor = n/10 (10 is hash table size)
std::vector<Node*> hash (std::vector<int> &myArray) {
    
    std::vector<Node*> hashTable(10, nullptr);
    
    for (auto &el: myArray) {
        
        int lastDigit = el % 10;
        
        Node *temp = new Node;
        temp->data = el;
        temp->next = nullptr;
        
        if (hashTable.at(lastDigit) == nullptr) {
            
            hashTable.at(lastDigit) = temp;
        }
        else {
            
            Node *curr = hashTable.at(lastDigit);
            while (curr->next != nullptr) { curr = curr->next; }
            curr->next = temp;
        }
    }
    
    return hashTable;
}

void printHashTable (std::vector<Node*> &hashTable) {
    
    for (auto &el: hashTable) {
        
        Node *curr = el;
        
        while (curr != nullptr) {
            
            std::cout << curr->data << ' ';
            curr = curr->next;
        }
    }
    std::cout << std::endl;
}

void deleteHashTable (std::vector<Node*> &hashTable) {
    
    for (auto &el: hashTable) {
        
        if (el != nullptr) {
            
            Node *curr = el->next;
            
            while (curr != nullptr) {
                
                Node *de_alloc = curr;
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
    
    std::vector<Node*> hashTable = hash(myArray);
    
    // prints: 10 11 11 12 13 3 24 5 16 7 9 (last digits ascending)
    printHashTable(hashTable);
    
    deleteHashTable(hashTable);
}
