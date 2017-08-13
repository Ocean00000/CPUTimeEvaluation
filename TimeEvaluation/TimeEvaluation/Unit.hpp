#pragma once

#include <chrono>

namespace time_evaluation {
	template<class DurationType>
	const char* const getUnit();

	template<>
	const char* const  getUnit<std::chrono::nanoseconds>() {
		return "nanosecond";
	};

	template<>
	const char* const  getUnit<std::chrono::microseconds>() {
		return "microsecond";
	};

	template<>
	const char* const  getUnit<std::chrono::milliseconds>() {
		return "millisecond";
	};

	template<>
	const char* const  getUnit<std::chrono::seconds>() {
		return "second";
	};
}