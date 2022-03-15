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

/*剑指 Offer II 067
给定一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。
*/
// x在二进制中的第n位 = (x >> n) & 1
class Solution {
  private:
    struct TreeNode {
        TreeNode *left;
        TreeNode *right;
        TreeNode() : left(nullptr), right(nullptr) {}
    };

  public:
    int findMaximumXOR(vector<int> &nums) {
        TreeNode *root = new TreeNode();
        for (int num : nums) {
            TreeNode *tmp = root;
            for (int k = 30; k >= 0; k--) {
                int bit = (num >> k) & 1;
                if (bit == 1) {
                    if (tmp->right == nullptr) {
                        tmp->right = new TreeNode();
                    }
                    tmp = tmp->right;
                } else {
                    if (tmp->left == nullptr) {
                        tmp->left = new TreeNode();
                    }
                    tmp = tmp->left;
                }
            }
        }

        int res = 0;
        for (int num : nums) {
            TreeNode *tmp = root;
            int x = 0;
            for (int k = 30; k >= 0; k--) {
                int bit = (num >> k) & 1;
                if (bit == 1) {
                    if (tmp->left != nullptr) {
                        tmp = tmp->left;
                        x += (1 << k);
                    } else {
                        tmp = tmp->right;
                    }
                } else {
                    if (tmp->right != nullptr) {
                        tmp = tmp->right;
                        x += (1 << k);
                    } else {
                        tmp = tmp->left;
                    }
                }
            }
            res = max(res, x);
        }
        return res;
    }
};