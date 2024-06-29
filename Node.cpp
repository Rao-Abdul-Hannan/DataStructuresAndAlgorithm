class Node{
	public:
		int data;
		Node *next;//TO point to next node, null otherwise
		//With default value of parameter, we can use the constructor with two as well as one parameter
		Node (int d, Node *n = nullptr){
			data = d;
			next = n;
		}
};
