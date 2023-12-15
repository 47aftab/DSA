#include <iostream>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : data(value), left(nullptr),
                          right(nullptr) {}
};
class BinarySearchTree
{
private:
    TreeNode *root;
    TreeNode *insert(TreeNode *root, int value)
    {
        if (root == nullptr)
        {
            return new TreeNode(value);
        }
        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insert(root->right, value);
        }
        return root;
    }
    TreeNode *findMin(TreeNode *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }
    TreeNode *remove(TreeNode *root, int value)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (value < root->data)
        {
            root->left = remove(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = remove(root->right, value);
        }
        else
        {
            if (root->left == nullptr)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            TreeNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp -> data);
        }
        return root;
    }
    bool search(TreeNode *root, int value)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->data == value)
        {
            return true;
        }
        else if (value < root->data)
        {
            return search(root->left, value);
        }
        else
        {
            return search(root->right, value);
        }
    }
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + countNodes(root->left) +
               countNodes(root->right);
    }
    void inOrderTraversal(TreeNode *root)
    {
        if (root != nullptr)
        {
            inOrderTraversal(root->left);
            std::cout << root->data << " ";
            inOrderTraversal(root->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}
    void insert(int value)
    {
        root = insert(root, value);
    }
    void remove(int value)
    {
        root = remove(root, value);
    }
    bool search(int value)
    {
        return search(root, value);
    }
    int countNodes()
    {
        return countNodes(root);
    }
    void displayInOrder()
    {
        std::cout << "In-order traversal of the BST: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};
int main()
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.displayInOrder();
    int searchValue = 40;
    cout << "Search for value " << searchValue << ": " << (bst.search(searchValue) ? "Found" : "Not Found")
         << endl;
    int deleteValue = 30;
    bst.remove(deleteValue);
    cout << "After deleting value " << deleteValue << " ";
    bst.displayInOrder();
    cout << "Number of nodes in the BST: " << bst.countNodes() << endl;
    return 0;
}