/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */
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
// @lc code=start
class Solution {
public:
    int n, m;
    void dfs(vector<vector<int> >& mat, vector<vector<bool> >& visited, int i, int j){     
        if(visited[i][j]) return;
        visited[i][j] = true; 
        if(i + 1 <  n && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j); 
        if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
        if(j + 1 <  m && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1); 
        if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        n=h.size();
        m=h[0].size();
        vector<vector<bool>> v(n, vector<bool>(m, 0)), p(n, vector<bool>(m, 0));
        for(int i=0;i<n;i++){// calls sirf ocean connected cells se lagao
            dfs(h, v, i, 0);
            dfs(h, p, i, m-1);
        }
        for(int i=0;i<m;i++){
            dfs(h, v, 0, i);
            dfs(h, p, n-1, i);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j] and p[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
// @lc code=end

