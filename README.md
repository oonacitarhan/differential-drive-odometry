# Differential Drive Odometry

Integrate differential-drive encoder logs with calibrated wheel geometry and exact constant-curvature pose updates.

**C++** · Reusable core · CLI examples · Regression checks · Reproducible benchmark

> **Provenance:** created with AI assistance on **2026-11-01**.
> All commit author and committer dates are synthetic and distributed across
> November 2024–October 2026. They do not establish work on those dates.

## Quick start

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j2
./build/experiment_cli examples/encoders.csv 0.0762 0.55 2048
```

## Repository map

- `include/` — public algorithm and analysis interfaces.
- `src/` — library implementation and CLI.
- `tests/` — independent reference and analysis executables.
- `examples/` — standalone library consumer and input fixtures.
- `benchmarks/` — compiled workload.
- `CMakeLists.txt` — library, executable and CTest targets.

## How it works

Wheel increments determine arc length and heading change. A sinc-form update avoids a division singularity near straight motion. Encoder calibration converts ticks to meters before integration; CSV replay produces a trajectory. Tests verify straight lines, in-place turns, circular arcs, subdivision consistency, and reversed increments.

## Verification

```sh
sh scripts/check.sh
```

Three CTest suites with multiple assertion C++ checks exercise reference cases, invalid inputs, and relevant invariants.
The complete local run is in [docs/verification.txt](docs/verification.txt).
The [checks workflow](.github/workflows/check.yml) executes the same source checks.

## Boundaries

Assumes planar no-slip differential-drive motion and constant curvature within each sample. Encoder inputs are increments, not cumulative counts. No IMU fusion, uncertainty model, time synchronization, or hardware deployment is included.

See [architecture](docs/architecture.md), [usage](docs/usage.md),
[release notes](CHANGELOG.md), and [provenance](PROVENANCE.json).

## License

MIT — [LICENSE](LICENSE).
