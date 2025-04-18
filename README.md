# Multi‑Paradigm Statistics Calculator

This repository contains three implementations of a basic statistics calculator (mean, median, mode), each demonstrating a different programming paradigm:

- **C (Procedural)**  
  File: `stats.c`  
  - Uses raw arrays, manual memory management, and `qsort`.
- **OCaml (Functional)**  
  File: `stats.ml`  
  - Uses immutable lists, `List.fold_left`, `List.sort`, and pure functions.
- **Python (Object‑Oriented)**  
  File: `stats.py`  
  - Defines a `StatisticsCalculator` class encapsulating all operations.

---

## Prerequisites

- **C**  
  - GCC (or another C compiler)  
- **OCaml**  
  - OCaml compiler (`ocamlc`, `ocamlopt`) or Dune  
- **Python**  
  - Python 3.x  

---

## Compilation & Execution

### C (Procedural)

```bash
# Compile
gcc -std=c11 -Wall -Wextra -O2 -o stats stats.c

# Run
./stats

# Interpret directly
ocaml stats.ml

# OR compile to bytecode
ocamlc -o stats stats.ml && ./stats

# OR compile native
ocamlopt -o stats stats.ml && ./stats

python3 stats.py

Mean:   2.40
Median: 2.00
Mode:   2

