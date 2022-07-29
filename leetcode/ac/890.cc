#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool compare(const string &word, const string &pattern)
    {
        if (word.size() != pattern.size())
        {
            return false;
        }

        map<char, char> p;
        map<char, bool> mappedChar;

        for (size_t i = 0; i < pattern.size(); i++)
        {
            if (p.find(pattern[i]) == p.end())
            {
                if (mappedChar.find(word[i]) == mappedChar.end())
                {
                    p.insert({pattern[i], word[i]});
                    mappedChar.insert({word[i], true});
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (p[pattern[i]] != word[i])
                {
                    return false;
                }
            }
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> rst;

        for (auto &word : words)
        {
            if (compare(word, pattern))
            {
                rst.push_back(word);
            }
        }

        return rst;
    }
};
