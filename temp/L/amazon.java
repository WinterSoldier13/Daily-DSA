// Amazon
// 1. User should be able to buy a product
// 2. user should be able to add multiple items in shopping cart;
// 3. user should be able to search for product and should get recommendation also
// 4. User should be able to track order
// 5. Buyer should be able to add product Review
// 6. Seller should be able to add products


class ShoppingPortal
{
	Search searchObj;
	vector<Product> getRecommendedProducts();
}

class User {

	ShoppingCart cart;
	ShoppingPortal shoppingPortal; // this shoping portal is generated uniqly for every user
	int customerId;

	public ShoppingCart getShoppingCart(customerId);
	public void addItemsToShoppingCart(Item item);
	public void updateItemFromShoppingCart(Item item);
	public void removeItemFromShoppingCart(Item item);
}

class Guest extends User {

	public Account createNewAccount(); // this is anonymous user

}

class RegisteredUser extends User {
	Account account;
}

class Seller extends User {

	public void addProduct(Product product);
}

class Buyer extends User {

	Order orderObj;
	vector<Order> allOrders;

	public void addReview(ProductReview review);
	public OrderStatus placeOrder(ShoppingCart cart);
	public vector<Order> getAllOrders();

}

class Account {

	String name;
	String email;
	String phoneNumber;
	String userName;
	String password;
	List<Address> shippingAdresses;
}

class Address {

	int pinCode; //ZipCode
	String street;
	String city;
	String state;
	String country;
}

class ShoppingCart {

	List<Item> items;
	double cartValue;

	public void addItem(Item item);
	public void updateItem(Item item);
	public void deleteItem(Item item);
	public List<Item> getItems();
	public double getCartValue();
}

class Item {

	Product product;
	int qty;

}

class Product {

	int productId;
	String productDescription;
	String name;
	ProductCategory productCategory;
	Seller seller;
	double cost;

	List<ProductReview> productReviews;

}


class ProductReview {

	String details;
	Buyer reviewer;
	int rating;

}

class search {

	public List<Product> searchByName(String name);
	public List<Product> searchByCategory(ProductCategory productCategory);
}

class Order {

	int orderId;
	List<Item> orderItem;
	double orderValue;
	Buyer buyer;
	Date orderDate;

	public OrderStatus placeOrder();
	public OrderStatus trackOrder();
	public void makePayment(PaymentType paymentType);

}

public enum ProductCategory {

	ELECTRONICS,FURNITURE,GROCERY,MOBILE;
}

public enum OrderStatus {

	PACKED, SHIPPED, ENROUTE, OUT_FOR_DELIVERY, DELIVERED, CANCELLED;
}

public enum PaymentStatus {

	SUCCESS, ERROR, CANCELLED, REFUND_INITIATED, REFUNDED;

}

public enum PaymentType {

	CREDIT_CARD, DEBIT_CARD, NET_BANKING, UPI;
}
