//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int result=0;
        if(str[0]=='-'){
             for(int i=1;i<str.size();i++){
            int temp=str[i]-'0';
            if(temp<0||temp>9)
                return -1;
            else{
                result=result*10+temp;
            }
            
        }
        result=-1*result;
        }
        else{
        for(int i=0;i<str.size();i++){
            int temp=str[i]-'0';
            if(temp<0||temp>9)
                return -1;
            else{
                result=result*10+temp;
            }
        }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends