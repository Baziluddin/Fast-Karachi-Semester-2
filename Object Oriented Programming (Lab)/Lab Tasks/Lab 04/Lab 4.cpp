// Q1
// 24k-0559 Bazil-Uddin-Khan
#include <iostream>
#include<string>
using namespace std;

class Book
{
    private:
    string Title;
    double Price;
    static int * Stock;
    int Booknum;
    
    public:
    Book()
    {
        Title = "Unknown";
        Price = 0.0;
        Booknum =0;
        if(Stock == nullptr)
        {
            Stock = new int (30);
            
        }
    }
    
    void Initialize(Book * book,int TotalBooks)
    {
        for(int i =0; i < TotalBooks;i++)
        {
            book[i].Title = "Unknown";
            book[i].Price =0.0;
        }
        
    }
    
    void SetAttributes(string NewTitle,double NewPrice)
    {
        Title = NewTitle;
        Price = NewPrice;
    }
    
    void UpdateBookDetails(int Booknum,Book * book,int Totalbooks)
    {
        for(int i =0; i < Totalbooks;i++)
        {
            if(i+1 == Booknum)
            {
                string NewTitle;
                cout << " Enter New Title " << endl;
                cin.ignore();
                getline(cin,NewTitle);
                
                double NewPrice;
                cout << " Enter New Price " << endl;
                cin >> NewPrice;
                book[i].SetAttributes(NewTitle,NewPrice);
                
                
            }
        }
    }
    
    void TrackStockLevels()
    {
        if(*(Stock) < 5)
        {
            cout << " Low-Stock Warning " << endl;
        }
    }
    
    void SimulateBookPurchases(Book * book,int i)
    {
        if(*(Stock) != 0)
        {
            string Title;
            cin.ignore();
            
            cout << " Enter Title of Book " << endl;
            getline(cin,Title);
        
            double Price;
            cout << " Enter Book price " << endl;
            cin >> Price;
            book[i].SetAttributes(Title,Price);
            Booknum++;
            (*Stock)--;
        
            
        }
        else
        {
            cout << " Sorry All Books Are been Purchased " <<  endl;
            
        }
        
    }
    
    string GetTitle()
    {
        return Title;
    }
    
    double GetPrice()
    {
        return Price;
    }
    
    void Display(Book * book,int TotalBooks)
    {
        for(int i =0; i < TotalBooks;i++)
        {
            cout << " Title of book " << i +1 << " is " << book[i].GetTitle() << endl;
            cout << " Price of book " << i +1 << " is " << book[i].GetPrice() << endl;
            
        }
        cout << " Capacity of Inventory system Still contains : " << *(Stock) << " Books " << endl;
    }
    ~Book()
    {
        if(Stock == nullptr)
        {
              delete Stock;
            
        }
      
    }
    
};

int * Book :: Stock ;

int main()
{
    cout << " Welcome To Bookstore Management System " << endl;
    
    int TotalBooks;
    cout << " Enter Total Books  You want To purchase " << endl;
    cin >> TotalBooks;
    
    Book * book = new Book[TotalBooks];
    book->Initialize(book,TotalBooks);
    
    for(int i =0; i < TotalBooks;i++)
    {
        book[i].SimulateBookPurchases(book,i);
        book[i].TrackStockLevels();
    }
    
    book->Display(book,TotalBooks);
    
    
    delete [] book;

    return 0;
}

// Q2
// 24K-0559 BAZIL UDDIN KHAN 

#include <iostream>
using namespace std;

class Book
{
    private:
    string Title;
    double Price;
    static int * Stock ;
    int Booknum;
    
    public:
    Book(const  Book & book )
    {
        Title = book.Title;
        Price = book.Price;
        if(Stock == nullptr)
        {
            Stock = new int(*book.Stock);
        }
    }
    Book()
    {
        Title = "Unknown";
        Price =0.0;
        Booknum =0;
        if(Stock == nullptr)
        {
            Stock = new int (30);
            
        }
        
    }
    
    Book(string Title,double Price)
    {
        this->Title = Title;
        this->Price = Price;
    }
    
    
    
    void Initialize(Book * book,int TotalBooks)
    {
        for(int i =0; i < TotalBooks;i++)
        {
            book[i].Title = "Unknown";
            book[i].Price =0.0;
        }
        
    }
    
    void SetAttributes(string NewTitle,double NewPrice)
    {
        Title = NewTitle;
        Price = NewPrice;
    }
    
    void SetPrice(double price)
    {
        Price = price;
    }
    
    void UpdateBookDetails(Book * book,int Totalbooks)
    {
        int BookNumber;
       
        cout << " Enter The Book Number " << endl;
        cin >> BookNumber;
        
        if(BookNumber > 0 && BookNumber <= Totalbooks)
        {
              for(int i =0; i < Totalbooks;i++) 
              {
            
                if(i == BookNumber-1)
               {
                  string NewTitle;
                  cout << " Enter New Title for this book " << endl;
                  cin.ignore();
                  getline(cin,NewTitle);
                
                 double NewPrice;
                 cout << " Enter New Price " << endl;
                 cin >> NewPrice;
                 book[i].SetAttributes(NewTitle,NewPrice);
                
                
            }
            
        }
      }
      else
        {
            cout << " Wrong Input  " << endl;
            
        }
    
     }
    
    
    void TrackStockLevels()
    {
        if(*(Stock) < 5)
        {
            cout << " Low-Stock Warning " << endl;
        }
    }
    
    void SimulateBookPurchases(Book * book,int i)
    {
        if(*(Stock) != 0 && *(Stock) > 0)
        {
            string Title;
            cin.ignore();
            cout << " Enter Title of Book " << endl;
            getline(cin,Title);
        
            double Price;
            cout << " Enter Book price " << endl;
            cin >> Price;
            book[i].SetAttributes(Title,Price);
            Booknum++;
            (*Stock)--;
        
            
        }
        else
        {
            cout << " Sorry All Books Are been Purchased " <<  endl;
            
        }
        
    }
    
    string GetTitle()
    {
        return Title;
    }
    
    double GetPrice()
    {
        return Price;
    }
    
    int  GetTotal()
    {
        return *(Stock);
    }
    
    
    int StockValidation(int TotalBooks)
    {
        if(TotalBooks < *(Stock))
        {
            return 1;
            
        }
        else
        {
            return 0;
        }
        
    }
    
    void Display(Book * book,int TotalBooks)
    {
        for(int i =0; i < TotalBooks;i++)
        {
            cout << " Title of book " << i +1 << " is " << book[i].GetTitle() << endl;
            cout << " Price of book " << i +1 << " is " << book[i].GetPrice() << endl;
            
        }
        cout << " Capacity of Inventory system Still contains : " << *(Stock) << " Books " << endl;
    }
    
    void ApplyDiscount(int TotalBooks,Book * book)
    {
         if(TotalBooks > 10)
        {
           for(int i =0; i < TotalBooks;i++)
           {
               double price = book[i].GetPrice();
               price = price - (price*0.1);
               book[i].SetPrice(price);
           }
        }
        
        else if(TotalBooks > 5)
        {
           for(int i =0; i < TotalBooks;i++)
           {
               double price = book[i].GetPrice();
               price = price - (price*0.05);
               book[i].SetPrice(price);
           }
        }
        
        
    }
    
    ~Book()
    {
        if(Stock != nullptr)
        {
              delete Stock;
              cout << " Book is Removed " << endl;
              Stock = nullptr;
            
        }
      
    }
    
    
    
};

int * Book :: Stock ;

int main()
{
    cout << " Welcome To Bookstore Management System " << endl;
    
    int TotalBooks;
    cout << " Enter Total Books  You want To purchase " << endl;
    cin >> TotalBooks;
    
    Book * book = new Book[TotalBooks];
    int Result = book->StockValidation(TotalBooks);
    if(Result == 1)
    {
        book->Initialize(book,TotalBooks);
    
         for(int i =0; i < TotalBooks;i++)
         {
            book[i].SimulateBookPurchases(book,i);
            book[i].TrackStockLevels();
         }
         
         string Choice;
         cout << " Enter in (Yes/No) if You want To Update Any Book Name " << endl;
         cin >> Choice;
         if(Choice == "Yes")
         {
             cout << " Before Updating " << endl;
             book->Display(book,TotalBooks);
         
             cout << " After Updating " << endl;
         
             book->UpdateBookDetails(book,TotalBooks);
             
         }
         
         
         cout << " Before Discount __ " << endl;
    
        book->Display(book,TotalBooks);
        cout << " After Discount ___ " << endl;
    
        book->ApplyDiscount(TotalBooks,book);
        
        Book BOOK = book[0];
        
        BOOK.Display(book,TotalBooks);
    
    
       delete [] book;
        
    }
    else
    {
        cout << " Warning ⚠️ Your are buying More than the stock Available that is : " << book->GetTotal();
        delete [] book;
        
    }
    

    return 0;
}
// Q3
// 24K-0559 BAZIL UDDIN KHAN

#include <iostream>
using namespace std;

class Book
{
    private:
    string Title;
    double Price;
    static int * Stock ;
    int Booknum;
    
  
    
    public:
    Book()
    {
        Booknum =0;
        if(Stock == nullptr)
        {
            Stock = new int (30);
            
        }
        
     
        
    }
    
    Book(string Title,double Price)
    {
        this->Title = Title;
        this->Price = Price;
    }
    
    Book(Book & Book)
    {
        
      
          Title =   Book.Title;
          Price = Book.Price;
          Stock = new int(*Book.Stock);
        
    }
    
    
    
    void Initialize(Book * book,int TotalBooks)
    {
        for(int i =0; i < TotalBooks;i++)
        {
            book[i].Title = "Unknown";
            book[i].Price =0.0;
        }
        
    }
    
    void SetAttributes(string NewTitle,double NewPrice)
    {
        Title = NewTitle;
        Price = NewPrice;
    }
    
    void SetPrice(double price)
    {
        Price = price;
    }
    
    void UpdateBookDetails(int Booknum,Book * book,int Totalbooks)
    {
        for(int i =0; i < Totalbooks;i++)
        {
            if(i == Booknum-1)
            {
                string NewTitle;
                cout << " Enter New Title " << endl;
                cin >> NewTitle;
                double NewPrice;
                cout << " Enter New Price " << endl;
                cin >> NewPrice;
                book[i].SetAttributes(NewTitle,NewPrice);
                
                
            }
        }
    }
    
    void TrackStockLevels()
    {
        if(*(Stock) < 5)
        {
            cout << " Low-Stock Warning " << endl;
        }
    }
    
    void SimulateBookPurchases(Book * book,int i)
    {
        if(*(Stock) != 0 && *(Stock) > 0)
        {
            string Title;
            cout << " Enter Title of Book " << endl;
            cin >> Title;
        
            double Price;
            cout << " Enter Book price " << endl;
            cin >> Price;
            book[i].SetAttributes(Title,Price);
            Booknum++;
            (*Stock)--;
        
            
        }
        else
        {
            cout << " Sorry All Books Are been Purchased " <<  endl;
            
        }
        
    }
    
    string GetTitle()
    {
        return Title;
    }
    
    double GetPrice()
    {
        return Price;
    }
    
    int  GetTotal()
    {
        return *(Stock);
    }
    
    
    int StockValidation(int TotalBooks)
    {
        if(TotalBooks < *(Stock))
        {
            return 1;
            
        }
        else
        {
            return 0;
        }
        
    }
    
    void Display(Book * book,int TotalBooks)
    {
        for(int i =0; i < TotalBooks;i++)
        {
            cout << " Title of book " << i +1 << " is " << book[i].GetTitle() << endl;
            cout << " Price of book " << i +1 << " is " << book[i].GetPrice() << endl;
            
        }
        cout << " Capacity of Inventory system Still contains : " << *(Stock) << " Books " << endl;
    }
    
    void ApplyDiscount(int TotalBooks,Book * book)
    {
         if(TotalBooks > 10)
         {
           for(int i =0; i < TotalBooks;i++)
           {
               double price = book[i].GetPrice();
               price = price - (price*0.1);
               book[i].SetPrice(price);
           }
        }
        else if(TotalBooks > 5)
        {
           for(int i =0; i < TotalBooks;i++)
           {
               double price = book[i].GetPrice();
               price = price - (price*0.05);
               book[i].SetPrice(price);
           }
        }
        
        
        
    }
    
    ~Book()
    {
        if(Stock == nullptr)
        {
              delete Stock;
              cout << " Object Destroyed " << endl;
            
        }
      
    }
    
    
    
};

int * Book :: Stock ;

int main()
{
    cout << " Welcome To Bookstore Management System " << endl;
    
    int TotalBooks;
    cout << " Enter Total Books  You want To purchase " << endl;
    cin >> TotalBooks;
    
    Book * book = new Book[TotalBooks];
    int Result = book->StockValidation(TotalBooks);
    if(Result == 1)
    {
        book->Initialize(book,TotalBooks);
    
         for(int i =0; i < TotalBooks;i++)
         {
            book[i].SimulateBookPurchases(book,i);
            book[i].TrackStockLevels();
         }
    
         cout << " Before Discount __ " << endl;
    
         book->Display(book,TotalBooks);
        cout << " After Discount ___ " << endl;
    
        book->ApplyDiscount(TotalBooks,book);
        
        book->Display(book,TotalBooks);
        cout << " Before Updating " << endl;
        
        book->Display(book,TotalBooks);
        
        
        Book BOOK(book[0]);
        BOOK.UpdateBookDetails(1,book,TotalBooks);
        
        cout << " After Updating " << endl;
        
        BOOK.Display(book,TotalBooks);
        
        cout << " Original object " << endl;
        book->Display(book,TotalBooks);
        
        
    
    
       delete [] book;
        
    }
    else
    {
        cout << " Warning ⚠️ Your are buying More than the stock Available that is : " << book->GetTotal();
        delete [] book;
        
    }
    

    return 0;
}
// Q4
// 24K-0559 BAZIL UDDIN KHAN

#include <iostream>
#include<string>
using namespace std;

class Book
{
    private:
    string Title;
    double Price;
    static int * Stock ;
    int Booknum;

    public:
    Book()
    {
        Title = "Unknown";
        Price =0.0;
        Booknum =0;
        if(Stock == nullptr)
        {
            Stock = new int (30);
            
        }
        
      
        
    }
    
    Book(string Title,double Price)
    {
        this->Title = Title;
        this->Price = Price;
    }
    
    Book(Book & book)
    {
        Title = book.Title;
        Price = book.Price;
            
        
    }
    
    
    
    void Initialize(Book * book,int TotalBooks)
    {
        for(int i =0; i < TotalBooks;i++)
        {
            book[i].Title = "Unknown";
            book[i].Price =0.0;
        }
        
    }
    
    void SetAttributes(string NewTitle,double NewPrice)
    {
        Title = NewTitle;
        Price = NewPrice;
    }
    
    void SetPrice(double price)
    {
        Price = price;
    }
    
    void UpdateBookDetails(int Booknum,Book * book,int Totalbooks)
    {
        for(int i =0; i < Totalbooks;i++)
        {
            if(i+1 == Booknum)
            {
                string NewTitle;
                cout << " Enter New Title " << endl;
                cin.ignore();
                getline(cin,NewTitle);
                
                double NewPrice;
                cout << " Enter New Price " << endl;
                cin >> NewPrice;
                book[i].SetAttributes(NewTitle,NewPrice);
                
                
            }
        }
    }
    
    void TrackStockLevels()
    {
        if(*(Stock) < 5)
        {
            cout << " Low-Stock Warning " << endl;
        }
    }
    
    void SimulateBookPurchases(Book * book,int i)
    {
        if(*(Stock) != 0 && *(Stock) > 0)
        {
            string Title;
            cout << " Enter Title of Book " << endl;
            cin >> Title;
        
            double Price;
            cout << " Enter Book price " << endl;
            cin >> Price;
            book[i].SetAttributes(Title,Price);
            Booknum++;
            (*Stock)--;
        
            
        }
        else
        {
            cout << " Sorry All Books Are been Purchased " <<  endl;
            
        }
        
    }
    
    string GetTitle()
    {
        return Title;
    }
    
    double GetPrice()
    {
        return Price;
    }
    
    int  GetTotal()
    {
        return *(Stock);
    }
    
    
    int StockValidation(int TotalBooks)
    {
        if(TotalBooks < *(Stock))
        {
            return 1;
            
        }
        else
        {
            return 0;
        }
        
    }
    
    void Display(Book * book,int TotalBooks)
    {
        for(int i =0; i < TotalBooks;i++)
        {
            cout << " Title of book " << i +1 << " is " << book[i].GetTitle() << endl;
            cout << " Price of book " << i +1 << " is " << book[i].GetPrice() << endl;
            
        }
        cout << " Capacity of Inventory system Still contains : " << *(Stock) << " Books " << endl;
    }
    
    void ApplyDiscount(int TotalBooks,Book * book)
    {
         if(TotalBooks > 10)
         {
           for(int i =0; i < TotalBooks;i++)
           {
               double price = book[i].GetPrice();
               price = price - (price*0.1);
               book[i].SetPrice(price);
           }
        }
        else if(TotalBooks > 5)
        {
           for(int i =0; i < TotalBooks;i++)
           {
               double price = book[i].GetPrice();
               price = price - (price*0.05);
               book[i].SetPrice(price);
           }
        }
        
        
        
    }
    
    double ValidateBooks(int TotalBooks)
    {
        if(TotalBooks > 10)
        {
            return 0.1;
        }
        else 
        {
            return 0.05;
        }
        
    }
    
    void PriceMechanism(Book * book,int TotalBooks)
    {
        cout << " Base Price is " << endl;
        for(int i =0; i < TotalBooks;i++)
        {
            cout << " Title is " << book[i].GetTitle() << 
               " Price is " << book[i].GetPrice() << endl;
        }
        
        cout << " Discount Percentage is " << book->ValidateBooks(TotalBooks) << endl;
        
        
        
        
    }
    
    ~Book()
    {
        if(Stock == nullptr)
        {
              delete Stock;
              cout << " Object Destroyed " << endl;
            
        }
      
    }
    
    
    
};

int * Book :: Stock ;

int main()
{
    cout << " Welcome To Bookstore Management System " << endl;
    
    int TotalBooks;
    cout << " Enter Total Books  You want To purchase " << endl;
    cin >> TotalBooks;
    
    Book * book = new Book[TotalBooks];
    int Result = book->StockValidation(TotalBooks);
    if(Result == 1)
    {
        book->Initialize(book,TotalBooks);
    
         for(int i =0; i < TotalBooks;i++)
         {
            book[i].SimulateBookPurchases(book,i);
            book[i].TrackStockLevels();
         }
    
         cout << " Before Discount __ " << endl;
    
         book->Display(book,TotalBooks);
        cout << " After Discount ___ " << endl;
    
        book->ApplyDiscount(TotalBooks,book);
        book->Display(book,TotalBooks);

        book->PriceMechanism(book,TotalBooks);
        
        
    
    
       delete [] book;
        
    }
    else
    {
        cout << " Warning ⚠️ Your are buying More than the stock Available that is : " << book->GetTotal();
        delete [] book;
        
    }
    

    return 0;
}
//Q5
// 24K-0559 BAZIL UDDIN KHAN
#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string Title;
    double Price;
    static int* Stock;
    int Booknum;
    static int TotalBooks;
    
    string* Bookids;
    
public:
    Book()
    {
        Title = "Unknown";
        Price = 0.0;
        Booknum = 0;
        
        if (Stock == nullptr)
        {
            Stock = new int(30);  
        }
        
        Bookids = new string[TotalBooks];  
    }
    
    Book(string title, double price) : Title(title), Price(price) {
        Booknum = 0;
        Bookids = new string[TotalBooks];  
    }
    
    
    Book(Book& BOOK)
    {
        this->Title = BOOK.Title;
        this->Price = BOOK.Price;
        this->Stock = BOOK.Stock;
        this->Bookids = new string[TotalBooks];  
        for (int i = 0; i < TotalBooks; i++) {
            this->Bookids[i] = BOOK.Bookids[i]; 
        }
    }
    
    void Initialize(Book* book, int TotalBooks)
    {
        for (int i = 0; i < TotalBooks; i++)
        {
            book[i].Title = "Unknown";
            book[i].Price = 0.0;
        }
    }
    
    void SetAttributes(string NewTitle, double NewPrice)
    {
        Title = NewTitle;
        Price = NewPrice;
    }
    
    void SetPrice(double price)
    {
        Price = price;
    }
    
    void UpdateBookDetails(int Booknum, Book* book, int Totalbooks)
    {
        for (int i = 0; i < Totalbooks; i++)
        {
            if (i == Booknum - 1)
            {
                string NewTitle;
                cout << " Enter New Title " << endl;
                cin.ignore();
                getline(cin, NewTitle);
                
                double NewPrice;
                cout << " Enter New Price " << endl;
                cin >> NewPrice;
                book[i].SetAttributes(NewTitle, NewPrice);
            }
        }
    }
    
    void TrackStockLevels()
    {
        if (*(Stock) < 5)
        {
            cout << " Low-Stock Warning " << endl;
        }
    }
    
    void SimulateBookPurchases(Book* book, int i)
    {
        if (*(Stock) != 0 && *(Stock) > 0)
        {
            string Title;
            cout << " Enter Title of Book " << endl;
            cin >> Title;
        
            double Price;
            cout << " Enter Book price " << endl;
            cin >> Price;
            book[i].SetAttributes(Title, Price);
            Booknum++;
            (*Stock)--;
            TotalBooks++;
        }
        else
        {
            cout << " Sorry All Books Are been Purchased " << endl;
        }
    }
    
    string GetTitle()
    {
        return Title;
    }
    
    double GetPrice()
    {
        return Price;
    }
    
    int GetTotal()
    {
        return *(Stock);
    }
    
    int StockValidation(int TotalBooks)
    {
        if (TotalBooks < *(Stock))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    void Display(Book* book, int TotalBooks)
    {
        for (int i = 0; i < TotalBooks; i++)
        {
            cout << " Title of book " << i + 1 << " is " << book[i].GetTitle() << endl;
            cout << " Price of book " << i + 1 << " is " << book[i].GetPrice() << endl;
        }
        cout << " Capacity of Inventory system Still contains : " << *(Stock) << " Books " << endl;
    }
    
    void SetTotalBooks(int TotalBooks)
        {
            this->TotalBooks = TotalBooks;
        }
     
    void DisplayAllDeatails(Book* book, int Totalbooks)
    {
        for (int i = 0; i < Totalbooks; i++)
        {
            cout << " Book id of Book " << i + 1 << " is" << Bookids[i] << " Title of book " << i + 1 << " is " << book[i].GetTitle() << endl;
            cout << " Price of book " << i + 1 << " is " << book[i].GetPrice() << endl;
        }
        cout << " Total Books Selled Are " << TotalBooks << endl;
        cout << " Capacity of Inventory system Still contains : " << *(Stock) << " Books " << endl;
    }
    
    void ApplyDiscount(int TotalBooks, Book* book)
    {
        if (TotalBooks > 10)
        {
            for (int i = 0; i < TotalBooks; i++)
            {
                double price = book[i].GetPrice();
                price = price - (price * 0.1);
                book[i].SetPrice(price);
            }
        }
        else if (TotalBooks > 5)
        {
            for (int i = 0; i < TotalBooks; i++)
            {
                double price = book[i].GetPrice();
                price = price - (price * 0.05);
                book[i].SetPrice(price);
            }
        }
    }
    
    void SetBookId(int TotalBooks)
    {
        for (int i = 0; i < TotalBooks; i++)
        {
            string str = "00";
            str = str + to_string(i);
            Bookids[i] = str;
        }
    }
    
    double ValidateBooks(int TotalBooks)
    {
        if (TotalBooks > 10)
        {
            return 0.1;
        }
        else 
        {
            return 0.05;
        }
    }
    
    void PriceMechanism(Book* book, int TotalBooks)
    {
        cout << " Base Price is " << endl;
        for (int i = 0; i < TotalBooks; i++)
        {
            cout << " Title is " << book[i].GetTitle() << 
                " Price is " << book[i].GetPrice() << endl;
        }
        
        cout << " Discount Percentage is " << book->ValidateBooks(TotalBooks) << endl;
        
        cout << " Bulk Purchase are " << endl;
        
        book->ApplyDiscount(TotalBooks, book);
    }
    
    ~Book()
    {
       
        if (Stock != nullptr)
        {
            delete Stock;
            Stock = nullptr;  
        }
        delete[] Bookids; 
    }
};

int* Book::Stock;
int Book :: TotalBooks =0;

int main()
{
    cout << " Welcome To Bookstore Management System " << endl;
    
    int TotalBooks;
    cout << " Enter Total Books  You want To purchase " << endl;
    cin >> TotalBooks;
    Book C;
    C.SetTotalBooks(TotalBooks);
    Book* book = new Book[TotalBooks];
    int Result = book->StockValidation(TotalBooks);
    
    book->SetBookId(TotalBooks);
    
    if (Result == 1)
    {
        book->Initialize(book, TotalBooks);
    
        for (int i = 0; i < TotalBooks; i++)
        {
            book[i].SimulateBookPurchases(book, i);
            book[i].TrackStockLevels();
        }
    
        cout << " Before Discount __ " << endl;
    
        book->Display(book, TotalBooks);
        cout << " After Discount ___ " << endl;
    
        book->ApplyDiscount(TotalBooks, book);
        book->Display(book, TotalBooks);
        
        book->SetBookId(TotalBooks);
        book->DisplayAllDeatails(book, TotalBooks);
    
        delete[] book;
    }
    else
    {
        cout << " Warning ⚠️ Your are buying More than the stock Available that is : " << book->GetTotal();
        delete[] book;
    }

    return 0;
}
