#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {

private:
    std::string title;
    double ranking;
    bool hasRating;

public:
    Movie();
    Movie(const std::string& title, double ranking, bool hasRating);

    void setTitle(const std::string& title);
    void setRanking(double ranking);
    void setHasRating(bool hasRating);

    std::string getTitle() const;
    double getRanking() const;
    bool getHasRating() const;

};




#endif
