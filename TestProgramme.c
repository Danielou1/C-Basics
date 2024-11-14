#include "sensor.h"

int main(){
    sensor_daten_t *sensor_daten = sensor_create("Sensor1", 0x01);
    sensor_write(sensor_daten);
    sensor_read(sensor_daten);
    sensor_delete(sensor_daten);
    return 0;
}