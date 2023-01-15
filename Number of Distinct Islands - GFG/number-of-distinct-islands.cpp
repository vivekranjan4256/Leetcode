//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,vector<pair<int,int>> &vec,int row0,int col0){
        vis[row][col]=1;
        vec.push_back({row-row0,col-col0});
        int n=grid.size();
        int m=grid[0].size();
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,-1,0,+1};
        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
                dfs(nrow,ncol,vis,grid,vec,row0,col0);
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,vis,grid,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
        }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends