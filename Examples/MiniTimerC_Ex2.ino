/*
MiniTimerC Example 2 - Multiple timers
Ermanno De Giuli
edg@flx.it - 2016
*/

#include <MiniTimerC.h>

MiniTimerC timerc[2];    // Instance timer

// the setup function
void setup() {

	Serial.begin(115200);
	Serial.println(F("Start... "));

	pinMode(13, OUTPUT);

	timerc[0].ExpireIn(1000);
	timerc[0].Start();
	
	for (int j = 0; j <= 10000; j++)

	timerc[1].ExpireIn(1500);
	timerc[1].Start();

}

// the loop function
void loop() {

	boolean t1 = timerc[0].IsExpired();
	boolean t2 = timerc[1].IsExpired();
	static boolean status = 0;

	if (t1)
	{
		status = !status;
		digitalWrite(13, status);
		Serial.print(" st - ");
		Serial.print(status, BIN);
		Serial.print(" ms - ");
		Serial.print(millis(), DEC);
		Serial.print(" T1 - ");
		Serial.println(timerc[0].TimeElapsed(), DEC);
		timerc[0].Start();
	}

	if (t2)
	{
		Serial.print(" st - ");
		Serial.print(status, BIN);
		Serial.print(" ms - ");
		Serial.print(millis(), DEC);
		Serial.print(" T2 - ");
		Serial.println(timerc[1].TimeElapsed(), DEC);
		timerc[1].Start();
	}




}
