#include <bits/stdc++.h>
using namespace std;

// Huffman Tree Node
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Compare function for priority queue (min-heap)
struct Compare {
    bool operator()(Node* l, Node* r) { return l->freq > r->freq; }
};

// Generate Huffman Codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;
    if (!root->left && !root->right) huffmanCode[root->ch] = code;
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Build Huffman Tree and Encode
void huffmanCoding(string text) {
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto it = freq.begin(); it != freq.end(); it++)
        pq.push(new Node(it->first, it->second));

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    unordered_map<char, string> huffmanCode;
    generateCodes(pq.top(), "", huffmanCode);

    cout << "Huffman Codes:\n";
    for (auto it = huffmanCode.begin(); it != huffmanCode.end(); it++)
        cout << it->first << " : " << it->second << "\n";

    cout << "\nEncoded String: ";
    for (char ch : text) cout << huffmanCode[ch];
    cout << endl;
}

int main() {
    string text = "huffman";
    huffmanCoding(text);
    return 0;
}


/*
       Build a Min-Heap: Insert all characters with their frequencies into a priority queue.
       Merge Nodes: Extract the two smallest nodes, merge them into a new node, and reinsert until one node remains.
       Build Huffman Tree: The last remaining node is the root of the Huffman Tree.
       Generate Codes: Traverse the tree recursively to assign binary codes (left = 0, right = 1).
       Encode Data: Replace each character in the input with its corresponding Huffman code.
       
*/


/*

   Character Huffman Codes:
   h: 110
   u: 1011
   f: 100
   m: 011
   a: 010
   n: 1111
   c: 000
   o: 1010
   d: 001
   i: 1110
   g: 1101
   e: 0101
   x: 0111
   l: 0001
   p: 0010


*/