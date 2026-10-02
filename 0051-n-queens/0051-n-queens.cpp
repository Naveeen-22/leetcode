class Solution {
    bool isSafe(vector<string> &board, int row, int col, int n){
        for(int i=0; i<col; i++){
            if(board[row][i]=='Q')
            return false;
        }
        for(int i=0; i<row; i++){
            if(board[i][col]=='Q')
            return false;
        }
        for(int i=row-1, j=col-1; i>=0&&j>=0; i--,j--){
            if(board[i][j]=='Q')
            return false;
        }
        for(int i=row-1, j=col+1; i>=0&&j>=0; i--,j++){
            if(board[i][j]=='Q')
            return false;
    }
    return true;
    }
    void solve(int row, int n, vector<string> board, vector<vector<string>> &ans){
       if(row==n){
        ans.push_back(board);
        return;
       }
        for(int i=0; i<n; i++){
            if(isSafe(board, row,i,n)){
                board[row][i] = 'Q';
                solve(row+1, n, board, ans);
                board[row][i]= '.';

            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(0,n,board, ans);
        return ans;
    }
};