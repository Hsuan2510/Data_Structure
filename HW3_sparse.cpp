#include<bits/stdc++.h> 

using namespace std;

typedef struct term{  //�C�@�ӫD�s���� 
	int row;
	int column;
	int value;
};
void sumadd(term ans[],int *cnt,int r,int c,int *sum){
	if(*sum){
		ans[++*cnt].row=r;
		ans[*cnt].column=c;
		ans[*cnt].value=*sum;
		*sum=0;	
	}
}
int main(){
	//��JA,B�}���x�} 
	int Arow=0,Acol=0,Anum=0;
	int Brow=0,Bcol=0,Bnum=0; 
	cin>>Arow>>Acol;
	term *A=new term[Arow*Acol];
	A[0].row=Arow;		//A[0] �O���`�@row,column A[0].value �����X�ӫD�s�V 
	A[0].column=Acol;
	for(int i=0;i<Arow;i++){
		for(int j=0;j<Acol;j++){
			int x;
			cin>>x;
			if(x!=0){
				A[++Anum].row=i;
				A[Anum].column=j;
				A[Anum].value=x;
			}
		}
	}
	A[0].value=Anum;
	cin>>Brow>>Bcol;
	term *B=new term[Brow*Bcol];
	B[0].row=Brow;
	B[0].column=Bcol;
	for(int i=0;i<Brow;i++){
		for(int j=0;j<Bcol;j++){
			int y;
			cin>>y;
			if(y!=0){
				B[++Bnum].row=i;
				B[Bnum].column=j;
				B[Bnum].value=y; 
			}
		}
	}
	B[0].value=Bnum;
	
	//��m�x�} 
	term *Bt=new term[Brow*Bcol];
	int row_term[Bcol]={0};
	int start_pos[Bcol]={0};
	Bt[0].row=B[0].column;
	Bt[0].column=B[0].row;
	Bt[0].value=B[0].value; 
	if(B[0].value>0){
		for(int i=1;i<=B[0].value;i++)
			row_term[B[i].column]++;   //�]�n�C�C���X�ӫD0�� 
		start_pos[0]=1;	    //0���_�l��m=1 
		for(int i=1;i<B[0].column;i++){
			start_pos[i]=start_pos[i-1]+row_term[i-1]; 
		}
		for(int i=1;i<=B[0].value;i++){
			int position;
			position=start_pos[B[i].column];  //�n��b�ĴX�� 
			start_pos[B[i].column]++;
			Bt[position].row=B[i].column;
			Bt[position].column=B[i].row;
			Bt[position].value=B[i].value;
			
		}
	}
	
	
	//A*Bt
	int Col=0,Row=0,sum=0,cnt=0;
	Row=A[1].row;
	int begin=1;
	term *ans=new term[Arow*Bcol];
	for(int i=1;i<=A[0].value;){
		Col=Bt[1].row;
		for(int j=1;j<=B[0].value+1;){
			if(A[i].row!=Row){
				sumadd(ans,&cnt,Row,Col,&sum);
				i=begin;
				while(Bt[j].row==Col) j++; //��B�Χ������� 
				Col=Bt[j].row;  //col����U�@�� 
				
			}
			else if(Bt[j].row!=Col){
				sumadd(ans,&cnt,Row,Col,&sum);
				i=begin;
				Col=Bt[j].row;
			}
			else{
				if(A[i].column<Bt[j].column){
					i++;
					continue;
				}
				else if(A[i].column==Bt[j].column){
					sum+= A[i].value*Bt[j].value;
					i++;
					j++;
					continue; 
				}
				else if(A[i].column>Bt[j].column){
					j++;
				}
			}
		}
		while(A[i].row==Row)i++;  //��A�S�Χ������� 
		begin=i;
		Row=A[i].row;  //A����U�@��row 
	}
	ans[0].row=A[0].row;
	ans[0].column=B[0].column;
	ans[0].value=cnt; 
	
	//��X
	for(int i=0;i<=cnt;i++){
		cout<<ans[i].row<<" "<<ans[i].column<<" "<<ans[i].value<<endl;
	}

}
