//C++ Program that manages an 'Aquarium and Pet Shop' details
//Created by Simon Calvin S

#include <iostream>
using namespace std;

class Pet{
	int petId,price,age;
	string* petName;
	string* breed;
	bool ifavailable;
	public:
		Pet(){
			petId=0;
			petName=new string; //dynamic memory allocation using new
			breed=new string;
			price=0;
			age=0;
			ifavailable=false;
		}
		virtual ~Pet(){
			delete petName; //dynamic memory deallocation using delete
			delete breed;
		}
		static int makePetId(){ //static function
            static int nextId = 101; //static variable
            return nextId++;
        }
		void setPets(string petName,string breed,int price,int age){
			petId = makePetId();
			*this->petName=petName;
			*this->breed=breed;
			this->price=price;
			this->age=age;
			ifavailable=true;
		}
		int getPrice(){return price;}
		bool available(){return ifavailable;}
		Pet& operator++(){++price;} //operator overloading for pre increment
		void operator!(){ifavailable = !ifavailable;} //operator overloading
    	virtual void display(){ //virtual function
			cout << "Pet ID : " << petId << endl;
			cout << "Pet Name : " << *petName << endl;
			cout << "Pet Breed : " << *breed << endl;
			cout << "Pet Price : " << price << endl;
			cout << "Pet Age : " << age << endl;
			cout << "Pet Availability : " << (ifavailable ? "Available" : "Not Available") << endl << endl;
		}
};

class Birds : public Pet{ //single inheritance
	int cagelength,cagebreadth,cageprice;
	public:
		Birds(){
			cagelength=0;
			cagebreadth=0;
			cageprice=0;
		}
		~Birds(){}
		void setBirdCage(int length,int breadth,int cageprice){
			cagelength=length;
			cagebreadth=breadth;
			this->cageprice=cageprice;
		}
		void display() override{ //virtual function overloading
			cout << "\n----------Bird details----------\n" << endl;
			Pet::display();
			cout << "Bird cage size : " << cagelength << "*" << cagebreadth << endl;
			cout << "Bird cage price : "<< cageprice << endl;
		}
		int getCagePrice(){return cageprice;}
};

class Dogs : public Pet{ //single inheritance
	int doghouselen,doghousewid,doghousepri;
	public:
		Dogs(){
			doghouselen=0;
			doghousewid=0;
			doghousepri=0;
		}
		~Dogs(){}
		void setHouse(int len,int wid,int h_pri){
			doghouselen=len;
			doghousewid=wid;
			doghousepri=h_pri;
		}
		void display() override{ //virtual function overloading
			cout << "\n----------Dog details----------\n" << endl;
			Pet::display();
			cout << "Dog house size : " << doghouselen << "*" << doghousewid << endl;
			cout << "Dog house price : " << doghousepri << endl;
		}
		int getHousePri(){return doghousepri;}
};

class Fishes : public Pet{ //single inheritance
	int tanklength,tankbreadth;
	string* watertype;
	public:
		Fishes(){watertype=new string;}
		~Fishes(){delete watertype;}
		void setFish(int t_length,int t_breadth,string w_type){
			tanklength=t_length;
			tankbreadth=t_breadth;
			*watertype=w_type;
		}
		void display() override{ //virtual function overloading
			cout << "\n----------Fish details----------\n" << endl;
			Pet::display();
			cout << "Tank size suitable : " << tanklength << "*" << tankbreadth << endl;
			cout << "Water type : " << *watertype << endl << endl;
		}
};

class Aquarium : public Fishes{ //multilevel inheritance
	string* tankName;
	int no_of_litres,tankprice;
	public:
		Aquarium(){tankName=new string;}
		~Aquarium(){delete tankName;}
		void setAqua(string nametank,int capacity){
			*tankName=nametank;
			no_of_litres=capacity;
			tankprice=capacity*10;
		}
		void displayAqua(){
			cout << "Tank Name : " << *tankName << endl;
			cout << "Litre Capacity : " << no_of_litres << "litres" << endl;
			cout << "Tank Price : " << tankprice << endl;
		}
		int getAquaPrice(){return tankprice;}
};

class Employee{
	int e_id[10]; //array
	string e_name[10]; //array
	int empCount;
	public:
		Employee(){empCount=0;}
		~Employee(){}
		void start(){cout << "\n---------------------------Simon Aquarium and Pet Shop---------------------------\n" << endl;}
		static int makeEmpId(){
			static int nextEmp=1;
			return nextEmp++;
		}
		void setEmp(string e_name){
			if(empCount<10){
				e_id[empCount]=makeEmpId();
				this->e_name[empCount]=e_name;
				empCount++;
			}
			else{
				cout << "Maximum employee limit reached" << endl;
			}
		}
		void printEmp(){
			cout << "---------Employee details---------\n" << endl;
			for(int i=0;i<empCount;++i){ //for loop
				cout << "Employee ID : " << e_id[i] << endl;
				cout << "Employee Name : " << e_name[i] << endl;	
			}
		}
		void endProgram(){
			cout << "\n\n";
			cout << "Thanks for visiting, visit us again!" << endl;
			cout << "Reminder : Meet any one of our employees to proceed with your payment" << endl;
		}
};

class OrderDetails{
	int o_id;
	string o_date;
	public:
		OrderDetails(){
			o_id=0;
			o_date="";
		}
		~OrderDetails(){}
		static int makeOrderId(){
			static int nextOrder=201;
			return nextOrder++;
		}
		void setOrderDet(string oDate){
			o_id=makeOrderId();
			o_date=oDate;
		}
		friend int getorderid(OrderDetails& order);
		friend string getorderdate(OrderDetails& order);
};
int getorderid(OrderDetails& order){return order.o_id;}
string getorderdate(OrderDetails& order){return order.o_date;}

class CustomerOrders : public Employee,public OrderDetails{ //multiple inheritance
	int custId;
	string custName;
	int totalPrice;
	public:
		CustomerOrders(){
			custId=0;
			custName="";
			totalPrice=0;
		}
		static int makeCustID(){
			static int nextCust=1001;
			return nextCust++;
		}
		void setCustomer(string c_name){
			custId=makeCustID();
			custName=c_name;
			totalPrice=0;
		}
		void yourorder(Birds& bird,Dogs& dog,Aquarium& aqua){
			int choice;
			while(true){ //while loop
				cout << "\n--------Select the product to buy--------\n" << endl;
				cout << "1. Buy Bird\n";
				cout << "2. Buy Dog\n";
				cout << "3. Buy Fish\n";
				cout << "4. Exit\n";
				cout << "Enter your choice (1,2,3 or 4): ";
				cin >> choice;
				if(cin.fail()){ //when user doesn't enter integer value for choice
					cin.clear();
					cin.ignore(1000,'\n');
					cout << "Invalid input! Please enter a number between 1 and 4." << endl;
					continue;
				}
				switch(choice){ //switch cases
					case 1:
						if(bird.available()){
							cout << "\nBird price added to purchase amount" << endl;
							bird.display();
							totalPrice+=bird.getPrice();
							cout << "--------------------------------" << endl;
							int cagechoice;
							cout << "Do you want to buy a cage?" << endl;
							cout << "\n1. Buy cage for bird\n2. Not buying cage" << endl;
							cout << "Enter your choice (1 or 2): ";
							cin >> cagechoice;
							if(cagechoice==1){
								totalPrice += bird.getCagePrice();
								cout << "Cage price added to purchase amount" << endl;
							}
							else if(cagechoice==2){
								cout << "Cage not bought" << endl;
							}
							else{
								cout << "Invalid choice" << endl;
								cout << "Cage not bought" << endl;
							}
						}
						else{
							cout << "Not available for sale" << endl;
						}
						break;
					case 2:
						if(dog.available()){
							cout << "\nDog price added to purchase amount" << endl;
							dog.display();
							totalPrice+=dog.getPrice();
							cout << "--------------------------------" << endl;
							int housechoice;
							cout << "Do you want to buy a dog house?" << endl;
							cout << "\n1. Buy dog house for dog\n2. Not buying dog house" << endl;
							cout << "Enter your choice (1 or 2): ";
							cin >> housechoice;
							if(housechoice==1){
								totalPrice += dog.getHousePri();
								cout << "Dog house price added to purchase amount" << endl;
							}
							else if(housechoice==2){
								cout << "Dog house not bought" << endl;
							}
							else{
								cout << "Invalid choice" << endl;
								cout << "Dog house not bought" << endl;
							}
						}
						else{
							cout << "Not available for sale" << endl;
						}	
						break;
					case 3:
						if(aqua.available()){
							cout << "\nFish price added to purchase amount" << endl;
							aqua.display();
							totalPrice+=aqua.getPrice();
							cout << "--------------------------------" << endl;
							aqua.displayAqua();
							int tankchoice;
							cout << "Do you want to buy a fish tank?" << endl;
							cout << "\n1. Buy tank for fish\n2. Not buying tank " << endl;
							cout << "Enter your choice (1 or 2): ";
							cin >> tankchoice;
							cout << endl;
							if(tankchoice==1){
								totalPrice+=aqua.getAquaPrice();
								cout << "Tank price added to purchase amount" << endl;
							}
							else if(tankchoice==2){
								cout << "Tank not bought" << endl;
							}
							else{
								cout << "Invalid choice" << endl;
								cout << "Tank not bought" << endl;
							}
						}
						else{
							cout << "Not available for sale" << endl;
						}
						break;
					case 4:
						if(totalPrice>0){
							while(true){
								cout << "-----------------------------\n\n\n";
								cout << "Thank you for your purchase!\n";
								cout << "Total Price: Rs. " << totalPrice << endl;
								int paychoice;
								cout << "Select a method to pay" << endl;
								cout << "Available options : " << endl;
								cout << "\n1. Credit/Debit\n2. Cash\n3. Online" << endl;
								cout << "Enter your choice(1,2 or 3) : ";
								cin >> paychoice;
								if(paychoice==1){
									cout << "\nProcessing credit/debit payment\n" << endl;
									cout << "CONTACT OUR EMPLOYEE TO CONTINUE WITH THE PAYMENT" << endl;
									printEmp();
									break;
								}
								else if(paychoice==2){
									cout << "\nProcessing cash payment\n" << endl;
									cout << "CONTACT OUR EMPLOYEE TO CONTINUE WITH THE PAYMENT" << endl;
									printEmp();
									break;
								}
								else if(paychoice==3){
									cout << "\nProcessing online payment\n" << endl;
									cout << "CONTACT OUR EMPLOYEE TO CONTINUE WITH THE PAYMENT" << endl;
									printEmp();
									break;
								}
								else{
									cout << "Wrong choice. Try again." << endl;
								}
							}
						}
						else{
							cout << "Thank you for visiting our shop" << endl;
						}
						return;
					default:
						cout << "Invalid choice! Please try again." << endl;
				}
			}
		}
		void printOrderDet(){
			cout << "\n----------Order Details----------\n" << endl;
			cout << "Order ID : " << getorderid(*this) << endl;
			cout << "Order Date : " << getorderdate(*this) << endl;
			cout << "Customer ID : " << custId << endl;
			cout << "Customer Name : " << custName << endl;
			cout << "Total Purchase Amount : Rs. " << totalPrice << endl;
		}
};

int main(){
	Employee e;
	e.start();
	cout << "Pets available for sale : " << endl;
	Pet* petobj;
	Birds bird;
	bird.setPets("Parrot","Macaw",8000,3);
	bird.setBirdCage(6,6,300);
	++bird; //operator overloading for pre increment
	petobj=&bird;
	petobj->display();
	Dogs dog;
	dog.setPets("Bulldog","English Bulldog",2000,5);
	dog.setHouse(6,6,200);
	!dog; //operator overloading
	Aquarium aqua;
	aqua.setPets("Goldfish","Fancy Goldfish",100,1);
	aqua.setFish(2,3,"Freshwater");
	aqua.setAqua("Deluxe Tank",20);
	petobj=&aqua;
	petobj->display();
	CustomerOrders order;
	string name;
	cout << "Enter your name to place your order : ";
	getline(cin,name);
	order.setCustomer(name);
	order.setEmp("Peter");
	order.setEmp("John");
	order.setOrderDet("19-10-2024");
	order.yourorder(bird,dog,aqua);
	order.printOrderDet();
	e.endProgram();
	return 0;
}
