#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define ld double

int n;

ld memo[301][301][301];

double dp(int z, int i, int j, int k){
	if(i+j+k==0)return 0;
	double &ans=memo[i][j][k];
	if(ans>0)return ans;

	ans=1;

	ld p0=((ld)(n-i-j-k))/n;
	ld p1=((ld)i)/n;
	ld p2=((ld)j)/n;
	ld p3=((ld)k)/n;

	if(i)ans+=dp(z+1, i-1, j, k)*p1;
	if(j)ans+=dp(z, i+1, j-1, k)*p2;
	if(k)ans+=dp(z, i, j+1, k-1)*p3;

	ans=ans/((ld)1-p0);

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

	vector<int> a(4, 0);
	for(int i=0;i<n;i++){
		int x; cin>>x;
		a[x]++;
	}
	memset(memo, -1, sizeof(memo));

	cout<<setprecision(10)<<fixed<<	dp(0, a[1], a[2], a[3]);
	
	return 0;
}