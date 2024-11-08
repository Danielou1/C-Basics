#include <stdio.h>
#include <stdint.h>

#define MAX_STRING_SIZE 11 // Maximale Größe des Strings (10 Ziffern + Nullterminator)

// Globales Array für den resultierenden String
char numberString[MAX_STRING_SIZE]; 

/**
 * Wandelt eine 32-Bit vorzeichenlose Ganzzahl (uint32_t) in einen String um.
 *
 * @param number Die zu konvertierende Zahl.
 */
void uint32_to_string(uint32_t number) {
    int index = MAX_STRING_SIZE - 2; // Startet am zweitletzten Index des Arrays
    numberString[MAX_STRING_SIZE - 1] = '\0'; // Setzt das Nullterminator am Ende des Strings

    // Umwandlung der Zahl in den String (von rechts nach links)
    do {
        // Berechnet die Ziffer und speichert sie im Array als Zeichen
        numberString[index--] = '0' + (number % 10); 
        number /= 10; // Entfernt die letzte Ziffer aus der Zahl
    } while (number > 0); // Schleife läuft, bis alle Ziffern verarbeitet sind

    // Verschiebt die Ziffern des Strings, um führende Nullen zu entfernen
    int start = index + 1;
    for (int i = 0; i < MAX_STRING_SIZE - start; i++) {
        // Kopiert die relevanten Ziffern an den Beginn des Strings
        numberString[i] = numberString[start + i]; 
    }
}

int main() {
    uint32_t number = 12345; // Beispielzahl
    uint32_to_string(number); // Ruft die Funktion auf, um die Zahl zu konvertieren
    printf("Die Zahl als String: %s\n", numberString); // Gibt den resultierenden String aus
    return 0; // Beendet das Programm erfolgreich
}
