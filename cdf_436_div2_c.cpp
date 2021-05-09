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
      lld a, b, f, k;
      cin >> a >> b >> f >> k;
      lld tank = b;
      lld dist = 0;
      lld count= 0;
      while (true){
      	dist += tank/a;
      	lld r = tank%a;
      	if (dist >= k)
      		break;
      	if (dist%2 == 0){
      		if (r>= f){
      			tank = b;
      			count++;
      			if (tank >= (a-f)){
      				tank-=(a-f);
      				dist++;
      			}
      			else{cout << "-1"; return 0;}
      		}
      		else{
      			if (dist == 0)
      				{cout << "-1"; return 0;}
      			else{
      				tank = b;
      				count++;
      				if (tank >= f){
      					tank-=f;
      					if (tank < f)
      						{cout << "-1"; return 0;}
      				}
      				else{cout << "-1"; return 0;}
      			}
      		}
      	}
      	else{
      		if (r >= (a-f)){
      			tank = b;
      			count++;
      			if (tank >= f){
      				tank-=f;
      				dist++;
      			}
      			else{cout << "-1"; return 0;}
      		}
      		else{
      			tank = b;
      			count++;
      			if (tank >= (a-f)){
      				tank-=(a-f);
      				if (tank < (a-f))
      					{cout << "-1"; return 0;}
      			}
      			else{cout << "-1"; return 0;}
      		}
      	}
      	if (dist >= k)
      		break;
      }
      cout << count;
      return 0;
}