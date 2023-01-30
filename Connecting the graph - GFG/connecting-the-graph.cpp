//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DSU
{
public:
    vector<int> parent, rank, size;
    DSU(int n)//constructor
    {
        parent.resize(n + 1);//using n+1 allows for use with both 0 indexed and 1 indexed
        size.resize(n + 1, 1);//initial size is 1 as size means number of nodes in the component

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]); //path compression by ultimate parent as parent of each node while backtracking
    }

    //rank is not exactly height as when we do path compression on the longer branch then other branch will remain unaffected so the actual height should decrease but the rank is not changed
    //it acts like height if we assume the path compression process to be imaginary and just to help us
    void union_rank(int u, int v)
    {
        int ulPar_u = findUPar(u), ulPar_v = findUPar(v);
        if (ulPar_u == ulPar_v)return ;

        if (rank[ulPar_u] > rank[ulPar_v])//lower rank component is merged to higher rank component as this way rank(height) of new component remains same
        {
            parent[ulPar_v] = ulPar_u;
        }
        else if (rank[ulPar_u] < rank[ulPar_v])
        {
            parent[ulPar_u] = ulPar_v;
        }
        else//if rank of both ultimate parents is same then we join anyone to another and one of them acts as the ultimate parent,thus we increase rank of the new ultimate parent by 1
        {
            parent[ulPar_u] = ulPar_v;
            rank[ulPar_v]++;
        }
    }

    //union by rank is not exactly intuitive due to rank and height differece so union by size makes it more intuitive
    void union_size(int u, int v)
    {
        int ulPar_u = findUPar(u), ulPar_v = findUPar(v);
        if (ulPar_u == ulPar_v)return ;

        if (size[ulPar_u] > size[ulPar_v])
        {
            parent[ulPar_v] = ulPar_u;
            size[ulPar_u] += size[ulPar_v];
        }
        else
        {
            parent[ulPar_u] = ulPar_v;
            size[ulPar_v] += size[ulPar_u];
        }
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DSU ds(n);
        int countextra=0;
        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            if(ds.findUPar(u)==ds.findUPar(v))
                countextra++;
            else
                ds.union_size(u,v);
        }
        int countconnected=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i)
                countconnected++;
        }
        if(countextra>=countconnected-1)
            return countconnected-1;
        else
            return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends