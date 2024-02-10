/* 
	Projekt c++ na lekcje Programowania
	Kacper Stańczyk 3IA
*/

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include <ctime>


using namespace std;
int wybor;
int HP = 20;
int O2 = 20;
int glod = 20;
int stamina = 20;
int Zelazo = 15;
int Stal = 0;
int Miedz = 0;
int MiesoKosmity = 0;
int nasionaMarchewki = 5;
int Marchewki = 0;
int dni = 1;
int limitHP = 10;
int limitO2 = 10;
int limitG = 10;
int limitS = 10;
int pojemnoscEkwipunku = 500;
int Silnik = 0;
int Sciana = 0;
int KrysztalMocy = 0;
int sumaSurowcow = Zelazo + Stal + Miedz + nasionaMarchewki + Marchewki + MiesoKosmity + KrysztalMocy + Silnik + Sciana;
int graczAtak = 5;
string klasa = "Klasa";
string k1 = "Silacz   ";
string k2 = "Farmer   ";
string k3 = "Kowal    ";
string k4 = "Hard Mode";

void Welcome();
void oGrze();
void GUI();
void rysowanie_mapy();
void walka();
void wybierzPostac();
void sadzenie();
void kopalnia();
void baza();
void craft();
void WygranaPrzegrana();
void ulepsz();

void setColor(int color)
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE); //ustawia kolor dla konsoli
	SetConsoleTextAttribute(hc, color);
}
void resetColor()
{
	HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE); //resetuje kolor na domyslnie ustawiony
	SetConsoleTextAttribute(hc, 5); //czyli ten
}
void sadzenie()
{
	int wyborM;
	cout << "| Podaj ile nasion chcesz zasadzic: " << endl;
	cin >> wyborM;
	if (wyborM <= nasionaMarchewki)
	{
		cout << "| Zasadziles " << wyborM << " nasion marchewek" << endl;
		nasionaMarchewki -= wyborM;
		Sleep(2000); //czeka 2s - 2000s milisekund
		cout << "| Wow, twoje plony juz urosly. Dodajemy do twojego ekwipunku " << wyborM << " marchewek" << endl;

		if (sumaSurowcow + wyborM <= pojemnoscEkwipunku)
		{
			Marchewki += wyborM;
			nasionaMarchewki += wyborM;
			cout << "| Pomyslnie zebrano marchewki" << endl;
			Sleep(1000);
			GUI();
		}
		else
		{
			cout << "| Ekwipunek jest pelny" << endl;
			nasionaMarchewki = nasionaMarchewki + ((sumaSurowcow + wyborM) - pojemnoscEkwipunku);
			Marchewki = Marchewki + ((sumaSurowcow + wyborM) - pojemnoscEkwipunku);
			Sleep(1000);
			GUI();

		}
	}
	else
	{
		cout << "Nie masz wystarczajacej ilosci nasion" << endl;
		Sleep(1000);
		GUI();
	}


}

int main()
{

	Welcome();

}


void wybierzPostac()
{
	system("cls");
	cout << "+=====================================================+" << endl;
	cout << "| Wybierz klase postaci ktora chcesz grac             | " << endl;
	cout << "+=====================================================+" << endl;
	cout << "| 1. Silacz | 30 HP | 15 O2 | 15 GLOD | 25 STAMINA    |" << endl;
	cout << "+-----------------------------------------------------+-----------------------------+" << endl;
	cout << "| 2. Farmer | 15 HP | 25 O2 | 25 GLOD | 15 STAMINA + 15 NASION KOSMICZNEJ MARCHEWKI |" << endl;
	cout << "+-----------------------------------------------------------------------------------+" << endl;
	cout << "| 3. Kowal | 20 HP | 20 O2 | 15 GLOD | 30 STAMINA + 20 ZELAZA,5 MIEDZI I STALI      | " << endl;
	cout << "+----------------------------------------------------+------------------------------+" << endl;
	cout << "| 4. HardMode | 10 HP | 10 O2 | 10 GLOD | 10 STAMINA |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
		cout << "Wybrales Silacza." << endl;
		HP = 30; O2 = 15; glod = 15; stamina = 25;
		limitHP = 30; limitO2 = 15; limitG = 15; limitS = 25; klasa = k1;
		Sleep(1000);
		GUI();
		break;
	case 2:
		cout << "Wybrales Farmera." << endl;
		HP = 15; O2 = 25; glod = 25; stamina = 15; nasionaMarchewki = 15; klasa = k2;
		limitHP = 15; limitO2 = 25; limitG = 25; limitS = 15;
		Sleep(1000);
		GUI();
		break;
	case 3:
		cout << "Wybrales Kowala." << endl;
		HP = 20; O2 = 20; glod = 15; stamina = 30; Zelazo = 20; Miedz = 5; Stal = 5; klasa = k3;
		limitHP = 20; limitO2 = 20; limitG = 15; limitS = 30;
		Sleep(1000);
		GUI();
		break;
	case 4:
		cout << "Wybrales tryb trudny." << endl;
		HP = 10; O2 = 10; glod = 10; stamina = 10; klasa = k4;
		limitHP = 10; limitO2 = 10; limitG = 10; limitS = 10;
		Sleep(1000);
		GUI();
		break;
	default:
		cout << "Wybrales niepoprawny numer klasy. Sprobuj ponownie" << endl;
		Sleep(500);
		wybierzPostac();
		break;
	}

}

void Welcome()
{
	system("cls");
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 12);
	cout << "+-----------------------------------------------------+" << endl;
	cout << "|                   WITAJ NA MARSIE                   |" << endl;
	cout << "|       WALCZ, ZDOBYWAJ SUROWCE I WROC NA ZIEMIE      |" << endl;
	cout << "+-----------------------------------------------------+" << endl;
	cout << "|                   1. Wejdz do gry                   |" << endl;
	cout << "+-----------------------------------------------------+" << endl;
	cout << "|                   2. O grze                         |" << endl;
	cout << "+-----------------------------------------------------+" << endl;
	cout << "|                   3. Wyjdz z gry                    |" << endl;
	cout << "+-----------------------------------------------------+" << endl;

	cin >> wybor;
	switch (wybor)
	{
	case 1:
		wybierzPostac();
		break;
	case 2:
		oGrze();
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "Zly wybor. Sprobuj jeszcze raz";
		Sleep(1000);
		Welcome();
		break;
	}

}
void oGrze()
{
	system("cls");
	cout << "+====================================+" << endl;
	cout << "|               O GRZE               |"<<endl;
	cout << "+====================================+" << endl;
	cout << "\nJestes czlonkiem wyszkolonej zalogi specjalnej, ktora zostala wyslana na Marsa.\nNiestety nie wszystko poszlo zgodnie z planem...\n";
	cout << "Wasz statek rozbija sie, a ty jako jedyny jakims cudem przezyles.\n";
	cout << "Teraz aby wrocic na Ziemie, musisz naprawic statek. Na twoje szczescie znajdujesz opuszczona baze z generatorem tlenu i nasionami\n";
	cout << "W miedzy czasie szukajac surowcow aby stworzyc nowe czesci do statku, musisz walczyc o przetrwanie na obcej planecie.\nPowodzenia\n\n";
	cout << "+============================================================================================+" << endl;
	cout << "| Kliknij 1 aby wrocic do ekranu glownego, lub jakikolwiek inny klawisz aby wyjsc z programu |" << endl;
	cout << "+============================================================================================+" << endl;
	cin >> wybor;
	if (wybor == 1)
	{
		system("cls");
		Welcome();
	}
	else
	{
		cin.get();
	}

}
void GUI()
{

	char choice = getchar();

	system("cls");
	WygranaPrzegrana();
	rysowanie_mapy();

	
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc, 5);
	cout << "+====================";setColor(13);cout << "INFO O GRACZU DZIEN: " << dni;resetColor();cout << "=========================+" << "+======================";setColor(13);cout << "CELE";resetColor();cout << "====================+" << endl;
	cout << "| ";setColor(13);cout << "HP: " << HP << "/" << limitHP << " O2: " << O2 << "/" << limitO2 << " GLOD: " << glod << "/" << limitG << " STAMINA: " << stamina << "/" << limitS << " KLASA: " << klasa;resetColor();cout << "  |" << " |";setColor(13);cout << " Aby wygrac stworz 2 Silniki, 4 Sciany oraz  ";resetColor();cout << " |" << endl;
	cout << "| ";setColor(13);cout << "Sila Ataku: " << graczAtak;resetColor();cout << "                                                    |" << " |";setColor(13);cout << " zdobadz 32 Krysztaly Mocy.";resetColor();cout << "                   |" << endl;
	cout << "+===================================================================+" << "| ";setColor(13);cout << "Craftingi:                                ";resetColor();cout << "   |" << endl;
	cout << "+==========================";setColor(13);cout << "EKWIPUNEK " << sumaSurowcow << "/" << pojemnoscEkwipunku;resetColor();cout << "=========================+" << "|";setColor(13);cout << " 1 Silnik - 20 stali, 20 miedzi, 5 krysztalow.";resetColor();cout << "|" << endl;
	cout << "| ";setColor(13);cout << "NasionaMarchewki: " << nasionaMarchewki << "    KosmicznaMarchew : " << Marchewki << "   MiesoKosmity : " << MiesoKosmity;resetColor();cout << "  |" << "  | ";setColor(13);cout << "1 Sciana = 10 stali, 10 miedzi";resetColor();cout << "               |" << endl;
	cout << "| ";setColor(13);cout << "  Stal: " << Stal << "                     Miedz : " << Miedz << "             Zelazo : " << Zelazo;resetColor();cout << " |" << "  | ";setColor(13);cout << "1 Stal = 5 zelaza";resetColor();cout << "                            |" << endl;
	cout << "| ";setColor(13);cout << "SilnikStatkuKosmicznego: " << Silnik << "   ScianaStatku: " << Sciana << "  KrysztalMocy: " << KrysztalMocy;resetColor();cout << "    |" << " +==============================================+" << endl;
	cout << "+===================================================================+" << endl;
	cout << "+================================================";setColor(13);cout << "KLIKNIJ ABY WYKONAC AKCJE";resetColor();cout << "===========================================+" << endl;
	cout << "| ";setColor(13);cout << " Z - Idz do kopalni  |  X - Idz do bazy  |  C - Walcz z kosmitami  |  V - Stworz przedmiot  |  Q - Zasadz marchew";resetColor();cout << "  | " << endl;
	cout << "+====================================================================================================================+" << endl;
	cout << "| ";setColor(13);cout << "                                    | R - Wyjdz z gry | F - Ulepsz sile ataku |                          ";resetColor();cout << "  |" << endl;
	cout << "+====================================================================================================================+" << endl;
	cout << "+====================================================";setColor(13);cout << "CZAT AKCJI";resetColor();cout << "=====================================================+" << endl;
	setColor(13);
	cout << "|";
	cin >> choice;

	switch (choice)
	{
	case 122:
	case 90:
		kopalnia();
		break;
	case 120:
	case 88:
		baza();
		break;
	case 99:
	case 67:
		walka();
		break;
	case 118:
	case 86:
		craft();
		break;
	case 113:
	case 81:
		sadzenie();
		break;
	case 114:
	case 82:
		exit(0);
		break;
	case 102:
	case 70:
		ulepsz();
	default:
		cout << "Nieobslugiwany przycisk";
		GUI();
		break;
	}
	
	
}

void rysowanie_mapy()
{
	
	char mapa[10][40] = {
		{219,219,219,219,219,2,177,177,219,219,219,219,219,219,219,219,219,219,219,30,219,219,219,219,219,219,177,177,219,65,219,219,219,219,219,219,219,219,219,30},
		{219,219,219,219,219,219,177,219,219,219,219,219,219,219,219,219,219,30,30,30,219,219,219,219,219,219,177,219,219,219,219,219,219,219,219,219,219,30,30,30},
		{30,30,30,219,219,219,177,177,177,177,219,219,219,219,219,219,219,219,30,30,30,30,30,219,219,219,177,177,177,177,219,219,219,219,219,219,219,219,30,30},
		{30,30,30,219,219,219,219,219,219,177,219,219,219,219,219,219,219,219,219,219,30,30,30,219,219,219,219,219,219,177,219,219,219,219,219,219,219,219,219,219},
		{30,219,219,219,219,219,219,219,177,177,177,219,219,219,219,219,219,219,219,219,30,219,219,219,219,219,219,219,177,177,177,219,219,219,219,219,219,219,219,219},
		{219,219,177,177,177,177,177,177,177,219,177,177,177,219,219,219,177,177,177,177,177,219,177,177,177,177,177,177,177,219,177,177,177,219,219,219,177,177,177,177},
		{177,177,177,219,219,219,219,219,219,219,219,219,177,177,177,177,177,219,30,30,177,177,177,219,219,219,219,219,219,219,219,219,177,177,177,177,177,219,30,30},
		{30,30,30,219,219,219,219,219,219,219,219,219,219,177,219,219,219,219,30,30,30,30,30,219,219,219,219,219,219,219,219,219,219,177,219,219,219,219,30,30},
		{30,30,30,219,219,219,219,219,219,219,219,219,177,177,219,219,219,30,30,30,30,30,30,219,219,219,219,219,219,219,127,127,177,177,219,219,219,30,30,30},
		{30,30,219,219,219,219,219,219,219,219,219,219,177,207,207,219,30,30,30,30,30,30,219,219,219,219,219,219,219,219,127,127,177,219,219,219,30,30,30,30},
	};
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 40; ++j) {
			switch (mapa[i][j])
			{
			case 30: //góry
				setColor(196);
				break;
			case 65: //rakieta
				setColor(192);
				break;
			case 127: //baza
				setColor(192);
				break;
			case 207: //kopalnia
				setColor(192);
				break;
			case 2: //kosmita
				setColor(192);
				break;
			default: //podloze
				setColor(12);
				break;
			}
			cout << mapa[i][j];
			

		}
		resetColor();
		cout << endl;
	}

}

void kopalnia()
{
	cout << "| Co chcesz wydobyc?" << endl;
	cout << "| 1. Zelazo" << endl;
	cout << "| 2. Miedz" << endl;
	cout << "| 3. Wroc do menu gry" << endl;
	cin >> wybor;
	if (wybor == 1)
	{
		cout << "| Wydobywasz zelazo..." << endl;
		cout << "| +3 zelaza  -2 staminy -2 glodu -1 tlenu" << endl;
		Zelazo += 3;
		stamina -= 2;
		glod -= 2;
		O2 -= 1;
		Sleep(1000);
		GUI();
	}
	else if (wybor == 2)
	{
		cout << "| Wydobywasz miedz..." << endl;
		cout << "| +2 miedzi -1 staminy -1 glodu -1 tlenu" << endl;
		Miedz += 2;
		stamina -= 1;
		glod -= 1;
		O2 -= 1;
		Sleep(1000);
		GUI();
	}
	else if (wybor == 3)
	{
		GUI();
	}
	else
	{
		cout << "Nieznana akcja" << endl;
		Sleep(500);
		GUI();
	}
	
}
void baza()
{
	int wybor1;
	cout << "| Jestes w bazie, wybierz co chcesz zrobic: " << endl;
	cout << "| 1. Idz spac - pelne naladowanie staminy." << endl;
	cout << "| 2. Naladuj O2 - koszt 2 KrysztalyMocy." << endl;
	cout << "| 3. Zjedz cos." << endl;
	cout << "| 4. Wroc do menu glownego." << endl;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
		cout << "| amirmir, zaraz bedzie nowy dzien" << endl;
		dni++;
		stamina = limitS;
		Sleep(2000);
		GUI();
		break;
	case 2:
		if (KrysztalMocy >= 2)
		{
			O2 = limitO2;
			KrysztalMocy -= 2;
			cout << "| Tlen naladowany na 100%" << endl;
			Sleep(1000);
			GUI();
		}
		else
		{
			cout << "| Przykro mi, nie masz wystarczajacej ilosci KrysztalowMocy" << endl;
			Sleep(1000);
			GUI();
		}
		break;
	case 3:
		cout << "| Wybierz co chcesz zjesc: \n| 1. KosmicznaMarchewka(+1 glod, +1 HP) \n| 2. MiesoKosmity(+1 glod, +1 stamina): " << endl;
		cin >> wybor1;
		if (wybor1 == 1)
		{
			if (Marchewki > 0)
			{
				if (HP < limitHP && glod < limitG)
				{
					HP += 1;
					glod += 1;
					cout << "| Zjadles MiesoKosmity. +1 stamina +1 glod" << endl;
					Sleep(1000);
					GUI();
					MiesoKosmity--;
				}
				else if (HP == limitHP && glod < limitG)
				{
					glod += 1;
					cout << "| Zjadles MiesoKosmity ale osiagnieto limit HP. + 1 glod" << endl;
					Sleep(1000);
					GUI();
					MiesoKosmity--;
				}
				else if (HP < limitHP && glod == limitG)
				{
					stamina += 1;
					cout << "| Zjadles MiesoKosmity ale osiagnieto limit glodu. + 1 HP" << endl;
					Sleep(1000);
					GUI();
					MiesoKosmity--;
				}
				else
				{
					cout << "| Osiagnieto limit HP i glodu. Nie mozesz wiecej zjesc." << endl;
					Sleep(1000);
					GUI();
				}
			}
			else
			{
				cout << "| Nie masz wystarczajaco marchewek." << endl;
				Sleep(1000);
				GUI();
			}
		}
		else if (wybor1 == 2)
		{
			if (MiesoKosmity > 0)
			{
				if (stamina < limitS && glod < limitG)
				{
					stamina += 1;
					glod += 1;
					cout << "| Zjadles MiesoKosmity. +1 stamina +1 glod" << endl;
					Sleep(1000);
					GUI();
					MiesoKosmity--;
				}
				else if (stamina == limitS && glod < limitG)
				{
					glod += 1;
					cout << "| Zjadles MiesoKosmity ale osiagnieto limit staminy. + 1 glod" << endl;
					Sleep(1000);
					GUI();
					MiesoKosmity--;
				}
				else if (stamina < limitS && glod == limitG)
				{
					stamina += 1;
					cout << "| Zjadles MiesoKosmity ale osiagnieto limit glodu. + 1 stamina" << endl;
					Sleep(1000);
					GUI();
					MiesoKosmity--;
				}
				else
				{
					cout << "| Osiagnieto limit staminy i glodu. Nie mozesz wiecej zjesc." << endl;
					Sleep(1000);
					GUI();
				}


			}
			else
			{
				cout << "| Nie masz wystarczajaco MiesaKosmity." << endl;
				Sleep(1000);
				GUI();
			}
		}
		else
		{
			cin.get();
			GUI();
		}
		break;
	case 4:
		GUI();
		break;
	default:
		GUI();
		break;
	}

}


void walka()
{


	int kosmitaHP = 15;
	int kosmitaAtak = 5;


	int graczHP = HP;
	


	cout << "| Spotkales kosmite! Czy chcesz stoczyc walke? Bedzie cie kosztowac 5 staminy i 3 tlenu \n| (1 - Tak, 2 - Wroc do menu): ";
	cin >> wybor;

	if (wybor == 1)
	{

		while (graczHP > 0 && kosmitaHP > 0)
		{

			kosmitaHP -= graczAtak;
			cout << "| Zadano " << graczAtak << " obrazen kosmicie. Pozostale HP kosmity: " << kosmitaHP << endl;
			Sleep(1000);

			if (rand() % 100 < 50)
			{

				graczHP -= kosmitaAtak;
				cout << "| Kosmita zadal " << kosmitaAtak << " obrazen. Pozostale HP gracza: " << graczHP << endl;
				Sleep(1000);
			}
			else
			{
				cout << "| Dobry unik! Kosmita nietrafil." << endl;
				Sleep(1000);
			}
		}


		if (graczHP > 0)
		{
			cout << "| Pokonales kosmite! Otrzymujesz: " << endl;
			int drop = rand() % 100;
			if (drop < 50) {
				MiesoKosmity += 1; cout << "| x1 MiesoKosmity, x1 KrysztalMocy" << endl;
				KrysztalMocy += 1;
				stamina -= 5;
				O2 -= 3;
				HP -= 3;
				Sleep(1000);
				GUI();
			}
			else
			{
				MiesoKosmity += 2; cout << "| x2 MiesoKosmity, x2 KrysztalMocy" << endl;
				KrysztalMocy += 1;
				KrysztalMocy += 2;
				stamina -= 5;
				O2 -= 3;
				HP -= 3;
				Sleep(1000);
				GUI();
			}
		}
		else
		{
			cout << "| Przegrales walke z kosmita. Tracisz 7 HP." << endl;
			HP -= 7;
			Sleep(1000);
			GUI();
		}
	}
	else
	{
		cout << "| Wracasz do lobby." << endl;
		Sleep(500);
		GUI();
	}



}
void craft()
{
	cout << "| Wybierz przedmiot ktory chcesz stworzyc: " << endl;
	cout << "| 1. Silnik Statku Kosmicznego" << endl;
	cout << "| 2. Sciana" << endl;
	cout << "| 3. Stal" << endl;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
		if (Stal >= 20 && Miedz >= 20 && KrysztalMocy >= 5)
		{
			cout << "| Udalo Ci sie stworzyc silnik!!" << endl;
			Silnik += 1;
			Sleep(1000);
			GUI();
		}
		else
		{
			cout << "| Niewystarczajaca ilosc materialow potrzebnych do stworzenia." << endl;
			Sleep(1000);
			GUI();
		}
		break;
	case 2:
		if (Stal >= 10 && Miedz >= 10)
		{
			cout << "| Udalo Ci sie stworzyc sciane!!" << endl;
			Sciana += 1;
			Sleep(1000);
			GUI();
		}
		else
		{
			cout << "| Niewystarczajaca ilosc materialow potrzebnych do stworzenia." << endl;
			Sleep(1000);
			GUI();
		}
		break;
	case 3:
		if (Zelazo >= 5)
		{
			cout << "| Udalo Ci sie stworzyc x1 stal!!" << endl;
			Stal += 1;
			Sleep(1000);
			GUI();
		}
		else
		{
			cout << "| Niewystarczajaca ilosc materialow potrzebnych do stworzenia." << endl;
			Sleep(1000);
			GUI();
		}
		break;
	default:
		GUI();
		break;
	}

}
void WygranaPrzegrana() {
	if (HP <= 0 || O2 <= 0 || stamina <= 0 || glod <= 0) {
		cout << "+=====================================================+" << endl;
		cout << "|                  Koniec Gry!                        |" << endl;
		cout << "+=====================================================+" << endl;
		cout << "| Przezyles " << dni << " dni                                     |" << endl;
		cout << "| Niestety, Twoje zdrowie, poziom tlenu, glodu        |" << endl;
		cout << "| lub stamina spadly do zera.                         |" << endl;
		cout << "|                  Przegrales...                      |" << endl;
		cout << "+=====================================================+" << endl;
		cin.get();
		exit(0);
	}
	else if (Silnik >= 2 && Sciana >= 4 && KrysztalMocy >= 32) {
		cout << "+=====================================================+" << endl;
		cout << "|                  Koniec Gry                         |" << endl;
		cout << "+=====================================================+" << endl;
		cout << "| Spedziles na Marsie " << dni << " dni                      |" << endl;
		cout << "| Brawo! Udało Ci się spełnić warunki końcowe gry.    |" << endl;
		cout << "| Posiadasz 2 silniki, 4 ściany i 32 Kryształy Mocy.  |" << endl;
		cout << "|                 Wygrałeś grę                        |" << endl;
		cout << "+=====================================================+" << endl;
		cin.get();
		exit(0);
	}
}
void ulepsz()
{
	int wyborU;
	cout << "Koszt ulepszenia sily ataku o 1 to 15 miedzi i 5 marchewek" << endl;
	cout << "(1. Ulepsz 2. Wroc do menu)" << endl;
	cin >> wyborU;
	switch (wyborU)
	{
	case 1:
		if (Miedz >= 15 && nasionaMarchewki >= 5)
		{
			cout << "Ulepszasz sile ataku..." << endl;
			graczAtak += 1;
			Miedz -= 15;
			nasionaMarchewki -= 5;
			cout << "Sila ataku ulepszona o 1!" << endl;
			Sleep(1000);
			GUI();
		}
		else
		{
			cout << "Niewystarczajaca ilosc materialow potrzebnych do ulepszenia." << endl;
			Sleep(1000);
			GUI();
		}
		break;
	case 2:
		GUI();
		break;
	default:
		GUI();
		break;
	}
}








