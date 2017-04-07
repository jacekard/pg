#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class point {
public:
	int x;
	int y;
	point() : x(0), y(0) {};

};

//void operator=(point& other) {
//	this->x += other.x;
//	this->y += other.y;
//}

//virtual void Wypisz(ostream& out) const = 0;
//friend ostream& operator<<(ostream& os, const Swiat& swiat);

//ostream& operator<<(ostream& os, const Swiat& swiat) {
//	swiat.Wypisz(os);
//	return os;
//}
#endif