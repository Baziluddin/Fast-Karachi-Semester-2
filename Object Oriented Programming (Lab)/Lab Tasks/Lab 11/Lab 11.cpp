
// Q1
// 24k-0559 Bazil-Uddin-Khan
#include<iostream>
#include<exception>
using namespace std;
class InvalidValueException : public std ::exception
{
    public:
    const char* what () const noexcept override
    {
        return " Invalid Age Negative Exception . Cant be Negative or Greater than 120 ";
    }
};

void validateFunction(int age)
{
        if(age < 0 || age > 120)
        {
           throw InvalidValueException();
        }
}

int main() 
{
    int Age;
    cout << "Enter Age" << endl;
    cin >> Age;
    
    try
    {
        validateFunction(Age);
    }
    
    catch(InvalidValueException & e)
    {
        cout << "Error " << e.what() << endl;
    }

    return 0;
}
//Q2
//24k-0559 Bazil-Uddin-Khan 
#include <iostream>
#include<exception>
using namespace std;

class StackOverFlowException : std::exception
{
    public:
    const char* what() const noexcept override
    {
        return "Stack Full Exception Error";
    }
};

class StackUnderFlowException : std::exception
{
    public:
    const char* what() const noexcept override
    {
        return "Stack Empty Exception Error";
    }
    
};

template<typename T>
class Stack
{
    T capacity[3];
    int trackpointer;
    
    public:
    Stack() : trackpointer(0)
    {}
    
    void Push(int num)
    {
        if(trackpointer < 3)
        {
            capacity[trackpointer] = num;
            cout << "Succesfully Poped In Number : " << capacity[trackpointer] << endl;
            trackpointer++;
        }
        else
        {
            throw StackOverFlowException();
        }
    }
    
    void Pop()
    {
        if(trackpointer == 0)
        {
            throw StackUnderFlowException();
        }
        else
        {
            cout << "Succesfully Poped Out The Number : " << capacity[trackpointer] << " from stack " << endl;
        }
    }
};

int main()
{
    Stack<int>stack;
    
    
    try
    {
        stack.Pop();
    }
    
    catch(StackUnderFlowException & e)
    {
        cout << "Exception is:" << e.what() << endl;
    }

    try
    {
        stack.Push(78);
        stack.Push(89);
        stack.Push(100);
        stack.Push(50);
    }
    
    
    catch(StackOverFlowException & e)
    {
        cout << "Exception is:" << e.what() << endl;
        
    }
    return 0;
}
// Q3
// 24k-0559 Bazil-Uddin-Khan 
#include <iostream>
#include<exception>
#include<fstream>
using namespace std;

class FileException : public std::exception
{
    virtual const char* what() 
    {
        return "File Error!.Exception";
    }
};

class FileNotFoundException : public FileException
{
    public:
    const char* what()const noexcept override
    {
        return "File Not Found Exception";
    }
};

class PermissionDeniedException : public FileException
{
    public:
    const char* what() const noexcept override
    {
        return "File Permission Denied Exception";
    }
};

void readFile(string  filename)
{
    if(filename == "secret.txt")
    {
        throw PermissionDeniedException();
    }
    
    ifstream stream;
    stream.open(filename);
    if(!stream)
    {
        cerr << "Cant open" << endl;
        throw FileNotFoundException();
    }
    
    stream.close();
}


int main() 
{
    try
    {
        readFile("secret.txt");
        
    }
    
    catch(FileNotFoundException & e)
    {
        cout << "File Not Found Exception " << e.what() << endl;
    }
    
    catch(PermissionDeniedException & e)
    {
        cout << "Permission of file denied Exception " << e.what() << endl;
    }
    

    return 0;
}
//Q4
//24k-0559 Bazil-Uddin-Khan Bscs-2H Task4.
#include<iostream>
#include<exception>
#include<cmath>
#include<type_traits>
using namespace std;

class NegativeNumberException :public std::exception
{
    public:
    const char* what() const noexcept override
    {
        return "Negative Number Exception";
    }
};

class InvalidTypeException : public std::exception
{
    public:
    const char* what() const noexcept override
    {
        return " Invalid Type Exception ";
    }
};



template<typename T>

void Sqrt(T num)
{
    if constexpr(!std::is_arithmetic<T>::value)
    {
        throw InvalidTypeException();
    }
    
    else if(num < 0)
    {
        throw NegativeNumberException();
    }
    
    else
    {
        cout << "Number : " << num << " root is " << sqrt(num) << endl;
    }
}

int main()
{
    try
    {
         Sqrt<string>("Hello");
    }
    
    catch(InvalidTypeException & e)
    {
        cout << " Invalid Type Exception " << e.what() << endl;
    }
    
    try
    {
        Sqrt<int>(-6);
    }
    
    catch(NegativeNumberException & e)
    {
        cout <<"Negative Type Exception " << e.what() << endl;
    }
    
    try
    {
        Sqrt<double>(4.0);
    }
    
    catch(NegativeNumberException & e)
    {
        cout << "Negative number exception error : " << e.what() << endl;
    }

    return 0;
}

// Q5
// 24k-0559 Bazil-Uddin-Khan Bscs-2H 

#include<iostream>
using namespace std;

class InsuffiecientFundsException : std :: exception
{
    public:
    const char* what() const noexcept override
    {
        return "Exception Insufficient Funds In Account";
    }
};

template<typename T>
class BankAccount
{
    private:
    T balance;

    public:
    BankAccount(T bal) : balance(bal)
    {}

    void withdraw(T withdraw)
    {
       if(balance < withdraw)
       {
        throw InsuffiecientFundsException();
       }
        
    }
    
    T GetBalance()
    {
        return balance;
    }


};

int main()
{
    BankAccount<int> bank(500);
    
    cout << "Current Balance Is " << bank.GetBalance() << endl;
    
    
    try
    {
        bank.withdraw(600);
    }
    catch(InsuffiecientFundsException & e)
        {
            cout << " Exception is " << e.what() << endl;
        }
    

}
