// File:		polygon.h
// Description:	This file contains the definition of the abstract base class "Polygon."
// Author:	  	Emma Smith
// Course:  	CS 3350, Fall 2026

#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <string>

using namespace std;

class Polygon {  // Abstract base class
protected:
	int side1;
public:
	Polygon(int side1 = 0) { this->side1 = side1; }  // Overloaded constructor with implementation
	virtual ~Polygon() {}  // Virtual destructor
	virtual double area() const = 0;  // pure virtual area function
	virtual double perimeter() const = 0;  // pure virtual perimeter function
	virtual string getName() const = 0;  // pure virtual getName function
};

#endif
