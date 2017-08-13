#include "stdafx.h"
#include "TimerName.hpp"
#include "FunctionClock.hpp"
#include "Unit.hpp"
#include <chrono>
#include <iostream>

using namespace time_evaluation;
using namespace std::chrono;
using namespace std;

namespace {
	template<class ClockType, class DurationType>
	double getLatency(const size_t count) {
		const typename ClockType::time_point start = ClockType::now();
		for (int i = 0; i < count; ++i) {
			ClockType::now();
		}
		const typename ClockType::time_point stop = ClockType::now();

		return static_cast<double>(duration_cast<DurationType>(stop - start).count()) / (count + 1);
	}

	template<class ClockType, class DurationType>
	double getResolutionTime(const size_t& count) {
		size_t index = 0;
		typename ClockType::time_point next;
		long long sum = 0;
		for (typename ClockType::time_point last = ClockType::now(); index < count; last = ClockType::now()) {
			next = ClockType::now();
			if (last != next) {
				++index;
				sum += duration_cast<DurationType>(next - last).count();
			}
		}

		return static_cast<double>(sum) / index;
	}

	template<class ClockType, class DurationType>
	void outputTime(const pair<size_t, size_t>& count) {
		cout << getTimeName<ClockType>() << "," << std::fixed << getResolutionTime<ClockType, DurationType>(count.first) << "," << getUnit<DurationType>()
			<< "," << std::fixed << getLatency<ClockType, nanoseconds>(count.second) << "," << getUnit<nanoseconds>() << endl;
	}
}

int main() {
	const pair<size_t, size_t> count{ 2000, 50000000 };
	SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS);
	cout << "Timer,Resolution,Unit,Latency,Unit" << endl;
	outputTime<system_clock, nanoseconds>(count);
	outputTime<steady_clock, nanoseconds>(count);
	outputTime<GetSystemTimeAsFileTime_function_clock, nanoseconds>(count);
	outputTime<GetSystemTimePreciseAsFileTime_function_clock, nanoseconds>(count);
	outputTime<QueryPerformanceCounter_function_clock, nanoseconds>(count);
	outputTime<timespec_get_function_clock, nanoseconds>(count);
	outputTime<clock_function_clock, milliseconds>(count);
	outputTime<GetTickCount_function_clock, milliseconds>(count);
	outputTime<GetTickCount64_function_clock, milliseconds>(count);
	outputTime<timeGetTime_function_clock, milliseconds>(count);
	outputTime<time_function_clock, seconds>(make_pair(20, count.second));

	SetPriorityClass(GetCurrentProcess(), NORMAL_PRIORITY_CLASS);

	return 0;
}