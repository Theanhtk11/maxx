#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <termios.h>

// Function to draw the chessboard
void drawChessboard(int kingRow, int kingCol, int queenRow, int queenCol) {
    // Clear the screen
    std::cout << "\033[2J";

    // Move the cursor to the top-left corner
    std::cout << "\033[1;1H";

    // Draw the chessboard
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == kingRow && j == kingCol)
                std::cout << " ♚ ";
            else if (i == queenRow && j == queenCol)
                std::cout << " ♛ ";
            else if ((i + j) % 2 == 0)
                std::cout << "   ";
            else
                std::cout << "\033[48;5;94m ▓ \033[0m";
        }
        std::cout << std::endl;
       
    }
}

// Function to get the pressed key without waiting for Enter
int getch() {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate random positions for the king and queen
    int kingRow = 1;
    int kingCol =1;
    int queenRow = 6;
    int queenCol = 6;

    // Draw the initial chessboard with the king and queen
    drawChessboard(kingRow, kingCol, queenRow, queenCol);

    // Game loop
    while (true) {
        // Get the pressed key
        int key = getch();

        // Update the king's position based on the pressed key
        switch (key) {
            case 65:  // Up arrow
                kingRow = (kingRow - 1 + 8) % 8;
                break;
            case 66:  // Down arrow
                kingRow = (kingRow + 1) % 8;
                break;
            case 67:  // Right arrow
                kingCol = (kingCol + 1) % 8;
                break;
            case 68:  // Left arrow
                kingCol = (kingCol - 1 + 8) % 8;
                break;
            case 'q':
                return 0;  // Quit the game
        }

        // Redraw the chessboard with the updated king's position
        drawChessboard(kingRow, kingCol, queenRow, queenCol);
    }

    return 0;
}
