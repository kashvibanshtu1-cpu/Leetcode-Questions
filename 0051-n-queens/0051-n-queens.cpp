class Solution {
public:
bool isSafe(int row,int col,vector<string>&board){
    // Firstly check for col
    for(int r=row-1;r>=0;r--){
        if(board[r][col] =='Q'){
            return false;
        }
    }
      // for left upward diagonal(no need for downward traversal)
    int r=row-1;
    int c=col-1;
    while(r>=0 && c>=0){
        if(board[r][c]=='Q'){
            return false;
        }
        r--;
        c--;
    }
    // for right upward diagonal
    int r1= row-1;
    int c1 = col+1;

while(r1 >= 0 && c1 < board.size())
{
    if(board[r1][c1] == 'Q')
        return false;

    r1--;
    c1++;
}
return true;
}

 void fun(int n, int row, vector<vector<string>>&ans,vector<string>&board ){
    // Base case
    if(row==n){
        // queens ka track of queens also
        ans.push_back(board);
        return;
    }
    for(int col=0;col<n;col++){
       if(isSafe(row,col,board)){
        // place
        board[row][col]='Q';
        fun(n,row+1,ans,board);
        board[row][col]='.';// Backtrack
       }
    // noramlly next col pe chale jao
    }
    return;// AGr pure col mai khi bhi nahi rkh paaye toh simply return 
   
}
    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        fun(n,0,ans,board);
        return ans;
    }
};