#include "TimerCalling.h"

Core::TimerCalling::TimerCalling(double timeout, void(&callback)())
	: m_timeout(timeout), m_callback(callback)
{
}

void Core::TimerCalling::execute()
{
	if (m_lostTime <= 0) {
		m_callback();
		m_lostTime = m_timeout;
	} else {
		m_lostTime -= Time::delta.count();
	}
}
