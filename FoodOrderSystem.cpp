//**********************************FOOD ORDERING SYSTEM****************************

#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
using namespace std;

//*********************************************************************************************************
//                                        CLASSES USED IN PROJECT
//*********************************************************************************************************

class Restaurant
{
private:
    char rest_name[20]="FastFoodCenter";
    char rest_add[30]="MotaBazar,Vallabh Vidhyanagar";
    char rest_mob[10]="12345";
public:
    void rdisplay()         // function to display the restaurant details
    {
        cout<<"\tRestaurant Name:"<<rest_name<<endl;
        cout<<"\t\tRestaurant Address:"<<rest_add<<endl;
        cout<<"\t\t\tRestaurant Contact_No:"<<rest_mob<<endl;
    }
    char *getr()       //function to return restaurant name
    {
        return rest_name;
    }
};
class Bill;
class Customer
{
private:
    char cust_uname[20];
    char cust_pass[10];
protected:
    char cust_name[20];
    char cust_add[30];
    char cust_mob[10];
public:
    void cust_details()
    {
        cout<<"\nPlease,Enter User Name:";
        cin>>cust_uname;
        cout<<"\n\tPlease,Enter Password:";
        cin>>cust_pass;
        cout<<"\n\t\tPlease,Enter Your Name:";
        cin>>cust_name;
        cout<<"\n\t\t\tPlease,Enter Your Delivery Address:";
        cin>>cust_add;
        cout<<"\n\t\t\t\tPlease,Enter Your Mobile Number:";
        cin>>cust_mob;
    }
    friend void copydetails(Bill&,Customer&);       // friend function to copy the details of customer into bill
    char *getu()          //function to return customer username
    {
        return cust_uname;
    }
    char *getp()         //function to return customer password

    {
        return cust_pass;
    }
    void copy_into(char *name,char *mob)        //function to copy customer name and mobile number
    {
        strcpy(name,cust_name);
        strcpy(mob,cust_mob);
    }
};
class Food
{
protected:
    int quantity=0,amount=0;
    char item_name[30];
public:
    void Pizza();          //function to show the choices for pizza
    void Burger();         //function to show the choices for burger
    void Sandwich();       //function to show the choices for sandwich
    void Roll();           //function to show the choices for roll
    void Biryani();        //function to show the choices for biryani
};
class Bill:public Customer,public Food       // class Bill is inheriting two classes namely Customer and Food
{
public:
    void storedata();             //function to store the details of orders into binary
    int showbill(const char *,const char *);           //function to display the bill in tabular format and return the value 0 if there is no order
    friend void copydetails(Bill&,Customer&);
    void cancelorder(const char *,const char *);        //function to cancel the order
    void display()              //function to display items,quantity and corresponding amount
    {
        cout<<"\t";
        cout.width(30);
        cout.setf(ios::left);
        cout<<item_name;
        cout.width(10);
        cout.unsetf(ios::left);
        cout<<quantity;
        cout.width(10);
        cout<<amount;
        cout<<endl;
    }
};

//*********************************************************************************************************
//                                        FUNCTION DEFINATIONS
//*********************************************************************************************************

void Food::Pizza()
{
    char pizza1[30]="Chicken Fazita" ,pizza2[30]="Chicken Bar BQ" ,pizza3[30]="Peri Peri" ,pizza4[30]="Creamy Max";
    int pchoice;
    pizza:
    cout<<"\n1) "<<pizza1<<"\n";
    cout<<"2) "<<pizza2<<"\n";
    cout<<"3) "<<pizza3<<"\n";
    cout<<"4) "<<pizza4<<"\n";
    cout<<"\nPlease Enter which Flavour would you like to have?:";
    cin>>pchoice;
    try
    {
        if(pchoice<1 || pchoice>4)
            throw 1;
    }
    catch(int)
    {
        cout<<"\nEnter The Correct Choice\n";
        goto pizza;
    }
    if(pchoice==1)
        strcpy(item_name,pizza1);
    if(pchoice==2)
        strcpy(item_name,pizza2);
    if(pchoice==3)
        strcpy(item_name,pizza3);
    if(pchoice==4)
        strcpy(item_name,pizza4);
    if(pchoice>=1 && pchoice<=4)
    {
        sizes:
        cout<<"\n1) Small Rs.250\n"<<"2) Regular Rs.500\n"<<"3) Large Rs.900\n";
        cout<<"\nChoose Size Please:";
        cin>>pchoice;
        try
        {
            if(pchoice<1 || pchoice>3)
                throw 1;
        }
        catch(int)
        {
            cout<<"\nEnter The Correct Choice\n";
            goto sizes;
        }
        if(pchoice>=1 && pchoice<=3)
        cout<<"\nPlease Enter Quantity: ";
        cin>>quantity;
        switch(pchoice)
        {
            case 1:
                amount = 250*quantity;
                break;
            case 2:
                amount = 500*quantity;
                break;
            case 3:
                amount = 900*quantity;
                break;
        }
    }
}
void Food::Burger()
{
    char bur1[30]="Zinger Burger",bur2[30]="Chicken Burger",bur3[30]="Beef Burger";
    int bchoice;
    burger:
    cout<<"\n1 "<<bur1<<" Rs.180"<<"\n";
    cout<<"2 "<<bur2<<" Rs.150"<<"\n";
    cout<<"3 "<<bur3<<" Rs.160"<<"\n";
    cout<<"\nPlease Enter which Burger you would like to have?: ";
    cin>>bchoice;
    try
    {
        if(bchoice<1 || bchoice>3)
            throw 1;
    }
    catch(int)
    {
        cout<<"\nEnter The Correct Choice\n";
        goto burger;
    }
    if(bchoice==1)
        strcpy(item_name,bur1);
    if(bchoice==2)
        strcpy(item_name,bur2);
    if(bchoice==3)
        strcpy(item_name,bur3);
    if(bchoice>=1 && bchoice<=3)
    {
        cout<<"\nPlease Enter Quantity: ";
        cin>>quantity;
        switch(bchoice)
        {
            case 1:
                amount = 180*quantity;
                break;
			case 2:
			    amount = 150*quantity;
                break;
			case 3:
			    amount = 160*quantity;
                break;
        }
    }
}
void Food::Sandwich()
{
    char sand1[30]="Club Sandwich", sand2[30]="Chicken Crispy Sandwich", sand3[30]="Extream Veg Sandwich";
    int schoice;
    sandwich:
    cout<<"\n1  "<<sand1<<" Rs.240"<<"\n";
    cout<<"2  "<<sand2<<" Rs.160"<<"\n";
    cout<<"3  "<<sand3<<" Rs.100"<<"\n";
    cout<<"\nPlease Enter which Sandwich you would like to have?:";
    cin>>schoice;
    try
    {
        if(schoice<1 || schoice>3)
            throw 1;
    }
    catch(int)
    {
        cout<<"\nEnter The Correct Choice\n";
        goto sandwich;
    }
    if(schoice==1)
        strcpy(item_name,sand1);
    if(schoice==2)
        strcpy(item_name,sand2);
    if(schoice==3)
        strcpy(item_name,sand3);
    if(schoice>=1 && schoice<=3)
    {
        cout<<"\nPlease Enter Quantity: ";
        cin>>quantity;
        switch(schoice)
        {
			case 1:
			    amount = 240*quantity;
                break;
			case 2:
			    amount = 160*quantity;
                break;
			case 3:
			    amount = 100*quantity;
                break;
        }
    }
}
void Food::Roll()
{
    char roll1[30]="Chicken Chatni Roll", roll2[30]="Chicken Mayo Roll", roll3[30]="Veg Roll With Fries";
    int rchoice;
    roll:
    cout<<"\n1 "<<roll1<<" Rs.150"<<"\n";
    cout<<"2 "<<roll2<<" Rs.100"<<"\n";
    cout<<"3 "<<roll3<<" Rs.120"<<"\n";
    cout<<"\nPlease Enter which you would like to have?: ";
    cin>>rchoice;
    try
    {
        if(rchoice<1 || rchoice>3)
            throw 1;
    }
    catch(int)
    {
        cout<<"\nEnter The Correct Choice\n";
        goto roll;
    }
    if(rchoice==1)
        strcpy(item_name,roll1);
    if(rchoice==2)
        strcpy(item_name,roll2);
    if(rchoice==3)
        strcpy(item_name,roll3);
    if(rchoice>=1 && rchoice<=3)
    {
        cout<<"\nHow Much Rolls Do you want: ";
        cin>>quantity;
        switch(rchoice)
        {
            case 1:
                amount = 150*quantity;
                break;
			case 2:
			    amount = 100*quantity;
                break;
			case 3:
			    amount = 120*quantity;
                break;
        }
    }
}
void Food::Biryani()
{
    char bir1[30]="Chicken Biryani", bir2[30]="Prawn Biryani", bir3[30]="Beef Biryani";
    int bchoice;
    biryani:
    cout<<"\n1 "<<bir1<<" Rs.160"<<"\n";
    cout<<"2 "<<bir2<<" Rs.220"<<"\n";
    cout<<"3 "<<bir3<<" Rs.140"<<"\n";
    cout<<"\nPlease Enter which Biryani you would like to have?:";
    cin>>bchoice;
    try
    {
        if(bchoice<1 || bchoice>3)
            throw 1;
    }
    catch(int)
    {
        cout<<"\nEnter The Correct Choice\n";
        goto biryani;
    }
    if(bchoice==1)
        strcpy(item_name,bir1);
    if(bchoice==2)
        strcpy(item_name,bir2);
    if(bchoice==3)
        strcpy(item_name,bir3);
    if(bchoice>=1 && bchoice<=3)
    {
        cout<<"\nPlease Enter Quantity: ";
        cin>>quantity;
        switch(bchoice)
        {
            case 1:
                amount = 160*quantity;
                break;
			case 2:
			    amount = 220*quantity;
                break;
			case 3:
			    amount = 140*quantity;
                break;
        }
    }
}
void copydetails(Bill &B,Customer &C)
{
    strcpy(B.cust_name,C.cust_name);
    strcpy(B.cust_add,C.cust_add);
    strcpy(B.cust_mob,C.cust_mob);
}
void Bill::storedata()
{
    fstream file;
    file.open("FoodManage.txt",ios::app|ios::binary);
    file.write((char *)this,sizeof(*this));
    file.close();
}
int Bill::showbill(const char *t,const char *m)
{
    ifstream fin;
    char name[20]={0};
    char mob[10]={0};
    int total_amount=0,check=0,c=0,d=0;
    fin.open("FoodManage.txt",ios::in|ios::binary);
    fin.seekg(-(sizeof(*this)),ios::end);     // to set the get pointer at the last object
    fin.read((char *)this,sizeof(*this));
    while(fin)
    {
        if(!strcmp(cust_name,t) && !strcmp(cust_mob,m))
        {
            if(strcmp(cust_name,name) && strcmp(cust_mob,mob))
            {
                c=fin.tellg();  // to store the value of get pointer when matching object will come for the first time
                cout<<endl<<"Your Bill:"<<endl;
                cout<<"\n\tCustomer Name:"<<cust_name<<endl;
                cout<<"\tCustomer Address:"<<cust_add<<endl;
                cout<<"\tCustomer Mob_No:"<<cust_mob<<endl;
                cout<<endl<<"\t";
                cout.width(30);
                cout.setf(ios::left);
                cout<<"Item Name";
                cout.width(10);
                cout.unsetf(ios::left);
                cout<<"Quantity";
                cout.width(10);
                cout<<"Amount";
                cout<<"\n\n";
                strcpy(name,cust_name);
                strcpy(mob,cust_mob);
            }
            check++;
        }
        if(check!=0)
        {
            if(!strcmp(cust_name,t) && !strcmp(cust_mob,m))
            {
                total_amount+=amount;
                d=fin.tellg();   // to store the value of get pointer when matching object will come for the last time
            }
            else
                break;
        }
        fin.seekg(-(2*(sizeof(*this))),ios::cur);   // to set the get pointer two object backward from current position
        fin.read((char *)this,sizeof(*this));
    }
    fin.clear();
    if(check!=0)
    {
        fin.seekg(d-sizeof(*this));   // to set the pointer at position from where we have to read
        while(fin.tellg()<c)
        {
            fin.read((char *)this,sizeof(*this));
            display();
        }
        cout.width(58);
        cout<<"-----";
        cout<<endl;
        cout.width(53);
        cout<<"Total Amount:";
        cout.fill('0');
        cout.width(5);
        cout<<total_amount;
        cout.fill(' ');
    }
    fin.close();
    return check;
}
void Bill::cancelorder(const char *t,const char *m)
{
    ifstream fin;
    ofstream fout;
    char name[20]={0};
    char mob[10]={0};
    int check=0,c=0,d=0;
    fin.open("FoodManage.txt",ios::in|ios::binary);
    fout.open("temp.txt",ios::out|ios::binary);
    fin.seekg(-(sizeof(*this)),ios::end);
    fin.read((char *)this,sizeof(*this));
    while(fin)
    {
        if(!strcmp(cust_name,t) && !strcmp(cust_mob,m))
        {
            if(strcmp(cust_name,name) && strcmp(cust_mob,mob))
            {
                c=fin.tellg();
                strcpy(name,cust_name);
                strcpy(mob,cust_mob);
            }
            check++;
        }
        if(check!=0)
        {
            if(!strcmp(cust_name,t) && !strcmp(cust_mob,m))
                d=fin.tellg();
            else
                break;
        }
        fin.seekg(-(2*(sizeof(*this))),ios::cur);
        fin.read((char *)this,sizeof(*this));
    }
    fin.clear();
    fin.seekg(0);
    fin.read((char *)this,sizeof(*this));
    while(!fin.eof())
    {
        if(fin.tellg()<d || fin.tellg()>c)
        {
            fout.write((char *)this,sizeof(*this));
        }
        fin.read((char *)this,sizeof(*this));
    }
    fin.close();
    fout.close();
    remove("FoodManage.txt");
    rename("temp.txt","FoodManage.txt");
}
int menu()          // function to display the food menu
{
    int choice=0;
    choices:
    cout<<"\n\t\t\t\t--------Menu--------\n\n";
	cout<<"1) Pizzas\n";
	cout<<"2) Burgers\n";
	cout<<"3) Sandwich\n";
	cout<<"4) Rolls\n";
	cout<<"5) Biryani\n";
	cout<<"\nPlease Enter your Choice: ";
	cin>>choice;
	try
    {
        if(choice<1 || choice>5)
            throw 1;
    }
    catch(int)
    {
        cout<<"\nEnter The Correct Choice\n";
        goto choices;
    }
	return choice;
}
int main()
{
    Restaurant R;
    char choice;
    int n;
    cout<<"\t\t\t***************Welcome To The "<<R.getr()<<"***************\n";
    beginning:
    system("cls");
    cout<<"\n\nPress 1 Restaurant Details\n";
    cout<<"Press 2 For Registration If You Are New Customer\n";
    cout<<"Press 3 If You Are Old Customer\n";
    cout<<"Press 4 To Close This Application\n";
    cin>>n;
    try
    {
        if(n<1 || n>4)
            throw 1;
    }
    catch(int)
    {
        cout<<"\nEnter The Correct Choice\n";
        goto beginning;
    }
    if(n==1)
    {
        R.rdisplay();
        cout<<"\nPress Any Key To Go Home";
        getch();
        goto beginning;
    }
    if(n==2)
    {
        registration:
        system("cls");
        Customer C;
        fstream fout;
        fout.open("CustomerData.txt",ios::app|ios::binary);
        C.cust_details();
        fout.write((char *)&C,sizeof(C));
        fout.close();
        cout<<"\nYou Have Successfully Registered\n";
        cout<<"\nPress Any Key To Go Home";
        getch();
        goto beginning;
    }
    if(n==3)
    {
        order:
        system("cls");
        Customer C;
        Bill B;
        int check=0;
        char name[20],mob[10],uname[20],pass[10];
        ifstream fin;
        fin.open("CustomerData.txt",ios::in|ios::binary);
        cout<<"\nEnter Your User Name:";
        cin>>uname;
        cout<<"Enter Your Password:";
        cin>>pass;
        fin.read((char *)&C,sizeof(C));
        while(!fin.eof())
        {
            if(!strcmp(uname,C.getu()) && !strcmp(pass,C.getp()))
            {
                copydetails(B,C);
                C.copy_into(name,mob);
                check++;
            }
            fin.read((char *)&C,sizeof(C));
        }
        if(check==0)
        {
            cout<<"Oops,It's Seems You Have Not Done The Registration Yet,Would You Like To Do? Y/N : ";
            cin>>choice;
            if(choice=='Y' || choice=='y')
            {
                goto registration;
            }
            else
            {
                goto beginning;
            }
        }
        start:
        system("cls");
        cout<<"\nPress 1 For Ordering The Food\n";
        cout<<"Press 2 To Cancel The Order\n";
        cout<<"Press 3 To View Your Previous Bill\n";
        cout<<"Press 4 To Close This Application\n";
        cin>>n;
        try
        {
            if(n<1 || n>4)
                throw 1;
        }
        catch(int)
        {
            cout<<"\nEnter The Correct Choice\n";
            goto start;
        }
        if(n==1)
        {
            menu:
            system("cls");
            switch(menu())
            {
                case 1:
                    B.Pizza();
                    B.storedata();
                    break;
                case 2:
                    B.Burger();
                    B.storedata();
                    break;
                case 3:
                    B.Sandwich();
                    B.storedata();
                    break;
                case 4:
                    B.Roll();
                    B.storedata();
                    break;
                case 5:
                    B.Biryani();
                    B.storedata();
                    break;
                default:
                    cout<<"Please Select Right Option: \n";
                    cout<<"Would You Like To Go To Food Menu Again? Y / N: ";
                    cin>>choice;
                    if(choice=='Y' || choice=='y')
                    {
                        goto menu;
                    }
                    else
                    {
                        goto start;
                    }
            }
            cout<<"\nWould you like to order anything else? Y / N: ";
            cin>>choice;
            if(choice=='Y' || choice=='y')
            {
                goto menu;
            }
            B.showbill(name,mob);
            cout<<"\nYour Order Will be delivered in 40 Minutes"<<endl;
            cout<<"Thank you For Ordering From FastFoodCenter\n\n";
            cout<<"\nPress Any Key To Go To Main Menu\n";
            getch();
            goto start;
        }
        if(n==2)
        {
            int x=0;
            x=B.showbill(name,mob);
            if(x==0)
                cout<<"\nSorry,There Is No Order From You\n";
            if(x!=0)
            {
                cout<<"\nAre You Sure To Cancel Your Order? Y/N :";
                cin>>choice;
                if(choice=='Y' || choice=='y')
                {
                    B.cancelorder(name,mob);
                    cout<<"\nYour Order Has Been Successfully Cancelled "<<endl;
                }
            }
            cout<<"\nPress Any Key To Exit\n";
            getch();
            exit(0);
        }
        if(n==3)
        {
            int y=0;
            y=B.showbill(name,mob);
            if(y==0)
                cout<<"\nSorry,There Is No Order From You\n";
            cout<<"\nPress Any Key To Exit\n";
            getch();
            exit(0);
        }
        if(n==4)
            exit(0);
    }
    if(n==4)
        exit(0);
    return 0;
}
