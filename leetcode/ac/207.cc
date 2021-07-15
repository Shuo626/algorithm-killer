#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        map<int, vector<int>> graph;

        for (vector<int>& pair: prerequisites) {
            int a, b;
            a = pair[0];
            b = pair[1];

            inDegree[b] += 1;
            graph[a].push_back(b);
        }

        queue<int> que;
        int count;

        count = 0;

        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                que.push(i);
                count += 1;
            }
        }

        while (!que.empty()) {
            int n;

            n = que.front();
            que.pop();

            for (int& pre: graph[n]) {
                inDegree[pre] -= 1;
                
                if (inDegree[pre] == 0) {
                    que.push(pre);
                    count += 1;
                }
            }
        }

        return count == numCourses;
    }
};