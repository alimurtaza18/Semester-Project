#ifndef MOVIELIST_H
#define MOVIELIST_H

#include "Movie.h"
#include "Stack.h"

class Movie_Node {
public:
    Movie data;
    Movie_Node* next;
    Movie_Node(Movie m);
};

class Movie_List {
private:
    Movie_Node* head;
public:
    Movie_List();
    void insert(Movie m);
    void remove(int id);
    void display();
    void movie_search(std::string movie, Stack& browsing_history);
};

#endif
