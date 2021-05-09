// 背が高く、誇りを持ってください。どんなに弱くても価値がないと感じても、心を燃やし続け、
// 歯を食いしばって前進します。ボールに丸まって隠れれば、時は過ぎ去ります。あなたが悲し
// みに浸っている間、それはあなたのために止まりません。世界が平和になるためには、すべて
// の悪魔を破壊しなければなりません。柱としての義務を果たしてください。そうすれば、来世
// でもきっとあなたは偉大になるでしょう。 -炎の柱、両十郎連国。
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    string s;
    cin >> s;
    lld n[3], p[3], c[3];
    for(lld i = 0; i < 3; i += 1){
    	cin >> n[i];
    }
    for(lld i = 0; i < 3; i += 1){
    	cin >> p[i];
    	c[i]  = 0;
    }
    lld r;
    cin >> r;
    for(lld i = 0; i < s.size(); i += 1){
    	if (s[i] == 'B')
    		c[0]++;
    	if (s[i] == 'S')
    		c[1]++;
    	if (s[i] == 'C')
    		c[2]++;
    }
    lld sum = MAX;
    for(lld i = 0; i < 3; i += 1){
    	if (c[i] > 0)
    		sum = min(sum, n[i]/c[i]);
    }
    for(lld i = 0; i < 3; i += 1){
    	n[i] -= sum*c[i];
    }
    while(true){
    	lld f = 0;
    	for(lld i = 0; i < 3; i += 1){
    		if (c[i] > 0){
    			if (n[i] > 0)
    				f = 1;
    		}
    	}
    	if (f == 0)
    		break;
    	lld g = 1;
    	for(lld i = 0; i < 3; i += 1){
    		if (c[i] > 0){
    			if (n[i] < c[i]){
    				if (p[i]*(c[i]-n[i]) <= r){
    					r -= p[i]*(c[i]-n[i]);
    					n[i] = c[i];
    				}
    				else{
    					g = 0;
    					break;
    				}
    			}
    		}
    	}
    	if (g == 0)
    		break;
    	for(lld i = 0; i < 3; i += 1){
    		if (c[i] > 0)
    			n[i] -= c[i];
    	}
    	sum++;
    }
    lld temp = 0;
    for(lld i = 0; i < 3; i += 1){
    	if (c[i] > 0)
    		temp += c[i]*p[i];
    }
    sum += r/temp;
    cout << sum;
    return 0;
}