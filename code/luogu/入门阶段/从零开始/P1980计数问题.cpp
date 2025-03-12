#include<iostream>
using namespace std;
int n,x,ans=0;
int count_(int a){
	int sum=0;
	while(a!=0){
		if(a%10==x){
			sum++;
		}
		a=a/10;
	}
	return sum;
}
int main(){
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		ans+=count_(i);
	}
	cout<<ans<<endl;
	return 0;
}