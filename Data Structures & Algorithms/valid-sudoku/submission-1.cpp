class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {

        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> subMat[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                char val = mat[i][j];

                // skip empty cells
                if (val == '.') continue;

                // check row
                if (rows[i].find(val) != rows[i].end())
                    return false;
                rows[i].insert(val);

                // check column
                if (cols[j].find(val) != cols[j].end())
                    return false;
                cols[j].insert(val);

                // calculate 3x3 box index
                int idx = (i / 3) * 3 + (j / 3);

                // check subgrid
                if (subMat[idx].find(val) != subMat[idx].end())
                    return false;
                subMat[idx].insert(val);
            }
        }

        return true;
    }
};