import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

// === PLAYER ===
class Player {
    private String name;
    private int position;

    public Player(String name) {
        this.name = name;

        // All players start at position 0 (outside the board)
        this.position = 0; 
    }

    public String getName() {
        return name;
    }

    public int getPosition() {
        return position;
    }

    public void setPosition(int position) {
        this.position = position;
    }
}

// === DICE ===
class Dice {
    private int sides;

    public Dice(int sides) {
        this.sides = sides;
    }

    // Generate a random number from 1 to 'sides'.
    public int roll() {
        // Dice rolling logic
        return (int)(Math.random() * sides) + 1;
    }
}

// === BOARD ===
class Board {
    private int size;

    // Handles BOTH Snakes and Ladders
    private Map<Integer, Integer> jumps; 

    public Board(int size) {
        this.size = size;
        // Initialize the 'jumps' map
        this.size = size;
        this.jumps = new HashMap<>();

    }

    /*
     * Unifying Mechanics (Logic)
     * - addJump(): Put the start and end positions into the jumps map.
     * - getFinalPosition(): Check if the map contains the 'position' as a key.
     * If yes, return the mapped destination value.
     * If no, return the original position.
     */
    public void addJump(int start, int end) {
        // Write logic to add a jump
        jumps.put(start, end);
    }

    public int getFinalPosition(int position) {
        // To return final position after checking for snakes/ladders
        return jumps.getOrDefault(position, position);
    }

    // --- HELPER METHOD ---
    public int getSize() {
        return size;
    }
}

// === GAME ENGINE ===
class GameEngine {
    private Queue<Player> players;
    private Board board;
    private Dice dice;

    public GameEngine(Queue<Player> players, Board board, Dice dice) {
        this.players = players;
        this.board = board;
        this.dice = dice;
    }

    public void playGame() {
        System.out.println("--- Starting Snake and Ladder Simulator ---");

        while (true) {
            // 1. Dequeue the player whose turn it is
            Player currentPlayer = players.poll();

            // 2. Roll the dice
            int rollValue = dice.roll();
            int currentPosition = currentPlayer.getPosition();
            int nextPosition = currentPosition + rollValue;

            // 3. Handle overshooting the exact winning square
            if (nextPosition > board.getSize()) {
                System.out.println(currentPlayer.getName() + " rolled a " + rollValue +
                        " but needs exactly " + (board.getSize() - currentPosition) + " to win. Turn skipped.");
                
                // Put back in queue
                players.offer(currentPlayer); 
                continue;
            }

            System.out.println(currentPlayer.getName() + " rolled a " + rollValue +
                    " and moved from " + currentPosition + " to " + nextPosition);

            // 4. Check for Snakes or Ladders
            int finalPosition = board.getFinalPosition(nextPosition);
            if (finalPosition > nextPosition) {
                System.out.println("   Yay! " + currentPlayer.getName() + " took a ladder up to " + finalPosition);
            } else if (finalPosition < nextPosition) {
                System.out.println("   Oh no! " + currentPlayer.getName() + " got bitten by a snake and slid down to "
                        + finalPosition);
            }

            // 5. Update player's position
            currentPlayer.setPosition(finalPosition);

            // 6. Check Win Condition
            if (hasWon(currentPlayer)) {
                System.out.println("\nGame Over! " + currentPlayer.getName() + " wins the game!");
                break;
            }

            // 7. Enqueue player at the back for their next turn
            players.offer(currentPlayer);
        }
    }

    private boolean hasWon(Player player) {
        return player.getPosition() == board.getSize();
    }
}

// === MAIN Class ===
public class SnakeLadder {
    public static void main(String[] args) {
        // Initialize core components
        Dice dice = new Dice(6);
        Board board = new Board(100);

        // Add Snakes (Start > End)
        board.addJump(99, 21);
        board.addJump(87, 36);
        board.addJump(62, 18);
        board.addJump(54, 34);
        board.addJump(17, 7);

        // Add Ladders (Start < End)
        board.addJump(4, 14);
        board.addJump(9, 31);
        board.addJump(28, 84);
        board.addJump(40, 59);
        board.addJump(51, 67);

        /*
         * Turn Management
         * - Initialize a Queue of Players using LinkedList.
         * - Add a Player named "Alice" to the queue.
         * - Add a Player named "Bob" to the queue.
         * - Create a new GameEngine instance, passing the queue, board, and dice.
         * - Play the game 
         */
        // Setup and execution logic here
        Queue<Player> players = new LinkedList<>();

        players.offer(new Player("Alice"));
        players.offer(new Player("Bob"));

        GameEngine engine = new GameEngine(players, board, dice);
        engine.playGame();
    }
}

/*
javac SnakeLadder.java && java SnakeLadder

OUTPUT: 

--- Starting Snake and Ladder Simulator ---
Alice rolled a 1 and moved from 0 to 1
Bob rolled a 2 and moved from 0 to 2
Alice rolled a 6 and moved from 1 to 7
Bob rolled a 4 and moved from 2 to 6
Alice rolled a 2 and moved from 7 to 9
   Yay! Alice took a ladder up to 31
Bob rolled a 3 and moved from 6 to 9
   Yay! Bob took a ladder up to 31
Alice rolled a 3 and moved from 31 to 34
Bob rolled a 6 and moved from 31 to 37
Alice rolled a 2 and moved from 34 to 36
Bob rolled a 4 and moved from 37 to 41
Alice rolled a 4 and moved from 36 to 40
   Yay! Alice took a ladder up to 59
Bob rolled a 2 and moved from 41 to 43
Alice rolled a 5 and moved from 59 to 64
Bob rolled a 6 and moved from 43 to 49
Alice rolled a 5 and moved from 64 to 69
Bob rolled a 6 and moved from 49 to 55
Alice rolled a 5 and moved from 69 to 74
Bob rolled a 4 and moved from 55 to 59
Alice rolled a 1 and moved from 74 to 75
Bob rolled a 4 and moved from 59 to 63
Alice rolled a 6 and moved from 75 to 81
Bob rolled a 6 and moved from 63 to 69
Alice rolled a 2 and moved from 81 to 83
Bob rolled a 6 and moved from 69 to 75
Alice rolled a 2 and moved from 83 to 85
Bob rolled a 5 and moved from 75 to 80
Alice rolled a 6 and moved from 85 to 91
Bob rolled a 3 and moved from 80 to 83
Alice rolled a 2 and moved from 91 to 93
Bob rolled a 5 and moved from 83 to 88
Alice rolled a 5 and moved from 93 to 98
Bob rolled a 2 and moved from 88 to 90
Alice rolled a 4 but needs exactly 2 to win. Turn skipped.
Bob rolled a 2 and moved from 90 to 92
Alice rolled a 2 and moved from 98 to 100

Game Over! Alice wins the game!

*/