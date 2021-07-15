#include <bits/stdc++.h>


using namespace std;


int main() {
    string s;

    cin >> s;

    map<char, int> charToNum;

    for (char c: s) {
        if (charToNum.find(c) == charToNum.end()) {
            charToNum[c] = 1;
        } else {
            charToNum[c] += 1;
        }
    }

    int l, r;
    int ans, ansPositon;
    
    l = r = 0;
    ans = s.length();

    map<char, int> subCharToNum;

    for (r = 0; r < s.length(); r++) {
        if (subCharToNum.find(s[r]) == subCharToNum.end()) {
            subCharToNum[s[r]] = 1;
        } else {
            subCharToNum[s[r]] += 1;
        }

        while (subCharToNum[s[l]] > 1) {
            subCharToNum[s[l]] -= 1;
            l++;
        }

        if (subCharToNum.size() == charToNum.size()) {
            if (r - l + 1 < ans) {
                ans = r - l + 1;
                ansPositon = l;
            }
        }
    }

    cout << ansPositon << "," << ans << endl;
}