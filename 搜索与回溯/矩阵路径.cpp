#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

bool exist(vector<vector<char>> &board, string word);
bool dfs(vector<vector<char>> &board, string word, int i, int j, int k);

bool dfs(vector<vector<char>> &board, string word, int i, int j, int k)
{
    int row = board.size();
    int col = board[0].size();
    int len = word.size();
    if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[k])
        return false;
    if (k == len - 1)
        return true;
    board[i][j] = ' ';
    bool res = dfs(board, word, i + 1, j, k + 1) ||
               dfs(board, word, i - 1, j, k + 1) ||
               dfs(board, word, i, j + 1, k + 1) ||
               dfs(board, word, i, j - 1, k + 1);
    board[i][j] = word[k];
    return res;
}

bool exist(vector<vector<char>> &board, string word)
{
    int row = board.size();
    int col = board[0].size();
    bool res = false;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (dfs(board, word, i, j, 0))
                return true;
        }
    }
    return false;
}