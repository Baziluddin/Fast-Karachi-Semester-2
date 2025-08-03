// 24K-0559 BAZIL-UDDIN-KHAN 
#include <iostream>
#include<cstring>
#include<string>
using namespace std;

class Person
{
    protected:
    string PersonName;
    string DateOfJoining;
    string email;
    string phoneNumber;
    
    public:
    Person(){}
    
    Person(string name,string date,string Email,string number) : PersonName(name),DateOfJoining(date),email(Email),phoneNumber(number)
    {}
    
    virtual  void DisplayInfo()
    {
        cout << " Person Details Are " << endl;
        cout << "Person Name is = " << PersonName << endl;
        cout << "Person Date Of Joining  is = " << DateOfJoining << endl;
        cout << "Person Email is = " << email << endl;
        cout << "Person Phone Number  is = " << phoneNumber << endl;
        
    }
    
    bool operator==(const Person& other) const
    {
    return this->email == other.email;
    }
    
};


class Routes
{
    private:
    string Route[24] = {"Roùte2","Route3","Route3B","Route4","Route4B","Route5","Route5B","Route6","Route6B","Route7","Route8","Route9","Route17","Route18","Route20","Route22","Route23","Route23B","Route24","Route24B","Route25","Route25B","Route26","Route26B"};
    string RoutesPickUp[24] = {"Saffora","SindhBaloach","KamranChorangi","Jamalipull","Maskan","PowerHouse","DolminMall","bardadari","Golbarq","Donisel","clifton","Bahria","Dha","UniversityRoad","Korangi","lyaripull","Motimehal","Sheefaisal","Balochistansajji","Kdm","Mehran","Lalqila","Tariqroad","Balochistanx"};
    
    public:
    int CheckRoute(string Routeu)
    {
        
        for(int i=0; i < 24; i++)
        {
            if(Route[i] == Routeu)
            {
                
                
                return 1;
            }
        }
    
      cout << " Not Found " << endl;
      return -1;
        
    }
    
    string GetRouteName(string RouteNumber)
    {
        for(int i =0; i < 24;i++)
        {
            if(Route[i] == RouteNumber)
            {
                string val = RoutesPickUp[i];
                return(val);
            }
        }
        return " ";
    }
    
    void DisplayInfo()
    {
        cout << " Routes Details Are " << endl;
        for( int y =0; y< 24;y++)
        {
            cout << Route[y] << "  ";
        }
        
        cout<< endl;
        
        cout << " Routes Stops Are " << endl;
         for(int y =0; y< 24;y++)
        {
            cout << RoutesPickUp[y] << "  ";
        }
        
        
        
    }
    bool operator==(const Routes& other) const
    {
       for (int i = 0; i < 24; i++) 
      {
        if (this->Route[i] != other.Route[i] || this->RoutesPickUp[i] != other.RoutesPickUp[i]) 
        {
            return false;  // Return false if any mismatch is found
         }
      }
       return true; 
   }// Return true if all elements match

    

    
};

class PaymentFee
{
    private:
    double Fees;
    string CardStatus;
    
    public:
    PaymentFee()
    {
        Fees =0;
        CardStatus = "NotPaid";
    }
    PaymentFee(double Fee)
    {
        this->Fees = Fee;
    }
    
    int PaymentFees(double fees)
    {
        if(Fees == fees)
        {
            this->Fees = Fees;
            this->CardStatus = "Paid";
            cout << " Payment Susssfully made " << endl;
            return 1;
        }
        else
        {
            cout << " Payment Not Recieved " << endl;
            return 0;
        }
        
    }
    
    void DisplayInfo()
    {
        cout << " Fees Status Is  " << endl;
        cout << " Fees Is " << Fees << endl;
        cout << " Card Status Is " << CardStatus << endl;
    }
    
    string GetStatus()
    {
        return CardStatus;
    }
    
    
};

class Student : public Person
{
    private:
    string StudentId;
    string StudentName;
    string StudentContactNumber;
    string BatchNo;
    string SemesterYear;//Fall,spring
    string RouteNumber;
    string StopName;
    static int TotalStudents;
    string CardNumber;
    
    Routes route;
    
    public:
    Student()
    {
        StudentId = " ";
        StudentName = " ";
        StudentContactNumber = " ";
        BatchNo = " ";
        SemesterYear = " ";//Fall,spring
        RouteNumber = " ";
        StopName = " ";
        CardNumber =" ";
    }
    Student(string StudentId,string StudentName,string StudentContactNumber, string BatchNo,string SemesterYear,string RouteNumber,string StopName,string CardNumber,string name,string date,string Email,string number) : Person(name,date,Email,number)
    {
        this->StudentId = StudentId;
        this->StudentName = StudentName;
        this->StudentContactNumber = StudentContactNumber;
        this->BatchNo = BatchNo;
        this->SemesterYear = SemesterYear;
        this->RouteNumber = RouteNumber;
        this->StopName = StopName;
        this->CardNumber = CardNumber;
    }
    
    void SetAttributes(string StudentId,string StudentName,string StudentContactNumber, string BatchNo,string SemesterYear,string RouteNumber,string StopName,string CardNumber)
    {
        this->StudentId = StudentId;
        this->StudentName = StudentName;
        this->StudentContactNumber = StudentContactNumber;
        this->BatchNo = BatchNo;
        this->SemesterYear = SemesterYear;
        this->RouteNumber = RouteNumber;
        this->StopName = StopName;
        this->CardNumber = CardNumber;
    }
    
    void StudentRegisteration()
    {
        string StudentId;
        cout << " Enter Your Fast Id like this(21k-0678) " << endl;
        cin >> StudentId;
        
        string StudentName;
        cout << " Enter Your Student Name " << endl;
        cin.ignore();
        getline(cin,StudentName);
        
        string StudentContactNumber;
        cout << " Enter Student Contact Number " << endl;
        
        cin >> StudentContactNumber;
        string BatchNo;
        cout << " Enter Batch No like 2022 " << endl;
        cin >> BatchNo;
        
        string SemesterYear;
        cout << " Enter Semester(Fall/Spring)Year like Fall2024 ";
        cin >> SemesterYear;
        
        string RouteNumber;
        cout << " Enter Route Number. Note Every Route Number start with (RouteNo) No represents The number of route like Route1 ,Route24 etc " << endl;
        cin >> RouteNumber;
    
        
    
        PaymentFee payment(21200);
        int Routenumber = route.CheckRoute(RouteNumber);
        if(Routenumber != -1)
        {
            this->RouteNumber = RouteNumber;
            string RouteName = route.GetRouteName(RouteNumber);
            if(RouteName != " " && payment.GetStatus() != "NotPaid")
            {
                this->StopName = RouteName;
                cout << " Succesfully Registered " << endl;
                CardNumber = ("0"+ to_string(TotalStudents));
                SetAttributes(StudentId,StudentName,StudentContactNumber,BatchNo,SemesterYear,RouteNumber,RouteName,CardNumber);
                
                TotalStudents++;
                
            }
            else
            {
                cout << " Failed To Register " << endl;
            }
            
            
        }
        else
        {
            cout << " Route Not Found " << endl;
        }
    
    }
    
    string GetContactNumber() const
    {
        return StudentContactNumber;
    }
    
    string GetName() const
    {
        return StudentName;
    }
    
    static int GetTotalStudents()
    {
        return TotalStudents;
    }
    
    string GetUserId() const
    {
        return StudentId;
    }
    
    void DisplayInfo()
    {
        cout << " Student Details  Is  " << endl;
        cout << " StudentId  Is  " << StudentId <<  endl;
        cout << " Student Name is " << StudentName << endl;
        cout << " Student ContactNumber  Is  "<< StudentContactNumber << endl;
       cout << " Student BatchNo  Is  " << BatchNo << endl;
       cout << " Student SemesterYear  Is  " << SemesterYear << endl;
       cout <<"Route Number Is " <<  RouteNumber << "And Stop Name Is "  << StopName << " And Card Number Is " << CardNumber << endl;
    }
    
    bool operator==(const Student& other) const 
    {
       return this->StudentId == other.StudentId;
    }
};



int Student :: TotalStudents =0;

class Attendance
{
    private:
    int TotalAttendance;
    Student * student = nullptr;
    int * Attendancechecker;
    
    public:
    Attendance(int Totalstudents,Student * students)
    {
       
        Attendancechecker = new int [Totalstudents];
        TotalAttendance =0;
        student = students;
        for(int i =0; i < Totalstudents;i++)
        {
            Attendancechecker[i] =0;
        }
    }
    
    void SetCard(string UserId,int Totalstudents)
    {
        PaymentFee card;
        string status = card.GetStatus();
        for(int j =0; j < Totalstudents;j++)
        {
            if(student[j].GetUserId() == UserId)
            {
               TotalAttendance++;
               Attendancechecker[j] = TotalAttendance;
             }
            
        }
        
        
        
    }
    
    void DisplayInfo(int Totalstudents)
    {
        for(int i =0; i < Totalstudents;i++)
        { 
            cout << " Attendance is of " << i+1 << " Student is " << endl;
            
            cout << Attendancechecker[i] << endl;
            cout << " Name is " << student[i].GetName() << endl;
            
            cout << " Id is " << student[i].GetUserId()<<endl;
            
            cout << " Contact Number is " << student[i].GetContactNumber() << endl;
            
        }
    }
    

    ~Attendance()
    {
         
         delete [] Attendancechecker;
    }
    
};

class Teacher : public Person,public PaymentFee, public Routes
{
    private:
    double MonthlyFees;
    double Salary;
    
    string RouteNumber;
    
    
    public:
    Teacher(){}
    
    Teacher(string name,string date,string Email,string number,double fees,string Routenumber,double salary) : MonthlyFees(fees),Person(name,date,Email,number),RouteNumber(Routenumber),PaymentFee(fees),Salary(salary)
    {}
    
    void DisplayInfo()
    {
        cout << endl;
        cout << " _Teacher Details Is_ " << endl;
        cout << " Teacher Name Is " << PersonName << endl;
        cout << " Teacher Email Is " << email << endl;
        cout << " Teacher Date Of 📅 Joining Is " << DateOfJoining << endl;
        cout << " Teacher Fees Is " << MonthlyFees << endl;
        cout << " Teacher Number Is " << phoneNumber << endl;
    }
    
    void TeacherRouteRegisteration()
    {
        PaymentFee payment(MonthlyFees);
        int result = PaymentFees(MonthlyFees);
        if(result !=0)
        {
        
           int Routenumber = CheckRoute(RouteNumber);
           if(Routenumber != -1)
           {
              string RouteName = GetRouteName(RouteNumber);
              if(RouteName != " " && payment.GetStatus() != "NotPaid")
              {
                
                cout << " Teacher Succesfully Registered " << endl;
                
              }
              else
              {
                cout << "Teacher Failed To Register " << endl;
              }
            
            
           }
           else
           {
            cout << " Route Not Found " << endl;
            }
        }
        
        else
        {
            cout << " Sorry Teacher But You Cannot Avail Transport Please Clear Fees " << endl;
        }
    }
    
};


class StaffMembers : public Person,public PaymentFee,public Routes
{
    private:
    double salary;
    string RouteNumber;
    
    public:
    StaffMembers()
    {
        salary =0.0;
        RouteNumber = " ";
    }
    
    StaffMembers(double Salary,double fees,string name,string date,string Email,string number,string Route) : salary(Salary),Person(name,date,Email,number),RouteNumber(Route),PaymentFee(fees)
    {
        
    }
    
    void DisplayInfo()
    {
        cout << endl;
        cout << " _Staff Info Is_ " << endl;
        cout << " Staff Name Is " << PersonName << endl;
        cout << " Staff Email Is " << email << endl;
        cout << "  Staff Date Of 📅 Joining Is " << DateOfJoining << endl;
        cout << " Stafff Fees Is " << salary << endl;
        cout << " Staff Number Is " << phoneNumber << endl;
    }
  

    void StaffRouteRegisteration()
    {
        PaymentFee payment(salary);
        int result = payment.PaymentFees(salary);
        
        if(result !=0)
        {
           cout << " Status " << payment.GetStatus() << endl;
           int Routenumber = CheckRoute(RouteNumber);
           if(Routenumber != -1)
           {
              string RouteName = GetRouteName(RouteNumber);
              if(RouteName != " " && payment.GetStatus() != "NotPaid")
              {
                
                cout << "Staff Succesfully Registered " << endl;
                
              }
              else
              {
                cout << "Staff Failed To Register " << endl;
              }
            
            
           }
           else
           {
            cout << " Route Not Found " << endl;
            }
        }
        
        else
        {
            cout << " Sorry Staff you  Cannot Avail Transport Please Clear Fees " << endl;
        }
    }
    
};

int main() 
{
    
    
   cout << " Welcome To Fast Bus Transportation System " << endl;
   cout << endl;
   
   int TotalStudents;
   cout << " Enter Total Students who want to make there Card " << endl;
   cin >> TotalStudents;
  
   Student * student = new Student[TotalStudents];
   for(int i =0; i < TotalStudents;i++)
   {
       student[i].StudentRegisteration();
       
   }
   
   Person *  person1 = new Person("Ali", "01-01-2023", "ali@fast.edu", "03001234567");
   Person * person2 = new Person("li", "01-01-2023", "ali@fast.edu", "03001234567");

   string userid;
   cout << " Enter User id whose Attendance is to be displayed " << endl;
   cin >> userid;
   
   Attendance attendance(TotalStudents,student);
   attendance.SetCard(userid,TotalStudents);
   attendance.DisplayInfo(TotalStudents);
   
   Teacher  teacher1("John Doe", "01-02-2023", "johndoe@fast.edu", "03001234567", 5000, "Route3", 100000);
   
   Person * person; // For Dynamic/LateBinding
   person = &teacher1;
   
    cout << endl;
    teacher1.TeacherRouteRegisteration();
    person->DisplayInfo();
    
    cout << endl;
    
    StaffMembers  staffmember1(34096,120,"Qasim","3-45-2099","12@nu","34","Route24");
    cout << endl;
    
    Person * Pes; // For Dynamics / Late Binding
    Pes = & staffmember1;
    
    staffmember1.StaffRouteRegisteration();
    Pes->DisplayInfo();
    
    cout << endl;
    cout <<" Operator Checking Outcomes Are "<< endl;
    
    Routes route1, route2;
    if (route1 == route2)
    {
     cout << "Both routes are the same." << endl;
    } 
    else 
    {
      cout << "Routes are different." << endl;
   }
   
   cout << endl;
   
   

   if (person1 == person2)
   {
    cout << "Both persons are the same." << endl;
    person2->DisplayInfo();
   } 
   else
   {
    cout << "Persons are different." << endl;
    person1->DisplayInfo();
    person2->DisplayInfo();
   }
   
   
   
   if (student[0] == student[1])
   {
    cout << "Both Students are the same." << endl;
   } 
   else
   {
    cout << "Students are different." << endl;
    
   }
   
   
   
   
   delete [] student;

    return 0;
}