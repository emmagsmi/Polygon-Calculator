// File:		shapes.cpp
// Description:	This file contains the implementation of all the derived classes.
// Author:	  	Emma Smith
// Course:  	CS 3350, Fall 2026

#include "shapes.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double M_PI = 3.14159265358979323846; // Value of pi

// Triangle class overloaded constructor, initializes side 1, side 2, and side 3
Triangle::Triangle(int side1, int side2, int side3) : Polygon(side1) {  // calls base class constructor to initialize side 1
	this->side2 = side2;
	this->side3 = side3;
}

// This function computes the area of a triangle using the semiperimeter
double Triangle::area() const {
	double a = static_cast<double>(side1);  // a = side 1
	double b = static_cast<double>(side2);  // b = side 2
	double c = static_cast<double>(side3);  // c = side 3
	double s;  // semiperimeter
	double area;

	s = (a + b + c) / 2.0;  // calculate semiperimeter

	area = s * (s - a) * (s - b) * (s - c);  // use semiperimeter to compute area

	return sqrt(area);
}

// This function computes the perimeter of a triangle
double Triangle::perimeter() const {
	return static_cast<double>(side1) + side2 + side3;
}

// This function computes the area of an isosceles triangle
double IsoscelesTriangle::area() const {
	double base = static_cast<double>(side1);  // side 1 = base
	double equalSide = static_cast<double>(side2);  // side 2 = equal side
	double area;

	area = (base / 4.0) * (sqrt((4 * (equalSide * equalSide)) - (base * base)));  // calculate area

	return area;
}

// This function computes the perimeter of an isosceles triangle
double IsoscelesTriangle::perimeter() const {
	return static_cast<double>(side1) + (2 * side2);
}

// This function computes the area of an equilateral triangle
double EquilateralTriangle::area() const {
	double area;

	area = (sqrt(3.0) / 4.0) * static_cast<double>(side1) * static_cast<double>(side1);  // calculate area

	return area;
}

// This function computes the perimeter of an equilateral triangle
double EquilateralTriangle::perimeter() const {
	return static_cast<double>(side1) * 3.0;
}

// Quadrilateral class overloaded constructor, initializes side 1, side 2, side 3, side 4, and angle
Quadrilateral::Quadrilateral(int side1, int side2, int side3, int side4, int angle) : Polygon(side1) {  // calls on base class constructor to initialize side 1
	this->side2 = side2;
	this->side3 = side3;
	this->side4 = side4;
	this->angle = angle;
}

// This function computes the area of a quadrilateral using Heron's formula in conjunction with SAS triangle area computation
double Quadrilateral::area() const {
	double a = static_cast<double>(side1);  // a = side 1
	double b = static_cast<double>(side2);  // b = side 2
	double c = static_cast<double>(side3);  // c = side 3
	double d = static_cast<double>(side4);  // d = side 4
	double s;  // semiperimeter
	double diagonal;
	double triangle1Area;
	double triangle2Area;
	double totalArea;
	double angleInRadians;

	angleInRadians = static_cast<double>(angle) * (M_PI / 180.0);  // convert the angle from degrees to radians

	triangle1Area = (1.0 / 2.0) * a * b * sin(angleInRadians);  // calculate the area of triangle 1

	diagonal = (a * a) + (b * b) - (2.0 * a * b * (cos(angleInRadians)));
	diagonal = sqrt(diagonal);  // find the length of the diagonal

	s = (c + d + diagonal) / 2.0;  // calculate the semiperimeter

	triangle2Area = s * (s - c) * (s - d) * (s - diagonal);
	triangle2Area = sqrt(triangle2Area);  // use the semiperimeter to calculate the area of triangle 2

	totalArea = triangle1Area + triangle2Area;  // add the areas of the two triangles together

	return totalArea;
}

// This function computes the perimeter of a quadrilateral
double Quadrilateral::perimeter() const {
	return static_cast<double>(side1) + side2 + side3 + side4;
}

// This function computes the area of a rectangle
double Rectangle::area() const {
	return static_cast<double>(side1) * side2;
}

// This function computes the perimeter of a rectangle
double Rectangle::perimeter() const {
	return (static_cast<double>(side1) * 2) + (side2 * 2);
}

// This function computes the area of a square
double Square::area() const {
	return static_cast<double>(side1) * side1;
}

// This function computes the perimeter of a square
double Square::perimeter() const {
	return static_cast<double>(side1) * 4;
}

// This function computes the area of a pentagon
double Pentagon::area() const {
	double area;

	area = (5.0 / 4.0) * (static_cast<double>(side1) * side1) * tan((3 * M_PI) / 10.0);  // calculate the area

	return area;
}

// This function computes the perimeter of a pentagon
double Pentagon::perimeter() const {
	return static_cast<double>(side1) * 5.0;
}

// This function computes the area of a hexagon
double Hexagon::area() const {
	double area;

	area = (3.0 / 2.0) * sqrt(3) * (static_cast<double>(side1) * side1);  // calculate the area

	return area;
}

// This function computes the perimeter of a hexagon
double Hexagon::perimeter() const {
	return static_cast<double>(side1) * 6.0;
}

// This function computes the area of an octagon
double Octagon::area() const {
	double area;

	area = 2.0 * (static_cast<double>(side1) * side1) * (1.0 / tan(M_PI / 8.0));  // calculate the area

	return area;
}

// This function computes the perimeter of an octagon
double Octagon::perimeter() const {
	return static_cast<double>(side1) * 8.0;
}