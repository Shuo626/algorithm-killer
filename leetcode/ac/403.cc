#include <bits/stdc++.h>


using namespace std;


class Solution0 {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) {
            return false;
        }

        return dfs(0, 1, 1, stones);
    }


    bool dfs(int lastIdx, int k, int p, vector<int>& stones) {
        if (k == 0) {
            return false;
        }

        int curIdx;

        for (curIdx = lastIdx + 1; curIdx < stones.size(); curIdx++) {
            if (stones[curIdx] == p) {
                break;
            }
            if (stones[curIdx] > p) {
                return false;
            }
        }

        if (curIdx == stones.size() - 1) {
            return true;
        }

        if (curIdx >= stones.size()) {
            return false;
        }

        return dfs(curIdx, k, p + k, stones) || dfs(curIdx, k - 1, p + k - 1, stones) || dfs(curIdx, k + 1, p + k + 1, stones);
    }
};


class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) {
            return false;
        }

        vector<vector<bool>> dp(stones.size(), vector<bool>(stones.size(), false));

        dp[1][1] = true;

        for (int i = 2; i < stones.size(); i++) {
            for (int j = i - 1; j >= 1; j--) {
                int k;
                k = stones[i] - stones[j];
                if (k <= j + 1) {
                    dp[i][k] = dp[i][k] || dp[j][k] || dp[j][k - 1] || dp[j][k + 1];
                }
            }
        }

        for (int i = 0; i < stones.size(); i++) {
            if (dp[stones.size() - 1][i]) {
                return true;
            }
        }

        return false;
    }
};


int main() {
    Solution solution;

    vector<int> v = {0, 1, 3, 6, 7};

    cout << solution.canCross(v);
}