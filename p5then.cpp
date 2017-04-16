#include <bits/stdc++.h>

using namespace std;

int n, m;
int degree[100005];
vector<int> AdjList[100005];

int main() {
	int N;
	cin >> N;
	for(int x = 0; x < N; x++) {
		cin >> n >> m;

		for(int i = 0; i < 100005; i++) {
			degree[i]=0;
			AdjList[i]={};
		}
		
		for(int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			AdjList[a].push_back(b);
			degree[b]++;
		}

		priority_queue<int> pq;
		for(int i = 0; i < n; i++) {
			if(degree[i]==0) pq.push(i);
		}

		vector<int> ans;
		while(!pq.empty()) {
			int c = pq.top();
			pq.pop();

			for(int i = 0; i < AdjList[c].size(); i++) {
				degree[AdjList[c][i]]--;
				if(!degree[AdjList[c][i]]) {
					pq.push(AdjList[c][i]);
				}
			}

			ans.push_back(c);
		}

		for(int i = n-1; i >= 0; i--) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}