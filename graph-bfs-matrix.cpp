//
//  Graph_BFS_matrix.cpp
//  Graph
//
//  Created by Nulyaka on 2/12/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
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
void BFS_matrix (const std::vector<std::vector<bool>> &myGraph) {
    
    int mtrxSize = static_cast<int>(myGraph.size());
    std::vector<bool> visited (mtrxSize, false);
    int counter(1);
    
    std::queue<int> myQueue;
    int root = getRandomInRange(1, mtrxSize - 1);
    
    myQueue.push(root);
    visited.at(root) = true;
    std::cout << counter << ") visited -> " << root << std::endl;
    counter++;
    
    while (!myQueue.empty()) {
        
        int vertex = myQueue.front();
        myQueue.pop();
        
        for (int secondVertex(1); secondVertex < mtrxSize; ++secondVertex) {
            
            if (myGraph.at(vertex).at(secondVertex) && !visited.at(secondVertex)) {
                
                myQueue.push(secondVertex);
                visited.at(secondVertex) = true;
                
                std::cout << counter << ") visited -> " << secondVertex << std::endl;
                counter++;
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
    
    // All possible variations of BFS search
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6
    // 2 -> 1 -> 4 -> 3 -> 5 -> 6
    // 3 -> 1 -> 4 -> 2 -> 5 -> 6
    // 4 -> 2 -> 3 -> 5 -> 6 -> 1
    // 5 -> 4 -> 2 -> 3 -> 6 -> 1
    // 6 -> 4 -> 2 -> 3 -> 5 -> 1
    BFS_matrix(myGraph);
}
