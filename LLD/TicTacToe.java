class Player {
    private String name;
    private char symbol;

    public Player(String name, char symbol) {
        this.name = name;
        this.symbol = symbol;
    }

    public String getName() { return name; }
    public char getSymbol() { return symbol; }
}

// === BOARD ===
class Board {
    private int size;
    private char[][] grid;

    /*
    Initialize the board
    - Assign the 'size' parameter to the class field.
    - Initialize the 'grid' array using this size.
    - Use nested loops to fill every cell with a blank space (' ').
    */
    public Board(int size) {
        this.size = size;
        this.grid = new char[size][size];

        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                this.grid[i][j] = ' ';
            }
        }

    }

    /*
    Place a symbol
    - Check if row and col are within bounds (0 to size-1). If not, print an error and return false.
    - Check if the cell is already occupied (not ' '). If not, print an error and return false.
    - If valid, assign the symbol to the grid and return true.
    */
    public boolean placeSymbol(int row, int col, char symbol) {
        // Validation and placement logic here
        if(row >= this.size || col >= this.size  || row < 0 || col < 0) {
            System.out.println("Invalid move: Out of bounds.");
            return false;
        }
        else if(this.grid[row][col] != ' ') {
            System.out.println("Invalid move: Cell already occupied.");
            return false; 
        }

        grid[row][col] = symbol;
        return true;
    }

    // --- HELPER METHODS ---
    public boolean isFull() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j] == ' ') return false;
            }
        }
        return true;
    }

    public int getSize() { return size; }
    public char[][] getGrid() { return grid; }
    public char getSymbol(int row, int col) { return grid[row][col]; } // custom

    public void printBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.print("[" + grid[i][j] + "]");
            }
            System.out.println();
        }
        System.out.println();
    }
}

// === GAME ENGINE ===
class GameEngine {
    private Board board;
    private Player player1;
    private Player player2;
    private Player currentPlayer;
    private int n;

    public GameEngine(Player p1, Player p2, int boardSize) {
        this.board = new Board(boardSize);
        this.player1 = p1;
        this.player2 = p2;
        this.currentPlayer = p1;
        n = this.board.getSize();
    }


    /*
    Dynamic Win Check
    - Do NOT hardcode for 3x3 (e.g., avoid grid[0][0]).
    - Use board.getSize() and loops to check rows, columns, and diagonals dynamically.
    - Return true if the current symbol has a winning line.
    */
    public boolean checkWin(char symbol) {
        // Dynamic win-checking logic here

        int i=0, j=0;
        while(i < n && j < n) {
            if(checkRow(i, symbol) || checkCol(j, symbol)) return true;

            i++; j++;
        }



        return checkDiagonal(symbol); // diagonal found?
    }

    /*
    Execute Turn
    1. Call board.placeSymbol() with the current player's symbol.
    2. If placement is successful:
        a. Print the updated board.
        b. Check if the player won. If yes, print victory message and return.
        c. Check if board is full. If yes, print draw message and return.
        d. If no win/draw, switch to the other player.
    */
    public void playTurn(int row, int col) {
        System.out.println(currentPlayer.getName() + " attempts to place '" + currentPlayer.getSymbol() + "' at (" + row + ", " + col + ")");
        // Turn delegation logic here

        if(board.placeSymbol(row, col, currentPlayer.getSymbol())) {
            this.board.printBoard();

            if(this.checkWin(currentPlayer.getSymbol())) {
                System.out.println("Game Over! " + currentPlayer.getName() + " wins");
                return;
            }
            else if(this.board.isFull()) {
                System.out.println("Game Over! " + "It's a draw!");
                return;
            }

            this.switchPlayer();
        }
    }

    // --- HELPER METHOD ---
    public void switchPlayer() {
        if (currentPlayer == player1) {
            currentPlayer = player2;
        } else {
            currentPlayer = player1;
        }
    }


    // Custom Helper Methods
    boolean checkRow(int row, char symbol) {
        for(int j=0; j<n; j++) {
            if(this.board.getSymbol(row, j) != symbol) return false;
        }

        return true;
    }
    
    boolean checkCol(int col, char symbol) {
        for(int i=0; i<n; i++) {
            if(this.board.getSymbol(i, col) != symbol) return false;
        }

        return true;
    }

    boolean checkDiagonal(char symbol) {
        boolean mainDiagonal = true;
        boolean antiDiagonal = true;
        for(int i=0; i<n; i++) {
            if(this.board.getSymbol(i, i) != symbol) mainDiagonal = false;
        }

        int i = 0, j = n-1;
        while(i < n) {
            if(this.board.getSymbol(i, j) != symbol) antiDiagonal = false;

            i++; j--;
        }

        return mainDiagonal || antiDiagonal;
    }
}

// === Main Class === 
public class TicTacToe {
    public static void main(String[] args) {
        Player p1 = new Player("Alice", 'X');
        Player p2 = new Player("Bob", 'O');
        
        // Creating a dynamic 3x3 board
        GameEngine engine = new GameEngine(p1, p2, 3);
        
        // Simulating a short game
        engine.playTurn(0, 0); // X
        engine.playTurn(1, 1); // O
        engine.playTurn(0, 1); // X
        engine.playTurn(1, 2); // O
        engine.playTurn(0, 2); // X Wins
    }
}

/*
OUTPUT: 

Alice attempts to place 'X' at (0, 0)
[X][ ][ ]
[ ][ ][ ]
[ ][ ][ ]

Bob attempts to place 'O' at (1, 1)
[X][ ][ ]
[ ][O][ ]
[ ][ ][ ]

Alice attempts to place 'X' at (0, 1)
[X][X][ ]
[ ][O][ ]
[ ][ ][ ]

Bob attempts to place 'O' at (1, 2)
[X][X][ ]
[ ][O][O]
[ ][ ][ ]

Alice attempts to place 'X' at (0, 2)
[X][X][X]
[ ][O][O]
[ ][ ][ ]

Game Over! Alice wins

*/