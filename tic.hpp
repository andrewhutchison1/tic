#ifndef TIC_HPP_
#define TIC_HPP_

#include <chrono>

template <
	typename Clock = std::chrono::high_resolution_clock,
	typename DefaultDuration = std::chrono::microseconds>
//	requires TrivialClock<Clock>
class basic_tic
{
public:
	template <typename Duration = DefaultDuration>
	auto toc() const noexcept -> Duration
	{
		return std::chrono::duration_cast<Duration>(Clock::now() - start_);
	}
private:
	std::chrono::time_point<Clock> const start_{Clock::now()};
};

using tic = basic_tic<std::chrono::high_resolution_clock>;

#endif // TIC_HPP_
