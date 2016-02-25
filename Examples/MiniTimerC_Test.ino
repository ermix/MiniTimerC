/*
MiniTimerC_Test
Ermanno De Giuli
edg@flx.it - 2016
*/

#include "MiniTimerC.h"

// Prescaler per ridurre il tempo di analogread (ARDUINO DEFAULT=128)
// http://www.microsmart.co.za/technical/2014/03/01/advanced-arduino-adc/
// Define various ADC prescaler
const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

#define USE_SERIAL_DEBUG						// Serial debug enable/disable

MiniTimerC timerc[2]; 

const unsigned long MILLIS_MAXVALUE = 4294967295;


extern volatile unsigned long timer0_millis;			// debug serve per resettare millis()

// the setup function runs once when you press reset or power the board
void setup() {

	// Velocizzaione analogRead() con prescaler 
	// http://forum.arduino.cc/index.php?topic=6549.0
	//
	// set up the ADC
	ADCSRA &= ~PS_128;  // remove bits set by Arduino library
						// you can choose a prescaler from above.
						// PS_16, PS_32, PS_64 or PS_128
	ADCSRA |= PS_16;    // set our own prescaler to ...

#ifdef USE_SERIAL_DEBUG
	Serial.begin(115200);
	Serial.println(F("Start... "));
#endif

	pinMode(13, OUTPUT);

    timer0_millis = 4294960000;

	timerc[0].SetExpire(1000);
	timerc[0].Start();

	delay(500);
	timerc[1].Start();
}

// the loop function runs over and over again forever
void loop() {

/*
#ifdef USE_SERIAL_DEBUG
	Serial.print(millis(), DEC);
	Serial.print(" # ");
	Serial.print(timerc.Get(), DEC);
	Serial.print(" # ");
	Serial.print(timerc2.Get(), DEC);
	// Serial.print(" # ");
	// Serial.print(MILLIS_MAXVALUE, DEC);
	// Serial.print(" # ");
	// Serial.print((long)(MILLIS_MAXVALUE*-1), DEC);
	// Serial.print(" # ");
	// Serial.print(MILLIS_MAXVALUE % millis(), DEC);
	Serial.println("");
#endif
*/
	
	boolean t1 = timerc[0].Expired();
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
		Serial.println(timerc[0].Get(), DEC);
		timerc[0].Start();
	}

/*
	if (t2 >= 2000)
	{
		digitalWrite(13, HIGH);
		Serial.print("T2 - ");
		Serial.println(t2, DEC);
		timerc2.Start();
	}
*/

}
