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

	int n, k;	cin>>n>>k;

	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];

	vector<int> dp(n, INT_MAX);
	dp[0]=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			if(i-j<0)break;
			dp[i]=min(dp[i], dp[i-j]+abs(a[i]-a[i-j]));
		}
	}
	cout<<dp[n-1];
	
	return 0;
}