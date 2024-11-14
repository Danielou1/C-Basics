/******************************************************************************
 * @file sensor.c
 * @brief Implementierung der Funktionen zur Verwaltung von Sensoren.
 * 
 * Diese Datei enthält die Definitionen der Funktionen zum Erstellen, Lesen, 
 * Schreiben und Löschen von Sensoren.
 * 
 * @author Danielou Mounsande
 * @date 14.11.2024
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"

/**
 * @brief Erstellt einen Sensor.
 * 
 * Diese Funktion reserviert Speicherplatz für einen neuen Sensor und initialisiert 
 * seine Felder mit den bereitgestellten Werten.
 * 
 * @param sensor_name Name des Sensors.
 * @param sensor_bus_address Busadresse des Sensors.
 * @return Zeiger auf eine initialisierte sensor_daten_t-Struktur oder NULL, 
 * wenn die Speicherzuweisung fehlschlägt.
 */
sensor_daten_t* sensor_create(char *sensor_name, uint8_t sensor_bus_address) {
    sensor_daten_t *sensor_daten = malloc(sizeof(sensor_daten_t));
    if (sensor_daten == NULL) {
        return NULL;
    }
    sensor_daten->sensor_name = sensor_name;
    sensor_daten->sensor_bus_address = sensor_bus_address;
    return sensor_daten;
}

/**
 * @brief Löscht einen Sensor.
 * 
 * Gibt den für die Sensorstruktur reservierten Speicher frei.
 * 
 * @param sensor_daten Zeiger auf die sensor_daten_t-Struktur des zu löschenden Sensors.
 */
void sensor_delete(sensor_daten_t *sensor_daten) {
    free(sensor_daten);
}

/**
 * @brief Liest den Wert des Sensors.
 * 
 * Gibt den aktuellen Lesewert des Sensors als Dezimalzahl und in Bytes aus.
 * Gibt je nach gelesener Wert einen Statuscode zurück.
 * 
 * @param sensor_daten Zeiger auf die sensor_daten_t-Struktur des Sensors.
 * @return READ_ERR, wenn der gelesene Wert 0 ist, sonst SUCCESS.
 */
enum status_codes sensor_read(sensor_daten_t *sensor_daten) {
    printf("Sensor %s read Value %d (Bytes: ", sensor_daten->sensor_name, sensor_daten->read_value.value);
    for (int i = 0; i < sizeof(sensor_daten->read_value.bytes); i++) {
        printf("0x%02X ", (unsigned char)sensor_daten->read_value.bytes[i]);
    }
    printf(")\n");

    return sensor_daten->read_value.value == 0 ? READ_ERR : SUCCESS;
}

/**
 * @brief Schreibt einen Wert in den Sensor.
 * 
 * Aktualisiert den Schreibwert des Sensors und kopiert ihn in den Lesewert,
 * um die Synchronisation sicherzustellen. Zeigt den Wert als Dezimalzahl und in Bytes an.
 * 
 * @param sensor_daten Zeiger auf die sensor_daten_t-Struktur des Sensors.
 * @param value Wert, der in den Sensor geschrieben wird.
 * @return READ_ERR, wenn der geschriebene Wert 0 ist, sonst SUCCESS.
 */
enum status_codes sensor_write(sensor_daten_t *sensor_daten, uint8_t value) {
    sensor_daten->write_value.value = value;
    sensor_daten->read_value.value = value;
    printf("Sensor write value %d | als Bytes ", sensor_daten->write_value.value);
    for (int i = 0; i < sizeof(sensor_daten->write_value.bytes); i++) {
        printf("0x%02X ", (unsigned char)sensor_daten->write_value.bytes[i]);
    }
    printf("\n");

    return sensor_daten->write_value.value == 0 ? READ_ERR : SUCCESS;
}
