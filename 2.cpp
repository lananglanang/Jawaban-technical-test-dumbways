#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int array[]={1,4,6,2,6,8,9,21,20, 14, 3,6,11,1,1,2,3,4,6,8,9,2,1,5,2,5,6,8,3,2};
	int n=sizeof(array)/sizeof(array[0]);  //ukuran array
	sort(array,array+n); //pengurutan array
	
	string peringkat[]={" pertama: "," kedua: "," ketiga: "};
	int ban=0;
	for(int i=n-1;i>=0;i--){
		if(array[i]%2==1){
			cout<<"Nilai tertinggi"<<peringkat[ban]<<array[i]<<endl;
			ban++;
		}
		if(ban==3){
			break;
		}
	}
	
	return 0;
}
