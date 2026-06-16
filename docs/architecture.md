# Architecture

Wheel increments determine arc length and heading change. A sinc-form update avoids a division singularity near straight motion. Encoder calibration converts ticks to meters before integration; CSV replay produces a trajectory. Tests verify straight lines, in-place turns, circular arcs, subdivision consistency, and reversed increments.

## Data flow

- `include/` — public algorithm and analysis interfaces.
- `src/` — library implementation and CLI.
- `tests/` — independent reference and analysis executables.
- `examples/` — standalone library consumer and input fixtures.
- `benchmarks/` — compiled workload.
- `CMakeLists.txt` — library, executable and CTest targets.

## Limits

Assumes planar no-slip differential-drive motion and constant curvature within each sample. Encoder inputs are increments, not cumulative counts. No IMU fusion, uncertainty model, time synchronization, or hardware deployment is included.
