/*******************
*	8/15
********************/

// 网易 游历魔法王国
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
  
void traversal(int n,int L,vector<int> &parent){
    int maxlen=0;
    vector<int> dp(n);
    for(int i=0;i<n-1;i++){
        dp[i+1]=dp[parent[i]]+1;
    maxlen=max(maxlen,dp[i+1]);   //使用贪心算法计算最长链的长度
    } 
    int validpath=min(maxlen,L);
    cout<<min(n,1+validpath+(L-validpath)/2);    
 }
 int main(){
     int n,L;
     cin>>n>>L;
     vector<int> parent;
     for(int i=0;i<n-1;i++){
         int temp;
         cin>>temp;
         parent.push_back(temp);
     }
     traversal(n,L,parent);
     return 0;
 }