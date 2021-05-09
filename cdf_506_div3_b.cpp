#include <bits/stdc++.h>
#include <set>
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
void merge(lld crr[], lld brr[], lld arr[], lld l, lld m, lld r){
    lld i , j ,  k;
    lld n1 = m-l+1; 
    lld n2 = r - m;
    lld L1[n1],L2[n1],L3[n1];
    lld R1[n2],R2[n2],R3[n2];
    for (i = 0; i < n1; i++){
        L1[i] = arr[l + i];
        L2[i] = brr[l + i];
        L3[i] = crr[l + i];
    }
    for (j = 0; j < n2; j++){
        R1[j] = arr[m+1+j];
        R2[j] = brr[m+1+j];
        R3[j] = crr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L1[i] <= R1[j]){
            arr[k] = L1[i];
            brr[k] = L2[i];
            crr[k] = L3[i];
            i++;
        }
        else{
            arr[k] = R1[j];
            brr[k] = R2[j];
            crr[k] = R3[j];
            j++;
        }
        k++;
    }
        while (i   <   n1){
            arr[k] = L1[i];
            brr[k] = L2[i];
            crr[k] = L3[i];
            i++;
            k++;
        }
        while (j   <   n2){
            arr[k] = R1[j];
            brr[k] = R2[j];
            crr[k] = R3[j];
            j++;
            k++;
        }
}
void mergeSort(lld crr[], lld brr[], lld arr[], lld l, lld r){
    if (l < r)
    {
        lld m = l+(r-l)/2;
        mergeSort(crr, brr, arr,l , m);
        mergeSort(crr, brr,arr,m+1 ,r);
        merge(crr, brr, arr, l, m , r);
    } 
}
lld n;
lld bank (lld A[],lld V[],lld k,lld p){
    if (k  >=  n){
        return 0;
    }
    if (V[k]==-1){
        if (p == -1){
            V[k] = bank(A,V,k+1,k) + 1;
        }
        else{
            if (A[k] <=  (2 * A[p+0])){
                V[k] = bank(A,V,k+1,k);
                V[k]+= 1;
            }
            else{
                return 0;
            }
        }
    }
    return (V[k]);
}
int main () {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("inputf.in",  "r",  stdin);
    // for writing output to output.txt
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld i;
    cin >> n;
    lld A[n];
    lld V[n];
    for(i = 0; i < n; i += 1){
        cin >> A[i];
        V[i]  =  -1;
    }
    lld c = 0;
    lld m = 0;
    for(i = 0; i < n; i += 1){
        c = bank(A, V, i, -1);
    }
    for(i = 0; i < n; i += 1){
        if (V[i] > m){
            m = V[i];
        }
    }
    cout << m <<"\n";
    return 0;
}