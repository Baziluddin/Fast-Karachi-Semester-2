// 24K-0559 BAZIL-UDDIN-KHAN
#include <iostream>
#include<cstring>
#include<string>
using namespace std;


class Routes
{
    private:
    string Routes[24] = {"Roùte2","Route3","Route3B","Route4","Route4B","Route5","Route5B","Route6","Route6B","Route7","Route8","Route9","Route17","Route18","Route20","Route22","Route23","Route23B","Route24","Route24B","Route25","Route25B","Route26","Route26B"};
    string RoutesPickUp[24] = {"Saffora","SindhBaloach","KamranChorangi","Jamalipull","Maskan","PowerHouse","DolminMall","bardadari","Golbarq","Donisel","clifton","Bahria","Dha","UniversityRoad","Korangi","lyaripull","Motimehal","Sheefaisal","Balochistansajji","Kdm","Mehran","Lalqila","Tariqroad","Balochistanx"};
    
    public:
    int CheckRoute(string Route)
    {
        
        for(int i=0; i < 24; i++)
        {
            if(Routes[i] == Route)
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
            if(Routes[i] == RouteNumber)
            {
                string val = RoutesPickUp[i];
                return(val);
            }
        }
        return " ";
    }
    
    
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
        if(Fees <= fees)
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
    
    string GetStatus()
    {
        return CardStatus;
    }
    
    
};

class Student
{
    private:
    string StudentId;
    string StudentName;
    string StudentContactNumber;
    string BatchNo;
    string SemesterYear;
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
        SemesterYear = " ";
        RouteNumber = " ";
        StopName = " ";
        CardNumber =" ";
    }
    Student(string StudentId,string StudentName,string StudentContactNumber, string BatchNo,string SemesterYear,string RouteNumber,string StopName,string CardNumber)
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
    
    void DisplayAttendance(int Totalstudents)
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
         
         cout << " Memory Released " << endl;
         delete [] Attendancechecker;
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

   string userid;
   cout << " Enter User id whose Attendance is to be noted " << endl;
   cin >> userid;
   
   Attendance attendance(TotalStudents,student);
   attendance.SetCard(userid,TotalStudents);
   attendance.DisplayAttendance(TotalStudents);
   
   delete [] student;

    return 0;
}