//
//  Dynamic_MultiStage_Graph.cpp
//  Dynamic
//
//  Created by Nulyaka on 3/7/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>

// finding min path from first to last vertex
// O(n^2)

void printMinCostPath (int stages, const std::vector<std::vector<int>> &myGraph) {
    
    int size = static_cast<int>(myGraph.size());
    int last_el = size - 1;
    
    // dir - direction
    std::vector<int> cost(size, 0), dir(size), path(stages + 1);
    
    cost.at(last_el) = 0;
    
    for (int i (last_el - 1); i >= 1; --i) {
        
        int min = INT_MAX;
        
        for (int k (i + 1); k <= last_el; ++k) {
            
            if ( myGraph.at(i).at(k) && (myGraph.at(i).at(k) + cost.at(k) < min) ) {
                
                min = myGraph.at(i).at(k) + cost.at(k);
                
                dir.at(i) = k;
            }
            
            cost.at(i) = min;
        }
    }
    
    path.at(1) = 1; path.at(stages) = 8;
    
    std::cout << path.at(1);
    
    for (int i (2); i <= stages; ++i) {
        
        path.at(i) = dir.at(path.at(i - 1));
        std::cout << " -> " << path.at(i);
    }
    
    std::cout << std::endl;
}

int main (void) {
    
    int stages (4);
    
    std::vector<std::vector<int>> myGraph
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 1, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 3, 0, 0},
        {0, 0, 0, 0, 0, 6, 7, 0, 0},
        {0, 0, 0, 0, 0, 6, 8, 9, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    printMinCostPath (stages, myGraph);
}
