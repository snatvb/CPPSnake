#pragma once
#include <chrono>

namespace Core {
	using namespace std::chrono;

	class Time {
	public:
		static std::chrono::duration<double> delta;
		static void init();
		static void update();

	private:
		static steady_clock::time_point m_lastTime;
	};
}
