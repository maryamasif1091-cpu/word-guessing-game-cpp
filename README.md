# 🎮 Word Guessing Game (C++ OOP Project)

##  Overview
This is a console-based Word Guessing Game developed in C++ using Object-Oriented Programming concepts. The game uses a dynamically generated grid where hidden words are placed in different directions, and the player must guess them correctly. It includes Easy and Hard modes with multiple levels, score tracking, and file handling.

##  Project Structure
- Header.h → Contains all class declarations, function prototypes, and global utilities
- source.cpp → Contains main implementation of all classes and game logic
- source1.cpp → Contains the main() function that starts the game

##  Features
- Dynamic 2D grid creation using pointers
- Word placement in horizontal, vertical, and diagonal directions
- Word validation using dictionary file
- Score tracking system with file saving
- Easy and Hard game modes
- Multiple levels in each mode
- Console color formatting using ANSI escape codes
- Exception handling for safe execution
- File handling for words and scores

##  Game Modes

###  Easy Mode
- Word length: 2–4 characters
- Level 1: Guess 3 words
- Level 2: Guess 5 words
- Level 3: Guess 7 words
- Word source: easy_words.txt (50 words)

###  Hard Mode
- Word length: 5–7 characters
- Level 1: Guess 3 words
- Level 2: Guess 5 words
- Level 3: Guess 7 words
- Word source: hard_words.txt (50 words)

##  Game Flow
1. Program starts from main() in source1.cpp
2. Main menu is displayed:
   - Start Game
   - Instructions
   - Highest Scores
   - About Us
   - Exit
3. Player selects Easy or Hard mode
4. Game loads grid and words for each level
5. Player guesses words from grid
6. Scores are updated and saved automatically

##  Core Mechanics
- Grid size changes with level:
  - Level 1 → 10x10
  - Level 2 → 15x15
  - Level 3 → 20x20
- Words are randomly placed in grid
- Remaining spaces are filled with random characters
- Words can appear horizontally, vertically, or diagonally
- Validation is done using:
  - Dictionary file check
  - Grid search logic

##  Classes Used
- Game → Controls overall game flow and menu
- Grid → Handles grid allocation, filling, and display
- Word_check → Loads dictionary and validates words
- Score_info → Tracks and saves player scores
- Level → Base abstract class for levels
- Easy_levels → Implements easy mode logic
- Difficult_levels → Implements hard mode logic

##  How to Compile and Run

### Compile:
g++ source.cpp source1.cpp -o game

### Run:
./game

##  Required Files
- easy_words.txt → 50 words (2–4 letters)
- hard_words.txt → 50 words (5–7 letters)
- scores.txt → Automatically generated for storing scores

##  Notes
- ANSI escape codes are used for console colors
- Dynamic memory is properly managed (allocation/deallocation)
- Exception handling is implemented for safety
- Grid supports multi-direction word search (horizontal, vertical, diagonal)
