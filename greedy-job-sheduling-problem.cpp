//
//  greedy-job-sheduling-problem.cpp
//  greedy
//
//  Created by Nulyaka on 2/28/20.
//  Copyright © 2020 Nulyaka. All rights reserved.
//

#include <iostream>
#include <vector>

// Job Sequencing with Deadlines


// pair of profit and deadline
typedef std::pair<int, int> job;

// comparing pair by their profit
bool sortinrev (job &pair1, job &pair2) {
    
    return pair1.first > pair2.first;
}

std::vector<int> JobSeq (std::vector<job> &jobs) {
    
    std::vector<int> mostProfit;
    
    // limiting working days to max value of deadline
    int lastDay = INT_MIN;
    
    for (int idx(0); idx < jobs.size(); ++idx) {
        
        if (lastDay < jobs.at(idx).second) lastDay = jobs.at(idx).second;
    }
    
    mostProfit.resize(lastDay, INT_MIN);
    // most profit jobes should be in the beginning
    std::sort(jobs.begin(), jobs.end(), sortinrev);
    
    for (int idx(0); idx < jobs.size(); ++idx) {
        
        int jobDay = jobs.at(idx).second - 1;
        
        if (jobDay >= lastDay) jobDay = lastDay;
        
        while (jobDay >= 0) {
            
            if (mostProfit.at(jobDay) < jobs.at(idx).first) {
                
                mostProfit.at(jobDay) = jobs.at(idx).first;
                break;
            }
            jobDay--;
        }
    }
    
    return mostProfit;
}

int main (void) {
    
    // given 4 days to do most profit jobs
    // vector jobs has pairs of profit and deadline for each job to do
    // using Greedy method we will choose most profit ones
    // limiting working days to maximal deadline value
    
    std::vector<job> jobs;
    jobs.push_back(job(35, 3));
    jobs.push_back(job(30, 4));
    jobs.push_back(job(25, 4));
    jobs.push_back(job(20, 2));
    jobs.push_back(job(15, 3));
    jobs.push_back(job(12, 1));
    jobs.push_back(job(5, 2));
    
    std::vector<int> mostProfit = JobSeq(jobs);
    
    // 20 25 35 30
    for (const auto &el: mostProfit) std::cout << el << ' ';
}

