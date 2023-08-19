#include "BooksList.h"
/*------------------------------------------*/
BookList::BookList()
{
    capacity=0;
    booksCount=0;
}
BookList::BookList(int capacity)
{
    this->capacity=capacity;
    books=new Book[capacity];
    booksCount=0;
}
void BookList::addBook(const Book& book)// at the end of the array.
{
    if(booksCount<capacity)
    {
        books[booksCount]=book;//author not =
        books[booksCount].setId(booksCount+1);
        booksCount++;
    }
    else
        cout<<"Array Is Full\n";
}
Book* BookList::searchBook(string title)
{
    for(int i=0;i<booksCount;i++)
    {
        if(books[i].getTitle()==title)
            return &books[i];
    }
    return nullptr;
}
Book* BookList::searchBook(int id)
{
    for(int i=0;i<booksCount;i++)
    {
        if(books[i].getId()==id)
            return &books[i];
    }
    return nullptr;
}
void BookList::deleteBook(int id)//delete a book
{
    bool x=true;
    for(int i=0;i<booksCount-1;i++)
    {
        if(books[i].getId()==id&&x)
        {
            x=false;
            i--;
            continue;
        }
        else if(!x)
        {
            books[i]=books[i+1];
            books[i].setId(i+1);
        }
    }
    booksCount--;
    capacity--;
}
Book BookList::getTheHighestRatedBook()
{
    double highRate=0;
    int index;
    for(int i=0;i<booksCount;i++)
    {
        if(highRate<books[i].getAverageRating())
        {
            highRate=books[i].getAverageRating();
            index=i;
        }
    }
    return books[index];
}
void BookList::getBooksForUser(const User &user)
{
    bool x=false;
    for(int i=0;i<booksCount;i++)
    {
        if(books[i].getAuthor()==user)
        {
            cout<<books[i];
            x=true;
        }
    }
    if(!x)
    {
        cout<<"there are not any books for this author\n";
    }
}
Book& BookList::operator[] (int index)
{
    if(index<0 && index>=booksCount)
    {
        cout<<"index out of bounds\n";
        exit(1);
    }

    return books[index];
}
ostream&operator<<(ostream &output,const BookList & bookList) //to display all books
{
    for(int i=0;i<bookList.booksCount;i++)
    {
        output<<bookList.books[i];
    }
    return output;
}
BookList::~BookList()
{
    delete[]books;
}
