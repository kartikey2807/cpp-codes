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
void make (string s[], lld let[], lld num[], lld sym[], lld n, lld m)
{
	for(lld i = 0; i < n; i += 1){
		// letter
		lld p = -1;
		for(lld j = 0; j < m; j += 1){
			if (s[i][j] >= 'a' && s[i][j] <= 'z'){
				p = j;
				break;
			}
		}
		lld q = -1;
		for(lld j = m-1; j >= 0; j -= 1){
			if (s[i][j] >= 'a' && s[i][j] <= 'z'){
				q = m-j;
				break;
			}
		}
		if (p != -1 && q != -1){
			let[i] = min(p,q);
		}
		else{
			if (p == -1 && q == -1){
				let[i] = -1;
			}
			else{
				if (p == -1)
					let[i] = q;
				else
					let[i] = p;
			}
		}
		// number
		p = -1;
		for(lld j = 0; j < m; j += 1){
			if (s[i][j] >= '0' && s[i][j] <= '9'){
				p = j;
				break;
			}
		}
		q = -1;
		for(lld j = m-1; j >= 0; j -= 1){
			if (s[i][j] >= '0' && s[i][j] <= '9'){
				q = m-j;
				break;
			}
		}
		if (p != -1 && q != -1){
			num[i] = min(p,q);
		}
		else{
			if (p == -1 && q == -1){
				num[i] = -1;
			}
			else{
				if (p == -1)
					num[i] = q;
				else
					num[i] = p;
			}
		}
		// symbol
		p = -1;
		for(lld j = 0; j < m; j += 1){
			if (s[i][j] == '#' || s[i][j] == '&' || s[i][j] == '*'){
				p = j;
				break;
			}
		}
		q = -1;
		for(lld j = m-1; j >= 0; j -= 1){
			if (s[i][j] == '#' || s[i][j] == '&' || s[i][j] == '*'){
				q = m-j;
				break;
			}
		}
		if (p != -1 && q != -1){
			sym[i] = min(p,q);
		}
		else{
			if (p == -1 && q == -1){
				sym[i] = -1;
			}
			else{
				if (p == -1)
					sym[i] = q;
				else
					sym[i] = p;
			}
		}
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      string s[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> s[i];
      }
      lld let[n];
      lld num[n];
      lld sym[n];
      make(s,let,num,sym,n,m);
      lld ans = MAX;
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < n; j += 1){
      		if (j == i)
      			continue;
      		for(lld k = 0; k < n; k += 1){
      			if (k == i || k == j)
      				continue;
      			if (let[i] != -1 && num[j] != -1 && sym[k] != -1)
      				ans = min(ans,let[i]+num[j]+sym[k]);
      		}
      	}
      }
      cout << ans;
      return 0;
}