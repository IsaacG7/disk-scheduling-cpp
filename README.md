# Disk Scheduling Algorithms

A C++ simulation of six classic disk scheduling algorithms, written for my Operating Systems course. Given a starting read head position and 1000 randomly generated cylinder requests, each algorithm calculates the total head movement required to service all requests — demonstrating the performance tradeoffs between scheduling strategies.

---

## Algorithms Implemented

| Algorithm | Description |
|-----------|-------------|
| **FCFS** | First Come First Served — services requests in the order they arrive, no optimization |
| **SSTF** | Shortest Seek Time First — always moves to the closest pending request |
| **SCAN** | Elevator algorithm — sweeps in one direction servicing requests, reverses at the end |
| **C-SCAN** | Circular SCAN — sweeps in one direction only, jumps back to the start when it reaches the end |
| **LOOK** | Like SCAN but only travels as far as the last request in each direction, no end-of-disk travel |
| **C-LOOK** | Like C-SCAN but jumps back to the lowest pending request rather than cylinder 0 |

---

## Requirements

- Linux or WSL (Windows Subsystem for Linux)
- g++ compiler

---

## Compilation

```bash
g++ disk_sched.cpp -o disk_sched
```

---

## Usage

```bash
./disk_sched <starting_position>
```

### Parameters

| Parameter | Type | Description |
|-----------|------|-------------|
| `starting_position` | int | Starting cylinder position of the read head (0–2999) |

The program automatically generates 1000 random cylinder requests in the range 0–2999.

### Example

```bash
./disk_sched 150
```

Starts the read head at cylinder 150 and runs all six algorithms against the same set of 1000 random requests.

---



- Disk size is 3000 cylinders (0–2999), defined as `NUM_CYLINDERS` in `disk_algorithms.h`
- The same 1000 random requests are used for all six algorithms in a single run, making results directly comparable
- Results will differ between runs since requests are randomly generated each time
- Algorithm descriptions and function signatures are defined in `disk_algorithms.h`
