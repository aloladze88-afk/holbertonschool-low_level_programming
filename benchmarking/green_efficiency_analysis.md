## Measurement Methodology

All measurements were collected by compiling and executing the lab programs under consistent conditions on the same machine. I used the project’s strict compilation flags (`-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`) to keep builds comparable. The programs report CPU time in seconds via `clock()`, and I recorded the outputs exactly as printed.

For baseline measurement, I ran the baseline loop program several times in sequence and logged the results in `baseline_loop-metrics.md` to get a repeatable reference point.

For algorithmic efficiency, I ran the comparison program that implements two approaches to the same calculation and captured totals and timings in `comparison_algorithms-metrics.md`. I treated matching totals as the correctness check.

For controlled instrumentation, I compiled and executed `instrumentation_lab.c`, which prints TOTAL runtime plus per-phase timings (e.g., BUILD_DATA and PROCESS) so time can be attributed to code sections.

## Observed Performance Differences

The algorithmic comparison shows the largest gap. Across repeated runs in `comparison_algorithms-metrics.md`, both approaches produced the same total (150000), but the naive approach took 3.042722 s, 3.181981 s, and 3.138245 s (mean ≈ 3.120983 s). The single-pass approach consistently reported 0.000107 s. That corresponds to an average speed-up of about 29,168× (3.120983 ÷ 0.000107) while preserving the result.

Instrumentation adds localisation. In one run of `instrumentation_lab.c`, TOTAL = 0.000919 s and BUILD_DATA = 0.000370 s, so BUILD_DATA accounts for ~40% of measured time, with the remainder spent in the later processing phase(s). Even when absolute times are small, this breakdown identifies which phase dominates.

## Relation Between Runtime and Energy Consumption

This lab does not measure electrical power, so it cannot report joules or watts. Still, when two correct implementations do the same work on the same machine, longer CPU-active time usually implies higher cumulative energy use if the workload is repeated. The naive vs single-pass timings illustrate how design choices can multiply CPU time for identical output.

## Limitations of the Experiment

Very small timings are sensitive to `clock()` resolution, OS scheduling, background activity, caching, and CPU frequency scaling. The number of runs is limited, so results indicate direction and magnitude rather than providing a statistical confidence interval. CPU time is also not wall-clock time, and neither equals energy without direct power measurement.

## Practical Engineering Takeaway

Start with a baseline (`baseline_loop-metrics.md`), compare only implementations that produce the same output (`comparison_algorithms-metrics.md`), then instrument phases (`instrumentation_lab.c`) to see where runtime is actually spent. The key lesson is that reducing repeated work through better algorithmic structure can dwarf minor code-level tweaks by orders of magnitude.