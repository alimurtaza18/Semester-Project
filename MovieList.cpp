#include "MovieList.h"
#include <iostream>
using namespace std;

Movie_Node::Movie_Node(Movie m) : data(m) {
    next = NULL;
}

Movie_List::Movie_List() {
    head = NULL;
}

void Movie_List::insert(Movie m) {
    Movie_Node* newNode = new Movie_Node(m);
    if (head == NULL) {
        head = newNode;
    }
    else {
        Movie_Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void Movie_List::remove(int id) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
    }
    else if (head->data.movie_id == id) {
        Movie_Node* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        Movie_Node* ptr = head;
        while (ptr->next != NULL && ptr->next->data.movie_id != id) {
            ptr = ptr->next;
        }
        if (ptr->next == NULL) {
            cout << "No matching item found." << endl;
        }
        else if (ptr->next->data.movie_id == id) {
            Movie_Node* temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
        }
    }
}

void Movie_List::display() {
    Movie_Node* ptr = head;
    int i = 1;
    if (head == NULL) {
        cout << "No information to display." << endl;
    }
    else {
        while (ptr != NULL) {
            cout << "Movie " << i << endl;
            cout << "Movie id: " << ptr->data.movie_id << endl;
            cout << "Title: " << ptr->data.title << endl;
            cout << "Genre: ";
            for (int j = 0; j < ptr->data.genre.size(); j++) {
                cout << ptr->data.genre[j];
                if (j < ptr->data.genre.size() - 1) cout << ", ";
            }
            cout << endl;
            cout << "Director: " << ptr->data.director << endl;
            cout << "Year: " << ptr->data.year << endl;
            cout << "Post URL: " << ptr->data.postURL << endl;
            ptr = ptr->next;
            i++;
            cout << endl;
        }
    }
}

void Movie_List::movie_search(string movie, Stack& browsing_history) {
    Movie_Node* ptr = head;
    bool flag = false;
    while (ptr != NULL) {
        if (movie == ptr->data.title) {
            cout << "Movie Found" << endl;
            cout << "Movie ID: " << ptr->data.movie_id << endl;
            cout << "Movie Title: " << ptr->data.title << endl;
            cout << "Genre: ";
            for (int i = 0; i < ptr->data.genre.size(); i++) {
                cout << ptr->data.genre[i];
                if (i < ptr->data.genre.size() - 1) cout << ", ";
            }
            cout << endl;
            cout << "Movie Director: " << ptr->data.director << endl;
            cout << "Movie Year: " << ptr->data.year << endl;
            cout << "Movie PostURL: " << ptr->data.postURL << endl;
            flag = true;
            browsing_history.push(ptr->data.title);
            return;
        }
        ptr = ptr->next;
    }
    if (flag == false) {
        cout << "Movie not found" << endl;
    }
}