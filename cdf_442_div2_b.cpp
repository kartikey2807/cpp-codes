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
      cin >> s;
      lld n = s.length();
      lld c = 0;
      vector <char> ab;
      vector <lld> cnt;
      for(lld i = 1; i < n; i += 1){
      	if (s[i] == s[i-1]){
      		c++;
      	}
      	else{
      		c++;
      		ab.push_back(s[i-1]);
      		cnt.push_back(c);
      		c=0;
      	}
      }
      c++;
      ab.push_back(s[n-1]);
      cnt.push_back(c);
      lld len = cnt.size();
      lld b_back[len];
      lld b_forw[len];
      lld b = 0;
      for(lld i = 0; i < len; i += 1){
      	if (ab[i] == 'b')
      		b+=cnt[i];
      	b_forw[i] = b;
      }
      b = 0;
      for(lld i = len-1; i>=0;i -= 1){
      	if (ab[i] == 'b')
      		b+=cnt[i];
      	b_back[i] = b; 
      }
      set <lld> vis;
      for(lld i = 0; i < len; i += 1){
      	if (ab[i]  ==  'b'){
      		lld minus = 0;
      		lld ans1 = MAX;
      		ans1 = min(ans1,b_back[i]-cnt[i]);
      		for(lld j = i+1; j < len; j += 1){
      			if (ab[j] == 'a')
      				minus += cnt[j];
      			else
      				ans1 = min(ans1, minus+b_back[j]-cnt[j]);
      		}
      		minus = 0;
      		lld ans2 = MAX;
      		ans2 = min(ans2, b_forw[i]-cnt[i]);
      		for(lld j = i - 1; j >= 0; j -= 1){
      			if (ab[j] == 'a')
      				minus += cnt[j];
      			else
      				ans2 = min(ans2, minus+b_forw[j]-cnt[j]);
      		}
      		vis.insert(ans1+ans2);
      	}
      }
      if (vis.empty()) cout << n << "\n";
      else{
      	set <lld> :: iterator itr = vis.begin();
      	cout << (n-(*itr));
      }
      return 0;
}