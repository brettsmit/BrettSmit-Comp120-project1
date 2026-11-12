#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void init_board(char board[]) {         // initialize the board

    for (int i = 0; i < 9; i++) {

        board[i] = ' ';
    }
}


void display_board(char board[]) {      // display the board
   
    char c[9];

    for (int i = 0; i < 9; i++) {
        
        c[i] = board[i];

        if (c[i] == ' ') {
            c[i] = '0' + i;
        }
    }

    printf("\n");
    printf(" %c | %c | %c\n", c[0], c[1], c[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[3], c[4], c[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[6], c[7], c[8]);
    printf("\n");
}


char other_player(char player) {        // switch player

    if (player == 'O') {
        return 'X';
    }
    else {
        return 'O';
    }
}

                                        
int get_human_move(char board[]) {      // get human move
    
    int move;
    bool valid = false;

    while (!valid) {

        printf("Your turn (0). Enter a square number (0-8): ");

        if (scanf("%d", &move) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');
            continue;
        }

        if (move < 0 || move > 8) {
            printf("Invalid number. Enter a correct number.\n");
        }
        else if (board[move] != ' ') {
            printf("That square is already taken. Choose an empty one.\n");
        }
        else {
            valid = true;
        }
    }

    return move;
}


int get_computer_move(char board[]) {       // get computer move

    int comp_move;
    printf("Computer (X) is thinking...\n");

    do {
        comp_move = rand() % 9;
    } while (board[comp_move] != ' ');

    printf("Computer (X) chose square %d.\n", comp_move);

    return comp_move;
}

void take_turn(char board[], char player) {     // take a turn

    int turn;

    if (player == 'O') {
        turn = get_human_move(board);
    }
    else {
        turn = get_computer_move(board);
    }
    board[turn] = player;
}

bool is_winner(char board[], char player) {     // check for winner

    if (board[0] == player && board[1] == player && board[2] == player)
        return true;

    if (board[3] == player && board[4] == player && board[5] == player)
        return true;

    if (board[6] == player && board[7] == player && board[8] == player)
        return true;

    if (board[0] == player && board[3] == player && board[6] == player)
        return true;

    if (board[1] == player && board[4] == player && board[7] == player)
        return true;

    if (board[2] == player && board[5] == player && board[8] == player)
        return true;

    if (board[0] == player && board[4] == player && board[8] == player)
        return true;

    if (board[2] == player && board[4] == player && board[6] == player)
        return true;

    return false;
}

void play_game(void) {                          // play one game

    char board [9];
    char player = 'O';
    bool game_over = false;

    init_board(board);

    display_board(board);

    for (int j = 0; j < 9 && !game_over; j++) {

        take_turn(board, player);
        display_board(board);

        if (is_winner(board, player)) {
            
            if (player == 'O') {
                printf("Congratulations! You won!\n");
            }
            else {
                printf("The computer wins! Better luck next time!\n");
            }
            game_over = true;
        }
        else if (j == 8) {
            
            printf("It's a draw!\n");

            game_over = true;
        }
        else {
            
            player = other_player(player);
        }
    }
}


bool play_again(void) {                         // ask to play again

    char answer;

    do {

        printf("\nWould you like to play again? (y/q): ");
        scanf(" %c", &answer);

        if (answer != 'y' && answer != 'Y' &&
            answer != 'q' && answer != 'Q') {

            printf("Invalid choice. Please enter y or q.\n");
        }

    } while (answer != 'y' && answer != 'Y' &&
             answer != 'q' && answer != 'Q');

    if (answer == 'y' || answer == 'Y') {
        printf("Playing again!\n");
        return true;
    }
    else {
        return false;
    }
}


int main(void) {

    srand(time(NULL));      // set the random seed

    printf("=====================================\n");
    printf("        TIC-TAC-TOE vs COMPUTER\n");
    printf("=====================================\n");
    printf("You are O and you go first. The computer is X.\n");
    printf("On your turn, type the number of an empty square:\n");

    do {
    
    play_game();            // begin game
    
    } while (play_again());

    printf("Thanks for playing!\n");
   
    return 0;
}