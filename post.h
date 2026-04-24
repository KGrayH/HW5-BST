#ifndef POST_H
#define POST_H

#include <iostream>
#include <string>

using namespace std;

class Post {

public:

    int postID;
    string caption;
    int likes;

    // Constructor
    Post(int id = 0, string cap = "", int like = 0) {
        postID = id;
        caption = cap;
        likes = like;
    }

    // Display Post Details
    void displayPost() const {

        cout << "Post ID: " << postID << endl;
        cout << "Caption: " << caption << endl;
        cout << "Likes: " << likes << endl;
        cout << "--------------------------" << endl;
    }
};

#endif
