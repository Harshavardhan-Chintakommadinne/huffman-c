#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char data;
    int freq;
    Node *left, *right;
    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Comparator for priority queue (min-heap)
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Function to print Huffman codes in preorder traversal
void printCodes(Node* root, string code) {
    if (!root) return;

    // Leaf node — print the character and its code
    if (root->data != '$')
        cout << code << " ";

    // Traverse left and right subtrees
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Build Huffman Tree and print codes
void HuffmanCodes(string S, int f[], int N) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Step 1: Create a leaf node for each character and push it into the priority queue
    for (int i = 0; i < N; i++)
        pq.push(new Node(S[i], f[i]));

    // Step 2: Build the Huffman Tree
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    // Step 3: Print Huffman codes (preorder)
    printCodes(pq.top(), "");
}

// Driver code
int main() {
    string S = "abcdef";
    int f[] = {5, 9, 12, 13, 16, 45};
    int N = S.size();

    HuffmanCodes(S, f, N);
    return 0;
}
