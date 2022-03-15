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
实现一个 MapSum 类，支持两个方法，insert 和 sum：
MapSum() 初始化 MapSum 对象
void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。
如果键 key已经存在，那么原来的键值对将被替代成新的键值对。
int sum(string prefix) 返回所有以该前缀 prefix开头的键 key 的值的总和。
*/
class MapSum {
  private:
    struct TreeNode {
        int val;
        bool isLast;
        vector<TreeNode *> sons;
        TreeNode(bool flag = false) : isLast(flag), sons(26, nullptr), val(0) {}
    };
    TreeNode *root;

  public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TreeNode(false);
    }

    void insert(string key, int val) {
        TreeNode *tmp = root;
        int i = 0;
        for (i = 0; i < key.size(); i++) {
            if (tmp->sons[key[i] - 'a'] == nullptr) {
                break;
            }
            tmp = tmp->sons[key[i] - 'a'];
        }
        for (i = i; i < key.size(); i++) {
            TreeNode *node = new TreeNode(false);
            tmp->sons[key[i] - 'a'] = node;
            tmp = node;
        }
        tmp->isLast = true;
        tmp->val = val;
    }

    int sum(string prefix) {
        int res = 0;
        TreeNode *tmp = root;
        int i = 0;
        for (i = 0; i < prefix.size(); i++) {
            if (tmp->sons[prefix[i] - 'a'] == nullptr) {
                return res;
            }
            tmp = tmp->sons[prefix[i] - 'a'];
        }
        stack<TreeNode *> s;
        s.push(tmp);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if (node->isLast == true) {
                res += node->val;
            }
            for (int i = 0; i < 26; i++) {
                if (node->sons[i] != nullptr) {
                    s.push(node->sons[i]);
                }
            }
        }
        return res;
    }
};