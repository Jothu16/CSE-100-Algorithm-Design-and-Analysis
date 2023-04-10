#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

//Attened Ghazal's office hours, helped me fix my code and pass all test cases.

class Node_Huffman {
public:
	char key;
	int freq;
	Node_Huffman* left;
	Node_Huffman* right;

	Node_Huffman(char Key, int Freq) {
		key = Key;
		freq = Freq; 
		left = right = NULL;
	}
	~Node_Huffman(){}
};

class minimum {
public:
	bool operator()(Node_Huffman* x, Node_Huffman* y) {
		return (x->freq > y->freq);
	}
};


void PrintCode(Node_Huffman *curr, string currCode, string &finalCode, char Letter) {
	if(curr == NULL)
		return;

  if(curr->key == Letter)//the node's key matches the desired letter
    if(finalCode.compare("") == 0)//and the final codeword we've got is not empty
      finalCode = currCode;//it has found the final codeword
  
  currCode.append("0");//adds a zero since it is going to search in left subtree
  
  PrintCode(curr->left, currCode, finalCode, Letter);//recursively call it on left subtree
  
  currCode.erase(currCode.length()-1,1);
  currCode.append("1"); //adds a one since it is going to search in right subtree 
  
  PrintCode(curr->right, currCode, finalCode, Letter);//recursively call it on righ subtree
}



string Print(Node_Huffman *root, char Letter) {// Function to print codewords. 
  string currCode = "";//keeps temporary codeword that is being updated in every recursive call
  string codeWord = "";//keeps final codeword
  
  PrintCode(root, currCode, codeWord, Letter);//start from root Node and compares every node's key value with desired letter until finds it then returns its codeWord
  return codeWord;
}




Node_Huffman* del(char key[], int freq[], int size) {

	priority_queue<Node_Huffman*, vector<Node_Huffman*>, minimum> myStack;
	
	//initializing the Nodes of HuffmanTree and store every letter right next to its freq and push it into the queue
	for (int i=0; i<size; i++){
		Node_Huffman* tempNode = new Node_Huffman(key[i], freq[i]);
		myStack.push(tempNode);
	}

	//Now generate the tree
	while(myStack.size() != 1) { //pop nodes from the queue one after another until there is only root node left in the queue
		Node_Huffman* left = myStack.top(); //read the Node with lowest freq. which is located on top of our priority queue
		myStack.pop();//take out that node from queue
		Node_Huffman* right =myStack.top();//read the Node with second lowest freq.
		myStack.pop();//again, take out that node from queue
		Node_Huffman* Z = new Node_Huffman('$',left->freq + right->freq);//generate a dummy node as their parent

		Z->left = left;
		Z->right = right;
		myStack.push(Z);//push the dummy node into the priority queue
	}

	return myStack.top();
}

int main() {
	int size;
	size = 6;;

	//Huffman_Codes key;
	char H[] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int freq[size];

	for(int i = 0; i < size; i++){
		int n;
		cin>>n;
		freq[i] = n;
		//H[i] = ((char)(1+i));
	} 
	Node_Huffman *root = del(H, freq, size);

	// Print Huffman code of every letter
	cout << "A:" << Print(root,'A') << endl;
	cout << "B:" << Print(root,'B') << endl;
	cout << "C:" << Print(root,'C') << endl;
	cout << "D:" << Print(root,'D') << endl;  
	cout << "E:" << Print(root,'E') << endl;
	cout << "F:" << Print(root,'F') << endl;


	//delete H, freq, size;
	return 0;
}
