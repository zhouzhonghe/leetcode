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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Node
{
  public:
    int val;
    Node *left;
    Node *right;

    Node()
    {
    }

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

//输入整数数组 arr ，找出其中最小的 k
//个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

vector<int> quickSort(vector<int> &arr, int k, int l, int r)
{
    int i = l, j = r;
    while (i < j) {
        while (i < j && arr[j] >= arr[l])
            j--;
        while (i < j && arr[i] <= arr[l])
            i++;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[l]);
    if (i > k)
        return quickSort(arr, k, l, i - 1);
    if (i < k)
        return quickSort(arr, k, i + 1, r);
    vector<int> res;
    res.assign(arr.begin(), arr.begin() + k);
    return res;
}

vector<int> getLeastNumbers(vector<int> &arr, int k)
{
    if (k >= arr.size())
        return arr;
    return quickSort(arr, k, 0, arr.size() - 1);
}

int main()
{
    vector<int> nums{10, 2, 4, 6, 3, 7, 9, 8};
    nums = getLeastNumbers(nums, 1);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
}