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
      lld n, k, a, b;
      cin >> n >> k >> a >> b;
      if (b >= a){
      	vector <char> ord;
      	while(a != 0  && b != 0){
      		ord.push_back('B');
      		ord.push_back('G');
      		a--; b--;
      	}
      	if (b == 0) {foi(i,ord.size()) cout << ord[i]; return 0;}
      	else{
      		ord.push_back('B');
      		b--;
      		map <lld, lld> cnt;
      		for(lld i = 0; i < ord.size(); i += 2){
      			cnt[i] = 1;
      		}
      		lld x = 0;
      		lld len = ord.size();
      		while(b != 0 && x < len){
      			if (cnt[x] < k){
      				cnt[x]++;
      				b -= 1;
      			}
      			else
      				x += 2;
      		}
      		if (b == 0){
      			for(lld i = 0; i < ord.size(); i += 1){
      				if (i%2 == 0){
      					while(cnt[i]){
      						cout << "B";
      						cnt[i] -= 1;
      					}
      				}
      				else
      					cout << "G";
      			}
      		}
      		else
      			cout << "NO";
      	}
      }
      else{
      	vector <char> ord;
      	while(a != 0  && b != 0){
      		ord.push_back('G');
      		ord.push_back('B');
      		a--; b--;
      	}
      	if (a == 0) {foi(i,ord.size()) cout << ord[i]; return 0;}
      	else{
      		ord.push_back('G');
      		a--;
      		map <lld, lld> cnt;
      		for(lld i = 0; i < ord.size(); i += 2){
      			cnt[i] = 1;
      		}
      		lld x = 0;
      		lld len = ord.size();
      		while(a != 0 && x < len){
      			if (cnt[x] < k){
      				cnt[x]++;
      				a -= 1;
      			}
      			else
      				x += 2;
      		}
      		if (a == 0){
      			for(lld i = 0; i < ord.size(); i += 1){
      				if (i%2 == 0){
      					while(cnt[i]){
      						cout << "G";
      						cnt[i] -= 1;
      					}
      				}
      				else
      					cout << "B";
      			}
      		}
      		else
      			cout << "NO";
      	}
      }
      return 0;
}