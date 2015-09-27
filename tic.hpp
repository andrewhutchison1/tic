#ifndef TIC_HPP_
#define TIC_HPP_

#include <chrono>

template <typename Clock = std::chrono::high_resolution_clock>
//	requires TrivialClock<Clock>
class basic_tic
{
public:
	basic_tic() noexcept
		: start_{Clock::now()}
	{ /* Nothing */ }

	template <typename Duration = std::chrono::milliseconds>
	auto toc() const noexcept -> Duration
	{
		return std::chrono::duration_cast<Duration>(Clock::now() - start_);
	}
private:
	std::chrono::time_point<Clock> start_;
};

using tic = basic_tic<std::chrono::high_resolution_clock>;

#endif // TIC_HPP_
