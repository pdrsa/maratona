// Time: (ubiratan, EduardoFernandes, pedrosa)
// pedrosa
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
  int n; cin >> n;
  vector<int> v(n);
  FOR(i,0,n) {
    char c; cin >> c;
    if(c == 'W') v[i] = 0;
    else v[i] = 1;
  }

  vector<int> branco, preto;
  auto novo_v = v;

  // BRANCO
  FOR(i,0,n-1) {
    if(v[i] == 0) continue;
    branco.pb(i);
    v[i] = 0;
    v[i+1] = (v[i+1]+1)%2;
  }
  if(v[n-1] == 0) {
    cout << branco.size() << endl;
    for(auto i :  branco) cout << i+1 << " ";
    cout << endl;
    return 0;
  }

  v = novo_v;

  // PRETO
  FOR(i,0,n-1) {
    if(v[i] == 1) continue;
    preto.pb(i);
    v[i] = 0;
    v[i+1] = (v[i+1]+1)%2;
  }
  if(v[n-1] == 1) {
    cout << preto.size() << endl;
    for(auto i :  preto) cout << i+1 << " ";
    cout << endl;
    return 0;
  }

  cout << -1 << endl;
  return 0;
}
