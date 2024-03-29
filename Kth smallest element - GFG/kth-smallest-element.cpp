//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    
    int partition(int arr[],int l,int r){
        int x=arr[r];
        int i=l-1;
        for(int j=l;j<=r-1;j++){
            if(arr[j]<=x){
                i=i+1;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[r]);
        return i+1;
    }
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        if(l==r)
            return arr[l];
        int pos=partition(arr,l,r);
        int count=pos-l+1;
        if(count==k)
            return arr[pos];
        else if(count>k)
            return kthSmallest(arr,l,pos-1,k);
        else
            return kthSmallest(arr,pos+1,r,k-count);
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends