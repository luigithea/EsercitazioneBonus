/*! \file Main.cpp
    \brief Main file of the project Esercitazione_Punti_Bonus

   @author Lorenzo Pitzalis & Luigi Thea

    Details.
*/

#include <iostream>

#include "polygon.h"
#include "RightTrapezoid.h"
#include "rectangle.h"
#include "rhombus.h"
#include "CreazioneOggetti.h"

using namespace std;

/// @param variable that contains the number of polygons
int i = 0;

/// @param variable for the array
int n = 0;

/// @param variable that contains the user choice
int scelta1 = 0;
int scelta2 = 0;
/// @param Array of pointers to base class
Polygon* p[99];

int main() {

    /// @brief Cycle that allows to make maximum 100 polygons
    while (i < 100) {
    start:
        /// @brief Interface that asks to the user which action he wants to do
        cout << "Che tipo di poligono vuoi disegnare?" << endl;
        cout << "La scelta e' tra:" << endl;
        cout << "Premi 1 per un rettangolo" << endl;
        cout << "Premi 2 per un rombo" << endl;
        cout << "Premi 3 per un trapezio rettangolo" << endl;
        cout << "Premi 4 per disegnare i poligoni scelti" << endl;
        cout << "Premi 5 per uscire senza stampare" << endl;
        scanf_s("%d", &scelta1);
        if (scelta1 > 5 || scelta1 < 0) {
            cout << "Devi inserire un numero da 1 a 5" << endl;
            cout << endl << flush;
            goto start;
        }

           

        /// @brief witch for the first interface
        switch (scelta1) {
        case 1: /// @brief Rectangle case
            float base;
            float altezzaRet;
            /// @brief interface to decide the sizes of the rectangle
        start1:     cout << "Premi:" << endl;
            cout << "1 per inserire i dati " << endl;
            cout << "2 per usare i dati di default" << endl;
            cout << endl << flush;
            scanf_s("%d", &scelta2);
            if (scelta2 == 1) {
                cout << "Inserisci il valore della base:" << endl;
                scanf_s("%f", &base);
                cout << "Insrisci il valore dell'altezza:" << endl;
                scanf_s("%f", &altezzaRet);
                CreazioneRettangolo(p, &n, base, altezzaRet);
            }
            else if (scelta2 == 2) {
                base = 5;
                altezzaRet = 4;
                CreazioneRettangolo(p, &n, base, altezzaRet);
            }
            else {
                cout << "Devi premere o 1 o 2" << endl;
                goto start1;
            }
            break;
        case 2: /// @brief Rhombus case
            float diagMax;
            float diagMin;
            /// @brief Interface to decide the sizes of the Rhombus
        start2:     cout << "Premi:" << endl;
            cout << "1 per inserire i dati " << endl;
            cout << "2 per usare i dati di default" << endl;
            scanf_s("%d", &scelta2);
            if (scelta2 == 1) {
                cout << "Insrisci il valore della diagonale maggiore:" << endl;
                scanf_s("%f", &diagMax);
                cout << "Insrisci il valore della diagonale minore:" << endl;
                scanf_s("%f", &diagMin);
                CreazioneRombo(p, &n, diagMax, diagMin);
            }
            else if (scelta2 == 2) {
                diagMax = 8;
                diagMin = 4;
                CreazioneRombo(p, &n, diagMax, diagMin);
            }
            else {
                cout << "Devi premere o 1 o 2" << endl;
                goto start2;
            }
            break;
        case 3: /// @brief RightTrapezoid case
            float baseMax;
            float baseMin;
            float altezzaTrap;
            /// @brief Interface to decide the sizes of the RighTrapezoid
        start3:     cout << "Premi:" << endl;
            cout << "1 per inserire i dati " << endl;
            cout << "2 per usare i dati di default" << endl;
            scanf_s("%d", &scelta2);
            if (scelta2 == 1) {
                cout << "Inserisci la base maggiore del trapezio" << endl;
                scanf_s("%f", &baseMax);
                cout << "Inserisci la base minore del trapezio" << endl;
                scanf_s("%f", &baseMin);
                cout << "Inserisci l'altezza del trapezio" << endl;
                scanf_s("%f", &altezzaTrap);
                CreazioneTrapezio(p, &n, baseMax, baseMin, altezzaTrap);
            }
            else if (scelta2 == 2) {
                baseMax = 7;
                baseMin = 4;
                altezzaTrap = 5;
                CreazioneTrapezio(p, &n, baseMax, baseMin, altezzaTrap);
            }
            else {
                cout << endl << flush;
                cout << "Devi premere o 1 o 2" << endl;
                goto start3;
            }
            break;
        case 4: /// @brief Draw case
            for (int l = 0; l < n; l++)
                p[l]->Draw();

            break;
        case 5: /// @brief Exit case
            if(n != 0) ///cause if u don't create any object you don't have to delete anything
            for (int k = 0; k <= n; k++) {
                delete p[k];
                p[k] = NULL;

            }
            exit(0);
        }
        i++;
    }
    return 0;
}