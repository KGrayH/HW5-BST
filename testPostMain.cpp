//Hensley H. and Windtell S.
//4/24/2026
//CSC 340 - Professor Karun Mehta
// Assignment 5 - Insta post manager using BST

#include "PostBST.h"
#include <iostream>
#include <string>
using namespace std;


int main() {

    PostBST bst;

    int choice;

    do {

        cout << "\n===== Instagram Post Manager =====\n";

        cout << "1. Add Post\n";
        cout << "2. Delete Post\n";
        cout << "3. Search Post\n";
        cout << "4. Display All Posts\n";
        cout << "5. Display Most Liked Post\n";
        cout << "6. Count Total Posts\n";
        cout << "7. Display Tree Height\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {

            int id, likes;
            string caption;

            cout << "Enter Post ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Caption: ";
            getline(cin, caption);

            cout << "Enter Likes: ";
            cin >> likes;

            bst.insertPost(Post(id, caption, likes));

            break;
        }

        case 2: {

            int id;

            cout << "Enter Post ID to delete: ";
            cin >> id;

            bst.deletePost(id);

            break;
        }

        case 3: {

            int id;

            cout << "Enter Post ID to search: ";
            cin >> id;

            bst.searchPost(id);

            break;
        }

        case 4:
            bst.displayPosts();
            break;

        case 5:
            bst.displayMostLiked();
            break;

        case 6:
            bst.totalPosts();
            break;

        case 7:
            bst.treeHeight();
            break;

        case 8:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    return 0;
}
