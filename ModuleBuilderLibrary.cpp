#include <iostream>
#include <string>

class Book {
public:
    void setTitle(const std::string& title) {
        title_ = title;
    }

    void setAuthor(const std::string& author) {
        author_ = author;
    }

    void setYear(int year) {
        year_ = year;
    }

    void printDetails() const {
        std::cout << "Book details:" << std::endl;
        std::cout << "Title: " << title_ << std::endl;
        std::cout << "Author: " << author_ << std::endl;
        std::cout << "Year: " << year_ << std::endl;
    }

private:
    std::string title_;
    std::string author_;
    int year_;
};

class BookBuilder {
public:
    virtual void buildTitle() = 0;
    virtual void buildAuthor() = 0;
    virtual void buildYear() = 0;
    virtual Book getResult() = 0;
};

class ConcreteBookBuilder : public BookBuilder {
public:
    ConcreteBookBuilder() {
        book_ = new Book();
    }

    void buildTitle() override {
        book_->setTitle("Sample Book");
    }

    void buildAuthor() override {
        book_->setAuthor("John Doe");
    }

    void buildYear() override {
        book_->setYear(2023);
    }

    Book getResult() override {
        return *book_;
    }

private:
    Book* book_;
};

class Director {
public:
    void setBuilder(BookBuilder* builder) {
        builder_ = builder;
    }

    Book constructBook() {
        builder_->buildTitle();
        builder_->buildAuthor();
        builder_->buildYear();
        return builder_->getResult();
    }

private:
    BookBuilder* builder_;
};

int main() {
    ConcreteBookBuilder concreteBuilder;
    Director director;
    director.setBuilder(&concreteBuilder);

    Book book = director.constructBook();
    book.printDetails();

    return 0;
}
