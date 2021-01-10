#pragma once
#include <string>
#include "iostream"


namespace Logger {
	using namespace std;

	template <typename T>
	inline void debug(T value) {
		cout << "[DEBUG]\t" << value << endl;
	}

	template <typename T>
	void debug(std::string description, T value) {
		cout << "[DEBUG]\t" << description << ": " << value << endl;
	}
}
