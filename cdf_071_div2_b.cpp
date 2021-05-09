#include <bits/stdc++.h>
#include <set>
#include <map>
#include <string>
using namespace std;
typedef long long int lld;
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
double getComb (double n, double x){
    if (x > n){
        return 0;
    }
    else{
        double r = 1.0;
        for(double i = 1.0; i<=x; i += 1){
            double a = n-i+1;
            double b = a / i;
            r*=b;
        }
        return r;
    }
}
void merge(lld brr[], lld arr[], lld l, lld m, lld r){
    lld i , j ,  k;
    lld n1 = m-l+1; 
    lld n2 = r - m;
    lld L1[n1],L2[n1];
    lld R1[n2],R2[n2];
    for (i = 0; i < n1; i++){
        L1[i] = arr[l + i];
        L2[i] = brr[l + i];
    }
    for (j = 0; j < n2; j++){
        R1[j] = arr[m+1+j];
        R2[j] = brr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L1[i] <= R1[j]){
            arr[k] = L1[i];
            brr[k] = L2[i];
            i++;
        }
        else{
            arr[k] = R1[j];
            brr[k] = R2[j];
            j++;
        }
        k++;
    }
        while (i   <   n1){
            arr[k] = L1[i];
            brr[k] = L2[i];
            i++;
            k++;
        }
        while (j   <   n2){
            arr[k] = R1[j];
            brr[k] = R2[j];
            j++;
            k++;
        }
}
void mergeSort(lld brr[], lld arr[], lld l, lld r){
    if (l < r)
    {
        lld m = l+(r-l)/2;
        mergeSort(brr, arr,l, m);
        mergeSort(brr,arr,m+1,r);
        merge(brr, arr, l, m, r);
    } 
} 
int main () {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("inputf.in",  "r",  stdin);
    // for writing output to output.txt
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld n, m;
    lld k, t;
    cin >> n;
    cin >> m;
    cin >> k;
    cin >> t;
    lld i, j;
    lld A[k];
    lld B[k];
    lld c, f;
    lld x, y;
    for(i = 0; i<k; i+=1){
        cin >>A[i];
        cin >>B[i];
    }
    mergeSort(A,B, 0,k-1);
    mergeSort(B,A, 0,k-1);
    lld carr, kiwi, grap ;
    for(i = 0; i<t; i+=1){
        cin >> x;
        cin >> y;
        c = 0;
        f = 1;
        carr = 0;
        kiwi = 1;
        grap = 2;
        for(j = 0; j<k; j+=1){
            if (x == A[j] && y == B[j]){
                f = 0;
                cout << "Waste" << "\n";
                break;
            }
        }
        if (f == 1){
            for(j = 0; j<k; j+=1){
                if ((x > A[j]) || (x ==A[j] && y>B[j])){
                    c++;
                }
            }
            carr = (carr+c)%3;
            kiwi = (kiwi+c)%3;
            grap = (grap+c)%3;
            if ((((x - 1) * m) + (y - 1)) % 3 == carr){
                cout << "Carrots"<<"\n";
            }
            if ((((x - 1) * m) + (y - 1)) % 3 == kiwi){
                cout << "Kiwis" << "\n";
            }
            if ((((x - 1) * m) + (y - 1)) % 3 == grap){
                cout << "Grapes"<< "\n";
            }
        }
    }
    return 0;
}