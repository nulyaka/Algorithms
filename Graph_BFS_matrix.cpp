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


void BFS_matrix (const std::vector<std::vector<bool>> &myGraph) {
    
    int rowSize = static_cast<int>(myGraph.at(0).size());
    std::vector<bool> visited (rowSize, false);
    int counter(1);
    
    std::queue<int> myQueue;
    myQueue.push(getRandomInRange(1, rowSize - 1));
    
    while (!myQueue.empty()) {
        
        int vertex = myQueue.front();
        myQueue.pop();
        
        if (!visited.at(vertex)) {
            
            visited.at(vertex) = true;
            std::cout << counter << ") visited -> " << vertex << std::endl;
            counter++;
        }
        
        for (int secondVertex(1); secondVertex < rowSize; ++secondVertex) {
            
            if (myGraph.at(vertex).at(secondVertex) && !visited.at(secondVertex)) {
                
                myQueue.push(secondVertex);
            }
        }
    }
}

int main (void) {
    
    // Graph example: 6 vertices, 6 edges
    //
    //        1
    //      /   \
    //     2    3
    //      \  /
    //       4
    //      / \
    //     5  6
    
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
