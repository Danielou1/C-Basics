/******************************************************************************
 * @file sensor.h
 * @brief Deklarationen zur Verwaltung von Sensoren.
 * 
 * Diese Datei enthält die Deklarationen der Strukturen, Typen und
 * Funktionen zur Verwaltung von Sensoren sowie ein Enum für Statuscodes.
 * 
 * @author Danielou Mounsande
 * @date 14.11.2024
 ******************************************************************************/

#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

/**
 * @enum status_codes
 * @brief Statuscodes für die Sensoroperationen.
 */
enum status_codes {
    SUCCESS, /**< Operation erfolgreich */
    READ_ERR, /**< Lesefehler */
    WRITE_ERR /**< Schreibfehler */
};

/**
 * @union uinteger32
 * @brief Union zur Speicherung eines 32-Bit-Wertes und seiner einzelnen Bytes.
 */
union uinteger32 {
    uint32_t value; /**< 32-Bit-Integer-Wert */
    char bytes[sizeof(uint32_t)]; /**< Darstellung in einzelnen Bytes */
};

/**
 * @struct sensor_daten_t
 * @brief Struktur zur Speicherung von Sensorinformationen.
 */
typedef struct sensor_daten_t {
    char *sensor_name; /**< Name des Sensors */
    uint8_t sensor_bus_address; /**< Busadresse des Sensors */
    enum status_codes status; /**< Aktueller Statuscode des Sensors */
    union uinteger32 read_value; /**< Lesewert des Sensors */
    union uinteger32 write_value; /**< Schreibwert des Sensors */
} sensor_daten_t;

/**
 * @brief Erstellt einen Sensor.
 * @param sensor_name Name des Sensors.
 * @param sensor_bus_address Busadresse des Sensors.
 * @return Zeiger auf eine initialisierte sensor_daten_t-Struktur.
 */
sensor_daten_t* sensor_create(char *sensor_name, uint8_t sensor_bus_address);

/**
 * @brief Löscht einen Sensor.
 * @param sensor_daten Zeiger auf die sensor_daten_t-Struktur des Sensors.
 */
void sensor_delete(sensor_daten_t *sensor_daten);

/**
 * @brief Liest den Wert des Sensors.
 * @param sensor_daten Zeiger auf die sensor_daten_t-Struktur des Sensors.
 * @return READ_ERR, wenn der gelesene Wert 0 ist, sonst SUCCESS.
 */
enum status_codes sensor_read(sensor_daten_t *sensor_daten);

/**
 * @brief Schreibt einen Wert in den Sensor.
 * @param sensor_daten Zeiger auf die sensor_daten_t-Struktur des Sensors.
 * @param value Wert, der in den Sensor geschrieben wird.
 * @return READ_ERR, wenn der geschriebene Wert 0 ist, sonst SUCCESS.
 */
enum status_codes sensor_write(sensor_daten_t *sensor_daten, uint8_t value);

#endif
