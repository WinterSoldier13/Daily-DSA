// LIBRARY
// 1. It should have members and Librarian 
// 2. Members should be able to issue a book either though
//    automatic computer or a librarian
// 4. Members and Librarian should be able to search for a book
// 5. There can be multiple copies of the same book
// 6. The book can be of different genere (like sci-fi, drama) and format(like hardcover, paperback)
// 7. Each book is kept on a unique rack


class Library {

	String name;
	Address location;
	List<BookItem> books;
}

class Book {

	long ISBN;
	String title;
	List<Author> authors;
	BookType bookType;
}

// we are defining this because there can be multiple copies of the same book
class BookItem extends Book {
	int itemId;
	Date publicationDate;
	Rack rackLocation;
	BookFormat bookFormat;

	BookStatus bookStatus;
	Date issueDate;
	List<Member> issueHistory;
}

class Address {

	int pinCode //ZipCode
	String street;
	String city;
	String state;
	String country;
}

public enum BookType {

	SCI_FI, ROMANTIC, FANTASY, DRAMA;
}

public enum BookFormat {

	HARDCOVER, PAPERBACK, NEWSPAPER, JOURNAL;
}

public enum BookStatus {

	ISSUED, AVAILABLE, RESERVED, LOST;
}

class Rack {

	int number;
	String locationId;

}

class Person {

	String firstName;
	String lastName;

}

class Author extends Person {

	List<Book> booksPublished;

}

class SystemUser extends Person {

	String Email;
	String phoneNumber;
	Account account;
}

class Member extends SystemUsers {

	int totalBookCheckedOut;
	List<BookItem> bookHistory;

	Search searchObj;
	BookIssueService issueService;

}

class Librarian extends SystemUsers {

	Search searchObj;
	BookIssueService issueService;

	public void addBookItem(BookItem bookItem);
	public BookItem deleteBookItem(); 
	public BookItem editBookItem(BookItem bookItem);
}

class Account {

	String userName;
	String password;
	int accountId;
}

class Search {

	public List<BookItem> geBookByTitle(String title);
	public List<BookItem> geBookByAuthor(Author author);
	public List<BookItem> geBookByType(BookType bookType);
	public List<BookItem> geBookByPublicationDate(Date publicationDate);

}

class BookIssueService {

	public BookReservationDetail getReservationDetail(BookItem book);

	public void updateReservationDetail(BookReservationDetail bookReservationDetail);

	public BookReservationDetail reserveBook(BookItem book, SystemUser user);

	public BookIssueDetail issueBook(BookItem book, SystemUser user);

	// it will internaly call the issueBook function after basic validations
	public BookIssueDetail renewBook(BookItem book, SystemUser user); 

	public void returnBook(BookItem book, SystemUser user);

}

class BookLending {

	BookItem book;
	Date startDate;
	SystemUser user;
}

class BookReservationDetail extends BookLending {

	BookReservationStatus reservationStatus;

}

class BookIssueDetail extends BookLending {

	Date dueDate;

}
