#include "sensor.h"

// Fonction pour lire la valeur du capteur
enum status_codes sensor_read(sensor_daten_t *sensor_daten) {
    printf("Sensor %s hat den Wert %d (Bytes: ", sensor_daten->sensor_name, sensor_daten->read_value.value);

    // Affichage des bytes
    for (int i = 0; i < sizeof(sensor_daten->read_value.bytes); i++) {
        printf("0x%02X ", (unsigned char)sensor_daten->read_value.bytes[i]);
    }
    printf(")\n");

    if (sensor_daten->read_value.value == 0) {
        return READ_ERR;
    }
    return SUCCESS;
}

// Fonction pour écrire une valeur dans le capteur
enum status_codes sensor_write(sensor_daten_t *sensor_daten, uint8_t value) {
    sensor_daten->write_value.value = value;
    printf("Sensor value %d | als bit ", sensor_daten->write_value.value);

    // Affichage des bytes
    for (int i = 0; i < sizeof(sensor_daten->write_value.bytes); i++) {
        printf("0x%02X ", (unsigned char)sensor_daten->write_value.bytes[i]);
    }
    printf("\n");

    if (sensor_daten->write_value.value == 0) {
        return READ_ERR;
    }
    return SUCCESS;
}