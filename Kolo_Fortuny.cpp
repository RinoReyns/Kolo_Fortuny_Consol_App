//////// POP 2013-12-17 projekt 1 Pindor £ukasz EIT 6 149292 Dev- C++ 5.3.0.4
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int TS=5;

struct staty_gracza	{
	 char imie [12] ;
	int kwota;
	char dodatki[100];

};
void wpis_graczy(int  liczba_graczy, staty_gracza tab[])  ///////// funkcja ta wczytuje imiona graczy do tablicy

{	cout<<endl;
	int b;
	cout<<"Podaj imiona graczy."<< endl<<endl;
	for (int i=0;i< liczba_graczy;i++)
	{	staty_gracza tab1[8];
		for(int j=0;j<13;j++)
		tab[i].imie[j]=' ';
		cin.sync();
		cout<<"Imie: ";
		cin>>tab1[i].imie;
		cin.sync();
		for(int j=0;j<9;j++)
		tab[i].imie[j]=tab1[i].imie[j];
		
		for(int j=9;j<13;j++)
		tab[i].imie[j]=tab1[i].imie[j];
		}
		cin.sync();}
		
		
	void wypis_graczy(int  liczba_graczy,int runda,staty_gracza tab[])   /////////// funkcja ta wypisuje graczy, oraz ich dorobek. przed 1 runda tylko imie a nastepnie
{																										///////// pieniadze i nagrody
	if (runda!=0)
	{cout<<"********************************************************************************"<<endl;
		cout<<"Imie gracza";
		cout<<setw(17)<<"Pieniadze";
		cout<<setw(25)<<"Nagrody dodatkowe"<<endl;
	 for( int i=0;i<liczba_graczy;i++)
	{
	
	cout<<"--------------------------------------------------------------------------------";                     ////// tabelka po zakonczeniu rundy
	cout<<"  "<<tab[i].imie<<setw(16-(sizeof(tab[i].imie)))<< "        "<<setw(5) <<tab[i].kwota<<"         "<<setw(10) <<tab[i].dodatki<<endl; 
	cout<<"--------------------------------------------------------------------------------"<<endl;
	}}
	
	if (runda==0)
	{cout<<"********************************************************************************"<<endl;
	cout<<setw(65)<<" W grze uczestnicza nastepujace osoby: "<<endl;
	for( int i=0;i<liczba_graczy;i++)
	{cin.sync();
	cout<<setw(15)<<"-----------------"<<endl;
	cout<<"|"<<setw((sizeof(tab[i].imie)))<<tab[i].imie<<setw(16-(sizeof(tab[i].imie)))<< " |"<<endl; ///////// ¿eby tabelka siê nie rozje¿d¿a³a
	cout<<setw(15)<<"-----------------"<<endl;
	}}}

int menu_p(staty_gracza tab_s[])    ////// poczatkowa funkcja, która pokazuje pierwszy ekran i wczytuje liczbe graczy i sprawdza czy liczba graczy jest prawid³owa
{	char h;
	int wybor;
	cout<<"********************************************************************************"<<endl;
	cout<<endl<<endl;
	cout<<setw(53) << "Witam w grze 'Kolo Fortuny'."<<endl<<endl;
	cout<<setw(65)<<"Jesli chcesz przeczytac reguly gry wcisnij 'T'. "<<endl<<endl;
				cin.sync();        
                wybor = cin.get();  
				h=(char)tolower(wybor);
				cin.sync();
	if(h=='t')			
	{
	cout<<setw(60) << "Oto reguly gry. Przeczytaj je uwaznie."<<endl<<endl;     ////// regu³y gry
	cout<<endl;
	system("pause");
	system("cls");
	cout<<"********************************************************************************"<<endl;
	cout<<"1.Gra ta przenaczona jest dla, od jednego do czterech, graczy."<<endl<<endl;
		cout<<endl;
		system("pause");
		cout<<endl;
	cout<<"2.Kolejnosc graczy w pierwszej rundzie zostanie ustalona przed rozpoczeciem gry."<<endl;
	cout<<"Kazda kolejna runde rozpoczyna gracz, ktory ma najmniej pieniedzy na swoim "<<endl;
	cout<<"koncie. Jesli gracze maja tyle samo pieniedzy na koncie to gracz, ktory na "<<endl;
	cout<<"poczatku wylosowal wieksza liczbe lub zaczynal poprzednia ture, jest"<<endl;
	cout<<"wczesniej w kolejnosci."<<endl<<endl;
	cout<<endl;
	system("pause");
	cout<<endl;
	cout<<"3.Gracz podaje tylko spolgloski. "<<endl<<endl;
		cout<<endl;
		system("pause");
		cout<<endl;
	cout<<"4.Samogloski moga zostac jedynie zakupione przez gracza za kwote 200 zl. "<<endl<<endl;
	system("pause");
	cout<<endl;
	cout<<"5.Kazda runda trwa 10 tur lub do momentu, kiedy haslo zostanie odgadniete."<<endl<<endl;
		cout<<endl;
		system("pause");
		cout<<endl;	
	cout<<"6. Jesli wylosujesz pole STOP lub BANKRUT tracisz ture. Dodatkowo przy "<<endl;
	cout<<"wylosowaniu pola BANKRUT wszystkie pieniadze z konta, lecz nie nagrody rzeczowe."<<endl<<endl;
		cout<<endl;
		system("pause");
		cout<<endl;
	cout<<"7. Jesli gracz nie odganie litery, nastepuje tura kolejnego zawodnika."<<endl<<endl;
			cout<<endl;
			system("pause");
			cout<<endl;
	cout<<"8. Jesli gracz straci ture, kwota na kole zostanie wylosowana jeszcze raz "<<endl;
		cout<<"w turze kolejnego zawodnika."<<endl;
		cout<<endl;
		system("pause");
		cout<<endl;	
	cout<<"9. Wygrywa gracz, ktory zgromadzi najwiecej pieniedzy."<<endl<<endl;
	cout<<endl;
	system("pause");
	cout<<endl;
	cout<<setw(60)<<" Uwaga!!! Gra nie zawiera polskich znakow"<<endl<<endl<<endl;
	cout<<setw(60)<<"Aby rozpoczac gre nacisnij dowolny przycisk.";
	cout<<endl;
	system("pause");
	system("cls");
	cout<<"********************************************************************************"<<endl;
	}
	cout<<setw(65)<<"Podaj ilosc graczy, ktorzy chca wziac udzial w grze: ";    ///// wczytywanie ilosci graczy
	char a[10];
	int b=0;
	int c=0;
	int g=0;
	
		cin>>a;								////// wczytanie do tablicy znaków znaków i zrzutowanie na int'a
		b=(int)a[0];	
		c=(int)a[1];
		cin.sync();
		cout<<endl;	
		while(!(b<53) or !(b>48) or !(c==0)) ////////// jesli pierwszy znak zawiera jest od 1 do 4 w kodzie ASCII a 2 równy 0 to progra wychodzi z pentli
		{
		cout<< "Podana liczba graczy jest nieprawidlowa. Podaj liczbe graczy jeszcze raz: ";
		a[1]='-';
		cin>> a;
		b=(int)a[0];
		c=(int)a[1];
		cin.sync();
		}
		g=a[0]-48;       ////// przpisanie ilosci graczy do zmiennej g, która jest zwracana
		
	wpis_graczy(g,tab_s);	
	system("cls");
	return g;}	

void kategorie(char tab[]/*tablica w której jest haslo*/ ,int licznik, int &rozmiar) //////// losowanie kategorii hasla i samego hasla w zaleznosci od rundy.
{ 
	if(licznik==2)
		{
		licznik=licznik-1;	
		}
		if(licznik>3)
		{	
			licznik=licznik-2;
	}
	int a=rand()%9+1;
	cout<<endl<<setw(50)<<"Zostala wylosowana kategoria: ";
	switch(a)
	{
	case 1:
			{int a1=a+licznik;
				cout<<"Miejsce"<<endl;
			if (a1==1)
				{
				char tab1[]="Honolulu";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];
				 }
				 
			if (a1==2)	
				{char tab1[]="Muzeum Narodowe";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}	
			if (a1==3)
				{ char tab1[]="Nebraska";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				 break;
			}
			
		case 2:
			{int a2=a+licznik;
				cout<<"Przyslowie/Powiedzene"<<endl;
			if (a2==2)
				{ char tab1[]="Kto sie czubi ten sie lubi";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
			if (a2==3)
				{ char tab1[]="Co ma wisiec nie utonie";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
			if (a2==4)
				{ char tab1[]="Od zera do milionera";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				 break;
			}
			case 3:
			{int a3=a+licznik;
				cout<<"Cytat"<<endl;
			if (a3==3)
				{ char tab1[]="Cogito ergo sum";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
			if (a3==4)
				{ char tab1[]="Alea iacta est";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
			if (a3==5)
				{ char tab1[]="Non omnis moriar";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				 break;
			}
			case 4:
			{int a4=a+licznik;
				cout<<"Osoba"<<endl;
			if (a4==4)
				{ char tab1[]="Winston Churchil";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
			if (a4==5)
				{ char tab1[]="Paul Gilbert";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
			if (a4==6)
			{ char tab1[]="Pan kolejarz";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				 break;
			}
			case 5:
			{int a5=a+licznik;
				cout<<"Tytul"<<endl;
			if (a5==5)
				{ char tab1[]="Perpetuum Debile";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
			if (a5==6)
				{ char tab1[]="Hrabianka";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
			if (a5==7)
				{ char tab1[]="Stairway to Heaven";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				 break;
				 }
			case 6:
				{int a6=a+licznik;
				cout<<"Rzecz"<<endl;
			if (a6==6)
				{ char tab1[]="Gitara";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
			if (a6==7)
				{ char tab1[]="Kopytko";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
			if (a6==8)
				{ char tab1[]="Latawiec";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				 break;
			}case 7:
			{int a7=a+licznik;
				cout<<"Czynnosc"<<endl;
			if (a7==7)
				{ char tab1[]="Tasowanie";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				if (a7==9)
				{ char tab1[]="Kontemplacja";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				if (a7==10)
				{ char tab1[]="Spawanie";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				 break;
			}
			case 8:
			{int a8=a+licznik;
				cout<<"Postac"<<endl;
			if (a8==8)
				{ char tab1[]="Predator";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				if (a8==9)
				{ char tab1[]="Killer";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				if (a8==10)
				{ char tab1[]="Ted Mosby";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				 break;
			}
			case 9:
			{int a9=a+licznik;
				cout<<"Miasto"<<endl;
			if (a9==9)
				{ char tab1[]="Woodstock";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}	
			if (a9==10)
				 { char tab1[]="Jarocin "; ////////////// JAorcin '84
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
			if (a9==11)
				{ char tab1[]="Las Vegas";
				rozmiar=sizeof(tab1);
				for (int i=0;i<rozmiar;i++)
				 tab[i]=tab1[i];}
				break;
				}}}

void kolo(char tab[], int &rozmiar,int runda, int &c,int licznik_rund )    /// kolo losujace wartoci o jakie graja gracze
{
int losy[20]={0/*bankrut*/,100,325,400,275,25,6/*stop*/,375,225,425,500,75,125,300,475,175,16/*nagroda*/,320,20,200};

int a; 
tab[0]=' ';
	a=rand()%20;
	 if (runda==0)    //// w losowaniy kolejnosci jest losowana liczba tak, by nie wylosowac pól bankrut, stop, nagroda
	 	do
	 	{ a=rand()%20;
	 	}
	 	while(a==0 or a==6 or a==16);
	 	if(licznik_rund==3)
	 		losy[10]=1400;
	 	if(licznik_rund==4)
	 		losy[10]=2000;
	
	if (a==0 )									// jesli funkcja wylosuje pole 0 do tablicy przypisuje bankrut
	{char Ctab[]="Bankrut";
	rozmiar=sizeof(Ctab);
	for (int i=0;i<rozmiar;i++)
	tab[i]=Ctab[i];}
	
	if (a==6 )										/// jak 6 to do tablicy przypisuje stop
	{char Ctab[]="Stop";
	rozmiar=sizeof(Ctab);
	for (int i=0;i<rozmiar;i++)
	tab[i]=Ctab[i];}
	
	if (a==16 )									// jak 16 to do tablicy przypisuje nagroda
	{char Ctab[]="Nagroda";
	rozmiar=sizeof(Ctab);
	for (int i=0;i<rozmiar;i++)
	tab[i]=Ctab[i];}
	
	if(a!=0 and a!=6 and a!=16)        
	{rozmiar=1;
	c=losy[a];}
	
		if(runda!=0)						
			if (rozmiar>1)				///jesli wylosowany bankrut, nagroda, stop, lub pole w pobli¿u tych pól,
				{if (a==0)
					{cout<<losy[19]<<" ";
				for(int i=0;i<rozmiar;i++)
					cout<<tab[i];
				 	cout<<" "<<losy[1];
					cout<<endl;
					cout<<setw(30)<< "Wylosowales pole: ";
					for(int i=0;i<rozmiar;i++)
					cout<<tab[i];
					;}	
					else	
					{
					cout<<losy[a-1]<<" ";
					for(int i=0;i<rozmiar;i++)
					cout<<tab[i];
					cout<<losy[a+1];
					cout<<endl;
					cout<< "Wylosowales pole: ";
					for(int i=0;i<rozmiar;i++)
					cout<<tab[i];
					}}
			else {
				 if(a==19)
				{
				cout<<losy[18]<<" ";
				cout<<c<<" ";
				char Ctab[]="Bankrut";
				rozmiar=sizeof(Ctab);
				for (int i=0;i<rozmiar;i++)
				{tab[i]=Ctab[i];
				cout<<tab[i];}
				cout<<endl;
				cout<<setw(30)<< "Wylosowales pole: "<<c;
				tab[0]=' ';
				}
				else{
				if((a-1)==0 or (a-1)==6 or (a-1)==16 or (a+1)==6 or (a+1)==16 ) //////// liczby w obli¿u stop, nagrody,bankruta
					{if ((a-1)==0 )		
					{char Ctab[]="Bankrut";
					rozmiar=sizeof(Ctab);
					for (int i=0;i<rozmiar;i++)
					{tab[i]=Ctab[i];
					cout<<tab[i];}
					cout<<c<<" "<<losy[a+1];
					cout<<endl;
					tab[0]=' ';
					rozmiar=1;
						cout<<setw(30)<< "Wylosowales pole: ";
						cout<<c;
					}
					if ((a-1)==6 or (a+1)==6 )
					{char Ctab[]="Stop";
					rozmiar=sizeof(Ctab);
					for (int i=0;i<rozmiar;i++)
					tab[i]=Ctab[i];
						if ((a-1)==6)
							{
							{for (int i=0;i<rozmiar;i++)
							cout<<tab[i];}
							cout<<c<<" "<<losy[a+1];
							tab[0]=' ';
							rozmiar=1;
							cout<<endl;
							cout<<setw(30)<< "Wylosowales pole: ";
							cout<<c;
							}
							else { cout<<losy[a-1]<<" "<<c<<" ";
							for (int i=0;i<rozmiar;i++)
							cout<<tab[i];
							
							tab[0]=' ';
							rozmiar=1;
							cout<<endl;
							cout<<setw(30)<< "Wylosowales pole: ";
							cout<<c;
							}}
	
					if ((a-1)==16 or (a+1)==16 )
					{char Ctab[]="Nagroda";
					rozmiar=sizeof(Ctab);
					for (int i=0;i<rozmiar;i++)
					tab[i]=Ctab[i];
					if ((a-1)==16)
							{
							{for (int i=0;i<rozmiar;i++)
							cout<<tab[i];}
							cout<<c<<" "<<losy[a+1];
							cout<<endl;
							tab[0]=' ';
							rozmiar=1;
							cout<<setw(30)<< "Wylosowales pole: ";
							cout<<c;
							}
							else { cout<<losy[a-1]<<" "<<c<<" ";
							for (int i=0;i<rozmiar;i++)
							cout<<tab[i];
							cout<<endl;
							tab[0]=' ';
							rozmiar=1;
							cout<<setw(30)<< "Wylosowales pole: ";
							cout<<c;
							}}}
						else {cout<<losy[a-1]<<" "<<c<<" "<<losy[a+1];			//////// kiedy w pobli¿u nie ma bankruta, nagrodylub stop,
						cout<<endl;
						cout<<setw(30)<< "Wylosowales pole: ";
						cout<<c;}
}
}

}
	

void plansze (char tab[], int licznik,int &rozmiar,int licznik_graczy )	// wypisywanie wylosowanego hasla 
{
	kategorie(tab,licznik, rozmiar);
	
	cout<<endl;
	cout<<setw(35);
	if(rozmiar<18)
	cout<<setw(30);
	else{cout<<setw(15);
	}
	for(int i=0;i<rozmiar-1;i++)
	{	
		if(tab[i]==' ')
		cout<<"  "; 
		else cout<<"_ ";
		}}

void samogloska	(staty_gracza tab_s[], char tab[],char tab2[],int rozmiar,int &h,int &l,int tura_gracz)   ///////// zapytanie o kupno samoglosek
{																			//// sprawdzanie, czy sa jeszcze jakies do kupienia i spradzanue czy gracz ma na to fundusze

	
		int wybor;
	 	char b;	
		 	
				if(h==0)
				{    
				cout<<endl<<"Jesli chcesz kupic samogloske wcisnij 'T'. Jesli nie wcisnij dowolny klawisz: ";
				cin.sync();        
                wybor = cin.get();  
				b=(char)tolower(wybor);}
				cin.sync();
				if(b=='t' or l>0)										////// warunek zakupu samogloski. czy by³a chec kupienia lub czy licznik jest wiekszy
				{														/////// od zera przy kolejnych obiegach pentli
			if(tab_s[tura_gracz].kwota<200)                   ////// warunek sprawdzajacy kwote na koncie
				{ cout<<"Nie masz pieniedzy na koncie, aby zakupic samogloske. Przykro mi."<<endl;
					tab_s[tura_gracz].kwota=(tab_s[tura_gracz].kwota);
				}
				else{
				 b='k';
					int p=0;
					
				switch(l)
				{case 0:{b='o';
				h=0;
				for(int i=0;i<2;i++)										////// pental robi podwójny obieg, gdy¿ samogloska moze byc duza i mala litera 
				{	for(int k=0;k<rozmiar-1;k++)							///// 
				{	if(h!=0)
						b=tolower(b);	
					if(h==0)
						b=toupper(b);	
					if (tab[k]==b)
						{
					if((tab2[k]=='_') and (tab_s[tura_gracz].kwota>=200))
					{tab2[k]=tab[k];
				tab_s[tura_gracz].kwota=tab_s[tura_gracz].kwota-200;
					p++;}}											//////// p licznik wyst¹pieñ danej samogloski i ile razy zostala zakupiona przez gracza
					h++;}											///////h licznik, który sprawdza, czy pental by³a chodŸ raz wykonana 
						if(i==1)									///// aby nie pokazywac pytania czy chesz kupic samogloske
						{if(p==0 and i==1)
						{l++;	
						 samogloska(tab_s,tab,tab2,rozmiar,h,l,tura_gracz);
						}else {if(p==1)
								cout<<"Kupiles "<<p<< " samogloske 'o' , ktora jest w nastepujacym miejscu:"<<endl<<endl<<setw(20);
							else cout<<"Kupiles "<<p<< " samoglosek 'o' , ktore sa w nastepujacych miejsach:"<<endl<<endl<<setw(20);
							for(int k=0;k<rozmiar-1;k++)			
							cout<<tab2[k]<<" ";	
							}}}
				break;}
				case 1:{b='i';
				h=0;
				for(int i=0;i<2;i++)
				{	for(int k=0;k<rozmiar-1;k++)
				{	
					if(h!=0)
						b=tolower(b);	
					if(h==0)
						b=toupper(b);	
					if (tab[k]==b)
						{
						if((tab2[k]=='_') and(tab_s[tura_gracz].kwota>=200))
					{tab2[k]=tab[k];
				tab_s[tura_gracz].kwota=tab_s[tura_gracz].kwota-200;
					p++;}}							
					h++;}
						if(i==1)
						{if(p==0 and i==1)
						{l++;	
						samogloska(tab_s,tab,tab2,rozmiar,h,l,tura_gracz);
						}else {if(p==1)
								cout<<"Kupiles "<<p<< " samogloske 'i' , ktora jest w nastepujacym miejscu:"<<endl<<endl<<setw(20);
							else cout<<"Kupiles "<<p<< " samoglosek 'i' , ktore sa w nastepujacych miejsach:"<<endl<<endl<<setw(20);
							for(int k=0;k<rozmiar-1;k++)			
							cout<<tab2[k]<<" ";	}}}
				break;}
				case 2:{b='a';
				h=0;		
				for(int i=0;i<2;i++)
				{	for(int k=0;k<rozmiar-1;k++)
				{	if(h!=0)
						b=tolower(b);	
					if(h==0)
						b=toupper(b);	
					if (tab[k]==b)
						{
					if((tab2[k]=='_') and(tab_s[tura_gracz].kwota>=200))
					{tab2[k]=tab[k];
				tab_s[tura_gracz].kwota=tab_s[tura_gracz].kwota-200;
					p++;}}							
					h++;}
						if(i==1)
						{if(p==0 and i==1)
						{l++;	
						samogloska(tab_s,tab,tab2,rozmiar,h,l,tura_gracz);
						}else {if(p==1)
								cout<<"Kupiles "<<p<< " samogloske 'a' , ktora jest w nastepujacym miejscu:"<<endl<<endl<<setw(20);
							else cout<<"Kupiles "<<p<< " samoglosek 'a' , ktore sa w nastepujacych miejsach:"<<endl<<endl<<setw(20);
							for(int k=0;k<rozmiar-1;k++)			
							cout<<tab2[k]<<" ";	}
				}}
				break;}
				case 3:{b='u';
				h=0;
				for(int i=0;i<2;i++)
				{	for(int k=0;k<rozmiar-1;k++)
				{	if(h!=0)
					b=tolower(b);	
					if(h==0)
						b=toupper(b);	
					if (tab[k]==b)
						{
					if((tab2[k]=='_') and(tab_s[tura_gracz].kwota>=200))
					{tab2[k]=tab[k];
				tab_s[tura_gracz].kwota=tab_s[tura_gracz].kwota-200;
					p++;}}							
					h++;}
						if(i==1)
						{if(p==0 and i==1)
						{l++;	
						samogloska(tab_s,tab,tab2,rozmiar,h,l,tura_gracz);
						}else {if(p==1)
								cout<<"Kupiles "<<p<< " samogloske 'u' , ktora jest w nastepujacym miejscu:"<<endl<<endl<<setw(20);
							else cout<<"Kupiles "<<p<< " samoglosek 'u' , ktore sa w nastepujacych miejsach:"<<endl<<endl<<setw(20);
					for(int k=0;k<rozmiar-1;k++)			
							cout<<tab2[k]<<" ";	}}}		
				break;}
				case 4:{b='e';
				h=0;
				
				for(int i=0;i<2;i++)
				{	for(int k=0;k<rozmiar-1;k++)
				{	
					if(h!=0)
						b=tolower(b);	
					if(h==0)
						b=toupper(b);	
					if (tab[k]==b)
						{
						if((tab2[k]=='_') and(tab_s[tura_gracz].kwota>=200))
					{tab2[k]=tab[k];
				tab_s[tura_gracz].kwota=tab_s[tura_gracz].kwota-200;
					p++;}}							
					h++;}
						if(i==1)
						{if(p==0 and i==1)
						{l++;	
						samogloska(tab_s,tab,tab2,rozmiar,h,l,tura_gracz);
						}else {if(p==1)
								cout<<"Kupiles "<<p<< " samogloske 'e' , ktora jest w nastepujacym miejscu:"<<endl<<endl<<setw(20);
							else cout<<"Kupiles "<<p<< " samoglosek 'e' , ktore sa w nastepujacych miejsach:"<<endl<<endl<<setw(20);
							for(int k=0;k<rozmiar-1;k++)			
							cout<<tab2[k]<<" ";	}}}
				break;}
				case 5:{b='y';
				h=0;
				for(int i=0;i<2;i++)
				{	for(int k=0;k<rozmiar-1;k++)
				{	if(h!=0)
						b=tolower(b);	
					if(h==0)
						b=toupper(b);	
					if (tab[k]==b)
						{
						if((tab2[k]=='_') and(tab_s[tura_gracz].kwota>=200))
					{tab2[k]=tab[k];
				tab_s[tura_gracz].kwota=tab_s[tura_gracz].kwota-200;
					p++;}}							
					h++;}
						if(i==1)
						{if(p==0 and i==1)
						{l++;	
						samogloska(tab_s,tab,tab2,rozmiar,h,l,tura_gracz);
						}else {if(p==1)
								cout<<"Kupiles "<<p<< " samogloske 'y' , ktora jest w nastepujacym miejscu:"<<endl<<endl<<setw(20);
							else cout<<"Kupiles "<<p<< " samoglosek 'y' , ktore sa w nastepujacych miejsach:"<<endl<<endl<<setw(20);
						for(int k=0;k<rozmiar-1;k++)			
							cout<<tab2[k]<<" ";	}}}	
				break;}
					default:{
						cout<<" Nie ma juz wiecej samoglosek do kupienia"<<endl;
						tab_s[tura_gracz].kwota=(tab_s[tura_gracz].kwota+200);
									
					break;}
					}
					}
					}
					cout<<endl;}
					
	

void whaslo(int rozmiar,char tab[]/*haslo*/,int &tura_gracz,int &c,char literki[],char tab2[]/*zakryte haslo*/,staty_gracza tab_s[],int licznik_graczy,int &o, int &prawda )
{																						// sprawdzanie czy podana literka jest w hasle 
		cin.sync();
			int a=0;
			 	c=0;
			int h=0;
			int l=0;
			 cout<<endl<<endl;
			 samogloska(tab_s,tab,tab2,rozmiar,h,l,tura_gracz);
			 for(int i=0;i<rozmiar;i++)											/////// sprawdzanie, czy po kupieniu samogloski sa jakies litery do odgadniecia
				{if(tab2[i]=='_')
				o++;}
			
			 if(o>1)
			 {
			 cout<<endl;
			cout<<setw(30)<<"Podaj spolgloske: ";
			cin>>literki;
			cin.sync();
			cout<<endl<<endl<<setw(25);
			int p=0;
			if(literki[1]==0)					////// sprawdzanie czy zostala podana jedna literak czy wiecej, jesli wiecej to tura przechodzi na kolejnego gracza
			{for(int k=0;k<rozmiar-1;k++)
				{
				if(literki[0]!='a' and literki[0]!='o' and literki[0]!='u' and literki[0]!='e' and literki[0]!='y' and literki[0]!='i')
					{if(p!=0)
						literki[0]=tolower(literki[0]);									/////// pentla wykonuje 2 obiegi, raz sprawdzaja czy podana literka wystepuje jako ma³a i 
					if(p==0)															////// czy wystepuje jako duza
						literki[0]=toupper(literki[0]);	
					if (tab[k]==literki[0])
						{
						if(tab2[k]=='_')
					{tab2[k]=tab[k];
					a++;
					c++;
					}
					else a=-2;
					}
					} 
					if(tab[k]==' ')
							tab2[k]=tab[k];
				if(p==1)		
				cout<<tab2[k]<<" ";
				if (k==rozmiar-2)
					{if(p==0)				/////// wywo³ywanie pentli po raz 2 po przez nadanie k wartosci -1, gdy¿ poca³ej pentli k dostaje wartosc o jeden wieksza
						{						////// za sprawa ++
						 p=1;
						k=-1;
						}}}
				if(a>0)
				{prawda=1;							////////wypisywanie odpowiedniego komunikatu zgodnie ze zbadanymi warunkami
				cout<<endl<<endl<<" Podales literke, ktora byla w hasle.";}
				else {
					
				 if(tura_gracz<licznik_graczy-1 )
				{tura_gracz++;}
				else {
				tura_gracz=0;}
				if(a==-2)
						cout<<endl<<"Podales literka, ktora juz zostala odkryta. Tracisz koleje. Teraz gracz "<<tab_s[tura_gracz].imie<<endl<<endl;
				else{
				
				if(literki[0]=='a' or literki[0]=='o' or literki[0]=='u' or literki[0]=='e' or literki[0]=='y' or literki[0]=='i')
						cout<<endl<<endl<<"Podales samogloske. Tracisz kolejke. Teraz tura gracza "<<tab_s[tura_gracz].imie;
						else cout<<endl<<endl<<"Podales znak, ktorego nie ma w hasle. Teraz tura gracza "<<tab_s[tura_gracz].imie;
				cout<<endl<<endl;
				cin.sync();
				}}}
				else cout<<"Podales za duzo znakow. Teraz tura gracza: "<<tab_s[tura_gracz].imie<<endl;
				o=0;
			for(int i=0;i<rozmiar;i++)
				{if(tab2[i]=='_')
				o++;}
			
			}}
				


void sprawdzanie(int &tura_gracz, int &liczba, char tab1[],staty_gracza tab_s[], int licznik,int rozmiar, char tab[],int licznik_graczy,int &licznik_p,int &c,int &rozmiark, int &licznik_przyp,char tabDod[],int licznik_b )
{
	char b;
		if(licznik_przyp>0)											///// po wylosowaniu nagrody i odgadnieciu literki nagroda jest przypisywana do gracza				
					{
						if(licznik_p==1)
								{tab_s[tura_gracz].dodatki[0]==' ';
								licznik_p=licznik_p+1;}
									 
									 
							if(tab_s[tura_gracz].dodatki[0]==' ')
								{for(int i=0;i<licznik_przyp;i++)
							{tab_s[tura_gracz].dodatki[i]=tabDod[i];							
						
							}}
							
							else{
							for( int i=0;i<sizeof(tab_s[tura_gracz].dodatki)+c;i++) 	
							{b=tab_s[tura_gracz].dodatki[i];
								if(b==' ')
								{c=i+1;
								tab_s[tura_gracz].dodatki[i]=',';
								
								break;
								}
								}
								
								cout<<endl;
								for(int i=c;i<licznik_przyp+c;i++)
								{tab_s[tura_gracz].dodatki[i]=tabDod[i-c];
								
								}
								for(int i=0;i<licznik_przyp+c;i++)
								cout<<tab_s[tura_gracz].dodatki[i];
								cout<<endl;
								}}
								else
if ((liczba>0) and (tab1[0]=='N'))				//////////////// jesli wylosowane pole jest nagroda, to jest losowany rodzaj nagrody
					{	
						if((tab1[0]=='N'))
					{ int a=rand()%4;						
						switch(a)
						{	case 0:{ char tabA[]={'L','O','D','O','W','K','A',' ',NULL};
							cout<<"pod ktorym kryje sie: ";
							cout<< tabA;
							cout<<" o wartosci 250 zl.";
							liczba=250;
							rozmiark=1;
							for(int i=0;i<sizeof(tabA);i++)
							tabDod[i]=tabA[i];
							licznik_przyp=sizeof(tabA);
								break;}
							case 1:{
							char tabA[]={'S','A','M','O','C','H','O','D',' ',NULL};
							cout<<"pod ktorym kryje sie: ";
							cout<< tabA;
							cout<<" o wartosci 50000 zl.";
							liczba=50000;
							rozmiark=1;
							for(int i=0;i<sizeof(tabA);i++)
							tabDod[i]=tabA[i];
							licznik_przyp=sizeof(tabA);
								
									 
								break;
							}
							case 2:{
							char tabA[]={'P','R','A','L','K','A',' ',NULL};
							cout<<"pod ktorym kryje sie: ";
							cout<< tabA;
							cout<<" o wartosci 150 zl.";
							liczba=150;
							rozmiark=1;
							for(int i=0;i<sizeof(tabA);i++)
							tabDod[i]=tabA[i];
							licznik_przyp=sizeof(tabA);
								break;
							}
							case 3:{char tabA[]={'D','O','M',' ',NULL};
								cout<<"pod ktorym kryje sie: ";
							cout<< tabA;
							cout<<" o wartosci 100000 zl.";
							liczba=100000;
							rozmiark=1;
								for(int i=0;i<sizeof(tabA);i++)
							tabDod[i]=tabA[i];
							licznik_przyp=sizeof(tabA);
								break;
							}}}}
					else if((tab1[0]=='S') or (tab1[0]=='B'))    ///////// jesli wylosowanne pole jest bankrutem albo stop, to tu nastepuja sprawdzenia i odpowiednie dzia³ania
						{	if (tura_gracz<licznik_graczy-1)		
								tura_gracz=tura_gracz+1;
							else tura_gracz=0;
							
							if(  tab1[0]=='S')
								cout<<endl<<"Tracisz ture. Teraz tura gracza: "<<tab_s[tura_gracz].imie<<endl;;
							
						if( licznik_b>1 and (tab1[0]=='B'))
							{cout<<" Tracisz wszystkie pieniadze i kolejke."<<endl<<endl;
								if(tura_gracz>0)
								{tab_s[tura_gracz-1].kwota=0;
								}else {
								tab_s[licznik_graczy-1].kwota=0;}
							cout<<" Teraz tura gracza: "<<tab_s[tura_gracz].imie;
							}	
							else{
							if (licznik_b==1  and (tab1[0]=='B'))
								cout<<"Nie masz pieniedzy na koncie, wiec tracisz tylko kolejke ."<<endl<<"Teraz tura gracza: "<<tab_s[tura_gracz].imie;
								}
								
								
								
								}}
	
void koniec(staty_gracza tab_s[],int licznik_rund,int liczba_graczy)		/// wypisywanie na koniec rundy i ca³ej gry tabeli z wygranymi graczy i kolejnoscia
{	staty_gracza buf;
		if(licznik_rund==4)
				{
				for (int i=0;i<liczba_graczy-1; i++)		//// gracz z najwieksza suma na konice jest tu wyswietlany na poczatku
				for (int j=0;j<liczba_graczy-1; j++)
				{
				if (tab_s[j].kwota<tab_s[j+1].kwota)
				{ buf=tab_s[j];
					tab_s[j]=tab_s[j+1];
					tab_s[j+1]=buf;}}
					
					wypis_graczy( liczba_graczy,licznik_rund,tab_s);
					cout<<"********************************************************************************"<<endl;
					cout<<setw(50)<<"Gra zostala zakonczona!!!!!!";
					cout<<endl<<setw(40)<<"Gre wygral gracz: "<<tab_s[0].imie<<". Gratulacje dla zwyciezcy"<<endl;
					}
					else{for (int i=0;i<liczba_graczy-1; i++)			
				for (int j=0;j<liczba_graczy-1; j++)
				{
				if (tab_s[j].dodatki<tab_s[j+1].dodatki)			 //// a tu gracz z najwiecej nagrud na koncie jest wyswietlany na koncu
				{ buf=tab_s[j];
					tab_s[j]=tab_s[j+1];
					tab_s[j+1]=buf;}}
					
					for (int i=0;i<liczba_graczy-1; i++)		
				for (int j=0;j<liczba_graczy-1; j++)
				{
				if (tab_s[j].kwota>tab_s[j+1].kwota)			 //// a tu gracz z najwieksza suma na koncie jest wyswietlany na koncu
				{ buf=tab_s[j];
					tab_s[j]=tab_s[j+1];
					tab_s[j+1]=buf;}}
					
					wypis_graczy( liczba_graczy,licznik_rund,tab_s);		
					
					}}	


void poczatek_rundy(char tab[], int &licznik,int rozmiar /*HASLA*/,int licznik_graczy, staty_gracza tab_s[],int &tura_gracz, int  rozmiark,int &licznik_rund)
{	
	char tab1[9];
	int liczba=0;	
	if(licznik==0)
	{ 
	int a=0;
	int b=1;
	int c=2;
	int d=3;
	staty_gracza buf;	
	
	cout<<"********************************************************************************"<<endl;
	cout<<setw(55)<<" A wiec rozpocznijmy gre!!!! "<<endl<<endl;
	cout<<setw(45)<<"Teraz odbedzie sie losowanie kolejnosci graczy w grze."<<endl;
	cout<<"Kazdy z graczy zakreci kolem i wylosuje liczbe. Ten z graczy, ktory wylosuje wieksza ten zaczyna.";

	cout<<" Aby rozpoczac losowanie nacisnij dowolny przycisk.";
	
	cout<<endl<<endl;
	do{																////////// losowanie kolejnosci graczy. Gdy którykolwiek z wyników sie powtarza
																	////////// program losuje jeszcze raz liczby, az beda inne
	for(int i=0;i<licznik_graczy;i++)
	{	
		kolo(tab1,rozmiar,licznik,liczba,licznik_rund);
		
		if(i==0)
			a=liczba;
		if(i==1)
			b=liczba;
		if(i==2)
			c=liczba;
		if(i==3)
			d=liczba;}
			}while (!((a!=b) and (a!=c) and (a!=d) and (b!=c) and (b!=d) and (c!=d)));
		if(licznik_graczy>0)
		cout<< tab_s[0].imie<<" wylosowal/a: "<<a<<endl; 
		if(licznik_graczy>1)
		cout<< tab_s[1].imie<<" wylosowal/a: "<<b<<endl; 
		if(licznik_graczy>2)
		cout<< tab_s[2].imie<<" wylosowal/a: "<<c<<endl; 
		if(licznik_graczy>3)
		cout<< tab_s[3].imie<<" wylosowal/a: "<<d<<endl; 
			cout<<endl;
		cout<<endl;
	cout<<endl;
	system("pause");
	cout<<endl;
		cout<<"A wiec kolejnosc graczy jest nastepujaca :"<<endl;
	
		int tablica[4]={a,b,c,d};
		int temp;
		for (int i=0;i<licznik_graczy-1; i++)							/////// ustalanie kolejnosci, od gracza, który wylosowa³ najwieksza sume, do tego co wylosowa³ najmniejsza
				for (int j=0;j<licznik_graczy-1; j++)
				{
				if (tablica[j]<tablica[j+1])
				{ 
					temp=tablica[j]; 
					tablica[j] = tablica[j+1];
					tablica[j+1] =temp; 
					
					buf=tab_s[j];
					tab_s[j]=tab_s[j+1];
					tab_s[j+1]=buf;}}
					
					for (int i=0;i<licznik_graczy;i++)				////// wypis
			cout<<"Gracz:" <<tab_s[i].imie<<endl;}		
			cout<<endl;
			cout<<endl;
			system("pause");
			system("cls");
			cout<<setw(30)<<"Czas rozpoczac runde "<<licznik+1;
			cout<<setw(30)<<". Teraz zostanie wylosowana kategoria."<<endl; 
		for(int i=0;i<licznik_graczy;i++)						////// zeowanie liczników kwoty wszystkich graczy
			{tab_s[i].kwota=0;
			for(int j=0;j<12;j++)
			tab_s[i].dodatki[j]=' ';
			}
		
		int licznik_w=0;
		int licznik_p=1;
		int puste_miejsce=0;
		int o;
		 int licznik_przyp;
		 char tabDod[15]; 
	    int licznik_b=0;
	
	for(int s=0;s<3;s++)								///////// wlasciwa gra, która odbywa sie 3 razy
	{plansze (tab,licznik, rozmiar,licznik_graczy );
			licznik=licznik+1;
			cout<<endl<<endl;;
			cout<<setw(20)<<"Runde rozpoczyna gracz "<<tab_s[0].imie;
			cout<<" i jako pierwszy losuje pole na kole."<<endl;
			cout<<endl;
			system("pause");
			cin.sync();
			cout<<endl;
			char literki[]={0,0,0};
			char tab2[rozmiar];
			o=0;
		for(int i=0;i<rozmiar;i++)
				tab2[i]='_';								///// wypisaywanie zakrytej tablicy z has³em
			tura_gracz=0;
			for(int i=0;i<10-o;i++)								////// jedna runda
			{ licznik_b++;
				int prawda=0;
			licznik_przyp=0;
			 char tabDod[]={' ',' ',' ',' ',' ',' ',' ',' ',' ',NULL};	
			 
			cout<<"Gracz "<<tab_s[tura_gracz].imie<<" wylosowal: ";
			kolo(tab1,rozmiark,licznik,liczba,licznik_rund);
			sprawdzanie(tura_gracz,liczba, tab1,tab_s,licznik, rozmiar,tab,licznik_graczy,licznik_p,puste_miejsce,rozmiark,licznik_przyp,tabDod,licznik_b); 
			cin.sync();	
			
			if (tab1[0]!='B' and tab1[0]!='S')							//// sprwadzanie, czy tura nie zosta³a stracona i wtedy dopiero gracz dostaje mozliwosc wpisania litery
			{whaslo(rozmiar,tab,tura_gracz,licznik_w,literki,tab2,tab_s,licznik_graczy,o,prawda);}
			
			
			if(licznik_przyp!=licznik_przyp+prawda)						//////// wpisanie nagrody odpowiedniemu graczowi
			{
			sprawdzanie(tura_gracz,liczba, tab1,tab_s,licznik, rozmiar,tab,licznik_graczy,licznik_p,puste_miejsce,rozmiark,licznik_przyp,tabDod,licznik_b); }
			if(o==1)												//////// sprawdzanie, czy sa jakies pute miejsca, jak nie to o dostaje wartosc 10 i konczy sie runda
			o=10;
			else o=0;
		
			if(rozmiark==1)										//////// przypisanie pieniedzy w zale¿nosci od ilosci wysp¹pieñ literki
				{tab_s[tura_gracz].kwota=tab_s[tura_gracz].kwota+(liczba*licznik_w);}
				
				cout<<endl;
				cout<<"Pieniadze gracza "<<tab_s[tura_gracz].imie<<" wynosza: "<<tab_s[tura_gracz].kwota;
				if((tab_s[tura_gracz].dodatki[0])!=' ')
					cout<<", a nagrody to: "<<tab_s[tura_gracz].dodatki<<endl;
					else cout<<endl;
					}
					cout<<endl;
					if(o==0)
					{cout<<setw(10)<<"Poprawne haslo to: "; 
				for(int i=0;i<rozmiar;i++)
				cout<<tab[i];	
				}
					else cout<<"Gratulacje!!!. Odgadles cale haslo!!"<<endl;
					cout<<endl;
					
		
			
			if (licznik_rund<4)
			{
			koniec(tab_s,licznik_rund,licznik_graczy);
			cout<< "Gracz "<< tab_s[0].imie<<" zacznie kolejna runde"<<endl;}
		cout<<endl;
		system("pause");
			system("cls");
				licznik_rund++;
				}

licznik_rund=4;
}

int main() {
 	staty_gracza tab_s[TS];
	srand(time(NULL));
	int liczba_graczy=0;
	int licznik_rund=0; //////////////// na poczatku na 0!!!!!!!!!!!!
	int rozmiar_hasla;	////// dlugosc hasla w tablicy 
	int rozmiark;
	char haslo[100];	//// do tej tablicy haslo wpisywane jest
	int tura_gracz=0;

 	
	liczba_graczy=menu_p(tab_s);
	for(int j=0;j<liczba_graczy;j++)
 	for(int i=0;i<99;i++)
	tab_s[j].dodatki[i]=' ';
	wypis_graczy( liczba_graczy,licznik_rund,tab_s);	
	cout<<endl;
	system("pause");
	system("cls"); 
	poczatek_rundy(haslo,licznik_rund,rozmiar_hasla,liczba_graczy,tab_s,tura_gracz, rozmiark, licznik_rund);

	koniec(tab_s,licznik_rund,liczba_graczy);

	return 0;
}

