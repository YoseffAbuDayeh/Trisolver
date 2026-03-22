# TriSolver

![C](https://img.shields.io/badge/language-C-blue?logo=c) ![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey)

A command-line triangle solver written in C. Given any valid combination of sides and angles, TriSolver computes all missing measurements and classifies the triangle — no calculator needed.

---

## Features

- Solves all four standard triangle cases: **SSS**, **SAS**, **ASA**, and **SSA**
- Applies the **Law of Sines** and **Law of Cosines** via `math.h`
- Computes **area** (Heron's formula) and **perimeter**
- Classifies triangles by side type (Equilateral, Isosceles, Scalene) and angle type (Acute, Right, Obtuse)
- Detects and rejects **impossible triangles** before output
- Validates input format and unknown commands with descriptive error messages
- Accepts `quit`, `exit`, `end`, or `bye` to cleanly terminate
- Case-insensitive command input

---

## Tech Stack

- **Language:** C (C99)
- **Libraries:** `math.h`, `string.h`, `ctype.h`, `stdio.h`
- **Build:** Microsoft Visual Studio (`.sln`)

---

## Usage

Run the compiled executable from your terminal. Each query follows the format:

```
-> <FORMAT> <value1> <value2> <value3>
```

where `FORMAT` is one of `SSS`, `SAS`, `ASA`, or `SSA`, and values are real numbers representing sides (S) or angles in degrees (A) in the order implied by the format.

**Examples:**

```
-> SSS 3 4 5
-> SAS 7 60 10
-> ASA 45 10 90
-> SSA 8 6 35
-> quit
```

**Sample output:**

```
Format: SSS
a =  3.000    alpha =   36.870
b =  4.000    beta  =   53.130
c =  5.000    gamma =   90.000
Perimeter =  12.000
Area      =   6.000
Type      = Scalene, Right
```

---

## Installation

```bash
# Clone the repository
git clone https://github.com/YoseffAbuDayeh/Trisolver.git
cd Trisolver
```

**Windows (Visual Studio):**
Open `YA_Project1.sln` and build with Ctrl+B, then run with Ctrl+F5.

**Linux / macOS (GCC):**
```bash
gcc trisolver/trisolver.c -o trisolver -lm
./trisolver
```

---

## How It Works

Each triangle case is handled by a dedicated function using standard trigonometric identities:

| Case | Method Used |
|------|-------------|
| SSS  | Law of Cosines → all three angles |
| SAS  | Law of Cosines → opposite side, then Law of Sines |
| ASA  | Angle sum → third angle, Law of Sines → both sides |
| SSA  | Law of Sines → second angle, then Law of Cosines |

A shared `finalPrint()` function handles classification, area/perimeter calculation, and triangle validity checking, keeping each solver function focused on the math alone.

---

*Academic project — Fanshawe College Computer Programmer Analyst program, 2023.*