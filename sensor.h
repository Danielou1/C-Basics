#include <stdint.h>

typedef struct sensor_daten_t {
    char *sensor_name;
    uint8_t sensor_bus_address;
    enum status_codes status;
    union uinteger32 read_value;
    union uinteger32 write_value;
} sensor_daten_t;

enum status_codes {
   SUCCESS,
   READ_ERR,
   WRITE_ERR,
};


union uinteger32{
    uint32_t value;
    char bytes[sizeof(value)];
};

sensor_daten_t* sensor_create(char *sensor_name, uint8_t sensor_bus_address);
void sensor_delete(sensor_daten_t *sensor_daten);
status_codes sensor_read(sensor_daten_t *sensor_daten);
status_codes sensor_write(sensor_daten_t *sensor_daten);