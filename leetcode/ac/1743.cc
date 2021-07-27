#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;

        map<int, int> numCount;
        map<int, int> leftToRight;
        map<int, int> rightToLeft;

        for (auto pair: adjacentPairs) {
            numCount[pair[0]] += 1;
            numCount[pair[1]] += 1;

            if (leftToRight.find(pair[0]) == leftToRight.end()) {
                leftToRight[pair[0]] = pair[1];
            } else {
                rightToLeft[pair[0]] = pair[1];
            }

            if (leftToRight.find(pair[1]) == leftToRight.end()) {
                leftToRight[pair[1]] = pair[0];
            } else {
                rightToLeft[pair[1]] = pair[0];
            }
        }

        vector<int> boundNum;

        for (auto iter = numCount.begin(); iter != numCount.end(); iter++) {
            if (iter->second == 1) {
                boundNum.push_back(iter->first);
            }
        }

        int firstNum, endNum, tmpNum;

        firstNum = boundNum[0];
        endNum = boundNum[1];

        ans.push_back(firstNum);

        if (leftToRight.find(firstNum) != leftToRight.end()) {
            ans.push_back(leftToRight[firstNum]);
            tmpNum = leftToRight[firstNum];
        } else {
            ans.push_back(rightToLeft[firstNum]);
            tmpNum = rightToLeft[firstNum];
        }

        while (tmpNum != endNum) {
            if (leftToRight.find(tmpNum) != leftToRight.end() && leftToRight[tmpNum] != ans[ans.size() - 2]) {
                tmpNum = leftToRight[tmpNum];
                ans.push_back(tmpNum);
            } else {
                tmpNum = rightToLeft[tmpNum];
                ans.push_back(tmpNum);
            }
        }

        return ans;
    }
};


int main() {
    vector<vector<int>> pairs = {{2, 1}, {3, 4}, {3, 2}};

    Solution solution;

    solution.restoreArray(pairs);
}