#include "Serial_Isra.h"
#include "WL_IMU.h"
#include <Arduino.h>


/*Isra Serial Class Setup*/
Serial_Isra Serial_Isra;

/*Sensors Setup*/
IMU imu;
//unsigned long current_time = 0;
//unsigned long previous_time = 0;
//unsigned long previous_time_ble = 0;

/*Serial Send*/
size_t Send_Length = 7;
char Send[7] = {0x30, 0x31, 0x32, 0x33, 0x33, 0x33, 0x33};
/*iMU SEND*/
//double L_IMUX_int = 0;
uint16_t L_IMUX_int = 0x00;
//double R_IMUX_int = 0;
uint16_t R_IMUX_int = 0x00;

float IMUX_float = 0;

/* Time control*/
unsigned long Delta_T1 = 50000;
unsigned long t_i, t_pr1;
double t;



void setup() {
  delay(3000);
  Serial.begin(115200);
  Serial_Isra.INIT();
  Serial.println("SETUP DONE");
  delay(100);
  CurrentControlSetup();
}

void loop() {
  imu.READ();
  //Serial_Isra.READ();
  t_i = micros();
  t = t_i / 1000000.0;
  float IMU11 = 150 * sin(t);
  float IMU22 = 150 * cos(t);
  L_IMUX_int = Serial_Isra.float_to_uint(IMU11, -180, 180, 16);
  R_IMUX_int = Serial_Isra.float_to_uint(IMU22, -180, 180, 16);
//  L_IMUX_int = Serial_Isra.float_to_uint(imu.LTx, -180, 180, 16);
//  R_IMUX_int = Serial_Isra.float_to_uint(imu.RTx, -180, 180, 16);
  Send[2] = L_IMUX_int >> 8;
  Send[3] = L_IMUX_int & 0xFF;
  Send[4] = R_IMUX_int >> 8;
  Send[5] = R_IMUX_int & 0xFF;

  //  uint16_t IMUX_int2 = (Send[2] << 8) | Send[3];
  //  L_IMUX_float = Serial_Isra.uint_to_float(IMUX_int2, -180, 180, 16);


  //Serial_Isra.READ2();

  if (t_i - t_pr1 > Delta_T1) {
    t_pr1 = t_i;
    //char Send3[7] = {0x30, 0x31, 0x32, 0x33, 0x33, 0x33, 0x33};
    Serial_Isra.WRITE(Send, Send_Length);
    //Serial7.println(" ");
    //Serial_Isra.Print_serial();
    Serial.print(-180);
    Serial.print(" ");
    Serial.print(180);
    Serial.print(" ");
    Serial.print(IMUX_float);
    Serial.print(" ");
    Serial.print(imu.LTx);
    Serial.println(" ");

  }

  //delay(2);

}

void CurrentControlSetup()
{
  imu.INIT();
  delay(500);
  imu.INIT_MEAN();
  //  current_time = micros();
  //  previous_time = current_time;
  //  previous_time_ble = current_time;
}
