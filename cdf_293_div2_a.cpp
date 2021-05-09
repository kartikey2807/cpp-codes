// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. Double cannot be used
// for comparisons use div and mod instead. 
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
#define auth set <lld> :: iterator
#define pb push_back
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      string s;
      string t;
      cin >> s >> t;
      lld pos;
      for(lld i = 0; i < s.size(); i += 1){
            if (s[i] < t[i]){
                  pos=i;
                  break;
            }
      }
      vector <char> ans(s.size());
      vector <char> bns(s.size());
      lld a = (lld)s[pos];
      lld b = (lld)t[pos];
      if (b-a >= 2){
            ans[pos] = (char)(a+1);
            for(lld i = 0; i < s.size(); i += 1){
                  if (i == pos)
                        continue;
                  ans[i] = s[i];
            }
            for(lld i = 0; i<ans.size(); i += 1){
                  cout << ans[i];
            }
      }
      else{
            ans[pos] = (char)a;
            bns[pos] = (char)b;
            for(lld i = 0; i < s.size(); i += 1){
                  if (i < pos){
                        ans[i] = s[i];
                        bns[i] = s[i];
                  }
                  if (i > pos){
                        ans[i] = 'z';
                        bns[i] = 'a';
                  }
            }
            lld f = 0;
            for(lld i = 0; i < s.size(); i += 1){
                  if (ans[i] > s[i]){
                        f = 1;
                        break;
                  }
            }
            if (f == 1){
                  for(lld i = 0; i < s.size(); i += 1){
                        cout << ans[i];
                  }
            }
            else{
                  lld g = 0;
                  for(lld i = 0; i < s.size(); i += 1){
                        if (bns[i] < t[i]){
                              g = 1;
                              break;
                        }
                  }
                  if (g == 1){
                        for(lld i = 0; i < s.size(); i += 1){
                              cout << bns[i];
                        }
                  }
                  else{
                        cout << "No such string";
                  }
            }
      }
      return 0;
}