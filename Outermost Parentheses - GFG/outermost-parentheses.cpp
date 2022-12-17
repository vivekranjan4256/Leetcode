//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        int count=0;
        string res="";
        int start=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                count++;
            else
                count--;
            if(count!=0)
                continue;
            else{
                res+=s.substr(start+1,i-start-1);
                start=i+1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends