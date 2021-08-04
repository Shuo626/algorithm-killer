#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans;

        ans = 0;
        
        sort(nums.begin(), nums.end());

        int size;

        size = nums.size();

        for (int i = 0; i < size - 2; i++) {
            if (nums[i] == 0) {
                continue;
            }

            int k;

            k = i + 2;
            
            for (int j = i + 1; j < size - 1; j++) {
                while (k < size && nums[i] + nums[j] > nums[k]) {
                    k++;
                }

                ans += k - j - 1;
            }
        }

        return ans;
    }
};
