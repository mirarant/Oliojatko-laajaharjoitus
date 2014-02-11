/*
 * VIPJasen.h
 *
 *  Created on: 18.12.2013
 *      Author: rantala6
 */

#ifndef VIPJASEN_H_
#define VIPJASEN_H_

#include "Jasen.h"

class VIPJasen: public Jasen {
public:
	VIPJasen(std::string, std::string, int);
	virtual ~VIPJasen();

	//getteri ja setteri
	bool isVip() const;
	void setVip(bool vip);

	//Tulostaa jäsenen tiedot
	virtual void tulostaJasen();

private:
	//VIP status
	bool VIP;
};

#endif /* VIPJASEN_H_ */
