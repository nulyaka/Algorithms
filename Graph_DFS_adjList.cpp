//
//  Graph_DFS_adjList.cpp
//  Graph
//
//  Created by Nulyaka on 2/12/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
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

void DFS_adjList (std::vector<std::list<int>> &myGraph) {
    
    int graphSize = static_cast<int>( myGraph.size() );
    std::vector<bool> visited (graphSize, false);
    int counter (1);
    
    std::stack<int> myStack;
    myStack.push(getRandomInRange(0, graphSize - 1));
    
    while ( !myStack.empty() ) {
        
        int vertex = myStack.top();
        myStack.pop();
        
        if (!visited.at(vertex)) {
            
            visited.at(vertex) = true;
            std::cout << counter << ") visited ->" << vertex << std::endl;
            counter++;
        }
        
        for (auto it = myGraph.at(vertex).begin(); it != myGraph.at(vertex).end(); ++it) {
            
            if ( !visited.at(*it) ) { myStack.push(*it); }
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
    
    // All possible variations of DFS search
    // 0 -> 2 -> 3 -> 5 -> 4 -> 1
    // 1 -> 3 -> 5 -> 4 -> 2 -> 0
    // 2 -> 3 -> 5 -> 4 -> 1 -> 0
    // 3 -> 5 -> 4 -> 2 -> 0 -> 1
    // 4 -> 3 -> 5 -> 2 -> 0 -> 1
    // 5 -> 3 -> 4 -> 2 -> 0 -> 1
    DFS_adjList(myGraph);
}
