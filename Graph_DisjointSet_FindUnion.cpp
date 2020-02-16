//
//  Graph_DisjointSet_FindUnion.cpp
//  Graph_DisjointSet
//
//  Created by Nulyaka on 2/15/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>


typedef int src;
typedef int dest;

typedef std::pair<src, dest> edge;

class Graph {
private:
    int vertices_number_m,
    edges_number_m;
    
public:
    std::vector<edge> edges;
    
public:
    Graph () {}
    
    Graph (int vertices_number, int edges_number):
    vertices_number_m(vertices_number),
    edges_number_m(edges_number) { edges.resize(edges_number); }
    
    int find_m (std::vector<int> &parent, int index);
    void union_m (std::vector<int> &parent, int firstv, int secondV);
    bool isCycle ();
};

int Graph::find_m (std::vector<int> &parent, int index) {
    
    if (parent.at(index) == -1) { return index; }
    
    return find_m(parent, parent.at(index));
}

void Graph::union_m (std::vector<int> &parent, int firstV, int secondV) {
    
    int firstSet = find_m(parent, firstV);
    int secondSet = find_m(parent, secondV);
    
    if (firstSet <= secondSet) { parent.at(secondSet) = firstSet; }
}

bool Graph::isCycle() {
    
    std::vector<int> parent (this->vertices_number_m, -1);
    
    for (int e(0); e < this->edges_number_m; ++e) {
        
        int firstV = find_m(parent, this->edges.at(e).first);
        int secondV = find_m(parent, this->edges.at(e).second);
        
        if (firstV == secondV) { return true; }
        
        union_m(parent, firstV, secondV);
    }
    
    return false;
}

int main (void) {
    
    // First example:
    
    Graph myGraph_c (8, 9);
    
    //  Circular Graph, 8 vertices, 9 edges
    //
    //   (0) ––– (2)
    //    |       |
    //   (1) ––– (3)
    //    |
    //   (4) ––– (6)
    //    |       |
    //   (5) ––– (7)
    //
    myGraph_c.edges = { {0, 1}, {2, 3}, {4, 5}, {6, 7}, {1, 3},
                        {1, 4}, {0, 2}, {5, 7}, {4, 6} };
    
    // true
    std::cout << myGraph_c.isCycle() << std::endl;
    
    
    
    // Second example:
    
    Graph myGraph_not_c (8, 7);
    
    //  not Circular Graph, 8 vertices, 7 edges
    //
    //   (0)     (2)
    //    |       |
    //   (1) ––– (3)
    //    |
    //   (4) ––– (6)
    //    |       |
    //   (5)     (7)
    //
    myGraph_not_c.edges = { {0, 1}, {2, 3}, {4, 5}, {6, 7},
                            {1, 3}, {1, 4}, {4, 6} };
    
    // false
    std::cout << myGraph_not_c.isCycle() << std::endl;
}

