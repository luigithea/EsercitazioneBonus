/** @file RightTrapezoid.cpp
	\brief Declaration of the general class RightTrapezoid
	@Luigi Thea
	@Lorenzo Pitzalis
*/

#include "RightTrapezoid.h"
#include <math.h>

/// @brief default constructor 
RightTrapezoid::RightTrapezoid() {

	cout << "RightTrapezoid - constructor - default" << endl;

	Init();
	/**area = 0.;
	perimeter = 0.;
	*/
}

/// @brief constructor
/// @param BS per BottomSide
/// @param TS per TopSide
/// @param H per Height
RightTrapezoid::RightTrapezoid(float BS, float TS, float H) {
	
	Init();

	cout << "RightTrapezoid - constructor" << endl;

	if (BS <= 0.)
		cout << "WARNING: RightTrapezoid - constructor: La base maggiore deve essere > 0" << endl;
	else
		BottomSide = BS;

	if (TS <= 0.)
		cout << "WARNING: RightTrapezoid - constructor: La base minore deve essere > 0" << endl;
	else
		TopSide = TS;

	if (H <= 0.)
		cout << "WARNING: RightTrapezoid - constructor: L'altezza deve essere > 0" << endl;
	else
		Height = H;

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
	area = 0.;
	perimeter = 0.;

}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void RightTrapezoid::Init(const RightTrapezoid& p) {
	Reset();
	BottomSide = p.BottomSide;
	TopSide = p.TopSide;
	Height = p.Height;

}

/// @brief total reset of the object  
void RightTrapezoid::Reset() {
	perimeter = 0.;
	area = 0.;
	BottomSide = 0.;
	TopSide = 0.;
	Height = 0.;

}

/// @brief che setta il valore della Base Maggiore
/// controlla anche che il valore sia maggiore di 0
void RightTrapezoid::SetBottomSide(float BS) {
	if (BS <= 0.) {
		cout << "WARNING: RightTrapoezoid - SetBS: La base maggiore deve essere > 0" << endl;
		return;
	}

	BottomSide = BS;
}

/// @brief che setta il valore della Base Minore
/// controlla anche che il valore sia maggiore di 0
void RightTrapezoid::SetTopSide(float TS) {
	if (TS <= 0.) {
		cout << "WARNING: RightTrapoezoid - SetTS: La base minore deve essere > 0" << endl;
		return;
	}

	TopSide = TS;
}

/// @brief che setta il valore dell'altezza
/// controlla anche che il valore sia maggiore di 0
void RightTrapezoid::SetHeight(float H) {
	if (H <= 0.) {
		cout << "WARNING: RightTrapoezoid - SetH: L'altezza deve essere > 0" << endl;
		return;
	}

	Height = H;
}

/// @brief che setta le dimensioni chiamando le tre funzioni
void RightTrapezoid::SetDim(float BS, float TS, float H) {
	SetBottomSide(BS);
	SetTopSide(TS);
	SetHeight(H);
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

/// @brief che legge la Base Maggiore dell'oggetto
/// @return la Base Maggiore 
float RightTrapezoid::GetBottomSide() {
	return BottomSide;
}

/// @brief che legge la Base Minore dell'oggetto
/// @return la Base Minore 
float RightTrapezoid::GetTopSide() {
	return TopSide;
}

/// @brief che legge l'altezza dell'oggetto
/// @return l'altezza 
float RightTrapezoid::GetHeight() {
	return Height;
}

/// @brief che legge le tre dimensioni dell'oggetto usando 3 puntatori
void RightTrapezoid::GetDim(float &BS, float &TS, float &H) {
	BS = BottomSide;
	TS = TopSide;
	H = Height;

	return;
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

/// @function that checks if an error has occured
int RightTrapezoid::Check() {
	if (BottomSide == 0 || TopSide == 0 || Height == 0 || BottomSide == TopSide)
		return 1;
	return 0;
}

/// @brief for debugging: all about the object
void RightTrapezoid::Dump() {

	cout << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << "Area = " << GetArea() << endl;
	cout << "Base maggiore = " << GetBottomSide() << endl;
	cout << "Base minore = " << GetTopSide() << endl;
	cout << "Altezza = " << GetHeight() << endl;
	cout << "Lato obliquo = " << GetSide() << endl;
	cout << endl << flush;

}

/// @brief che calcola l'area del trapezio
/// @return l'area
float RightTrapezoid::Area() {
	area = (BottomSide + TopSide) * Height / 2;
	return area;
}

/// @brief che calcola il lato obliquo del trapezio
/// @return il lato obliquo
float RightTrapezoid::GetSide() {
	float seg;

	if (BottomSide < TopSide) {
		float t;
		t = BottomSide;
		BottomSide = TopSide;
		TopSide = t;
		cout << "Base Maggiore e Base Minore Sono State Invertite" << endl;

	}
	else if (BottomSide == TopSide) {
		cout << "ERRORE DI CALCOLO: Base Maggiore e Base minore NON possono essere uguali" << endl;

		RightTrapezoid::~RightTrapezoid();

		exit(0);
	}

	seg = (BottomSide - TopSide);
	
	return sqrt((pow(seg, 2) + pow(Height, 2)));

}

/// @brief che calcola il perimetro del trapezio
/// @return il perimetro
float RightTrapezoid::Perimeter() {
	perimeter = GetSide() + BottomSide + TopSide + Height;
	return perimeter;
}

/// @brief che disegna il trapezio
void RightTrapezoid::Draw() {
	
	cout << "Disegno un trapezio rettangolo" << endl;
	cout << endl << flush;
	Dump();
}