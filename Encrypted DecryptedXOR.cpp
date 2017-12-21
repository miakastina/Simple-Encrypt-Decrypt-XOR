//Created by Mia Kastina
//   NIM 2015-81-178
#include <iostream>
#include <conio.h>
#include <string.h>
#include <math.h>
using namespace std;

void dec(unsigned char y)
{
	cout<<" :  "<<y<<"\t: "<<(int)y<<"\t\t"<<": ";
}

void binary(unsigned char x)
{
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

void garis()
{
	cout <<" ****************************************\n";	  
}

void headerAwal()
{
	cout<<" ........................................ \n";
	cout<<" :    PROGRAM ENKRIPSI DAN DESKRIPSI    : \n";
	cout<<" :       MENGGUNAKAN METODA XOR         : \n";
	cout<<" ........................................ \n\n";
}

void headerAscii()
{
	cout<<" Tampilan Kode ASCII\n";
	garis();
	cout<<" : Char"<<"\t"<<":"<<" Decimal "<<"\t"<<":"<<" Binary "<<"\t"<<":\n";
	garis();
}

void headerProsesXOR()
{
	cout<<" ============== PROSES XOR ==============\n"; 
	cout<<" ==============  ENKRIPSI  ==============\n\n";
}

void headerStlhEnkripsi()
{
	cout<<"        Pesan Setelah di Enkripsi        \n";
	cout<<" ========================================\n";
	cout<<"\n"<<" ";
}

void headerProsesDeskripsi()
{
	cout<<" ============Proses Deskripsi============\n"; 
	cout<<" ========================================\n";
}

void headerPD()
{
	
	cout<<" Kode ASCII\n";
	cout<<" Binary"<<"\t"<<"  => "<<"Decimal"<<"\t"<<" => "<<"\t"<<"Char\n";
	garis();
}


void headerStlhDeskripsi()
{
	cout <<"        Pesan Setelah di Deskripsi       \n";
	cout <<" ========================================\n";
	cout <<"\n"<<" ";
}

void CreatedBy(){
	char n[20]= {78,97,109,97,32,58,32,77,105,97,32,75,97,115,116,105,110,97};
	char m[20]= {78,73,77,32,32,58,32,50,48,49,53,45,56,49,45,49,55,56};
	int i;
	cout <<" ========================================\n\t"<<"   ";
	for(i=0;i<=17;i++)
	{
	 	cout<<n[i];
	}	
	cout<<"\n\t"<<"   ";
	for(i=0;i<=17;i++)
	{
		cout<<m[i];
	}
	cout<<"\n"<<" ========================================\n";
}

int main()
{
unsigned char pesan [100],kunci[100],enkripsi [100],deskripsi [100];
int panjang_data,panjang_data_kunci,i,j=0;
unsigned int ascii[100],ascii_kunci [100],ascii_enkripsi [100],ascii_deskripsi [100];
	headerAwal();
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
	headerAscii();
	for (i=0; i<=panjang_data-1; i++)
			{
				//mengubah pesan menjadi kode ascii
				ascii[i] = int (pesan[i]); 
				dec(pesan[i]);
				binary(pesan[i]);
				cout<<"\t"<<":\n";
			}
	garis();
cout<<endl;
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
//MENAMPILKAN KODE ASCII KUNCI
	headerAscii();
	for (i=0; i<=panjang_data_kunci-1; i++)
	{
		//menampilkan perubahan kunci menjadi kode ascii
		ascii_kunci[i] = int (kunci[i]);
		dec(kunci[i]);
		binary(kunci[i]);
		cout<<"\t"<<":\n";
	}
	garis();
cout<<endl;
//MENAMPILKAN ENKRIPSI PROSES XOR PESAN DAN KUNCI 
	headerProsesXOR();
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
		binary(pesan[i]);
		cout<<"  "<<" XOR "<<"  ";
		binary(kunci[j]);
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
		binary(enkripsi[i]);
		cout<<endl;
		cout<<"\t\t  Decimal "<<"   =   "<<ascii_enkripsi[i]<<"\n"
			<<"\t\t  Char "<<"\t     =   "<<enkripsi[i]<<endl;
	}
cout<<endl;
//HASIL DARI ENKRIPSI
	headerStlhEnkripsi();
	//menampilkan hasil enkripsi
	for (i=0; i<=panjang_data-1; i++)
	{
		cout<<enkripsi[i]<<" ";
	}
cout<<"\n\n\n";
//MENAMPILKAN PROSES DESKRIPSI YANG TELAH DIENKRIPSI
	headerProsesDeskripsi();
	cout<<"             *Pesan Enkripsi*            \n";
	headerPD();
	//menampilkan perubahan enkripsi kode ASCII (Biner => Decimal => Char)
	for (i=0; i<=panjang_data-1; i++)
	{
		ascii_deskripsi[i] = enkripsi[i] ;
		cout <<" ";
		binary(enkripsi[i]);
		cout<<" => "<<int (enkripsi[i])<<" "<<"\t"<<" => " <<"\t"<<enkripsi [i]<< endl;
	}
cout<<"\n\n";
	cout<<" HASIL\n\n";
	cout<<"            *Pesan Deskripsi*            \n";
	headerPD();
	//menampilkan perubahan deskripsi kode ASCII (Biner => Decimal => Char)
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
	cout<<" ";
	binary(deskripsi[i]);
	cout<<" => "<<int(deskripsi[i])<<" "<<"\t"<<" =>"<<"\t"<<deskripsi[i]<<endl;
	}
cout <<endl;
//HASIL DARI DESKRIPSI
	headerStlhDeskripsi();
	//menampilkan hasil deskripsi
	for (i=0; i<=panjang_data-1; i++)
	{
		cout <<deskripsi[i]<<" " ;
	}
cout<<endl<<endl;
	CreatedBy();
return 0;
}

