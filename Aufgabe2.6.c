#include <stdio.h>  // Einbindung der Standardbibliothek für Ein-/Ausgabe-Funktionen
#include <stdlib.h> // Einbindung der Bibliothek für Speicherzuweisungsfunktionen

int main() {
    // Dynamische Speicherzuweisung für ein Array von 27 Zeichen (26 Buchstaben + Nullzeichen)
    char *alphabet = (char*)malloc(27 * sizeof(char)); 

    // Überprüfen, ob die Speicherzuweisung erfolgreich war
    if (alphabet == NULL) {
        return 1; // Fehlerfall, wenn malloc fehlschlägt (Speicher konnte nicht zugewiesen werden)
    }

    // Zuweisung von 27 (was keine Bedeutung hat) an die erste Stelle des Arrays (wird nicht weiter verwendet)
    *alphabet = 27; 

    // Pointer auf den Anfang des Arrays initialisieren
    char* current_alphabet = alphabet;

    // Schleife, die durch das Alphabet von 'A' bis 'Z' iteriert
    // und die Zeichen im Array speichert
    for (char i = 'A'; i <= 'Z'; i++) {
        *current_alphabet = i; // Das aktuelle Zeichen (Buchstabe) in das Array einfügen
        current_alphabet++;    // Zeiger auf das nächste Array-Element verschieben
    }

    // Nullzeichen setzen, um das Array als C-String zu terminieren
    *current_alphabet = '\0';

    // Pointer zurück auf den Beginn des Arrays setzen
    current_alphabet = alphabet;

    // Ausgabe des vollständigen Alphabets als String
    while (*current_alphabet != '\0') {
        printf("%c", *current_alphabet); // Gibt das aktuelle Zeichen aus
        current_alphabet++;             // Zeiger auf das nächste Zeichen verschieben
    }

    // Freigeben des dynamisch zugewiesenen Speichers, um Speicherlecks zu vermeiden
    free(alphabet);

    return 0; // Erfolgreicher Abschluss des Programms
}
