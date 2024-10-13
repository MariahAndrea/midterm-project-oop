#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

class Item{
	private:
		string id, name, category;
		int quantity;
		float price;
		
	public:
		Item(string i, string n, int q, float p, string c){
			id = i;
			name = n;
			price = p;
			quantity = q;
			category = c;
		}
		
		string getID(){ return id; }
		string getName(){ return name; }
		float getPrice(){ return price; }
		int getQuantity(){ return quantity; }
		string getCategory(){ return category; }	
		
		void setQuantity(int quantity) { this->quantity = quantity; } // for setting a new quantity
		void setPrice(int price) { this->price = price; } // for setting a new price
		
		virtual void addItem() = 0;
		virtual void viewItems() = 0;

		virtual ~Item() = default;
};

class AllItems{
	private:
		vector<Item*> allItems;
		
	public:	
		void addItem(Item* item) { //to add all the items from the catgories in one vector
			allItems.push_back(item);
		}
		
		bool checkDuplicates(string id){
			auto it = find_if(allItems.begin(), allItems.end(), [&](Item* item){ //to find a value in vector
				return item->getID() == id;
			});
			
			if (it == allItems.end()){ //check for duplicate IDs
				return false;
			} else {
				return true;
			}
		}
  		
		void updateQuantity(){
			string id;
			int newQuantity;
			bool priceupdatevalid = false;
			system("CLS");
			
			cout << "\n\n	===== U P D A T E  I T E M S   ( Q U A N T I T Y ) ===== " << endl << endl;
			
			if (allItems.empty()){
				cout << "	Inventory empty. Nothing to update. " << endl << endl; //displays when inventory is empty
				
			}  else {
				cout << "	Enter ID: ";
				cin.ignore();
				getline(cin, id);
				
				auto it = find_if(allItems.begin(), allItems.end(), [&] (Item* item){ //to find a value in vector
					return item->getID() == id;
				});
					
				if (it != allItems.end()){
					do {
						cout << "	Enter new quantity: ";
						cin >> newQuantity;
								
						if (cin.fail()) { //validation for if not integer
							cout << "	Invalid input. Please enter a number." << endl;
							cin.clear();
							cin.ignore(1000, '\n');
								
						} else if ( newQuantity < 0 ){
							cout << "	Invalid input. Must not be less than ." << endl;
							
						} else if ((*it)->getQuantity() == newQuantity){ //checks if same as original quantity
							cout << "	Must not be the same as previous value." << endl;
					
						}  else{
								cout << "	Price of item " << (*it)->getName() << " is updated from " << (*it)->getQuantity() << " to " << newQuantity << endl << endl;
								(*it)->setPrice(newQuantity); //updates quantity 
								break;
								
							}
						} while (!priceupdatevalid);
							
					} else {   
						cout << "	Item not found!" << endl;
					}
			}
			
			system("PAUSE");
			system("CLS");
		}
		
		void updatePrice(){
			string id;
			double newPrice;
			bool priceupdatevalid = false;
			system("CLS");
			
			cout << "\n\n	===== U P D A T E  I T E M S   ( P R I C E ) ===== " << endl << endl;
			
			if (allItems.empty()){
				cout << "	Inventory empty. Nothing to update. " << endl << endl; //displays when inventory is empty
				
			} else{
				cout << "	Enter ID: ";
				cin.ignore();
				getline(cin, id);
				
				auto it = find_if(allItems.begin(), allItems.end(), [&] (Item* item){ //to find a value in vector
					return item->getID() == id;
				});
					
				if (it != allItems.end()){
					do {
						cout << "	Enter new price: ";
						cin >> newPrice;
								
						if (cin.fail()) { //validation for if not integer
							cout << "	Invalid input. Please enter a number." << endl;
							cin.clear();
							cin.ignore(1000, '\n');
								
						} else if ( newPrice < 0 ){
							cout << "	Invalid input. Must not be less than ." << endl;
							
						} else if ((*it)->getPrice() == newPrice){ //checks if same as original price
							cout << "	Must not be the same as previous value." << endl;
					
						}  else{
								cout << "	Price of item " << (*it)->getName() << " is updated from " << (*it)->getPrice() << " to " << newPrice << endl << endl;
								(*it)->setPrice(newPrice); //updates price 
								break;
								
							}
						} while (!priceupdatevalid);
							
					} else {   
						cout << "	Item not found!" << endl;
					}
			}
			system("PAUSE");
			system("CLS");
		}
		
		void deleteItem(){
			string id; 
			system("CLS");
			
			cout << "\n	===== D E L E T E   I T E M S ===== " << endl << endl;
			
			if (allItems.empty()){
				cout << "	Inventory empty. Nothing to delete." << endl << endl;
				
			} else{
				cout << "	Enter ID of item: ";
				getline(cin, id);			
				
				auto it = find_if(allItems.begin(), allItems.end(), [&]( Item* item){
	            	return item->getID() == id;
	       		});
	
	     	   if (it != allItems.end()){
	    	    	cout << "	Item " << (*it)->getName() << " has been removed from inventory." << endl;
	    	        allItems.erase(it);
	    	    } else{
	            	cout << "	Item not found!" << endl;
				}	
			}
			
			system("PAUSE");
			system("CLS");		
		}	
		
		void displayAllItems(){
			system("CLS");
			
			cout << "\n	============================== A L L   I T E M S ==============================" << endl << endl;

			if (allItems.empty()){
				cout << "	No items to show. Add items to show." << endl << endl;
				
			} else{
				cout << "	ID" << setw(20) << "Name" << setw(20) << "Quantity" << setw(15) << "Price" << setw(20) << "Category" << endl << endl;
				for (int i= 0; i < allItems.size(); i++){
					cout << setw(10) << allItems[i]->getID() << setw(20)  << fixed << allItems[i]->getName() << setw(20) << allItems[i]->getQuantity() << setw(15) << setprecision(2) << allItems[i]->getPrice() << setw(20) << allItems[i]->getCategory() << fixed << endl;
				}
			}
			cout << endl;
			system("PAUSE");
			system("CLS");	 	
		}
		
		void searchItems(){
			string id;
			system("CLS");
			
			cout << "\n	============== S E A R C H   I T E M S ==============" << endl << endl;
			
			if (allItems.empty()){
				cout << "	Inventory empty. Nothing to search" << endl << endl;
				
			} else{
				cout << "	Enter ID: "; 
				getline (cin, id);
				
				auto it = find_if(allItems.begin(), allItems.end(), [&](Item* item){ //to find a value in vector
					return item->getID() == id;
				});
				
				if (it != allItems.end()){ 
					cout << "	-------------------------------------"<< endl;
					cout << "	Item Details: "<< endl << endl;
					cout << "	Name: " << (*it)->getName() << endl;
					cout << "	Quantity: " << (*it)->getQuantity() << endl;
					cout << "	Price: " << (*it)->getPrice() << endl;
					cout << "	Category: " << (*it)->getCategory() << endl << endl;
					cout << "	-------------------------------------" << endl << endl;
				} else {
					cout << "	Item not found!" << endl;
				}
			}
				
			system("PAUSE");
			system("CLS");
		}
		
		void sortItemsQuantity(){
			int option;
			bool sortvalid = false;
			system("CLS");
			
			cout << "\n	============== S O R T   I T E M S   ( Q U A N T I T Y ) ==============" << endl << endl;
			
			if (allItems.empty()){
				cout << "	Inventory empty. Nothing to sort." << endl << endl;
				
			} else {
				cout << " 	-----------------------------" << endl << endl;
				cout << "	IN ORDER OF: " << endl << endl;
				cout << "	[1] Ascending" << endl;
				cout << "	[2] Descending" << endl << endl;
				cout << " 	-----------------------------" << endl << endl;
				
				do {
					cout << "	Enter option: ";
					cin >> option;
					cin.ignore();
					
					if (cin.fail()) { //validation for if not integer
						cout << "	Invalid input. Please enter an integer." << endl << endl;
						cin.clear();
						cin.ignore(1000, '\n');
					} else if (option > 2 || option < 1 ){
						cout << "	Invalid input. Please enter either 1 or 2 only." << endl << endl;
					} else{
						break;
					}
				} while (!sortvalid);
					
				switch (option){
					case 1:
						sort(allItems.begin(), allItems.end(), [](Item* a, Item* b){
							return a->getQuantity() < b->getQuantity();
						});
						for (int i= 0; i < allItems.size(); i++){
							cout << setw(10) << allItems[i]->getID() << setw(20)  << fixed << allItems[i]->getName() << setw(20) << allItems[i]->getQuantity() << setw(15) << setprecision(2) << allItems[i]->getPrice() << setw(15) << allItems[i]->getCategory() << endl;
						}
						break;
					case 2:
						sort(allItems.begin(), allItems.end(),[](Item* a, Item* b){
							return a->getQuantity() > b->getQuantity();
						});
						for (int i= 0; i < allItems.size(); i++){
							cout << setw(10) << allItems[i]->getID() << setw(20)  << fixed << allItems[i]->getName() << setw(20) << allItems[i]->getQuantity() << setw(15) << setprecision(2) << allItems[i]->getPrice() << setw(15) << allItems[i]->getCategory() << endl;
						}
						break;
					default:
						cout << "	Invalid input. Enter either 1 or 2 only." << endl;
						break;
				}
			}
			
			system("PAUSE");
			system("CLS");
			
		}
		
		void sortItemsPrice(){
			int option;
			bool sortvalid = false;
			system("CLS");
			
			cout << "\n	============== S O R T   I T E M S   ( P R I C E ) ==============" << endl << endl;
			
			if (allItems.empty()){
				cout << "	Inventory empty. Nothing to sort." << endl << endl;
				
			} else{
				cout << " 	-----------------------------" << endl << endl;
				cout << "	IN ORDER OF: " << endl << endl;
				cout << "	[1] Ascending" << endl;
				cout << "	[2] Descending" << endl << endl;
				cout << " 	-----------------------------" << endl << endl;
				
				do {
					cout << "	Enter option: ";
					cin >> option;
					cin.ignore();
					
					if (cin.fail()) { //validation for if not integer
						cout << "	Invalid input. Please enter an integer." << endl << endl;
						cin.clear();
						cin.ignore(1000, '\n');
					} else if (option > 2 || option < 1 ){
						cout << "	Invalid input. Please enter either 1 or 2 only." << endl << endl;
					} else{
						break;
					}
				} while (!sortvalid);
					
				switch (option){
					case 1:
						sort(allItems.begin(), allItems.end(), [](Item* a, Item* b){ //compares the price of each item
							return a->getPrice() < b->getPrice();
						});
						for (int i= 0; i < allItems.size(); i++){
							Item* item = allItems[i];
							cout << setw(10) << item->getID() << setw(20)  << fixed << item->getName() << setw(20) << item->getQuantity() << setw(15) << setprecision(2) << item->getPrice() << setw(15) << item->getCategory() << endl;
						}
						break;
					case 2:
						sort(allItems.begin(), allItems.end(),[](Item* a, Item* b){
							return a->getQuantity() > b->getQuantity();
						});
						for (int i= 0; i < allItems.size(); i++){
							Item* item = allItems[i];
							cout << setw(10) << item->getID() << setw(20)  << fixed << item->getName() << setw(20) << item->getQuantity() << setw(15) << setprecision(2) << item->getPrice() << setw(15) << item->getCategory() << endl;
						}
						break;
					default:
						cout << "	Invalid input. Enter either 1 or 2 only." << endl;
						break;
				}
			}
			
			system("PAUSE");
			system("CLS");
		}
		
		void displayLowStock(){	
			bool lowstockvalid = false;
			system("CLS");
			
			cout << "\n	=================== L O W   S T O C K   I T E M S ===================" << endl << endl;
			
			if (allItems.empty()){
				cout << "	Inventory empty. No item to display." << endl << endl;
				
			} else{
				cout << "	ID" << setw(20) << "Name" << setw(20) << "Quantity" << setw(15) << "Price" << setw(20) << "Category" << endl << endl;
					
				for (int i= 0; i < allItems.size(); i++){
					Item* item = allItems[i];
					if (item->getQuantity() <= 5){
						lowstockvalid = true;
							cout << setw(10) << allItems[i]->getID() << setw(20)  << fixed << allItems[i]->getName() << setw(20) << allItems[i]->getQuantity() << setw(15) << setprecision(2) << allItems[i]->getPrice() << setw(20) << allItems[i]->getCategory() << fixed << endl;
					} 	
				}
				
				if (!lowstockvalid) {
						cout << "	No items with less then 5 stock." << endl;
				}
			}
			cout << endl;
			system("PAUSE");
			system("CLS");
		}
		  
};

class Clothing : public Item{
	private: 
		vector<Item*> clothing;
		AllItems& allItems;
		
	public:
		Clothing(string i, string n, int q, float p, AllItems& allItemsObj)  : Item(i, n, q, p, "Clothing"), allItems(allItemsObj) {}
		
		void addItem() override{
			string id, name;
			int quantity;
			double price; 
			bool idvalid = false;
			bool namevalid = false;
			bool quantityvalid = false;
			bool pricevalid = false;
			
			//id input
			do {
				cout << "\n	Enter ID: ";
				getline (cin, id);
				
				if (id.empty()){ //checks if input is empty
					cout << "	Invalid input. ID cannot be empty.";
					continue;
				} 
				
				if (allItems.checkDuplicates(id) == false){//validation if duplicate id
					break;
				} else {
					cout << "	Item with ID " << id << " already exists." << endl;
				}	
				
			} while (!idvalid);
			 		
			//name input	
			do {
				cout << "	Enter Name: ";
				getline(cin, name);
				
				if (name.empty()){
					cout << "	Invalid input. Name cannot be empty." << endl;
				} else {
					break;
				}
			} while (!namevalid);
				
			//quantity input
			do { 
				cout << "	Enter Quantity: ";
				cin >> quantity;
				
				if (cin.fail() || (cin.peek() != '\n')) { //validation for if not integer and if has symbols and spaces
					cout << "	Invalid input. Please enter an integer." << endl;
					cin.clear();
					cin.ignore(1000, '\n');
				} else if (quantity < 1 ){
					cout << "	Invalid input. Must not be less than 1." << endl;
				} else {
					break;
				}
			} while (!quantityvalid);
			
			//price input
			do {
				cout << "	Enter Price: ";
				cin >> price;
				
				if (cin.fail() || (cin.peek() != '\n')) { //validation for if not integer
						cout << "	Invalid input. Please enter a number." << endl;
						cin.clear();
						cin.ignore(1000, '\n');
				} else if (price < 1 ){
					cout << "	Invalid input. Must not be less than 1." << endl;
				} else {
					break;
				}
			} while (!pricevalid);
			
			//add item	
			Clothing* newClothing = new Clothing(id, name, quantity, price, allItems);
			clothing.emplace_back(newClothing);
			allItems.addItem(newClothing);
			cout << "\n	Item added successfully" << endl << endl;
			
			system("PAUSE");
			system("CLS");
		}
		
		void viewItems() override{
			system("CLS");
			cout << "\n	============== C L O T H I N G   I T E M S ============== " << endl << endl;
			
			if (clothing.empty()){
				cout << "	No items to display. Add items to display." << endl;
				
			} else{
				cout << "	ID" << setw(20) << "Name" << setw(20) << "Quantity" << setw(15) << "Price" << endl << endl;
	        	for (int i= 0; i < clothing.size(); i++) {
					cout << setw(10) << clothing[i]->getID() << setw(20)  << fixed << clothing[i]->getName() << setw(20) << clothing[i]->getQuantity() << setw(15) << setprecision(2) << clothing[i]->getPrice() << endl;
	        	}
			}	
			cout << endl;
			system("PAUSE");
			system("CLS");
		}
			
};

class Electronics : public Item{
	private: 
		vector<Item*> electronics;
		AllItems& allItems;
		
	public:	
		Electronics(string i, string n, int q, float p, AllItems& allItemsObj)  : Item(i, n, q, p, "Electronics"), allItems(allItemsObj) {}
		
		void addItem() override{
			string id, name;
			int quantity;
			double price; 
			bool idvalid = false;
			bool namevalid = false;
			bool quantityvalid = false;
			bool pricevalid = false;
			
			//id input
		do {
				cout << "\n	Enter ID: ";
				getline (cin, id);
				
				if (id.empty()){ //checks if input is empty
					cout << "	Invalid input. ID cannot be empty.";
					continue;
				} 
				
				if (allItems.checkDuplicates(id) == false){//validation if duplicate id
					break;
				} else {
					cout << "	Item with ID " << id << " already exists." << endl;
				}
				
			} while (!idvalid);
			 			
			//name input	
			do {
				cout << "	Name: ";
				getline(cin, name);
				
				if (name.empty()){
					cout << "	Invalid input. Name cannot be empty." << endl;
				} else {
					break;
				}
			} while (!namevalid);
				
			//quantity input
			do { 
				cout << "	Quantity: ";
				cin >> quantity;
				
				if (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) { //validation for if not integer
						cout << "	Invalid input. Please enter an integer." << endl;
						cin.clear();
						cin.ignore(1000, '\n');
				} else if (quantity < 1 ){
					cout << "	Invalid input. Must not be less than 1." << endl;
				} else {
					break;
				}
			} while (!quantityvalid);
			
			//price input
			do {
				cout << "	Price: ";
				cin >> price;
				
				if (cin.fail()) { //validation for if not integer
						cout << "	Invalid input. Please enter a number." << endl;
						cin.clear();
						cin.ignore(1000, '\n');
				} else if (price < 1 ){
					cout << "	Invalid input. Must not be less than 1." << endl;
				} else {
					break;
				}
			} while (!pricevalid);
			
			//add item	
			Electronics* newElectronics = new Electronics(id, name, quantity, price, allItems);
			electronics.emplace_back(newElectronics);
			allItems.addItem(newElectronics);
			cout << "\n	Item added successfully" << endl << endl;
			
			system("PAUSE");
			system("CLS");
		}	
		
		void viewItems() override{
			system("CLS");
			cout << "\n	============== E L E C T R O N I C   I T E M S ============== " << endl << endl;
			
       		if (electronics.empty()){
				cout << "	No items to display. Add items to display." << endl;
				
			} else{
				cout << "	ID" << setw(20) << "Name" << setw(20) << "Quantity" << setw(15) << "Price" << endl << endl;
	        	for (int i= 0; i < electronics.size(); i++) {
					cout << setw(10) << electronics[i]->getID() << setw(20)  << fixed << electronics[i]->getName() << setw(20) << electronics[i]->getQuantity() << setw(15) << setprecision(2) << electronics[i]->getPrice() << endl;
	        	}
			}
			cout << endl;
			system("PAUSE");
			system("CLS");
		}	
};

class Entertainment : public Item{
	private:
		vector<Item*> entertainment;
		AllItems& allItems;
		
	public:
		Entertainment(string i, string n, int q, float p, AllItems& allItemsObj)  : Item(i, n, q, p, "Entertainment"), allItems(allItemsObj) {}
		
		void addItem() override{
			string id, name;
			int quantity;
			double price; 
			bool idvalid = false;
			bool namevalid = false;
			bool quantityvalid = false;
			bool pricevalid = false;
			
			//id input
			do {
				cout << "\n	Enter ID: ";
				getline (cin, id);
				
				if (id.empty()){ //checks if input is empty
					cout << "	Invalid input. ID cannot be empty.";
					continue;
				} 
				
				if (allItems.checkDuplicates(id) == false){//validation if duplicate id
					break;
				} else {
					cout << "	Item with ID " << id << " already exists." << endl;
				}	
				
			} while (!idvalid);
				
			//name input	
			do {
				cout << "	Name: ";
				getline(cin, name);
				
				if (name.empty()){
					cout << "	Invalid input. Name cannot be empty." << endl;
				} else {
					break;
				}
			} while (!namevalid);
				
			//quantity input
			do { 
				cout << "	Quantity: ";
				cin >> quantity;
				
				if (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) { //validation for if not integer
						cout << "	Invalid input. Please enter an integer." << endl;
						cin.clear();
						cin.ignore(1000, '\n');
				} else if (quantity < 1 ){
					cout << "	Invalid input. Must not be less than 1." << endl;
				} else {
					break;
				}
			} while (!quantityvalid);
			
			//price input
			do {
				cout << "	Price: ";
				cin >> price;
				
				if (cin.fail()) { //validation for if not integer
						cout << "	Invalid input. Please enter a number." << endl;
						cin.clear();
						cin.ignore(1000, '\n');
				} else if (price < 1 ){
					cout << "	Invalid input. Must not be less than 1." << endl;
				} else {
					break;
				}
			} while (!pricevalid);
			
			//add item	
			Entertainment* newEntertainment = new Entertainment(id, name, quantity, price, allItems);
			entertainment.emplace_back(newEntertainment);
			allItems.addItem(newEntertainment);
			cout << "\n	Item added successfully" << endl << endl;
			
			system("PAUSE");
			system("CLS");		
		}
		
		void viewItems() override{
			system("CLS");
			cout << "\n	============== E N T E R T A I N M E N T   I T E M S ============== " << endl << endl;
       			if (entertainment.empty()){
				cout << "	No items to display. Add items to display." << endl << endl;
				
			} else{
				cout << "	ID" << setw(20) << "Name" << setw(20) << "Quantity" << setw(15) << "Price" << endl << endl;
	        	for (int i= 0; i < entertainment.size(); i++) {
					cout << setw(10) << entertainment[i]->getID() << setw(20)  << fixed << entertainment[i]->getName() << setw(20) << entertainment[i]->getQuantity() << setw(15) << setprecision(2) << entertainment[i]->getPrice() << endl;
	        	}
			}
			cout << endl;
			system("PAUSE");
			system("CLS");
		}		
};

int main(){
	AllItems all;
	Clothing cloth("", "", 0, 0.0, all);
	Electronics elec("", "", 0, 0.0, all);
	Entertainment ent("", "", 0, 0.0, all);
	
	int option;
	bool menuvalid = false; //for validation
	char ch;
	
	do{
		cout << "\n	---------- I N V E N T O R Y ----------" << endl << endl;
		cout << "	[1] Add Item" << endl;
		cout << "	[2] Update Item" << endl;
		cout << "	[3] Remove Item" << endl;
		cout << "	[4] Display Items by Category" << endl;
		cout << "	[5] Display All Items" << endl;
		cout << "	[6] Search Item" << endl;
		cout << "	[7] Sort Items" << endl;
		cout << "	[8] Display Low Stock Items" << endl;
		cout << "	[9] Exit" << endl << endl;
	
		do {
			cout << "	Enter option: ";
			cin >> option;
			
			if (cin.fail() || (cin.peek() != '\n')) { //validation for if not integer
				cout << "	Invalid input. Please enter an integer." << endl << endl;
				cin.clear();
				cin.ignore(1000, '\n');
			} else if (option > 9 || option < 1 ){
				cout << "	Invalid input. Please choose from 1 to 9 only." << endl << endl;
			} else{
				cin.ignore(1000, '\n');
				break;
			}
		} while (option != 9 || !menuvalid);
		
		switch (option){
			
			case 1:{
				string category;
				system("CLS");
				
				cout << "\n	====== A D D   I T E M S =====" << endl << endl;
				cout << " 	-----------------------------" << endl << endl;
				cout << "	CATEGORIES: " << endl << endl;
				cout << "	> Clothing" << endl;
				cout << "	> Electronics" << endl;
				cout << "	> Entertainment" << endl << endl;
				cout << " 	-----------------------------" << endl;
				
				do {
					cout << "	Enter Category: ";
					getline(cin, category);
						
					for(char &c: category) {
						c = tolower(c);
					}
						
					if (category == "clothing"){
						cloth.addItem();
					} else if (category == "electronics"){
						elec.addItem();
					} else if (category == "entertainment"){
						ent.addItem();
					} else {
						cout << "	Category " << category << " does not exist." << endl;
					}
					
				} while (category != "clothing" && category != "electronics" && category != "entertainment");
				break;
			}
			
			case 2:{
				system("CLS");
				cout << "\n	========== U P D A T E   I T E M S =========" << endl << endl;
				cout << " 	-----------------------------" << endl << endl;
				cout << "	UPDATE ITEMS BY: " << endl;
				cout << "	[1] Quantity" << endl;
				cout << "	[2] Price" << endl << endl;
				cout << " 	-----------------------------" << endl;
				
				do {
					cout << "	Enter option: ";
					cin >> option;
						
					if (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) { //validation for if not integer
						cout << "	Invalid input. Please enter an integer." << endl << endl;
						cin.clear();
						cin.ignore(1000, '\n');
					} else if (option > 2 || option < 1 ){
						cout << "	Invalid input. Please choose either 1 or 2 only." << endl << endl;
					} else{
						break;
					}
				} while (!menuvalid);
				
				switch (option){
					case 1: 
						all.updateQuantity();
						break;
					case 2:
						all.updatePrice();
						break;
				}
			}
			break;
				
			case 3:
				all.deleteItem(); 

				break;
				
			case 4:{
				string category;
				system("CLS");
				
				cout << "\n	===== D I S P L A Y I N G   I T E M S   B Y   C A T E G O R Y ====" << endl << endl;
				cout << " 	-----------------------------" << endl << endl;
				cout << "	CATEGORIES: " << endl << endl;
				cout << "	> Clothing" << endl;
				cout << "	> Electronics" << endl;
				cout << "	> Entertainment" << endl << endl;
				cout << " 	-----------------------------" << endl;
				do {
					cout << "	Enter Category: ";
					getline(cin, category);
						
					for(char &c: category) {
						c = tolower(c);
					}
						
					if (category == "clothing"){
						cloth.viewItems();
						break;
					} else if (category == "electronics"){
						elec.viewItems();
					} else if (category == "entertainment"){
						ent.viewItems();
					} else {
						cout << "	Category " << category << " does not exist." << endl;
					}
				} while (category != "clothing" && category != "electronics" && category != "entertainment");
				cin.ignore();
				break;
			}
	
			case 5:
				all.displayAllItems();
				break;
				
			case 6:
				all.searchItems();
				break;
				
			case 7:{
				cout << "\n	========== S O R T   I T E M S =========" << endl << endl;
				cout << " 	-----------------------------" << endl << endl;
				cout << "	SORT ITEMS BY: " << endl;
				cout << "	[1] Quantity" << endl;
				cout << "	[2] Price" << endl << endl;
				cout << " 	-----------------------------" << endl;
				
				do {
					cout << "	Enter option: ";
					cin >> option;
					cin.ignore();
						
					if (cin.fail()) { //validation for if not integer
						cout << "	Invalid input. Please enter an integer." << endl << endl;
						cin.clear();
						cin.ignore(1000, '\n');
					} else if (option > 2 || option < 1 ){
						cout << "	Invalid input. Please choose either 1 or 2 only." << endl << endl;
					} else{
						break;
					}
					
				} while (!menuvalid);
				
				switch (option){
					case 1: 
						all.sortItemsQuantity();
						break;
					case 2:
						all.sortItemsPrice();
						break;
				}
			}	break;
			case 8:
				all.displayLowStock();
				break;
			case 9:
				cout << "	Exiting...";
				exit(0);
				break;
			default:
				cout << "	Invalid input. Please choose from 1-9 only.";
				break;
		}
	} while (option != 9);
	
}