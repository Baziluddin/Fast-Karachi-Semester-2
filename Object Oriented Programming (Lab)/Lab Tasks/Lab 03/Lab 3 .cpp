// 24K-0559 BAZIL UDDIN KHAN 
#include <iostream>
using namespace std;

class MarkerPen
{
    private:
    string Brand;
    string Colour;
    int Inklevel;
    string Refeliblity;
    
    public:
    void SetBrand(string brand)
    {
        Brand = brand;
    }
    
    void SetColour(string colour)
    {
        Colour = colour;
    }
    
    void SetInklevel(int level)
    {
        Inklevel = level;
    }
    
    void SetRefeblity(string refebelity )
    {
       Refeliblity = refebelity;
    }
    
    void Descreaseink()
    {
        if(Inklevel > 0)
        {
            Inklevel--;
        }
        else
        {
            cout << " Inklevel Ended " << endl;
        }
    
    }
    
    void Setrefiliblity(int level)
    {
        if(Refeliblity == "Yes")
        {
            Inklevel = level;
        }
        
        
    }
    
    string Getbrand()
    {
        return Brand;
    }
    
    string Getcolour()
    {
        return Colour;
    }
    
    int Getlevel()
    {
        return Inklevel;
    }
    
    string  Getrefeblity()
    {
        return Refeliblity;
    }
    
    void Displayinfo()
    {
        cout << " Brand is " << Brand << 
                " Colour is " << Colour << " Ink level " << Inklevel << " Refeblity is " << Refeliblity << endl;
    }
    
};

int main() 
{
    string brand;
    cout << " Enter Brand " << endl;
    cin >> brand;
    string colour;
    cout << " Enter Colour " << endl;
    cin >> colour;
    int level;
    cout << " Enter ink level " << endl;
    cin >> level;
    string refeblity;
    cout <<  "  Enter in (Yes/No) the refeblity status of marker " << endl;
    cin >> refeblity;
    
    
    MarkerPen markerpen;
    markerpen.SetBrand(brand);
    markerpen.SetColour(colour);
    markerpen.SetInklevel(level);
    markerpen.SetRefeblity(refeblity);
    
    for(int i =0; i < 7; i++)
    {
        markerpen.Descreaseink();
        if(markerpen.Getlevel() == 0)
        {
            int Level;
            cout << " Tell refeblity level " << endl;
            cin >> Level;
            markerpen.Setrefiliblity(Level);
        }
    }
    markerpen.Displayinfo();
    return 0;
}

// Q2
// 24K-0559 BAZIL-UDDIN-KHAN
#include <iostream>
using namespace std;

class TeaMug
{
  private:
  string Brand;
  string Colour;
  int Capacity;
  int Currentfilllevel;
  
  public:
  
  void SetBrand(string brand)
  {
      Brand = brand;
  }
  void SetColour(string colour)
  {
      Colour = colour;
  }
  void SetCapacity(int capacity)
  {
      Capacity = capacity;
  }
  void SetCurrentfilllevel(int currentlevel)
  {
      Currentfilllevel = currentlevel;
  }
  
  string GetBrand()
  {
      return Brand;
  }
  string GetColour()
  {
      return Colour;
  }
  int Getcapacity()
  {
      return Capacity;
  }
  int GetCurrentfilllevel()
  {
      return Currentfilllevel;
  }
  
  int SipTea()
  {
      if(Currentfilllevel  != 0)
      {
          Currentfilllevel--;
          cout << " Your mug has Current Mug level : " << Currentfilllevel << endl;
          return 1;
      }
      else
      {
          return 0;
      }
  }
  
  void Refill()
  {
      if(Currentfilllevel == 0)
      {
          Currentfilllevel = Capacity;
          cout << " Succesfully Refiled " << " " << " Ink level is now Reset to  " << Capacity <<  endl;
      }
  }
};

int main()
{
    TeaMug Teamug;
    string Brand;
    cout << " Enter Mug Brand " << endl;
    cin >> Brand;
    
    string Colour;
    cout << " Enter Mug  colour " << endl;
    cin >> Colour;
    
    int Capacity;
    cout << " Enter Mug Capacity " << endl;
    cin >> Capacity;
    
    int Currentlevel;
    cout << " Enter Mug  Current level  " << endl;
    cin >> Currentlevel;
    
    Teamug.SetBrand(Brand);
    Teamug.SetColour(Colour);
    Teamug.SetCapacity(Capacity);
    Teamug.SetCurrentfilllevel(Currentlevel);
    for(int i =0; Teamug.Getcapacity() != 0 ; i++)
    {
        int result = Teamug.SipTea();
        if(result == 0)
        {
            Teamug.Refill();
            break;
        }
        
    }
    


    return 0;
}

// Q3
// 24k-0559 BAZIL-UDDIN-KHAN
#include <iostream>
using namespace std;

class Planner
{
    private:
    string Array[12][30];
    
    public:
    void EnterPlans()
    {
        
        
        for(int i =0; i < 12; i++)
        {
            string ChoiceMonth;
            cout << " Do you want To enter Tasks in this Month.  Enter In (Yes/No).  Month:  " << i+1  << endl;
            cin >> ChoiceMonth;
            if(ChoiceMonth == "Yes")
            {
                 for(int j =0; j < 30; j++)
                {
                    string WantTask;
                    cout << " Enter in (Yes/No) if You want to add task in month " << i+1 << endl;
                    cin >> WantTask;
                    
                    if(WantTask == "Yes")
                    {
                        string Task;
                        cout << " Enter Task " << endl;
                        cin >> Task;
                        Array[i][j] = Task;
                        
                    }
                    else
                    {
                        Array[i][j] = " ";
                        string Result;
                        cout << " If you want To add any other Tasks in the month.Enyer in (Yes/No)  " << endl;
                        cin >> Result;
                        if(Result == "No")
                        {
                            break;
                        }
                    }
                }
                
            }
           
        }
    }
    
    void ReviewPlans()
    {
        for(int i =0; i < 12;i++)
        {
            cout << " The Task for month " << i+1 << " are " << endl;
            for(int j =0; j < 30; j++)
            {
                cout << Array[i][j] << " ";
            }
            cout << endl;
        }
    }
    void Updatetask()
    {
        int Monthnum;
        cout << " Enter Month (1-12) " << endl;
        cin >> Monthnum;
        if(Monthnum > 0 && Monthnum <13)
        {
            string Task;
            cout << " Enter Task To Update " << endl;
            cin >> Task;
            for(int i =0; i < 12;i++)
            {
               if(Monthnum == i+1)
              {
                for(int j =0; j < 30; j++)
                 {
                     if(Array[i][j] == Task)
                     {
                      string Newtask;
                      cout << " Enter New    Task " << endl;
                      cin >> Newtask;
                      Array[i][j] = Newtask;
                      
                     }
                
                  }
               }
            }
            
        }
        else
        {
            cout << " Invalid Input " << endl;
        }
    }
    
    void RemoveTask()
    {
        int Monthnum;
        cout << " Enter Month (1-12) " << endl;
        cin >> Monthnum;
        if(Monthnum > 0 && Monthnum < 13)
        {
            string Task;
            cout << " Enter Task " << endl;
            cin >> Task;
            for(int i =0; i < 12;i++)
            {
               if(Monthnum == i+1)
               {
                  for(int j =0; j < 30; j++)
                  {
                      if(Array[i][j] == Task)
                     {
                     Array[i][j] = " ";
                     }
                
                   }
               }
            }
            
        }
        else
        {
            cout << " Invalid Input " << endl;
        }
        
           
        
    }
};




int main()
{
    cout << " Welcome To Your Planner Management System " << endl;
    
    Planner planner;
    while(1)
    {
        string Choice;
        cout << " Enter Your Choice (Add/Remove/Update/Display/Exit) " << endl;
        cin >> Choice;
        
        if(Choice == "Add")
        {
           planner.EnterPlans();
        }
        else  if(Choice == "Update")
        {
         planner.Updatetask();
        }
       else if(Choice == "Remove")
        {
         planner.RemoveTask();
        }
       else if(Choice == "Display")
       {
          planner.ReviewPlans();
       }
       
       else if(Choice == "Exit")
       {
           break;
       }
       
       else
       {
        cout << " Invalid " << endl;
       }
        
    }
    
    
   

    return 0;
}

// Q4
// 24k - 0559 Bazil uddin khan
#include <iostream>
using  namespace std;

class Laptop
{
    private:
    string Brand;
    string Model;
    double Processing;
    double Storage;
    double Ram;
    
    public:
    
    void AyeshaOnLaptops()
    {
        cout << " Ayesha Laptop on " << endl;
    }
    
    void BilalOnLaptops()
    {
        cout << " Bilal Laptop on " << endl;
    }
    
    void AyeshaOffLaptops()
    {
        cout << " Ayesha Laptop off " << endl;
        
    }
    
    void BilalOffLaptops()
    {
        cout << " Bilal Laptop off " << endl;
        
    }
    
    string GetBrand()
    {
        return Brand;
    }
    
    string GetModel()
    {
        return Model;
    }
    
    double GetProcessing()
    {
        return Processing;
    }
    
    double GetStorage()
    {
        return Storage;
    }
    
    double GetRam()
    {
        return Ram;
        
    }
    
    void StartProgram()
    {
        cout << " Start The Program " << endl;
    }
    
    void EndProgram()
     {
        cout << " Stop The Program " << endl;
    }
    
    void SetAllattributes(string brand,
    string model,double processing, double storage,double ram)
    {
        Brand = brand;
        Model = model;
        Processing = processing;
        Storage = storage;
        Ram = ram;
        
    }
    void EnterDetails(Laptop & Ayesha , Laptop & Bilal)
    {
        cout << " Enter Deatils For Ayesha " << endl;
        string brand;
        cout << " Enter Brand of Ayesha laptop " << endl;
        cin >> brand;
        
        string model;
        cout << " Enter Model of Ayesha laptop " << endl;
        cin >> model;
        
        double processing;
        cout << " Enter Processing of Ayesha laptop " << endl;
        cin >> processing;
        
        double storage;
        cout << " Enter Storage of Ayesha laptop " << endl;
        cin >> storage;
        
        double ram;
        cout << " Enter Ram of Ayesha laptop " << endl;
        cin >> ram;
        
        Ayesha.SetAllattributes(brand,model,processing,storage,ram);
        
        
        cout << " Enter Deatils For Bilal " << endl;
        string BRAND;
        cout << " Enter Brand of Bilal laptop " << endl;
        cin >> BRAND;
        
        string MODEL;
        cout << " Enter Model of Bilal laptop " << endl;
        cin >> MODEL;
        
        double PROCESSING;
        cout << " Enter Processing of BILAL laptop " << endl;
        cin >> PROCESSING;
        
        double STORAGE;
        cout << " Enter Storage of Bilal laptop " << endl;
        cin >> STORAGE;
        
        double RAM;
        cout << " Enter Ram of Bilal laptop " << endl;
        cin >> RAM;
        
        Bilal.SetAllattributes(BRAND,MODEL,PROCESSING,STORAGE,RAM);
        
    }
    void CheckSpecifications(Laptop Ayesha, Laptop Bilal)
    {
        if(Ayesha.GetBrand() == Bilal.GetBrand())
        {
            if(Ayesha.GetModel() == Bilal.GetModel())
            {
                cout << " Both have same Model " << endl;
            }
            else if(Ayesha.GetModel() > Bilal .GetModel())
            {
                 cout << " Ayesha has Advance Model " << endl;
            }
            else
            {
                cout << " Bilal has better Processing " << endl;
            }
        }
        
         if(Ayesha.GetRam() > Bilal.GetRam())
        {
            cout << " Ayesha laptop has better ram " << endl;
            if(Ayesha.GetProcessing() > Bilal.GetProcessing())
            {
                
               cout << " Ayesha laptop has better Processing power " << endl;
            }

        }
        
       if(Ayesha.GetRam()  < Bilal.GetRam())
        {
            cout << " Bilal laptop has better ram " << endl;
            if(Ayesha.GetProcessing() < Bilal.GetProcessing())
            {
               cout << " Bilal laptop has better Processing power " << endl;
            }
        }
    }
};
int main() 
{
   Laptop Ayesha;
   Ayesha.StartProgram();
   Ayesha.AyeshaOnLaptops();
   Laptop Bilal;
   Bilal.BilalOnLaptops();
   Ayesha.EnterDetails(Ayesha,Bilal);
   Ayesha.CheckSpecifications(Ayesha,Bilal);
   Ayesha.AyeshaOffLaptops();
   Bilal.BilalOffLaptops();
   Ayesha.EndProgram();
    return 0;
}
// Q5
// 24k-0559 BAZIL-UDDIN-KHAN
#include <iostream>
using namespace std;

class GroceryStore
{
    private:
    string ItemName;
    int Totalitems=0;
    double Prices;
    
    public:
    void SetItemName(string itemname)
    {
        ItemName = itemname;
    }
    
    string GetItemName()
    {
        return ItemName;
    }
    
    
    void SetTotalItems()
    {
        Totalitems++;
    }
    
    void SetPrices(double price)
    {
        Prices = price;
    }
    
    int GetTotalitems()
    {
        return Totalitems;
    }
    
    double GetPrice()
    {
        return Prices;
    }
    
    void AddnewItems(int TotalItems,GroceryStore * grocerrystore)
    {
        for(int i =0; i < TotalItems;i++)
        {
            string Name;
            cout << " Enter Name of item to be added " << endl;
            cin >> Name;
            Totalitems++;
            double price;
            cout << " Enter Price For Item "  << i+1 << endl;
            cin >> price;
            grocerrystore[i].SetTotalItems();
            grocerrystore[i].SetPrices(price);
            grocerrystore[i].SetItemName(Name);
        }
    }
    
    void Updateprices(int TotalItems,GroceryStore * grocerrystore)
    {
        string UpdateItem;
        cout << " Enter Item Whose Price is to be Updated " << endl;
        cin >> UpdateItem;
        double UpdatePrice;
        cout << " Enter Updated Price of item  " << endl;
        cin >> UpdatePrice;
        
        for(int i =0; i < TotalItems;i++)
        {
            if(grocerrystore[i].GetItemName() == UpdateItem)
            {
                grocerrystore[i].SetPrices(UpdatePrice);
            }
        }
    }
        
    void GenerateReciept(int TotalItems,GroceryStore * grocerrystore,int Totalpurchase)
        {
            double Totalprice =0;
            
            for(int j =0; j < Totalpurchase; j++)
            {
                double PriceTotal =0; 
                int Quantity =0;
                
                string ItemName;
                cout << " Enter Item that is Purchased " << endl;
                cin >> ItemName;
                
                
                
                for(int i =0; i < TotalItems;i++)
                {
                    if(grocerrystore[i].GetItemName() == ItemName)
                    {
                        Totalprice = Totalprice + grocerrystore[i].GetPrice();
                        PriceTotal = PriceTotal + grocerrystore[i].GetPrice();
                    Quantity++;
                    }
                }
                
            cout << " Item Name " << ItemName << " Price is " << PriceTotal << " Quantity Of Item is " << Quantity << endl;
            
            }
            cout << " Your Total Bill id " << Totalprice << endl;
        }
        
};

int main() 
{
    int TotalItems;
    string Choice;
    GroceryStore * grocerrystore;
    cout << " Welcome To Grocerry Management System " << endl;
    
    while(1)
    {
        cout << " Enter (Add/Exit/Update/Recipt) " << endl;
        cin >> Choice;
        if(Choice == "Add")
        {
            cout << " Enter Total Items to Add " << endl;
            cin >> TotalItems;
            grocerrystore = new GroceryStore[TotalItems];
            grocerrystore->AddnewItems(TotalItems,grocerrystore);
        }
       else if(Choice == "Update")
        {
            grocerrystore->Updateprices(TotalItems,grocerrystore);
        }
       else if(Choice == "Recipt")
        {
            int TotalItem;
            cout << " Enter Total Items Purchased " << endl;
            cin >> TotalItem;
            grocerrystore->GenerateReciept(TotalItems,grocerrystore,TotalItem);
            
            
        }
        
        else if(Choice == "Exit")
        {
            break;
        }
        
        else 
        {
            cout << " Invalid Entry try Again " << endl;
        }
        
    }
    
    delete [] grocerrystore;
    
    
    return 0;
}
