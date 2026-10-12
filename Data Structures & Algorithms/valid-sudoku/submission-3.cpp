class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    array<unordered_set<char>, 9> righe, colonne, quadrati;
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if (board[i][j] == '.')continue;
                if (!righe[i].insert(board[i][j]).second || !colonne[j].insert(board[i][j]).second || !quadrati[(i / 3) * 3 + (j / 3)].insert(board[i][j]).second)
                    return false;
            }
        }
        return true;
    }
};
