#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

//两种选其一
const int MAXN=35000;
//const int MAXN=sqrt(1e9)+1;

bool isPrime[MAXN];
vector<int> prime;

void init() {
    fill_n(isPrime,MAXN,true);
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2; i<MAXN; i++) {
        if(!isPrime[i])continue;
        prime.push_back(i);
        for(int j=i*i; j<MAXN; j+=i) {
            //质数的倍数为非质数
            isPrime[j]=false;
        }
    }
    return ;
}

int main() {
    init();
    int num;
    while(scanf("%d",&num)!=EOF) {
        int answer=0;
        for(int i=0; i<prime.size()&&prime[i]<num; i++) {
            int factor=prime[i];
            while(num%factor==0) {
                num/=factor;
                answer++;
            }
        }
        if(num>1) {
            answer++;
        }
        cout<<answer<<endl;
    }
    return 0;
}
