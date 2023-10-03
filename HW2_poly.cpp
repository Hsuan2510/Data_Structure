#include<bits/stdc++.h> 

using namespace std;

typedef struct Poly{
	int coef;
	int expon;
};

int main(){
	int a,b,bNow=0,aNow=0,now=0;
	cin>>a;
	Poly *A=new Poly[a];
	for(int i=0;i<a;i++){
		cin>>A[i].coef;
		cin>>A[i].expon;
	}
	cin>>b;
	Poly *B=new Poly[b];
	for(int i=0;i<b;i++){
		cin>>B[i].coef;
		cin>>B[i].expon;
	}
	
	Poly *ans=new Poly[a+b];
	while(aNow<a && bNow<b){
		if(A[aNow].expon<B[bNow].expon){
			ans[now].expon=B[bNow].expon;
			ans[now].coef=B[bNow].coef;
			now++;
			bNow++; 
		}
		else if(A[aNow].expon==B[bNow].expon){
			ans[now].expon=B[bNow].expon;
			ans[now].coef=A[aNow].coef+B[bNow].coef;
			now++;
			bNow++;
			aNow++;
		}
		else if(A[aNow].expon>B[bNow].expon){
			ans[now].expon=A[aNow].expon;
			ans[now].coef=A[aNow].coef;
			now++;
			aNow++; 
		}
	}
	
	
	if(aNow<a){
		for(int i=aNow;i<a;i++){
			ans[now].expon=A[i].expon;
			ans[now].coef=A[i].coef;
			now++;
		}
	}
	else if(bNow<b){
		for(int i=bNow;i<b;i++){
			ans[now].expon=B[i].expon;
			ans[now].coef=B[i].coef;
			now++;
		}
	}
	
	for(int i=0;i<now;i++){
		if(ans[i].coef==0){
			continue;
		}
		else{
			if(i==now-1)
				cout<<ans[i].coef<<" "<<ans[i].expon;
			
			else
				cout<<ans[i].coef<<" "<<ans[i].expon<<" ";
		}
	}
	return 0;
}
