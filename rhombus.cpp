/*! \file rhombus.cpp
	\brief class Rhombus: implementation of the functions

	Details.
*/

#include<iostream>
#include "rhombus.h"
#include "polygon.h"

/// @brief default constructor 
Rhombus::Rhombus() 
{

	cout << "Rhombus - constructor - default" << endl;

	diagMax = 0;
	diagMin = 0;
	area = 0;
	perimeter = 0;
}

/// @brief init constructor 
/// @param dH horizontal diagonal dimension
/// @param dL horizontal diagonal dimension
Rhombus::Rhombus(float dH, float dV)
{

	diagMax = 0;
	diagMin = 0;
	area = 0;
	perimeter = 0;
	cout << "Rhombus - constructor" << endl;

	if (dH <= 0)
		cout << "WARNING: Rhombus - constructor: diagMax should be > 0" << endl;
	else
		diagMax = dH;

	if (dV <= 0)
		cout << "WARNING: Rhombus - constructor: diagMin should be > 0" << endl;
	else
		diagMin = dV;
}


/// @brief copy constructor
/// @param Rhombus to copy passed by reference
Rhombus::Rhombus(const Rhombus& r)
{
	cout << "Rhombus - copy constructor" << endl;
	area = r.area;
	perimeter = r.perimeter;
	diagMax = r.diagMax;
	diagMin = r.diagMin;
}

/// @brief destructor 
Rhombus::~Rhombus() 
{

	cout << "Rhombus - destructor" << endl;

}

/// @brief overload operator =
/// @param Rhombus to be copied passed by reference (as a constant to block an eventual change to the object to be copied)
/// @return this object
Rhombus& Rhombus::operator=(const Rhombus& r)
{
	cout << "Rhombus - operator =" << endl;

	diagMax = r.diagMax;
	diagMin = r.diagMin;

	return *this;
}

/// @brief overload operator == (useful for if(obj1=obj2) construct, when are to obj equal? we have to decide it, obj1 is the caller, obj2 is called as a parameter)
/// @param Rhombus to check if it is equal to the Rhombus that called == operator (as a constant to block an eventual change)
/// @return true if diagMax and diagMin of the two Rhombus are equal, false otherwise (we decided the meaning of the operator ==)
bool Rhombus::operator==(const Rhombus& r)
{
	if (diagMax == r.diagMax && diagMin == r.diagMin)
	{
		return true;
	}
	return false;
}

/// @brief calculates the side of the Rhombus with the two diagonals
/// @return side of the Rhombus
float Rhombus::Side()
{
	return (float)sqrt(pow(diagMax/2, 2) + pow(diagMin / 2, 2));
}

/// @brief set diagMax of the object
/// @param dH diagMax to set in pixels
void Rhombus::SetHorD(float dH)
{

	if (dH < 0) {
		cout << "WARNING: Rhombus - SetHorD: horizontal diagonal should be > 0" << endl;
		return;
	}

	diagMax = dH;

}

/// @brief set diagMin of the object
/// @param dV diagMin to set in pixels
void Rhombus::SetVerD(float dV)
{

	if (dV < 0) {
		cout << "WARNING: Rhombus - SetVerD: vertical diagonal should be > 0" << endl;
		return;
	}

	diagMin = dV;

}

/// @function that checks if an error has occured
int Rhombus::Check() {
	if (diagMax == 0 || diagMin == 0)
		return 1;
	return 0;
}

/// @brief set dimensions of the object
/// @param dH diagMax to set in pixels
/// @param dV diagMin to set in pixels
void Rhombus::SetDim(float dH, float dV)
{

	SetHorD(dH);
	SetVerD(dV);

}

/// @brief get diagMax of the object
/// @return diagMax of the object
float Rhombus::GetHorD()
{

	return diagMax;

}

/// @brief get diagMin of the object
/// @return diagMin of the object
float Rhombus::GetVerD()
{

	return diagMin;

}

/// @brief get diagMax and diagMin of the object returning them in the given variables
/// @param given variable to return diagMax in pixels
/// @param given variable to return diagMin in pixels
void Rhombus::GetDim(float& dH, float& dV)
{

	dH = diagMax;
	dV = diagMin;

	return;
}

/// @brief get side of the object
/// @return side of the object
float Rhombus::GetSide()
{
	return Side();
}

/// @brief function to calculate the area of a Rhombus
/// @return area of the given Rhombus
float Rhombus::GetArea()
{
	area = Area();
	return area;
}

/// @brief function to calculate the perimeter of a Rhombus
/// @return perimeter of the given Rhombus
float Rhombus::GetPerimeter()
{
	perimeter = Perimeter();
	return perimeter;
}

/// @brief che calcola il perimetro del rombo
/// @ritorna il perimetro
float Rhombus::Perimeter() {
	float side = Side();
	perimeter = side * 4;
	return perimeter;
}

/// @brief che calcola l'area del rombo
/// @ritorna l'area
float Rhombus::Area() {
	area = (diagMax * diagMin) / 2;
	return area;
}

/// @brief che disegna il rombo
void Rhombus::Draw() {

	cout << "Disegno un rombo" << endl;
	cout << endl << flush;
	Dump();
}


/// @brief for debugging: all about the object
void Rhombus::Dump() {

	cout << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << "Area = " << GetArea() << endl;
	cout << "Diagonale maggiore = " << GetHorD() << endl;
	cout << "Diagonale minore = " << GetVerD() << endl;
	cout << "Lato obliquo = " << GetSide() << endl;
	cout << endl << flush;

}
