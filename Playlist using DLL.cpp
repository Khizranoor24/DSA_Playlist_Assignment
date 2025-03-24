#include <iostream>
#include <string>
using namespace std;

// Node structure for doubly linked list
struct Song {
    string name;
    Song* prev;
    Song* next;
    
    Song(string songName) {
        name = songName;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
private:
    Song* head;
    Song* tail;
public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    // Add song to the end
    void addSong(string songName) {
        Song* newSong = new Song(songName);
        if (!head) {
            head = tail = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << "Added: " << songName << endl;
    }

    void displayPlaylist() {
        if (!head) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        Song* temp = head;
        cout << "Playlist: " << endl;
        while (temp) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "END" << endl;
    }

    void deleteSong(string songName) {
        if (!head) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        Song* temp = head;
        while (temp && temp->name != songName) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Song not found!" << endl;
            return;
        }
        if (temp == head) {
            head = head->next;
            if (head) head->prev = NULL;
        } else if (temp == tail) {
            tail = tail->prev;
            if (tail) tail->next = NULL;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
        cout << songName <<" Is Deleted from the playlist "<< endl;
    }
};

int main() {
    Playlist myPlaylist;
    myPlaylist.addSong("Song A");
    myPlaylist.addSong("Song B");
    myPlaylist.addSong("Song C");
    myPlaylist.displayPlaylist();
    myPlaylist.deleteSong("Song B");
    myPlaylist.displayPlaylist();
    return 0;
}

