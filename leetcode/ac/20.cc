#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    bool isValid(string s) {
        map<char, char> _map;
        _map[')'] = '(';
        _map[']'] = '[';
        _map['}'] = '{';

        stack<char> _stack;

        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                _stack.push(c);
            } else {
                if (_stack.size() == 0 || _stack.top() != _map[c]) {
                    return false;
                }

                _stack.pop();
            }
        }
        
        if (_stack.size() == 0) {
            return true;
        } else {
            return false;
        }
    }
};