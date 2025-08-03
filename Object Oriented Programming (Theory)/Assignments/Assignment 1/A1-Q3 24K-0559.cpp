// 24K-0559 BAZIL-UDDIN-KHAN

#include <iostream>
using namespace std;

class UserRegister
{
    private:
    int Age;
    string LiscenceType;
    string ContactNumber;
    string UserId;
    
    public:
    
    UserRegister()
    {
        Age = 0;
        LiscenceType = " ";
        ContactNumber =" ";
        UserId = " ";
    }
    string GetUserId() 
    {
        return UserId;
    }
    
    void SetAge(int Age)
    {
        this->Age = Age;
    }
    void SetLiscenceType(string LiscenceType)
    {
        this->LiscenceType = LiscenceType;
    }
    void SetContactNum(string ContactNumber)
    {
        this->ContactNumber = ContactNumber;
    }
    
    void RegisterDeatils()
    {
        int Age;
        cout << " Enter Your Age " << endl;
        cin >> Age;
        this->Age = Age;
        string LiscenceType;
        cout << " Enter Your Liscence Type(Full,Intermediate,Learners) " << endl;
        cin >> LiscenceType;
        this->LiscenceType = LiscenceType;
        string ContactNumber;
        cout << " Enter Your Contact Number " << endl;
        cin >> ContactNumber;
        this->ContactNumber = ContactNumber;
        string UserId;
        cout << " Enter Your User Id " << endl;
        cin >> UserId;
        this->UserId = UserId;
        
    }
    
    
    
    
    void UpdateDetails(UserRegister* user,int j)
    {
        int Age;
        cout << " Enter Your Updated Age " << endl;
        cin >> Age;
        user[j].SetAge(Age);
    
        string LiscenceType;
        cout << " Enter Your Updated Liscence Type " << endl;
        cin >> LiscenceType;
        
        user[j].SetLiscenceType(LiscenceType);
        
        string ContactNumber;
        cout << " Enter Your Updated Contact Number " << endl;
        cin >> ContactNumber;
        
        user[j].SetContactNum(ContactNumber);
       
    }
    void CallCapplicationStatus()
    {
        ApplicationStatus();
    }
    
    void StartApplication()
    {
        cout << " Start Your Application " << endl;
        
    }
    void EndApplication()
    {
        cout << "  Application Ended  " << endl;
        
    }
    int ApplicationStatus()
    {
        return 1;
    }
    string GetLiscenceType()
    {
        return LiscenceType;
    }
    
};

class Vehicle
{
    private:
    string Model;
    double RentalPrice;
    string EligiblityStatus;
    string  LearnersVehicles[10] = {"NisanVersa","Toyotayaris","Kia","Hyundai","ToyotaCarolla","SuzukiAlto","SuzukiMehran","Honda","HondaGr","Honda360" };
    
    double LearnerCarsRentalPrice[10] = {3235.56,4300,7500.67,11000,4200,9000,6700,2034,5000,3000};
    
    string IntermediateVehicles[10] = {"NisanVersa","Toyotayaris","Kia","Hyundai","ToyotaCarolla","SuzukiAlto","SuzukiMehran","Honda","HondaGr","Honda360" };
    
    double IntermediateCarsRentalPrice[10] = {12355.56,13000,14500.67,11000,14200,19000,67000,2034,5000,30000};
    
    string FullVehicles[10] = {"HondaBrv","KiaPicanto","KiaSportage","Ford","Toyataparado","SuzukiAlto","SuzukiMehran","Honda","HondaGr","Honda360" };
    
    double FullCarsRentalPrice[10] = {123555.56,130000,145000.67,110000,142000,190000,67000,203004,500000,30000};
    
    void SetAttributes(string Model,double RentalPrice,string EligiblityStatus)
    {
        this->Model = Model;
        this->RentalPrice = RentalPrice;
        this->EligiblityStatus = EligiblityStatus;
    }
    
    public:
    Vehicle()
    {
        Model = " ";
        RentalPrice =0;
        EligiblityStatus = " ";
        
    }
    Vehicle(string Model,double RentalPrice,string EligiblityStatus)
    {
        this->Model = Model;
        this->RentalPrice = RentalPrice;
        this->EligiblityStatus = EligiblityStatus;
    }
  
    
    void BuiltInWork(Vehicle ** vehicle)
    {
        
        for(int i =0; i < 10; i++)
        {
            vehicle[i]->SetAttributes(LearnersVehicles[i],LearnerCarsRentalPrice[i],"Learners");
        }
        for(int i =0; i < 10; i++)
        {
            vehicle[i+10]->SetAttributes(IntermediateVehicles[i],IntermediateCarsRentalPrice[i],"Intermediate");
        }
        for(int i =0; i < 10; i++)
        {
            vehicle[i+20]->SetAttributes(FullVehicles[i],FullCarsRentalPrice[i],"Full");
        }
        
    }
    
    
    string GetEligiblityStatus()
    {
        return EligiblityStatus;
    }
    
    double GetRentalRate()
    {
        return RentalPrice;
    }
    
    
    void Display(string Type)
    {
        if(Type == "Learners")
        { 
          cout << " Your VehicleLisence Is  " << "Learners" << endl;
        
          cout << " Available Care Are " << endl;
          cout << "  Cars   " << "    " << "   Rents  " << endl;
           for(int i =0; i < 10; i++)
           {
            cout << "  " << LearnersVehicles[i]
                 << "\t\t\t"  << LearnerCarsRentalPrice[i] << "     " << endl;
            
           }
        
        }
        
        
        else if(Type == "Intermediate")
        { 
          cout << " Your VehicleLisence Is  " << "Intermediate" << endl;
        
          cout << " Available Care Are " << endl;
          cout << "  Cars   " << "    " << "   Rents  " << endl;
           for(int i =0; i < 10; i++)
           {
            cout << "  " << IntermediateVehicles[i]
                 << "\t\t\t"   << IntermediateCarsRentalPrice[i] << "     " << endl;
            
           }
        
        }
        
        else if(Type == "Full")
        { 
          cout << " Your VehicleLisence Is  " << "Full" << endl;
        
          cout << " Available Care Are " << endl;
          cout << "  Cars   " << "    " << "   Rents  " << endl;
           for(int i =0; i < 10; i++)
           {
            cout << "  " << FullVehicles[i]
                 << "\t\t\t"  << FullCarsRentalPrice[i] << "      " << endl;
            
           }
        
        }
        
        else
         { 
             cout << " Invalid " << endl;
         }
    }
    void CheckUserRequirements(string VehicleName,UserRegister * user,int j,Vehicle ** vehicle)
    {
        
        string LiscenceType = user[j].GetLiscenceType();
        int Found = -1;
        if(LiscenceType == "Learners")
        {
            
            for(int i =0; i < 10; i++)
            {
                if(vehicle[i]->GetEligiblityStatus() == LiscenceType && LearnersVehicles[i] == VehicleName)
                {
                    cout << " Vehicle is Available and You are Competent To use it  " << endl;
                    cout << " Vehicle name is " << LearnersVehicles[i] << " " << "Vehicle Rent is : " << " " <<  vehicle[i]->GetRentalRate() << endl;
                    Found =0;

                    break;
                }
               
            }
        }
        else if(LiscenceType == "Intermediate")
        {
            
            for(int i =0; i < 10; i++)
            {
                if(vehicle[i+10]->GetEligiblityStatus() == LiscenceType && IntermediateVehicles[i] == VehicleName)
                {
                    cout << " Vehicle is Available and You are Competent To use it  " << endl;
                    cout << " Vehicle name is " << IntermediateVehicles[i] << " " << " Vehicle Rent is : " << " " <<  vehicle[i]->GetRentalRate() << endl;
                    Found =0;

                    break;
                    
                }
      
            }
        }
       else if(LiscenceType == "Full")
        {
            
            for(int i =0; i < 10; i++)
            {
                if(vehicle[i+20]->GetEligiblityStatus() == LiscenceType && FullVehicles[i] == VehicleName)
                {
                    cout << " Vehicle is Available and You are Competent To use it  " << endl;
                    cout << " Vehicle name is " << FullVehicles[i] << " " << "Vehicle Rent is : " << " " <<  vehicle[i+20]->GetRentalRate() << endl;
                    Found =0;

                    
                    break;
                }
      
            }
        }
        if(Found == -1)
        {
            cout << " Sorry You Are Not Eligible For This Car " << endl;
            
        }
        
    }
    ~Vehicle()
    {
    }
        
};

int main() 
{
    
    cout << " Welcome to  vehicle rental system " << endl;
   UserRegister * user = new UserRegister[1000];
   int i=0;
   Vehicle ** vehicle = new Vehicle*[30];
   for(int y =0; y < 30; y++ )
   {
       vehicle[y] = new Vehicle();
   }
   (vehicle[i])->BuiltInWork(vehicle);
  
   user[i].StartApplication();
   int Count =0;
   while(1)
   {
       
       string Choice;
       cout << " Enter Your Choice (Registerinfo/Update/RegisterVehicle/Exit/Display) ";
       cin >> Choice;
      
        if(Choice == "Registerinfo")
       {
            user[i].RegisterDeatils();
            i++;
            Count =1;
       }
       else if(Choice == "Update"&&Count!=0)
       {
           string UserId;
           cout << " Enter User Id For Updation  " << endl;
           cin >> UserId;
           for(int j =0; j <= i;j++)
           {
               if(user[j].GetUserId() == UserId)
               {
                   user[j].UpdateDetails(user,j);
                   break;
               }
           }
           
       }
       else if(Choice == "RegisterVehicle"&&Count!=0)
       {
           string VehicleName;
           cout << " Enter Vehicle Name You want To hire " << endl;
           cin >> VehicleName;
           (vehicle[i])->CheckUserRequirements(VehicleName,user,i-1,vehicle);
           
           
       }
       
       else if(Choice == "Display" &&Count!=0)
       {
           string Type = user[i-1].GetLiscenceType();
           vehicle[i-1]->Display(Type);
       }
       else if(Choice == "Exit")
       {
           user[i].EndApplication();
           break;
       }
       
       else if(Count == 0)
       {
           cout << " First Register "<<endl;
       }
       
       
       else
       {
           cout << " Invalid Input " << endl;
       }
   }
   
   for(int j =0; j < 30;j++)
   {
       delete vehicle[j];
   }
   
   
    delete [] vehicle;
    delete [] user;
    return 0;
}