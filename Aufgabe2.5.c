#include <stdio.h>   // Einbindung der Standard-Ein-/Ausgabebibliothek für printf
#include <stdint.h>  // Einbindung der Bibliothek für standardisierte Integer-Typen

/**
 * @brief Setzt ein Bit an einer bestimmten Position in einer 16-Bit-Ganzzahl.
 *
 * Diese Funktion setzt das Bit an der angegebenen Position in der Zahl auf 1.
 * Wenn die Position ungültig ist (kleiner als 0 oder größer als 15), 
 * bleibt die Zahl unverändert.
 *
 * @param number Die 16-Bit-Ganzzahl, deren Bit gesetzt werden soll.
 * @param position Die Position des zu setzenden Bits (0-15).
 * @return uint16_t Die neue Zahl mit dem gesetzten Bit.
 */
uint16_t set_bit(uint16_t number, uint8_t position) {
    // Überprüft, ob die Position gültig ist
    if (position < 0 || position > 15) {
        return number; // Rückgabe der ursprünglichen Zahl, wenn die Position ungültig ist
    }
    
    uint16_t mask = 1 << position; // Erstelle eine Maske, bei der nur das angegebene Bit gesetzt ist
    number |= mask; // Setze das Bit an der angegebenen Position
    return number; // Rückgabe der modifizierten Zahl
}

/**
 * @brief Tauscht die Bytes eines 16-Bit-Werts.
 *
 * Diese Funktion tauscht die oberen und unteren 8 Bits eines 16-Bit-Werts.
 *
 * @param number Die 16-Bit-Ganzzahl, deren Bytes getauscht werden sollen.
 * @return uint16_t Der Wert mit vertauschten Bytes.
 */
uint16_t swap_bytes(uint16_t number) {
    // Verschiebt die oberen 8 Bits nach unten und die unteren 8 Bits nach oben
    uint16_t to_swap_bytes = ((number >> 8) & 0x00FF) | ((number << 8) & 0xFF00);
    return to_swap_bytes; // Rückgabe des Werts mit vertauschten Bytes
}

/**
 * @brief Extrahiert den oberen Nibble (die oberen 4 Bits) einer 8-Bit-Ganzzahl.
 *
 * Diese Funktion extrahiert den oberen Nibble (die 4 höchsten Bits) eines 8-Bit-Werts,
 * indem der Wert mit der Maske 0xF verknüpft wird. Das Ergebnis sind die 4 höchsten Bits des Werts.
 *
 * @param number Der 8-Bit-Wert, dessen oberer Nibble extrahiert werden soll.
 * @return uint8_t Der extrahierte obere Nibble des Werts.
 */
uint8_t get_high_nibble(uint8_t number) {
    uint8_t modified_nibble = number >> 4; // Verschiebe die oberen 4 Bits in die unteren 4 Bits
    return modified_nibble; // Rückgabe des extrahierten oberen Nibbles
}
