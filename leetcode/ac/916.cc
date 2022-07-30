#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void countLetters(map<char, int> &letters, const string &s)
    {
        for (auto &c : s)
        {
            letters[c] += 1;
        }
    }

    bool verifyUniversalWord(map<char, int> &words2, map<char, int> &word1)
    {

        for (auto &kv : words2)
        {
            if (word1.find(kv.first) == word1.end() || word1[kv.first] < kv.second)
            {
                return false;
            }
        }

        return true;
    }

    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> rst;

        map<char, int> words2LettersCount;

        for (auto &word2 : words2)
        {
            map<char, int> letters;
            countLetters(letters, word2);

            for (auto &kv : letters)
            {
                if (words2LettersCount.find(kv.first) == words2LettersCount.end())
                {
                    words2LettersCount.insert(kv);
                }
                else if (words2LettersCount[kv.first] < kv.second)
                {
                    words2LettersCount[kv.first] = kv.second;
                }
            }
        }

        for (auto &word1 : words1)
        {
            map<char, int> letters;
            countLetters(letters, word1);
            if (verifyUniversalWord(words2LettersCount, letters))
            {
                rst.push_back(word1);
            }
        }

        return rst;
    }
};
