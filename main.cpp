#include<iostream>
#include<fstream> 	//adding for file processing system
#include<string>
#include <Windows.h>
#include <unistd.h> //adding for delay
using namespace std;
//functions declearjation
void intro();
void userlogin();
void adminlogin();
void userreg();
void adminreg();
void user_home(string);
void admin_home();
void product_cat(string);
void add_product();
void billing(double,string);
void create_userhistory(string,double,int,string);
void show_history(string);
int get_num_of_purchases(string);
int main(){
	intro();	
}
//Welcome screen
void intro(){
	system("cls");
	int choice;
	system("Color 0B");

cout<<"\t---------------- Welcome To My Mart ----------------"<<endl<<endl;
sleep(1);
cout<<"\tPress 1 for Login"<<endl;
cout<<"\tpress 2 for Registraion"<<endl;
cout<<"\tpress 3 for Admin Login"<<endl;
cout<<"\tPress 4 to Quit App"<<endl;
cout<<endl;
sleep(1);
cout<<"Enter Number of Your choice : ";
	cin>>choice;
if(choice == 1){
	userlogin();
}else if(choice == 2){
	userreg();
}else if(choice == 3){
	adminlogin();
}else if(choice == 4){
	cout<<"Thankyou Visit us again";
}else{
	cout<<endl<<"\t Invalid Input";
	sleep(2);
	system("cls");
	main();
}
}
// User Ka kaam
//User HomeScreen
void user_home(string username){
	system("cls");
	int c;
	cout<<"\t---------------- Welcome To User Home Screen ----------------"<<endl<<endl;
	sleep(1);
    cout<<"\t Press 1 to view Product Categories"<<endl;
	cout<<"\t press 2 to view Puchase History"<<endl;
	cout<<"\t Press 3 to Logout"<<endl;
 	sleep(1);
	 cout<<endl<<"Enter The Number of Your choice : ";
 	cin>>c;
 	if(c==1){
 	 product_cat(username);
	 }else if(c==2){
	 	show_history(username);
	 }else if(c==3){
	 	intro();
	 }else{
	cout<<"\t Invalid Input"<<endl;
	sleep(2);
	system("cls");
	user_home(username);
	 }
}
// user history
void create_userhistory(string item_name[], double price, int count,string username) {
    ofstream outfile("history.txt", ios::app);
    outfile<<username<<" ";
	for(int i =0;i<count;i++){
		outfile<<item_name[i]<<",";
}
       outfile<<" "<<price<<endl;
}
// viewcategory screen
void product_cat(string username){
	//function declearation
void cat_fashion(string); 
void cat_mobile(string);
void cat_homedec(string);
void cat_electronics(string);
void cat_beauty(string);
 int c;
string cat[6]={"Fashion",
				"Mobiles and accesories",
				"Beauty",
				"Electronics",
				"Home-Decoration",
				"Go back"
				};
	system("cls");
	 cout<<"\t---------------- Choose the Category ----------------"<<endl<<endl;
	 for(int i=0;i<6;i++){
	 	cout<<"\tpress "<<i+1<<" for visiting "<<cat[i]<<" page"<<endl;
	 }
	 cout<<endl;
	 cout<<"Enter Input of your choice: ";
	 cin>>c;
	 if(c==1){
	 	cat_fashion(username);
	 }else if(c==2){
	 	cat_mobile(username);
	 }else if(c==3){
	 	cat_beauty(username);
	 }else if(c==4){
	 	cat_electronics(username);
	 }else if(c==5){
	 	cat_homedec(username);
	 }else if(c==6){
	 user_home(username);
	 }
	 else{
	 	cout<<"Invalid Input";
	 	sleep(2);
	 	product_cat(username);
	 }

}
//fashion category screen
void cat_fashion(string username){
    system("cls");
    string pname, item_name; 
    int count = 0;
    int cnt = 0;
    bool isfound = false;
    double pprice = 0;
    double tprice = 0;   

    cout << "\t---------------- Fashion Page ----------------" << endl << endl;
    ifstream file("fashion.txt");
    while (file >> pname >> pprice) {
        cout << count+1;
        cout << "\tProduct name : " << pname ;
        cout << "\tProduct price : " << pprice << endl;
        count++;
    }

    string item[count]; // moved declaration of item array after count is determined
    cout << endl << "\tInput 0 if you are done shopping" << endl;
    while (true) {
        cout << endl << "\tEnter the name of the item you want to buy : ";
        cin >> item_name;
        ifstream infile("fashion.txt");
        while (infile >> pname >> pprice) {
            if (pname == item_name) {
				isfound = true; 
                tprice += pprice; 
                item[cnt] = item_name; 
                cnt++; 
            }
        }
        if (isfound == true) {
            cout << "Total Amount is : " << tprice << endl;
        } else {
            cout << "Sorry, " << item_name << " not found." << endl;
        }
        if (item_name == "0") {
            create_userhistory(item, tprice, cnt,username); // call function to create user history
            billing(tprice,username);// call function for billling
            break;
        }
    }	   
}
//Mobile category screen
void cat_mobile(string username){
 	system("cls");
    string pname,item_name; 
    int count = 0;
    bool isfound = false;
    double pprice =0;
    double tprice = 0;
    int cnt = 0;
	   cout<<"\t---------------- Mobiles and Accesories Page ----------------"<<endl<<endl;
 	  ifstream file("mobile.txt");
 	  
 	  while(file>>pname>>pprice){
 	  	    cout<<count+1;
 	  	    cout << "\tProduct name : " << pname ;
            cout << "\tProduct price : " << pprice<< endl;
	      count++;
	   }
	    string item[count]; // moved declaration of item array after count is determined
    cout << endl << "\tInput 0 if you are done shopping" << endl;
    cout << endl << "\tEnter the name the Exact same name of product"<<endl;
    while (true) {
        cout << endl << "\tEnter the name of the item you want to buy : ";
        cin >> item_name;
        ifstream infile("mobile.txt");
        while (infile >> pname >> pprice) {
            if (pname == item_name) {
				isfound = true; 
                tprice += pprice; 
                item[cnt] = item_name; 
                cnt++; 
            }
        }
        if (isfound == true) {
            cout << "Total Amount is : " << tprice << endl;
        } else {
            cout << "Sorry, " << item_name << " not found." << endl;
        }
        if (item_name == "0") {
            create_userhistory(item, tprice, cnt,username); // call function to create user history
            billing(tprice,username);// call function for billling
            break;
        }
    }	     
 }
 //beauty category screen
void cat_beauty(string username){
 	system("cls");
    string pname,item_name; 
    int count = 0;
    bool isfound = false;
    double pprice =0;
    double tprice = 0;
    int cnt = 0;
    
	   cout<<"\t---------------- Beauty Page ----------------"<<endl<<endl;
 	  ifstream file("beauty.txt");
 	  while(file>>pname>>pprice){
 	  	    cout<<count+1;
 	  	    cout << "\tProduct name : " << pname ;
            cout << "\tProduct price : " << pprice<< endl;
	      count++;
	   }
	  	  string item[count]; // moved declaration of item array after count is determined
    cout << endl << "\tInput 0 if you are done shopping" << endl;
    cout << endl << "\tEnter the name the Exact same name of product"<<endl;
    while (true) {
        cout << endl << "\tEnter the name of the item you want to buy : ";
        cin >> item_name;
        ifstream infile("beauty.txt");
        while (infile >> pname >> pprice) {
            if (pname == item_name) {
				isfound = true; 
                tprice += pprice; 
                item[cnt] = item_name; 
                cnt++; 
            }
        }
        if (isfound == true) {
            cout << "Total Amount is : " << tprice << endl;
        } else {
            cout << "Sorry, " << item_name << " not found." << endl;
        }
        if (item_name == "0") {
            create_userhistory(item, tprice, cnt,username); // call function to create user history
            billing(tprice,username);// call function for billling
            break;
        }
    }	   
 }
 //electronics category screen
void cat_electronics(string username){
 	system("cls");
 	     string pname,item_name; 
    int count = 0;
    bool isfound = false;
    double pprice =0;
    double tprice = 0;
    int cnt = 0;
	   cout<<"\t---------------- Electronic Page ----------------"<<endl<<endl;
 	  ifstream file("electronics.txt"); 
 	  while(file>>pname>>pprice){
 	  	    cout<<count+1;
 	  	    cout << "\tProduct name : " << pname ;
            cout << "\tProduct price : " << pprice<< endl;
	      count++;
	   }
	      string item[count]; // moved declaration of item array after count is determined
    cout << endl << "\tInput 0 if you are done shopping" << endl;
    cout << endl << "\tEnter the name the Exact same name of product"<<endl;
    while (true) {
        cout << endl << "\tEnter the name of the item you want to buy : ";
        cin >> item_name;
        ifstream infile("electronics.txt");
        while (infile >> pname >> pprice) {
            if (pname == item_name) {
				isfound = true; 
                tprice += pprice; 
                item[cnt] = item_name; 
                cnt++; 
            }
        }
        if (isfound == true) {
            cout << "Total Amount is : " << tprice << endl;
        } else {
            cout << "Sorry, " << item_name << " not found." << endl;
        }
        if (item_name == "0") {
            create_userhistory(item, tprice, cnt,username); // call function to create user history
            billing(tprice,username);// call function for billling
            break;
        }
    }	   
 }
 //home and decor category screen
void cat_homedec(string username){
 	system("cls");
 	     string pname,item_name; 
    int count = 0;
    bool isfound = false;
    double pprice =0;
    double tprice = 0;
    int cnt = 0;
	   cout<<"\t---------------- Home and decoration Page ----------------"<<endl<<endl;
 	  ifstream file("home_dec.txt");
 	  while(file>>pname>>pprice){
 	  	    cout<<count+1;
 	  	    cout << "\tProduct name : " << pname ;
            cout << "\tProduct price : " << pprice<< endl;
	      count++;
	   }
	     string item[count]; // moved declaration of item array after count is determined
    cout << endl << "\tInput 0 if you are done shopping" << endl;
    while (true) {
        cout << endl << "\tEnter the name of the item you want to buy : ";
        cin >> item_name;
        ifstream infile("home_dec.txt");
        while (infile >> pname >> pprice) {
            if (pname == item_name) {
				isfound = true; 
                tprice += pprice; 
                item[cnt] = item_name; 
                cnt++; 
            }
        }
        if (isfound == true) {
            cout << "Total Amount is : " << tprice << endl;
        } else {
            cout << "Sorry, " << item_name << " not found." << endl;
        }
        if (item_name == "0") {
            create_userhistory(item, tprice, cnt,username); // call function to create user history
            billing(tprice,username);// call function for billling
            break;
        }
    }	   
 }
 //show user history
void show_history(string username) {
	system("cls");
    string search_string = username;
    ifstream file("history.txt");
    string line;
    bool isfound = false;
    cout<<"\t---------------- Purchase History ----------------"<<endl<<endl;
    while (getline(file, line)) {
        if (line.find(search_string) != string::npos) {
            cout <<"\t"<< line << endl;
         isfound = true; 
		}
    }
    
    if(isfound != true){
    	cout<<"No Purcahase History found "<<endl;
	}
    
    file.close();
 int c;
 cout<<"Press 0 to go back : ";
 cin>>c;
 if(c==0){
 	user_home(username);
 }

}
//biling 
//tracking number of purchases
int get_num_of_purchases(string username) {
    ifstream infile("history.txt");
    string search_string = username;
	string line;
    int num_of_purchases = 0;
while (getline(infile, line)) {
        if (line.find(search_string) != string::npos) {
         num_of_purchases++;
		}
    }
    infile.close();
    return num_of_purchases;
}

 void billing(double price, string username) {
    system("cls");
    int c;
    string address;
    int num_of_purchases = get_num_of_purchases(username); // a function to get the number of purchases made by the user
    bool is_discount = false;

    cout << "\t---------------- Billing Page ----------------" << endl << endl;
    cout << "Total Payable Amount is " << price << endl;

    if (price == 0) {
        cout << endl << "\tYou did not purchase anything";
        sleep(3);
        product_cat(username);
    }
    
    if (num_of_purchases % 4 == 0 && num_of_purchases > 0) {
        double discount = 0.35 * price;
        price -= discount;
        is_discount = true;
        cout << "Congratulations! You are eligible for a 35% discount on this purchase." << endl;
        cout << "Your discounted price is " << price << endl;
    }

    cout << endl << "\tEnter Your address :";
    cin >> address;
    cout << endl << "\tSelect payment method" << endl;
    cout << "\tpress 1 for cash on delivery" << endl;
    cout << "\tpress 2 for Online payment" << endl;
    cout << endl << "Enter your choice : ";
    cin >> c;

    if (c == 1) {
        cout << "Thanks for purchase! Your package will be delivered to you as soon as possible." << endl;
        sleep(3);
        product_cat(username);
    }
    else if (c == 2) {
        unsigned short cvv;
        cout << "\tEnter the CVV number : ";
        cin >> cvv;
        cout << "\tPaying";
        sleep(1);
        cout << ".";
        sleep(1);
        cout << ".";
        sleep(1);
        cout << "." << endl;
        cout << "Thanks for purchase! Your package will be delivered to you as soon as possible." << endl;
        sleep(3);
        product_cat(username);
    }
}

// User role Auth
void userlogin(){
    string username,password,un,pw;
    bool isfound = false;
     system("cls");
    cout<<"\t---------------- Welcome To User Login Page ----------------"<<endl<<endl;
    cout<<"\tEnter Your username : ";
    cin>>username;
    cout<<"\tEnter Your Password : ";
    cin>>password;
    ifstream file("userauthrecords.txt");
    while(file>>un>>pw){ 
        if(un == username && pw == password){
            isfound = true;
            break;
        }
    }
    file.close();

    if(isfound){
        cout<<"Successfully Login";
        sleep(2);
        user_home(username); 
    }else{
       int c;
        cout<<endl<<"\tWrong Username Or Password try Again"<<endl;
        sleep(1);
		cout<<endl<<"\tWant to Redirect Welcome Screen press 1"<<endl;
		cout<<"\tWant to Redirect User Registertation Screen press 2"<<endl;
		sleep(1);
		cout<<endl<<"Enter Number of Your choice : ";
		cin>>c;	
		if(c==1){
			main();
		}else if(c==2){
			userreg();
		}else{
			cout<<"\tInvalid Input";
			sleep(2);
			system("cls");
			main();
		}
}
}
void userreg(){
	string username,password,un,pw;
	int c;
	system("cls");
	cout<<"\t---------------- Welcome To User Registeration Page ----------------"<<endl<<endl;
	cout<<"\tEnter the username : ";
	cin>>username;
	cout<<"\tEnter the Password : ";
	cin>>password;
	ofstream file("userauthrecords.txt",ios::app);
	file<<username<<" "<<password<<endl;
	cout<<endl;
	cout<<"\tRegisteration Sucessfull! Now u can Login and Enjoy our services";
	cout<<endl<<endl<<"Press 1 for Login Screen : ";
	cin>>c;
	if(c==1){
		userlogin();
	}else{
		cout<<"Invalid Input";
		sleep(2);
		main();
}
}
//Admin ka Kaam
// admin homescreen
void admin_home(){
	system("cls");
	int c;
	cout<<"\t---------------- Welcome To Admin Home Screen ----------------"<<endl<<endl;
	sleep(1);
    cout<<"\t Press 1 to Add Product"<<endl;
	cout<<"\t press 2 to Create New Admin"<<endl;
	cout<<"\t Press 3 to Logout"<<endl;
	sleep(1);
	cout<<endl<<"Enter The Number of Your choice : ";
 	cin>>c;
 	if(c==1){
 	add_product();
	 }else if(c==2){
	 	adminreg();
	 }else if(c==3){
	 	intro();
	 }else{
	cout<<"\t Invalid Input"<<endl;
	sleep(2);
	system("cls");
	admin_home();
	 }
}
// Admin role Auth
void adminreg(){
	string username,password,un,pw;
	system("cls");
	 cout<<"\t---------------- Welcome To Admin Login Page ----------------"<<endl<<endl;
	cout<<"\tEnter the username : ";
	cin>>username;
	cout<<"\tEnter the Password : ";
	cin>>password;
	ofstream file("adminauthrecords.txt",ios::app);
	file<<username<<" "<<password<<endl;
	cout<<endl<<"\tRegistration is sucessfully";
	sleep(2);
	system("cls");
		admin_home();
}
void adminlogin(){
	bool isfound =false;
	string username,password,un,pw;
	system("cls");
	 cout<<"\t---------------- Welcome To Admin Registration Page ----------------"<<endl<<endl;
	cout<<"\tEnter Your username : ";
	cin>>username;
	cout<<"\tEnter Your Password : ";
	cin>>password;	
	ifstream file("adminauthrecords.txt");
 while(file>>un>>pw){ 
        if(un == username && pw == password){
            isfound = true;
            break;
        }
    }
    file.close();

    if(isfound){
        cout<<endl<<"Successfully Login";
        sleep(2);
        admin_home();
        
    }else{
        cout<<endl<<"\tWrong Username Or Password try Again"<<endl;
	sleep(2);
	main();
}
}
//add products in cat
void add_product(){
//def suporting func
void fashion();
void beauty();
void electronics();
void home_dec();
void mobile_acces();
	int c;
string cat[6]={"Fashion",
				"Mobiles and accesories",
				"Beauty",
				"Electronics",
				"Home-Decoration",
				"Go-Back"
				};
	system("cls");
	 cout<<"\t---------------- Choose the Category ----------------"<<endl<<endl;
	 for(int i=0;i<6;i++){
	 	cout<<"\tpress "<<i+1<<" for add "<<cat[i]<<" product"<<endl;
	 }
	 cout<<endl;
	 cout<<"Enter Input of your choice: ";
	 cin>>c;
	 if(c==1){
	 fashion();
	 }else if(c==2){
	 	mobile_acces();
	 }else if(c==3){
	 	beauty();
	 }else if(c==4){
	 	electronics();
	 }else if(c==5){
	 home_dec();
	 }else if(c==6){
	 add_product();
	 }else{
	 	cout<<"Invalid Input";
	 	sleep(2);
	 	admin_home();
	 }
}
//supporting func for adding product
void fashion(){
    system("cls");
   ofstream outfile("fashion.txt", ios::app);
    int num;
	string name;
    double price;
     cout<<"\t---------------- Add Product in Fashion Cataegory ----------------"<<endl<<endl;
    
    cout<<"\tEnter how many Product you want to Enter : ";
    cin>>num;
     cout<<endl<<"Make sure to Enter Product name Without Spacing"<<endl;
	for(int i=0;i<num;i++){
		cout<<endl<<"Number of Product "<<i+1<<endl;
	cout << "\tEnter product name: ";
    cin >> name;
    cout << "\tEnter product price: ";
    cin >> price;	
    outfile <<name << " " << price<<endl;
     cout<<endl << "Product added to Successfully" << endl;
	}
	sleep(2);
	add_product();
}
void mobile_acces(){
    system("cls");
   ofstream outfile("mobile.txt", ios::app);
    int num;
	string name;
    double price;
     cout<<"\t---------------- Add Product in Mobiles and accesories Cataegory ----------------"<<endl<<endl;
    cout<<"\tEnter how many Product you want to Enter : ";
    cin>>num;
       cout<<endl<<"Make sure to Enter Product name Without Spacing"<<endl;
	for(int i=0;i<num;i++){
		cout<<endl<<"Number of Product "<<i+1<<endl;
	cout << "\tEnter product name: ";
    cin >> name;
    cout << "\tEnter product price: ";
    cin >> price;	
    outfile <<name << " " << price<<endl;
     cout<<endl << "Product added to Successfully" << endl;
	}
	sleep(2);
	add_product();
}
void beauty(){
    system("cls");
   ofstream outfile("beauty.txt", ios::app);
    int num;
	string name;
    double price;
     cout<<"\t---------------- Add Product in Beauty Cataegory ----------------"<<endl<<endl;
    cout<<"\tEnter how many Product you want to Enter : ";
    cin>>num;
	   cout<<endl<<"Make sure to Enter Product name Without Spacing"<<endl;
	for(int i=0;i<num;i++){
		cout<<endl<<"Number of Product "<<i+1<<endl;
	cout << "\tEnter product name: ";
    cin >> name;
    cout << "\tEnter product price: ";
    cin >> price;	
    outfile <<name << " " << price<<endl;
     cout<<endl << "Product added to Successfully" << endl;
	}
	sleep(2);
	add_product();
}
void electronics(){
    system("cls");
   ofstream outfile("electronics.txt", ios::app);
    int num;
	string name;
    double price;
     cout<<"\t---------------- Add Product in Electronics Cataegory ----------------"<<endl<<endl;
    cout<<"\tEnter how many Product you want to Enter : ";
    cin>>num;
   cout<<endl<<"Make sure to Enter Product name Without Spacing"<<endl;
	for(int i=0;i<num;i++){
		cout<<endl<<"Number of Product "<<i+1<<endl;
	cout << "\tEnter product name: ";
    cin >> name;
    cout << "\tEnter product price: ";
    cin >> price;	
    outfile <<name << " " << price<<endl;
     cout<<endl << "Product added to Successfully" << endl;
	}
	sleep(2);
	add_product();
}
void home_dec(){
    system("cls");
   ofstream outfile("home_dec.txt", ios::app);
    int num;
	string name;
    double price;
     cout<<"\t---------------- Add Product in Home and Decoration Cataegory ----------------"<<endl<<endl;
    cout<<"\tEnter how many Product you want to Enter : ";
    cin>>num;
	   cout<<endl<<"Make sure to Enter Product name Without Spacing"<<endl;
	for(int i=0;i<num;i++){
		cout<<endl<<"Number of Product "<<i+1<<endl;
	cout << "\tEnter product name: ";
    cin >> name;
    cout << "\tEnter product price: ";
    cin >> price;	
    outfile <<name << " " << price<<endl;
    cout <<endl<< "Product added to Successfully" << endl;
	}
	sleep(2);
	add_product();
}
