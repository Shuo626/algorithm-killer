#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }

        map<int, int> nodeToDegree;
        map<int, set<int>> graph;

        for (auto& edge: edges) {
            nodeToDegree[edge[0]]++;
            nodeToDegree[edge[1]]++;

            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        queue<int> q;

        while (nodeToDegree.size() > 2) {
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                int x = *(graph[cur].begin());

                nodeToDegree[x]--;
                graph[x].erase(cur);
            }
            
            auto it = nodeToDegree.begin();
            
            while (it != nodeToDegree.end()) {
                if (it->second == 1) {
                    q.push(it->first);
                    it = nodeToDegree.erase(it);
                } else {
                    it++;
                }
            }
        }

        vector<int> ans;

        for (auto it = nodeToDegree.begin(); it != nodeToDegree.end(); it++) {
            ans.push_back(it->first);
        }

        return ans;
    }
};


int main() {
    Solution s;

    vector<vector<int>> e = {{0, 1}, {0, 2}, {0, 3}, {3, 4}, {4, 5}};

    s.findMinHeightTrees(6, e);
}
