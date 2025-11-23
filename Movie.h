#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>

class Movie {
private:
    double rating;
public:
    int movie_id;
    std::string title;
    std::vector<std::string> genre;
    std::string director;
    int year;
    std::string postURL;

    Movie(int movie_id, std::string title, std::vector<std::string> genre,
        std::string director, int year, double rating, std::string postURL);

    double getRating();
    void setRating(double rating);
};

#endif
