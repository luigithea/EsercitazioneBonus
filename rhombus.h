/*! \file rhombus.h
	\brief Declaration of the class Rhombus

	Details.
*/


#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <math.h>
#include "polygon.h"

using namespace std;

/// @class Rhombus
/// @brief to manage an object with the shape of a Rhombus
class Rhombus:public Polygon
{
private:

	float diagMax;
	float diagMin;
	float area, perimeter;

	float Side();
	float Area();
	float Perimeter();

public:

	/// @brief default constructor
	Rhombus();

	/// @brief init constructor
	Rhombus(float dH, float dV);

	/// @brief copy constructor
	Rhombus(const Rhombus &r);

	/// @brief destructor
	~Rhombus();



	/// @brief overload operator =
	Rhombus& operator=(const Rhombus& r);

	/// @brief overload operator ==
	bool operator==(const Rhombus& r);



	/// @brief functions to set dimensions of the Rhombus
	void SetHorD(float dH);
	void SetVerD(float dV);
	void SetDim(float dH, float dV);

	/// @brief functions to get dimensions of the Rhombus
	float GetHorD();
	float GetVerD();
	void GetDim(float& dH, float& dV);
	float GetSide();

	/// @brief functions to calculate informations about the Rhombus
	float GetArea();
	float GetPerimeter();
	int Check();
	/// @brief funzioni per stampare i dati
	void Dump();
	void Draw();
};

#endif
