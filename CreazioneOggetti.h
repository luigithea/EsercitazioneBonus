/*! \file CreazioneOggetti.h
	\brief Declaration of the object creator library CreazioneOggetti

	Details.
*/
#pragma once

#define CREAZIONEOGGETTI_H

#include "polygon.h"
/// @brief that creates a Rectangle
void CreazioneRettangolo(Polygon* ptr[], int *c, float b, float h);
/// @brief that creates a Rhombus
void CreazioneRombo(Polygon* ptr[], int *c, float D, float d);
/// @brief that creates a Trapezoid
void CreazioneTrapezio(Polygon* ptr[], int *c, float B, float b, float h);