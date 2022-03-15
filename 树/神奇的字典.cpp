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

/*剑指 Offer II 064
设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 互不相同 。
如果给出一个单词，请判定能否只将这个单词中一个字母换成另一个字母，
使得所形成的新单词存在于已构建的神奇字典中。实现 MagicDictionary 类：
MagicDictionary() 初始化对象
void buildDict(String[] dictionary) 使用字符串数组 dictionary 设定该数据结构，dictionary
中的字符串互不相同
bool search(String searchWord) 给定一个字符串 searchWord ，判定能否只将字符串中
一个 字母换成另一个字母，使得所形成的新字符串能够与字典中的任一字符串匹配。如果可以，返回 true
；否则，返回 false 。
*/
class MagicDictionary {
  private:
    set<string> s;
    unordered_map<string, int> map;

  public:
    /** Initialize your data structure here. */
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for (string s : dictionary) {
            this->s.insert(s);
            for (int i = 0; i < s.size(); i++) {
                char c = s[i];
                s[i] = '*';
                map[s]++;
                s[i] = c;
            }
        }
    }

    bool search(string searchWord) {
        string tmp = searchWord;
        for (int i = 0; i < searchWord.size(); i++) {
            char c = searchWord[i];
            searchWord[i] = '*';
            if (map[searchWord] > 1 || (map[searchWord] == 1 && s.count(tmp) == 0)) {
                return true;
            }
            searchWord[i] = c;
        }
        return false;
    }
};