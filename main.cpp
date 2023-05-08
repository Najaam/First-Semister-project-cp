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
sleep(1);
cout<<"\tpress 2 for Registraion"<<endl;
sleep(1);
cout<<"\tpress 3 for Admin Login"<<endl;
sleep(1);

cout<<"\tPress 4 to Quit App"<<endl;
sleep(1);
cout<<endl;
cout<<"\tEnter Number of Your choice : ";
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
    sleep(1);
	cout<<"\t press 2 to view Puchase History"<<endl;
    sleep(1);
	cout<<"\t Press 3 to Logout"<<endl;
 	sleep(1);
	 cout<<endl<<"Enter The Number of Your choice : ";
 	cin>>c;
 	if(c==1){
 		cout<<"Product category ka function nhi baana abhi tak";
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
// User role Auth
void userlogin(){
    string username,password,un,pw;
    bool isfound = false;
    system("cls");
    cout<<"Enter Your username : ";
    cin>>username;
    cout<<"Enter Your Password : ";
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
		cout<<endl<<"\tWant to Redirect Welcome Screen press 1"<<endl;
		cout<<"\tWant to Redirect User Registertation Screen press 2"<<endl;
		cout<<endl<<"\tEnter Number of Your choice : ";
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
	sleep(3);
	system("cls");
		main();
}
//Admin ka Kaam
void admin_home(){
	int c;
	cout<<"\t---------------- Welcome To Admin Home Screen ----------------"<<endl<<endl;
	sleep(1);
    cout<<"\t Press 1 to Add Product"<<endl;
    sleep(1);
	cout<<"\t press 2 to Create New Admin"<<endl;
    sleep(1);
	cout<<"\t Press 3 to Logout"<<endl;
 	sleep(1);
	 cout<<endl<<"Enter The Number of Your choice : ";
 	cin>>c;
 	if(c==1){
 		cout<<"Add Product ka function nhi baana abhi tak";
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
	cout<<"Enter the username : ";
	cin>>username;
	cout<<"Enter the Password : ";
	cin>>password;
	ofstream file("adminauthrecords.txt",ios::app);
	file<<username<<" "<<password<<endl;
	cout<<endl<<"/tRegistration is sucessfull";
	sleep(2);
	system("cls");
		main();
}
void adminlogin(){
	bool isfound =false;
	string username,password,un,pw;
	system("cls");
	cout<<"Enter Your username : ";
	cin>>username;
	cout<<"Enter Your Password : ";
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
        cout<<"Successfully Login";
        sleep(2);
        admin_home();
        
    }else{
        cout<<endl<<"\tWrong Username Or Password try Again"<<endl;
	sleep(2);
	main();
	

}
}

