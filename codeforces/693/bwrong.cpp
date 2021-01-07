#include<bits/stdc++.h>
using namespace std;
#define joker ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define z 1000000007
#define sh 1000000000
#define mi2 500000004
#define pb push_back
#define pba pop_back
#define pf push_front
#define mpa make_pair
#define fi first
#define se second
#define pr(x) printf("%d ", x)
#define sc(x) scanf("%d",&x)
#define mxf INT_MAX
#define mnf INT_MIN
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;
typedef map<ll,ll> mpi;
typedef map<ll,pi> mpii;

void why_so_serious(){
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif 
}

int  main()
{
	
    //why_so_serious();

    int t;
    cin>>t;
    while(t--){
    	int n,i;
    	cin>>n;
    	int ar[n];
    	int sum=0;
    	for(i=0;i<n;i++){
    		cin>>ar[i];
    		sum+=ar[i];
    	}
    	if(sum&1){
    		cout<<"No"<<endl;

    	}
    	else{
			int cont = 0;
    		int m=sum/2;
    		int dp[m+1];
    		memset(dp,0,sizeof(dp));
    		dp[0]=1;
    		for(i=0;i<n;i++){
    			for(int j=m;j>0;j--){
    				if(j-ar[i]>=0)
    				{
    					dp[j]=max(dp[j-ar[i]], dp[j]);
    					cont++;
					}
    			}
    		}
			cout << "N of Operations: " << cont << endl;
    		if(dp[m])
    			cout<<"Yes"<<endl;
    		else
    			cout<<"No"<<endl;
    	}

    }
}
