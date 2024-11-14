#include <stdio.h>
#include "sensor.h"

sensor_daten_t* sensor_create(char *sensor_name, uint8_t sensor_bus_address){
    sensor_daten_t *sensor_daten = malloc(sizeof(sensor_daten_t));
    sensor_daten->sensor_name = sensor_name;
    sensor_daten->sensor_bus_address = sensor_bus_address;

    return sensor_daten;
}

void sensor_delete(sensor_daten_t *sensor_daten){
    free(sensor_daten);
}

enum status_codes sensor_read(sensor_daten_t *sensor_daten){
    printf("Sensor %d hat den Wert %x\n", sensor_daten->read_value, sensor_daten->read_value.bytes);

    if (sensor_daten->read_value.value == 0){

        return READ_ERR;
    }
    
    return SUCCESS;
}

enum status_codes sensor_write(sensor_daten_t *sensor_daten, uint8_t value){
    printf("Sensor value %d | als bit 0x%02X  ", sensor_daten->write_value.value = value,  sensor_daten->write_value.bytes[value]);

    if (sensor_daten->write_value.value == 0)
    {
        return READ_ERR;
    }
    
    return SUCCESS;
}