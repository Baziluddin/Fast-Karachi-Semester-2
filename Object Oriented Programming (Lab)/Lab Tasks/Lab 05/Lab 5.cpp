// Q1
//24k-0559 bazil-uddin-khan
#include<iostream>
using namespace std;

class Car
{
    string Registerationnumber;
    string ModelName;
    string  OwnerName;

    public:
    Car()
    {
        Registerationnumber = " ";
        ModelName = " ";
        OwnerName = " ";
       
    }

    Car(string regisnum, string modelname, string ownername)
    {
        Registerationnumber = regisnum;
        ModelName = modelname;
        OwnerName = ownername;

    }
    

    void  Dispaly()
    {
        cout << "Registeration number is " << Registerationnumber << " " << " MOdel name is " <<  ModelName << " " << " owner nameis " << OwnerName << endl;

    }
    
    void SetOwnerName(string Name)
    {
       OwnerName = Name;
    }


};

int main()
{
   Car car1("1234k","ty65","ALi");
   car1.Dispaly();
   Car car2(car1);
   car2.SetOwnerName("Qasim");
   car2.Dispaly();
}
// Q2
// 24k-0559 bazil-uddin-khan
#include<iostream>
using namespace std;

class Patient
{
    private:
    string Uniqueid;
    string Uniquename;
    int * Results;
    int Totalelement;

    public:
    Patient()
    {
        Uniqueid = " ";
        Uniquename = " ";
        Results = nullptr;
        Totalelement =0;

    }
    Patient(string uniqueid, string unquename, int totalelement)
    {
        Totalelement = totalelement;
        
        Results = new int[Totalelement];
        for(int i =0; i <Totalelement ;i++)
            {
                    int result;
                   cout << " enter test  results "<<endl;
                   cin >> result;
                   Results[i]= result;

            }
        
        Uniqueid = uniqueid;
        Uniquename = unquename;

    }

    Patient(const Patient & pateint)
    {
        Uniqueid = pateint.Uniqueid;
        Uniquename  = pateint.Uniquename;
        Totalelement = pateint.Totalelement;
        Results = new int[Totalelement];
        for(int i = 0; i < Totalelement;i++)
        {
             Results[i] =pateint.Results[i];
        }


    }

    void setid(string newid )
    {
        Uniqueid = newid;


    }

    void update()
    {
        string newid;
        cout << " enter new id " << endl;
        cin >> newid;
        setid(newid);

    }

    void display()
    {
        cout << " patient name is " << Uniqueid << endl;;
        cout << " unique name is " << Uniquename << endl;
        for(int i =0 ; i < Totalelement;i++)
        {
            cout << Results[i] << endl;

        }
    }
    
    ~Patient() 
    {
        delete[] Results;
    }

};

int main()
{
    int totalelement;
    cout << " enter total elements " << endl;
    cin >> totalelement;

    Patient patient("123","patiney",totalelement);
    cout << "Original paytient  details  " << endl;
    
    patient.display();
    
    Patient patient2 = patient;
    
   
    cout << " Updating Copy Patients  " << endl;
    
    patient2.update();
    
    cout << " Original patient Details  After Copy "  << endl;
    
    patient.display();

    
    cout << " Copied patient details  after update " << endl;
    patient2.display();
   
}
// Q3
// 24k-0559 Bazil-Uddin-Khan 

#include <iostream>
using namespace std;

class Proffessor
{
    private:
    string ProffesorName;
    string ProffesorDepartment;
    
    public:
    Proffessor()
    {
        ProffesorName= " ";
        ProffesorDepartment = " ";
    }
    
    Proffessor(string ProffesorName,string ProffesorDepartment)
    {
        this->ProffesorName = ProffesorName;
        this->ProffesorDepartment = ProffesorDepartment;
    }
    
    string GetName()
    {
        return ProffesorName;
    }
    
    string GetDepartment()
    {
        return ProffesorDepartment;
    }
    
    void DisplayInfo()
    {
        cout << " Proffesor Name Is " << ProffesorName << endl;
        cout << " Professor Department Is " << ProffesorDepartment << endl;
        
    }
    
    void InitializeDetails(string ProffessorName, string Proffesordepartment)
    {
        ProffesorName = ProffessorName;
        ProffesorDepartment = Proffesordepartment;
    }
};


class University
{
    private:
    Proffessor * proffesor= nullptr;
    string UniversityName;
    string UniversityId;
    
    public:
    University(int TotalProffessors,string UniversityName, string UniversityId)
    {
        if(proffesor == nullptr)
        {
            proffesor = new Proffessor[TotalProffessors];
           this->UniversityName = UniversityName;
           this->UniversityId = UniversityId;
            
        }
        
    }
    
    University(string Uniname,string Uniid) : UniversityName(Uniname),UniversityId(Uniid)
    {}
    
    void DisplayUniversityDetails(int TotalElements)
    {
        cout << " University Deatils is " << endl;
        
        
        
        cout << " University Name Is " << UniversityName << " University Id is " << UniversityId << endl;
        
        cout << " Proffesor Details are " << endl;
        
        string professname;
        string proffesordepart;
        
        cin.ignore();
        for(int i = 0; i < TotalElements;i++)
        {
            
            
            cout << " Proffesor Name is " << endl;
            
            getline(cin,professname);
            
            cout << " Proffessor department is " << endl;
            
            getline(cin,proffesordepart);
            
            
            proffesor[i].InitializeDetails(professname,proffesordepart);
        }
        
        for(int i = 0; i < TotalElements;i++)
        {
            proffesor[i].DisplayInfo();
        }
    }
    
    
    ~University()
    {
       delete[] proffesor;
       
    }
};

int main()
{
    
    cout << " Welcome To Fast Management System " << endl;
    
    int Totalelements;
    cout << " Enter Total Proffessors " << endl;
    cin >> Totalelements;
    
    University uni(Totalelements,"Fast","Fastzx");
    uni.DisplayUniversityDetails(Totalelements);

    return 0;
}
// Q4
// Bazil uddin Khan 24k-0559

#include <iostream>
using namespace std;

class Battery
{
    private:
    double Capacity;
    const string BatteryType ;
    
    public:
    Battery() : BatteryType("NonRemovableBattery")
    {
        Capacity = 0;
        
    }
    
    Battery(double capacity) : Capacity(capacity), BatteryType("NonRemovableBattery")
    { }
    
    void SetCapacity(double Capacity)
    {
        this->Capacity = Capacity;
    }
    
    void DisplayBatteryinfo()
    {
        cout << " Battery Capacity is " << Capacity << " Battery 🔋 Type is " << BatteryType << endl;
    }
    
};


class SmartPhone
{
    private:
    Battery battery;
    string SmartPhoneName;
    double SmartPhonePrice;
    string SmartPhoneCompany;
    
    public:
    SmartPhone()
    {
        SmartPhoneName = " ";
        SmartPhonePrice = 0.0;
        SmartPhoneCompany = " ";
    }
    
    void SetName(string name)
    {
        SmartPhoneName = name;
    }
    
    void SetPrice(double price)
    {
        SmartPhonePrice = price;
    }
    
    void SetCompany(string company)
    {
        SmartPhoneCompany = company;
    }
    
    
    void Initialize(SmartPhone * smartphone,int Totalphone)
    {
        string Smartphonename;
        double smartphoneprice;
        string  smartphonecompany;
        
       
        for(int i =0; i < Totalphone;i++)
         {
            
           cout << " Enter Smart Phone Name " << endl;
            cin >> Smartphonename;
            smartphone[i].SetName(Smartphonename);
            
           cout << " Enter Smart Phone Price " << endl;
           cin >> smartphoneprice;
           smartphone[i].SetPrice(smartphoneprice);
        
        
           cout << " Enter Smart Phone Company  " << endl;
           cin >> smartphonecompany;
           smartphone[i].SetCompany(smartphonecompany);
           
        
          double Capacity;
           cout << " Enter Capacity " << endl;
          cin >> Capacity;
        
         battery.SetCapacity(Capacity);
       }
             
         }
      
    
    string GetName()
    {
        return SmartPhoneName;
    }
    double GetPrice()
    {
        return SmartPhonePrice;
    }
    string GetCompany()
    {
        return SmartPhoneCompany;
    }
    
    void Display(SmartPhone * smartphone,int Totalphones)
    {
        for(int i =0; i < Totalphones;i++)
        {
            cout << " Smart Phone Name is " << smartphone[i].GetName() << " Smart phone Price is " << smartphone[i].GetPrice() << " Smart Phone Company is  " << smartphone[i].GetCompany() << endl;
            
        }
        battery.DisplayBatteryinfo();
        
    }
    
    
};

int main() 
{
    int Totalphone;
    cout << " Enter Total phone " << endl;
    cin >> Totalphone;
    SmartPhone * smartphone = new SmartPhone[Totalphone];
    smartphone->Initialize(smartphone,Totalphone);
    
    smartphone->Display(smartphone,Totalphone);
    
    delete [] smartphone;

    return 0;
}
// Q5
// 24k-0559 Bazil-Uddin-Khan 

#include <iostream>
using namespace std;

class TourGuide
{
    private:
    string Name;
    int YearsOfExperience;
    string Specialization;
    
    public:
    TourGuide()
    {
        Name= " ";
        YearsOfExperience = 0;
        Specialization = " ";
    }
    
    TourGuide(string name, int yearexperience,string specialization)
    {
        Name = name;
        YearsOfExperience = yearexperience;
        Specialization = specialization;
        
    }
    
    string GetName()
    {
        return Name;
    }
    
    string GetSpecialization()
    {
        return Specialization;
    }
    
    int TotalYears()
    {
        return YearsOfExperience;
    }
    
    void DisplayInfo()
    {
        cout << " Tour Guide  Name Is " << Name << endl;
        cout << "  Tour Guide Is Specialized In  " << Specialization << endl;
        cout << " Tour Guide has " << YearsOfExperience << " years of Experience " << endl;
        
    }
    
    void InitializeDetails(string Name,int YearsOfExperience,string Specialization)
    {
        this->Name = Name;
        this->YearsOfExperience = YearsOfExperience;
        this->Specialization = Specialization;
    }
};


class TravelAgency
{
    private:
    TourGuide * tourguide = nullptr;
    string AgencyName;
    long AgencyContactNo;
    
    public:
    TravelAgency(int TotalGuides,string AgencyName, long AgencyContactNo)
    {
        if(tourguide == nullptr)
        {
            tourguide = new TourGuide[TotalGuides];
           this->AgencyName = AgencyName;
           this->AgencyContactNo = AgencyContactNo;
        }
    }
    
    TravelAgency(string Agencyname,double agencycontactno)
    {
        AgencyName = Agencyname;
        AgencyContactNo = agencycontactno;
    }
    
    void DisplayDetails(int TotalElements)
    {
        cout << " Travel Agency Deatils is " << endl;
        
        
        
        cout << " Travel Agency Name Is " << AgencyName << " Ttavel Agency Contact No is " << AgencyContactNo << endl;
        
        cout << " Travel Guide  Details are that are been hired " << endl;
        
        string Travelguidename;
        int Yearsexperience;
        string specialization;
        
        cin.ignore();
        for(int i = 0; i < TotalElements;i++)
        {
            
            
            cout << " Travel Guide  Name is " << endl;
            
            getline(cin,Travelguidename);
            
            cout << " Travel Guide Specialization is " << endl;
            
            getline(cin,specialization);
            
            cout << " Enter Travel Guide Total Experience " << endl;
            cin >> Yearsexperience;
            cin.ignore();

            tourguide[i].InitializeDetails(Travelguidename,Yearsexperience,specialization);
        }
        
        for(int i = 0; i < TotalElements;i++)
        {
            tourguide[i].DisplayInfo();
        }
    }
    
    
    ~TravelAgency()
    {
       delete[] tourguide;
       
    }
};
int main()
{
    
    cout << " Welcome To Travel Agency " << endl;
    
    int Totalelements;
    cout << " Enter TotalGuides of Agency " << endl;
    cin >> Totalelements;
    
    TravelAgency travel(Totalelements,"Tcs",9287654321);
    travel.DisplayDetails(Totalelements);

    return 0;
}
// Q6
// 24k-0559 Bazil-Uddin-Khan

#include <iostream>
using namespace std;

class Movie
{
    string Title;
    string Director;
    double Duration;
    
    public:
    Movie()
    {
        Title = " ";
         Director = " " ;
         Duration = 0;
    }

     Movie(string Title,string Director,int Duration)
    {
        this->Title = Title;
         this->Director =  Director;
         this->Duration = Duration;
    }

      void SetAttributes()
      {
               string title;
               cout << " Enter Title " << endl;
               cin >> title;
               Title = title;
               string director;
                cout << " Enter Director " << endl;
               cin >> director;
               Director = director;
 
               int duration;
                cout << " Enter Duration Of Movie  " << endl;
               cin >> duration;
               Duration = duration;


  
      }

    
     void MovieDetails()
     {


      cout << " Title is " << Title <<  " Director is " << Director << " Duration is " << Duration << endl;
   
     }
 
    string GetDirector()
     {

              return Director;
     }
    string GetTitle()
    {

              return Title;
    }

    int GetDuration()
    {
      return Duration;

    }
    
};

class Cinema
{
private:
       string CinemaName;
       Movie * movie = nullptr;
 public:
       Cinema()
       {
          CinemaName = " ";
       }

       Cinema(string CinemaName,int TotalMovies)
       {
         this->CinemaName = CinemaName;
         movie = new Movie[TotalMovies];

       }


      void AddMovieinCinema(int TotalMovies)
      {
           for(int i =0; i < TotalMovies;i++)

           {
                  movie[i].SetAttributes();
            }

        }
    
        void DisplayCinemasMovie(int TotalMovies)
        {
             cout << " Cinema Name Is " << CinemaName << endl;
             for(int i =0; i < TotalMovies;i++)
             {
                 cout << " Cinema " << i+1 << " Movie Title  is " << movie[i].GetTitle() << " Movie Director is " << movie[i].GetDirector() << " Movies Duration is " << movie[i].GetDuration() << endl;
              }

        }
        ~Cinema()
        {
            delete [] movie;
        }

};

int main()
{
    int TotalMovies;
    cout << " Enter Total Movies In Cinema " << endl;
    cin >> TotalMovies;
      string CinemaName;
      cout << " Enter Cinema Name is " << endl;
      cin >> CinemaName;
     Cinema cinema(CinemaName,TotalMovies);
    cinema.AddMovieinCinema(TotalMovies);
    cinema.DisplayCinemasMovie(TotalMovies);

    return 0;
}
//Q7
//24k-0559 Bazil-Uddin-Khan

#include <iostream>
using namespace std;

class Product
{
    string UniqueName;
    string ProductId;
    double Price;
    
    public:
    Product()
    {
          UniqueName = " ";
          ProductId    = " " ;
          Price = 0;
    }

    Product(string UniqueName,string ProductId ,double Price)
    {
        this->UniqueName = UniqueName;
         this->Price =  Price;
         this->ProductId = ProductId;
    }

      void SetAttributes()
      {
               string uniquename;
               cout << " Enter Name of Product  " << endl;
               cin >> uniquename;
               UniqueName  = uniquename;
               string productid;
                cout << " Enter Product id " << endl;
               cin >> productid;
               ProductId = productid;
 
               double price;
               cout << " Enter Price Of Product  " << endl;
               cin >> price;
               Price = price;
  
      }
      
      
      void SetName(string name)
      {
          UniqueName = name;
      }
      
      
      void SetPrice(double price)
      {
          Price = price;
      }
    
      
      void SetId(string id)
      {   
          ProductId = id;
          
      }
     void ProductDetails()
     {


      cout << " Product Name is " << UniqueName <<  " Product id is  " << ProductId  << " Price is  is " << Price <<  endl;
   
     }
 
    string GetName()
    {

              return UniqueName;
    }
    double GetPrice()
    {

              return Price;
    }

    string GetId()
    {
      return ProductId;

     }
    
};

class Inventory
{
private:
       string InventoryName;
       Product * product = nullptr;
 public:
       Inventory()
       {
           InventoryName = " ";
       }

       Inventory(string InventoryName,int Totalproducts)
       {
         this->InventoryName = InventoryName;
         product = new Product[Totalproducts];
       }



      void AddProductinInventory(int Totalproducts)
      {
           for(int i =0; i < Totalproducts ;i++)

           {
                product[i].SetAttributes();
            }

        }
        
        void DisplayProduct(int i)
        {
             

           cout << " Product  " << i+1 << " Product Name  is " << product[i].GetName() << " Product id " << product[i].GetId() << " Price is  " << product[i].GetPrice() << endl;
 

        }
        
        void Sort(int Totalproducts)
        {
          for (int i = 0; i < Totalproducts - 1; i++)
            {
               for (int j = 0; j < Totalproducts - i - 1; j++)
                {
                  if (product[j].GetPrice() > product[j + 1].GetPrice())
                  {
                
                    Product temp = product[j];
                    product[j] = product[j + 1];
                    product[j + 1] = temp;
                  }
                }
            }


        cout << "Products sorted by price in  ascending order" << endl;
        for (int i = 0; i < Totalproducts; i++)
         {
           DisplayProduct(i);
        }
     }
        
        void SearchInInventory(int Totalproducts)
        {
            string Productname;
            cout << " Enter Product Name To Be Searched " << endl;
            cin >> Productname;
            int Found = -1;
            for(int i =0; i < Totalproducts;i++)
            {
                if(Productname == product[i].GetName())
                {    
                    DisplayProduct(i);
                    Found = 1;
                    break;
                }
            }
            if (Found != 1)
            {
                cout << " Sorry But Product Not Found " << endl;
            }
        }
    


    ~Inventory()
    { 
        delete [] product;
    }

};

int main()
{
    int Totalproducts;
    cout << " Enter Total Products In Inventory " << endl;
    cin >> Totalproducts;
    string InventoryName;
    cout << " Enter Inventory Name is " << endl;
    cin.ignore();
    getline(cin,InventoryName);
    Inventory inventory(InventoryName,Totalproducts);
    inventory.AddProductinInventory(Totalproducts);
    inventory.SearchInInventory(Totalproducts);
    inventory.Sort(Totalproducts);

    return 0;
}
