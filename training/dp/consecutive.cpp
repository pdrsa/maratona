//JP - Not in Kansas Anymore
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
const int MAX = 2e5 + 5;
int n;
map<int,int> dp;
vector<int> v;

int main(){ _
	cin >> n;
	v = vector<int>(n);
	for(int &i:v){
		cin >> i;
		if(dp.count(i-1)){
			dp[i] = max(dp[i], dp[i-1]+1);
		} else{
			dp[i] = 0;
		}
	}
	
	ii maxi = {0,0};
	for(auto i:dp){
		if(i.s > maxi.s) maxi = i;
	}
	
	cout << maxi.s + 1 << endl;
	if(maxi.s == 0){
		cout << 1 << endl; exit(0);
	}

	int aux = maxi.f - maxi.s;
	
	for(int i = 0; i < n and (aux <= maxi.f); i++){
		if(v[i] == aux){ cout << i+1 << " "; aux++;}
	}

	cout << endl;
	exit(0);
}
