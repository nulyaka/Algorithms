//
//  graph-dfs-matrix.cpp
//  graph
//
//  Created by Nulyaka on 2/12/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <random>

// randomly selecting vertex from graph to start searching
int getRandomInRange(int from, int to)
{
    std::random_device rd;  // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(from, to); // define the range
    
    return distr(eng);
}

// O(n^2)
void DFS_matrix (const std::vector<std::vector<bool>> &myGraph) {
    
    int mtrxSize = static_cast<int>(myGraph.size());
    std::vector<bool> visited (mtrxSize, false);
    int counter(1);
    
    std::stack<int> myStack;
    myStack.push(getRandomInRange(1, mtrxSize - 1));
    
    while (!myStack.empty()) {
        
        int vertex = myStack.top();
        myStack.pop();
        
        if (!visited.at(vertex)) {
            
            visited.at(vertex) = true;
            std::cout << counter << ") visited -> " << vertex << std::endl;
            counter++;
        }
        
        for (int secondVertex(1); secondVertex < mtrxSize; ++secondVertex) {
            
            if (myGraph.at(vertex).at(secondVertex) && !visited.at(secondVertex)) {
                
                myStack.push(secondVertex);
            }
        }
    }
}

int main (void) {
    
    // Graph example: 6 vertices, 6 edges
    //
    //        1
    //      /   \
    //     2     3
    //      \   /
    //        4
    //      /   \
    //     5     6
    
    std::vector<std::vector<bool>> myGraph
    {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    
    // All possible variations of DFS search
    // 1 -> 3 -> 4 -> 6 -> 5 -> 2
    // 2 -> 4 -> 6 -> 5 -> 3 -> 1
    // 3 -> 4 -> 6 -> 5 -> 2 -> 1
    // 4 -> 6 -> 5 -> 3 -> 1 -> 2
    // 5 -> 4 -> 6 -> 3 -> 1 -> 2
    // 6 -> 4 -> 5 -> 3 -> 1 -> 2
    DFS_matrix(myGraph);
}
