# Tic
A tiny, lightweight implementation of MATLAB-style differential duration
timing in clean C++14. To install, simply put `tic.hpp` in your project
directory or on your compiler's include path.

### Usage
To start a timer, simply construct a named `tic`. Call `toc` on it to get
a `std::chrono::duration` object that represents the elapsed time.

```
auto timer = tic{};
// ...
// Do some stuff you want to time
// ...
auto duration = timer.toc(); // duration stores the elapsed time
```

You can parameterize the timer based on the type of clock you want to use;
alias `basic_tic` with a type satisfying `TrivialClock` to achieve this.
`tic` is an alias for `basic_tic<std::chrono::high_resolution_clock>`.
The member function `toc` is parameterised by a duration type, the default
is `std::chrono::milliseconds`.

```
auto timer = basic_tic<std::chrono::steady_clock>; // Use a monotonic clock
// ...
auto duration = timer.toc<std::chrono::seconds>(); // Elapsed seconds
```

`toc` does not reset the timer:

```
auto timer = tic{};
std::this_thread::sleep_for(1s);
auto dur1 = timer.toc(); // dur1 ~= 1000 ms
std::this_thread::sleep_for(1s);
auto dur2 = timer.toc(); // dur2 ~= 2000 ms
```
