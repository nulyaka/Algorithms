  
//
//  Greedy_HuffmanCoding.cpp
//  Greedy
//
//  Created by Nulyaka on 3/3/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

// Example:

// "BCCABBDDAECCBBAEDDCC" is message we need to send
// each char is 8 bits
// 8 x 20 = 160 bits to send

// Huffman MinHeap:

// char        A   B   C   D   E
// frequency  [3] [5] [6] [4] [2]

//   [20]
//  0/  \1
// [9] [11]

//   [11]
//  0/  \1
// [5] [6] [9]

//    [9]
//  0/  \1
// [5] [4] [5] [6]

//    [5]
//  0/  \1
// [2] [3] [4] [5] [6]

// D: 00
// B: 01
// E: 100
// A: 101
// C: 11

// Huffman coding:

// char  frequency    code      bits

// 'A'       3        001     9  (3 x 3)
// 'B'       5        10      10 (5 x 2)
// 'C'       6        11      12 (6 x 2)
// 'D'       4        01      8  (4 x 2)
// 'E'       2        000     6  (2 x 3)
//                            Total 45 bits

// 45 bits message + 52 bits tree/table = 97 bits vs 160 bits originally

// Implementation:

// pair of char and its frequency
typedef std::pair<char, int> char_freq;

class MinHeapNode {
public:
    
    char_freq data;
    MinHeapNode *l_child, *r_child;
    
public:
    
    MinHeapNode (char_freq data) {
        this->data = data;
        l_child = r_child = nullptr;
    }
};

// comparing nodes in MinHeap
class CompLength {
public:
    bool operator() (MinHeapNode *left, MinHeapNode *right) {
        
        return left->data.second > right->data.second;
    }
};

void printCoding (MinHeapNode* myNode, std::string myString) {
    
    if (myNode == nullptr) return;
    
    if (myNode->data.first != '#') std::cout << myNode->data.first << ": " << myString << std::endl;
    
    printCoding(myNode->l_child, myString + '0');
    printCoding(myNode->r_child, myString + '1');
}

void HuffmanCoding (const std::vector<char_freq> &myArray) {
    
    MinHeapNode *top, *left, *right;
    
    std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, CompLength> minHeap;
    
    for (const auto &el: myArray) { minHeap.push(new MinHeapNode(el)); }
    
    while (minHeap.size() != 1) {
        
        left = minHeap.top();
        minHeap.pop();
        
        right = minHeap.top();
        minHeap.pop();
        
        char_freq temp ('#', left->data.second + right->data.second);
        
        top = new MinHeapNode(temp);
        
        top->l_child = left;
        top->r_child = right;
        
        minHeap.push(top);
    }
    
    printCoding(minHeap.top(), "");
}

int main (void) {
    
    std::vector<char_freq> myArray { {'A', 3}, {'B', 5}, {'C', 6}, {'D', 4}, {'E', 2} };
    
    HuffmanCoding(myArray);
}

