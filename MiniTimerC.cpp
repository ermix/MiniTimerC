//
// MiniTimerC
// Ermanno De Giuli
// edg@flx.it - 2016
//

#include "MiniTimerC.h"

/// <summary>
/// 
/// </summary>
MiniTimerC::MiniTimerC()
{
	_t_set_ms = 0;
}

/// <summary>
/// Start the timer
/// </summary>
void MiniTimerC::Start()
{
	_t_start_ms = millis();
}

/// <summary>
/// Return elapsed time from Start
/// </summary>
uint32_t MiniTimerC::TimeElapsed()
{
	return millis() - _t_start_ms - _t_set_ms;
}

/// <summary>
/// Set expire time 
/// </summary>
void MiniTimerC::ExpireIn(uint32_t t_exp_ms)
{
	_t_exp_ms = t_exp_ms;
}

/// <summary>
/// Return if the time is expired
/// </summary>
boolean MiniTimerC::IsExpired()
{
	return (millis() - _t_start_ms - _t_set_ms) >= _t_exp_ms;
}

