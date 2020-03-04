  
//
//  Graph_Greedy_PrimsMST.cpp
//  Graph
//
//  Created by Nulyaka on 3/4/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

// Prims Minimum Spanning Tree algorithm O(n^2), extra memory (3 arrays of size n)

#include <iostream>
#include <vector>

int minCostVertex (std::vector<int> &cost, std::vector<bool> &visited) {
    
    int minCost (INT_MAX), minIndex;
    
    for (int v(0); v < visited.size(); ++v) {
        
        if (!visited.at(v) && cost.at(v) < minCost) {
            
            minCost = cost.at(v);
            minIndex = v;
        }
    }
    
    return minIndex;
}

// Prints:
// Edges 	Weight
// 2->1	  16
// 3->2	  12
// 4->3	  22
// 5->4	  25
// 0->5  	10
// 1->6  	14

// path: 0 -> 5 -> 4 -> 3 -> 2 -> 1 -> 6

void printPath (std::vector<int> &path, std::vector<std::vector<int>> &myGraph) {
    
    std::cout << "Edges \tWeight" << std::endl;
  
    for (int v(1); v < path.size(); ++v) {
        
        std::cout << path.at(v) << "->" << v << "\t" << myGraph.at(v).at(path.at(v)) << std::endl;
    }
}

void PrimsAlgo (std::vector<std::vector<int>> &myGraph) {
    
    int size = static_cast<int>(myGraph.size());
    
    std::vector<bool> visited (size, false);
    std::vector<int> cost (size, INT_MAX);
    std::vector<int> path (size);
    
    cost.at(0) = 0;
    path.at(0) = -1; // -1 cause it's root
    
    for (int e(0); e < size - 1; ++e) {
        
        // in order to find all conected vertices to u
        int u = minCostVertex(cost, visited);
        
        visited.at(u) = true;
        
        // u is a row in matrix, we iterate through all columns of u
        for (int v(0); v < size; ++v) {
            
            if (myGraph.at(u).at(v) && !visited.at(v)
                && myGraph.at(u).at(v) < cost.at(v)) {
                
                cost.at(v) = myGraph.at(u).at(v);
                path.at(v) = u;
            }
        }
    }
    
    printPath(path, myGraph);
}

int main (void) {
    
    std::vector<std::vector<int>> myGraph
    {
        { 0, 28,  0,  0,  0, 10,  0},
        {28,  0, 16,  0,  0,  0, 14},
        { 0, 16,  0, 12,  0,  0,  0},
        { 0,  0, 12,  0, 22,  0, 18},
        { 0,  0,  0, 22,  0, 25, 24},
        {10,  0,  0,  0, 25,  0,  0},
        { 0, 14,  0, 18, 24,  0,  0}
    };
    
    PrimsAlgo(myGraph);
}
