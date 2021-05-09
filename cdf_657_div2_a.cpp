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
bool compare (char c[], lld l)
{
	if (c[l] == 'a' && c[l+2] == 'a' && c[l+4] == 'a' && c[l+6] == 'a' && c[l+1] == 'b' && c[l+5] == 'b' && c[l+3] == 'c')
		return true;
	return false;
}
lld check (char c[], lld n)
{
	lld cnt = 0;
	for(lld i = 0; i < n-7+1; i += 1){
		if (compare(c,i))
			cnt++;
	}
	return cnt;
}
bool comp (char c[], lld p, lld n)
{
	char x[n];
	for(lld i = 0; i < n; i += 1){
		x[i] = c[i];
	}
	for(lld i = p; i<p+7; i += 1){
		if (x[i]  == '?'){
			switch(i-p){
				case 0:
				case 2:
				case 4:
				case 6: x[i] = 'a'; break;
				case 1:
				case 5: x[i] = 'b'; break;
				case 3: x[i] = 'c'; break;
			}
		}
	}
	lld cnt = 0;
	for(lld i = 0; i < n-7+1; i += 1){
		if (compare(x,i))
			cnt++;
	}
	if (cnt == 1) return true;
	else return false;
}
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
      	lld n;
      	cin >> n;
      	char c[n];
      	for(lld i = 0; i < n; i += 1)
      		cin >> c[i];
      	lld x = check(c,n);
      	if (x == 0){
      		lld f = -1;
      		for(lld i = 0; i < n-7+1; i += 1){
      			if (comp(c,i,n)){
      				f = i;
      				break;
      			}
      		}
      		if (f != -1){
      			cout << "Yes\n";
      			for(lld i = f; i < f+7; i += 1){
      				if (c[i]  == '?'){
      					switch(i-f){
      						case 0:
      						case 2:
      						case 4:
      						case 6: c[i] = 'a'; break;
      						case 1:
      						case 5: c[i] = 'b'; break;
      						case 3: c[i] = 'c'; break;
      					}
      				}
      			}
      			for(lld i = 0; i < n; i += 1)
      				if (c[i] == '?')
      					c[i]= 'x';
      			for(lld i = 0; i < n; i += 1)
      				cout << c[i];
      			cout << "\n";
      		}
      		else cout << "No\n";
      	}
      	else{
      		if (x == 1){
      			cout << "Yes\n";
      			for(lld i = 0; i < n; i += 1)
      				if (c[i] == '?')
      					c[i]= 'x';
      			for(lld i = 0; i < n; i += 1)
      				cout << c[i];
      			cout << "\n";
      		}
      		else cout << "No\n";
      	}
      }
      return 0;
}