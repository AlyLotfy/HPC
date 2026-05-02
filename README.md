# High-Performance Computing — AAST Student Cluster

**Parallel-computing assignments and benchmarks executed on AAST's student HPC cluster.**

[![C](https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=black)](#)
[![MPI](https://img.shields.io/badge/MPI-OpenMPI-005F9E)](#)
[![OpenMP](https://img.shields.io/badge/OpenMP-thread_parallel-green)](#)
[![Linux](https://img.shields.io/badge/Linux-FCC624?logo=linux&logoColor=black)](#)

---

## Overview

This repository contains the work I did using **AAST's student HPC cluster** for the High-Performance Computing course. The focus is on understanding **why** parallelism matters, **where** it pays off, and **what breaks** when you scale up — not just running pre-baked benchmarks.

---

## Topics Covered

- **Shared-memory parallelism** with **OpenMP** — `#pragma omp parallel for`, reductions, critical sections
- **Distributed-memory parallelism** with **MPI** — `MPI_Send`, `MPI_Recv`, collective operations (`MPI_Bcast`, `MPI_Reduce`)
- **Hybrid MPI + OpenMP** — combining both for multi-node, multi-core workloads
- **Profiling & speedup analysis** — Amdahl's law in practice, strong vs. weak scaling
- **Cluster job submission** — SLURM batch scripts, resource allocation

---

## Tech Stack

- **C** — primary language
- **OpenMP** — shared-memory threading
- **OpenMPI** — distributed-memory message passing
- **SLURM** — job scheduler on the AAST cluster
- **gcc** — compiler

---

## Building & Running

### OpenMP example
```bash
gcc -O2 -fopenmp src/openmp_example.c -o openmp_example
OMP_NUM_THREADS=8 ./openmp_example
```

### MPI example
```bash
mpicc -O2 src/mpi_example.c -o mpi_example
mpirun -np 4 ./mpi_example
```

### On the cluster (SLURM)
```bash
sbatch jobs/run.slurm
squeue -u $USER
```

---

## Related Work

- [Parallel-Distribution-in-Machine-Learning-Models](https://github.com/AlyLotfy/Parallel-Distribution-in-Machine-Learning-Models) — applying these HPC techniques specifically to scaling ML training

---

## License

Academic coursework, AAST College of Artificial Intelligence.
