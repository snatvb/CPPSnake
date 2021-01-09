#pragma once
#include "Time.h"

namespace Core {
	class Time;
	class TimerCalling {

		TimerCalling(double timeout, void(&callback)());

		void execute();
	private:
		double m_timeout;
		double m_lostTime;
		void (&m_callback)();
	};
}
