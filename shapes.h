// File:		shapes.h
// Description:	This file contains the definitions of all the derived classes.
// Author:	  	Emma Smith
// Course:  	CS 3350, Fall 2026

#ifndef SHAPES_H
#define SHAPES_H

#include "polygon.h"
#include <iostream>
#include <string>

using namespace std;

// Triangle derived class
class Triangle : public Polygon {
protected:
	int side2;
	int side3;
public:
	Triangle(int side1 = 0, int side2 = 0, int side3 = 0);  // Overloaded constructor
	double area() const override;
	double perimeter() const override;
	string getName() const override { return "Triangle"; }  // Return the polygon name as "Triangle"
};

// Isosceles Triangle derived class
class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int side1 = 0, int side2 = 0) : Triangle(side1, side2, side2) {}  // Overloaded constructor, calls on parent class for implementation
	double area() const override;
	double perimeter() const override;
	string getName() const override { return "Isosceles Triangle"; }  // Return the polygon name as "Isosceles Triangle"
};

// Equilateral Triangle derived class
class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int side1 = 0) : Triangle(side1, side1, side1) {}  // Overloaded constructor, calls on parent class for implementation
	double area() const override;
	double perimeter() const override;
	string getName() const override { return "Equilateral Triangle"; }  // Return the polygon name as "Equilateral Triangle"
};

// Quadrilateral derived class
class Quadrilateral : public Polygon {
protected:
	int side2;
	int side3;
	int side4;
	int angle;
public:
	Quadrilateral(int side1 = 0, int side2 = 0, int side3 = 0, int side4 = 0, int angle = 0);  // Overloaded constructor
	double area() const override;
	double perimeter() const override;
	string getName() const override { return "Quadrilateral"; }  // Return polygon name as "Quadrilateral"
};

// Rectangle derived class
class Rectangle : public Quadrilateral {
public:
	Rectangle(int side1 = 0, int side2 = 0, int angle = 0) : Quadrilateral(side1, side2, side1, side2, angle) {}  // Overloaded constructor, calls on parent class for implementation
	double area() const override;
	double perimeter() const override;
	string getName() const override { return "Rectangle"; }  // Return polygon name as "Rectangle"
};

// Square derived class
class Square : public Rectangle {
public:
	Square(int side1 = 0, int angle = 0) : Rectangle(side1, side1, angle) {}  // Overloaded constructor, calls on parent class for implementation
	double area() const override;
	double perimeter() const override;
	string getName() const override { return "Square"; }  // Return polygon name as "Square"
};

// Pentagon derived class
class Pentagon : public Polygon {
public:
	Pentagon(int side1 = 0) : Polygon(side1) {}  // Overloaded constructor, calls on base class constructor for implementation
	double area() const override;
	double perimeter() const override;
	string getName() const override { return "Pentagon"; }  // Return polygon name as "Pentagon"
};

// Hexagon derived class
class Hexagon : public Polygon {
public:
	Hexagon(int side1 = 0) : Polygon(side1) {}  // Overloaded constructor, calls on base class constructor for implementation
	double area() const override;
	double perimeter() const override;
	string getName() const override { return "Hexagon"; }  // Return polygon name as "Hexagon"
};

// Octagon derived class
class Octagon : public Polygon {
public:
	Octagon(int side1 = 0) : Polygon(side1) {}  // Overloaded constructor, calls on base class constructor for implementation
	double area() const override;
	double perimeter() const override;
	string getName() const override { return "Octagon"; }  // Return polygon name as "Octagon"
};

#endif
