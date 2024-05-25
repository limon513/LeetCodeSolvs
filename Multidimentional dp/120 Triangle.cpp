Qusetion Link: https://leetcode.com/problems/triangle/
the question suggests that given an triangle array, like pascel tree. we have to travarse from top to bottom and also calculate minimum path sum.
for every step we can go from a row to next row with the same colum number or the next one. ( array[row][col] -> array[row+1][col] or array[row+1][col+1] )
if we see the all possible path is like this for the array [[2],[3,4],[6,5,7],[4,1,8,3]]

    2
   3 4
  6 5 7
 4 1 8 3
So, it is a straight forward dynamic programming problem. we have two states row and column and we have to take the minimum of them;
                                                                   (row,col)
                                           (row+1, col)+array[row][col]   (row+1,col+1)+array[row][col]
now the code part:
class Solution {
public:
    int n;
    vector<vector<int>>ar;
    int dp[205][205];
    
    int magic(int row, int col){
        if(row>=n) return 0;    //if we are getting out of bounds the we have nothing there so return 0;
        if(dp[row][col]!=-1) return dp[row][col];   //memoization part
        int ans = 0;
        int a = magic(row+1,col)+ar[row][col];  //first state if we go from [row][col] to [row+1][col];
        int b = magic(row+1,col+1)+ar[row][col];//second state if we go from [row][col] to [row+1][col+1];
        ans = min(a,b); //take the minimum from them
        return dp[row][col] = ans;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        ar=triangle;
        for(int i=0; i<205; i++){
            for(int j=0; j<205; j++){
                dp[i][j]=-1;
            }
        }
        int ans = magic(0,0);   // start with row=0 and col=0;
        return ans;
    }
};
