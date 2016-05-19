#ifndef __config_h__
#define __config_h__

/* Prototype definitions */
extern void motorStop(void);
extern void motorFw(void);
extern void motorBw(void);
extern void motorFw(void);
extern void motorRight(void);
extern void motorLeft(void);
extern int  readSensor(int);

/* Motor Pin Definitions */
#define M1_OUT1 2
#define M1_OUT2 3
#define M2_OUT1 4
#define M2_OUT2 5

/* IR Sensor Pin Definitions */
#define SEN1 A0
#define SEN2 A1

/* Motor Enable Pin Definitions (It can be used for speed control from PWM) */
#define M1_EN 9
#define M2_EN 10

/* PWM values for speed control (0-255) 8-bit PWM */
#define M1_SPEED 140
#define M2_SPEED 140

/* Sensor Average Times */
#define AVG_SAMPLE_RATE 100

/* Sensor Threshold */
/* Lesser value indicates more black and lower indicates more white */
#define SEN1_THRESHOLD 200
#define SEN2_THRESHOLD 260

/* Delay for loop in ms */
#define LOOP_DELAY 500

#endif
