//
// Created by Work on 2022/4/26.
//
#include<bits/stdc++.h>
using namespace std;
string run(int x,int i=0,string s=string("")){
	if(x==0)return string("0");
	do if(x&1)s=(i==1?"2":"2("+run(i)+")")+(s==""?"":"+")+s;//拼接字符串，应题意，要把低次方接在后面
	while(++i,x>>=1);//每次向右移位
	return s;
}
int main(){
	int x;cin>>x;
	cout<<run(x)<<endl;
}