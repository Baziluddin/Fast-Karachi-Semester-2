// 24k-0559 BAZIL-UDDIN-KHAN
#include <iostream>
using namespace std;

class Vehicle
{
    private:
    double Capacity;
    double EnergyConsumption;
    double AverageSpeed;
    
    
    
    static  int Activedelieveries;
    
    protected:
    string vehicleID;
    
    string Routes[6] = {"Clifton","Millinium","Saddar","Nazimabad","Gulshan","Malir"};
    double EstimatedTimeInHour[6] = {3.4,4,2,2,4,1.5};
    double Distance[6] ={2,5,3,7,8,9};
    string FoodAvailable[10] = {"Biryani", "Nihari", "Haleem", "Paya", "Chapli Kebab", "Sajji", "Karahi", "Aloo Paratha", "Chana Chaat", "Zarda"};
    double Prices[10] = {
        300.0, 350.0, 190.0, 350.0, 0.0, 1430.0, 960.0, 350.0, 490.0, 800};
    
    public:
    Vehicle(){vehicleID = " ";}
    
    Vehicle(string Id,double capacity,
    double Consumption,
    double Speed) : vehicleID(Id),AverageSpeed(Speed),EnergyConsumption(Consumption),Capacity(capacity)  
    {}
    string GetvehicleID()
    {
        return vehicleID;
        
    }
    double GetAverageSpeed()
    {
        return AverageSpeed;
    }
    double EstimatedTimeDelievery()
    {
        cout << " _Locations Available For Delivery Are_ " << endl;
        for(int y =0; y<6;y++)
        {
            cout << " " << Routes[y] << "  " << endl;
        }
        
        string Choice;
        cout << " Enter Your Location For Order " << endl;
        cin >> Choice;
        
        int Index = -1;
        for(int u =0; u<6; u++)
        {
            if(Routes[u] == Choice)
            {
                Index = u;
            }
            
        }
        if(Index != -1)
        {
            double TimeReq = (Distance[Index] *EstimatedTimeInHour[Index] - Distance[Index]);
            cout << " Time Of Delievery Is  = " << TimeReq << endl;
            return TimeReq;
            
        }
        
        else
        {
            cout << " Sorry We Donot Provide Seruve Here " << endl;
            return 0;
        }
        
        
    }
    
   friend bool operator==(const Vehicle& v1, const Vehicle& v2);
    
    
    void OptimumDeilieveryRoute(double TimeReq )
    {
        
        double Optimum = TimeReq;
        int index =0;
        for(int y =1; y < 6; y++)
        {
            if(Optimum<=EstimatedTimeInHour[y])
            {
                Optimum = EstimatedTimeInHour[y];
                index = y;
            }
        }
        
        
        cout << " The Optimum Delievery Route For Deilevery will Be Through  " << Routes[index] << endl;
        Activedelieveries++;
        cout << "Active Delievers Are " << Activedelieveries << endl;
        
        
    }
    
    virtual void VehicleMovement()
    {
        string Order;
        cout << " __Orders Available Are__ : " << endl;
        for(int i =0; i <10; i++)
        {
            cout << " " <<  FoodAvailable[i] << " " << endl;
        }
        double TotalBill = 0.0;
   while(1)
   {
          cout << " Do You Want To Place Order ? (Yes/No) " << endl;
        cin >> Order;
        if(Order == "Yes")
        {
        
                string Choice;
                cout << " Enter Meal Name " << endl;
                cin >> Choice;
                
                for(int i =0; i < 10;i++)
                {
                    if(Choice ==FoodAvailable[i])
                    {
                        
                        TotalBill = TotalBill + Prices[i];
                    }
                }
        }
            
        
            
        
        else
        {
            cout << " Thanks For Visiting Our System " << endl;
            cout << " Total Bill Is " << TotalBill << endl;
            break;
        }
    }
    }

    
};

 
int Vehicle :: Activedelieveries =0;


bool operator==(const Vehicle& v1, const Vehicle& v2) {
    return (v1.AverageSpeed == v2.AverageSpeed) && (v1.Capacity == v2.Capacity) && (v1.EnergyConsumption == v2.EnergyConsumption);
}


class RamazanDrone : public Vehicle
{
    private:
    
    
    protected:
    
    double Moisture[6] = {5,6,2,3,4,7};
    double DroneSpeed[3] = {45,75,100};
    
    
    public:
    RamazanDrone()
    {}
    
    RamazanDrone(string Id,double capacity,
    double Consumption,
    double Speed) : Vehicle(Id,capacity,
     Consumption, Speed)
    {}
    
    void VehicleMovement()
    {
       Vehicle :: VehicleMovement();
       double TimeReq = EstimatedTimeDelievery();
       OptimumDeilieveryRoute(TimeReq);
       
       double SmallestMoisture = Moisture[0];
       int Index = -1;
       for(int y =1;y<6;y++)
        {
            if(Moisture[y] < SmallestMoisture)
            {
                SmallestMoisture = Moisture[y];
                Index = y;
            }
        }
        
        if(Index != -1)
        {
            cout << " Drone Taking The Route Where Moisture Lowest Is = " << Moisture[Index] << " Location is = " << Routes[Index] << endl;
            
        }
        
    }
    
    
};


class RamazanTimeShip : public Vehicle
{
    protected:
    
    private:
    double Capacity;
    double EnergyConsumption;
    double AverageSpeed;
    double Protocol[2] = {2,8};
    string Protocolindex[2] = {
        "Time Taken","Ratings Provied Out Bw(1-10) "};
    
    
    public:
    RamazanTimeShip()
    {}
    
    RamazanTimeShip(string Id,double capacity,
    double Consumption,
    double Speed) : Vehicle(Id,capacity,Consumption,Speed) 
    {}
    
    void VehicleMovement()
    {
        
        cout << "Vehicle Id Of " << vehicleID <<  "is Goining On A Visit In History " << endl;
        Vehicle :: VehicleMovement();
        
        double timereq = EstimatedTimeDelievery();
        if(timereq !=0)
        {
            OptimumDeilieveryRoute(timereq);
            double rating;
            cout << " Enter Rating (1-10) " << endl;
            cin >> rating;
            
            if(timereq <=2 && rating >=8)
            {
                Protocol[0] = timereq;
                Protocol[1] = rating;
                cout << " Time Machine Succesfully Toured History And Met Protocols With Updated Recent History " << endl;
            }
            else
            {
                cout << " Meet History Standards Now!. " << endl;
            }
            
        }
       
    }
    
};

class RamazanHyperPod : public Vehicle
{
    private:
    double Capacity;
    double EnergyConsumption;
    double AverageSpeed;
    
    protected:
    double TunnelCapacityInMeter[6] = 
    {12,32,47,34,23,10};
    
    public:
    RamazanHyperPod()
    {}
    
    RamazanHyperPod(string Id,double capacity,
    double Consumption,
    double Speed) : Vehicle(Id,capacity,Consumption,Speed)
    {}
    
    void VehicleMovement()
    {
       
        double TimeReq = EstimatedTimeDelievery();
        if(TimeReq != 0)
        {
           OptimumDeilieveryRoute(TimeReq);
        
           int index =0;
          double HighestCapacity = TunnelCapacityInMeter[0];
           for(int y =1;y<6;y++)
          {
              if(HighestCapacity < TunnelCapacityInMeter[y] )
              {
                 HighestCapacity =  TunnelCapacityInMeter[y];
                 index = y;
              }
          }
        
          cout << " From The Location " << Routes[index] << " And The Tunnel Has This Capaciry " << TunnelCapacityInMeter[index] << endl;
        }
      }
    
};

class OperatorControlPanel
{
public:
    void command(string action, int packageID)
    {
        cout << "Executing " << action << " for package " << packageID << " normally." << endl;
    }

    void command(string action, int packageID, string urgencyLevel) {
        cout << "Executing " << action << " for package " << packageID << " with urgency: " << urgencyLevel << endl;
       }
};


class AiConflictResolutionSystem
{
public:
    static Vehicle resolveConflict(Vehicle v1, Vehicle v2)
    {
        if (v1 == v2)
        {
            cout << "Both vehicles are efficient.But Assigning first available vehicle." << endl;
            return v1;
            
        } 
        else if (v1.GetAverageSpeed() > v2.GetAverageSpeed())
        {
            cout << " Vehicle 1 is faster. Selecting v1" << endl;
            return v1;
            
        } 
        else 
        {
            cout << "Vehicle 2 is more efficient. Selecting v2" << endl;
            return v2;
        }
    }
};



int main() 
{
   
    RamazanDrone drone("DroneX", 10, 85, 120);   
    RamazanTimeShip timeShip("TimeShipY", 30, 90, 80); 
    RamazanHyperPod hyperPod("HyperPodZ", 100, 75, 150); 

   cout << " Ramazan Drome " << endl;
    double droneTime = drone.EstimatedTimeDelievery();
    drone.OptimumDeilieveryRoute(droneTime);
    
    cout << " Time Ship " << endl;
    double timeShipTime = timeShip.EstimatedTimeDelievery();
    timeShip.OptimumDeilieveryRoute(timeShipTime);
    
    cout << " HyperPod " << endl;
    double hyperPodTime = hyperPod.EstimatedTimeDelievery();
    hyperPod.OptimumDeilieveryRoute(hyperPodTime);

   
   cout << endl;
   cout << endl;
   cout << " Command Deciding " << endl;
    OperatorControlPanel panel;
    panel.command("Deliver", 101); 
    panel.command("Deliver", 102, "Urgent"); 


    cout << "  AI Conflict Resolution Test  " << endl;
    Vehicle vehicle1("DroneX", 10, 85, 120);
    Vehicle vehicle2("HyperPodY", 50, 95, 120);

    
    Vehicle selectedVehicle = AiConflictResolutionSystem::resolveConflict(vehicle1, vehicle2);
    
    cout << " Ai is selecteing the following vehicle for delivery:" << endl;
    cout << "Vehicle ID: " << selectedVehicle.GetvehicleID() << ", Speed: " << selectedVehicle.GetAverageSpeed() << endl;
    
   
    cout << "  Vehicle Movements "  << endl;
    drone.VehicleMovement(); 
    timeShip.VehicleMovement(); 
    hyperPod.VehicleMovement(); 

    return 0;
}