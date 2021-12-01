//
// Created by huanyan on 2021/11/24.
//

class Solution {
public:
    bool dfs(vector <vector<char>> &board, vector <vector<bool>> &visited, string &word, int idx, int row, int col) {
        if (idx == word.size()) {
            return true;
        }

        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && !visited[row][col]) {
            if (board[row][col] != word[idx]) {
                return false;
            }
            visited[row][col] = true;
            bool flag = dfs(board, visited, word, idx + 1, row + 1, col) || dfs(board, visited, word, idx + 1, row - 1, col) || dfs(board, visited, word, idx + 1, row, col + 1) ||
                        dfs(board, visited, word, idx + 1, row, col - 1);
            visited[row][col] = false;
            return flag;
        }
        return false;
    }


    bool exist(vector <vector<char>> &board, string word) {
        vector <vector<bool>> visited(board.size(), vector<bool>(board[0].size()));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                bool flag = dfs(board, visited, word, 0, i, j);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};