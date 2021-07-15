#include <bits/stdc++.h>


using namespace std;


class Solution0 {
public:
    bool isScramble(string s1, string s2) {
        return _isScramble(s1, s2);
    }


    bool _isScramble(string& s1, string& s2) {
        if (s1 == s2) {
            return true;
        }

        if (s1.size() == 1) {
            return false;
        }

        bool ans, result;
        ans = false;

        for (int i = 1; i < s1.size(); i++) {
            string ls1, rs1, ls2, rs2, cls2, crs2;

            ls1 = s1.substr(0, i);
            rs1 = s1.substr(i, s1.size() - i);
            ls2 = s2.substr(0, i);
            rs2 = s2.substr(i, s2.size() - i);
            cls2 = s2.substr(0, s2.size() - i);
            crs2 = s2.substr(s2.size() - i, i);

            result = _isScramble(ls1, ls2) && _isScramble(rs1, rs2) || _isScramble(ls1, crs2) && _isScramble(rs1, cls2);
            ans = ans || result;
        }

        return ans;
    }
};


class Solution {
public:
    bool dp[30][30][30];


    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        if (s1.size() != s2.size()) {
            return false;
        }

        int len;

        len = s1.size();

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                dp[i][j][0] = s1[i] == s2[j];
            }
        }

        for (int l = 2; l <= len; l++) {
            for (int i = 0; i < len - l + 1; i++) {
                for (int j = 0; j < len - l + 1; j++) {
                    bool a, b;
                    for (int k = 1; k < l; k++) {
                        a = dp[i][j][k - 1] && dp[i + k][j + k][l - k - 1];
                        b = dp[i][j + l - k][k - 1] && dp[i + k][j][l - k - 1];

                        if (a || b) {
                            break;
                        }
                    }
                    dp[i][j][l - 1] = a || b;
                }
            }
        }

        return dp[0][0][len - 1];
    }
};