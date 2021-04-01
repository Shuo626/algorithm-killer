#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> resultCab;
    vector<int> _nums;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> none;
        resultCab.push_back(none);

        _nums = nums;

        for (int i = 1; i <= nums.size(); i++) {
            C(i, nums.size());
        }

        return resultCab;
    }

    void C(int a, int b) {
        dfs(1, 0, a, b);
    }

    void dfs(int step, int start, int a, int b) {
        if (step > a) {
            updateResult();
            return;
        }

        for (int i = start; i < b; i++) {
            tmp.push_back(_nums[i]);
            dfs(step + 1, i + 1, a, b);
            tmp.pop_back();
        }
    }

    void updateResult() {
        if (!checkSame()) {
            resultCab.push_back(tmp);
        }
    }

    bool checkSame() {
        for (vector<int>& result: resultCab) {
            if (result == tmp) {
                return true;
            }
        }
        
        return false;
    }
};


int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    Solution solution;
    vector<vector<int>> result = solution.subsetsWithDup(nums);

    for (vector<int>& nn: result) {
        for (int& n: nn) {
            cout << n;
        }
        cout << endl;
    }
}