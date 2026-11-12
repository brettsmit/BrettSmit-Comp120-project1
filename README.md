# Brett Smit Comp120 Project 1 Tic-Tac-Toe vs. Computer

Description

This project is a simple Tic-Tac-Toe game written in C where a user plays against the computer. The game is played on a 3x3 board, with the user playing as O and the computer playing as X. The user always goes first.

Players take turns selecting an empty square by entering its corresponding number (0–8). The computer randomly selects an available square for its moves. The game continues until either player gets three symbols in a row horizontally, vertically, or diagonally, or all nine squares are filled resulting in a draw.

After each game, the user can choose to play again or quit the program.


Features


Play Tic-Tac-Toe against a computer opponent.

Numbered 3x3 game board with positions from 0 to 8.

Random computer moves using rand().

Win detection for all horizontal, vertical, and diagonal combinations.

Draw detection when all nine squares are occupied.

Input validation to prevent invalid or occupied square selections.

Option to play multiple games without restarting the program.


Code Overview


The program is organized into separate functions to keep the code organized and easier to understand.

init_board() – Initializes all nine board positions as empty.

display_board() – Displays the game board using a temporary character array (char c[9]) to show the available square numbers.

other_player() – Switches between the human player (O) and computer (X).

get_human_move() – Requests a square selection from the user and checks that the move is valid.

get_computer_move() – Randomly selects an available square for the computer.

take_turn() – Determines whose turn it is and places the appropriate symbol on the board.

is_winner() – Checks all eight possible winning combinations to determine whether a player has won.

play_game() – Controls the game flow, including turns, board updates, win detection, and draws.

play_again() – Asks the user whether they would like to play another game.


Concepts Practiced


This project demonstrates several fundamental C programming concepts, including:

Variables and data types (int, char, and bool).

One-dimensional character arrays.

User-defined functions and function parameters.

Conditional statements (if, else if, and else).

Loops (for, while, and do...while).

Boolean expressions and logical operators.

User input and output using scanf() and printf().

Random number generation using rand() and srand().

Input validation and error handling.


How to Run


Clone or download this repository.

Open the project folder in a C-compatible IDE or text editor.

Compile the source file using a C compiler such as GCC:

gcc brettproject1.c -o tic_tac_toe

Run the compiled program:

./tic_tac_toe

Follow the instructions displayed in the terminal to play the game.

License

This project was created as an individual educational assignment for COMP 120. It is intended for educational purposes and to demonstrate fundamental C programming concepts.
