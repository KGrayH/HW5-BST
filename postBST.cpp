#include "PostBST.h"
#include <iostream>
using namespace std;

// Constructor
PostBST::PostBST() {
    root = nullptr;
}

// ================= INSERT =================

Node* PostBST::insert(Node* root, Post p) {

    // TODO:
    // Implement recursive BST insertion
    // Rules:
    // 1. Insert based on postID
    // 2. No duplicate IDs allowed

    if (root == nullptr) {
        return new Node(p);
    }

    if (p.postID < root->data.postID) {
        root->left = insert(root->left, p);
    }
    else if (p.postID > root->data.postID) {
        root->right = insert(root->right, p);
    }
    else {
        cout << "Duplicated ID. Post not inserted.\n";
    }

    return root;   // Temporary return
}

void PostBST::insertPost(Post p) {

    root = insert(root, p);
}

// ================= SEARCH =================

Node* PostBST::search(Node* root, int postID) {

    // TODO:
    // Implement recursive search
if (root == nullptr) {
    return nullptr;
}
 if (postID == root->data.postID) {
        return root;
    }
    else if (postID < root->data.postID) {
        return search(root->left, postID);
    }
    else {
        return search(root->right, postID);
    }
}

void PostBST::searchPost(int postID) {

    Node* result = search(root, postID);

    if (result)
        result->data.displayPost();
    else
        cout << "Post Not Found\n";
}

// ================= DELETE =================

Node* PostBST::findMin(Node* root) {

    // TODO:
    // Find minimum value node

      if (root == nullptr) {
        return nullptr;
    }

    while (root->left != nullptr) {
        root = root->left;
    }

    return root;
}

Node* PostBST::deletePost(Node* root, int postID) {

    // TODO:
    // Implement recursive delete
    // Handle:
    // 1. Leaf node
    // 2. One child
    // 3. Two children

    if (root == nullptr) {
        return nullptr;
    }

    if (postID < root->data.postID) {
        root->left = deletePost(root->left, postID);
    }
    else if (postID > root->data.postID) {
        root->right = deletePost(root->right, postID);
    }
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deletePost(root->right, temp->data.postID);
    }

    return root;
}

void PostBST::deletePost(int postID) {

    root = deletePost(root, postID);
}

// ================= TRAVERSAL =================

void PostBST::inorder(Node* root) {

    // TODO:
    // Implement inorder traversal

        if (root == nullptr) {
        return;
    }

    inorder(root->left);
    root->data.displayPost();
    inorder(root->right);

}

void PostBST::displayPosts() {

    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    inorder(root);
}

// ================= MOST LIKED =================

void PostBST::findMostLiked(Node* root, Post &maxPost) {

    // TODO:
    // Traverse tree recursively
    // Update maxPost when needed
        if (root == nullptr) {
        return;
    }

    if (root->data.likes > maxPost.likes) {
        maxPost = root->data;
    }

    findMostLiked(root->left, maxPost);
    findMostLiked(root->right, maxPost);

}

void PostBST::displayMostLiked() {

    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    Post maxPost = root->data;

    findMostLiked(root, maxPost);

    cout << "\nMost Liked Post:\n";
    maxPost.displayPost();
}

// ================= COUNT =================

int PostBST::countPosts(Node* root) {

    // TODO:
    // Return total number of nodes

    if (root == nullptr) {
        return 0;
    }
    return 1 + countPosts(root->left) + countPosts(root->right);
}

void PostBST::totalPosts() {

    cout << "Total Posts: "
         << countPosts(root)
         << endl;
}

// ================= HEIGHT =================

int PostBST::height(Node* root) {
    // TODO:
    // Compute tree height recursively
    if (root == nullptr) {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

void PostBST::treeHeight() {

    cout << "Tree Height: "
         << height(root)
         << endl;
}
