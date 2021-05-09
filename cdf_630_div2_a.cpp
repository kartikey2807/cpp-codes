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
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main (){
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",   stdin);
    freopen("outputf.in", "w",  stdout);
    #endif
    FastIO
    lld T;
    cin >> T;
    while (T!=0){
    	lld a, b;
    	lld c, d;
    	lld x, y;
    	lld X[2];
    	lld Y[2];
    	cin >> a;
    	cin >> b;
    	cin >> c;
    	cin >> d;
    	cin >> x;
    	cin >> y;
    	lld i, f;
    	foi(i,2){
    		cin >> X[i];
    		cin >> Y[i];
    	}
        f = 1;
        if (a!=0||b!=0){
            if (a == b){
                if ((x+1 < X[0] || x+1 > X[1]) && (x-1 < X[0] || x-1 > X[1]))
                        f = 0;
            }
            else{
                if (a > b)
                    if (x-(a-b) < X[0] || x-(a-b) > X[1])
                        f = 0;
                if (b > a)
                    if (x+(b-a) < X[0] || x+(b-a) > X[1])
                        f = 0;
            }
        }
        if (c!=0||d!=0){
            if (c == d){
                if ((y+1 < Y[0] || y+1 > Y[1]) && (y-1 < Y[0] || y-1 > Y[1]))
                        f = 0;
            }
            else{
                if (c > d)
                    if (y-(c-d) < Y[0] || y-(c-d) > Y[1])
                        f = 0;
                if (d > c)
                    if (y+(d-c) < Y[0] || y+(d-c) > Y[1])
                        f = 0;
            }
        }
        if (f == 1)
            cout << "Yes\n";
        else
            cout <<  "No\n";
    	T-=1;
    }
    return 0;
}