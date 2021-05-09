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
string s;
string t;
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n >> s >> t;
      lld c = 0;
      for(lld i = 0; i < n; i += 1){
      	if (s[i] != t[i])
      		c++;
      }
      if (c == 0){cout << "0\n" << "-1 -1"; return 0;}
      if (c == 1){cout << "1\n" << "-1 -1"; return 0;}
      map <pair<char,char>,lld> cnt;
      for(lld i = 0; i < n; i += 1){
      	if (s[i] != t[i])
      		{cnt[{s[i],t[i]}] = i+1;}
      }
      for(lld i = 0; i < n; i += 1){
      	if (s[i] != t[i]){
      		if (cnt[{t[i],s[i]}] != 0)
      			{cout << c-2 << "\n" << cnt[{s[i],t[i]}] << " " << cnt[{t[i],s[i]}]; return 0;}
      	}
      }
      for(lld i = 0; i < n; i += 1){
      	if (s[i] != t[i]){
      		for(char a = 'a'; a <= 'z'; a++){
      			if (t[i] != a && cnt[{t[i],a}] != 0)
      				{cout << c-1 << "\n" << cnt[{s[i],t[i]}] << " " << cnt[{t[i],a}]; return 0;}
      		}
      	}
      }
      for(lld i = 0; i < n; i += 1){
      	if (s[i] != t[i]){
      		for(char a = 'a'; a <= 'z'; a++){
      			if (s[i] != a && cnt[{a,s[i]}] != 0)
      				{cout << c-1 << "\n" << cnt[{s[i],t[i]}] << " " << cnt[{a,s[i]}]; return 0;}
      		}
      	}
      }
      vector <lld> v;
      for(lld i = 0; i < n; i += 1){
      	if (s[i] != t[i])
      		v.push_back(i);
      }
      cout << c << " " << v[0]+1 << " " << v[1]+1;
      return 0;
}