#include <stdio.h>
#include <stdlib.h>  // Inclusion nécessaire pour malloc et free
#include <stdint.h>  // Inclusion pour uint8_t, uint32_t

// Définition de l'enum pour les codes d'état
enum status_codes {
    SUCCESS,
    READ_ERR,
    WRITE_ERR,
};

// Union pour stocker une valeur 32 bits ou ses bytes individuels
union uinteger32 {
    uint32_t value;
    char bytes[sizeof(uint32_t)];
};

// Structure pour stocker les données du capteur
typedef struct sensor_daten_t {
    char *sensor_name;
    uint8_t sensor_bus_address;
    enum status_codes status;
    union uinteger32 read_value;
    union uinteger32 write_value;
} sensor_daten_t;

// Fonction pour créer un capteur
sensor_daten_t* sensor_create(char *sensor_name, uint8_t sensor_bus_address) {
    sensor_daten_t *sensor_daten = (sensor_daten_t *)malloc(sizeof(sensor_daten_t));
    if (sensor_daten == NULL) {
        return NULL;  // Vérification de l'allocation réussie
    }
    sensor_daten->sensor_name = sensor_name;
    sensor_daten->sensor_bus_address = sensor_bus_address;
    return sensor_daten;
}

// Fonction pour supprimer un capteur
void sensor_delete(sensor_daten_t *sensor_daten) {
    free(sensor_daten);
}
enum status_codes sensor_read(sensor_daten_t *sensor_daten);
enum status_codes sensor_write(sensor_daten_t *sensor_daten, uint8_t value);