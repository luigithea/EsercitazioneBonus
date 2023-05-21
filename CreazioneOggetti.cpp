/*! \file CreazioneOggetti.cpp
    \brief Implementation of the object creator library CreazioneOggetti

    Details.
*/

#include "polygon.h"
#include<iostream>
#include "rectangle.h"
#include "rhombus.h"
#include "RightTrapezoid.h"

using namespace std;

/// @brief that creates a Rectangle
void CreazioneRettangolo(Polygon* ptr[], int *c, float b, float h) {
    ptr[*c] = new Rectangle(b, h);
    Rectangle* ptrRect = static_cast<Rectangle*>(ptr[*c]);
    if (ptrRect->Check() == 0)
        *c = *c + 1;
    else {
        delete ptr[*c];
        cout << endl << flush;
        cout << "Poligono non inserito riprovare" << endl;
        cout << "Ricorda che nessuno dei parametri puo' essere uguale a 0" << endl;
        cout << endl << flush;
    }
}

/// @brief that creates a Rhombus
void CreazioneRombo(Polygon *ptr[], int *c, float D, float d) {
    ptr[*c] = new Rhombus(D, d);
    Rhombus* ptrRhom = static_cast<Rhombus*>(ptr[*c]);
    if (ptrRhom->Check() == 0)
        *c = *c + 1;
    else {
        delete ptr[*c];
        cout << endl << flush;
        cout << "Poligono non inserito riprovare" << endl;
        cout << "Ricorda che nessuno dei parametri puo' essere uguale a 0" << endl;
        cout << endl << flush;
    }
}

/// @brief that creates a RighTrapezoid
void CreazioneTrapezio(Polygon* ptr[], int *c, float B, float b, float h) {
    ptr[*c] = new RightTrapezoid(B, b, h);
    RightTrapezoid* ptrTrap = static_cast<RightTrapezoid*>(ptr[*c]);
    if (ptrTrap->Check() == 0)
        *c = *c + 1;
    else {
        delete ptr[*c];
        cout << endl << flush;
        cout << "Poligono non inserito riprovare" << endl;
        cout << "Ricorda che la base maggiore non puo' essere uguale alla base minore e nessuno dei parametri puo' essere uguale a 0" << endl;
        cout << endl << flush;
    }
}