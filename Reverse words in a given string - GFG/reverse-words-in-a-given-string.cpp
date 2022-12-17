//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        vector<string> v;
        string str="";
        for(int i=0;i<S.length();i++){
            if(S[i]=='.'){
                v.push_back(str);
                str="";
            }
            else
                str+=S[i];
        }
        v.push_back(str);
        string result="";
        for(int i=v.size()-1;i>0;i--){
            result+=v[i];
            result+=".";
        }
        result+=v[0];
        return result;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends