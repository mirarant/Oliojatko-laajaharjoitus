/*
 * Luettelo.cpp
 *
 *  Created on: 17.1.2014
 *      Author: rantala6
 */

#include "Luettelo.h"

Luettelo::Luettelo() {

}

Luettelo::~Luettelo() {

	//Debug tulostus
	std::cout << "Tuhottiin jäsenluettelo." << std::endl;

}

//Lisää jäsenen vektoriin
void Luettelo::lisaa_unique_ptr(std::unique_ptr<Jasen> jsn) {

	//käytetään std::move koska unique_ptr voi vain siirtää, ei kopioida
	jvektori.push_back(std::move(jsn));
}

//Tulostaa kaikki vektorin jäsenet
void Luettelo::tulostaVektori() {

	std::cout << "Tulostetaan jäsenluettelo" << std::endl;

	for(auto ite = jvektori.begin(); ite != jvektori.end(); ite++) {
		(*ite)->tulostaJasen();
	}
}

//Muuttaa tietyn jäsenen tietoja
//Käy lävitse koko vektorin ja etsii etu- ja sukunimen perusteella
//Jos löydetään sopiva jäsen, pyydetään uudet tiedot jotka tallennetaan
void Luettelo::muutaJasen(std::string etunimi, std::string sukunimi) {

	for(auto ite = jvektori.begin(); ite != jvektori.end(); ite++) {
		if(etunimi.compare((*ite)->getEtunimi()) == 0) {
			if(sukunimi.compare((*ite)->getSukunimi()) == 0) {
				std::cout << "Löytyi samanniminen jäsen." << std::endl;

				std::string etutmp, sukutmp;
				int ikatmp;

				std::cout << "Anna uusi etunimi: ";
				std::cin >> etutmp;
				(*ite)->setEtunimi(etutmp);

				std::cout << "Anna uusi sukunimi: ";
				std::cin >> sukutmp;
				(*ite)->setSukunimi(sukutmp);

				std::cout << "Anna uusi ikä: ";
				std::cin >> ikatmp;
				(*ite)->setIka(ikatmp);

				//Debug tulostus
				if( typeid(**ite) != typeid(VIPJasen))
					std::cout << "Ei ollut VIP" << std::endl;
			}
		}
	}
}

//Poistaa tietyn jäsenen
//Käy lävitse koko vektorin ja etsii etu- ja sukunimen perusteella
//Jos löydetään sopiva jäsen niin se poistetaan
void Luettelo::poistaJasen(std::string etunimi, std::string sukunimi) {

	std::vector<std::unique_ptr<Jasen> >::iterator apuIte;
	bool tark = false;

	for(auto ite = jvektori.begin(); ite != jvektori.end(); ite++) {
		if(etunimi.compare((*ite)->getEtunimi()) == 0) {
			if(sukunimi.compare((*ite)->getSukunimi()) == 0) {
				std::cout << "Löytyi samanniminen jäsen." << std::endl;

				//Siirrettään pointterin omistus apuiteraattorille
				apuIte = std::move(ite);
				//Tällä kerrotaan että on jotain poistettavaa
				tark = true;
			}
		}
	}
	//Varsinainen poisto tapahtuu tässä
	if(tark)
		jvektori.erase(apuIte);
}

//Getteri vektorille
const std::vector<std::unique_ptr<Jasen> > & Luettelo::getJvektori() const {

	return jvektori;
}

