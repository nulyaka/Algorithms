#include <iostream>
#include <vector>
#include <list>
#include <queue>

typedef std::pair<int, int> dest_cost;

class CompareCost {
public:
    bool operator()(dest_cost a, dest_cost b) {
        return a.second > b.second;
    }
};

std::vector<int> DijsktraAlgorithm(std::vector<std::list<dest_cost>>& sources, int startSource) {
    
    int totalVertices = static_cast<int>(sources.size());
    
    // All vertices except source vertex will be infinity at the start
    std::vector<int> cost(totalVertices, INT_MAX);
    
    // distance from source is calculated and finalized
    std::vector<bool> included(totalVertices, false);
    
    // distance from source is calculated, not finalized
    std::vector<bool> relaxed(totalVertices, false);
    
    // keeps track of vertices whose minimum distance from source calculated and finalized
    std::priority_queue<dest_cost, std::vector<dest_cost>, CompareCost> shortestPath;
    
    shortestPath.push(std::make_pair(startSource, 0));
    relaxed.at(startSource) = true;
    cost.at(startSource) = 0;
    
    while (shortestPath.empty() == false) {
        
        dest_cost curr = shortestPath.top();
        shortestPath.pop();
        
        // v - current vertex
        int v      = curr.first;
        int v_cost = curr.second;
        
        included.at(v) = true;
        
        for (auto& neighbor : sources.at(v)) {
            
            int u      = neighbor.first;
            int u_cost = neighbor.second;
            
            if (included.at(u)) continue;
            
            if (relaxed.at(u)) {
                
                cost.at(u) = std::min(cost.at(u), v_cost + u_cost);
            }
            else {
                
                relaxed.at(u) = true;
                cost.at(u) = v_cost + u_cost;
                
                shortestPath.push(std::make_pair(u, v_cost + u_cost));
            }
        }
    }
    
    return cost;
}

int main(int argc, const char * argv[]) {
    
    
    std::vector<std::list<dest_cost>> sources
    {
        { {1, 4}, {7, 8}                   }, // 0
        { {0, 4}, {2, 8},  {7, 11}         }, // 1
        { {1, 8}, {3, 7},  {5, 4},  {8, 2} }, // 2
        { {2, 7}, {4, 9},  {5, 14}         }, // 3
        { {3, 9}, {5, 10}                  }, // 4
        { {2, 4}, {3, 14}, {4, 10}, {6, 2} }, // 5
        { {5, 2}, {7, 1},  {8, 6}          }, // 6
        { {0, 8}, {1, 11}, {6, 1},  {8, 7} }, // 7
        { {2, 2}, {6, 6},  {7, 7}          }  // 8
    };
    
    std::vector<int> res (DijsktraAlgorithm(sources, 0));
    
    for (int& el : res) {
        
        std::cout << el << " ";
    }
    
    return 0;
}
