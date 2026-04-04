#include "../include/Movie.h"

Movie::Movie(){
    title= "";
    ranking = 0.0;
    hasRating = false;
}

Movie::Movie(const std::string& title, double ranking, bool hasRating){
    this->title = title;
    this->ranking = ranking;
    this->hasRating = hasRating;
}

void Movie::setTitle(const std::string& title){
    this->title = title;

}

void Movie::setRanking(double ranking){
    this->ranking = ranking;
}

void Movie::setHasRating(bool hasRating) {
    this->hasRating = hasRating;
}

std::string Movie::getTitle() const{
    return title;
}

double Movie::getRanking() const {
    return ranking;
}

bool Movie::getHasRating() const {
    return hasRating;
}
