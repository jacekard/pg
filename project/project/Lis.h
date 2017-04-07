#ifndef LIS_H
#define LIS_H
#include "Zwierze.h"

class Lis : public Zwierze {
public:
	Lis(Swiat&);
	Lis(Swiat&, int, int);
	void akcja();
	void rozmnazanie() override;
};

#endif