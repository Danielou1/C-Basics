#include <stdio.h> // Einbindung der Standard-Ein-/Ausgabebibliothek

// Globale Variablen
int count = 10; // Zählt die Anzahl der Iterationen in der while-Schleife
int a = 0; // Variable, die in der while-Schleife inkrementiert wird

/**
 * @brief Hauptfunktion des Programms.
 *
 * Dieses Programm führt zwei Schleifen aus:
 * 1. Eine `for`-Schleife, die `i` von 0 bis `count` (10) iteriert und `i` bei jeder Iteration ausgibt.
 * 2. Eine `while`-Schleife, die `a` bei jeder Iteration ausgibt und `count` dekrementiert, bis `count` 0 erreicht.
 *
 * @return int Gibt 0 zurück, um anzuzeigen, dass das Programm erfolgreich beendet wurde.
 */
int main() {
    
    // For-Schleife: Zählt von 0 bis `count - 1`
    for (int i = 0; i < count; i++) {
        printf("i = %d\n", i); // Ausgabe des Werts von `i` in jeder Iteration
    }
    
    // While-Schleife: Dekrementiert `count` und inkrementiert `a`
    while (count > 0) {
        printf("a = %d\n", a++); // Ausgabe des aktuellen Werts von `a`, dann Inkrementierung
        count--; // Dekrementiert `count` in jeder Iteration
    }

    return 0; // Programm erfolgreich beendet
}
