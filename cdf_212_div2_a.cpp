// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define auth map <pair <lld, lld>, lld> :: iterator
#define pb push_back
map <pair <lld, lld>, lld> vis1, vis2;
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld t, l;
      cin >> t;
      foi(l,t){
            vis1.clear();
            vis2.clear();
            char dda[9][9];
            for(lld i = 1; i <= 8; i += 1){
                  for(lld j = 1; j <= 8; j += 1){
                        cin >> dda[i][j];
                  }
            }
            pair <lld, lld> P[2];
            lld cnt = 0;
            for(lld i = 1; i <= 8; i += 1){
                  for(lld j = 1; j <= 8; j += 1){
                        if (dda[i][j] == 'K'){
                              P[cnt] = {i,j};
                              cnt++;
                        }
                  }
            }
            queue <pair <lld, lld> > q1, q2;
            q1.push(P[0]);
            vis1[P[0]]= 0;
            while(!q1.empty()){
                  pair <lld, lld> p = q1.front();
                  q1.pop();
                  if (p.first+2 >= 1 && p.first+2 <= 8 && p.second+2 >= 1 && p.second+2 <= 8 && !vis1.count({p.first+2,p.second+2}))
                        {q1.push({p.first+2,p.second+2}); vis1[{p.first+2,p.second+2}] = vis1[p]+1;}
                  if (p.first-2 >= 1 && p.first-2 <= 8 && p.second+2 >= 1 && p.second+2 <= 8 && !vis1.count({p.first-2,p.second+2}))
                        {q1.push({p.first-2,p.second+2}); vis1[{p.first-2,p.second+2}] = vis1[p]+1;}
                  if (p.first+2 >= 1 && p.first+2 <= 8 && p.second-2 >= 1 && p.second-2 <= 8 && !vis1.count({p.first+2,p.second-2}))
                        {q1.push({p.first+2,p.second-2}); vis1[{p.first+2,p.second-2}] = vis1[p]+1;}
                  if (p.first-2 >= 1 && p.first-2 <= 8 && p.second-2 >= 1 && p.second-2 <= 8 && !vis1.count({p.first-2,p.second-2}))
                        {q1.push({p.first-2,p.second-2}); vis1[{p.first-2,p.second-2}] = vis1[p]+1;}
            }
            if (vis1.count(P[1]) && vis1[P[1]]%2 == 0)
                  cout << "YES\n";
            else
                  cout <<  "NO\n";
      }
      return 0;
}