//==========MODIFICATION==========//
/*
  This is a modification of TDS Sensor Meter suitable for ESP32 and the usage of external ADC

  modification is mainly in the read Analog and removing analog input pin (just input analog voltage value)
*/

/***************************************************
 DFRobot Gravity: Analog TDS Sensor/Meter
 <https://www.dfrobot.com/wiki/index.php/Gravity:_Analog_TDS_Sensor_/_Meter_For_Arduino_SKU:_SEN0244>

 ***************************************************
 This sample code shows how to read the tds value and calibrate it with the standard buffer solution.
 707ppm(1413us/cm)@25^c standard buffer solution is recommended.

 Created 2018-1-3
 By Jason <jason.ling@dfrobot.com@dfrobot.com>

 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution.
 ****************************************************/

 /***********Notice and Trouble shooting***************
 1. This code is tested on Arduino Uno with Arduino IDE 1.0.5 r2 and 1.8.2.
 2. Calibration CMD:
     enter -> enter the calibration mode
     cal:tds value -> calibrate with the known tds value(25^c). e.g.cal:707
     exit -> save the parameters and exit the calibration mode
 ****************************************************/

 #include <EEPROM.h>
 #include "GravityTDSAnalog.h"

 #define EEPROM_SIZE 512

 GravityTDSAnalog gravityTdsAnalog;
 float temperature = 25, tdsValue = 0, voltage = 0;


 void setup(){
   Serial.begin(115200);
   EEPROM.begin(EEPROM_SIZE);  //Initialize EEPROM
   gravityTdsAnalog.begin();  //initialization
 }

 void loop(){
   gravityTdsAnalog.setVoltage(voltage);
   gravityTdsAnalog.setTemperature(temperature);  // set the temperature and execute temperature compensation
   gravityTdsAnalog.update();  //sample and calculate
   tdsValue = gravityTdsAnalog.getTdsValue();  // then get the value
   Serial.print(tdsValue,0);
   Serial.println("ppm");
   delay(1000);
 }
