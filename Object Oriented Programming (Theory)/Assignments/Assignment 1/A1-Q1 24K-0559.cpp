// 24K-0559 BAZIL-UDDIN-KHAN

#include <iostream>
using namespace std;

class Mentor;

class Student
{
    private:
    string StudentId;
    string Name;
    int Age;
    string SportsInterests[100];
    string MentorAssigned;
    int i;
    
    public:
    Student()
    {
        StudentId = " ";
        Name = " ";
        Age =0;
        for(int i =0; i < 100; i++)
        {
            SportsInterests[i] = " ";
        }
        MentorAssigned = " ";
        i =0;
    }
    
    Student(string StudentId, string Name, int Age,string MentorAssigned)
    {
        this->StudentId = StudentId;
        this->Name = Name;
        this->Age = Age;
        this->MentorAssigned = MentorAssigned;
    }
    
    void SetAttributes(string StudentId, string Name, int Age,string MentorAssigned)
    {
        this->StudentId = StudentId;
        this->Name = Name;
        this->Age = Age;
        this->MentorAssigned = MentorAssigned;
        
    }
    
    void RegisterForMentorship(Mentor & m,string sportsinterest);
    
    void UpdateSportsInterests()
    {
        int Priority;
        cout << " Enter Your priority " << endl;
        cin >> Priority;
        
        string UpdateInterest;
        cout << " Enter New Sports interest To be Updated " << endl;
        cin >> UpdateInterest;
        
        for(int i =0; i < 100; i++)
        {
            if(i+1 == Priority)
            {
                SportsInterests[i] = UpdateInterest;
            }
        }
    }
    
    void viewMentorDetails(Mentor & m);
    
    
    string GetName()
    {
        return Name;
    }
};
class Mentor
{
    private:
    string MentorId;
    string Name;
    string sportsExpertise[100];
    int MaxLearners;
    int CountLearners;
    string * AssignedLearners ;
    
    public:
    Mentor()
    {
        MentorId = " ";
        Name = " ";
        MaxLearners =0;
        CountLearners =0;
        AssignedLearners = nullptr;
    }
    
    Mentor(string MentorId,string Name,
    int MaxLearners)
    {
        this->MentorId = MentorId;
        this->Name = Name;
        this->MaxLearners = MaxLearners;
        CountLearners =0;
        
        AssignedLearners = new string[MaxLearners];
        
        
    }
    
    void AssignLearner(Student & S);
    
    void RemoveLearner();
    
    void viewLearners()
    {
        cout << " Learners Are " << endl;
        for(int i =0; i < CountLearners;i++)
        {
            cout << AssignedLearners[i] << " " << endl;
        }
    }
    
    void ProvideGauidance()
    {
        string Message;
        cout << " Enter A Question on which you want to fell You need Quaidance " << endl;
        cin.ignore();
        getline(cin,Message);
        
        string Response;
        cout << " Enter Response of Quaidance " << endl;
        
        
        getline(cin,Response);
        
        
        cout << " Reponse of Qs is " <<  Response << " Qs was " << Message <<  endl;
    }
    
    int GetCurrentCount()
    {
        
        return CountLearners;
    }
    
    int GetTotalcount()
    {
        return MaxLearners;
    }
    
    string GetName()
    { 
        return Name;
        
    }
    void PrintInfo()
    {
        
            cout << " Mentor Name is " << Name << " " << " Mentor id is " << MentorId << " " << " Max quantity is " << MaxLearners << endl;
        
    }
    
    
    ~Mentor() 
    {
       delete[] AssignedLearners;
    }
    
};

void Student :: viewMentorDetails(Mentor & m )
{
        cout << " Mentor Details Are " << endl;
        m.PrintInfo();
       
}
    

void Student ::  RegisterForMentorship(Mentor & m,string sportsinterest)
{
       if(m.GetCurrentCount() < m.GetTotalcount())
       {
           string studentid;
           cout << " Enter Student Id like(21k-5678) " << endl;
           cin >> studentid;
           
           string name;
           cout << " Enter Name " << endl;
           cin >> name;
           
           int age;
           cout << " Enter Age " << endl;
           cin >> age;
           
           string mentorassigned;
           cout << " Enter Your Mentor Assigned " << endl;
           cin >> mentorassigned;
           
           
           
           if(mentorassigned != m.GetName())
           {
               return;
           }
           
           SportsInterests[i++] = sportsinterest;
           
           Student S(studentid,name,age,mentorassigned);
           
           m.AssignLearner(S);
           cout << " Student Succesfully Registered " << endl;
       }
       else
       {
           cout << " Sorry Its Full " << endl;
       }
}
 
class Skill
{
    private:
    string SkillId;
    string SkillName;
    string Description;
    
    public:
    Skill()
    {
        SkillId = " ";
        SkillName = " ";
        Description = " ";
    }
    Skill(string SkillId,string SkillName
    ,string Description)
    {
        this->SkillId = SkillId;
        this-> SkillName = SkillName;
        this->Description = Description;
    }
    
    void InitalizeSkillDeatails(string SkillId,string SkillName,string Description)
    {
        this->SkillId = SkillId;
        this->SkillName = SkillName;
        this->Description = Description;
    }
    
    void ShowSkillDeatils()
    {
        cout << " Skill Id is " << SkillId << " " << " Skill Name is " << " " << SkillName << " " << " Description is " << Description << endl;
    }
    
    void UpdateSkillDescription(string NewDescription)
    {
        Description = NewDescription;
    }
    string Getskillname()
    {
        return SkillName;
    }
    
};

void Mentor :: AssignLearner(Student & S)
{
        if(CountLearners < MaxLearners)
        {
           AssignedLearners[CountLearners++] =  S.GetName();
           
        }
        else
        {
            cout << " No space " << endl;
        }
        
}

void Mentor :: RemoveLearner()
{
        string RemovedLearner;
        cout << " Enter Learner/Student to be removed " << endl;
        cin >> RemovedLearner;
       
       int Found = -1;
        for(int i =0; i < CountLearners; i++)
        {
            if(AssignedLearners[i] == RemovedLearner)
            {
                Found =i;
                break;
            }
        }
        if(Found == -1)
        {
            cout << " Student Not Found " << endl;
            
        }
        else
        {   
            for(int j =Found; j < CountLearners-1 ;j++  )
                {
                   AssignedLearners[j] = AssignedLearners[j+1];
                }
                
                CountLearners--;
                cout << " Succesfully Removed " << endl;
        }
                
}

class Sport
{
    private:
    string SportId;
    string Name;
    string Description;
    string * RequiredSkills;
    int Totalskills;
    
    public:
    Sport()
    {
        SportId = " ";
        Name = " ";
        Description = " ";
        Totalskills =0;
        RequiredSkills = new string[100];
    }
    
    Sport(string SportId,string Name,string Description)
    {
        this->SportId = SportId;
        this->Name = Name;
        this->Description = Description;
    }

    void Addskill(Skill s)
    {
        if(Totalskills < 100)
         {
             
           RequiredSkills[Totalskills] = s.Getskillname();
            Totalskills++;
         }
         else
         {
             cout << " Skill are Reached " << endl;
             
         }
    }
    
    void Removeskill(Skill s)
    {
        
        int Index = -1;
        
        for(int i =0; i < Totalskills;i++)
        {
            if(RequiredSkills[i] != s.Getskillname())
            {
              Index =i;
              break;
              
              
            }
            
        }
        if(Index != -1)
        {    
             for(int i =Index; i < Totalskills-1;i++)
             {
               RequiredSkills[i] = RequiredSkills[i+1];
             }
             Totalskills--;
             
        }
        else
        {
            cout << " Skill Not Found " << endl;
            
        }
    }
};

int main() 
{
    cout << " Welcome To Sports System  "<< endl;
    
      // Mentor Class 
      
    int Quantity;
    string MentorId;
    string MentorName;
    cout << " Enter Mentor Id like (21k-4567) " << endl;
    cin >> MentorId;
    
    cout << " Enter Mentor Name " << endl;
    cin >> MentorName;
    
    cout << " Enter How Much Learners Can Mentor Teach " << endl;
    cin >> Quantity;
    
    Mentor mentor(MentorId,MentorName,Quantity);
    
        // Skill Class
    
    int TotalSkills;
    cout << " Enter Total Skills of The Mentor " << endl;
    cin >> TotalSkills;
    Skill skill[TotalSkills];
    for(int i =0; i < TotalSkills;i++)
    {
        string Skillid;
        cout << " Enter Skill id " << endl;
        cin >> Skillid;
        
        string Skillname;
        cout << " Enter Skill Name " << endl;
        cin.ignore();
        getline(cin,Skillname);
        
        string Description;
        cout << " Enter Skill Description " << endl;
        
        getline(cin,Description);
        
        skill[i].InitalizeSkillDeatails(Skillid,Skillname,Description);
    }
    
    for(int i =0; i < TotalSkills;i++)
    {
        skill[i].ShowSkillDeatils();
    }
    
    
    string Choice;
    cout << " Do you want To update Your Skills. Enter in(Yes/No) " << endl;
    cin >> Choice;
    if(Choice == "Yes")
    {
         string Skillname;
         cout << " Enter Skill Name To update " << endl;
         cin >> Skillname;
        for(int j =0; j < TotalSkills;j++)
        {
            if(skill[j].Getskillname() == Skillname)
            {
                string Newskill;
                cout << " Enter Updated Skill " << endl;
                cin >> Newskill;
                skill[j].UpdateSkillDescription(Newskill);
            }
        }
        skill->ShowSkillDeatils();
    }
    
    
    // Sport Class
    
    int TotalSportsSkill;
    cout << " Enter Total Sports Skills " << endl;
    cin >> TotalSportsSkill;
    
    Sport sport;
    
    string Sportsinterest;
            cout << " Enter Sports Interest " << endl;
            cin >> Sportsinterest;
    
    for(int i =0; i < TotalSportsSkill;i++)
    {
            string Choice;
            cout << " Enter in Yes/No if you want to add skill " << endl;
            cin >> Choice;
            
            if(Choice == "Yes")
            {
                sport.Addskill(skill[i]);
            }
            
            string CHOICE;
            cout << " Enter in Yes/No if you want to remove skill " << endl;
            cin >> Choice;
            if(CHOICE == "Yes")
            {   
                sport.Removeskill(skill[i]);
            }
            
            
            string SportId;
            cout << " Enter Sport Id " << endl;
            cin >> SportId;
    
            
    }
   
   
    // Student Class 
    
    Student * student = new Student[Quantity];
    
    
    for(int i =0; i < Quantity; i++)
    {
        student[i].RegisterForMentorship(mentor,Sportsinterest);
    }
    
    student[0].viewMentorDetails(mentor);
    
    mentor.viewLearners();
    mentor.ProvideGauidance();
    
    int Totalremove;
    cout << " Enter Total Students To be Removed " << endl;
    cin >> Totalremove;
    if(Totalremove <= Quantity)
    {
        for(int i =0; i < Totalremove;i++)
        {
            mentor.RemoveLearner();
        }
        cout << " Updated Learners Now " << endl;
        
        mentor.viewLearners();
    }
    else
    {
        cout << " Error You Are Trying To Remove More Students Than Are Learning " <<  endl;
    }
    return 0;
}