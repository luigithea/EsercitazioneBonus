#pragma once
/** @file RightTrapezoid.h
	\brief Declaration of the general class RightTrapezoid
	@Luigi Thea
	@Lorenzo Pitzalis
*/

#ifndef RIGHTTRAPEZOID_H
#define RIGHTTRAPEZOID_H

#include<iostream>
#include "polygon.h"

using namespace std;

/// @class RightTrapezoid
/// @brief an abstract base class for polygons
class RightTrapezoid :public Polygon {
private:
	float perimeter;
	float area;
	float BottomSide, TopSide, Height;
	
	float Area();
	float Perimeter();

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	RightTrapezoid();
	RightTrapezoid(float BS, float TS, float H);
	RightTrapezoid(const RightTrapezoid& p);
	virtual ~RightTrapezoid();
	/// @}

	/// @name OPERATORS
	/// @{
	RightTrapezoid& operator=(const RightTrapezoid& p);
	bool operator==(const RightTrapezoid& p);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const RightTrapezoid& r);
	void Reset();
	/// @}

	/// @name SETTERS
	/// @{
	void SetBottomSide(float BS);
	void SetTopSide(float TS);
	void SetHeight(float H);
	void SetDim(float BS, float TS, float H);
	/// @}

	/// @name GETTERS
	/// @{
	float GetArea();
	float GetPerimeter();

	float GetSide();
	float GetBottomSide();
	float GetTopSide();
	float GetHeight();
	void GetDim(float& BS, float& TS, float& H);
	/// @}

	/// @name DRAWING
	/// @{
	virtual void Draw();
	/// @}

	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	int Check();
	void Dump();
	/// @}

};

#endif