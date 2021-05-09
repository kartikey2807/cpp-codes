#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld t;
    cin >> t;
    while(t--)
    {
    	lld n, k;
    	cin >> n >> k;
    	lld A[n];
    	for(lld i = 0; i < n; i += 1)
    		cin >> A[i];
    	lld pos;
    	for(lld i = 0; i < k; i += 1)
    	{
    		pos =  -1;
    		for(lld j = 0; j < n-1; )
    		{
    			if (A[j] < A[j+1])
    			{
    				pos=j;
    				break;
    			}
    			else
    				j+= 1;
    		}
    		if (pos == -1)
    			break;
    		A[pos] ++;
    	}
    	if (pos == -1)
    		cout << pos << "\n";
    	else
    		cout <<pos+1<< "\n";
    }
    return 0;
}