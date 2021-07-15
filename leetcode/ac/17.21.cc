#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int left, right, ans;
        left = ans = 0;
        right = 1;

        vector<int> behindMax;
        int tmpMax;
        tmpMax = 0;

        for (int i = height.size() - 1; i >= 0; i--) {
            behindMax.push_back(tmpMax);
            tmpMax = max(height[i], tmpMax);
        }

        reverse(behindMax.begin(), behindMax.end());

        while (right < height.size()) {
            if (height[right] >= height[left] || behindMax[right] <= height[right]) {
                ans += calValue(left, right, height);
                
                while (right + 1 < height.size() && behindMax[right] == height[right + 1]) {
                    right += 1;
                }

                left = right; 
            }

            right++;
        }

        return ans;
    }

    int calValue(int left, int right, vector<int>& height) {
        int result;

        result = (right - left - 1) * min(height[left], height[right]);

        for (int i = left + 1; i < right; i++) {
            result -= height[i];
        }

        return result;
    }
};


int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solution;
    cout << solution.trap(height) << endl;
}