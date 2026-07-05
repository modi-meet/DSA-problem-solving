import java.util.*;

// === ENUMS ===
enum VehicleType {
    MOTORCYCLE, CAR, TRUCK
}

enum SpotType {
    SMALL, MEDIUM, LARGE
}

// === CUSTOM EXCEPTION ===
class NoSpotAvailableException extends Exception {
    public NoSpotAvailableException(String message) {
        super(message);
    }
}

// === VEHICLE HIERARCHY ===
abstract class Vehicle {
    private String licensePlate;
    private VehicleType type;

    public Vehicle(String licensePlate, VehicleType type) {
        this.licensePlate = licensePlate;
        this.type = type;
    }

    public String getLicensePlate() {
        return licensePlate;
    }

    public VehicleType getType() {
        return type;
    }
}

class Motorcycle extends Vehicle {
    public Motorcycle(String licensePlate) {
        super(licensePlate, VehicleType.MOTORCYCLE);
    }
}

class Car extends Vehicle {
    public Car(String licensePlate) {
        super(licensePlate, VehicleType.CAR);
    }
}

class Truck extends Vehicle {
    public Truck(String licensePlate) {
        super(licensePlate, VehicleType.TRUCK);
    }
}

// === PARKING SPOT HIERARCHY ===
abstract class ParkingSpot {
    private int spotNumber;
    private SpotType type;
    private boolean isFree;
    private Vehicle parkedVehicle;

    public ParkingSpot(int spotNumber, SpotType type) {
        this.spotNumber = spotNumber;
        this.type = type;
        this.isFree = true;
    }

    public int getSpotNumber() {
        return spotNumber;
    }

    public SpotType getType() {
        return type;
    }

    public boolean isFree() {
        return isFree;
    }

    public Vehicle getParkedVehicle() {
        return parkedVehicle;
    }

    public abstract boolean canFitVehicle(Vehicle vehicle);

    public void park(Vehicle vehicle) {
        this.parkedVehicle = vehicle;
        this.isFree = false;
    }

    public void removeVehicle() {
        this.parkedVehicle = null;
        this.isFree = true;
    }
}

class SmallSpot extends ParkingSpot {
    public SmallSpot(int spotNumber) {
        super(spotNumber, SpotType.SMALL);
    }

    @Override
    public boolean canFitVehicle(Vehicle v) {
        // Return true ONLY if the vehicle is a MOTORCYCLE

        return v.getType()==VehicleType.MOTORCYCLE;

    }
}

class MediumSpot extends ParkingSpot {
    public MediumSpot(int spotNumber) {
        super(spotNumber, SpotType.MEDIUM);
    }

    @Override
    public boolean canFitVehicle(Vehicle v) {
        // Return true if the vehicle is a CAR or a MOTORCYCLE

        return v.getType() == VehicleType.MOTORCYCLE || v.getType() == VehicleType.CAR;
    }
}

class LargeSpot extends ParkingSpot {
    public LargeSpot(int spotNumber) {
        super(spotNumber, SpotType.LARGE);
    }

    @Override
    public boolean canFitVehicle(Vehicle v) {
        // Return true for all vehicles (Large fits anything)

        return true;
    }
}

// === TICKET & FEE CALCULATOR ===
class Ticket {
    private String ticketId;
    private int spotNumber;
    private SpotType spotType;
    private long entryTime;

    public Ticket(int spotNumber, SpotType spotType) {
        this.ticketId = UUID.randomUUID().toString().substring(0, 8);
        this.spotNumber = spotNumber;
        this.spotType = spotType;
        this.entryTime = System.currentTimeMillis();
    }

    public int getSpotNumber() {
        return spotNumber;
    }

    public SpotType getSpotType() {
        return spotType;
    }

    public long getEntryTime() {
        return entryTime;
    }
}

class FeeCalculator {
    private static final double HOURLY_RATE = 10.0;

    public double calculateFee(long entryTime) {

        // Simulated 2-hour fee
        return 2 * HOURLY_RATE; 
    }
}

// === CORE SYSTEM: PARKING LOT ===
class ParkingLot {
    private Map<SpotType, Queue<ParkingSpot>> availableSpots;
    private Map<Integer, ParkingSpot> allSpotsDirectory;
    private FeeCalculator feeCalculator;

    public ParkingLot(FeeCalculator feeCalculator) {
        this.feeCalculator = feeCalculator;
        this.availableSpots = new HashMap<>();
        this.allSpotsDirectory = new HashMap<>();

        // Loop through all SpotType enum values.
        // For each type, put a new LinkedList into the availableSpots map.
        for(SpotType spotType : SpotType.values()) {
            availableSpots.put(spotType, new LinkedList<>());
        }

    }

    public void addSpot(ParkingSpot spot) {
        availableSpots.get(spot.getType()).add(spot);
        allSpotsDirectory.put(spot.getSpotNumber(), spot);
    }

    // Helper: Defines the exact fallback search order for each vehicle type
    private List<SpotType> getSearchPath(VehicleType type) {
        switch (type) {
            case MOTORCYCLE:
                return Arrays.asList(SpotType.SMALL, SpotType.MEDIUM, SpotType.LARGE);
            case CAR:
                return Arrays.asList(SpotType.MEDIUM, SpotType.LARGE);
            case TRUCK:
                return Arrays.asList(SpotType.LARGE);
            default:
                return Arrays.asList(SpotType.LARGE);
        }
    }

    public Ticket parkVehicle(Vehicle vehicle) throws NoSpotAvailableException {
        List<SpotType> searchPath = getSearchPath(vehicle.getType());

        // Iterate through the searchPath to find an available spot.
        // 1. Get the Queue of suitable spots for the current SpotType in the loop.
        // 2. If the Queue is NOT empty, poll the spot, park the vehicle, print a
        // success message, and return a new Ticket.
        // 3. If the loop finishes and no spots were found, throw a NoSpotAvailableException
        for (SpotType type : searchPath) {
            Queue<ParkingSpot> spots = availableSpots.get(type);

            if (!spots.isEmpty()) {

                ParkingSpot spot = spots.poll();

                spot.park(vehicle);

                System.out.println(vehicle.getType() + " parked at " + spot.getType() + " Spot " + spot.getSpotNumber());
                
                return new Ticket(spot.getSpotNumber(), spot.getType());
            }
        }

        throw new NoSpotAvailableException("Lot Full: No available spots for vehicle type " + vehicle.getType());
    }

    public double processExit(Ticket ticket) {
        ParkingSpot spot = allSpotsDirectory.get(ticket.getSpotNumber());

        // Check if the spot exists and is NOT free.
        // 1. If occupied, remove the vehicle from the spot and print a message.
        // 2. Add the spot back to the correct Queue in the availableSpots map.
        // 3. Return the calculated fee using the feeCalculator.
        // 4. Return 0.0 if the spot was invalid or already empty.
        if (spot != null && !spot.isFree()) {

            System.out.println("Vehicle exited from Spot " + spot.getSpotNumber());

            spot.removeVehicle();

            availableSpots.get(spot.getType()).offer(spot);

            return feeCalculator.calculateFee(ticket.getEntryTime());
        }

        return 0.0;
    }
}

// === MAIN CLASS ===
public class ParkingLotSystem {
    public static void main(String[] args) {
        System.out.println("--- Booting up Parking Lot System ---");

        FeeCalculator calculator = new FeeCalculator();
        ParkingLot lot = new ParkingLot(calculator);

        lot.addSpot(new SmallSpot(1));
        lot.addSpot(new MediumSpot(2));
        lot.addSpot(new MediumSpot(3));
        lot.addSpot(new LargeSpot(4));

        Vehicle car1 = new Car("ABC-123");
        Vehicle car2 = new Car("XYZ-987");
        Vehicle car3 = new Car("FALLBACK-1");
        Vehicle truck1 = new Truck("BIG-BOY");

        try {
            System.out.println("\n[Attempting to park Car 1]");
            Ticket ticket1 = lot.parkVehicle(car1);

            System.out.println("\n[Attempting to park Car 2]");
            Ticket ticket2 = lot.parkVehicle(car2);

            System.out.println("\n[Attempting to park Car 3 - Cascading to Large]");
            Ticket ticket3 = lot.parkVehicle(car3);

            System.out.println("\n[Attempting to park Truck 1 - Should Fail]");
            Ticket ticket4 = lot.parkVehicle(truck1);

        } catch (NoSpotAvailableException e) {
            System.out.println("System Alert: " + e.getMessage());
        }
    }
}

/*

OUTPUT:

--- Booting up Parking Lot System ---

[Attempting to park Car 1]
CAR parked at MEDIUM Spot 2

[Attempting to park Car 2]
CAR parked at MEDIUM Spot 3

[Attempting to park Car 3 - Cascading to Large]
CAR parked at LARGE Spot 4

[Attempting to park Truck 1 - Should Fail]
System Alert: Lot Full: No available spots for vehicle type TRUCK

*/