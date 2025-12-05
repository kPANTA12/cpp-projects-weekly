# C++ Weekly Projects

## Overview
This is a collection of weekly C++ projects designed to strengthen problem-solving skills, improve coding fundamentals, and build a complete portfolio over time. The repository contains small-to-medium projects built every week, covering topics from basics to OOP, STL, data structures, file handling, and algorithms.

**Goal:** Complete 1 C++ project every week to build consistency, mastery, and hands-on experience.

## Current State
- **Active Project:** Week 01 - Number Guessing Game
- **Language:** C++
- **Compiler:** Clang 14 (C++11 standard)
- **Status:** Fully functional and ready to run

## Project Architecture

### Week 01: Number Guessing Game
**Location:** `Week01_NumberGuessingGame/src/main.cpp`

**Features:**
- Random number generation (1-100)
- User input validation
- Attempt tracking (max 10 attempts)
- High/low hints
- Play again functionality
- Error handling for invalid inputs

**Build System:**
- Manual compilation using Clang++
- C++11 standard
- Single source file architecture

## How to Run

The project is configured to run automatically in Replit. The workflow compiles and executes the Number Guessing Game:

1. Click the "Run" button in Replit
2. The game will compile and start automatically
3. Follow the on-screen prompts to play

**Manual compilation (if needed):**
```bash
cd Week01_NumberGuessingGame
clang++ -std=c++11 -o game src/main.cpp
./game
```

## Project Structure
```
.
├── Week01_NumberGuessingGame/
│   ├── src/
│   │   └── main.cpp          # Main game implementation
│   └── README.md
├── README.md                  # Main repository README
└── replit.md                  # This file
```

## Recent Changes
- **Dec 5, 2024:** Initial setup in Replit environment
  - Implemented Number Guessing Game
  - Installed C++ Clang 14 toolchain
  - Configured workflow for automatic compilation and execution
  - Added .gitignore for C++ build artifacts

## Technologies & Concepts
Each project helps practice important C++ concepts:
- Variables, loops, conditions
- Functions & modular programming
- Object-Oriented Programming (OOP)
- File handling (read/write)
- STL (vector, map, set, queue, stack)
- Data structures & algorithms
- Error handling & clean coding

## Upcoming Projects
- Week 02: Calculator App
- Week 03: Student Report Card System
- Week 04: To-Do List (File Handling)
- Week 05: Bank Management System (OOP)
- And more...

## Development Notes
- This is a console-based application (no frontend/backend separation)
- All projects are compiled and run directly in the terminal
- Uses standard C++ libraries only (no external dependencies)
