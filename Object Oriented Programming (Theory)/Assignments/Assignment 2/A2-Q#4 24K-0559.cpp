//Bazil-Uddin-Khan 24k-0559

#include <iostream>
using namespace std;



int ProduceHash(string password)
{
    int hash = 5381;
    for(char c : password) {
        hash = hash * 33 + c;
    }
    return hash;
}


class User
{
    
    protected:
    string name;
    string id;
    string email;
    int hashed_password;
    int Hashed;
    string Studentpermission[1] = {"sumbit assignment"};
    string Tapermission[2] = {"view projects", "manage_students"};
    string Proffesorpermission[2] = {"assign projects","full_lab_access"};
    string permissionlist;
    
    
    public:
    User()
    {
        name = " ";
        id = " ";
        email = " ";
        hashed_password =0;
        
    }
    User(string Name, string Id, string Email, string password,string list) 
    : name(Name), id(Id), email(Email),permissionlist(list), hashed_password(ProduceHash(password)) {}

    void displayinfo()
    {
        cout << " Name is " << name << endl;
        cout << " id is " << id << endl;
        cout << " Email is "<<email<< endl;
        cout << " Hashed password is " << hashed_password << endl;
        cout << " Permission list is " << permissionlist << endl;
    }
    
    bool authenticatepassword()
    {
        string password;
        cout << " Enter Password To Check Access: ";
        cin >> password;
        if (ProduceHash(password) == hashed_password)
        {
            cout << " Correct Password " << endl;
            return 1;
        }
        else
        {
            cout << " Wrong Password " << endl;
            return 0;
        }
    }
    
    void accesslab()
    {
        if(permissionlist == "STUDENT")
        {
            
            
            string taskS;
            cout << " Welcome Student. Enter Your Task " << endl;
            cin.ignore();
            getline(cin,taskS);
            
           
            if(taskS == Studentpermission[0])
            {
                cout << " Access Granted Succesfully " << endl;
            }
            else
            {
                cout << " Invalid Entry. Access rejected  " << endl;
                
            }
        }
        
        else if(permissionlist == "TA")
        { 
            string taskT;
            cout << " Welcome Ta. Enter Your Task " << endl;
            cin.ignore();
            getline(cin,taskT);
             if(taskT == Tapermission[0] || taskT == Tapermission[1])
            {
                cout << " Access Granted Succesfully " << endl;
            }
            else
            {
                cout << " Invalid Entry. Access rejected  " << endl;
                
            }
        }
        
        else if(permissionlist == "PROFESSOR")
        { 
            string taskP;
            cout << " Welcome Proffesor. Enter Your Task " << endl;
            cin.ignore();
            getline(cin,taskP);
            if(taskP == Proffesorpermission[0] || taskP == Proffesorpermission[1])
            {
                cout << " Access Granted Succesfully " << endl;
            }
            else
            {
                cout << " Invalid Entry. Access rejected  " << endl;
                
            }
        }
        else
        {
            cout << " Invalid Entry. Access rejected  " << endl;
        }
        
    }
    
    int Authentification(string Action)
    {
        if(permissionlist == "STUDENT")
        {
            
         if(Action == "sumbit assignment")
            {
                cout << " Access Granted Succesfully " << endl;
                return 1;
            }
            else
            {
                cout << " Invalid Entry. Access rejected  " << endl;
                return 0;
                
            }
        }
        
        else if(permissionlist == "TA")
        { 
            
             if(Action == Tapermission[0] || Action == Tapermission[1])
            {
                cout << " Access Granted Succesfully " << endl;
                return 1;
            }
            else
            {
                cout << " Invalid Entry. Access rejected  " << endl;
                return 0;
                
            }
        }
        
        else if(permissionlist == "PROFESSOR")
        { 
            
            if(Action == Proffesorpermission[0] || Action == Proffesorpermission[1])
            {
                cout << " Access Granted Succesfully " << endl;
                return 1;
            }
            else
            {
                cout << " Invalid Entry. Access rejected  " << endl;
                return 0;
                
            }
        }
        else
        {
            cout << " Invalid Entry. Access rejected  " << endl;
            return 0;
        }
        
    }
    
};


int authenticateAndPerformAction(User * user, string action)
{
    bool result = user->authenticatepassword();
    if(result == 1)
    {
        cout  << " Succesfully Authentified Procced " << endl;
        int resalt = user->Authentification(action);
        if(resalt == 1)
        {
            cout << " Action Performed Successfully " << endl;
            return 1;
        }
        
        else
        {
            cout << " Sorry!.  Action didn't Performed Successfully " << endl;
            return 0;
        }
        
        
    }
    else
    {
        cout  << " Unsuccesfull. Authentication Failed. " << endl;
        return 0;
        
    }
    
}

class TA;
class Student : public User
{
    private:
    int Assignments[16] =
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };
    
  static  int StudentSumbissionTracker;
    int date;
    int month;
    int year;
    
    public:
    Student() : date(0),month(0),year(0)
    {}
    
    Student(string Name, string Id,string Email,string charachter,string list) : User( Name, Id,Email,charachter,list)
    {
        
    }
    
    void displayinfo(TA * ta);
   
    void GiveAssignment(string Assignmentname)
    {
        int dateOfSumbission;
        cout << " Enter Sumbission Date like from(1-31) " << endl;
        cin >> dateOfSumbission;
        if(dateOfSumbission > 0 && dateOfSumbission < 32)
        {
            date = dateOfSumbission;
        
        
            int Month;
            cout << " Enter Month (1-12) " << endl;
            cin >> Month;
            month = Month;
        
            if(Month > 0 && Month <13)
            {
                month = Month;
                int Year;
                cout << " Enter Year like 2025 etc " << endl;
                cin >> Year;
                year = Year;
                
            }
            
        }
    }
    
    void SubmitAssignment()
    {
      int Month, Date, Year;
      cout << " Enter Month Of Submission " << endl;
       cin >> Month;
       month = Month;
       
      cout << " Enter Date Of Submission " << endl;
      cin >> Date;
      date = Date;
      
     cout << " Enter Year Of Submission " << endl;
     cin >> Year;
     year = Year;

      if (Year > year || (Year == year && Month > month) || (Year == year && Month == month && Date > date))
      {
        cout << " Sorry. Submission deadline was " << date << "-" << month << "-" << year << endl;
        return;
       }

       if (StudentSumbissionTracker < 16)
      {
        Assignments[StudentSumbissionTracker] = 1;  
        StudentSumbissionTracker++;
        cout << "Assignment submitted successfully!" << endl;
        cout << " S" << StudentSumbissionTracker << endl;
       }
       else
       {
        cout << " No more submissions allowed." << endl;
       }
     }
    
    
};
int Student :: StudentSumbissionTracker =0;

class TA : public Student
{
    private: 
    string StudentList[20] =  {
    "Aiden", "Bella", "Caleb", "Daniel", "Elena", "Felix", "Grace", "Henry", "Isla", "Jack",  
    "Kaitlyn", "Liam", "Mia", "Nathan", "Olivia", "Paul", "Quinn", "Ryan", "Sophia", "Thomas" };
    
   
    int ProjectCount[10];
    string TaProjectList[2];
    
    string TaStudents[16];
    
    int CurrentProjects;
    int Totaltastudents;
    string TaName;
   
   public:
   TA()
   {}
   
   TA(string Name, string Id,string Email,string charachter,string list,string taname) : Student( Name, Id,Email,charachter, list),TaName(taname)
   {
       CurrentProjects =0;
       Totaltastudents =0;
   }
   
   void AssignStudents()
   {

        if(Totaltastudents > 16)
       { 
          cout << " Cant Add " << endl;
          return;
        }

       string StudentName;
       cout << "Enter Student Name To Be Assigned To TA: ";
       cin >> StudentName;

       int found =-1;
       for(int i = 0; i < Totaltastudents; i++) 
       {
         if(TaStudents[i] == StudentName)
          {
            cout << " Found " << endl;
            found =1;
            return;
          }
       }

    
       if(found ==-1)
       {
          for(int i = 0; i < 20; i++)
          {
               if(StudentName == StudentList[i])
              { 
              TaStudents[Totaltastudents] = StudentName;
                Totaltastudents++;
        
              }
           }
        }
        else
        {
        cout << " Student Already Assigned " << endl;
         }
        

    
   }
   
   void ViewCurrentProjects()
   {
       for(int y =0; y< CurrentProjects ;y++)
       {
           cout << " Project " << y+1 << " is " << TaProjectList[y] << endl;
       }
   }
   
   void ProjectDetails()
   {

       string Choice;
       cout << " Enter Choice In Yes/No if You want to start Project or not " << endl;
       cin >> Choice;
       if(Choice == "Yes")
       {
           if (CurrentProjects >= 2) 
           {
            cout << "TA can only work on 2 projects at a time." << endl;
           return;
           }
           string projectname;
           cout << " Enter Project name " << endl;
           cin >> projectname;
           
        TaProjectList[CurrentProjects] = projectname;
        cout << " Project Assigned Is " << projectname << endl;
            CurrentProjects++;
       }
       
   }
   
   void displayinfo()
  {
    cout << "TA Students: " << endl;
    for(int y = 0; y < Totaltastudents; y++)
    {
        cout << "  " << TaStudents[y] << endl;
    }

    cout << "Projects Assigned to TA: " << endl;
    for(int y = 0; y < CurrentProjects; y++)
    {
        cout << "  Project " << y+1 << ": " << TaProjectList[y] << endl;
    }
   }
   
   int SearchTaStudent(string Studentname)
   {
       for(int y =0; y< Totaltastudents;y++)
       {
           if(Studentname == TaStudents[y] )
           {
               return 1;
           }
       }
       return 0;
   }
   
   int GetProject()
   {
       return CurrentProjects;
   }

    
};

void Student ::  displayinfo(TA * ta)
    
    {
        
        int result = ta->SearchTaStudent(name);
        if(result == 1)
        {
        cout << " Assignment Sumbission Status is " << endl;
        cout << name << " Sumbitted The Assignment " << endl;
        cout << " Email is " << email << endl;
        cout << " Id Is " << id << endl;
        for(int y =0; y < 16;y++)
        {
            cout << " Student " << y+1 << " Status is " << Assignments[y] << endl;
        }
        }
    }

class Proffessor : public User
{
    private:
    string ProffessorName;
    int Projects;
    
    public:
    Proffessor()
    {
        ProffessorName = " ";
    }
    
    Proffessor(string Name, string Id,string Email,string charachter,string lists,string name) : User( Name, Id, Email, charachter,lists)
    {
        ProffessorName = name;
    }
    
    void displayinfo()
    {
        cout << " Proffesor Name is " << ProffessorName << endl;
        cout << " Proffesor id is " << id << endl;
       cout << " Proffesor email is " << email << endl;
        
    }
    
    void WorkOnProject(TA *ta)
    {
       if (ta->GetProject() >= 2)
       {
        cout << "TA is already working on 2 projects." << endl;
        return;
       }

       ta->ProjectDetails();  
       cout << "Professor assigned a project to the TA successfully!"  << endl;
     }
    
    
};


int main() 
{
    
    cout << " _User Details_ " << endl;
    cout << endl;
    User user("Qasim","12k-8765","Qasim@nu.pk","1234567","TA");
    
    user.displayinfo();
    cout << endl;
    
    TA ta1("Alice", "T001", "alice@example.com", "tapass", "TA", "Alice");
    
    cout << " Ta  Is Trying To Get Access to  Assigned Students for him  And Manage his projects " << endl;
    
    
    int Result = authenticateAndPerformAction(&ta1, "manage_students");
    if(Result == 1)
    {
        ta1.AssignStudents();
        ta1.AssignStudents();
        ta1.AssignStudents();
        ta1.AssignStudents();
        cout << endl;
        cout << " _Ta Details_ " << endl;
        
        ta1.displayinfo();
        cout << endl;
        
        ta1.ProjectDetails();
        ta1.ProjectDetails(); 
        ta1.ProjectDetails(); 
        ta1.ViewCurrentProjects();
       
        
    }
    else
    {
        cout << " Sorry Failed Authentification. Please Try Again " << endl;
    
    }
    
    // My logic: The Constructor Name of student Should Of student should be in Ta Students assigned array so that he can Sumbit Assignment. Else if name will not be in Ta list so his assignment would be coming output as sumbitted but its assignment will not Checked/Recived by this Ta.
    Student s1("Henry", "S001", "john@example.com", "studentpass", "STUDENT");
    Student s2("Daniel","S002","Daniel@nu.edu.pk","studentpass2","STUDENT");

    
    cout << " Student Is Trying To Get Access to See Assigned Assignment And Sumbit It in time " << endl;
    
    int result = authenticateAndPerformAction(&s1, "sumbit assignment");
    if(result == 1)
    {
        s1.GiveAssignment("Mvc Assignment");
        s1.SubmitAssignment();
        cout << endl;
        cout << " _Student Details_ " << endl;
        cout << endl;
        s1.displayinfo(&ta1);// In Display MY Logic : Is That Student Can See only His Assignment Status so Others Status will be coming 0 so that  student cant see other Details
        
    }
    else
    {
        cout << " Sorry Failed Authentification. Please Try Again " << endl;
    
    }
    
    cout << " Student Is Trying To Get Access to See Assigned Assignment And Sumbit It in time " << endl;
    int esult = authenticateAndPerformAction(&s2, "sumbit assignment");
    if(esult == 1)
    {
        s2.GiveAssignment("Mvc Assignment");
        s2.SubmitAssignment();
        cout << endl;
        cout << " _Student Details_ " << endl;
        cout << endl;
        s2.displayinfo(&ta1);
        
    }
    else
    {
        cout << " Sorry Failed Authentification. Please Try Again " << endl;
    
    }
    
    
    
    Proffessor p1("Dr. Smith", "P001", "smith@example.com", "professorpass", "PROFESSOR", "Dr. Smith");
    
    cout << " Proffesor Is Signing To Get Access to See Assigned Assignment And GetAccess to lab" << endl;
    
    int REsult = authenticateAndPerformAction(&p1, "assign projects");
    if(REsult == 1)
    {
         p1.WorkOnProject(&ta1);
         cout << endl;
         cout << " _Proffesor Details_ " << endl;
         p1.displayinfo();
         cout << endl;

    }
    else
    {
        cout << " Sorry Failed Authentification. Please Try Again " << endl;
    
    }

    return 0;
}