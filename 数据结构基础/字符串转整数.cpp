#include <cmath>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int strToInt(string str);

int strToInt(string str)
{
    int len = str.size();
    int start, end;
    char s = ' ';
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            if (str[i] == '+' || str[i] == '-') {
                if (i == len - 1)
                    return 0;
                start = i + 1;
                s = str[i];
                break;
            } else if ((str[i] - '0') <= 9 && (str[i] - '0') >= 0) {
                start = i;
                s = '+';
                break;
            } else
                return 0;
        }
    }
    cout << start << endl;
    if (s == ' ')
        return 0;
    for (int i = start; i < len; i++) {
        if ((str[i] - '0') > 9 || (str[i] - '0') < 0) {
            end = i - 1;
            break;
        }
        if (i == len - 1)
            end = i;
    }
    cout << end << endl;
    double sum = 0;
    for (int i = start; i <= end; i++) {
        sum += (str[i] - '0') * pow(10, end - i);
    }
    if (s == '-')
        sum *= -1;
    if (sum > pow(2, 31) - 1)
        return pow(2, 31) - 1;
    if (sum < -pow(2, 31))
        return -pow(2, 31);
    return sum;
}

int main()
{
    string str = "4193 with words";
    int num = strToInt(str);
    cout << num;
}