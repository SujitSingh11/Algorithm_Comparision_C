
// C++ program for B-Tree insertion
#include <iostream>
using namespace std;

// A BTree node
class BTreeNode
{
    int *keys;     // An array of keys
    int t;         // Minimum degree (defines the range for number of keys)
    BTreeNode **C; // An array of child pointers
    int n;         // Current number of keys
    bool leaf;     // Is true when node is leaf. Otherwise false
public:
    BTreeNode(int _t, bool _leaf); // Constructor

    void insertNonFull(int k);

    void splitChild(int i, BTreeNode *y);

    void traverse();

    BTreeNode *search(int k); // returns NULL if k is not present.

    friend class BTree;
};

// A BTree
class BTree
{
    BTreeNode *root; // Pointer to root node
    int t;           // Minimum degree
public:
    // Constructor (Initializes tree as empty)
    BTree(int _t)
    {
        root = NULL;
        t = _t;
    }

    // function to traverse the tree
    void traverse()
    {
        if (root != NULL)
            root->traverse();
    }

    // function to search a key in this tree
    BTreeNode *search(int k)
    {
        return (root == NULL) ? NULL : root->search(k);
    }

    // The main function that inserts a new key in this B-Tree
    void insert(int k);
};

// Constructor for BTreeNode class
BTreeNode::BTreeNode(int t1, bool leaf1)
{
    // Copy the given minimum degree and leaf property
    t = t1;
    leaf = leaf1;

    keys = new int[2 * t - 1];
    C = new BTreeNode *[2 * t];

    // Initialize the number of keys as 0
    n = 0;
}

// Function to traverse all nodes in a subtree rooted with this node
void BTreeNode::traverse()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (leaf == false)
            C[i]->traverse();
        cout << " " << keys[i];
    }

    if (leaf == false)
        C[i]->traverse();
}

// Function to search key k in subtree rooted with this node
BTreeNode *BTreeNode::search(int k)
{
    int i = 0;
    while (i < n && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;

    if (leaf == true)
        return NULL;

    return C[i]->search(k);
}

// The main function that inserts a new key in this B-Tree
void BTree::insert(int k)
{
    // If tree is empty
    if (root == NULL)
    {
        // Allocate memory for root
        root = new BTreeNode(t, true);
        root->keys[0] = k; // Insert key
        root->n = 1;       // Update number of keys in root
    }
    else // If tree is not empty
    {
        if (root->n == 2 * t - 1)
        {
            BTreeNode *s = new BTreeNode(t, false);

            s->C[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);

            // Change root
            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

void BTreeNode::insertNonFull(int k)
{
    int i = n - 1;

    if (leaf == true)
    {
        while (i >= 0 && keys[i] > k)
        {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        n = n + 1;
    }
    else
    {
        while (i >= 0 && keys[i] > k)
            i--;

        if (C[i + 1]->n == 2 * t - 1)
        {
            splitChild(i + 1, C[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode *y)
{
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];

    n = n + 1;
}

int main()
{
    int degree;
    int keys;
    cout << "Enter minium  Degree of B-Tree: ";
    cin >> degree;
    BTree t(degree);
    cout << "Enter number of keys: ";
    cin >> keys;
    int key[keys];
    cout << "Enter " << keys << " keys: ";
    for (int i = 0; i < keys; i++)
    {
        cin >> key[i];
    }
    for (int i = 0; i < keys; i++)
    {
        t.insert(key[i]);
    }
    cout << "Traversal of the constucted tree is ";
    t.traverse();

    return 0;
}