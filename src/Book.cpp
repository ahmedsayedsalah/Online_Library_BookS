#include "Book.h"
/*-------------------------------*/
//initializtion
int Book::count=0;
/*-------------------------------*/
//constructors
Book::Book()
{
    title="";
    isbn="";
    count++;
    id=count;
    category="";
    averageRating=0;
    //User author; //if pointer (User*author; in .h) & (author=new User; in .cpp)
    //hasAuthor=false;
    numRate=0;
    sumRate=0;
}
Book::Book(string title, string isbn, string category)
{
    this->title=title;
    this->isbn=isbn;
    this->category=category;
    count++;
    id=count;
    averageRating=0;
    //User author;
    //hasAuthor=false;
    numRate=0;
    sumRate=0;
}
Book::Book(const Book&book)
{
    title=book.title;
    isbn=book.isbn;
    category=book.category;
    id=book.id;
    averageRating=book.averageRating;
    numRate=book.numRate;
    sumRate=book.sumRate;
    setAuthor(book.author);
}
/*-------------------------------*/
//setter & getter
void Book::setTitle(string title)
{
    this->title=title;
}
 string Book::getTitle() const
 {
     return title;
 }
 void Book::setIsbn(string isbn)
 {
     this->isbn=isbn;
 }
 string Book::getIsbn() const
 {
     return isbn;
 }
 void Book::setId(int id)
 {
     this->id=id;
 }
 int Book::getId() const
 {
     return id;
 }
 void Book::setCategory(string category)
 {
     this->category=category;
 }
 string Book::getCategory()const
 {
     return category;
 }
 void Book::setAuthor(const User & author)
 {
     //hasAuthor=true;
     this->author=author;
 }
 User Book::getAuthor() const
 {
     return author;
 }
 double Book::getAverageRating () const
 {
     return averageRating;
 }
/*-------------------------------*/
void Book::rateBook(double rate)
{
    numRate++;
    sumRate+=rate;
    averageRating=sumRate/numRate;
}
/*-------------------------------*/
bool Book::operator==(const Book& book)
{
    return (title==book.title && isbn==book.isbn && category==book.category && averageRating==book.averageRating && author==(book.author));
}
istream &operator>>( istream &input, Book &book)
{
    cout<<"enter the book informatio by order\n";
    input>>book.title>>book.isbn>>book.category;
    return input;
}
ostream &operator<<(ostream &output, const Book &book)
{
    output<<"============Book "<<book.id<<" info==========\n";
    output<<"Title: "<<book.title;
    output<<"| Isbn: "<<book.isbn;
    output<<"| id: "<<book.id;
    output<<"| Category: "<<book.category;
    output<<"| AverageRate: "<<book.averageRating<<endl;
    if(book.author.getName()!="")
    {
        cout<<"============information about author============\n"<<(book.author);
    }
    cout<<"===============================================\n";
    return output;
}
