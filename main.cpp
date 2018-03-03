#include<iostream>
#include <string>
#include <cstdlib>

using namespace std;

/* Global Variablen */
bool tresor = 1;
int geld = 300000;
int diamenten = 55;
bool alarm = 0;


void loese_alarm_aus() {
    alarm = true;
}

void klaue_geld(int Betrag) {
    cout << "Wir klauen " << Betrag << " Euros" << endl;

    if ( Betrag > geld) {
        cout << "Soviel Geld ist doch gar nicht im Tresor!" << endl;
        Betrag = geld;
    }

    cout << "Genug Geld da, ich nehme " << Betrag << endl;
    geld = geld - Betrag;

}

void schliesse_tresor() {
    tresor = 1 ;
    cout << "Der Tresor wurde geschlossen" << endl;
}

void schaue_tresor() {

    cout << "Es sind " << geld << " Euros " << "im Tresor" << endl;
    cout << "Und ausserdem " << diamenten  << " Diamanten" <<  endl;

}

void oeffne_tresor() {
    tresor = 0 ;
    cout << "Der Tresor wurde geöffnet" << endl;

    return;
}

int  main() {

    string eingabe;
    string kennwort = "123";

    /* Wenn Tresor zu ist */
    if ( tresor == 1) {
        cout << "Hallo, wie heisst das geheime Kennwort für den Tresor?" << endl;
        cin >> eingabe;
        cout << "Deine Eingabe lautet " << eingabe << endl;

        if (eingabe == kennwort) {
            oeffne_tresor();
            schaue_tresor();
            schliesse_tresor();
        } else {
            cout << "Das Kennwort ist falsch!" << endl;
            loese_alarm_aus();
        }
    } else {

        schaue_tresor();
        klaue_geld(50000000);
        loese_alarm_aus();
        schaue_tresor();

        schliesse_tresor();
    }

    if ( alarm == 1) {
        std::system("say 'HALT! STOP! Alarm ausgeloest, Polizei ist auf dem Weg'");
        cout << "Alarm ausgeloest, Polizei ist auf dem Weg\a" << endl;
    }

    return 0;

}

