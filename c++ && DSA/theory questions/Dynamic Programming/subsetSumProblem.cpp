#include<bits/stdc++.h>
using namespace std;

//using plain recursion
bool isSubsetSum1(int arr[] , int n , int sum){
    if(sum == 0)
        return true;
    if(n == 0)
        return false;
    
    if(arr[n-1] <= sum)
        return isSubsetSum1(arr , n -1 , sum - arr[n-1]) || isSubsetSum1(arr , n-1 , sum);
    else 
        return isSubsetSum1(arr , n-1 , sum);
}



//using tabulation : bottom up
bool isSubsetSum2(int arr[] , int n , int sum){
    bool dp[n+1][sum + 1];                       //dp matrix or the subproblem matrix;

    for(int i = 0  ; i<=n ; i++){                //initialization
        dp[i][0] = true;
    }
    for(int i = 1 ; i<=sum ; i++){
        dp[0][i] = false;
    }

    for(int i = 1 ; i<=n ; i++){                  //building the subproblem matrix by using prev values going upto the final ans
        for(int j = 1 ; j<=sum ; j++){            //while building this matrix for ij we assume we have problems of smaller i and j : basically the thought of recrursion is seen here
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
            else   
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main(){
    int arr[]  = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr)/sizeof(int);
    cout<<boolalpha<<isSubsetSum2(arr , n , 9)<<endl;
    cout<<isSubsetSum1(arr,  n , 9)<<endl;
    
    return 0;
}