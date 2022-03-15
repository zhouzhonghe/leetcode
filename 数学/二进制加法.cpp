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

class Solution
{
  public:
    string addBinary(string a, string b)
    {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string res = (i >= j) ? a : b;
        int ca = 0;
        for (int k = res.size() - 1; k >= 0; k--) {
            int aNum = (i >= 0) ? a[i] - '0' : 0;
            int bNum = (j >= 0) ? b[j] - '0' : 0;
            int sum = aNum + bNum + ca;
            if (sum == 0 || sum == 2)
                res[k] = '0';
            else
                res[k] = '1';
            ca = (sum >= 2) ? 1 : 0;
            i--;
            j--;
        }
        if (ca == 1)
            res.insert(0, "1");
        return res;
    }
};