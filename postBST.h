#ifndef POSTBST_H
#define POSTBST_H

#include "Post.h"

struct Node {

    Post data;
    Node* left;
    Node* right;

    Node(Post p) {
        data = p;
        left = nullptr;
        right = nullptr;
    }
};

class PostBST {

private:

    Node* root;

    // ===== Recursive Helper Functions =====

    Node* insert(Node* root, Post p);

    Node* deletePost(Node* root, int postID);

    Node* search(Node* root, int postID);

    Node* findMin(Node* root);

    void inorder(Node* root);

    void findMostLiked(Node* root, Post &maxPost);

    int countPosts(Node* root);

    int height(Node* root);

public:

    // Constructor
    PostBST();

    // Public Interface Functions

    void insertPost(Post p);

    void deletePost(int postID);

    void searchPost(int postID);

    void displayPosts();

    void displayMostLiked();

    void totalPosts();

    void treeHeight();
};

#endif
