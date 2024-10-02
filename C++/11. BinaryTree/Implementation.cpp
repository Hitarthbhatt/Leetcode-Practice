#include <iostream>
#include <queue>

using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {

    int data;
    cout << "Enter the data " << endl;
    cin >> data;

    root = new node(data);

    if (data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting left of " << data << endl;
    root->left = buildTree(root);
    cout << "Enter data for inserting right of " << data << endl;
    root->right = buildTree(root);

    return root;
}

void levelOrderTraversal(node* root) {

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {

        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // Purana level complete
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inOrder(node* root) { // L N R

    // Base case
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}

void preOrder(node* root) { // N L R

    // Base case
    if (root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root) { // L R N

    // Base case
    if (root == NULL) return;

    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
}


// Build the tree by using level order traversal.
void buildFromLevelOrderTraversal(node* &root) {

    queue<node*> q;
    cout << "Enter data for root node " << endl;
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);

    while (!q.empty()) {

        node* temp = q.front();
        q.pop();

        cout << "Enter data for inserting left of " << temp->data << endl;
        int leftData;
        cin >> leftData;
        
        if (leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data for inserting right of " << temp->data << endl;
        int rightData;
        cin >> rightData;
        
        if (rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }

}

int main() {

    node* root = NULL;

    // root = buildTree(root);
    // 5 4  3 2 -1 -1 1 -1 -1 8 -1 -1 6 -1 7 -1 -1

    buildFromLevelOrderTraversal(root);
    levelOrderTraversal(root);

    return 0;
}