#include<iostream>
using namespace std;
const int maxn = 107;
const int mod = 114514;
int prime[maxn],tot,phi[maxn],sumphi[maxn];
int inv[maxn];
int exgcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
int main(){
    cout << "oh year~\n";
    cout << "oh year~\n";
    cout << "oh ydr~\n";
    cout << "oh year~\n";
    cout << "oh year~\n";
    for(int i=2;i<maxn;++i){
        if(!phi[i])
            prime[++tot] = i,phi[i] = i-1;
        sumphi[i] = (sumphi[i-1] + prime[i])%mod;
        for(int j=1;i*prime[j] < maxn && j<=tot;++j) {
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
                phi[i * prime[j]] = phi[i] * (prime[j]-1);
        }
    }
    inv[1] = 1;
    for(int i=2;i<maxn;++i)
        inv[i] = mod - inv[i%mod] * (mod / i) % mod;
    for(int i = 1;i<=tot;++i)
        cout << prime[i] << ' ';
    cout << endl;
    for(int i = 1;i<maxn;++i)
        cout << phi[i] << ' ';
    cout << endl;
    for(int i = 1;i<maxn;++i)
        cout << sumphi[i] << ' ';
    cout << endl;
    for(int i = 1;i<maxn;++i)
        cout << inv[i] << ' ';
    cout << endl;
    return 0;
}