#include "RightTrapezoid.h"
#include "RightTrapezoid.h"
#include <math.h>



#include "RightTrapezoid.h"

/// @brief default constructor 
RightTrapezoid::RightTrapezoid() {

	cout << "RightTrapezoid - constructor - default" << endl;

	area = 0.;
	perimeter = 0.;

}

/// @brief copy constructor 
/// @param r reference to the object that should be copied 
RightTrapezoid::RightTrapezoid(const RightTrapezoid& p) {

	cout << "RightTrapezoid - copy constructor" << endl;

	Init(p);
}

/// @brief destructor
RightTrapezoid::~RightTrapezoid() {

	cout << "RightTrapezoid - destructor" << endl;
	Reset();

}

/// @brief overload of operator = 
/// @param p reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
RightTrapezoid& RightTrapezoid::operator=(const RightTrapezoid& p) {

	return *this;

}

/// @brief overload of operator == 
/// @param p reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool RightTrapezoid::operator==(const RightTrapezoid& r) {
	return false;
}


/// @brief default initialization of the object
void RightTrapezoid::Init() {
	Reset();
	perimeter = 0.;
	area = 0.;
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void RightTrapezoid::Init(const RightTrapezoid& p) {
	Reset();

}

/// @brief total reset of the object  
void RightTrapezoid::Reset() {
	perimeter = 0.;
	area = 0.;
}

/// @brief get the area of the object
/// @return area 
float RightTrapezoid::GetArea() {

	area = Area();
	return area;

}

/// @brief get the perimeter of the object
/// @return perimeter 
float RightTrapezoid::GetPerimeter() {

	perimeter = Perimeter();
	return perimeter;

}

/// @brief write an error message 
/// @param string message to be printed
void RightTrapezoid::ErrorMessage(const char* string) {

	cout << endl << "ERROR -- RightTrapezoid --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void RightTrapezoid::WarningMessage(const char* string) {

	cout << endl << "WARNING -- RightTrapezoid --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void RightTrapezoid::Dump() {

	cout << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << "Area = " << GetArea() << endl;
	cout << endl << flush;

}



float RightTrapezoid:: GetValue(){

}
float RightTrapezoid::Area() {


	area = (b1 + b2) * h / 2;
		return area;
}


float RightTrapezoid::Perimeter() {


	int seg = 0;
	seg = b1 - b2;
	
	perimeter = sqrt(pow(seg, 2) + pow(h, 2)) + b1 + b2 + h;
	return perimeter;

}