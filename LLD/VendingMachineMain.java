// === STATE INTERFACE ===
interface State {
    // Declare the 5 methods for the state interface here:
    void insertCoin();
    void ejectCoin();
    void pressButton();
    void dispense();
    void refill(int count);
}

// === CONTEXT CLASS ===
class VendingMachine {
    // Declare the private fields here. You will need:
    // - 4 State variables (noCoinState, hasCoinState, dispenseState, soldOutState)
    // - 1 State variable for the currentState (currentState)
    // - 1 integer for the inventory count (inventory)
    private State noCoinState;
    private State hasCoinState;
    private State dispenseState;
    private State soldOutState;
    private State currentState;
    private int inventory;


    public VendingMachine(int inventory) {
        this.noCoinState = new NoCoinState(this);
        this.hasCoinState = new HasCoinState(this);
        this.dispenseState = new DispenseState(this);
        this.soldOutState = new SoldOutState(this);

        this.inventory = inventory;

        if (inventory > 0) {
            currentState = noCoinState;
        } else {
            currentState = soldOutState;
        }
    }

    // --- Core Actions Delegated to Current State ---
    public void insertCoin() {
        currentState.insertCoin();
    }

    public void ejectCoin() {
        currentState.ejectCoin();
    }

    public void dispense() {
        currentState.dispense();
    }

    public void pressButton() {
        currentState.pressButton();
        // A vending machine automatically attempts to dispense after button press
        dispense();
    }

    public void refill(int count) {
        currentState.refill(count);
    }

    // --- State Management ---
    public void setState(State state) {
        this.currentState = state;
    }

    public void releaseProduct() {
        System.out.println("A product comes rolling out the slot...");
        if (inventory > 0) {
            inventory--;
        }
    }

    public int getInventory() {
        return inventory;
    }

    public void addInventory(int count) {
        this.inventory += count;
    }

    // --- State Getters ---
    public State getNoCoinState() { return noCoinState; }
    public State getHasCoinState() { return hasCoinState; }
    public State getDispenseState() { return dispenseState; }
    public State getSoldOutState() { return soldOutState; }
}

// === CONCRETE STATE 1: NO COIN ===
class NoCoinState implements State {
    private VendingMachine machine;

    public NoCoinState(VendingMachine machine) {
        this.machine = machine;
    }

    @Override
    public void insertCoin() {
        System.out.println("Coin inserted.");
        // Transition the machine to the HasCoinState
    
        machine.setState(machine.getHasCoinState());
    }

    @Override
    public void ejectCoin() {
        System.out.println("You haven't inserted a coin.");
    }

    @Override
    public void pressButton() {
        System.out.println("You pressed the button, but there is no coin.");
    }

    @Override
    public void dispense() {
        System.out.println("You need to pay first.");
    }

    @Override
    public void refill(int count) {
        // Add the count to the machine's inventory
        machine.addInventory(count);


        System.out.println("Machine refilled. Total inventory: " + machine.getInventory());
    }
}

// === CONCRETE STATE 2: HAS COIN ===
class HasCoinState implements State {
    private VendingMachine machine;

    public HasCoinState(VendingMachine machine) {
        this.machine = machine;
    }

    @Override
    public void insertCoin() {
        System.out.println("You can't insert another coin.");
    }

    @Override
    public void ejectCoin() {
        System.out.println("Coin returned.");
        // Transition the machine to the NoCoinState
        
        machine.setState(machine.getNoCoinState());
    }

    @Override
    public void pressButton() {
        System.out.println("Button pressed...");
        // Transition the machine to the DispenseState
        
        machine.setState(machine.getDispenseState());
    }

    @Override
    public void dispense() {
        System.out.println("No product dispensed yet.");
    }

    @Override
    public void refill(int count) {
        System.out.println("Cannot refill during an active transaction.");
    }
}

// === CONCRETE STATE 3: DISPENSE ===
class DispenseState implements State {
    private VendingMachine machine;

    public DispenseState(VendingMachine machine) {
        this.machine = machine;
    }

    @Override
    public void insertCoin() {
        System.out.println("Please wait, we're already giving you a product.");
    }

    @Override
    public void ejectCoin() {
        System.out.println("Sorry, you already pressed the button.");
    }

    @Override
    public void pressButton() {
        System.out.println("Pressing twice doesn't get you another product!");
    }

    @Override
    public void dispense() {
        // Release the product from the machine
        machine.releaseProduct();
        

        // Check the machine's inventory. 
        //     If > 0, transition to NoCoinState. 
        //     If 0, System.out.println("Oops, out of inventory!"); and transition to SoldOutState.
        if(machine.getInventory() > 0) machine.setState(machine.getNoCoinState());
        else {
            System.out.println("Oops, out of inventory!");
            machine.setState(machine.getSoldOutState());
        }
    }

    @Override
    public void refill(int count) {
        System.out.println("Cannot refill while dispensing.");
    }
}

// === CONCRETE STATE 4: SOLD OUT ===
class SoldOutState implements State {
    private VendingMachine machine;

    public SoldOutState(VendingMachine machine) {
        this.machine = machine;
    }

    @Override
    public void insertCoin() {
        System.out.println("You can't insert a coin, the machine is sold out.");
    }

    @Override
    public void ejectCoin() {
        System.out.println("You haven't inserted a coin yet.");
    }

    @Override
    public void pressButton() {
        System.out.println("You pressed, but there are no products.");
    }

    @Override
    public void dispense() {
        System.out.println("No product dispensed.");
    }

    @Override
    public void refill(int count) {
        // Add the count to the machine's inventory using machine.addInventory()
        machine.addInventory(count);


        System.out.println("Machine refilled. Total inventory: " + machine.getInventory());
        // Transition to NoCoinState
        
        machine.setState(machine.getNoCoinState());
    }
}

// === MAIN CLASS ===
public class VendingMachineMain {
    public static void main(String[] args) {
        System.out.println("--- Booting up Vending Machine (Inventory: 2) ---");
        VendingMachine machine = new VendingMachine(2);

        System.out.println("\n[1: Happy Path]");
        machine.insertCoin();
        machine.pressButton();

        System.out.println("\n[2: Invalid Action (Eject without coin)]");
        machine.ejectCoin();

        System.out.println("\n[3: Ejecting Coin before dispense]");
        machine.insertCoin();
        machine.ejectCoin();

        System.out.println("\n[4: Buying the last item]");
        machine.insertCoin();
        machine.pressButton();

        System.out.println("\n[5: Trying to buy when sold out]");
        machine.insertCoin();
        machine.pressButton();
        
        System.out.println("\n[6: Refilling the machine]");
        machine.refill(5);
        machine.insertCoin();
        machine.pressButton();
    }
}
/*
OUTPUT: 

--- Booting up Vending Machine (Inventory: 2) ---

[1: Happy Path]
Coin inserted.
Button pressed...
A product comes rolling out the slot...

[2: Invalid Action (Eject without coin)]
You haven't inserted a coin.

[3: Ejecting Coin before dispense]
Coin inserted.
Coin returned.

[4: Buying the last item]
Coin inserted.
Button pressed...
A product comes rolling out the slot...
Oops, out of inventory!

[5: Trying to buy when sold out]
You can't insert a coin, the machine is sold out.
You pressed, but there are no products.
No product dispensed.

[6: Refilling the machine]
Machine refilled. Total inventory: 5
Coin inserted.
Button pressed...
A product comes rolling out the slot...

*/