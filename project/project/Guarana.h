#ifndef GUARANA_H
#define GUARANA_H
#include "Roslina.h"

class Guarana : public Roslina {
public:
	Guarana(Swiat&);
	Guarana(Swiat&, int, int);
	~Guarana();
	void rozmnazanie() override;
	void akcja() override;
};

#endif