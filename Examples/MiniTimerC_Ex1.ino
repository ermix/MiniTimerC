/*
MiniTimerC Example 1
Ermanno De Giuli
edg@flx.it - 2016
*/

#include <MiniTimerC.h>

MiniTimerC timerc;    // Instance timer

// the setup function
void setup() {

	Serial.begin(115200);
	Serial.println(F("Start... "));

	pinMode(13, OUTPUT);

	timerc.ExpireIn(1000);
	timerc.Start();

}

// the loop function
void loop() {

	boolean t1 = timerc.IsExpired();
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
		Serial.println(timerc.TimeElapsed(), DEC);
		timerc.Start();
	}

}
