#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
在英语中，有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——
我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，
可以形成新的单词 another(另一个)。现在，给定一个由许多词根组成的词典和一个句子，
需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。
需要输出替换之后的句子。
*/
class Solution {
  public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        string res = "";
        for (int i = 0; i < sentence.size(); i++) {
            int j = i + 1;
            while (j < sentence.size() && sentence[j] != ' ') {
                j++;
            }
            string word = sentence.substr(i, j - i);
            int minLen = INT_MAX;
            string substitute = "";
            for (int k = 0; k < dictionary.size(); k++) {
                int len = dictionary[k].size();
                if (len <= word.size() && len < minLen && word.substr(0, len) == dictionary[k]) {
                    minLen = len;
                    substitute = dictionary[k];
                }
            }
            if (substitute != "") {
                res += substitute;
            } else {
                res += word;
            }
            res += " ";
            i = j;
        }
        res.erase(res.size() - 1, 1);
        return res;
    }
};