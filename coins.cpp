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

	int n; cin>>n;

	double p[n];

	for(int i=0;i<n;i++)cin>>p[i];

	double dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));

	dp[0][0]=1;
	

	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			dp[i][j]=(j==0?0:dp[i-1][j-1]*p[i-1])+dp[i-1][j]*(1-p[i-1]);
		}
	}

	double ans=0;
	for(int i=0;i<=n;i++){
		int tails=n-i;
		if(i>tails)ans+=dp[n][i];
	}

	cout<<setprecision(10)<<fixed<<ans;
	return 0;
}