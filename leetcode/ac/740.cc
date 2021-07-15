#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    struct Num {
        int num;
        int sum;
    };

    typedef struct Num Num;


    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<Num> _nums;
        int i = 0;

        while (i < nums.size()) {
            Num num;
            num.num = nums[i];
            num.sum = 0;

            while (i < nums.size() && nums[i] == num.num) {
                num.sum += nums[i];
                i++;
            }

            _nums.push_back(num);
        }

        vector<vector<int>> dp;

        vector<int> num0;
        num0.push_back(0);
        num0.push_back(_nums[0].sum);
        dp.push_back(num0);

        for (int i = 1; i < _nums.size(); i++) {
            vector<int> numI;

            numI.push_back(max(dp[i - 1][0], dp[i - 1][1]));
            
            if (_nums[i].num == _nums[i - 1].num + 1) {
                numI.push_back(dp[i - 1][0] + _nums[i].sum);
            } else {
                numI.push_back(max(dp[i - 1][0], dp[i - 1][1]) + _nums[i].sum);
            }

            dp.push_back(numI);
        }

        return max(dp[_nums.size() - 1][0], dp[_nums.size() - 1][1]);
    }
};


int main() {
    Solution s;

    vector<int> nums = {1};

    cout << s.deleteAndEarn(nums);
}