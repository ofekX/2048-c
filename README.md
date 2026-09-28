# 🎮 2048 in C

A terminal implementation of 2048 built in C. Slide tiles, merge matching numbers, and reach the target across three board sizes.

## What's included

- Movement in all four directions
- Random tiles, score tracking, and win/loss detection
- Three board setups: **3×3 → 16**, **2×2 → 32**, and **4×4 → 2048**
- A Makefile for building the game

## Build & Run

With GCC and Make installed, run these commands from the project folder in Linux, macOS, or WSL:

```bash
make
./game2048
```

The Makefile should use `EXEC=game2048`.

## Controls

Type a letter and press **Enter**. Uppercase and lowercase both work.

| Key | Action |
| --- | --- |
| `N` | Start a new game or restart |
| `L` / `R` | Move left / right |
| `U` / `D` | Move up / down |
| `E` | Leave the current board setup |

The three board setups run in order. Pressing `E` advances to the next one; leaving the last setup closes the program. Best scores are kept only for the current setup while it is running.

To remove the compiled files:

```bash
make clean
```
