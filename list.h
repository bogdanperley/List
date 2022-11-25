struct Node {
	int data{};
	Node* prev{};
	Node* next{};
};

class List {
private:
	Node* node_{};

public:
	List() = default;
	~List();
	//List(const List &copy);
	void push_front(int val);
	void push_back(int val);
	void insert_node(Node* position, int val);
	void print();
	void delete_node(Node* position);
	void pop_front();
	void pop_back();
	Node* find_node(int val);
	void clear();
};