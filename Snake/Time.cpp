#include "Time.h"

namespace Core {
	std::chrono::duration<double> Time::delta;
	steady_clock::time_point Time::m_lastTime;

	void Time::update()
	{
		auto now = high_resolution_clock::now();
		Time::delta = now - m_lastTime;
		Time::m_lastTime = now;
	}

	void Time::init()
	{
		Time::m_lastTime = high_resolution_clock::now();
	}
}
