#pragma once

#include <chrono>

namespace time_evaluation {
	template<class DurationType>
	const char* const get_unit();

	template<>
	const char* const  get_unit<std::chrono::nanoseconds>() {
		return "nanosecond";
	};

}