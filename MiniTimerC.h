//
// MiniTimerC
// Ermanno De Giuli
// edg@flx.it - 2016
//

#ifndef _MINITIMERC_h
#define _MINITIMERC_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class MiniTimerC
{
public:
	MiniTimerC();
	void Start();
	uint32_t Get();
	void SetExpire(uint32_t);
	boolean Expired();
protected:
private:
	uint8_t _t_timers;
	uint32_t _t_set_ms;
	uint32_t _t_start_ms;
	uint32_t _t_exp_ms;
};
#endif

