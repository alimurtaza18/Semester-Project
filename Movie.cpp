#include "Movie.h"

Movie::Movie(int movie_id, std::string title, std::vector<std::string> genre,
    std::string director, int year, double rating, std::string postURL) {
    this->movie_id = movie_id;
    this->title = title;
    this->genre = genre;
    this->director = director;
    this->year = year;
    this->rating = rating;
    this->postURL = postURL;
}

double Movie::getRating() {
    return rating;
}

void Movie::setRating(double rating) {
    this->rating = rating;
}