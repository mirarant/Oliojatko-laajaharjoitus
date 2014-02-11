/*
 * Jasen.cpp
 *
 *  Created on: 18.12.2013
 *      Author: rantala6
 */

#include "Jasen.h"

Jasen::Jasen(std::string etunimi, std::string sukunimi, int ika) {
	setEtunimi(etunimi);
	setSukunimi(sukunimi);
	setIka(ika);
}

Jasen::~Jasen() {

	//Debug tulostus
	std::cout << "Poistetaan Jasen" << std::endl;
}

//getteri
const std::string& Jasen::getEtunimi() const {
	return etunimi;
}

//setteri
void Jasen::setEtunimi(const std::string& etunimi) {
	this->etunimi = etunimi;
}

//getteri
int Jasen::getIka() const {
	return ika;
}

//setteri
void Jasen::setIka(int ika) {
	this->ika = ika;
}

//getteri
const std::string& Jasen::getSukunimi() const {
	return sukunimi;
}

//setteri
void Jasen::setSukunimi(const std::string& sukunimi) {
	this->sukunimi = sukunimi;
}

//Tulostaa jäsenen etu- ja sukunimen sekä iän
void Jasen::tulostaJasen() {
	std::cout << "Nimi: " << getEtunimi() << " " << getSukunimi() << "\n" << "Ikä: " << getIka() << std::endl;
}

