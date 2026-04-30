## Overview

In this lab you will build a complete **Tic-Tac-Toe** game in C, step by step.  
Each phase introduces a new concept and then asks you to apply it in the game.

You will work with:

- **multidimensional arrays** for the game board,
- passing arrays to **functions**,
- input handling with `scanf` and `getchar`,
- a simple **menu** using `switch`,
- **loop control** with `break` and `continue`,
- winner detection logic,
- and (in the challenges) **strings**, a simple **scoreboard** with `static`, and draw detection.

Read each phase carefully before writing code.

---

## Phase 1 — The Board: Multidimensional Arrays

So far you have used one-dimensional arrays (a single row of values).  
A **multidimensional array** is an array of arrays, useful for grids, tables, or, in this case, a **3×3 board**.

// Declaration of a 2D matrix
char board[3][3];
// board[row][col]
// board[0][0] = top-left corner
// board[2][2] = bottom-right corner

We will initialize the board with all positions empty (for example, using '.'):

void init_board(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '.';
        }
    }
}

Task (Phase 1)

Create a file tictactoe.c.
Declare a char board[3][3]; in main.
Implement init_board.
In main, call init_board(board);.
At this point, your program does not need to print anything yet. Just make sure it compiles.

Phase 2 — Printing the Board: Arrays as Function Arguments
When you pass a 2D array as a function argument, you must specify the sizes of all dimensions except the first one:

void print_board(char board[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}
The output should look like:

. | . | .
---+---+---
. | . | .
---+---+---
. | . | .

Task (Phase 2)

Add print_board to your program.
After calling init_board(board); in main, call print_board(board);.
Compile and run. Verify that the board appears correctly.
Phase 3 — Reading a Move: scanf() and getchar()
To read the player’s move, you will ask for the row and column (0 to 2).

There is a common problem with scanf: after reading a number, a \n (newline) remains in the input buffer. This can interfere with later input.
Using getchar() we can consume that leftover newline.

getchar() — reads and returns a single character from input.
Useful to clear the buffer after scanf or to read simple answers like 'y'/'n'.
putchar(c) — prints a single character. Equivalent to printf("%c", c).
Example function to read a move:

int get_move(int *row, int *col)
{
    printf("Row (0-2): ");
    if (scanf("%d", row) != 1)
    {
        getchar(); // clear invalid character
        return 0;
    }
    printf("Column (0-2): ");
    if (scanf("%d", col) != 1)
    {
        getchar(); // clear invalid character
        return 0;
    }
    getchar(); // clear the '\n' left in the buffer
    return 1;
}

Task (Phase 3)

Add get_move to your program.
In main, after initializing and printing the board:
call get_move(&row, &col),
if the function returns 1, place an 'X' at board[row][col] (for now, ignore validation).
Print the board again to see the move.
Phase 4 — Game Menu: switch and Multiple Alternatives
The switch statement is an alternative to if/else if when you want to compare one variable with several fixed values.
It often makes the code more readable:

// Equivalent with if/else if:
if (option == 1) { ... }
else if (option == 2) { ... }
else if (option == 3) { ... }
// With switch (cleaner):
switch (option)
{
    case 1:
        // play
        break; // ← without break, execution "falls through" to the next case!
    case 2:
        // instructions
        break;
    case 3:
        // exit
        break;
    default:
        // invalid option
        break;
}

The break inside the switch is required to exit each case.
Without it, C executes all following case blocks (this behaviour is called fall-through).

Example menu:

void show_menu(void)
{
    printf("=== TIC-TAC-TOE ===\n");
    printf("1. Play\n");
    printf("2. Exit\n");
    printf("Option: ");
}
In main:

int option;
show_menu();
scanf("%d", &option);
getchar(); // clear buffer
switch (option)
{
    case 1:
        // start game
        break;
    case 2:
        printf("Goodbye!\n");
        return 0;
    default:
        printf("Invalid option.\n");
        break;
}

Task (Phase 4)

Add show_menu to your program.
In main, show the menu, read the option, and:
if option == 1, start a new game (initialize board, then enter the game loop),
if option == 2, exit the program.
Phase 5 — Main Game Loop: break and continue
Inside the game, you will use a loop that repeats rounds until:

someone wins, or
the board is full (draw).
You will use:

break — to exit the loop when the game ends.
continue — to skip the rest of the loop when a move is invalid (and ask again).
Example ideas:

// break — exit the loop when the game is over
while (1)
{
    // play one turn
    if (game_over)
    {
        break; // leave the while loop
    }
}
// continue — ignore invalid moves
while (moves < 9)
{
    // read move (row, col)
    if (position_occupied)
    {
        printf("Position already taken! Try another one.\n");
        continue; // back to the start of the loop without incrementing moves
    }
    // apply move
    moves++;
}

Task (Phase 5)

Implement a game loop that:
alternates between player X and player O,
reads moves with get_move,
rejects invalid moves (outside [0–2] or already occupied) using continue,
stops when someone wins or after 9 valid moves (board full).
After each valid move:
update the board,
print the board.
You can use a variable like current_player ('X' or 'O') and flip it every turn.

Phase 6 — Checking for a Winner
Create a function that checks whether a player has won. A player wins if they have 3 equal symbols in a row, column, or diagonal:

int check_winner(char board[3][3])
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != '.' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
        {
            return 1;
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] != '.' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j])
        {
            return 1;
        }
    }
    // Check diagonals
    if (board[0][0] != '.' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
    {
        return 1;
    }
    if (board[0][2] != '.' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
    {
        return 1;
    }
    return 0;
}
Task (Phase 6)

Add check_winner to your program.
In the main game loop, after each valid move:
call check_winner(board),
if it returns 1, print a message announcing the winner and break out of the loop.
Challenge 1 — Player Names: Strings and Array of Strings
A string in C is a char array terminated by '\0'.
To store the names of both players you can use an array of strings:

char players[2][50]; // 2 players, names up to 49 characters
printf("Player 1 name (X): ");
scanf("%49s", players[0]); // %49s reads up to 49 characters (avoids overflow)
printf("Player 2 name (O): ");
scanf("%49s", players[1]);
Use %49s instead of %s to limit the number of characters read — good security practice in C.

Challenge Task

Ask for both player names before starting the game.
Use their names in the messages, e.g.:
"Joao played at [1][2]",
"Maria wins!".
Challenge 2 — Win Counter: static
Storage classes define where and for how long a variable exists in memory:




Class
Keyword
Lives in
Lifetime
Automatic
auto
Stack
While function runs
Static
static
Data segment
Entire program
External
extern
Data segment
Entire program
Register
register
CPU register (suggested)
While function runs
The most useful here is static: a static variable inside a function keeps its value between calls.

Example:

void update_score(int winner)
{
    static int score[2] = {0, 0}; // keeps its value between calls!
    if (winner == 1) score[0]++;
    if (winner == 2) score[1]++;
    printf("Score: P1=%d | P2=%d\n", score[0], score[1]);
}
Challenge Task

Add a win counter using static inside a function like update_score.
At the end of each game:
call update_score with the winner (1 or 2),
ask if the players want to play again,
if yes, restart the game loop but keep the score.
Challenge 3 — Detecting a Draw
Add detection of a draw — when the board is full and there is no winner.

Create a function:

int is_draw(char board[3][3])
{
    // return 1 if there are no '.' positions left, otherwise 0
}
Challenge Task

Implement is_draw to check if there are any empty positions left.
In the main game loop:
after each move, check:
if check_winner is true → someone won,
else if is_draw is true → it is a draw.
Print an appropriate message.
Common Errors and How to Fix Them



Error
Why it happens
How to fix
Input “gets stuck” after scanf
\n stays in the input buffer
Use getchar() after scanf
switch executes all cases
Missing break at the end of each case
Add break before the next case
Invalid board positions accepted
Input not validated
Check row >= 0 && row <= 2 && col >= 0 && col <= 2
Board not updating in function
2D arrays are passed by reference in C
Make sure you use board[i][j], not a local copy
Winner not detected
Comparison condition is wrong
Check board[i][j] != '.' before comparing equality
static not preserving value
Variable declared without static
Ensure the declaration uses static
What You Have Learned and Applied
By the end of this lab you will have practised:

Multidimensional arrays — char board[3][3] to represent a 2D grid.
Arrays as function arguments — passing and manipulating boards inside functions.
scanf in more depth — reading with validation, using %49s to limit strings.
getchar and putchar — reading/writing single characters and clearing the input buffer.
switch — cleaner alternative to if/else if for multiple fixed options.
break and continue — fine control of loop flow.
Strings and array of strings — char name[50], char players[2][50].
Storage classes — using static to keep state between function calls.
Basic game logic design — modelling game state, turns, and win/draw conditions.


