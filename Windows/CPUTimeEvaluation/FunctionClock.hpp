#pragma once

#include <chrono>
#include <Windows.h>
#include <processthreadsapi.h>

namespace time_evaluation {
	struct GetProcessTimes_kernel_function_clock {
		using rep = long long;
		using period = std::nano;
		using duration=std::chrono::nanoseconds;
		using time_point = std::chrono::time_point<GetProcessTimes_kernel_function_clock>;

		static inline time_point now() noexcept{
			FILETIME creation;
			FILETIME exit;
			FILETIME kernel;
			FILETIME user;
			GetProcessTimes(GetCurrentProcess(), &creation, &exit, &kernel, &user);
			return (time_point(duration(((((ULONGLONG)kernel.dwHighDateTime) << 32) + kernel.dwLowDateTime) * 100)));
		}
	};

	struct GetProcessTimes_user_function_clock {
		using rep = long long;
		using period = std::nano;
		using duration = std::chrono::nanoseconds;
		using time_point = std::chrono::time_point<GetProcessTimes_user_function_clock>;

		static inline time_point now() noexcept {
			FILETIME creation;
			FILETIME exit;
			FILETIME kernel;
			FILETIME user;
			GetProcessTimes(GetCurrentProcess(), &creation, &exit, &kernel, &user);
			return (time_point(duration(((((ULONGLONG)user.dwHighDateTime) << 32) + user.dwLowDateTime) * 100)));
		}
	};

	
}