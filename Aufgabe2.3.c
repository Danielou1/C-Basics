#include <stdio.h> // Einbindung der Standard-Ein-/Ausgabebibliothek

// Globales Array, das den String "Hello World as String!" speichert
char charString[] = "Hello World as String!";

/**
 * @brief Hauptfunktion des Programms.
 *
 * Dieses Programm gibt den Text "Hello World as String!" aus, der in der globalen
 * Variable `charString` gespeichert ist. Die Funktion verwendet `printf` zur 
 * Ausgabe des Strings auf der Konsole.
 *
 * @param argc Anzahl der Argumente, die beim Programmaufruf übergeben wurden.
 * @param argv Array von Zeichenketten, das die übergebenen Argumente enthält.
 * @return int Gibt 0 zurück, um anzuzeigen, dass das Programm erfolgreich beendet wurde.
 */
int main(int argc, char *argv[]) {
    printf("%s\n", charString); // Gibt den Inhalt von `charString` aus, gefolgt von einem Zeilenumbruch
    return 0; // Programm erfolgreich beendet
}
