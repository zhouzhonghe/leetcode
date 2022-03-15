#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> quickSort(vector<int> &nums);
void recur(vector<int> &nums, int l, int r);

vector<int> quickSort(vector<int> &nums)
{
    recur(nums, 0, nums.size() - 1);
    return nums;
}

void recur(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;
    int tmp = nums[l];
    int i = l, j = r; //为防止所有数都比基数大，左指针从基数开始
    while (i < j) {
        while (i < j && nums[j] >= tmp) //因为选择左端为基数，所以先向左循环
            j--;
        while (i < j && nums[i] <= tmp) //为防止左指针不动，必须用大于等于判断
            i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[i]);
    recur(nums, l, i - 1);
    recur(nums, i + 1, r);
}
int main()
{
    vector<int> nums{2, 4, 9, 3, 1, 7, 0, 8, 6, 5};
    nums = quickSort(nums);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
}