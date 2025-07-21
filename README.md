# 🕹️ Terminal Checkers Game in C

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Status](https://img.shields.io/badge/Status-Completed-green)
![License](https://img.shields.io/badge/License-MIT-lightgrey)

A terminal-based **Checkers (Draughts) game** built using the C programming language. It supports both **multiplayer** and **single-player (vs computer)** modes, includes a **60-second move timer**, **piece capturing**, **king promotion**, and **draw conditions**.

---

## 🎮 Game Modes

- 👥 **Multiplayer Mode** — Two human players take turns.
- 🤖 **Single Player Mode** — Play against a basic AI.

---

## 📷 Board Sample (9x9)
```bash
    0   1   2   3   4   5   6   7   8
  +---+---+---+---+---+---+---+---+---+
0 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
  +---+---+---+---+---+---+---+---+---+
1 | O |   | O |   | O |   | O |   | O |
  +---+---+---+---+---+---+---+---+---+
2 |   | O |   | O |   | O |   | O |   |
  +---+---+---+---+---+---+---+---+---+
3 | O |   | O |   | O |   | O |   | O |
  +---+---+---+---+---+---+---+---+---+
4 |   |   |   |   |   |   |   |   |   |
  +---+---+---+---+---+---+---+---+---+
5 |   |   |   |   |   |   |   |   |   |
  +---+---+---+---+---+---+---+---+---+
6 | X |   | X |   | X |   | X |   | X |
  +---+---+---+---+---+---+---+---+---+
7 |   | X |   | X |   | X |   | X |   |
  +---+---+---+---+---+---+---+---+---+
8 | X |   | X |   | X |   | X |   | X |
  +---+---+---+---+---+---+---+---+---+

```


---

## ⚙️ Features

- 📦 9x9 grid initialized with **Dynamic Memory Allocation**
- ⏳ **60-second** timer for each player move
- ✅ **Move validation** for legal inputs
- 👑 **King Promotion** (X → A, O → B)
- 🔁 **Turn-based control** with move swapping
- 💥 **Capture mechanic** for jumping over opponent pieces
- 💡 **Basic computer AI** in single-player mode
- 🏆 **Win/Draw detection**
- 🖨️ **Formatted ASCII board display**

---

## 🚀 How to Run

### ✅ Prerequisites

- C Compiler (e.g., GCC, MinGW, TDM-GCC)

### 💻 Compile & Run

#### On Windows:
```bash
gcc Final_Project1[1].c -o checkers_game
checkers_game.exe
```
#### On Linux/macOS:
```bash
gcc Final_Project1[1].c -o checkers_game
./checkers_game
```

## 🎯 Objective
Capture all opponent pieces using diagonal moves

Reach the last row to promote your piece to a king

Game can end in a win or a draw (after 4 consecutive invalid moves)



## 🧠 How to Play
Choose Game Mode

1 → Multiplayer (Player vs Player)

2 → Single Player (Player vs Computer AI)

Input Moves

Enter source position (e.g., 6 1)

Enter destination position (e.g., 5 2)

Timer Rules

You have 60 seconds to make each move

If exceeded, the move becomes invalid

Gameplay Rules

Only diagonal moves are allowed

You can capture opponent pieces by jumping

If your piece reaches the opposite end, it is promoted to king

Kings can move diagonally in both forward and backward directions



# 📜 License
This project is licensed under the MIT License.
Feel free to use, modify, and distribute this game for educational or personal use.
