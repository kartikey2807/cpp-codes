// マップやその他の非常に複雑なタプルは使用しないでください。そして、文字列
// で遊ぶとき、それを整数配列に変換します。それは不思議です。パニックになら
// ないでください。それに慣れているときは常に競争をしてください。評価が下がっ
// たときに強調しないでください、それは起こります。だから、冷静ですが重要なコード:)
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
      lld cnt = 0;
      for(lld i = 0; i < s.size(); i += 1)
      	if (s[i] == '?')
      		cnt++;
      map <char, lld> cnt_t, cnt_s;
      for(lld i = 0; i < s.size(); i += 1)
      	cnt_s[s[i]]++;
      for(lld i = 0; i < t.size(); i += 1)
      	cnt_t[t[i]]++;
      map <char, lld> put;
      while(cnt){
      	lld min = MAX;
      	char chr;
      	for(char a = 'a'; a <= 'z'; a += 1){
      		if (cnt_t[a] > 0){
      			if ((cnt_s[a]/cnt_t[a])< min){
      				min = cnt_s[a]/cnt_t[a];
      				chr = a;
      			}
      		}
      	}
      	cnt_s[chr]++;
      	put[chr]++;
      	cnt--;
      }
      for(lld i = 0; i < s.size(); i += 1){
      	if (s[i] == '?'){
      		for(char a = 'a'; a <= 'z'; a += 1){
      			if (put[a] > 0){
      				s[i] = a;
      				put[a]--;
      				break;
      			}
      		}
      	}
      }
      cout << s;
      return 0;
}