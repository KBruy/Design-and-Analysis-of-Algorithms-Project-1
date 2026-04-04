#include "../include/Movie.h"

Movie::Movie(){
    title= "";
    ranking = 0.0;
}

Movie::Movie(const std::string& title, double ranking){
    this ->title = title;
    this ->ranking = ranking;

}

void Movie::setTitle(const std::string& title){
    this->title = title;

}

void Movie::setRanking(double ranking){
    this->ranking = ranking;
}

std::string Movie::getTitle() const{
    return title;
}

double Movie::getRanking() const {
    return ranking;
}

