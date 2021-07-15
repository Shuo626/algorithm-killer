#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;


int main() {
    int n, k;

    vector<int> nums;
    nums.push_back(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }

    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;

        for (int j = 0; j <= (r - l) / 2; j++) {
            int tmp;
            tmp = nums[l + j];
            nums[l + j] = nums[r - j];
            nums[r - j] = tmp;
        }
    }

    for (int i = 1; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
}