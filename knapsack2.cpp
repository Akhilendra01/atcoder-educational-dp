#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define inf (int)1e15;
	
int dp[105][(int)1e5+5];

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

	
	for(int i=1;i<=1e5;i++)dp[0][i]=1e15;
	for(int i=0;i<=100;i++)dp[i][0]=0;

	for(int i=1;i<=N;i++){
		for(int j=1;j<=1e5;j++){
			if(j-v[i-1]>=0)
				dp[i][j]=min(dp[i-1][j], w[i-1]+dp[i-1][j-v[i-1]]);
			else 
				dp[i][j]=dp[i-1][j];
		}
	}

	int res=1e5;
	while(dp[N][res]>W){
		res--;
	}
	cout<<res<<"\n";
	return 0;
}