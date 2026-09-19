class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int index = -1;
        int max_count = -1;
        for(int i=0; i<n; i++){
            int countRow = 0;
            for(int j=0; j<m; j++){
                countRow += mat[i][j];
            }
        if(countRow > max_count){
            max_count = countRow;
            index = i;
        }
        }
        return {index , max_count};
    }
};