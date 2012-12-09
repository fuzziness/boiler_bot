#include <SoftwareSerial.h>
#include <GSM_Shield.h>
#include <ArduinoTestSuite.h>

GSM gsm;

void hardwareReady()
{
  Serial.println('2');
  String deviceInfo = "";
  char result[30]; 
  if (gsm.SendATCmdWaitResp("ATI", 100, 500, result, 2) == AT_RESP_OK) {
    //deviceInfo += "SIM900 R11.0";
    deviceInfo += result;
  }
  ATS_PrintTestStatus("SIM900 ready", deviceInfo.startsWith("SIM900"));
}

void hardwareWakeup()
{
  Serial.println('1');
  gsm.TurnOn(9600);             //module power on
  gsm.Echo(1);                  //enable AT echo
  ATS_PrintTestStatus("Hardware wakeup", gsm.IsInitialized() > 0); 
}

void setup()
{
  Serial.println('0');
  ATS_begin("TheMakers", "BoilerBot hardware tests"); 
  Serial.println("GSM library version: " + gsm.LibVer()); 
  hardwareWakeup();
  hardwareReady(); 
  ATS_end();
    Serial.println('3');
}

void loop()
{
  Serial.println('4');
}


