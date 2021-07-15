#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int dp[1001][1001];


    int longestCommonSubsequence(string text1, string text2) {
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = max3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + 1);
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }


    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }
};


int main() {
    string text1 = "abcde";
    string text2 = "ace";

    Solution solution;

    solution.longestCommonSubsequence(text1, text2);
}