#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left, right, ans;

        left = 0;
        right = 0;
        ans = 0;

        map<char, int> charNums;

        while (right < s.size()) {
            do {
                charNums[s[right]]++;
                right++;
            } while (right < s.size() && charNums.find(s[right]) == charNums.end());

            ans = max(ans, right - left);

            while (right < s.size() && s[left] != s[right]) {
                charNums.erase(s[left]);
                left++;
            }

            charNums.erase(s[left]);
            left++;
        }

        return ans;
    }
};


int main() {
    string s = "tmmzuxt";

    Solution solution;

    solution.lengthOfLongestSubstring(s);
}