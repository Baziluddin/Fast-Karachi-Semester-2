// Q1
//24k0559 Bazil - Uddin - Khan

#include<iostream>
using namespace std;

class Employee
{
  private:
  string Name;
  float Salary;

  public:
  Employee()
  {
    Name = " ";
    Salary = 0.0;
  }

  Employee(string name, float salary) : Name(name), Salary(salary)
  {}

  void display()
  {
    cout << " name is " << Name << endl;
    cout << " salary " << Salary << endl;
  }


};

class Manager : public Employee
{
    float BONUS;

    public:
    Manager()
    {
        BONUS = 0.0;
    }

    Manager(string name, float salary,float bonous) : Employee(name,salary)
    {
        BONUS = bonous;
       
    }

 void display()
   {
    Employee :: display();
    cout << " bonous is " << BONUS << endl;
   
  }



};

int main()
{
    string name;
    float salary;
    float bous;
    cout << " Enter Name ";
    
    getline(cin,name);
    cout << " Enter Salary " << endl;
    cin >> salary;
    cout << " Enter Bonus " << endl;
    cin >> bous;

    Manager man(name, salary, bous);
    man.display();
}
// Q2
// 24k-0559 Bazil - Uddin - Khan 
#include<iostream>
using namespace std;

class Vehicle
{
    private:
    string brand;
    int speed;

    public:
    Vehicle()
    {
        brand = " ";
        speed = 0;

    }

    Vehicle(string   Brand, int Speed): brand(Brand), speed(Speed)
    {}

  void displayDetails()
   {
   
    cout << " brand is " << brand << endl;
    cout << " speed is " << speed << endl;

   
  }

};

class Car : public Vehicle
{
    private:
   
    int seats;

    public:
    Car()
    {
       
        seats = 0;

    }

    Car(string   Brand, int Speed, int Seats): Vehicle(Brand,Speed)
    {
        seats = Seats;
    }

  void displayDetails()
   {
    Vehicle :: displayDetails();

   
   
    cout << " sEATS is " << seats << endl;

   
  }
 




};
class ElectricCar : public Car
{
    private:
   
    int batterylife;

    public:
    ElectricCar()
    {
       
        batterylife =0;

    }

    ElectricCar(string Brand, int Speed, int Seats ,int battery): Car(Brand, Speed, Seats)
    {
        batterylife = battery;
    }

  void displayDetails()
   {
    Car :: displayDetails();

   
   
    cout << " baaterly life is " << batterylife << endl;

   
  }
 

};

int main()
{
string brand;
cout << " enter brand " << endl;
cin >> brand;
int speed;
cout << " enter speed " << endl;
cin >> speed;
int seats;
cout << " enter seats " << endl;
cin >> seats ;
int  batterylife;
cout << " enter batteylife " << endl;
cin >>batterylife ;

ElectricCar c(brand,speed,seats,batterylife);
c.displayDetails();


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
// Q5
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
