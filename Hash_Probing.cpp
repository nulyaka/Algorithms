//
//  Hash_Probing.cpp
//  Hashing Techniques
//
//  Created by Nulyaka on 2/10/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>

// d - data, s - size of hash, i - index

// Linear Probing formula:
// h(d) = (f(d) + i) % s

// where f(d) = d % s
// and i >= 0 and i < s

// e.g  d = 25, s = 20, i = 0
// h(25) = ((25 % 20) + 0) % 20 = 5 (this is the index, where we store our data)
// if cell of hash on that index is already occupied by some data,
// we again use the formula, but changing i = i + 1 (1, 2, 3, 4, ..., s - 1)

int probeLinear (std::vector<int> &hashTable, int data) {
    
    int hashSize = static_cast<int>(hashTable.size());
    int lastDigit = data % hashSize;
    int index (0);
    
    while (hashTable.at((lastDigit + index) % hashSize) != INT_MIN) { index++; }
    
    return (lastDigit + index) % hashSize;
}

// Quadratic Probing formula is the same:
// h(d) = (f(d) + i) % s
// but changing i = i^2 (0, 1, 4, 9, 16, ...)

int probeQuadratic (std::vector<int> &hashTable, int data) {
    
    int hashSize = static_cast<int>(hashTable.size());
    int lastDigit = data % hashSize;
    int index (0);
    
    while (hashTable.at((lastDigit + index) % hashSize) != INT_MIN) { index *= index; }
    
    return (lastDigit + index) % hashSize;
}

bool searchDataLinear (std::vector<int> &hashTable, int data) {
    
    int hashSize = static_cast<int>(hashTable.size());
    int searchIndex = data % hashSize;
    
    while (hashTable.at(searchIndex) != INT_MIN) {
        
        if (hashTable.at(searchIndex) == data) { return true; }
        else { 
            // in order to search quadratic, call function
            // probeQuadratic instead of probeLinear
            searchIndex = probeLinear(hashTable, data); 
        }
    }
    
    return false;
}

void insertData (std::vector<int> &hashTable, int data) {
    
    int hashSize = static_cast<int>(hashTable.size());;
    int storeToIndex = data % hashSize;
    
    if (hashTable.at(storeToIndex) != INT_MIN) {
        
        storeToIndex = probeLinear(hashTable, data);
    }
    
    hashTable.at(storeToIndex) = data;
}

std::vector<int> insertArray (std::vector<int> &myArray) {
    
    int hashSize = static_cast<int>(myArray.size()) * 2;
    std::vector<int> hashTable (hashSize, INT_MIN);
    
    for (auto &data: myArray) { insertData(hashTable, data); }
    
    return hashTable;
}
