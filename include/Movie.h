#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {

private:
    std::string title;
    double ranking;

    public:
    Movie();
    Movie(const std::string& title, double ranking);

    void setTitle(const std::string& title);
    void setRanking(double ranking);

    std::string getTitle() const;
    double getRanking() const;

};




#endif