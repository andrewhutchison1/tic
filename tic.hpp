#ifndef AH1_TIC_HPP_
#define AH1_TIC_HPP_

#include <chrono>

namespace ah1 {

template <
	typename Clock = std::chrono::high_resolution_clock,
	typename DefaultDuration = std::chrono::microseconds>
//	requires TrivialClock<Clock>
class basic_tic
{
public:
	using clock_type = Clock;

	template <typename Duration = DefaultDuration>
	auto toc() const noexcept -> Duration
	{
		auto const delta = clock_type::now() - start_;
		return std::chrono::duration_cast<Duration>(delta);
	}
private:
	std::chrono::time_point<clock_type> const start_{clock_type::now()};
};

using tic = basic_tic<std::chrono::high_resolution_clock>;

} // namespace ah1

#endif // AH1_TIC_HPP_
