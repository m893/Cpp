/***********
 * Author :   Mohammed Akram
 * Date  :   6 Aug,  2023
 * Version :  1.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 1.0              6 Aug, 2023               Mohammed Akram
***************************************************************************/
/*
    @brief  
        Hospital system with 9 APIS 
        1) AddNewBook
        2) SearchForBook
        3) printWhoBorrowerd
        4) PrintAllBooksSort
        5) PrintAllBooksSort
        6) AddNewUser
        7) UserBorrowBook
        8) UserReturnBook
        9) PrintAllUsers
    using Three Struct first struct for book , second for user , and the last one for th system 


*/

#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_BOOKS       100
#define MAX_USERS       100

struct book
{
    int book_id ;
    string book_name;
    int book_quantity ;
    int total_borrowed;
    book()
    {
        book_id =-1 ;
        book_name = "";
        book_quantity=total_borrowed=0;
    }
    void InsertBookInfo()
    {
        cout<<"Enter book ID \n";
        cin>>book_id;
        cout<<"Enter book Name \n";
        cin>>book_name;
        cout<<"Enter book Quantity \n";
        cin>>book_quantity;
        total_borrowed=0;
    }
    bool BorrowBook(int UserId)
    {
            if(book_quantity-total_borrowed==0)
            {
                return false;
            }else
            {

            }
                total_borrowed++;
                return true;
    }
    void UserRuturnBook()
    {
        total_borrowed--;
        
    }
    bool BookHasThisPrefix(string prefix)
    {
        if(book_name.size()< prefix.size())
        {
            return false;
        }
        for(int i = 0 ; i < (int)prefix.size();i++)
        {
            if(prefix[i]!=book_name[i])
            {
                return false;
            }
        }
        return true;
    }

};

bool CopmareBookByName(book & a , book &b )
{
    return a.book_name < b.book_name;
}
bool CopmareBookById(book & a , book &b)
{
    return a.book_id<b.book_id;
}
struct user
{
    int user_id;
    string user_name;
    int BorrowedBooks_id[MAX_BOOKS];
    int length;

    user()
    {
        user_id=length=0;
        user_name="";
    }
    void UserBorrowBook( int _book_id)
    {
        BorrowedBooks_id[length++]=_book_id;
    }
    void ReturnBorrowedBook(int _bookId)
    {
        bool removed=false;
        for(int i =0 ; i < length ; i++)
        {
            if(BorrowedBooks_id[i]==_bookId)
            {
                for(int j=i+1 ; j < length ; j++)
                {
                    BorrowedBooks_id[j-1]=BorrowedBooks_id[j];
                }
                removed=true;
                --length;
                break;
            }
        }
        if(!removed)
        {
            cout<<"USer "<<user_name<<" didnot take this book id: "<<_bookId<<"\n";

        }
    }
    bool ThisBookBorrowed(int bookid)
    {
        for(int i = 0 ; i< length ; i++)
        {
            if(BorrowedBooks_id[i]==bookid)
            {
                return true;
            }
        }
        return false;
    }
    void PrintAllbooksUserBorrowed()
    {
        sort(BorrowedBooks_id , BorrowedBooks_id+length);
        cout<<"User: "<<user_name<<" Id: "<<user_id<<"Borrowes Book Ids: ";
        for(int i = 0; i < length ; i++)
        {
            cout<<BorrowedBooks_id[i]<<" ";
        }
        cout<<"\n";
    }
    void ReadUserInfo()
    {
        cout<<"Enter User Name , Enter User Id\n";
        cin>>user_name>>user_id;
    }

};


struct Library_System
{
    book Books[MAX_BOOKS];
    user Users[MAX_USERS];
    int BooksCounter;
    int UsersCounters;
    Library_System()
    {
        BooksCounter=UsersCounters=0;
    }
   
    void StartSystem()
    {
        int flag = -1 ;
        while(flag==-1)
        {
           int choice=AdminChoice();
            switch (choice)
            {
            case 1:
                    AddNewBook();
                break;
            case 2:
                    SearchForBook();
                break;
            case 3:
                    printWhoBorrowerdThisBook();
                break;
            case 4:
                    PrintAllBooksSortedById();
                break;
            case 5:
                    PrintAllBooksSortedByName();
                break;
            case 6:
                    AddNewUser();
                break;
            case 7:
                    UserBorrowBook();
                break;
            case 8:
                    UserReturnBook();
                break;
            case 9:
                    PrintAllUsers();
                break;
            case 10:
                    flag=1;
                break;
            
            default:
                break;
            }
        }   
    }
    int AdminChoice()
    {
        int choice=-1;
        while ((choice==-1))
        {
            cout << "********************Library Menu*****************************\n";
                    cout << "1) AddNewBook\n";
                    cout << "2) SearchForBook\n";
                    cout << "3) printWhoBorrowerdThisBook\n";
                    cout << "4) PrintAllBooksSortedById\n";
                    cout << "5) PrintAllBooksSortedByName\n";
                    cout << "6) AddNewUser\n";
                    cout << "7) UserBorrowBook\n";
                    cout << "8) UserReturnBook\n";
                    cout << "9) PrintAllUsers\n";
                    cout << "10) Exit\n";
                cout<<"********************************************\n";
                cout<<"********************************************\n";
                cout << "\nEnter your menu choice: ";
                cin >> choice;
                if (!(1 <= choice && choice <= 10)) {
                    cout << "Invalid choice. Try again\n";
                    choice = -1;	
                }

        }
        return choice;
        
    }
void AddNewBook()
{
        
    Books[BooksCounter++].InsertBookInfo();
}
void SearchForBook()
{
    string prefix;
    cout<<"Enter The Book Prefix\n";
    cin>>prefix;
    bool flag = true;
    for(int i = 0 ; i < BooksCounter ; i++)
    {
        if(Books[i].BookHasThisPrefix(prefix))
        {
            cout<<Books[i].book_name<<"\n";
            flag=false;
        }
    }
    if(flag)
    {
        cout<<"No such Book\n";
    }
}
void printWhoBorrowerdThisBook()
{
    string _name;
    int Index = -1;
   cout<<"Enter The Book Name\n";
   cin>>_name;
   for(int i =0 ; i < BooksCounter ; i++)
   {
        if(Books[i].book_name==_name)
        {
            Index=i;
        }
   }
   if(Index==-1)
   {
        cout<<"Book Not Exist\n";
        return;
   }
   else
   {

   }
   if(Books[Index].total_borrowed==0)
   {
        cout<<"No borrowed Copies\n";
        return;
   }
   int bookid=Books[Index].book_id;
   for(int i = 0 ; i < UsersCounters ; i++)
   {
        if(Users[i].ThisBookBorrowed(bookid))
        {
            cout<<Users[i].user_name<<"\n";
        }
   }

    
}
void PrintAllBooksSortedById()
{
    sort(Books,Books+BooksCounter,CopmareBookById);
    for(int i = 0 ; i < BooksCounter ; i++)
    {
        cout<<"Book ID: "<<Books[i].book_id<<" Book Name: "<<Books[i].book_name<<" Total Copies: "<<Books[i].book_quantity<<"\n";

    }
}
 void PrintAllBooksSortedByName()
 {
    sort(Books,Books+BooksCounter,CopmareBookByName);
    for(int i = 0 ; i < BooksCounter ; i++)
    {
        cout<<"Book ID: "<<Books[i].book_id<<" Book Name: "<<Books[i].book_name<<" Total Copies: "<<Books[i].book_quantity<<"\n";

    }
 }
 void AddNewUser()
 {
            
            Users[UsersCounters++].ReadUserInfo();
 }
  void UserBorrowBook()
 {  
        int bookindex{-1} , userindex  {-1};
        string bookname , username;
        cout<<"Enter Book Name \n";
         cin>>bookname;
         cout<<"Enter User Name \n";
        cin>>username;
        for(int i = 0 ; i < BooksCounter ; i++)
        {
            if(Books[i].book_name==bookname)
            {
                    bookindex=i;
            }
        }
        for(int i = 0 ; i < UsersCounters ; i++)
        {
            if(Users[i].user_name==username)
            {
                    userindex=i;
            }
        }
        if(bookindex==-1 || userindex==-1)
        {
            cout<<"No Such A Book Or A User \n";
        }
        int userid=Users[userindex].user_id;
       int bookid=Books[bookindex].book_id;
       if(!Books[bookindex].BorrowBook(userid))
       {
        cout<<"No More Copies\n";
       }
       else
       {
            Users[userindex].UserBorrowBook(bookid);
       }


 }
 void UserReturnBook()
 {
    int bookindex{-1} , userindex  {-1};
        string bookname , username;
        cout<<"Enter Used Book Name \n";
         cin>>bookname;
         cout<<"Enter Used Book Name \n";
        cin>>username;
        for(int i = 0 ; i < BooksCounter ; i++)
        {
            if(Books[i].book_name==bookname)
            {
                    bookindex=i;
            }
        }
        for(int i = 0 ; i < UsersCounters ; i++)
        {
            if(Users[i].user_name==username)
            {
                    userindex=i;
            }
        }
        if(bookindex==-1 || userindex==-1)
        {
            cout<<"No Such A Book Or A User \n";
        }
       int bookid=Books[bookindex].book_id;
       Books[bookindex].UserRuturnBook();
       Users[userindex].ReturnBorrowedBook(bookid);

 }
  void PrintAllUsers()
  {

    for(int i = 0 ; i < UsersCounters ; i++)
    {
        Users[i].PrintAllbooksUserBorrowed();
    }
    cout<<"\n";
  }
};

int main()
{
    Library_System Library1;
    Library1.StartSystem();
    return 0 ;
}



