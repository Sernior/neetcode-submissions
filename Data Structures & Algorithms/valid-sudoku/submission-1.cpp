class Solution {
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        array<bitset<9>, 9> righe, colonne, quadrati;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                const char c = board[i][j];
                if (c == '.') continue;
                const int d = c - '1';
                const int q = (i / 3) * 3 + j / 3;
                if (righe[i][d] || colonne[j][d] || quadrati[q][d]) return false;
                righe[i][d] = colonne[j][d] = quadrati[q][d] = true;
            }
        }
        return true;
    }
};
