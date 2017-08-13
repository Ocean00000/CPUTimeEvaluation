#pragma once

#include <chrono>
#include <Windows.h>
#include <mmsystem.h>

namespace time_evaluation {
	struct GetSystemTimeAsFileTime_function_clock {
		typedef long long rep;
		typedef std::nano period;
		typedef std::chrono::nanoseconds duration;
		typedef std::chrono::time_point<GetSystemTimeAsFileTime_function_clock> time_point;

		static inline time_point now() _NOEXCEPT {
			FILETIME filetime;
			GetSystemTimeAsFileTime(&filetime);
			return (time_point(duration(((((ULONGLONG)filetime.dwHighDateTime) << 32) + filetime.dwLowDateTime) * 100)));
		}
	};

	struct GetSystemTimePreciseAsFileTime_function_clock {
		typedef long long rep;
		typedef std::nano period;
		typedef std::chrono::nanoseconds duration;
		typedef std::chrono::time_point<GetSystemTimePreciseAsFileTime_function_clock> time_point;

		static inline time_point now() _NOEXCEPT {
			FILETIME filetime;
			GetSystemTimePreciseAsFileTime(&filetime);
			return (time_point(duration(((((ULONGLONG)filetime.dwHighDateTime) << 32) + filetime.dwLowDateTime) * 100)));
		}
	};

	struct QueryPerformanceCounter_function_clock {
		typedef long long rep;
		typedef std::nano period;
		typedef std::chrono::nanoseconds duration;
		typedef std::chrono::time_point<QueryPerformanceCounter_function_clock> time_point;

		static inline time_point now() _NOEXCEPT {
			static const LARGE_INTEGER qpf = getQueryPerformanceFrequency();
			LARGE_INTEGER qpc;
			QueryPerformanceCounter(&qpc);
			return (time_point(duration((qpc.QuadPart * period::den) / qpf.QuadPart)));
		}
	private:
		static inline LARGE_INTEGER getQueryPerformanceFrequency() {
			LARGE_INTEGER qpf;
			QueryPerformanceFrequency(&qpf);
			return qpf;
		}
	};

	struct timespec_get_function_clock {
		typedef long long rep;
		typedef std::nano period;
		typedef std::chrono::nanoseconds duration;
		typedef std::chrono::time_point<timespec_get_function_clock> time_point;

		static inline time_point now() _NOEXCEPT {
			timespec time;
			timespec_get(&time, TIME_UTC);
			return (time_point(duration(time.tv_sec * period::den + time.tv_nsec)));
		}
	};

	struct clock_function_clock {
		typedef long long rep;
		typedef std::milli period;
		typedef std::chrono::milliseconds duration;
		typedef std::chrono::time_point<clock_function_clock> time_point;

		static inline time_point now() _NOEXCEPT {
			return (time_point(duration(clock())));
		}
	};

	struct GetTickCount_function_clock {
		typedef long long rep;
		typedef std::milli period;
		typedef std::chrono::milliseconds duration;
		typedef std::chrono::time_point<GetTickCount_function_clock> time_point;

		static inline time_point now() _NOEXCEPT {
			return (time_point(duration(GetTickCount())));
		}
	};

	struct GetTickCount64_function_clock {
		typedef long long rep;
		typedef std::milli period;
		typedef std::chrono::milliseconds duration;
		typedef std::chrono::time_point<GetTickCount64_function_clock> time_point;

		static inline time_point now() _NOEXCEPT {
			return (time_point(duration(GetTickCount64())));
		}
	};

	struct timeGetTime_function_clock {
		typedef long long rep;
		typedef std::milli period;
		typedef std::chrono::milliseconds duration;
		typedef std::chrono::time_point<timeGetTime_function_clock> time_point;
		static constexpr bool is_steady = false;

		static inline time_point now() _NOEXCEPT {
			return (time_point(duration(timeGetTime())));
		}
	};

	struct time_function_clock {
		typedef long long rep;
		typedef std::ratio<1, 1> period;
		typedef std::chrono::seconds duration;
		typedef std::chrono::time_point<time_function_clock> time_point;

		static inline time_point now() _NOEXCEPT {
			time_t timer;
			time(&timer);
			return (time_point(duration(static_cast<long long>(timer))));
		}
	};
}