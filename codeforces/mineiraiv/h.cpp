//JP - Not in Kansas Anymore
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
// #define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 250;

# define sq(x) ((x)*(ll)(x))

struct pt{
    int x,y;
    pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    bool operator < (const pt p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator == (const pt p) const {
        return x == p.x and y == p.y;
    }
    pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    pt operator * (const int c) const { return pt(x*c, y*c); }
    ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
    ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
    friend istream& operator >> (istream& in, pt& p){
        return in >> p.x >> p.y;
    }
};

struct line {
    pt p, q;
    line() {}
    line(pt p_, pt q_) : p(p_), q(q_) {}
    friend istream& operator >> (istream& in, line& r) {
        return in >> r.p >> r.q;
    }
};

ll sarea2(pt p, pt q, pt r) {
    return (q-p) ^(r-q);
}

bool ccw(pt p, pt q, pt r){
    return sarea2(p, q, r) > 0;
}

bool isinseg(pt p, line r){
    pt a = r.p - p, b = r.q - p;
    return (a ^ b) == 0 and (a * b) <= 0;
}

bool interseg(line r, line s) {
    // if (isinseg(r.p, s) or isinseg(r.q, s)
    //    or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

    return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
                ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

bool check(pt p, pt q, vector<line> &lines, int id1, int id2){
    line a(p, q);
    for(int i = 0; i < lines.size(); i++) if(i != id1 and i != id2)
        if(interseg(a, lines[i])) return false;
    return true;
}

double dist(pt p, pt q){
    double h = p.x - q.x;
    double v = p.y - q.y;
    return sqrt(h*h + v*v);
}

double dis[MAX];
void dijkstra(int v, int n, vector<vector<pair<int, double>>> &g){
    for(int i = 0; i < n; i++) dis[i] = LINF;
    dis[v] = 0;
    priority_queue<pair<double, int>> pq;
    pq.emplace(0, v);

    while(not pq.empty()){
        auto [ndist, u] = pq.top(); pq.pop();
        if(-ndist > dis[u]) continue;

        for(auto [idx, w]: g[u]) if(dis[idx] > dis[u] + w) {
            dis[idx] = dis[u] + w;
            pq.emplace(-dis[idx], idx);
        }
    }
}

int32_t main(){ _
    pt alien, disco; cin >> alien >> disco;
    int n; cin >> n;
    vector<line> lines(n);

    for(int i = 0; i < n; i++) cin >> lines[i];

    vector<vector<pair<int, double>>> g(2*n + 2);
    
    // Alien
    for(int i = 0; i < n; i++){
        pt a = lines[i].p;
        pt b = lines[i].q;
        if(check(alien, a, lines, i, i))
            g[0].pb({2*i+1, dist(alien, a)}), g[2*i+1].pb({0, dist(alien, a)});
        if(check(alien, b, lines, i, i))
            g[0].pb({2*i+2, dist(alien, b)}), g[2*i+2].pb({0, dist(alien, b)});
    }
    
    int disi = 2*n + 1;
    if(check(alien, disco, lines, -1, -1)){
        g[0].pb({disi, dist(alien, disco)});
        g[disi].pb({0, dist(alien, disco)});
    }
    // Disco
    for(int i = 0; i < n; i++){
        pt a = lines[i].p;
        pt b = lines[i].q;
        if(check(disco, lines[i].p, lines, i, i))
            g[disi].pb({2*i+1, dist(disco, a)}), g[2*i+1].pb({disi, dist(disco, a)});
        if(check(disco, lines[i].q, lines, i, i))
            g[disi].pb({2*i+2, dist(disco, b)}), g[2*i+2].pb({disi, dist(disco, b)});
    }

    // Muros
    for(int i = 0; i < n; i++){
        pt a    = lines[i].p;
        int ida = 2*i + 1;
        pt b = lines[i].q;
        int idb = 2*i + 2;
        g[ida].pb({idb, dist(a, b)});
        g[idb].pb({ida, dist(a, b)});

        for(int j = i+1; j < n; j++){
            pt c = lines[j].p;
            int idc = 2*j + 1;
            pt d = lines[j].q;
            int idd = 2*j + 2;
            
            // A C
            double disn = dist(a, c);
            if(check(a, c, lines, i, j))
                g[ida].pb({idc, disn}), g[idc].pb({ida, disn});
            
            // A D
            disn = dist(a, d);
            if(check(a, d, lines, i, j))
                g[ida].pb({idd, disn}), g[idd].pb({ida, disn});

            // B C
            disn = dist(b, c);
            if(check(b, c, lines, i, j))
                g[idb].pb({idc, disn}), g[idc].pb({idb, disn});

            // B D
            disn = dist(b, d);
            if(check(b, d, lines, i, j))
                g[idb].pb({idd, disn}), g[idd].pb({idb, disn});
        }
    }

    dijkstra(0, 2*n + 2, g);
    cout << fixed << setprecision(2);
    cout << dis[disi] << endl;
    exit(0);
}
