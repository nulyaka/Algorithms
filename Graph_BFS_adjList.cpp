//
//  Graph_BFS_adjList.cpp
//  Graph
//
//  Created by Nulyaka on 2/12/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
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

void BFS_adjList (std::vector<std::list<int>> &myGraph) {
    
    int graphSize = static_cast<int>( myGraph.size() );
    std::vector<bool> visited (graphSize, false);
    int counter (1);
    
    std::queue<int> myQueue;
    myQueue.push(getRandomInRange(0, graphSize - 1));
    
    while ( !myQueue.empty() ) {
        
        int vertex = myQueue.front();
        myQueue.pop();
        
        if (!visited.at(vertex)) {
            
            visited.at(vertex) = true;
            std::cout << counter << ") visited ->" << vertex << std::endl;
            counter++;
        }
        
        for (auto it = myGraph.at(vertex).begin(); it != myGraph.at(vertex).end(); ++it) {
            
            if ( !visited.at(*it) ) { myQueue.push(*it); }
        }
    }
}

int main (void) {
    
    // Graph example: 6 vertices, 6 edges
    //
    //        0
    //      /   \
    //     1     2
    //      \   /
    //        3
    //      /   \
    //     4     5
    
    std::vector<std::list<int>> myGraph
    {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2, 4, 5},
        {3},
        {3}
    };
    
    // All possible variations of BFS search
    // 0 -> 1 -> 2 -> 3 -> 4 -> 5
    // 1 -> 0 -> 3 -> 2 -> 4 -> 5
    // 2 -> 0 -> 3 -> 1 -> 4 -> 5
    // 3 -> 1 -> 2 -> 4 -> 5 -> 0
    // 4 -> 3 -> 1 -> 2 -> 5 -> 0
    // 5 -> 3 -> 1 -> 2 -> 4 -> 0
    BFS_adjList(myGraph);
}
