// HOTEL
// 1. Guest will be able to SEARCH and book room
// 2. Different kind of rooms will be available
// 3. There will be different kinds of people interacting
//      (i) Guest-> will book the room, or cancel a booked room
//      (ii) Receptionist -> should checkIn and checkOut guest
//      (iii) houseKeeping -> should clean the room 
//      (iv) Admin -> who should be able to add or delete rooms
// 4. Each room will have a key and a master key

class Hotel {
	
	String Name;
	Integer id;
	Location hotelLocation;
	List<Room> roomList;

	Receptionist receptionist;
	vector<HouseKeeper> houseKeepers;


}

class Location {
	
	Double longitude;
	Double latitude;
}

class Room {
	
	String roomNumber;
	RoomStyle roomStyle;
	RoomStatus roomStatus;
	Double bookingPrice;
	List<RoomKey> roomKeys;

}

public enum RoomStyle {
	
	STANDARD, DELUX, FAMILY_SUITE;
}

public enum RoomStatus {
	
	AVAILABLE, RESERVED, NOT_AVAILBLE, OCCUPIED, SERVICE_IN_PROGRESS;
}

class RoomKey {
	
	String keyId;
	Date issuedAt;
	Boolean isActive;
	Boolean isMaster;

	public void assignRoom(Room room);

}

abstract class Person {

	String name;
	Account accountDetail;
	String phone;
}


class HouseKeeper extends Person {

	public List<Room> public getRoomsServiced(Date date);
}

class Guest extends Person {

	Search searchObj;
	Booking bookingObj;

	public List<RoomBooking> getAllRoomBookings();
	public RoomBooking createBooking();
	public RoomBooking cancelBooking(int bookingId);
}

class Receptionist extends Person {

	Search searchObj;
	Booking bookingObj;

	public void checkInGuest(Guest guest, RoomBooking bookingInfo);
	public void checkOutGuest(Guest guest, RoomBooking bookingInfo);

}

class admin extends Person {

	public void addRomm(Room roomDetail);
	public Room deleteRoom(String roomId);
	public void editRoom(Room roomDetail);
}

class search {

	public List<Room> searchRoom(RoomStyle roomStyle, Date startDate, int duration);

}

class RoomBooking {

	String bookingId;
	Date startDate;
	Int durationInDays;
	BookingStatus bookingStatus;
	List<Guest> guestList;
	List<Room> roomInfo;
	RoomCharge totalRoomCharges;
}


/**
*	Decorator pattern is used to decorate the prices here.
**/

class RoomCharge implements BaseRoomCharge {

	
	double cost;


	public Double getCost() {
		return cost;
	}
	void appendCost(double cost) {
		this.cost += cost;
	}
}

class Booking {

	public RoomBooking createBooking(Guest guestInfo);
	public RoomBooking cancelBooking(int bookingId);

}
