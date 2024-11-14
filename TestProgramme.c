#include "sensor.h"


int main() {
    sensor_daten_t *sensor_daten = sensor_create("Sensor1", 0x01);
    if (sensor_daten == NULL) {
        printf("Failed to allocate memory for sensor.\n");
        return 1;
    }

    // Écriture et lecture de la valeur du capteur
    sensor_write(sensor_daten, 10);  // Added a default value as the second argument

    int value = sensor_read(sensor_daten);

    // Suppression du capteur
    sensor_delete(sensor_daten);
    return 0;
}