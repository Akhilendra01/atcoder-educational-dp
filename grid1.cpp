#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define mod 1000000007

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


	int h, w; cin>>h>>w;
	char mat[h][w];

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
			cin>>mat[i][j];
	}

	int dp[h+1][w+1];
	memset(dp, 0, sizeof(dp));
	dp[1][1]=1;	
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(mat[i-1][j-1]=='#')continue;
			dp[i][j]+=dp[i-1][j]+dp[i][j-1];
			dp[i][j]%=mod;
		}
	}
	cout<<dp[h][w];
	
	return 0;
}