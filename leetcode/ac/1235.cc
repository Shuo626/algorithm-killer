#include<bits/stdc++.h>


using namespace std;


class Solution {
public:
    struct Job {
        int startTime;
        int endTime;
        int profile;
    };

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> jobs;
        
        Job job;
        job.endTime = 0;
        jobs.push_back(job);

        for (int i = 0; i < startTime.size(); i++) {
            Job job;
            job.startTime = startTime[i];
            job.endTime = endTime[i];
            job.profile = profit[i];
            jobs.push_back(job);
        }
        sort(jobs.begin(), jobs.end(), compare);

        int dp[50005];
        int prev[50005];
        
        for (int i = 1; i < jobs.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (jobs[j].endTime <= jobs[i].startTime) {
                    prev[i] = j;
                    break;
                }
            }
        }

        dp[0] = 0;

        for (int i = 1; i < jobs.size(); i++) {
            dp[i] = max(dp[i - 1], dp[prev[i]] + jobs[i].profile);
        }

        return dp[jobs.size() - 1];
    }

    static bool compare(const Job& job1, const Job& job2) {
        return job1.endTime < job2.endTime;
    }
};