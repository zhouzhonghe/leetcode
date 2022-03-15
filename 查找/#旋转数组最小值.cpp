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

//给你一个可能存在 重复 元素值的数组 numbers ，它原来是一个升序排列的数组，
//并按上述情形进行了一次旋转。请返回旋转数组的最小元素。例如，数组 [3,4,5,1,2]
//为 [1,2,3,4,5] 的一次旋转，该数组的最小值为1。  

int minArray(vector<int> &numbers) {
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (numbers[m] > numbers[m + 1])
            return numbers[m + 1];
        else if (numbers[m] > numbers[r])
            l = m + 1;
        else if (numbers[m] < numbers[r])
            r = m;
        else
            r--;
    }
    return numbers[l];
}