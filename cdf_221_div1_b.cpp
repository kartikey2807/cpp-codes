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
#define LEN 6000
lld arr[LEN][LEN];
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld n, m;
    cin >> n >> m;
    lld dda[n][m];
    for(lld i = 0; i < n; i += 1){
    	for(lld j = 0; j < m; j += 1){
    		char temp;
    		cin >> temp;
    		dda[i][j] = (lld)temp-48;
    	}
    }
    lld cnt = 0;
    for(lld i = 0; i < n; i += 1){
    	for(lld j = 0; j < m; j += 1){
    		if (dda[i][j] == 1)
    			cnt++;
    	}
    }
    if (cnt){
    	for(lld i = 0; i < n; i += 1){
    		lld start = 0;
    		for(lld end = 0; end < m; end += 1){
    			if (dda[i][end]  == 1)
    				arr[end][start]++;
    			else
    				start = end+1;
    		}
    	}
    	lld ans = MIN;
    	for(lld end = 0; end < m; end += 1){
    		lld sum = 0;
    		for(lld start = 0; start <= end; start += 1){
    			sum+= arr[end][start];
    			ans = max(ans,(end-start+1)*sum);
    		}
    	}
    	cout << ans;
    }
    else{
    	cout << cnt;
    }
    return 0;
}