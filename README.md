cis2252_final_project
=====================
Assignment Definition 

This assignment requires the development of C++ software that supports the back-end activities of an imaginary food service (i.e., software that simulates the processing of customer service requests and management of inventory). Customers will use a separate Web-based app that stores request details in specially formatted text files (see input definitions below). Your food service application must read these text files, manage active order activity in virtual “shopping carts”, and then update inventory and produce receipts (as output text files) when orders are complete. Also, your application must manage customer payment accounts and provide system support functions for inventory control and reporting. The following list represents the minimum set of functional requirements.

•	Addition of food items to shopping carts. (Inventory is temporarily updated.)
•	Removal of food items from shopping carts. (Temporary changes to inventory are cancelled.)
•	Creation of shopping cart reports. (Output text file with list of cart items for a specific customer.)
•	Processing of payment upon checkout. (Includes processing of coupons.)
•	Processing of order information in customer carts upon checkout. (Commit changes to inventory.)
•	Management of debit accounts for customers. (All payments must be made from these accounts.)
•	Addition of food item quantity to the inventory of the food service (i.e., re-stocking)
•	Creation of inventory control reports. (Report for entire inventory or for specific food items.)


Assumptions, Pre-conditions and Minimum Data Requirements


General: 	Customer account info (name, account#, etc.) must be pre-loaded in a customer file.
	Customer requests may be stored in separate or combined text files. (See below.)
	Sample request files used for testing must be pre-generated.
	A simple console user interface must be provided for inventory control and reporting.
Payment and
Debit Accounts:	Customers are given an initial balance on their service debit account.
	You need to keep track of account balances and reject payments over that amount.
	Customers may submit requests to add money to their food service debit accounts.
	If total cost of cart items exceeds account balance, then cancel checkout.
Food Items: 	You must define a minimum of twenty (20) types of food items.
	Initial inventory (food, quantity, prices) must be pre-loaded into an inventory file.
	Customers must specify a quantity for each food item request.
	Price changes may occur during re-stocking but do not affect price of items in carts.
	Adding or removing food to carts causes only temporary changes to inventory data.
Shopping Carts:	Each customer may use only one cart at a time.
	The food service can handle a maximum of twenty (20) active carts at one time.
	Customers may save cart contents and continue later but only on the same day.
	Checkout request files will also contain any coupon information. (Max. 10 coupons.)
	Customer cart reports must show all cart items with prices, quantities, and a total.
	Each cart is deleted immediately after payment and checkout.
	Customers may only remove cart items for one food item at a time.
	Entire quantity specified for addition to a cart must be available (no partial orders).
Inventory
Control and
Reporting:	Service support staff may perform re-stocking actions at any time.
	Food re-stocking inputs specify food item names, prices, and quantities.
	Re-stocking quantity values must be added to current quantity levels.
	Inventory control reports are only displayed on a console screen – not saved to a file.
		

 
Implementation Requirements
 
You must use the following features or structures of the C++ programming language.

•	At least one (1) instance of inheritance using your own classes.
•	At least one (1) use of polymorphism and at least one (1) use of composition.
•	Initialization of class data must be performed in class constructors.
•	The array class template.
•	Pointer data types and the C++ String class.
•	At least one (1) instance of operator overloading other than stream input or output.
•	At least one (1) use of an STL container with associated iterator and algorithms.
•	Exception handling must be implemented to validate user inputs.
•	All customer, account, cart and inventory data must be stored in random access binary files (.dat).
•	Inventory control input and output should be implemented with a simple text-based console window.

User Input Definitions

Customer requests

Each customer request may be contained in its own file or combined with similar requests. Each file name must end with a sequence number that indicates the order in which files must be processed by your application (e.g., REQUEST01.TXT, REQUEST04.TXT, REQUEST02.TXT, REQUEST03.TXT). You must pre-generate enough sample request files to adequately test your application and all of its functions.




  OR





Request Formats (text file content):
•	Adding a food item to a cart  	=  ADD:customer_number,food_item_name,quantity
•	Removing a food item from a cart 	=  REMOVE:customer_number,food_item_name,quantity
•	Creation of shopping cart reports	=  CARTREPORT:customer_number
•	Customer checkout	=  CHECKOUT:customer_number,coupon_list
•	Add money to debit account	=  CREDIT:customer_number,money_amount

	Notes:
1.	“coupon_list” is a list of food item money amount pairs. Each pair is enclosed in square brackets and values separated with a comma (e.g., [Apples,-1.00][Milk,-0.75])
2.	“customer_number” is an 8-digit value (e.g., 23738495)

Inventory Control User Interface

The user interface for the inventory control must be implemented with a simple text-based console window. Use basic stream input and output (cin and cout) to prompt the user for input and display results.
 
User Output Definitions

Shopping Cart Reports

Customers may request to see the contents of their shopping cart at any time. Upon request, you must write the following information to a text file (.TXT). The file name must contain the customer account number (e.g., CARTREPORT23738495.TXT).

•	Customer account number
•	A list of food items with associated quantity and price values
•	Total cost of all items in this cart

Checkout Receipt

This is a report is almost identical to the cart report but it also includes a record of coupons applied.

•	Current date
•	Customer account number
•	A list of food items with associated quantity and price values
•	A list of coupons each represented by the associated food name and discount price
•	Total cost of all items in this cart at checkout

Inventory Controls Reports

There are only two types of inventory reports – one that shows all food items and one that shows only a selected item.

•	Current date
•	A list of food items with associated quantity and price values

OR

•	Current date
•	One food item with associated quantity and price value

Data Files

You must design your own files to hold data that your application needs to run properly. However, you must use only one file for all customer data (including account data), one file for all cart data and one file for all inventory data. Each of these three data files must use random access with binary format.

Validation and Error Messages

You must use C++ exception handling (try-throw-catch) to check for the follow exceptions. Print an appropriate error message in the console window whenever these exceptions are detected.

•	Food request quantity not available in inventory
•	Insufficient quantity in cart for remove request
•	Insufficient funds in debit account at checkout

 
Required Items to be Submitted for Stages of Development

Stage 1:	Samples of user input files for all functional requirements.
	UML class and communication (collaboration) diagrams.
Stage 2:	Description of data files and illustration showing which class methods access each file.
Stage 3:	Final tested version of C++ code
