#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n;
vector<int> a;

int memo[3001][3001][2];

int dp(int i, int j, int taro){
	if(i>j)return 0;

	int &ans=memo[i][j][taro];

	if(ans!=-1)return ans;
	
	if(taro){
		ans=max(a[i]+dp(i+1, j, 0), a[j]+dp(i, j-1, 0));
	}
	else{
		ans=min(dp(i+1, j, 1), dp(i, j-1, 1));
	}
	return ans;
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	a.resize(n);

	int sum=0;
	for(int i=0;i<n;i++)cin>>a[i], sum+=a[i];

	memset(memo, -1, sizeof(memo));

	int x=dp(0, n-1, 1);
	int y=sum-x;
	cout<<x-y<<"\n";
	
	return 0;
}