// Q1
// Bazil-Uddin-Khan 24k-0559
#include<iostream>
using namespace std;

class Account
{
    protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;
    double rate = 2.4;
    int Time = 2;

    public:
    Account()
    {
            accountNumber = 0;
            balance = 0.0;
            accountHolderName = " ";
            accountType = " ";

    }

    Account(int accountnum,double Balance, string accountName,string Type) : accountNumber(accountnum), balance(Balance), accountHolderName(accountName), accountType(Type)
    {}

    virtual void deposit(double amount)
    {
        balance  = balance + amount;
        cout << " Succesfully Deposited " << endl;
        

    }

    virtual void withdraw(double amount)
    {
        if(balance > amount )
        {
             balance = balance - amount;
        }
        else
        {
            cout << " Sorry cant proceed with withdraw reqeust " << endl;
        }
       
    }

    virtual void CalculateInterest()
    {
        double interestrate = (balance * rate * Time)/100;
        rate = interestrate;
        cout << " Interest Earned  is " << interestrate << endl;

    }

    virtual void printStatement()
    {
        cout << " Rate is " << rate << endl;
        cout << " Account number  is " << accountNumber << endl;
        cout << " account holder name  is " << accountHolderName << endl;
        cout << " Balance is " << balance << endl;
        cout << " Accountt ype  is " << accountType << endl;

    }

    virtual void GetAccountINfo()
    {
        cout << " Rate is " << rate << endl;
        cout << " Account number  is " << accountNumber << endl;
        cout << " account holder name  is " << accountHolderName << endl;
        cout << " Balance is " << balance << endl;
        cout << " Accountt ype  is " << accountType << endl;

    }


};

class SavingsAccount : public Account
{
    protected:
    double interestRate;
    double minimumBalane;

    public:
    SavingsAccount()
    {
        interestRate  = 0.0;
        minimumBalane = 0.0;
    }

    SavingsAccount(int accountnum,double Balance, string accountName,string Type, double rate, double minbalance) : Account(accountnum,Balance,accountName,Type) ,interestRate(rate), minimumBalane(minbalance)
    {}

    
    void CalculateInterest()
    {
        double RATE = (balance * rate * Time)/100;
        interestRate = RATE;
        cout << " Interest  is " << RATE << endl;

    }

    void withdraw(double amount)
    {
        if(balance - amount >= minimumBalane)
        {
             balance = balance - amount;
             cout << " Withdrawn =  " <<  amount << " Amount in balance is " << balance << endl;
             
        }
        else
        {
            cout << " Sorry cant proceed with withdraw reqeust " << endl;
        }
       
    }

    
    void printStatement()
    {
        Account :: printStatement();
        cout << " Rate is " << interestRate << endl;
        cout << " minimum blance is " << minimumBalane << endl;
    }



};


class CheckingAccount : public Account
{


    public:

    CheckingAccount()
    { }

    CheckingAccount(int accountnum,double Balance, string accountName,string Type) : Account(accountnum,Balance,accountName,Type) 
    {}

    
    void CalculateInterest()
    {
        double RATE = (balance * rate * Time);
        rate = RATE;
        cout << " rate is " << RATE << endl;

    }

    void withdraw(double amount)
    {
        if(balance >= amount)
        {
             balance = balance - amount;
             cout << " Withdrawn =  " <<  amount << " Amount in balance is " << balance << endl;
        }
        else
        {
            cout << " Sorry cant proceed with withdraw reqeust " << endl;
        }
       
    }

};

class FixedDepositAccount : public Account
{
    protected:
    string maturityDate;
    double fixedInterestrate;


    public:

    FixedDepositAccount()
    {
        fixedInterestrate  = 0.0;
        maturityDate = " ";
    }

    FixedDepositAccount(int accountnum,double Balance, string accountName,string Type,string Date, double rate) : Account(accountnum,Balance,accountName,Type) ,maturityDate(Date), fixedInterestrate(rate)
    {}

    
    void CalculateInterest()
    {
        double RATE = (balance * rate * Time);
        fixedInterestrate = RATE;
        cout << " rate is " << RATE << endl;

    }

    void withdraw(double amount)
    {
    cout << "Cannot withdraw before maturity date: " << maturityDate << endl;
    }

    
    void printStatement()
    {
        cout << " fixed Rate is " << fixedInterestrate << endl;
        cout << " date  is " << maturityDate << endl;
    }


};

int main()
{
    
    Account * account[3];
    account[0] = new SavingsAccount(101, 5000, "Alice", "Savings", 3.5, 2000);
    account[1] = new CheckingAccount (102, 3000, "Bob", "Checking");
    account[2] = new FixedDepositAccount (103, 10000, "Charlie", "Fixed Deposit", "2026-01-01", 5.0);
    
    cout << "StartUp Account Details " << endl ;
    
    for (int i = 0; i < 3; i++) {
        account[i]->printStatement();
    }

    
    cout << " Try Your Transactions";
    account[0]->deposit(2000);
    account[0]->withdraw(6000); 

    account[1]->deposit(1000);
    account[1]->withdraw(3500); 

    account[2]->withdraw(5000); 

    
    cout << " Updated  Account Details After Transactions " << endl;
    for (int i = 0; i < 3; i++) {
        account[i]->printStatement();
    }

    
    for (int i = 0; i < 3; i++) {
        delete account[i];
    }

    return 0;
}
// Q2
// Bazil-Uddin-Khan 24k-0559 Bscs-2H 
#include<iostream>
using namespace std;

class Shape
{
    int position;
    string colour;
    double borderThickness;

    public:
    Shape()
    {
        position = 0;
        colour = " ";
        borderThickness = 0.0;
    }

    Shape(int position,string colour,double borderThickness) : position(position), colour(colour), borderThickness(borderThickness)
    {}

    void draw()
    {
        cout << " Object is drawing " << " with position is " << position << " colour is " << colour << " boorder is " << borderThickness << endl;
    }

    virtual void calculateArea()
    {}

    virtual void calculatePerimeter()
    {}

};

class Circle : public Shape
{
    double radius;
    int centreposition;

    public:
    Circle()
    {
        radius = 0.0;
        centreposition = 0;
    }



    Circle(int position,string colour,double borderThickness,double rad, int curentpos) : radius(rad), centreposition(curentpos),Shape(position,colour,borderThickness)
    {}

    void calculateArea()
    {
        double area = (3.142 * radius * radius);
        cout << " Area is " << area << endl;
    }

    void calculatePerimeter()
    {
        cout << " Can't calucalate periemter of circle " << endl;

    }

    void draw()
    {
        cout << " Circle is drawing " << " with position is " << centreposition <<  " radius  is " << radius << endl;
    }



};

class Rectangle : public Shape
{

    double width;
    double height;
    double TopleftCornerPos;
    
    int centreposition;

    public:
    Rectangle()
    {
        width = 0.0;
        height = 0;
        TopleftCornerPos = 0.0;
    }



    Rectangle(int position,string colour,double borderThickness,double Width,double Hieght,double pos) : width(Width),TopleftCornerPos(pos),height(Hieght),Shape(position,colour,borderThickness)
    {}

    void calculateArea()
    {
        double area = (height * width);
        cout << " Rectangle  Area is " << area << endl;
    }

    void calculatePerimeter()
    {
        double perimeter = 2*(width + height);
        cout << " Periemeter Of Rectangle is " <<perimeter<< endl;

    }

    void draw()
    {
        cout << " Rectangle is drawing " << " with Top left position is " <<TopleftCornerPos<<  " widtg is " << width << " Height is " << height <<  endl;
    }

};


class Triangle : public Shape
{
    
    double Base;
    double Height;
    
    public:
    Triangle()
    {
        Base = 0.0;
        Height = 0.0;
    }
    
    Triangle(int position,string colour,double borderThickness,double base, double height) : Shape( position,colour,borderThickness),Base(base),Height(height)
    { }
    
    void calculateArea()
    {
        double area =(0.5*Height *Base);
        cout << " Triangle  Area is " << area << endl;
    }

    void calculatePerimeter()
    {
    double perimeter  = (Base + Height);
        cout << " Periemeter Of Rectangle is " << perimeter << endl;

    }

    void draw()
    {
        cout << " Triangle is drawing " << " with base is  " << Base <<   " Height is " << Height <<  endl;
    }

};


class Polygon : public Shape
{
    int side;
    
    public:
    Polygon()
    {
        side =0.0;
    }
    
    Polygon(int position,string colour,double borderThickness,int Side) : Shape( position, colour, borderThickness),side(Side)
    {}
    
    void calculateArea()
    {
        double area =(2.598*side*side);
        cout << " Hexa Polygon   Area is " << area << endl;
    }

    void calculatePerimeter()
    {
    double perimeter  = (6 * side);
        cout << " Periemeter Of Hexa polygon is " << perimeter << endl;

    }

    void draw()
    {
        cout <<" Polygon is drawing " << " with side of Hexa polyogn is  is  " << side <<  endl;
    }
    
};

int main()
{
    Circle circle(4,"Red",5.6,4,5);
    circle.draw();
    circle.calculateArea();
    circle.calculatePerimeter();
    
    Rectangle rectangle(3,"Blue",5.6,1.2,3,5.8);
    rectangle.draw();
    rectangle.calculateArea();
    rectangle.calculatePerimeter();
    
    Triangle triangle(2,"White",7,6.7,3);
    triangle.draw();
    triangle.calculateArea();
    triangle.calculatePerimeter();
    
    Polygon polygon(2,"Purple",2.7,7);
    polygon.draw();
    polygon.calculateArea();
    polygon.calculatePerimeter();
    
    
}
// Q3
// 24k-0559 Bazil - Uddin - Khan 
 #include<iostream> 
 using namespace std;

class Person
{
    private: string name; 
    int age;

public:
Person()
{
    name = " ";
    age = 0;

}

Person(string Name, int Age): name(Name), age(Age)
{}

void displayDetails() {

cout << " Name  is " << name << endl;
cout << " Age  is " << age << endl;

}

};

class Teacher : virtual public Person { private:

string subject;

public:
Teacher()
{
   
  subject = " ";

}

Teacher(string name, int age, string Subject): Person(name,age)
{
    subject = Subject;
}

void displayDetails() 
{ 
    Person :: displayDetails();

    cout << " Subject is " << subject << endl;

}

}; 

class Researcher : virtual public Person {
    private:

string researchArea;

public:
Researcher()
{
   
 researchArea = " ";

}

Researcher(string name, int age, string rearch): Person(name,age)
{
    researchArea = rearch;
}

void displayDetails() 
{
    Person :: displayDetails();
    cout << " Researcher Area is " << researchArea << endl; 
    
}

};

class Proffessor : public Teacher ,public Researcher {
    private: 
    int Publications;

public:
Proffessor()
{
    Publications = 0;
}

Proffessor(string name, int Age,string subject , string rearch,int publication) : Person(name,Age), Teacher(name,Age,subject),Researcher(name,Age,rearch)
{
    
    Publications = publication;
}

void displayDetails()

{
   
    Teacher :: displayDetails();
    cout << " Publucations are  " << Publications << endl; }

};

int main()
{ 
    string Name; 
    
    cout << " enter Name " << endl;
    getline(cin,Name);

int age; cout << " enter age " << endl; cin >> age;

string Subject;
cin.ignore();
cout << " enter subject " << endl;
getline(cin,Subject);

string  reasearch; 

cout << " enter Researcher " << endl; 
getline(cin,reasearch);

int publication; 
cout << " Enter Number Of publications " << endl; 
cin >> publication;

Proffessor p(Name,age,Subject,reasearch,publication);
p.displayDetails();

}
// Q4
// Bazil-Uddin-Khan 24k- 0559
#include <iostream>
using namespace std;

class Account
{
    private:
    int accountNumber;
    float balance;
    
    public:
    Account()
    {
        accountNumber =0;
        balance = 0.0;
    }
    
    Account(int num,float Balance) : accountNumber(num),balance(Balance)
    {}
    
    void displayDetails()
    {
        cout << " Account Num is " << accountNumber << endl;
        cout << " Balance is " << balance << endl;
    }
    
    
};

class SavingsAccount : public Account
{
    private:
    float interestRate;
    
    public:
    SavingsAccount()
    {
        interestRate = 0.0;
    }
    
    SavingsAccount(int num,float Balance,float rate) : Account(num, Balance) , interestRate(rate)
    { }
    
    void displayDetails()
    {
        Account :: displayDetails();
        cout << " Interest Rate is " << interestRate << endl;
    }
    
};

class CheckingAccount : public Account
{
    private:
    float overdraftLimit;
    
    public:
    CheckingAccount()
    {
        overdraftLimit = 0.0;
    }
    
    CheckingAccount(int num,float Balance,float limit) : Account(num, Balance) , overdraftLimit(limit)
    { }
    
    void displayDetails()
    {
        Account :: displayDetails();
        cout << " Over draft Limit  is " << overdraftLimit << endl;
    }
    
};

int main()
{
    int Num;
    cout << " Enter The Account Number " << endl;
    cin >> Num;
    
    float balance;
    cout << " Enter Balance in Account " << endl;
    cin >> balance;
    
    float rate;
    cout << " Enter Interest Rate " << endl;
    cin >> rate;
    
    float limit;
    cout << " Enter Over draft Limit " << endl;
    cin >> limit;
    
    string Choice;
    cout << " Enter Choice For S(Savings) && For Checking(C) " << endl;
    cin >> Choice;
    if(Choice == "S")
    {
        SavingsAccount saccount(Num,balance,rate);
        saccount.displayDetails();
    }
    else
    {
        CheckingAccount saccount(Num,balance,limit);
        saccount.displayDetails();
    } 
    
    
    

    return 0;
}
//Q5

 // BAZIL-UDDN-KHAN 24K-0559

#include <iostream>
using namespace std;


class Device
{
    private:
    int deviceID;
    bool status;
    
    public:
    Device()
    {
        deviceID = 0;
        status = false;
    }
    
    Device(int id,bool Status)
    {
       deviceID = id;
       status = Status;
    }
    
    void displayDetails()
    {
        cout << " Device id is " << deviceID << endl;
        cout << " Status of Device is " << status << endl;
    }
    
    
};

class SmartPhone : virtual public Device
{
    private:
    float screenSize;

    public:
    SmartPhone()
    {
        screenSize =0.0;
    }
    
    SmartPhone(int id,bool Status,float size) :Device(id,Status),screenSize(size)
    {}
    
    void displayDetails()
    {
 
        cout << "  Screen size of Device is " << screenSize << endl;
    }
    
    
};

class SmartWatch : virtual public Device
{
    private:
    bool heartRateMonitor;
    

    public:
    SmartWatch()
    {
        heartRateMonitor = false;
    }
    
    SmartWatch(int id,bool Status,bool rate) :Device(id,Status), heartRateMonitor(rate)
    { }
    
    void displayDetails()
    {
        
        cout << "  Heart Rate is " << heartRateMonitor << endl;
    }
    
    
};

class SmartWearable : public SmartPhone, SmartWatch  
{
    int stepCounter;
    
    public:
    SmartWearable()
    {
        stepCounter =0;
    }
    
    SmartWearable(int id,bool Status,bool rate,int counter,float size) : Device(id,Status) , SmartPhone(id,Status,size), SmartWatch(id,Status,rate), stepCounter(counter)
    { }
    
    void displayDetails()
    {
        Device :: displayDetails();
        SmartWatch :: displayDetails();
        SmartPhone :: displayDetails();
        cout << " Step Counter is " << stepCounter << endl;
    }
    
};


int main() 
{
    int id;
    cout << " Enter Id " << endl;
    cin >> id;
    
    bool status;
    cout << " Enter Device Status (true for 1/false for 0 ) " << endl;
    cin >> status;
    
    float size;
    cout << " Enter Screen Size of SmartPhone " << endl;
    cin >> size;
    
    bool heartrate;
    cout << " Enter in(true for 1) /(false for 0) for heart rate " << endl;
    cin >> heartrate;
    
    int counter;
    cout << " Enter Step Counter " << endl;
    cin >> counter;
    
    SmartWearable w(id,status,heartrate,counter,size);
    w.displayDetails();

    return 0;
}
