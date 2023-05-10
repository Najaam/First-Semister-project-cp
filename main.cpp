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
void user_home();
void admin_home();
void product_cat();
void add_product();

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
	intro();
}
}
// User Ka kaam
//User HomeScreen
void user_home(){
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
 	 product_cat();
	 }else if(c==2){
	 	cout<<"Purchase history ka function nhi baana abhi tak";
	 }else if(c==3){
	 	intro();
	 }else{
	cout<<"\t Invalid Input"<<endl;
	sleep(2);
	system("cls");
	user_home();
	 }
}
// viewcategory screen
void product_cat(){
	//function declearation
void cat_fashion(); 
void cat_mobile();
void cat_homedec();
void cat_electronics();
void cat_beauty();
	int c;
string cat[5]={"Fashion",
				"Mobiles and accesories",
				"Beauty",
				"Electronics",
				"Home-Decoration"};
	system("cls");
	 cout<<"\t---------------- Choose the Category ----------------"<<endl<<endl;
	 for(int i=0;i<5;i++){
	 	cout<<"\tpress "<<i+1<<" for visiting "<<cat[i]<<" page"<<endl;
	 }
	 cout<<endl;
	 cout<<"Enter Input of your choice: ";
	 cin>>c;
	 if(c==1){
	 	cat_fashion();
	 }else if(c==2){
	 	cat_mobile();
	 }else if(c==3){
	 	cat_beauty();
	 }else if(c==4){
	 	cat_electronics();
	 }else if(c==5){
	 	cat_homedec();
	 }else{
	 	cout<<"Invalid Input";
	 	sleep(2);
	 	product_cat();
	 }

}
//fashion category screen
void cat_fashion(){
 	system("cls");
 	  string pname,pprice;
	   cout<<"\t---------------- Fashion Page ----------------"<<endl<<endl;
 	  ifstream file("fashion.txt");
 	  int count =0;
 	  while(file>>pname>>pprice){
 	  	    cout<<count+1;
 	  	    cout << "\tProduct name : " << pname ;
            cout << "\tProduct price : " << pprice<< endl;
	      count++;
	   }
 }
//Mobile category screen
void cat_mobile(){
 	system("cls");
 	  string pname,pprice;
	   cout<<"\t---------------- Mobiles and Accesories Page ----------------"<<endl<<endl;
 	  ifstream file("mobile.txt");
 	  int count =0;
 	  while(file>>pname>>pprice){
 	  	    cout<<count+1;
 	  	    cout << "\tProduct name : " << pname ;
            cout << "\tProduct price : " << pprice<< endl;
	      count++;
	   }
 }
 //beauty category screen
void cat_beauty(){
 	system("cls");
 	  string pname,pprice;
	   cout<<"\t---------------- beauty Page ----------------"<<endl<<endl;
 	  ifstream file("beauty.txt");
 	  int count =0;
 	  while(file>>pname>>pprice){
 	  	    cout<<count+1;
 	  	    cout << "\tProduct name : " << pname ;
            cout << "\tProduct price : " << pprice<< endl;
	      count++;
	   }
 }
 //electronics category screen
void cat_electronics(){
 	system("cls");
 	  string pname,pprice;
	   cout<<"\t---------------- Fashion Page ----------------"<<endl<<endl;
 	  ifstream file("electronics.txt");
 	  int count =0;
 	  while(file>>pname>>pprice){
 	  	    cout<<count+1;
 	  	    cout << "\tProduct name : " << pname ;
            cout << "\tProduct price : " << pprice<< endl;
	      count++;
	   }
 }
 //home and decor category screen
void cat_homedec(){
 	system("cls");
 	  string pname,pprice;
	   cout<<"\t---------------- Fashion Page ----------------"<<endl<<endl;
 	  ifstream file("home_dec.txt");
 	  int count =0;
 	  while(file>>pname>>pprice){
 	  	    cout<<count+1;
 	  	    cout << "\tProduct name : " << pname ;
            cout << "\tProduct price : " << pprice<< endl;
	      count++;
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
        user_home(); 
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
	user_home();
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
//	def suporting func
void fashion();
void beauty();
void electronics();
void home_dec();
void mobile_acces();
	int c;
string cat[5]={"Fashion",
				"Mobiles and accesories",
				"Beauty",
				"Electronics",
				"Home-Decoration"};
	system("cls");
	 cout<<"\t---------------- Choose the Category ----------------"<<endl<<endl;
	 for(int i=0;i<5;i++){
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
	 }else{
	 	cout<<"Invalid Input";
	 	sleep(2);
	 	product_cat();
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
	for(int i=0;i<num;i++){
		cout<<"Number of Product "<<i+1<<endl;
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
	for(int i=0;i<num;i++){
		cout<<"Number of Product "<<i+1<<endl;
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
	for(int i=0;i<num;i++){
		cout<<"Number of Product "<<i+1<<endl;
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
	for(int i=0;i<num;i++){
		cout<<"Number of Product "<<i+1<<endl;
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
	for(int i=0;i<num;i++){
		cout<<"Number of Product "<<i+1<<endl;
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


