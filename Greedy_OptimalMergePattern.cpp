//
//  Greedy_OptimalMergePattern.cpp
//  Greedy
//
//  Created by Nulyaka on 2/29/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <list>
#include <queue>

// s_l stands for (SIZE, LIST)
// pair of list length(SIZE) and list itself(LIST)
typedef std::pair<int, std::list<int>> s_l;

// needed for inserting elements inside of priority queue (Min Heap)
class CompLength {
public:
    bool operator() (const s_l &first, const s_l &second) {
        return first.first < second.first;
    }
};

// Optimal Merge Pattern

// There are pairs (list length, list itself) in Min Heap (priority queue)
// Top element (root) of this queue is the pair with the less list length

// Popping two lists with lowest length and merging them
// New list with new length is being inserted again in heap as a pair
// Continuing it, until one pair is left
std::list<int> mergeOptimal (std::priority_queue<s_l, std::vector<s_l>, CompLength> &myLists) {
    
    while (myLists.size() > 1) {
        
        int firstSize = myLists.top().first;
        std::list<int> first_l = myLists.top().second;
        myLists.pop();
        
        int secondSize = myLists.top().first;
        std::list<int> second_l = myLists.top().second;
        myLists.pop();
        
        // list1 size + list2 size
        int mergedSize = firstSize + secondSize;
        
        // first two lists merged in first_l
        first_l.merge(second_l);
        
        // pushing in heap again
        myLists.push(s_l(mergedSize, first_l));
    }
    
    // only one pair is left in heap, returning its list
    return myLists.top().second;
}

int main (void) {
    
    std::priority_queue<s_l, std::vector<s_l>, CompLength> myLists;
    
    myLists.push(s_l(1, { 4 }));
    myLists.push(s_l(2, { 5 , 7 }));
    myLists.push(s_l(4, { 6, 7, 8, 10 }));
    myLists.push(s_l(6, { 1, 3, 8, 12, 15, 18 }));
    myLists.push(s_l(6, {-10, -2, 0, 2, 9, 20}));
    
    std::list<int> result = mergeOptimal(myLists);
    
    for (std::list<int>::iterator it = result.begin(); it != result.end(); ++it) {
        
        std::cout << *it << std::endl;
    }
}

