/**
 * @ Author: luoqi
 * @ Create Time: 2023-07-02 03:18
 * @ Modified by: luoqi
 * @ Modified time: 2023-08-25 20:40
 * @ Description:
 */

#ifndef _QBLC_DEV_H
#define _QBLC_DEV_H

#include "../hardware/motor.h"
#include "../hardware/jy901.h"

typedef struct qblc_dev{
    MotorObj motor_l;
    MotorObj motor_r;

} QblcObj; // Q balance car

int qblc_dev_init(void);

// #define  qblc_dev()
QblcObj *qblc_dev(void);

#endif
