#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool d[50];
bool in[50];
bool out[50];

int n;

bool can(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < n and (!d[j]) and out[i] and in[j];
}

void bfs(int x) {
	memset(d, false, sizeof d);
	queue<int> q;

	d[x] = true;
	q.push(x);

	while(!q.empty()) {
		int s = q.front(); q.pop();
		if(can(s, s+1)){
			d[s+1] = true;
			q.push(s+1);
		}
		if(can(s, s-1)){
			d[s-1] = true;
			q.push(s-1);
		}
	}
}

int main(){ _
	int tt; cin >> tt;
	for(int t = 0; t < tt; t++){
		memset(in, false, sizeof in);
		memset(out, false, sizeof out);
		cin >> n;
		char aux;
		for(int i = 0; i < n; i++){
			cin >> aux;
			if(aux == 'Y') in[i] = true;
		}
		for(int i = 0; i < n; i++){
			cin >> aux;
			if(aux == 'Y') out[i] = true;
		}

		
		cout << "Case #" << t+1 << ":" << endl;
		for(int i = 0; i < n; i++){
			bfs(i);
			for(int j = 0; j < n; j++){
				if(d[j]) cout << 'Y';
				else cout << 'N';
			}
			cout << endl;
		}


	}
	exit(0);
}
