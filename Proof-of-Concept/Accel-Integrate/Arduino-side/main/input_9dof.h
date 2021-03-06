//Header for global functions for 9d0f
#ifndef DOF_CLASS_H
#define DOF_CLASS_H


#include <Mahony.h>
#include <Madgwick.h>
#include <Adafruit_FXAS21002C.h>
#include <Adafruit_FXOS8700.h>



class dof {
  private:
    //Mahony filter;
    Madgwick filter;
    Adafruit_FXAS21002C gyro;
    Adafruit_FXOS8700 accelmag;
    sensors_event_t gyro_event;
    sensors_event_t accel_event;
    sensors_event_t mag_event;
    
  public:
    double heading;
    double headingAdj;
    double pitch;
    double roll;
    float accelX;
    float accelY;
    float accelZ;
    float accelX_lowpass;
    float accelY_lowpass;
    float accelZ_lowpass;
    void init(void);
    void updatedof(void);
    void printOutPlot(void);
    void updateAccel(float ax, float ay, float az);
};

#endif // DOF_CLASS_H
