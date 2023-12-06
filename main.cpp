#include "Article.h"

#include <iostream>
#include <string>

int main()
{
    Article article1;
    article1.get_authors();
    article1.get_name();
    article1.get_quote();
    article1.get_size();
    article1.get_language();

    std::string authors[2] = { "A", "B" };
    Article article2(2, authors, "View", 58.5, 10000, "Russian");
    article2.get_authors();
    article2.get_name();
    article2.get_quote();
    article2.get_size();
    article2.get_language();

    Article article3(article2);
    std::string new_authors[3] = { "C", "D", "E" };
    article3.change_authors(3, new_authors);
    article3.change_name("By");
    article3.change_quote(46.5);
    article3.change_size(20000);
    article3.change_language("Bel");

    article3.get_authors();
    article3.get_name();
    article3.get_quote();
    article3.get_size();
    article3.get_language();

    std::string authors1[2] = { "A", "B" };
    Article article4(2, authors1, "View1", 58.5, 70000, "Russian");

    std::string authors2[2] = { "A", "C" };
    Article article5(2, authors2, "View2", 68.5, 1500, "Russian");

    std::string authors3[2] = { "C", "B" };
    Article article6(2, authors3, "View3", 78.5, 900, "Russian");

    Article list[3] = { article4, article5, article6};

    unsigned res1 = numb_of_articles(3, list, "B");
    std::cout << res1 << std::endl;

    double res2 = average_size(3, list, 60);
    std::cout << res2<< std::endl;

    list_of_authors(3, list);

    return 0;
}