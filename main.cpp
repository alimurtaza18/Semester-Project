#include <iostream>
#include <string>
#include <vector>
#include "MovieList.h"
#include "Stack.h"
using namespace std;

int main() {
    Movie_List list;
    string movie_name;
    Stack browsing_history;

    vector<string> genre_vector7 = { "Drama", "Mystery", "Thriller" };
    Movie m1(1007, "Dark", genre_vector7, "Baran bo Odar, Jantje Friese", 2017, 8.8,
        "https://www.imdb.com/title/tt5753856/");

    vector<string> genre_vector2 = { "Action", "Adventure", "Sci-Fi" };
    Movie m2(1002, "Avengers: Endgame", genre_vector2, "Anthony Russo, Joe Russo", 2019, 8.4,
        "https://www.imdb.com/title/tt4154796/");

    vector<string> genre_vector3 = { "Crime", "Drama", "Mystery" };
    Movie m3(1003, "Breaking Bad", genre_vector3, "Vince Gilligan", 2008, 9.5,
        "https://www.imdb.com/title/tt0903747/");

    vector<string> genre_vector4 = { "Animation", "Adventure", "Comedy" };
    Movie m4(1004, "Spider-Man: Into the Spider-Verse", genre_vector4, "Bob Persichetti, Peter Ramsey, Rodney Rothman", 2018, 8.4,
        "https://www.imdb.com/title/tt4633694/");

    vector<string> genre_vector5 = { "Drama", "Romance", "War" };
    Movie m5(1005, "Titanic", genre_vector5, "James Cameron", 1997, 7.8,
        "https://www.imdb.com/title/tt0120338/");

    vector<string> genre_vector6 = { "Horror", "Thriller", "Mystery" };
    Movie m6(1006, "The Haunting of Hill House", genre_vector6, "Mike Flanagan", 2018, 8.6,
        "https://www.imdb.com/title/tt6763664/");

    list.insert(m1);
    list.insert(m2);
    list.insert(m3);
    list.insert(m4);
    list.insert(m5);
    list.insert(m6);

    list.display();

    cout << "Enter a movie name: ";
    getline(cin, movie_name);
    list.movie_search(movie_name, browsing_history);
    browsing_history.Browsing_history();

    return 0;
}