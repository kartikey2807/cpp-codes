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
vector <lld> prefix_function(string s)
{
      lld n = s.size();
      vector <lld> pi(n);
      for(lld i = 1; i < n; i += 1){
            lld j = pi[i-1];
            while(j > 0 && s[i] != s[j])
                  j = pi[j-1];
            if (s[i] == s[j])
                  j++;
            pi[i] = j;
      }
      return pi;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      string s, t;
      cin >> s >> t;
      lld lens = s.size();
      lld lent = t.size();
      lld A[lens],B[lent];
      for(lld i = 0; i < lens; i += 1){
            A[i] = (lld)s[i]-48;
      }
      for(lld i = 0; i < lent; i += 1){
            B[i] = (lld)t[i]-48;
      }
      if (lent > lens)
            {cout << s;return 0;}

      vector <lld> orz = prefix_function(t);
      lld pos = lent-orz[lent-1];
      map <lld, lld> cnt_s, cnt_t;
      for(lld i = 0; i < lens; i += 1)
            cnt_s[A[i]]++;
      for(lld i = 0; i < lent; i += 1)
            cnt_t[B[i]]++;
      string ans = "";
      if (pos == lent){
            while(true){
                  if (cnt_s[0] < cnt_t[0] || cnt_s[1] < cnt_t[1])
                        break;
                  ans += t;
                  cnt_s[0] -= cnt_t[0];
                  cnt_s[1] -= cnt_t[1];
            }
            while(cnt_s[0]) {ans += '0'; cnt_s[0]--;}
            while(cnt_s[1]) {ans += '1'; cnt_s[1]--;}
            cout << ans;
      }
      else{
            if (cnt_s[0] < cnt_t[0] || cnt_s[1] < cnt_t[1]){
                  cout << s;
            }
            else{
                  ans += t;
                  cnt_s[0] -= cnt_t[0];
                  cnt_s[1] -= cnt_t[1];
                  string rem = "";
                  cnt_t[0] = cnt_t[1] = 0;
                  for(lld i = lent-pos; i < lent; i += 1){
                        rem += t[i];
                        cnt_t[B[i]]++;
                  }
                  while(true){
                        if (cnt_s[0] < cnt_t[0] || cnt_s[1] < cnt_t[1])
                              break;
                        ans += rem;
                        cnt_s[0] -= cnt_t[0];
                        cnt_s[1] -= cnt_t[1];
                  }
                  while(cnt_s[0]) {ans += '0'; cnt_s[0]--;}
                  while(cnt_s[1]) {ans += '1'; cnt_s[1]--;}
                  cout << ans;
            }
      }
      return 0;
}