#include <BLE.h>
#include <LFS.h>

#include <HardwareSerial.h>

BLE ble;
LFS fileSys;

void setup()
{
	Serial.begin(115200);

	// BLE
	ble.init();
}

unsigned long startTime = 0;

void loop()
{
	if(startTime == 0)
	{
		startTime = millis();
	}
	if(ble.connection)
	{
		float x = (millis() - startTime) / 1000.0;
		float y = sin(x);

		Serial.println(String(x) + "," + String(y));

		ble.send(String(x) + "," + String(y));

		delay(100);
	}
}
