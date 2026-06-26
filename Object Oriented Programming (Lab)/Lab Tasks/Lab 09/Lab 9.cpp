
// Bazil-Uddin-Khan24k-0559 
#include <iostream>
using namespace std;

class Vehicle
{
    protected:
    string model;
    double rate;
    
    public:
    Vehicle():model(" "),rate(0.0)
    {}
    
    Vehicle(string mode,double Rate) : model(mode),rate(Rate)
    {}
    
    virtual void displayDetails() =0;
    
    virtual double getDailyRate() =0;
    
};

class Car : public Vehicle
{

    public:
    Car()
    {}
    
    Car(string mode,double rate): Vehicle(mode,rate)
    {}
    
    void displayDetails()
    {
        cout << " Car Model Is " << model << " and Car Rate is " << rate << endl;
    }
    
    double getDailyRate()
    {
        return rate;
    }
    
};

class Bike : public Vehicle
{

    public:
    Bike()    
    {}
    
    Bike(string mode,double rate): Vehicle(mode,rate)
    {}
    
    void displayDetails()
    {
        cout << " Bike Model Is " << model << " and Bike Rate is " << rate << endl;
    }
    
    double getDailyRate()
    {
        return rate;
    }
    
};


int main()
{
    Vehicle * vehicle[2] = {
        new Car("Toyota",4.6), new Bike("Zxcdf",5.8)
    };
    

    vehicle[0]->displayDetails();
    vehicle[1]->displayDetails();
    cout << " Car Rate Is " << vehicle[0]->getDailyRate() << endl;
    cout << " Bike Rate Is " << vehicle[1]->getDailyRate() << endl;
   
    return 0;
}
//Q2
// Bazil-Uddin-Khan24k-0559 
#include <iostream>
using namespace std;

class SmartDevice
{
    
    public:
    SmartDevice()
    {}
    
    
    virtual void turnOn() =0;
    
    virtual void turnOff() =0;
    
    virtual bool getStatus() =0;
    
};

class LightBulb : public SmartDevice
{
    protected:
    bool isOn;
    int brightness;
    
    public:
    LightBulb()
    {}
    
    LightBulb(int bright): brightness(bright),isOn(0)
    {}
    
    void turnOn()
    {
        isOn = 1;
    }
    
    void turnOff()
    {
        isOn = 0;
    }
    
    bool getStatus()
    {
        return isOn;
    }
    
    int GetBrightness()
    {
        return brightness;
    }
    
    string GetOnoff()
    {
        if(isOn == 1)
        {
            return "on";
        }
        else
        {
            return "off";
        }
    }

};

class Thermostat : public SmartDevice
{
    protected:
    bool isOn;
    double temperature;
    
    public:
    Thermostat()
    {}
    
    Thermostat(double temp): temperature(temp),isOn(0)
    {}
    
    void turnOn()
    {
        isOn = 1;
    }
    
    void turnOff()
    {
        isOn = 0;
    }
    
    bool getStatus()
    {
        return isOn;
    }
    
    double GetTemp()
    {
        return temperature;
    }
    
    string GetOnoff()
    {
        if(isOn == 1)
        {
            return "on";
        }
        else
        {
            return "off";
        }
        
    }
  
};

int main()
{
  LightBulb bulb(27);
  Thermostat thermo(56.89);
  
  cout << "---Bulb Details---"<< endl;
  
  
  cout << " Bulb Updated Status Is " << bulb.getStatus() <<" and Bulb is " << bulb.GetOnoff() << endl;
  
  bulb.turnOn();
  
  cout << " Bulb Updated Status Is " << bulb.getStatus() <<" and Bulb is " << bulb.GetOnoff() << endl;
  
  bulb.turnOff();
  
  cout << " Bulb Updated Status Is " << bulb.getStatus() <<" and Bulb is " << bulb.GetOnoff() << endl;
  
  cout << " Bulb Brightness is "<< bulb.GetBrightness() << endl;
  
  cout << "---Thermostat Details---"<< endl;
  
  
  cout << " Thermo  Status Is " << bulb.getStatus() <<" and Thermo is " << bulb.GetOnoff() << endl;
  
  
  thermo.turnOn();
  
  
  cout << " Thermostat Updated Status Is " << thermo.getStatus() <<" and Thermostat is " << thermo.GetOnoff() << endl;
  
  thermo.turnOff();
 
  cout << " Thermostat Updated Status Is " << thermo.getStatus() <<" and Thermostat is " << thermo.GetOnoff() << endl;
  
  cout << " Thermostat has " << thermo.GetTemp() << " Temperature " << endl;
 
    return 0;
}

// Q4
// Bazil-Uddin-Khan24k-0559 
#include <iostream>
using namespace std;

class PaymentMethod
{

    public:
    PaymentMethod()
    {}
    
    virtual void processPayment(double amount) =0;
    
};

class CreditCard  : public PaymentMethod
{
    protected:
    string cardNumber;
    
    public:
    CreditCard()
    {}
    
    CreditCard(string number): cardNumber(number)
    {}
    
    void processPayment(double payment)
    {
        if(payment > 0)
        {
            cout << "Succesfully Processing Payment! "
                << payment << endl;
        }
        else
        {
            cout << " Sorry!. Cant Proceed Payment " << endl;
        }
        
    }
    
    
};

class DigitalWallet : public PaymentMethod
{
    protected:
    double balance;
    
    public:
    DigitalWallet()    
    {}
    
    DigitalWallet(double bal):balance(bal)
    {}

    void processPayment(double price)
    {
        if(price <= balance)
        {
            balance = balance - price;
            cout << " Susssfully!. Updated The Balance " << balance << endl;
        }
        else
        {
            cout << " Too less Money " << endl;
        }
    }

    
};


int main()
{
    CreditCard credit("12345567");
    DigitalWallet wallet(867.87);
    
    cout << " --Credit Processing-- " << endl;
    credit.processPayment(700);
    
    cout << " --DigitalWallet Processing -- " << endl;
    wallet.processPayment(80);
    
    return 0;
}
// Q5
// Bazil-Uddin-Khan24k-0559 
#include <iostream>
using namespace std;

class Activity
{
    public:
    Activity()
    {}
    
 virtual void calculateCaloriesBurned() =0;
};

class Running : public Activity
{
    protected:
    double distance;
    double time;
    
    public:
    Running()
    {}
    
    Running(double dis, double Time): distance(dis),time(Time)
    {}
    
    void calculateCaloriesBurned() 
    {
        double calburned = (distance/time);
        cout << "Total Calories Burned 🔥 Is " << calburned << endl;
    }
};

class Cycling : public Activity
{
    protected:
    double speed;
    double time;
    
    public:
    Cycling()    
    {}
    
    Cycling(double Speed,double Time): speed(Speed),time(Time)
    {}

    void calculateCaloriesBurned() 
    {
        double calburned = (speed/time);
        cout << "Total Calories Burned 🔥 Is " << calburned << endl;
    }
};


int main()
{
    Running run(876,2.65);
    Cycling cycle(6.78,2.3);
    
    cout << " _Running_ 🏃‍ " << endl;
    run.calculateCaloriesBurned();
    
    cout << " _Cycling_ ‍ " << endl;
    cycle.calculateCaloriesBurned();
    
    return 0;
}
