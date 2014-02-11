/*
 * Jasen.h
 *
 *  Created on: 18.12.2013
 *      Author: rantala6
 */

#ifndef JASEN_H_
#define JASEN_H_

#include <iostream>

class Jasen {
public:
	Jasen(std::string, std::string, int);
	virtual ~Jasen();

	//getteri ja setteri
	const std::string& getEtunimi() const;
	void setEtunimi(const std::string& etunimi);

	//getteri ja setteri
	int getIka() const;
	void setIka(int ika);

	//getteri ja setteri
	const std::string& getSukunimi() const;
	void setSukunimi(const std::string& sukunimi);

	//Tulostaa jäsenen tiedot
	virtual void tulostaJasen();

private:
	std::string etunimi;
	std::string sukunimi;
	int ika;
};

#endif /* JASEN_H_ */
