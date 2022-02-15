#pragma once

#include <chrono>

namespace time_evaluation {
	template<class TimerType>
	const char* const get_time_name();

	struct GetProcessTimes_kernel_function_clock;

	template<>
	const char* const get_time_name<GetProcessTimes_kernel_function_clock>() {
		return "GetProcessTimes(kernel)";
	};

	struct GetProcessTimes_user_function_clock;

	template<>
	const char* const get_time_name<GetProcessTimes_user_function_clock>() {
		return "GetProcessTimes(user)";
	};

}