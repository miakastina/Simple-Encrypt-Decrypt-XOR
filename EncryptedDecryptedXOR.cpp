//Create by Mia Kastina
//   NIM 2015-81-178
#include <iostream>
#include <conio.h>
#include <string.h>
#include <math.h>
using namespace std;

void dec(unsigned char y){
	cout<<" :  "<<y<<"\t: "<<(int)y<<"\t\t"<<": ";
}

void binaryBits(unsigned char x){
	
	for (int i=7; i>=0; i--)
    {
		if(x >= pow(2,i))
		{
			cout<<"1";
			x = x - pow(2,i);
		}
		else
		cout<<"0";
	}
	
} 

int main()
{
unsigned char pesan [100],kunci[100],enkripsi [100],deskripsi [100];
int panjang_data,panjang_data_kunci,i,j=0;
unsigned int ascii[100],ascii_kunci [100],ascii_enkripsi [100],ascii_deskripsi [100];
cout<<" ........................................ \n";
cout<<" :    PROGRAM ENKRIPSI DAN DESKRIPSI    : \n";
cout<<" :       MENGGUNAKAN METODA XOR         : \n";
cout<<" ........................................ \n\n";
// INPUT PESAN
cout<<" SILAHKAN MASUKKAN PESAN\n";
cin.sync();
cout <<" Pesan = ";
cin.get((char*)pesan,100);
//MENGHITUNG PANJANG PESAN
panjang_data = strlen ((char*)pesan); 
cout<<endl;
//MENAMPILKAN PANJANG PESAN
cout<<" Panjang Data Pesan = "<<panjang_data<<"\n\n"; 
//MENAMPILKAN KODE ASCII PESAN
cout<<" Tampilan Kode ASCII\n";
cout<<" ****************************************\n";
cout<<" : Char"<<"\t"<<":"<<" Decimal "<<"\t"<<":"<<" Binary "<<"\t"<<":\n";
cout<<" ****************************************\n";
for (i=0; i<=panjang_data-1; i++)
		{
			//mengubah pesan menjadi kode ascii
			ascii[i] = int (pesan[i]); 
			dec(pesan[i]);
			binaryBits(pesan[i]);
			cout<<"\t"<<":\n";
		}
cout <<" ****************************************\n\n";	  

//INPUT KUNCI
cout <<" SILAHKAN MASUKKAN KUNCI \n"; 
cin.sync();
cout <<" Kunci : ";
cin.get((char*)kunci,100);
//MENGHITUNG PANJANG KUNCI
panjang_data_kunci = strlen ((char*)kunci);
cout <<endl;
//MENAMPILKAN PANJANG KUNCI
cout<<" Panjang Data Kunci = "<<panjang_data_kunci<<"\n\n";
cout<<" Tampilan Kode ASCII\n";
//MENAMPILKAN KODE ASCII KUNCI
cout<<" ****************************************\n";
cout<<" : Char"<<"\t"<<":"<<" Decimal "<<"\t"<<":"<<" Binary "<<"\t"<<":\n";
cout<<" ****************************************\n";
	for (i=0; i<=panjang_data_kunci-1; i++)
	{
		//menampilkan perubahan kunci menjadi kode ascii
		ascii_kunci[i] = int (kunci[i]);
		dec(kunci[i]);
		binaryBits(kunci[i]);
		cout<<"\t"<<":\n";
	}
cout<<" ****************************************\n\n";	

//MENAMPILKAN ENKRIPSI PROSES XOR PESAN DAN KUNCI 
cout<<" ============== PROSES XOR ==============\n"; 
cout<<" ==============  ENKRIPSI  ==============\n\n";
	//menampilkan perulangan kunci kode ASCII
	for (i=0; i<=panjang_data-1; i++){
		ascii_kunci[i] = int (kunci[i]);
		if(i == panjang_data_kunci){
			i = 0;
		}
		else
		{
			i = i + 1;
		}
	}
	
	//menampilkan proses XOR
	for (i=0; i<=panjang_data-1; i++)
	{
		//menampilkan pesan XOR kunci
		cout<<" ";
		binaryBits(pesan[i]);
		cout<<"  "<<" XOR "<<"  ";
		binaryBits(kunci[j]);
		cout<<"   =   ";
		//proses XOR pesan dengan kunci
		ascii_enkripsi[i] = ascii[i] ^ ascii_kunci[j]; 
		j = j + 1;
			if (j == panjang_data_kunci)
			{
				j = 0;
			}	
		//menampilkan perubahan kode ASCII 	
		enkripsi [i] = int (ascii_enkripsi[i]);
		binaryBits(enkripsi[i]);
		cout<<endl;
		cout<<"\t\t  Decimal "<<"   =   "<<ascii_enkripsi[i]<<"\n"
			<<"\t\t  Char "<<"\t     =   "<<enkripsi[i]<<endl;
	}
cout<<endl;
//HASIL DARI ENKRIPSI
cout<<"        Pesan Setelah di Enkripsi        \n";
cout<<" ========================================\n";
cout<<"\n"<<" ";
	//menampilkan hasil enkripsi
	for (i=0; i<=panjang_data-1; i++)
	{
		cout<<enkripsi[i]<<" ";
	}
cout<<"\n\n\n";
//MENAMPILKAN PROSES DESKRIPSI YANG TELAH DIENKRIPSI
cout<<" ============Proses Deskripsi============\n"; 
cout<<" ========================================\n";
cout<<" \tPesan Enkripsi\n";
cout<<" \tKode ASCII\n";
cout<<" \t"<<"Char"<<"\t"<<" => "<<"\t"<<"Decimal\n";
cout<<" \t***********************"<<"\n\n";
	//menampilkan perubahan enkripsi kode ASCII (Char => Decimal)
	for (i=0; i<=panjang_data-1; i++)
	{
		ascii_deskripsi[i] = enkripsi[i] ;
		cout <<" \t"<< enkripsi [i] <<"\t"<<" => " <<"\t"<< ascii_deskripsi[i]<< endl;
	}
cout<<"\n\n";
cout<<" HASIL\n\n";
cout<<" \tPesan Deskripsi\n";
cout<<" \tKode ASCII\n";
cout<<" \t"<<"Decimal"<<"\t"<<" => "<<"\t"<<"Char\n";
cout<<" \t***********************\n\n";
	//menampilkan perubahan deskripsi kode ASCII (Decimal => Char)
	for (i=0; i<=panjang_data-1; i++)
	{
		//proses XOR enkripsi dengan kunci
		deskripsi[i] = ascii_deskripsi [i] ^ ascii_kunci[j]; 
		j = j + 1;
			if (j == panjang_data_kunci)
			{
				j = 0;
			}
	//menampilkan perubahan kode ASCII 
	cout<<"\t"<<ascii_enkripsi[i]<<"\t"<<" =>"<<"\t"<<deskripsi[i]<<endl;
	}
cout <<endl;
//HASIL DARI DESKRIPSI
cout <<"        Pesan Setelah di Deskripsi       \n";
cout <<" ========================================\n";
cout <<"\n"<<" ";
	//menampilkan hasil deskripsi
	for (i=0; i<=panjang_data-1; i++)
	{
		cout <<deskripsi[i]<<" " ;
	}
cout<<endl<<endl;

cout <<" ========================================\n";
cout<<"\t   Nama"<<"\t"<<":"<<" Mia Kastina\n";
cout<<"\t   NIM"<<"\t"<<":"<<" 2015-81-178\n";
cout <<" ========================================\n";
return 0;
}

