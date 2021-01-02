#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#include<stdlib.h>
using namespace std;
int ubahInt(string s){
	s.erase(remove(s.begin(), s.end(), '.'), s.end()); //menghilangkan tanda titik
	int a=0;
	stringstream geek(s); 
    geek >> a; // Ubah ke int
	return a;
}
string ubahString(int n){
	string s;
	stringstream geek;
	geek << n; 
    geek >> s; // Ubah ke string
    
    int panj=s.length();
	int ban=0;
	for(int i=panj;i>0;i--){
		if(ban==3){
			ban=0;
			s.insert(i,1,'.');
		}
		ban++;
	}
    
	return s;
}


string sebut(int n){
	string s;
	string digit[11]={"","se","dua ","tiga ","empat ","lima ","enam ","tujuh ","delapan ","sembilan ","satu"};
	string imbuh[4]={"ratus ","puluh ","","belas "};
	int ratusan=n/100;
	int puluhan=(n%100)/10;
	int satuan=(n%10);
	if(satuan==1){
		satuan=10;
	}
	
	int array[3]={ratusan,puluhan,satuan};
	int flag=0;
	for(int i=0;i<3;i++){
		if(i==1 && array[i]==1){
			flag=1;
		}
		else if(array[i]!=0){
			if(flag==1){
				s+=digit[array[i]]+imbuh[i+1];
			}
			else{
				s+=digit[array[i]]+imbuh[i];
			}
			flag=0;
			
		}
	}
	return s;
}


string bilang(string s){
	string akhiran[]={"rupiah","ribu ","juta ","miliar ","biliar "};
	size_t n = count(s.begin(), s.end(), '.');
	
	string kata;
	int len=s.length();
	string ban;
	for(int i=0;i<len;i++){
		if(s[i]!='.' || i==len-1){
			ban+=s[i];
		}
		if(s[i]=='.' || i==len-1){
			int angka=ubahInt(ban);
			kata+=sebut(angka)+akhiran[n];
			n--;
			ban.clear();
		}

	}
	
	return kata;
}





int main(){
	string baya, tota;
	cout<<"Menghitung kembalian\n\n";
	cout<<"Uang dibayar: Rp ";
	cin>>baya;
	cout<<"\nTotal bayar: Rp ";
	cin>>tota;
	
	int total=ubahInt(tota);
	int bayar=ubahInt(baya);

	cout<<"\n\n-----------------------------------------------\n-----------------------------------------------\n\n";
	
	int tambah = 0;
	if(total>bayar){
		while(total>bayar){
			string h=ubahString(total-bayar);
			cout<<"Uang yang dibayar kurang sebesar "<<h<<"\nMasukkan tambahan bayar: Rp ";
			string tamba;
			cin>>tamba;
			tambah=ubahInt(tamba);
			bayar+=tambah; 
			cout<<endl<<endl;
		}
		system("cls");
		string b=ubahString(bayar);
		string t=ubahString(total);
		cout<<"Uang dibayar: Rp "<<b;
		cout<<"\nTotal bayar: Rp "<<t;
		cout<<"\n\n-----------------------------------------------\n-----------------------------------------------\n\n";
	}
	
	
	
	
	string money[12]={"100.000","50.000","20.000","10.000","5.000","2.000","1.000","500","100","50","10","1"};
	int uang[12]={100000,50000,20000,10000,5000,2000,1000,500,100,50,10,1};
	int itung[12]={0};

	int pec=0;
	int selisih=bayar-total;
	while(selisih!=0){
		while(selisih>=uang[pec]){
			selisih-=uang[pec];
			itung[pec]++;
		}
		pec++;
	}
	
	for (int i=0;i<12;i++){
		if(itung[i]==0){
			continue;
		}
		cout<<"Uang pecahan Rp "<<money[i]<<" sebanyak "<<itung[i]<<" lembar\n";
	}
	cout<<endl;
	cout<<"\n-----------------------------------------------\n-----------------------------------------------\n\n";
	
	int kembalian=0;
	for (int i=0;i<12;i++){
		kembalian+=itung[i]*uang[i];
	}
	
	string kembalia=ubahString(kembalian);
	string terbilang=bilang(kembalia);
	
	cout<<"Total kembalian: Rp "<<kembalia<<endl;
	cout<<"Terbilang: "<<terbilang<<endl<<endl;
	
	
	return 0;
}
