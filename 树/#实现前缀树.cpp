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

/*剑指 Offer II 062
Trie（发音类似 "try"）或者说 前缀树是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。
这一数据结构有相当多的应用情景，例如自动补完和拼写检查。请你实现 Trie 类：
Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word在前缀树中，返回true；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，
返回 true ；否则，返回 false 。
 */
class Trie {
  private:
    struct TreeNode {
        bool isLast;
        vector<TreeNode *> sons;
        TreeNode(bool flag = false) : isLast(flag), sons(26, nullptr) {}
    };
    TreeNode *root;

  public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TreeNode(false);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode *tmp = root;
        int i = 0;
        for (i = 0; i < word.size(); i++) {
            if (tmp->sons[word[i] - 'a'] == nullptr) {
                break;
            }
            tmp = tmp->sons[word[i] - 'a'];
        }
        for (i = i; i < word.size(); i++) {
            TreeNode *node = new TreeNode(false);
            tmp->sons[word[i] - 'a'] = node;
            tmp = node;
        }
        tmp->isLast = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *tmp = root;
        int i = 0;
        for (i = 0; i < word.size(); i++) {
            if (tmp->sons[word[i] - 'a'] == nullptr) {
                return false;
            }
            tmp = tmp->sons[word[i] - 'a'];
        }
        if (tmp->isLast != true) {
            return false;
        } else {
            return true;
        }
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode *tmp = root;
        int i = 0;
        for (i = 0; i < prefix.size(); i++) {
            if (tmp->sons[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            tmp = tmp->sons[prefix[i] - 'a'];
        }
        return true;
    }
};