#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	for(int i=n;i>=0;i--){//注意，循环要从大到小
		int x;
		cin>>x;
		if(x){
			if(i!=n&&x>0)
				cout<<'+';
			if(i!=0&&x==-1)
				cout<<'-';
			if(abs(x)>1||i==0)
				cout<<x;
			if(i>1)
				cout<<"x^"<<i;
			if(i==1)
				cout<<'x';
		}
	}
	return 0;
}