#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        map<char, int> charToNum;

        for (auto &c : s)
        {
            charToNum[c] += 1;
        }

        for (auto c : t)
        {
            if (charToNum.find(c) == charToNum.end() || charToNum[c] == 0)
            {
                return false;
            }
            charToNum[c] -= 1;
        }

        for (auto kv : charToNum)
        {
            if (kv.second != 0)
            {
                return false;
            }
        }

        return true;
    }
};
