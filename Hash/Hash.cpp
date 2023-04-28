#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

struct Node {
	string FIO;
	string data;
	long int num_pass;
	Node* next;
	Node(string fio, string dat, int num) : FIO(fio), data(dat), num_pass(num), next(nullptr) {}
	Node(string data) : data(data), FIO("NULL"), num_pass(0), next(nullptr) {}
	friend ostream& operator<<(ostream& out, const Node& node)
	{
		if (node.data == "not find") { out << "not find"; }
		else if (node.data == "delete") { out << "delete"; }
		else
			out << " | " << node.FIO << "\t" << node.data << "\t" << node.num_pass << " | ";
		return out;
	}
};

class HashTable {
private:
	vector<Node*> table;
	int size;
	int count_collision = 0;
	int hash(string str)
	{
		double a = ((sqrt(5) - 1) / 2) * get_sum_of_date(str);
		double c = size * (a - int(a));
		return int(c);
	}
	int get_sum_of_date(string str)
	{
		return stoi(str.substr(0, 2)) + stoi(str.substr(3, 2)) + stoi(str.substr(6, 4));
	}
public:
	HashTable(int s) : size(s)
	{
		table.resize(size, nullptr);
	}
	void insert(string FIO, string key, int num) {
		int index = hash(key);
		Node* newNode = new Node(FIO, key, num);
		if (table[index] == nullptr) {
			table[index] = newNode;
		}
		else {
			count_collision++;
			Node* current = table[index];
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void remove(string key) {
		int index = hash(key);
		if (table[index] == nullptr) {
			return;
		}
		else if (table[index]->data == key) {
			Node* temp = table[index];
			table[index] = temp->next;
			delete temp;
		}
		else {
			Node* current = table[index];
			while (current->next != nullptr && current->next->data != key) {
				current = current->next;
			}
			if (current->next != nullptr && current->next->data == key) {
				Node* temp = current->next;
				current->next = temp->next;
				delete temp;
			}
		}
	}

	Node find(string key) {
		int index = hash(key);
		Node* current = table[index];
		while (current != nullptr) {
			if (current->data == key) {
				return *current;
			}
			current = current->next;
		}
		return Node("not find");
	}

	void print() {
		cout << "Hash table contents:\n";
		for (int i = 0; i < size; i++) {
			cout << i << ": ";
			if (table[i] == nullptr) {
				cout << "empty\n";
			}
			else {
				Node* current = table[i];
				while (current != nullptr) {
					cout << *current;
					current = current->next;
				}
				cout << "\n";
			}
		}
		cout << "Number of collisions: " << count_collision << "\n";
	}
};

int main() {
	HashTable myTable(10);
	myTable.insert("Ivanov Ivan", "22.05.2000", 123456);
	myTable.insert("Petrov Petr", "01.01.1998", 654321);
	myTable.insert("Sidorov Andrey", "18.09.2001", 246813);

	cout << "Hash table contents after inserting:\n";
	myTable.print();

	myTable.remove("01.01.1998");

	cout << "\nHash table contents after removing:\n";
	myTable.print();

	Node result = myTable.find("22.05.2000");
	cout << "\nNode with key '22.05.2000': " << result << endl;

	return 0;
}