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
/// Start the timer, store current time 
/// </summary>
void MiniTimerC::Start()
{
	_t_start_ms = millis();
}

/// <summary>
/// Return elapsed time from start time
/// </summary>
uint32_t MiniTimerC::Get()
{
	return millis() - _t_start_ms - _t_set_ms;
}

/// <summary>
/// Set expire time 
/// </summary>
void MiniTimerC::SetExpire(uint32_t t_exp_ms)
{
	_t_exp_ms = t_exp_ms;
}

/// <summary>
/// Return if the expire time is elapsed
/// </summary>
boolean MiniTimerC::Expired()
{
	return (millis() - _t_start_ms - _t_set_ms) >= _t_exp_ms;
}

