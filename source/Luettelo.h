/*
 * Luettelo.h
 *
 *  Created on: 17.1.2014
 *      Author: rantala6
 */

#ifndef LUETTELO_H_
#define LUETTELO_H_

#include <iostream>
#include <vector>
#include <memory>

#include "Jasen.h"
#include "VIPJasen.h"

class Luettelo {
public:
	Luettelo();
	virtual ~Luettelo();

	//void lisaa_unique_ptr(std::string, std::string, int);
	void lisaa_unique_ptr(std::unique_ptr<Jasen> jsn);

	//Tulostaa vektorin sisällön
	void tulostaVektori();

	//Muuttaa jäsenen tietoja
	void muutaJasen(std::string, std::string);

	//Poistaa jäsenen
	void poistaJasen(std::string, std::string);

	//Vektori getteri
	const std::vector<std::unique_ptr<Jasen> > & getJvektori() const;

private:
	//Jäsenluettelo
	std::vector<std::unique_ptr<Jasen> > jvektori;
};

#endif /* LUETTELO_H_ */
