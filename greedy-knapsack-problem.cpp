//
//  greedy-knapsack-problem.cpp
//  greedy
//
//  Created by Nulyaka on 2/20/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

// used for sorting vector of pairs
bool sortinrev(const std::pair<double, int> &a,
               const std::pair<double, int> &b)
{
    return (a.first > b.first);
}

// Knapsack Problem, greedy method
// O(n), extra memory (n size map)
int sumOfBestProfits (const std::vector<std::vector<int>>& objects, int limit) {
    
    int sumOfBestProfits(0);
    
    
    // pair: best profit (Profit / Weight), Index of objects
    typedef std::pair<double, int> pw_i;
    
    // Best Profit Objects
    std::vector<pw_i> bp_objects;
    
    for (int i(0); i < objects.at(0).size(); ++i) {
        
        // profit / weight
        double pw = (double)objects.at(0).at(i) / objects.at(1).at(i);
        
        bp_objects.push_back(std::pair<double, int>(pw, i));
    }
    
    std::sort(bp_objects.begin(), bp_objects.end(), sortinrev);
    
    int sum (0);
    
    for (auto it = bp_objects.begin(); it != bp_objects.end(); ++it) {
        
        sum += objects.at(1).at(it->second);
        sumOfBestProfits += objects.at(0).at(it->second);
        
        if (sum > limit) {
            
            sumOfBestProfits -= objects.at(0).at(it->second);
        }
    }

    return sumOfBestProfits;
}

int main (void) {
    
    std::vector<int> profits {10, 5, 15, 7, 6, 18, 3};
    std::vector<int> weights {2,  3,  5, 7, 1,  4, 1};
    
    std::vector<std::vector<int>> objects;
    objects.push_back(profits);
    objects.push_back(weights);
    
    int limit = 15;
    
    std::cout << sumOfBestProfits(objects, limit) << std::endl;
}
