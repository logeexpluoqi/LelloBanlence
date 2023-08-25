/**
 * @ Author: luoqi
 * @ Create Time: 2023-08-23 21:48
 * @ Modified by: luoqi
 * @ Modified time: 2023-08-25 20:54
 * @ Description:
 */

#ifndef _JY901_H
#define _JY901_H

#include <stdint.h> 

typedef struct jy901
{
    /* acceleration */
    float accx;
    float accy;
    float accz;
    /* angular velocity */
    float ax;
    float ay;
    float az;
    /* angular */
    float roll;
    float pitch;
    float yaw;
}JY901Obj;


int jy901_init(JY901Obj *dev);

int jy901_decode(JY901Obj *dev, uint8_t *data);

#endif
