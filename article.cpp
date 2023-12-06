#include "article.h"
#include <iostream>
#include <string>

Article::Article() :
    numb_authors(0), authors(NULL), name(""), quote(0), size(0), language("")
{
}

Article::Article(const Article& other) :
    numb_authors(other.numb_authors), authors(NULL), name(other.name), quote(other.quote), size(other.size), language(other.language)
{
    authors = new std::string[numb_authors];
    for (unsigned i = 0; i < numb_authors; ++i)
    {
        authors[i] = other.authors[i];
    }
}
Article::Article(unsigned new_numb_authors, std::string* new_authors, std::string new_name, double new_quote, double new_size, std::string new_language) :
    numb_authors(new_numb_authors), authors(NULL), name(new_name), quote(new_quote), size(new_size), language(new_language)
{
    authors = new std::string[numb_authors];
    for (unsigned i = 0; i < numb_authors; ++i)
    {
        authors[i] = new_authors[i];
    }
}
Article::~Article()
{
    delete[] authors;
}

void Article::get_authors()
{
    for (unsigned i = 0; i < numb_authors; ++i)
    {
        std::cout << authors[i] << ' ';
    }
    std::cout << std::endl;
}
void Article::get_name()
{
    std::cout << name << std::endl;
}
void Article::get_quote()
{
    std::cout << quote << std::endl;
}
void Article::get_size()
{
    std::cout << size << std::endl;
}
void Article::get_language()
{
    std::cout << language << std::endl;
}

void Article::change_authors(unsigned new_numb_authors, std::string* new_authors)
{
    delete[] authors;
    numb_authors = new_numb_authors;
    authors = new std::string[numb_authors];
    for (unsigned i = 0; i < numb_authors; ++i)
        authors[i] = new_authors[i];
}
void Article::change_name(std::string new_name)
{
    name = new_name;
}
void Article::change_quote(double new_quote)
{
    quote = new_quote;
}
void Article::change_size(double new_size)
{
    size = new_size;
}
void Article::change_language(std::string new_language)
{
    language = new_language;
}

unsigned numb_of_articles(unsigned number, Article* articles, std::string author)
{
    unsigned count = 0;
    for (unsigned i = 0; i < number; ++i)
    {
        for (unsigned j = 0; j < articles[i].numb_authors; ++j)
            if (author == articles[i].authors[j])
                count += 1;
    }
    return count;
}

double average_size(unsigned number, Article* articles, double quotes)
{
    double sum_size = 0;
    unsigned count = 0;
    for (unsigned i = 0; i < number; ++i)
    {
        if (articles[i].quote > quotes)
        {
            sum_size += articles[i].size;
            count += 1;
        }
    }
    double average = sum_size / count;
    return average;
}

struct Author
{
    std::string name_author;
    double quote_articles;
    int numb_articles;
};


void list_of_authors(unsigned number_articles, Article* articles)
{
    unsigned n = 0;
    Author* authors = new Author[n];
    for (unsigned i = 0; i < number_articles; ++i)
    {
        for (unsigned j = 0; j < articles[i].numb_authors; ++j)
        {
            bool f = false;
            for (unsigned k = 0; k < n; ++k)
            {
                if (articles[i].authors[j] == authors[k].name_author)
                {
                    authors[k].numb_articles += 1;
                    authors[k].quote_articles += articles[i].quote;
                    f = true;
                    break;
                }
            }
            if (f == false)
            {
                Author* tmp = new Author[n + 1];
                for (size_t m = 0; m < n; ++m)
                {
                    tmp[m] = authors[m];
                }
                tmp[n].name_author = articles[i].authors[j];
                tmp[n].quote_articles = articles[i].quote;
                tmp[n].numb_articles = 1;
                n = n + 1;
                
                authors = new Author[n];
                for (size_t m = 0; m < n; ++m)
                {
                    authors[m] = tmp[m];
                }
                delete[] tmp;
            }
        }
    }
    for (unsigned i = 0; i < n; ++i)
    {
        for (unsigned j = i + 1; j < n; ++j)
        {
            if ((authors[i].quote_articles / authors[i].numb_articles) < (authors[j].quote_articles / authors[j].numb_articles))
            {
                Author tmp;
                tmp = authors[i];

                authors[i] = authors[j];

                authors[j] = tmp;
            }
        }
    }
    for (unsigned i = 0; i < n; ++i)
    {
        double av = authors[i].quote_articles / authors[i].numb_articles;
        std::cout << authors[i].name_author << " " << av << std::endl;
    }
}



    /*std::string *authors = new std::string[number_articles];
    double *quote_articles = new double [number_articles];
    int *numb_articles = new int [number_articles];
    for (unsigned i = 0; i < number_articles; ++i)
    {
        for (unsigned j = 0; j < articles[i].numb_authors; ++j)
        {
            for (unsigned k = 0; k < number_articles; ++k)
            {
                if (articles[i].authors[j] == authors[k])
                {
                    numb_articles[k] = numb_articles[k] + 1;
                    quote_articles[k] = quote_articles[k] + articles[i].quote;
                }
                else
                {

                }
            }
        }
    }*/
