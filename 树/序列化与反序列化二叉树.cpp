#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*剑指 Offer II 048
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，
同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
反序列化算法执行逻辑，只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) {
            return "";
        }
        queue<TreeNode *> q;
        q.push(root);
        string res = "";
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp == nullptr) {
                res += "None,";
            } else {
                res += to_string(tmp->val) + ",";
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        res.erase(res.size() - 1, 1);
        while (res[res.size() - 1] == 'e') {
            res.erase(res.size() - 5, 5);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.size() == 0) {
            return nullptr;
        }
        vector<TreeNode *> Nodes;
        for (int i = 0; i < data.size(); i++) {
            int j = i;
            while (j < data.size() && data[j] != ',') {
                j++;
            }
            string sub = data.substr(i, j - i);
            if (sub == "None") {
                Nodes.push_back(nullptr);
            } else {
                TreeNode *Node = new TreeNode(stoi(sub));
                Nodes.push_back(Node);
            }
            i = j;
        }
        int idx = 1;
        for (int i = 0; i < Nodes.size(); i++) {
            if (Nodes[i] != nullptr) {
                if (idx < Nodes.size()) {
                    Nodes[i]->left = Nodes[idx++];
                } else {
                    break;
                }
                if (idx < Nodes.size()) {
                    Nodes[i]->right = Nodes[idx++];
                } else {
                    break;
                }
            }
        }
        return Nodes[0];
    }
};