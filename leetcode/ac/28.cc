#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }

        if (haystack.size() < needle.size()) {
            return -1;
        }

        int i, j;

        for (i = 0; i <= haystack.size() - needle.size(); i++) {
            if (haystack[i] == needle[0] && check(haystack, needle, i)) {
                return i;
            }
        }

        return -1;
    }


    bool check(string& haystack, string& needle, int start) {
        for (int i = 0; i < needle.size(); i++) {
            if (haystack[i + start] != needle[i]) {
                return false;
            }
        }

        return true;
    } 
};