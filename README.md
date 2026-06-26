# 🎮 2048 Game (C++)

A console-based implementation of the classic **2048** puzzle game written in **C++**.

The objective of the game is simple: merge tiles with the same value until you create the **2048** tile. Although the rules are easy to learn, mastering the game requires strategic planning and careful decision-making. :contentReference[oaicite:0]{index=0}

---

## 📌 Features

- ✅ Classic 4×4 game board
- ✅ Random generation of new tiles (2 and 4)
- ✅ Tile merging according to the official 2048 rules
- ✅ Score calculation
- ✅ Win detection (2048 tile)
- ✅ Game Over detection
- ✅ Keyboard-controlled gameplay
- ✅ Console-based user interface
- ✅ Written entirely in C++

---

## 🛠️ Technologies Used

- **Language:** C++
- **IDE:** Visual Studio / Code::Blocks (or any C++ IDE)
- **Compiler:** GCC / MSVC
- **Standard Library:** C++ Standard Library

---

## 📂 Project Structure

```
2048-Game/
│
├── Main.cpp        # Complete source code
└── README.md       # Project documentation
```

---

## ▶️ How to Run

### Using g++

Compile the project:

```bash
g++ Main.cpp -o 2048
```

Run:

```bash
./2048
```

### Visual Studio

1. Create a new **Console Application**.
2. Replace the generated source file with `Main.cpp`.
3. Build and Run.

---

## 🎮 How to Play

Use the keyboard to move all tiles on the board.

| Key | Action |
|------|--------|
| w | Move Up |
| s | Move Down |
| a | Move Left |
| d | Move Right |

Whenever two tiles with the same number collide, they merge into one tile with double the value.

After every valid move, a new tile (2 or 4) appears in a random empty position.

The game ends when:

- No empty cells remain.
- No adjacent tiles can be merged.

You win by creating the **2048** tile.

---

## 🧠 Game Rules

- The board size is **4 × 4**.
- At the beginning, two random tiles appear.
- Every move shifts all tiles in the selected direction.
- Equal adjacent tiles merge only once per move.
- Each successful move creates a new random tile.
- Continue merging tiles until reaching **2048** or until no moves remain.

---

## 💡 Concepts Used

This project demonstrates several important C++ programming concepts:

- Functions
- Arrays
- Loops
- Conditional Statements
- Random Number Generation
- Game Logic
- Input Handling
- Console Programming

---

## 📸 Gameplay

Example board:

```

+------+------+------+------+
|      |      |      |  8   |
+------+------+------+------+
|      |      |  2   |  64  |
+------+------+------+------+
|      |  2   |  16  |  4   |
+------+------+------+------+
|      |  4   |  2   |  2   |
+------+------+------+------+

```

---

## 🚀 Future Improvements

- Colored console output
- Undo feature
- High score saving
- Multiple board sizes
- Better UI
- Animation effects
- AI player
- Object-Oriented implementation

---

## 📖 Learning Purpose

This project was developed as a practice project to improve C++ programming skills and strengthen understanding of:

- Algorithm implementation
- Matrix manipulation
- Problem solving
- Game development fundamentals
- Console application development

---

## 👤 Author

**Moeed Gholipour**

GitHub:
https://github.com/Moeedgh

---

## ⭐ If you like this project

Give it a ⭐ on GitHub!