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

	int N, W; cin>>N>>W;

	vector<int> w(N);
	vector<int> v(N);

	for(int i=0;i<N;i++)cin>>w[i]>>v[i];

	int dp[N+1][W+1];
	memset(dp, 0, sizeof(dp));

	for(int i=1;i<=N;i++){
		for(int j=1;j<=W;j++){
			if(j-w[i-1]>=0)
				dp[i][j]=max(dp[i-1][j], v[i-1]+dp[i-1][j-w[i-1]]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[N][W];
	return 0;
}