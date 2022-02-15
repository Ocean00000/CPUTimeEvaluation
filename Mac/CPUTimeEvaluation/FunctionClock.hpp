#pragma once

#include <chrono>
#include <sys/times.h>

namespace time_evaluation {
	struct times_kernel_function_clock {
		using rep = long long;
		using period = std::micro;
		using duration=std::chrono::microseconds;
		using time_point = std::chrono::time_point<times_kernel_function_clock>;

		static inline time_point now() noexcept{
            tms time;
            times(&time);
			return (time_point(duration(time.tms_stime + time.tms_cstime)));
		}
	};

	struct times_user_function_clock {
        using rep = long long;
        using period = std::micro;
        using duration=std::chrono::microseconds;
        using time_point = std::chrono::time_point<times_kernel_function_clock>;

        static inline time_point now() noexcept{
            tms time;
            times(&time);
            CLOCKS_PER_SEC;
            return (time_point(duration(time.tms_utime + time.tms_cutime)));
        }
	};

	
}
