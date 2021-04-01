#include<bits/stdc++.h>


using namespace std;


#define MAX_N 2 * 100000
#define INF 0x3f3f3f3f;


int n;
int numbers[MAX_N];


int max3(int a, int b, int c) {
    return max(max(a, b), c);
}


int merge(int left_max, int right_max, int start, int end) {
    int mid;
    mid = (start + end) / 2;

    int index;
    int sum; 
    int tmp_left_max = -INF;
    int tmp_right_max = -INF;

    index = mid;
    sum = 0;
    while (index >= start) {
        sum += numbers[index];
        tmp_left_max = max(sum, tmp_left_max);

        index--;
    }

    index = mid + 1;
    sum = 0;
    while (index <= end) {
        sum += numbers[index];
        tmp_right_max = max(sum, tmp_right_max);

        index++;
    }

    int merge_max;
    merge_max = max3(tmp_left_max, tmp_right_max, tmp_right_max + tmp_left_max);

    return max3(left_max, right_max, merge_max);
}


int cal_max_sub_sum(int start, int end) {
    if (start == end) {
        return numbers[start];
    }

    int mid;
    mid = (start + end) / 2;

    int left, right;
    left = cal_max_sub_sum(start, mid);
    right = cal_max_sub_sum(mid + 1, end);
    
    return merge(left, right, start, end);
}


int main() {    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int ans;
    ans = cal_max_sub_sum(0, n - 1);

    cout << ans << endl;
}
