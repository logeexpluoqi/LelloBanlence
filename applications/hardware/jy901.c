/**
 * @ Author: luoqi
 * @ Create Time: 2023-08-23 21:47
 * @ Modified by: luoqi
 * @ Modified time: 2023-08-25 20:56
 * @ Description:
 */

#include <string.h>
#include "jy901.h"

static float coeff_acc = 0.0;
static float coeff_vangle = 0.0;
static float coeff_angle = 0.0;
static float g = 9.8;

static enum {
    JY901_ACCELERATION = 0x51,
    JY901_VANGULAR = 0x52,
    JY901_ANGULAR = 0x53,
};

int jy901_init(JY901Obj *dev)
{
    memset(dev, 0, sizeof(JY901Obj));
    coeff_acc = (16 * 9.8) / 32768.0;
    coeff_vangle = 2000.0 / 32768.0;
    coeff_angle = 0.0;
    return 0;
}

int jy901_decode(JY901Obj *dev, uint8_t *data)
{
    uint8_t sum;
    int16_t value = 0;
    if (data[0] != 0x55) {
        return -1;
    }
    for (int i = 0; i < 10; i++) {
        sum += data[i];
    }
    if (data[10] != sum) {
        return -2;
    }
    switch (data[1]) {
    case JY901_ACCELERATION:
        dev->accx = ((int16_t)data[3] << 8 | data[2]) * coeff_acc;
        dev->accy = ((int16_t)data[5] << 8 | data[4]) * coeff_acc;
        dev->accz = ((int16_t)data[7] << 8 | data[6]) * coeff_acc;
        break;
    case JY901_VANGULAR:
        dev->ax = ((int16_t)data[3] << 8 | data[2]) * coeff_vangle;
        dev->ay = ((int16_t)data[5] << 8 | data[4]) * coeff_vangle;
        dev->az = ((int16_t)data[7] << 8 | data[6]) * coeff_vangle;
        break;
    case JY901_ANGULAR:
        dev->roll = ((int16_t)data[3] << 8 | data[2]) * coeff_angle;
        dev->pitch = ((int16_t)data[5] << 8 | data[4]) * coeff_angle;
        dev->yaw = ((int16_t)data[7] << 8 | data[6]) * coeff_angle;
        break;
    default:
        return -1;
    }
    return 0;
}
