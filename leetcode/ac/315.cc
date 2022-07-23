#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void merge(vector<pair<int, int>> &arr, size_t l, size_t mid, size_t r, vector<int> &counts)
    {
        size_t i, j;
        i = l;
        j = mid + 1;

        vector<pair<int, int>> tmp;

        while (i <= mid && j <= r)
        {
            if (arr[i].first <= arr[j].first)
            {
                tmp.push_back(arr[j++]);
            }
            else
            {
                counts[arr[i].second] += r - j + 1;
                tmp.push_back(arr[i++]);
            }
        }

        while (i <= mid)
        {
            tmp.push_back(arr[i++]);
        }

        while (j <= r)
        {
            tmp.push_back(arr[j++]);
        }

        for (i = l; i <= r; i++)
        {
            arr[i] = tmp[i - l];
        }
    }

    void mergeSort(vector<pair<int, int>> &arr, size_t l, size_t r, vector<int> &counts)
    {
        if (l == r)
        {
            return;
        }

        int mid = (l + r) / 2;
        mergeSort(arr, l, mid, counts);
        mergeSort(arr, mid + 1, r, counts);

        merge(arr, l, mid, r, counts);
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        size_t size = nums.size();
        vector<int> counts(size, 0);
        vector<pair<int, int>> arr;

        for (size_t i = 0; i < size; i++)
        {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, size - 1, counts);

        return counts;
    }
};
