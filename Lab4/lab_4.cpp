#include <iostream>
#include <string>
#include <sstream>

class Book {
public:
    std::string bookName;
    std::string author;
    std::string year;
    std::string status;

    // Конструктор по умолчанию
    Book() : bookName("Unknown"), author("Unknown"), year("Unknown"), status("Unknown") {}

    // Параметризованный конструктор
    Book(const std::string& bookName, const std::string& author, const std::string& year, const std::string& status)
        : bookName(bookName), author(author), year(year), status(status) {
    }

    // Копирующий конструктор
    Book(const Book& other)
        : bookName(other.bookName), author(other.author), year(other.year), status(other.status) {
    }

    // Деструктор
    ~Book() {
        std::cout << bookName << " was deleted!" << std::endl;
    }
};

std::string uknownIfEmpty(std::string text) {
    if (text.empty()) {
        return "Unknown";
    }

    return text;
}

std::string replace(std::string text) {
    if (!text.empty() && text.front() == ' ') {
        text.erase(0, 1);
        return uknownIfEmpty(text);
    }

    return uknownIfEmpty(text);
}

int main() {
    using namespace std;
    char addNewBook;
    cout << "Do you want to add a new book? (y/n): ";
    cin >> addNewBook;
    cin.ignore();

    if (addNewBook == 'y') {
        string allBookInfo;

        cout << "Please, enter book details in format: book name, author, year, status\n";
        getline(cin, allBookInfo);

        stringstream ss(allBookInfo);
        string bookName, author, year, status;

        getline(ss, bookName, ',');
        getline(ss, author, ',');
        getline(ss, year, ',');
        getline(ss, status, ',');

        Book book(replace(bookName), replace(author), replace(year), replace(status)); //

        cout << "\nNew book added:\n";
        cout << "Book Name: " << book.bookName << "\nAuthor: " << book.author
            << "\nYear: " << book.year << "\nStatus: " << book.status << endl;
    }
    else {
        cout << "No new book added.\n";
    }

    return 0;
}

