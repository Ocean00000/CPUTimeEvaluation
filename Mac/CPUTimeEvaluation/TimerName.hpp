#pragma once

#include <chrono>

namespace time_evaluation {
	template<class TimerType>
	const char* const get_time_name();

	struct times_kernel_function_clock;

	template<>
	const char* const get_time_name<times_kernel_function_clock>() {
		return "times(kernel)";
	};

	struct times_user_function_clock;

	template<>
	const char* const get_time_name<times_user_function_clock>() {
		return "times(user)";
	};

}
