#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int dp[100001];

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin>>n>>k;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	/*
		state dp[i] = win or loss 1 or 0
		for each j in a
			dp[i]|=dp[i-j]^1
	*/

	dp[0]=0;
	for(int i=1;i<=k;i++){
		dp[i]=0;
		for(int j=0;j<n;j++){
			if(a[j]>i)continue;
			dp[i]|=dp[i-a[j]]^1;
		}
	}
	if(dp[k]==1)cout<<"First";
	else cout<<"Second";
	return 0;
}