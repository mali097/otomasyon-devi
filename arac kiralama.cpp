#include <iomanip> 
#include <cstring> 
#include <stdlib.h>
#include <conio.h>
#include <stdio.h> 
#include <fstream>                  
#include <iostream>

using namespace std;

struct Araba
{

	char arabamarka[80];
	char Yakitturu[5];
	char arabaplaka[80];
    int arabafiyati;	
};
void arabaEkle();
void arabaListeleme();
void arabaArama();
void arabaSil();
void arabaDuzenle();
int main(){
	setlocale(LC_ALL,"Turkish");
	
	char anamenu;
	do{
	system("cls");
	
	cout << "*<<<<<<<Hosgeldiniz>>>>>>*"<<endl;
	cout << "*      Seçim Yapiniz     *"<<endl;
	cout << "*   1- Araba Ekleme      *"<<endl;
	cout << "*   2- Araba Listeleme   *"<<endl;
	cout << "*     3- Araba Arama     *"<<endl;
	cout << "*    4-  Araba Sil       *"<<endl;
	cout << "*    5- Araba Düzenle    *"<<endl;
    char secim;
	cin>> secim;
	
	switch(secim) 
	{
		case '1' : 
		{
		arabaEkle();
		break;	
		}
		case '2' : 
		{
		 arabaListeleme()	;
		 break;
		}
		case '3' : 
		{
		 arabaArama()	;
		 break;
		}
		case '4' : 
		{
		 arabaSil()	;
		 break;
		}
		case '5' : 
		{
		 arabaDuzenle();
		 break;
		}
	}
	
	cout << "Anamenuye Donmek icin: 0`a basin cikmak için: e" <<endl ; 
	anamenu=getche();
	
    }while(anamenu=='a');
     

return 0;
}

Araba car;

void arabaEkle()
{
	ofstream yaz("araba.dat",ios::binary |ios::app);
	char secim;
	int adet=0;
    
	do{

	cout << "Araba marka Giriniz" << endl;
	cin>> car.arabamarka;
	cout << "Yakýt Türü Giriniz" << endl;
	cin>> car.Yakitturu;
	cout << "Araba plaka giriniz" << endl;
	cin>>car.arabaplaka;
	cout << "Araba Fiyatý giriniz" << endl;
	cin>>car.arabafiyati;
		
	cout << endl;
	yaz.write((char*)&car, sizeof(car));	
	adet++;	
	cout << "Baska Araba eklemek istermisiniz?" << endl;
	secim=getche();
	cout << endl;
	}while(secim=='e' || secim=='E');
	
	cout << adet << " adet Araba Ekledi.." << endl;
	
	yaz.close();
	
	
}

void arabaListeleme()
{
	
	ifstream oku("Araba.dat",ios::binary |ios::app);
    
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(car);
	cout << "Toplam Kiralanan araba Sayýsý:"<< kayits << endl;
	
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			oku.seekg(i*sizeof(car));
			oku.read((char*)&car, sizeof(car));	
		
			cout << i+1 << ". araba bilgileri"<< endl;
			cout << "Araba Markasý: "<< car.arabamarka <<endl ;
			cout << "Araba Yakýt türü: "<< car.Yakitturu <<endl ;
			cout << "Araba Plaka: "<< car.arabaplaka <<endl ;
			cout << "Araba Fiyatý: "<< car.arabafiyati <<endl ;
			
		}
		
		
	}
	else
	cout << "Araba Bulunamadi..." << endl;

	oku.close();
}
void arabaArama()
{
	
	ifstream oku("Araba.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(car);
//	cout << "Toplam Ogrenci Kayit Sayisi:"<< kayits << endl;

cout <<"Aranan yakýt türünü Giriniz"<< endl;
char yakitturu[80];
cin>> yakitturu;
 		
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			
			oku.seekg(i*sizeof(car));
			oku.read((char*)&car, sizeof(car));
			
			if(strcmp(car.arabaplaka,car.arabaplaka)==0)
			{
			cout <<  "Araç Bilgileri"<< endl;
			cout << "Araç Markasý: "<< car.arabamarka <<endl ;
			cout << "araç yakýt türü: "<< car.Yakitturu <<endl ;
			cout << "araç plaka: "<< car.arabaplaka <<endl ;
			cout << "araç fiyatý: "<< car.arabafiyati <<endl ;
			
		    }
		}
		
		
	}
	else
	cout << "Kayitli arac Bulunamadi..." << endl;

	oku.close();
}

void arabaSil()
{
	char arabaplaka[80];
	 char yakitturu[80];
     char secim= ' ';
     bool var=false;
     
    ifstream oku("araba.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);

	int kayitsayisi=oku.tellg()/sizeof(car);
	
     cout<<"Kaydini Sileceginiz araba plaka giriniz : ";
     cin>>arabaplaka;

     for(int i=0;i<kayitsayisi;i++)
     {
            oku.seekg(i*sizeof(car));
			oku.read((char*)&car, sizeof(car));
			
     if(strcmp(car.arabaplaka,arabaplaka)==0)
       {
                 cout<<endl;
                 cout<<"Arabanýn";
                  cout<<"\nMarkasý : "<<car.arabamarka<<endl;
                   cout<<"\nYakýt türü: "<<car.Yakitturu;
                   
                cout<<"\nFýyatý: "<<car.arabafiyati;
               
         	 				  
                cout<<"\n\nSilmek Istediginiz plaka Bu Mu? : ";
                 secim=getche();
            if(secim == 'H' || secim == 'h')
              {      
			    Araba y_car;
                ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
                
                strcpy(y_car.arabamarka,car.arabamarka);
                strcpy(y_car.Yakitturu,car.Yakitturu);
                strcpy(y_car.arabaplaka,car.arabaplaka);
                        
                y_dosya.write((char*)&car, sizeof(car));
                y_dosya.close();
              }
            if(secim=='e'||secim=='E')
              {
   			   	var=true;
  		 	  }
        }
             else
             {
              Araba y_car;
              ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
              
              strcpy(y_car.arabamarka,car.arabamarka);
              strcpy(y_car.arabaplaka,car.arabaplaka);
              strcpy(y_car.Yakitturu,car.Yakitturu);
               y_car.arabafiyati=car.arabafiyati;       
              y_dosya.write((char*)&car, sizeof(car));
              y_dosya.close();
             }
     }
    oku.close();
    if(var)
    {
               remove("araba.dat");
               rename("Yedek.dat","araba.dat");
               cout<<"\n Kayit Silindi"<<endl;
    }
    else
    {
               remove("Yedek.dat");
               cout<<"\n Kayit Bulunamadi"<<endl;                  
    }
	
	
}

void arabaDuzenle()
{
	 char arabaplaka[80];
     char secim= ' ';
     bool var=false;
     
    ifstream oku("araba.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);

	int kayitsayisi=oku.tellg()/sizeof(car);
		
     cout<<"Kaydini Duzelteceginiz araba plaka Giriniz : ";
     cin>>arabaplaka;

     for(int i=0;i<kayitsayisi;i++)
     {
            oku.seekg(i*sizeof(car));
			oku.read((char*)&car, sizeof(car));
			
     		if(strcmp(car.arabaplaka,arabaplaka)==0)
     		  {
     		  	
                 cout<<endl;
                 cout<<"Arabanýn";
                 cout<<"\nMarkasý : "<<car.arabamarka<<endl;
                 cout<<"\nYakýt Türü : "<<car.Yakitturu;
                 cout<<"\nFiyatý : "<<car.arabafiyati;
                cout<<"\nPlakasý : "<<car.arabaplaka;
                 
                  cout<<"\n\nDuzeltmek Istediginiz Araba Bu Mu? [E/H] : ";
                  secim=getche();
                  if(secim == 'E' || secim == 'e')
                  {
                     	var=true;
                        ofstream dosya("Yedek.dat",ios::app|ios::binary);
                        cout << "\nAraba Marka giriniz" << endl;
						cin>> car.arabamarka;
						cout << "Araba Yakýt türü Giriniz" << endl;
						cin>> car.Yakitturu;
						cout << "Araba Fiyatý Giriniz" << endl;
						cin>> car.arabafiyati;
						cout << "Araba Plaka Giriniz" << endl;
						cin>>car.arabaplaka;
						cout << endl;
		  
                        dosya.write((char*)&car, sizeof(car));
                        dosya.close();
            	  }
            	 else
                 	{
                         Araba y_car;
                         ofstream y_dosya;
                         y_dosya.open("Yedek.dat",ios::app|ios::binary);
                         
                    	 strcpy(y_car.arabamarka,car.arabamarka);
            			 strcpy(y_car.Yakitturu,car.Yakitturu);
            			 strcpy(y_car.arabaplaka,car.arabaplaka);
             			  y_car.arabafiyati=car.arabafiyati;
                         
             			 y_dosya.write((char*)&y_car, sizeof(y_car));
                         y_dosya.close();
                   }
     }
 }
    oku.close();
    if(var)
    {
               remove("araba.dat");
               rename("Yedek.dat","araba.dat");
               cout<<"\nKayit Duzeltildi."<<endl;
    }
    else
    {
               remove("Yedek.dat");
               cout<<"\nKayit Bulunamadi"<<endl;                  
    }

}


