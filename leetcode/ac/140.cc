#include<bits/stdc++.h>


using namespace std;


// dfs
class Solution {
public:
    vector<string> sentences;
    vector<string> words;
    map<string, bool> isWords;
    map<int, bool> subCanSplitMap;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++) {
            isWords.insert(pair<string, bool>(wordDict[i], true));
        }
        dfs(s, 0, wordDict);

        return sentences;
    }

    bool dfs(string s, int index, vector<string>& wordDict) {
        if (index == s.size()) {
            catWords();
            return true;
        }

        int start;
        bool canSplit;
        start = index;
        canSplit = false; 

        while (index < s.size()) {
            string word;
            word = s.substr(start, index - start + 1);

            if (isWord(word, wordDict)) {
                words.push_back(word);
                if (subCanSplitMap.count(index + 1) == 0 || subCanSplitMap[index + 1] == true) {
                    canSplit = canSplit | dfs(s, index + 1, wordDict);
                } 
                words.pop_back();
            }

            index++;
        }

        subCanSplitMap[start] = canSplit;
        return canSplit;
    }

    void catWords() {
        string sentence;
        sentence = "";

        for (int i = 0; i < words.size(); i++) {
            sentence += words[i] + " "; 
        }

        sentence = sentence.substr(0, sentence.size() - 1);
        sentences.push_back(sentence);
    }

    bool isWord(string word, vector<string>& wordDict) {
        if (isWords.count(word) == 1) {
            return true;
        } else {
            return false;
        }
    }
};
