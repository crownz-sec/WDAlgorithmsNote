#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
<<<<<<< HEAD

=======
>>>>>>> parent of 6dd9bdd... æ›´æ–°6-2ï¼Œ6-3
using namespace std;
/**Ê®½øÖÆÓë¶ş½øÖÆ 
*Ë¼Â·£ºÊ®½øÖÆ×ª¶ş½øÖÆ£¬¶ş½øÖÆÄæĞò£¬¶ş½øÖÆ×ªÊ®½øÖÆ£¨³ËÒ»¸ö²»Í¬µÄ10Ö¸ÊıºóÏà¼Ó£© 
*×¢Òâ£º´ËÌâÊı¾İÈÔ½Ï´ó£¬1000Î»ÒÔÄÚ 
*/

string divide2(const string &s){
	//Ä£ÄâÊÖ¶¯³ıÒÔ2
	const int n=s.size();
	string res(n,'0');
	int bias=0;
	for(int i=0;i<n;++i){
		res[i]=(s[i]-'0'+10*bias)/2+'0';
		bias=(s[i]-'0'+10*bias)%2;
	}
	int index=0;
	while(res[index]=='0')++index;
	return res.substr(index);
}

string multiple(string str,const int& x,int carry){
	carry=0;//´æ´¢½øÎ»
	for(int i=str.size()-1;i>=0;--i){
		int curr=x*(str[i]-'0')+carry;
		str[i]=curr%10+'0';
		carry = curr/10;
	} 
	if(carry!=0)str=(char)('0'+carry)+str;
	return str;
}

string add(string str,int x){
	return multiple(str,1,x);
}


int main(){
	vector<int> v;
	string A;
	int last;
	while(cin>>A){
		while(A.size()!=0){
			last = A[A.size()-1]-'0';
			v.push_back(last%2);
			A = divide2(A);	
		}
		string ans = "0";
		for(int i=0;i<v.size();++i){
			ans = multiple(ans,2,0);
			ans = add(ans,v[i]);
			cout<<ans<<endl;
		} 
		cout<<ans<<endl;
		
	}
	//vµÄÕıĞò¼´Ô­Êı¶ş½øÖÆÄæĞò

	return 0;
}

