/**************************************************************************************************************
 * @file TestProgramme.c
 * @brief Testprogramm für die Sensorverwaltungsfunktionen.
 * 
 * Dieses Programm testet das Erstellen, Lesen, Schreiben und Löschen von Sensoren.
 * 
 * @autor Danielou Mounsande
 * @date 14.11.2024
 ************************************************************************************************************/

#include <stdio.h>
#include "sensor.h"

/**
 * @brief Einstiegspunkt des Programms.
 * 
 * Erstellt zwei Sensoren, schreibt und liest deren Werte und löscht die Sensoren.
 * 
 * @return Programmstatuscode, 0 für Erfolg.
 */
int main() {
    sensor_daten_t *sensor_daten = sensor_create("Sensor1", 0x01);
    if (sensor_daten == NULL) {
        printf("Failed to allocate memory for sensor.\n");
        return 1;
    }

    sensor_write(sensor_daten, 42);
    sensor_read(sensor_daten);
    sensor_delete(sensor_daten);

    sensor_daten_t *sensor_daten2 = sensor_create("Sensor2", 0x02);
    sensor_write(sensor_daten2, 57);
    sensor_read(sensor_daten2);
    sensor_delete(sensor_daten2);

    return 0;
}
