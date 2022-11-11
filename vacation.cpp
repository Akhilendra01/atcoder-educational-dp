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
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);

	for(int i=0;i<n;i++)cin>>a[i]>>b[i]>>c[i];

	int dp[n+1][3];
	memset(dp, 0, sizeof(dp));

	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][1], dp[i-1][2])+a[i-1];
		dp[i][1]=max(dp[i-1][0], dp[i-1][2])+b[i-1];
		dp[i][2]=max(dp[i-1][1], dp[i-1][0])+c[i-1];
	}

	cout<<max(dp[n][0], max(dp[n][1], dp[n][2]));
	
	return 0;
}