#pragma once
//
#include "windows.h"

#include <iostream>
#include <random>
#include <conio.h>
#include<stdio.h>


using namespace std;
//
#define WIDTH 40
#define HEIGHT 20
#define OFFY 1
#define OFFX 2

//
struct position{
	int x;
	int y;
};

random_device gen;
uniform_int_distribution<int> move_dist(1,100);
uniform_int_distribution<int> x_dist(1, 39);
uniform_int_distribution<int> y_dist(1, 19);
//

#include "Organizm.h"
#include "Swiat.h"
#include "Roslina.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Czlowiek.h"
//


//
