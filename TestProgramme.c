/**
 * @file TestProgramme.c
 * @brief Testprogramm für die Sensorverwaltungsfunktionen.
 * 
 * Dieses Programm testet das Erstellen, Lesen, Schreiben und Löschen von Sensoren
 * und überprüft die Rückgabestatuscodes, um sicherzustellen, dass die Funktionen 
 * korrekt arbeiten.
 * 
 * @autor Danielou Mounsande
 * @date 2024
 */

#include <stdio.h>
#include "sensor.h"

/**
 * @brief Einstiegspunkt des Programms.
 * 
 * Erstellt zwei Sensoren, schreibt und liest deren Werte, prüft die Rückgabestatuscodes
 * und löscht die Sensoren.
 * 
 * @return Programmstatuscode, 0 für Erfolg.
 */
int main() {
    sensor_daten_t *sensor_daten = sensor_create("Sensor1", 0x01);
    if (sensor_daten == NULL) {
        printf("Failed to allocate memory for sensor.\n");
        return 1;
    }

    // Teste Schreibvorgang mit Nullwert und überprüfe den Rückgabestatus
    enum status_codes status = sensor_write(sensor_daten, 0);
    if (status == READ_ERR) {
        printf("Test erfolgreich: sensor_write() hat READ_ERR zurückgegeben für Wert 0.\n");
    } else {
        printf("Test fehlgeschlagen: sensor_write() sollte READ_ERR für Wert 0 zurückgeben.\n");
    }

    // Teste Lesevorgang und überprüfe den Rückgabestatus
    status = sensor_read(sensor_daten);
    if (status == READ_ERR) {
        printf("Test erfolgreich: sensor_read() hat READ_ERR zurückgegeben für Wert 0.\n");
    } else {
        printf("Test fehlgeschlagen: sensor_read() sollte READ_ERR für Wert 0 zurückgeben.\n");
    }

    sensor_delete(sensor_daten);

    // Erstelle einen zweiten Sensor und teste einen gültigen Schreibvorgang
    sensor_daten_t *sensor_daten2 = sensor_create("Sensor2", 0x02);
    status = sensor_write(sensor_daten2, 57);
    if (status == SUCCESS) {
        printf("Test erfolgreich: sensor_write() hat SUCCESS zurückgegeben für Wert 57.\n");
    } else {
        printf("Test fehlgeschlagen: sensor_write() sollte SUCCESS für Wert 57 zurückgeben.\n");
    }

    // Teste erneut den Lesevorgang für einen nicht-null Wert
    status = sensor_read(sensor_daten2);
    if (status == SUCCESS) {
        printf("Test erfolgreich: sensor_read() hat SUCCESS zurückgegeben für Wert 57.\n");
    } else {
        printf("Test fehlgeschlagen: sensor_read() sollte SUCCESS für Wert 57 zurückgeben.\n");
    }

    sensor_delete(sensor_daten2);

    return 0;
}
