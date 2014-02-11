/*
 * main.cpp
 *
 *  Created on: 18.12.2013
 *      Author: Mikko Rantala, 224477
 *
 *  	Laajaharjoitustyö, jäsenluettelo
 *
 */

#include <iostream>
#include <limits>
#include <cctype>
#include <memory>

#include "Jasen.h"
#include "VIPJasen.h"
#include "Luettelo.h"

using namespace std;

int main() {

	//Väliaikaisia apumuuttujia
	string etutmp = "", sukutmp = "", status = "";
	int ikatmp = 0;
	//Käytetään valikossa kun päätetään oliko käyttäjän antama arvo ok
	bool valid = false;

	//C++11 smart pointer, automaattinen muistinhallinta
	//delete avainsanaa ei tarvita
	unique_ptr<Luettelo> jasenluettelo(new Luettelo);

	//Switch-case valitsin
	int valinta=9;

	//Päävalikko alkaa tästä
	do {
		cout << "************************************************************" << endl;
		cout << "Valitse jokin seuraavista:" << endl;
		cout << "1. Luo jäsen" << endl;
		cout << "2. Tulosta jäsenet" << endl;
		cout << "3. Muokkaa jäsentä" << endl;
		cout << "4. Poista jäsen" << endl;
		cout << "0. Lopeta ohjelma" << endl;
		cout << "************************************************************" << endl;
		cin >> valinta;

		//Pyyhitään input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch(valinta) {
			//Luodaan jäsen
			case 1:
				//Pyydetään käyttäjältä jäsenen etunimi

				cout << "Anna jäsenen etunimi: ";
				cin >> etutmp;

				//Pyydetään käyttäjältä jäsenen sukunimi

				cout << "Anna jäsenen sukunimi: ";
				cin >> sukutmp;

				//Pyydetään käyttäjältä jäsenen ikä
				//Sisältää virheentarkastuksen, vain numerot hyväksytään
				do {
					cout << "Anna jäsenen ikä: ";
					cin >> ikatmp;
				    if( cin.fail() )
				    {
				        std::cout << "Jäsenen iän täytyy olla numero" << endl ;
				        cin.clear();
				        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				        valid = false;
				    }
				    else
				    {
				    	//Debug tulostus
				        //std::cout << "Ikä oli: " << ikatmp << endl ;
				        valid = true;
				    }
				} while(valid == false);

				//Pyydetään käyttäjältä jäsenen VIP-status
				//Sisältää virheentarkastuksen, vain k tai e hyväksytään
				do {
					cout << "Onko kyseessä VIP-jäsen (k/e): ";
					cin >> status;
					if(!status.compare("k") || !status.compare("e"))
						valid = true;
					else {
						cout << "Ole hyvä ja valitse k/e" << endl;
						valid = false;
					}
				} while(valid == false);

				if(!status.compare("k"))
					jasenluettelo->lisaa_unique_ptr(std::unique_ptr<VIPJasen> (new VIPJasen(etutmp, sukutmp, ikatmp)));
				else if(!status.compare("e"))
					jasenluettelo->lisaa_unique_ptr(std::unique_ptr<Jasen> (new Jasen(etutmp, sukutmp, ikatmp)));

				break;
			//Tulostetaan kaikki jäsenet
			case 2:
				if(jasenluettelo->getJvektori().size())
					jasenluettelo->tulostaVektori();
				else
					cout << "Ei jäseniä luettelossa." << endl;


				break;
			//Muokataan jäsentä
			case 3:
				//Annetaan metodille etu- ja sukunimi
				//Käydään vektoria lävitse kunnes löydetään oikea jäsen
				//Otetaan olio vektorista referenssillä käsittelyyn

				//Pyydetään käyttäjältä jäsenen etunimi
				//Sisältää virheentarkastuksen, vain kirjaimet hyväksytään

				cout << "Anna jäsenen etunimi: ";
				cin >> etutmp;

				cout << "Anna jäsenen sukunimi: ";
				cin >> sukutmp;

				jasenluettelo->muutaJasen(etutmp, sukutmp);

				break;
			//Poistetaan jäsen
			case 4:
				//Annetaan metodille etu- ja sukunimi
				//Käydään vektoria lävitse kunnes löydetään oikea jäsen

				cout << "Anna jäsenen etunimi: ";
				cin >> etutmp;

				cout << "Anna jäsenen sukunimi: ";
				cin >> sukutmp;

				jasenluettelo->poistaJasen(etutmp, sukutmp);

				break;

			default:
				break;
		}

	//Päävalikko loppuu tähän
	}while(valinta != 0);

	return 0;
}


