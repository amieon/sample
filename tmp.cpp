#include<iostream>
using namespace std;
const int maxn = 107;
int prime[maxn],tot,phi[maxn];
int main(){
    cout << "oh year~\n";
    for(int i=2;i<maxn;++i){
        if(!phi[i])
            prime[++tot] = i,phi[i] = i-1;
        for(int j=1;i*prime[j] < maxn && j<=tot;++j) {
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
                phi[i * prime[j]] = phi[i] * (prime[j]-1);
        }
    }
    for(int i = 1;i<=tot;++i)
        cout << prime[i] << ' ';
    cout << endl;
    for(int i = 1;i<maxn;++i)
        cout << phi[i] << ' ';
    cout << endl;
    return 0;
}