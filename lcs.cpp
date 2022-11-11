#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	string s, t; cin>>s>>t;
	int n=s.length(), m=t.length();

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	string ans="";

	int i=n, j=m;
	while(i>0 and j>0){
		if(dp[i][j]>dp[i-1][j] and dp[i][j]>dp[i][j-1]){
			ans=s[i-1]+ans;
			i--;
			j--;
		}
		else{
			if(dp[i][j]==dp[i-1][j])i--;
			else j--;
		}
	}
	cout<<ans;
	
	return 0;
}