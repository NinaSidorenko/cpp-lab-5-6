#ifndef article_h
#define article_h

#include <string>

class Article
{
    unsigned numb_authors;
    std::string* authors;
    std::string name;
    double       quote;
    double       size;
    std::string language;
public:
    Article();
    Article(const Article& other);
    Article(unsigned new_numb_authors, std::string* new_authors, std::string new_name, double new_quote, double new_size, std::string new_language);
    ~Article();

    void get_authors();
    void get_name();
    void get_quote();
    void get_size();
    void get_language();

    void change_authors(unsigned new_numb_authors, std::string* new_authors);
    void change_name(std::string new_name);
    void change_quote(double new_quote);
    void change_size(double new_size);
    void change_language(std::string new_language);

    friend unsigned numb_of_articles(unsigned number, Article* articles, std::string author);
    friend double average_size(unsigned number, Article* articles, double quotes);
    friend void list_of_authors(unsigned number_articles, Article* articles);
};



#endif //article_h