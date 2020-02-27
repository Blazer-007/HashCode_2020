// Vivek Rai
// Blazer_007

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")

#include <bits/stdc++.h>
#define fastio 		ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cin.exceptions(cin.failbit);
#define mp(i,j)     make_pair(i,j)
#define inf         0x3f3f3f3f
//#define INF         0x3f3f3f3f3f3f3f3fLL
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define FF           first
#define SS           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define bit(x, y)   (((x)>>(y))&1)
#define bctz(x)     (__builtin_ctz(x))
#define bclz(x)     (__builtin_clz(x))
#define bclzl(x)    (__builtin_clzll(x))
#define bctzl(x)    (__builtin_ctzll(x))
#define bpt(x)      (__builtin_popcount(x))
#define bptl(x)     (__builtin_popcountll(x))
#define loop(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

//#define INF 1000000007
// 
//ll f[100001];
// 
//ll pow(ll a, ll b, ll MOD)
//{
// ll x=1,y=a; 
// while(b > 0)
// 	{
// 		if(b%2 == 1)
// 	{
// 		x=(x*y);
// 		if(x>MOD) x%=MOD;
// 	}
// 	y = (y*y);
// 	if(y>MOD) y%=MOD; 
// 	b /= 2;
// 	}
// return x;
//}
 
/* Modular Multiplicative Inverse
 Using Euler's Theorem
 a^(phi(m)) = 1 (mod m)
 a^(-1) = a^(m-2) (mod m) */
//ll InverseEuler(ll n, ll MOD)
//{
// return pow(n,MOD-2,MOD);
//}
// 
//ll C(ll n, ll r, ll MOD)
//{
// 
// return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
//}

bool comp(pair<ll,ll> &p1,pair<ll,ll> &p2){
	return p1.FF>p2.FF ;
}

void solution(){
	ll b,l,d;
	cin>>b>>l>>d;
	vi score(b);
	loop(i,0,b){
		cin>>score[i];
	}
	vector<pair<ll,pair<ll,ll> > > library;
	vector<vector<pair<ll,ll> > > lbr;
	loop(i,0,l){
		ll bl,sign,scan;
		cin>>bl>>sign>>scan;
		pair<ll,ll> p1;
		p1 = mp(scan,i);
		pair<ll,pair<ll,ll> > p2;
		p2 = mp(sign,p1);
		library.pb(p2);
		vector<pair<ll,ll> > vec;
		loop(i,0,bl){
			ll idx;
			cin>>idx;
			vec.pb({score[idx],idx});
		}
		sort(all(vec),comp);
		lbr.pb(vec);
	} 
	sort(all(library));
	ll signup = 0;
	ll sum = 0;
	loop(i,0,l){
		sum += library[i].FF;
		if(sum>d){
			break;
		}else {
			signup++;
		}
	}
	cout<<signup<<endl;
	ll summ = 0;
	loop(i,0,signup){
		ll lib_id = library[i].SS.SS , scan = library[i].SS.FF ;
		cout<<lib_id<<" ";
		summ += library[i].FF;
		ll rem = d - summ ;
		ll books = sz(lbr[lib_id]);
		ll sizee;
		if((rem*scan)>=books){
			cout<<books<<endl;
			sizee = books;
		}else{
			ll bks = rem*scan ;
			sizee = bks;
			cout<<bks<<endl;
		}
		loop(i,0,sizee){
			cout<<lbr[lib_id][i].SS<<" ";
		}
		cout<<endl;
	}
	
}

signed main(){
    #ifndef ONLINE_JUDGE
    freopen("E:/COMPUTER/CP Codes/Hash Code/d_tough_choices.txt","r",stdin);
    freopen("E:/COMPUTER/CP Codes/Hash Code/d_tough_choices_output1.txt","w",stdout);
    #endif
    fastio;
//    f[0] = 1;
//	for(int i = 1 ; i <= 100000 ; i++)
//		f[i] = (f[i-1]*i)%INF;
//    clock_t time_req;
    //code to be written here
    int t=1;
//    cin>>t;
    for(int i=1;i<=t;i++){
    	//cout<<"Case #"<<i<<":";
    	solution();
	}  
	
	
//	time_req = clock() - time_req;
//    cout<<endl<< "Processor time taken is "<< (double)time_req/CLOCKS_PER_SEC << " seconds" << endl;
	     
    return 0;
}
