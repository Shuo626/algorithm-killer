#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    string tmp;
    string _digits;
    vector<string> ans;
    map<char, string> digToLetter;


    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return ans;
        }
        
        _digits = digits;

        initDigitToLetterMap();
        dfs(0);

        return ans;
    }

    void initDigitToLetterMap() {
        digToLetter['2'] = "abc";
        digToLetter['3'] = "def";
        digToLetter['4'] = "ghi";
        digToLetter['5'] = "jkl";
        digToLetter['6'] = "mno";
        digToLetter['7'] = "pqrs";
        digToLetter['8'] = "tuv";
        digToLetter['9'] = "wxyz";
    }

    void dfs(int idx) {
        if (idx >= _digits.length()) {
            ans.push_back(tmp);
            return;
        }

        string letters = digToLetter[_digits[idx]];

        for (char &c: letters) {
            tmp.push_back(c);
            dfs(idx + 1);
            tmp.pop_back();
        }
    }
};