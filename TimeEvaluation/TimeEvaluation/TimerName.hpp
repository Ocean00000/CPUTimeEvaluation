#pragma once

#include <chrono>

namespace time_evaluation {
	template<class TimerType>
	const char* const getTimeName();

	template<>
	const char* const getTimeName<std::chrono::system_clock>() {
		return "chrono::system_clock";
	};

	template<>
	const char* const getTimeName<std::chrono::steady_clock>() {
		return "chrono::steady_clock";
	};

	struct GetSystemTimeAsFileTime_function_clock;

	template<>
	const char* const getTimeName<GetSystemTimeAsFileTime_function_clock>() {
		return "GetSystemTimeAsFileTime";
	};

	struct GetSystemTimePreciseAsFileTime_function_clock;

	template<>
	const char* const getTimeName<GetSystemTimePreciseAsFileTime_function_clock>() {
		return "GetSystemTimePreciseAsFileTime";
	};

	struct QueryPerformanceCounter_function_clock;

	template<>
	const char* const getTimeName<QueryPerformanceCounter_function_clock>() {
		return "QueryPerformanceCounter";
	};

	struct timespec_get_function_clock;

	template<>
	const char* const getTimeName<timespec_get_function_clock>() {
		return "timespec_get";
	};

	struct clock_function_clock;

	template<>
	const char* const getTimeName<clock_function_clock>() {
		return "clock";
	};

	struct GetTickCount_function_clock;

	template<>
	const char* const getTimeName<GetTickCount_function_clock>() {
		return "GetTickCount";
	};

	struct GetTickCount64_function_clock;

	template<>
	const char* const getTimeName<GetTickCount64_function_clock>() {
		return "GetTickCount64";
	};

	struct timeGetTime_function_clock;

	template<>
	const char* const getTimeName<timeGetTime_function_clock>() {
		return "timeGetTime";
	};

	struct time_function_clock;

	template<>
	const char* const getTimeName<time_function_clock>() {
		return "time";
	};
}