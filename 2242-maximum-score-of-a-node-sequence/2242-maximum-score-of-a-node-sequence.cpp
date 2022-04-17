#include <bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std; 
using namespace __gnu_pbds;
  
#define loop(i, a, b) for (int i = a; i < b; i++) 
#define si(x) scanf("%d", &x) 
#define sl(x) scanf("%lld", &x) 
#define ss(s) scanf("%s", s) 
#define pi(x) printf("%d\n", x) 
#define pl(x) printf("%lld\n", x) 
#define ps(s) printf("%s\n", s) 
#define sz(x) (int)x.size()
#define pb push_back 
#define mid(l, r) (l+(r-l)/2)
#define set_bits(x) __builtin_popcountll(x)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define mp make_pair 
#define ll long long 
#define F first 
#define mod 1000000007
#define mod1 998244353
#define inf 1e18
#define rall(x) x.rbegin(),x.rend()
#define S second 
#define PI 3.141592653589793238
// #define b(x) x.begin()
// #define e(x) x.end() 
// vector, pair, set, multiset, map, variable, valarray;
#define debug(x) cout << #x <<" -> "; _print(x); cout << endl;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define init(x, v) memset(x, v, sizeof(x)) 
#define sortall(x) sort(all(x)) 

typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pl; 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<pii> vpii; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

//void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout <<"\""<< t<<"\"";}
void _print(char t) {cout <<"\'"<< t<<"\'";}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.F); cout << ", "; _print(p.S); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(valarray <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

class Solution {
public:
    int maximumScore(vector<int>& s, vector<vector<int>>& edges) {
        int n=s.size();
        vector<vector<int>> l(n);
        for(auto x:edges){
            l[x[0]].push_back(x[1]);
            l[x[1]].push_back(x[0]);
        }
        for(auto &x:l){
            sort(x.begin(), x.end(), [&](int a, int b){
                return s[a]>s[b];
            });
        }
        int ans=-1;
        for(auto &e:edges){
            int u=e[0], v=e[1];
            int res=s[u]+s[v];
            for(int i=0;i<min(3, (int)l[u].size());i++){
                int x=l[u][i];
                if(x==v)continue;
                for(int j=0;j<min(3, (int)l[v].size());j++){
                    int y=l[v][j];
                    if(y==u or x==y){
                        continue;
                    }
                    ans=max(ans, res+s[x]+s[y]);
                }
            }
        }
        return ans;
    }
};