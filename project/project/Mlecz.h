#ifndef MLECZ_H
#define MLECZ_H
#include "Roslina.h"

class Mlecz : public Roslina {
public:
	Mlecz(Swiat&);
	Mlecz(Swiat&, int, int);
	void rozmnazanie() override;
	void akcja() override;
};

#endif