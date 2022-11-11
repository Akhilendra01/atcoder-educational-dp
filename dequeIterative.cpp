#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


int dp[3002][3002][2];

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++)cin>>a[i], sum+=a[i];

	memset(dp, 0, sizeof(dp));
 
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			dp[i][j][0]=min(dp[i+1][j][1], dp[i][j-1][1]);
			dp[i][j][1]=max(a[i-1]+dp[i+1][j][0], a[j-1]+dp[i][j-1][0]);
		}
	}

	int x=dp[1][n][1];
	int y=sum-x;
	cout<<x-y;
	return 0;
}