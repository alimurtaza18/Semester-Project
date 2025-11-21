#include <iostream>
#include <vector>
using namespace std; 

class Movie {

private:
	double rating;
public:
	int movie_id;
	string title;
	vector<string> genre;
	string director;
	int year;
	string postURL;


	Movie(int movie_id, string title, vector<string> genre, string director, int year, double rating, string postURL) {
		this->movie_id = movie_id;
		this->title = title;
		this->genre = genre;
		this->director = director;
		this->year = year;
		this->rating = rating;
		this->postURL = postURL;
	}
		double getRating() {
			return rating;
		}

		void setRating(double rating) {
			this->rating = rating; 
		}
};


class Movie_Node {
public: 
	Movie data; 
	Movie_Node* next;

	Movie_Node(Movie m) : data(m) { //data(m) 
		                            // = 
		                            //data = m
		next = NULL; 
	}

};


class Movie_List {
private: 
	Movie_Node* head; 
public:
	Movie_List() {
		 head = NULL; 
	}

	void insert(Movie m) {
		Movie_Node* newNode = new Movie_Node(m);
		if (head == NULL) {
			head = newNode; 
		}
		else{
			Movie_Node* ptr = head; 
			while (ptr->next != NULL) {
				ptr = ptr->next; 
			}
			ptr->next = newNode; 
		}
		}

	void remove(int id) {
		if (head == NULL) {
			cout << "The list is empty. " << endl;
		}
		else if (head->data.movie_id == id) {
			Movie_Node* temp = head; 
			head = head->next; 
			delete(temp); 
		}
		else {
			Movie_Node* ptr = head;
			while (ptr->next != NULL && ptr->next->data.movie_id != id) {
				ptr = ptr->next; 
			}
			if (ptr->next == NULL) {
				cout << "No matching item found. " << endl;
			}
			else if (ptr->next->data.movie_id == id) {
				Movie_Node* temp = ptr->next; 
				ptr->next = ptr->next->next; 
				delete(temp); 
			}
		
		}
	}

	void display() {
		Movie_Node* ptr = head; 
		int i = 1; 
		if (head == NULL) {
			cout << "No information to display. " << endl; 
		}
		else {
			while (ptr->next != NULL) {
				cout << "Movie " << i << endl;
				cout << "Movie id: " << ptr->data.movie_id << endl;
				cout << "Title: " << ptr->data.title << endl;
				cout << "Genre: ";
				for (int i = 0; i < ptr->data.genre.size(); i++) {
					cout << ptr->data.genre[i] << ", ";
				}
				cout << "Director: " << ptr->data.director << endl;
				cout << "Year: " << ptr->data.year << endl;
				cout << "Post URL: " << ptr->data.postURL << endl;
				ptr = ptr->next; 
				i++;
				cout << endl; 
			}
		}
	}
	
};


int main() {
	Movie_List list; 

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

}