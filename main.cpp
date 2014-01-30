#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

typedef struct{
	int left;
	int straight;
	int right;
}struct_flow;


int main(int argc, char *argv[])
{
	int f1;
	int f2;
	int f3;
	int f4;
	int i;
	int j;
	
	struct_flow flow[6][4];
	struct_flow sub[4];
	char temp[2]="";
	char solusi[13]="";
	char temp2[4]="";
	int temp_hitung[4];
	int DS=0;
	int hitungDS=0;
	int den[4];
	
	
	flow[0][0].left = 1;
	flow[0][0].straight = 1;
	flow[0][0].right = 1;
	
	flow[0][1].left = 0;
	flow[0][1].straight = 0;
	flow[0][1].right = 0;
	
	flow[0][2].left = 0;
	flow[0][2].straight = 0;
	flow[0][2].right = 0;
	
	flow[0][3].left = 1;
	flow[0][3].straight = 0;
	flow[0][3].right = 0;
	
	//--------------------- 1
	
	flow[1][0].left = 1;
	flow[1][0].straight = 0;
	flow[1][0].right = 0;
	
	flow[1][1].left = 1;
	flow[1][1].straight = 1;
	flow[1][1].right = 1;

	flow[1][2].left = 0;
	flow[1][2].straight = 0;
	flow[1][2].right = 0;
	
	flow[1][3].left = 0;
	flow[1][3].straight = 0;
	flow[1][3].right = 0;
	
	//--------------------- 2
	
	flow[2][0].left = 0;
	flow[2][0].straight = 0;
	flow[2][0].right = 0;
	
	flow[2][1].left = 1;
	flow[2][1].straight = 0;
	flow[2][1].right = 0;
	
	flow[2][2].left = 1;
	flow[2][2].straight = 1;
	flow[2][2].right = 1;
	
	flow[2][3].left = 0;
	flow[2][3].straight = 0;
	flow[2][3].right = 0;
	
	//--------------------- 3
	
	flow[3][0].left = 0;
	flow[3][0].straight = 0;
	flow[3][0].right = 0;
	
	flow[3][1].left = 0;
	flow[3][1].straight = 0;
	flow[3][1].right = 0;
	
	flow[3][2].left = 1;
	flow[3][2].straight = 0;
	flow[3][2].right = 0;
	
	flow[3][3].left = 1;
	flow[3][3].straight = 1;
	flow[3][3].right = 1;
	
	//--------------------- 4
	
	flow[4][0].left = 1;
	flow[4][0].straight = 1;
	flow[4][0].right = 0;
	
	flow[4][1].left = 0;
	flow[4][1].straight = 0;
	flow[4][1].right = 0;
	
	flow[4][2].left = 1;
	flow[4][2].straight = 1;
	flow[4][2].right = 0;
	
	flow[4][3].left = 0;
	flow[4][3].straight = 0;
	flow[4][3].right = 0;
	
	//--------------------- 5
	
	flow[5][0].left = 0;
	flow[5][0].straight = 0;
	flow[5][0].right = 0;
	
	flow[5][1].left = 1;
	flow[5][1].straight = 1;
	flow[5][1].right = 0;

	flow[5][2].left = 0;
	flow[5][2].straight = 0;
	flow[5][2].right = 0;
	
	flow[5][3].left = 1;
	flow[5][3].straight = 1;
	flow[5][3].right = 0;
	
	//--------------------- 6


	
	cout<<"Masukkan Flow 1 : ";cin>>den[0];
	cout<<"Masukkan Flow 2 : ";cin>>den[1];
	cout<<"Masukkan Flow 3 : ";cin>>den[2];
	cout<<"Masukkan Flow 4 : ";cin>>den[3];
	
	cout<<endl;
	cout<<"Himpunan Kandidat  "<<endl;
	cout<<"F1  F2  F3  F4"<<endl;
	cout<<"LSR LSR LSR LSR "<<endl;
	
	cout<<endl;
	//menampilkan 
	for (i=0;i<6;i++){
		for(j=0;j<4;j++){
			cout<<flow[i][j].left;
			cout<<flow[i][j].straight;
			cout<<flow[i][j].right;
			cout<<" ";
			
		}
		cout<<endl;
	}
	cout<<""<<endl;
	
	//memasukkan solusi
	for(i=0;i<4;i++){
		
		itoa(flow[0][i].left,temp,10);
		strcat(solusi,temp);
		
		itoa(flow[0][i].straight,temp,10);
		strcat(solusi,temp);
		
		itoa(flow[0][i].right,temp,10);
		strcat(solusi,temp);
		
		
	}
	
	sub[0].left = flow[0][0].left;
	sub[0].straight = flow[0][0].straight;
	sub[0].right = flow[0][0].right;
	
	sub[1].left = flow[0][1].left;
	sub[1].straight = flow[0][1].straight;
	sub[1].right = flow[0][1].right;
	
	sub[2].left = flow[0][2].left;
	sub[2].straight = flow[0][2].straight;
	sub[2].right = flow[0][2].right;
	
	sub[3].left = flow[0][3].left;
	sub[3].straight = flow[0][3].straight;
	sub[3].right = flow[0][3].right;
	
	for (i=0;i<4;i++){
		temp_hitung[i] = sub[i].left + sub[i].straight + sub[i].right;
		temp_hitung[i] = temp_hitung[i]*30;
		temp_hitung[i] = den[i] - temp_hitung[i];
		if (temp_hitung[i] < 0){
			temp_hitung[i] = 0;
		}
		
		
	}
	
	hitungDS = temp_hitung[0] + temp_hitung[1] + temp_hitung[2] + temp_hitung[3];
	if (DS == 0){
		DS = hitungDS;
	} else if(hitungDS >= DS){
		DS = hitungDS;
	}
	cout<<"DS : "<<DS<<endl;
	cout<<"Solusi : "<<solusi<<endl;
	
	
	system("pause");
	return 0;
}
