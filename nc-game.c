#include <stdio.h>

int board[3][3] = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
};

_Bool hasPlayer1Won = 0;
_Bool hasPlayer2Won = 0;
_Bool haveDraw = 0;

void drawBoard(_Bool isFirst);
int getPlayerInput(_Bool isPlayer1);
void setBoard(_Bool isPlayer1, int markedTile);
void checkBoard();

int main()
{
  // Draw instructions, initial setup
  drawBoard(1);

  // Keep getting input, adjusting board and checking for result until game over
  while ((!hasPlayer1Won) && (!hasPlayer2Won) && (!haveDraw)) {
    setBoard(1, getPlayerInput(1));
    drawBoard(0);
    checkBoard();

    if (hasPlayer1Won || haveDraw) {
      break;
    }
    setBoard(0, getPlayerInput(0));
    drawBoard(0);
    checkBoard();
  }

  if (hasPlayer1Won) {
    printf("\nVICTORY PLAYER 1, through wit and strategy you beat Player 2.\n");
    return 0;
  } else if (hasPlayer2Won) {
    printf("\nVICTORY PLAYER 2, through wit and strategy you beat Player 1.\n");
    return 0;
  }

  printf("\nDRAW. Well played Player 1 and Player 2, your brains are evenly matched.\n");
  return 0;
}

/***
 * Function which draws the board.
 * Input: Boolean whether this is the initial board
 * If not initial board will output 'x','o' if the board array has been adjusted in that tile
***/
void drawBoard(_Bool isFirst)
{
  int i, j;
  if (isFirst) {
    printf("\nNaughts and Crosses 2-Player Game\n\n");
    printf("INSTRUCTIONS: When prompted, enter a number from 1 to 9. The board below shows\n");
    printf("which tile this will mark. Player 1 marks (x) and Player 2 marks (o). Mark 3 tiles\n");
    printf("in a row to win. Invalid entries will be punished.\n");
    printf("\n-------------\n");
    for (i=0; i<3; i++) {
      for (j=0; j<3; j++) {
        printf("| %i ", board[i][j]);
        board[i][j] = 0;
        if (j == 2) {
          printf("|\n");
          printf("-------------\n");
        }
      }
    }
  } else {
    printf("\n-------------\n");
    for (i=0; i<3; i++) {
      for (j=0; j<3; j++) {
        if (board[i][j] == 0) {
          printf("|   ");
        } else if (board[i][j] == 1) {
          printf("| x ");
        } else {
          printf("| o ");
        }
        if (j == 2) {
          printf("|\n");
          printf("-------------\n");
        }
      }
    }

  }
}

/***
 * Function which gets Player Input.
 * Input: Boolean whether Player 1 or Player 2
 * Output: The marked tile number to be used by 'setBoard'
***/
int getPlayerInput(_Bool isPlayer1)
{
  if (isPlayer1) {
    printf("\nPlayer 1 please choose a tile to mark from 1 to 9: ");
    scanf("%i", &markedTile);
  } else {
    printf("\nPlayer 2 please choose a tile to mark from 1 to 9: ");
    scanf("%i", &markedTile);
  }
  return markedTile;
}

void checkBoard()
{
  int i;
  int markedColumns = 0;
  for (i=0; i<3; i++) {
    if (
      ((board[0][i] == 1) && (board[1][i] == 1) && (board[2][i] == 1)) ||
      ((board[i][0] == 1) && (board[i][1] == 1) && (board[i][2] == 1))
    ) {
      hasPlayer1Won = 1;
    } else if (
      ((board[0][i] == 2) && (board[1][i] == 2) && (board[2][i] == 2)) ||
      ((board[i][0] == 2) && (board[i][1] == 2) && (board[i][2] == 2))
    ) {
      hasPlayer2Won = 1;
    } else if (
      ((board[0][i] != 0) && (board[1][i] != 0) && (board[2][i] != 0))
    ) {
      markedColumns += 1;
    }
  }
  if (
    ((board[0][0] == 1) && (board[1][1] == 1) && (board[2][2] == 1)) ||
    ((board[0][2] == 1) && (board[1][1] == 1) && (board[2][0] == 1))
  ) {
    hasPlayer1Won = 1;
  } else if (
    ((board[0][0] == 2) && (board[1][1] == 2) && (board[2][2] == 2)) ||
    ((board[0][2] == 2) && (board[1][1] == 2) && (board[2][0] == 2))
  ) {
    hasPlayer2Won = 1;
  } else if (markedColumns > 2) {
    haveDraw = 1;
  }
}

/***
 * Function which correctly sets the board array depending on user input
 * Input: Boolean whether Player 1 or Player 2, integer of which tile to set
 * Player 1 marked tiles will be represented by '1', Player 2 '2'
 * Invalid tiles will simply print a message and skip the current turn
***/
void setBoard(_Bool isPlayer1, int markedTile)
{
  switch (markedTile)
  {
    case 1:
      if (board[0][0] == 0) {
        if (isPlayer1) {
          board[0][0] = 1;
        } else {
          board[0][0] = 2;
        }
      } else {
        printf("You selected a marked tile. For carelessness, you forfeit a turn.\n");
      }
      break;
    case 2:
      if (board[0][1] == 0) {
        if (isPlayer1) {
          board[0][1] = 1;
        } else {
          board[0][1] = 2;
        }
      } else {
        printf("You selected a marked tile. For carelessness, you forfeit a turn.\n");
      }
      break;
    case 3:
      if (board[0][2] == 0) {
        if (isPlayer1) {
          board[0][2] = 1;
        } else {
          board[0][2] = 2;
        }
      } else {
        printf("You selected a marked tile. For carelessness, you forfeit a turn.\n");
      }
      break;
    case 4:
      if (board[1][0] == 0) {
        if (isPlayer1) {
          board[1][0] = 1;
        } else {
          board[1][0] = 2;
        }
      } else {
        printf("You selected a marked tile. For carelessness, you forfeit a turn.\n");
      }
      break;
    case 5:
      if (board[1][1] == 0) {
        if (isPlayer1) {
          board[1][1] = 1;
        } else {
          board[1][1] = 2;
        }
      } else {
        printf("You selected a marked tile. For carelessness, you forfeit a turn.\n");
      }
      break;
    case 6:
      if (board[1][2] == 0) {
        if (isPlayer1) {
          board[1][2] = 1;
        } else {
          board[1][2] = 2;
        }
      } else {
        printf("You selected a marked tile. For carelessness, you forfeit a turn.\n");
      }
      break;
    case 7:
      if (board[2][0] == 0) {
        if (isPlayer1) {
          board[2][0] = 1;
        } else {
          board[2][0] = 2;
        }
      } else {
        printf("You selected a marked tile. For carelessness, you forfeit a turn.\n");
      }
      break;
    case 8:
      if (board[2][1] == 0) {
        if (isPlayer1) {
          board[2][1] = 1;
        } else {
          board[2][1] = 2;
        }
      } else {
        printf("You selected a marked tile. For carelessness, you forfeit a turn.\n");
      }
      break;
    case 9:
      if (board[2][2] == 0) {
        if (isPlayer1) {
          board[2][2] = 1;
        } else {
          board[2][2] = 2;
        }
      } else {
        printf("You selected a marked tile. For carelessness, you forfeit a turn.\n");
      }
      break;
    default:
      printf("Opps! You entered a number which does not correspond to a tile. You forfeit a turn.\n");
  }
}
