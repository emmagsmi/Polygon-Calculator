// File:		main.cpp 
// Description:	This file contains the client code and useful functions. It allows the client to create polygon objects,
//              display all shapes created, and display the statistics for all shapes created using a menu.
// Author:	  	Emma Smith
// Course:  	CS 3350, Fall 2026

#include "shapes.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

// Function Prototypes
int getUserChoice();
Polygon* createPolygon(int userChoice);
void showAreaPerimeter(Polygon* polygon);
void displayAllShapes(const vector<Polygon*>& polygons);
void displayStatistics(const vector<Polygon*>& polygons);
bool isNumeric(string userInput);
int convert2Numeric(string userInput);
int getPositiveInteger();
double getLargestArea(const vector<Polygon*>& polygons);
double getAverageArea(const vector<Polygon*>& polygons);
double getAveragePerimeter(const vector<Polygon*>& polygons);


int main() {
	cout << "Hello from .slnx project!\n";

	vector<Polygon*> polygons;  // Vector to store dynamically allocated polygons
	int userChoice;

	userChoice = getUserChoice();  // Get the user's choice from the menu

	while (userChoice != 12) {  // Program runs until the user has chosen to exit
		// If the user has chosen to add a polygon, create the polygon and add it to the vector
		if (userChoice >= 1 && userChoice <= 9) {
			Polygon* polygon = createPolygon(userChoice);

			polygons.push_back(polygon);

			cout << "Polygon created successfully." << endl;

			showAreaPerimeter(polygon);  // Show the area and perimeter of the polygon
		}

		// If the user has chosen to display all shapes, display all shapes in the vector
		else if (userChoice == 10) {
			displayAllShapes(polygons);
		}

		// If the user has chosen to display statistics, display the statistics for all shapes in the vector
		else if (userChoice == 11) {
			displayStatistics(polygons);
		}

		userChoice = getUserChoice();  // Get the user's choice from the menu again
	}

	for (int i = 0; i < polygons.size(); i++) {  // Delete all dynamically allocated polygons in the vector
		delete polygons[i];
	}

	polygons.clear();  // Clear the vector

	return 0;
}

/* Function: getUserChoice
 * Purpose: This function displays a menu, gets the user's choice from input, validates the input, and returns the polygon choice as an integer.
 */
int getUserChoice() {
	string userInput;
	int userChoice;

	// Display the Polygon Calculator menu
	cout << "========================================" << endl;
	cout << "      Polygon Calculator" << endl;
	cout << "========================================" << endl;
	cout << "1. Add Triangle" << endl;
	cout << "2. Add Isosceles Triangle" << endl;
	cout << "3. Add Equilateral Triangle" << endl;
	cout << "4. Add Quadrilateral" << endl;
	cout << "5. Add Rectangle" << endl;
	cout << "6. Add Square" << endl;
	cout << "7. Add Pentagon" << endl;
	cout << "8. Add Hexagon" << endl;
	cout << "9. Add Octagon" << endl;
	cout << "10. Display All Shapes" << endl;
	cout << "11. Display Statistics" << endl;
	cout << "12. Exit" << endl;
	cout << endl;

	// Get the user's choice from input
	cout << "Enter your choice: ";
	getline(cin, userInput);

	// If the user's choice is not a number, display an error message and redisplay the menu
	if (!isNumeric(userInput)) {
		cout << "ERROR: Numeric input is required." << endl;
		cout << endl;
		return getUserChoice();
	}

	userChoice = convert2Numeric(userInput);  // Convert the user's choice to an integer

	// If the user's choice is not in the valid range, display an error message and redisplay the menu
	if (userChoice < 1 || userChoice > 12) {
		cout << "ERROR: Invalid menu option." << endl;
		cout << endl;
		return getUserChoice();
	}
	// If the user's choice is in the valid range, return it
	else {
		return userChoice;
	}
}

/* Function: createPolygon
 * Purpose: This function receives the polygon choice, accepts additional input, validates and dynamically allocates the selected polygon
 */
Polygon* createPolygon(int userChoice) {
	int side1;
	int side2;
	int side3;
	int side4;
	int angle;

	if (userChoice == 1) {  // Triangle
		// Get the validated lengths of the sides of the triangle from the user
		cout << "Triangle: Please provide length of side 1: ";
		side1 = getPositiveInteger();

		cout << "Triangle: Please provide length of side 2: ";
		side2 = getPositiveInteger();

		cout << "Triangle: Please provide length of side 3: ";
		side3 = getPositiveInteger();

		cout << endl;

		return new Triangle(side1, side2, side3);  // Create a new Triangle object
	}

	else if (userChoice == 2) {  // Isosceles Triangle
		// Get the validated lengths of the base and sides of the isosceles triangle from the user
		cout << "Isosceles Triangle: Please provide length of base: ";
		side1 = getPositiveInteger();

		cout << "Isosceles Triangle: Please provide length of sides: ";
		side2 = getPositiveInteger();

		cout << endl;

		return new IsoscelesTriangle(side1, side2);  // Create a new IsoscelesTriangle object
	}

	else if (userChoice == 3) {  // Equilateral Triangle
		// Get the validated length of the sides of the equilateral triangle from the user
		cout << "Equilateral Triangle: Please provide length of sides: ";
		side1 = getPositiveInteger();

		cout << endl;

		return new EquilateralTriangle(side1);  // Create a new EquilateralTriangle object
	}

	else if (userChoice == 4) {  // Quadrilateral
		// Get the validated lengths of the sides and angle of the quadrilateral from the user
		cout << "Quadrilateral: Please provide length of side 1: ";
		side1 = getPositiveInteger();

		cout << "Quadrilateral: Please provide length of side 2: ";
		side2 = getPositiveInteger();

		cout << "Quadrilateral: Please provide length of side 3: ";
		side3 = getPositiveInteger();

		cout << "Quadrilateral: Please provide length of side 4: ";
		side4 = getPositiveInteger();

		cout << "Quadrilateral: Please provide angle between side 1 and side 2: ";
		angle = getPositiveInteger();

		while (angle > 180) {  // Validate that the angle is less than or equal to 180 degrees
			cout << "ERROR: Angle must be less than or equal to 180 degrees. Please try again: ";
			angle = getPositiveInteger();
		}

		cout << endl;

		return new Quadrilateral(side1, side2, side3, side4, angle);  // Create a new Quadrilateral object
	}

	else if (userChoice == 5) {  // Rectangle
		// Get the validated lengths of the sides of the rectangle from the user
		cout << "Rectangle: Please provide length of side 1: ";
		side1 = getPositiveInteger();

		cout << "Rectangle: Please provide length of side 2: ";
		side2 = getPositiveInteger();

		cout << endl;

		return new Rectangle(side1, side2, 90);  // Create a new Rectangle object with angle set to 90 degrees
	}

	else if (userChoice == 6) {  // Square
		// Get the validated length of the side of the square from the user
		cout << "Square: Please provide length of side: ";
		side1 = getPositiveInteger();

		cout << endl;

		return new Square(side1, 90);  // Create a new Square object with angle set to 90 degrees
	}

	else if (userChoice == 7) {  // Pentagon
		// Get the validated length of the side of the pentagon from the user
		cout << "Pentagon: Please provide length of side: ";
		side1 = getPositiveInteger();

		cout << endl;

		return new Pentagon(side1);  // Create a new Pentagon object
	}

	else if (userChoice == 8) {  // Hexagon
		// Get the validated length of the side of the hexagon from the user
		cout << "Hexagon: Please provide length of side: ";
		side1 = getPositiveInteger();

		cout << endl;

		return new Hexagon(side1);  // Create a new Hexagon object
	}

	else if (userChoice == 9) {  // Octagon
		// Get the validated length of the side of the octagon from the user
		cout << "Octagon: Please provide length of side: ";
		side1 = getPositiveInteger();

		cout << endl;

		return new Octagon(side1);  // Create a new Octagon object
	}
}

/* Function: showAreaPerimeter
 * Purpose: This function accepts a pointer to a polygon and calls the area and perimeter functions appropriate to the polygon type.
 */
void showAreaPerimeter(Polygon* polygon) {
	cout << fixed << setprecision(2);  // Set the output to display to two decimal places
	cout << polygon->getName() << endl;  // Display the name of the polygon
	cout << "Area: " << polygon->area() << endl;  // Display the area of the polygon
	cout << "Perimeter: " << polygon->perimeter() << endl;  // Display the perimeter of the polygon
	cout << endl;
}

/* Function: displayAllShapes
 * Purpose: This function all the shapes sorted in the vector.
 */
void displayAllShapes(const vector<Polygon*>& polygons) {
	// Display header
	cout << endl;
	cout << "========================================" << endl;
	cout << "Stored Polygon Objects" << endl;
	cout << "========================================" << endl;

	// If the vector is empty, display a message indicating that no polygons have been stored
	if (polygons.empty()) {
		cout << "No polygons have been stored." << endl;
		cout << endl;
		return;
	}

	// Loop through the vector and display the name, area, and perimeter of each polygon
	for (int i = 0; i < polygons.size(); i++) {
		cout << fixed << setprecision(2);  // Set the output to display two decimal places
		cout << "Shape #" << i + 1 << endl;  // Display the shape number
		cout << "Type: " << polygons[i]->getName() << endl;  // Display the name of the polygon
		cout << "Area: " << polygons[i]->area() << endl;  // Display the area of the polygon
		cout << "Perimeter: " << polygons[i]->perimeter() << endl;  // Display the perimeter of the polygon
		cout << endl;
	}

	cout << "Total shapes stored: " << polygons.size() << endl;  // Display the total number of polygons stored
	cout << endl;
}

/* Function: displayStatistics
 * Purpose: This function displays the total numver of shapes, the largest area, the average area, and the average perimeter of all shapes in the vector.
 */
void displayStatistics(const vector<Polygon*>& polygons) {
	// Display header
	cout << endl;
	cout << "========================================" << endl;
	cout << "Polygon Statistics" << endl;
	cout << "========================================" << endl;

	if (polygons.empty()) {  // If the vector is empty, display a message indicating that no polygons have been stored
		cout << "No polygons have been stored." << endl;
		cout << endl;
		return;
	}

	cout << "Total Shapes: " << polygons.size() << endl;  // Display the total number of polygons stored
	cout << "Largest Area: " << fixed << setprecision(2) << getLargestArea(polygons) << endl;  // Display the area of the polygon with the largest area
	cout << "Average Area: " << fixed << setprecision(2) << getAverageArea(polygons) << endl;  // Display the average area of all polygons stored
	cout << "Average Perimeter: " << fixed << setprecision(2) << getAveragePerimeter(polygons) << endl;  // Display the average perimeter of all polygons stored
	cout << endl;
}

/* Function: isNumeric
 * Purpose: This function returns true if the given string is numeric.
 */
bool isNumeric(string userInput) {
	// If there is no input, return false
	if (userInput.empty()) {
		return false;
	}
	// Check if each index is numeric
	for (int i = 0; i < userInput.length(); i++) {
		if (!isdigit(userInput[i])) {
			// First index can be the negative sign in case of negative numbers
			if ((i == 0) && (userInput[i] == '-')) {
				continue;
			}
			// Return false if not a valid number
			else {
				return false;
			}
		}
	}

	return true;  // Return true if user input is a valid number
}

/* Function: convert2Numeric
 * Purpose: This function returns the integer value contained in the given string.
 */
int convert2Numeric(string userInput) {
	return stoi(userInput);
}

/* Function: getPositiveInteger
 * Purpose: This function returns a positive integer from the user. It is used to validate the input for the polygon sides and angles.
 */
int getPositiveInteger() {
	string input;

	getline(cin, input);  // Get the input from the user

	while (!isNumeric(input) || convert2Numeric(input) <= 0) {
		// Check if input is numeric, output error message if not and prompt the user to try again
		if (!isNumeric(input)) {
			cout << "ERROR: Numeric input is required. Please try again: ";
		}
		// Check if input is a positive integer, output error message if not and prompt the user to try again
		else {
			cout << "ERROR: Positive integer input is required. Please try again: ";
		}

		getline(cin, input);  // Get user input again if not a positive integer
	}

	return convert2Numeric(input);
}

/* Function: getLargestArea
 * Purpose: This function finds and returns the largest area of all polygons in the vector.
 */
double getLargestArea(const vector<Polygon*>& polygons) {
	double largestArea = 0.0;

	// If there are no polygons, return the largest area as 0.0
	if (polygons.empty()) {
		return largestArea;
	}
	// Find the polygon with the largest area
	for (int i = 0; i < polygons.size(); i++) {
		if (polygons[i]->area() > largestArea) {
			largestArea = polygons[i]->area();
		}
	}
	return largestArea;
}

/* Function: getAverageArea
 * Purpose: This function finds and returns the average area of all polygons in the vector.
 */
double getAverageArea(const vector<Polygon*>& polygons) {
	double averageArea = 0.0;
	double totalArea = 0.0;

	// If there are no polygons, return the average area as 0.0
	if (polygons.empty()) {
		return averageArea;
	}
	// Add up the total area of all the polygons
	for (int i = 0; i < polygons.size(); i++) {
		totalArea += polygons[i]->area();
	}

	averageArea = totalArea / polygons.size();  // Find the average area

	return averageArea;
}

/* Function: getAveragePerimeter
 * Purpose: This function finds and returns the average perimeter of all polygons in the vector.
 */
double getAveragePerimeter(const vector<Polygon*>& polygons) {
	double averagePerimeter = 0.0;
	double totalPerimeter = 0.0;

	// If there are no polygons, return the average perimeter as 0.0
	if (polygons.empty()) {
		return averagePerimeter;
	}
	// Add up the total perimeter for all the polygons
	for (int i = 0; i < polygons.size(); i++) {
		totalPerimeter += polygons[i]->perimeter();
	}

	averagePerimeter = totalPerimeter / polygons.size();  // Find the average perimeter

	return averagePerimeter;
}
