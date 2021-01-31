#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

int m,n;
v32 degree;
vector<v32> g;
void solve(vector<bool> &seen,int i,stack<int> &st){
   seen[i]=1;
   for(auto it:g[i]){
       if(seen[it]==false){
           solve(seen,it,st);
           
       }
   }
    st.push(i);
}
int main()
{
     fast_cin();
     ll t,i,j,k,q;
     cin >> n >> m;
     degree.resize(n+1,0);
     g.resize(n+1);
     for(int i=1;i<=m;i++) {
      int a,b; cin>>a>>b;
      g[a].push_back(b);
      degree[b]++;
    }
    vector<bool> seen(n+1,0),vis(n+1,0);
     stack<int> st;
    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            solve(seen,i,st);
        }
    }
    //if(st.empty() || flag==0) { cout<<"IMPOSSIBLE\n"; return 0; }
            
    unordered_map<int,int> Map;
    int idx=1;
    vector<int> tsort;
    while (!st.empty())
    {
        if(!vis[st.top()]){
           Map[st.top()]=idx;
           vis[st.top()]=1; idx++;
           tsort.pb(st.top());
        }
        st.pop();
    }
    for(int i=1;i<=n;i++){
        for(auto it:g[i]){
            if((Map.find(i)==Map.end() ||Map.find(it)==Map.end()) || Map[i] > Map[it]){
                cout<<"IMPOSSIBLE\n"; return 0;
            }
        }
    }
    for(int i=0;i<tsort.size();i++)
      cout<<tsort[i]<<" ";
  return 0;
}