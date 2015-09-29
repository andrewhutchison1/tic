# Tic
A tiny, lightweight implementation of MATLAB-style differential duration
timing in clean C++14. To install, simply `#include "tic.hpp"`. Compiles
under `-std=c++11` as well as `-std=c++14`.

## Usage
### Timing a region of code
To time a region of code, construct a named `tic` at the desired start
position and call the `toc` method to get the duration.

```cpp
// Timing a region of code
auto timer = tic{};
// ...
// Some stuff that we want to time
// ...
auto dur = timer.toc(); // dur is std::chrono::microseconds
```

`toc` does not reset the timer.

### Using a different clock
`tic` uses `std::chrono::high_resolution_clock` as its default
clock. In fact, `tic` is an alias of the unparameterised template
`basic_tic<Clock>`. You can make an alias of `basic_tic` to any type that
satisfies `TrivialClock`.

```cpp
// Using a different clock
using steady_tic = basic_tic<std::chrono::steady_clock>; // Monotonic clock
auto timer = steady_tic{};
// ...
auto dur = timer.toc(); // dur is std::chrono::microseconds
```

### Controlling the duration returned by `toc`
`tic` uses `std::chrono::microseconds` as the default duration type
returned by `toc`. To avoid having to perform a `duration_cast` after
calling `toc`, you can control the duration returned by `toc` in two
related ways.

1. Explicitly parameterize the call to `toc`
2. Alias `basic_tic` with a `DefaultDuration` parameter

```cpp
// 1. Explicitly parameterize the call the toc
auto timer = tic{}; // Uses the default clock
// ...
auto dur = timer.toc<std::chrono::seconds>(); // dur is std::chrono::seconds

// 2. Alias basic_tic with a DefaultDuration parameter
using tic_s = basic_tic<
	std::chrono::high_resolution_clock,
	std::chrono::seconds>;
auto timer = tic_s{};
// ...
auto dur = timer.toc(); // dur is std::chrono::seconds
// But you can still explicitly request a different duration
auto dur2 = timer.toc<std::chrono::hours>(); // dur is std::chrono::hours
```
