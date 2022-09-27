// Library book lending
#include<iostream>
#include<vector>
#include<string>
#include<windows.h>
#include<conio.h>
using namespace std;

void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void colored_text()
{
    int a = 4, b =14, c = 7;
    string s1 = "NOTE : ", s2 = "Enter 'end' to exit";
    Color(a); // Red
    cout<<s1;
    Color(b); // Yellow
    cout<<s2<<endl;
    Color(c); // Default white
}

class book_shop
{
    protected:
        vector<string> book; //0 length vector
        vector<string> end_book;
    public:
        int count = 10;
        int white = 7;
        int green = 10;
        void book_shelf() // Default books
        {
            book.push_back("Paradise Lost");
            book.push_back("Phantom of the Opera");
            book.push_back("Trapped");
            book.push_back("Frankenstein");
            book.push_back("Moby Dick");
            book.push_back("Lesser Key of Solomon");
            book.push_back("Bible");
            book.push_back("Lord of the Rings");
            book.push_back("Dante's Inferno");
            book.push_back("The Wizard of Oz");
        }
        void display()
        {
            cout<<"\nBooks available :\n"<<endl;
            for(int i=0;i<count;i++)
            {
                cout<<i+1<<") "<<book[i]<<endl;
            }
        }
        void end();
        void access(string *s)
        {
            for(int i=0;i<count;i++)
            {
                if(book[i]==(*s))
                {
                    cout<<"---------------------\n"<<"Book Issued: ";
                    Color(green);
                    cout<<book[i]<<endl;
                    Color(white);
                    end_book.push_back(book[i]); // Adds book to end list
                    book.erase(book.begin()+i);
                    count--;
                    cout<<"-----------X-----------"<<endl;
                    goto Q;
                }
                else if(i==(count-1))
                {
                    cout<<"\nERROR : Book N/A"<<endl;
                    cout<<"-----------X-----------"<<endl;
                    goto Q;
                }
            }
            Q:
            exit;
        }
        void give_book(int a);
        void clear_book() // For clearing data
        {
            book.clear();
        }
};

void book_shop :: give_book(int a)
{
    string name;
    for(int i=0;i<a;i++)
    {
        // For by-passing the re-occuring problem of getline() not working the 1st time
        if(i==0) 
        {
            name = "Empty";
            getline(cin,name);
        }
        cout<<"Enter book name : ";
        getline(cin,name);
        book.push_back(name);
        count++;
    }
}

void book_shop :: end()
{
    int normal = 7, clr = 13;
    cout<<"\nTotal books issued: "<<end_book.size()<<endl;
    cout<<"List of issued books:"<<endl;
    for(int i=0;i<end_book.size();i++)
    {
        cout<<i+1<<") ";
        Color(13);
        cout<<end_book[i]<<endl;
        Color(normal);
    }
}

int main()
{
    book_shop bk1;
    string str,str2,str3;
    int num;
    bk1.book_shelf();
    cout<<"Borrowing book | ENTER -> 'borrow'"<<endl;
    cout<<"Returning book | ENTER -> 'return"<<endl;
    cin>>str2;
    if(str2=="return")
    {
        cout<<"Enter no. of books you want to give back: ";
        cin>>num;
        bk1.give_book(num);
        goto start;
    }
    else if(str2=="borrow")
    {
        start:
        {
        str = "Empty";
        int val = bk1.count;
        for(int i=0;i<val;i++)
        {
            bk1.display();
            // For bypassing the re-occuring problem of getline() not working the 1st time
            if(i==0 && str2=="borrow") 
            {
                getline(cin,str); //-> Have to enter whitespace for program to continue
            }

            colored_text();
            cout<<"Enter book name: ";

            int x = 10, y = 7;
            Color(x); // Green
            getline(cin,str);
            Color(y); // Default white

            if(str=="end")
            {
                bk1.end();
                break;
            }
            bk1.access(&str);
            if(i==(val-1))
            {
                cout<<"NO BOOKS LEFT!"<<endl;
            }
        }
        }
    }
    bk1.clear_book();
    return 0;
}