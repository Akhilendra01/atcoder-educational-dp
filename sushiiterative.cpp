#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

#define ld double


int32_t main(){


#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;

	vector<int> a(4, 0);
	for(int i=0;i<n;i++){
		int x; cin>>x;
		a[x]++;
	}

	ld dp[a[1]+a[2]+a[3]+1][a[2]+a[3]+1][a[3]+1];
	dp[0][0][0]=0;


	for(int k=0;k<=a[3];k++){
		for(int j=0;j<=a[2]+a[3];j++){
			for(int i=0;i<=a[1]+a[2]+a[3];i++){
				if(i+j+k==0)continue;

				dp[i][j][k]=1;
				
				ld p0=((ld)(n-i-j-k))/n;
				ld p1=((ld)i)/n;
				ld p2=((ld)j)/n;
				ld p3=((ld)k)/n;

				if(i>0)dp[i][j][k]+=dp[i-1][j][k]*p1;
				if(j>0 and i<n)dp[i][j][k]+=dp[i+1][j-1][k]*p2;
				if(k>0 and j<n)dp[i][j][k]+=dp[i][j+1][k-1]*p3;
			
				dp[i][j][k]/=((ld)1-p0);
			}
		}
	}

	cout<<setprecision(10)<<fixed<<dp[a[1]][a[2]][a[3]];
	
	return 0;
}