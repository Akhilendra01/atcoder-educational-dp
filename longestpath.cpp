#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define N (int)1e5

vector<int> a[N+1];
int dis[N+1];
bool vis[N];

int dfs(int node){
	vis[node]=1;
	for(int child: a[node]){
		if(vis[child]){
			dis[node]=max(dis[node], dis[child]+1);
			continue;
		}

		int dist=dfs(child);
		dis[node]=max(dis[node], dist+1);
	}
	return dis[node];
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n, m;	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x, y;
		cin>>x>>y;
		a[x].push_back(y);
	}

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	int mx=INT_MIN;
	for(int i=1;i<=n;i++)mx=max(mx, dis[i]);
	cout<<mx;
	return 0;
}