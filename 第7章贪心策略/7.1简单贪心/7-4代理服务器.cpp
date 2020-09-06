#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

string agency[1001];
string server[5001];

// 贪心策略：每次选择能访问最远的ip地址进行访问，再从断点开始换下一个能访问最远的ip

int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>agency[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>server[i];
	}
	
	//判断输出-1的情况，仅可能是只有一个ip并且该ip在server列表中
	if (n==1){
		int feasible = 1;
		for (int i=0; i<m; i++){
			if (agency[0] == server[i])
				feasible = 0;
		}
		//遍历全部server，看唯一的ip是否在其中，若是则不feasible
		if (feasible)
			cout << 1 << endl;
		else cout << -1 << endl;
		
	}else{
		int count = 0;
		int begin = 0, max = 0;
		int i=0,j=0;
		while(begin != m){
			for(i=0;i<n;i++){
				for(j=begin;j<m;j++){
					if(agency[i] == server[j])
						break;
				}
				//该循环结束后，如果j==m,则说明走通，否则表明最远可走到server[j]
				if (j>max)
					max = j;
			}
			
			// 找到并记录所有ip中最远能走到的server，下次从这里开始搜索
			begin = max;
			// 无论如何count都会大于等于1，所以最后输出时要-1
			count++;
		}
		cout<<count-1<<endl;
	}
	return 0;
}