/*
 * VIPJasen.cpp
 *
 *  Created on: 18.12.2013
 *      Author: rantala6
 */

#include "VIPJasen.h"

VIPJasen::VIPJasen(std::string etunimi, std::string sukunimi, int ika) :
	Jasen(etunimi, sukunimi, ika)
{
	setVip(true);

}

VIPJasen::~VIPJasen() {

	//Debug tulostus
	std::cout << "Poistetaan VIPJasen" << std::endl;
}

//getteri
bool VIPJasen::isVip() const {
	return VIP;
}

//setteri
void VIPJasen::setVip(bool vip) {
	this->VIP = vip;
}

//Tulostaa VIP jäsenen tiedot, käyttää yläluokan tulosta funktiota
void VIPJasen::tulostaJasen() {
	//std::cout << "Nimi: " << getEtunimi() << " " << getSukunimi() << "\n" << "Ikä: " << getIka() << std::endl;
	Jasen::tulostaJasen();
	std::cout << "VIP status" << std::endl;
}
