#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#define MAX 10000
using namespace std;

struct Node{
	char* a; //Dynamic array a
	int n; //size of a
	Node* pLeft;
	Node* pRight;
};

struct Player
{
	string name, nation, club;
	int day, month, year, height, weight;
};


int sumArray(char *a, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

bool priority(Node* a, Node* b) {
	if (sumArray(a->a, a->n) > sumArray(b->a, b->n)) return true;
	else if (sumArray(a->a, a->n) == sumArray(b->a, b->n)) {
		if (a->n > b->n) return true;
		else return false;
	}
	else return false;
}

Node *createNode(char *a, int n) {
	Node *newnode = new Node;
	newnode->a = a;
	newnode->n = n;
	newnode->pLeft = newnode->pRight = NULL;
	return newnode;
}

int height(Node *root)
{
	if (root == NULL)
		return 0;
	return max(height(root->pLeft), height(root->pRight)) + 1;
}

void leftRotate(Node *&root) // Xoay trai
{
	Node *p = root->pRight;
	root->pRight = p->pLeft;
	p->pLeft = root;
	root = p;
}

void rightRotate(Node *&root) // Xoay phai
{
	Node *p = root->pLeft;
	root->pLeft = p->pRight;
	p->pRight = root;
	root = p;
}

void rebalance(Node *&root)
{
	if (height(root->pLeft) - height(root->pRight) > 1) // Mat can bang trai
	{
		if (height(root->pLeft->pLeft) > height(root->pLeft->pRight)) // Mat can bang trai trai
			rightRotate(root);
		else // Mat can bang trai phai
		{
			leftRotate(root->pLeft);
			rightRotate(root);
		}
	}
	else if (height(root->pLeft) - height(root->pRight) < -1) // Mat can bang phai
	{
		if (height(root->pRight->pRight) > height(root->pRight->pLeft)) // Mat can bang phai phai
			leftRotate(root);
		else // Mat can bang phai trai
		{
			rightRotate(root->pRight);
			leftRotate(root);
		}
	}
}

void insert(Node *&root, char *a, int n) {
	if (root == NULL) {
		root = createNode(a, n);
		return;
	}
	Node* newNode = createNode(a, n);
	if (priority(root, newNode)) {
		insert(root->pLeft, a, n);
	}
	else {
		insert(root->pRight, a, n);
	}
	rebalance(root);
}

int countChar(char* c) {
	int count = 0;
	for (int i = 0; i < sizeof(c); i++) {
		count++;
	}
	return count;
}

Node* createTree(string filename) {
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open()) {
		cout << "Khong mo duoc file Tree" << endl;;
		return NULL;
	}
	Node *root = NULL;
	
	string temp;
	while (!fin.eof()) {
		char *a;
		int n;
		fin.getline(a, MAX, ',');
		n = countChar(a);
		if(fin.getline(a, MAX, '\n')) break;
		insert(root, a, n);
		
	}

	fin.close();
	return root;

}

void printLevelKNode(Node* root, int k, int level)
{
	if (root == NULL)
		return;
	if (k == 1)
	{
		cout << "Level " << level << ": ";
		for (int i = 0; i < root->n; i++)
			cout << root->a[i] << " ";
		cout << "\n";
	}
	else
	{
		printLevelKNode(root->pLeft, k - 1, level);
		printLevelKNode(root->pRight, k - 1, level);
	}
}

void levelOrder(Node* pRoot)
{
	int h = height(pRoot);
	for (int i = 1; i <= h; i++)
		printLevelKNode(pRoot, i, i);
}

void remove(Node*& pRoot, int *a, int n) {

}

bool compareArray(int *a, int *b, int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			return false;
	return true;
}
/*
void copyArray(Node *&root, char *b, int n)
{
	delete[] root->a;
	root->n = n;
	root->a = new int[n];
	for (int i = 0; i < n; i++)
		root->a[i] = b[i];
}

void removeHelp(Node *&root, char *a, int n)
{
	if (root == NULL)
		return;
	int sumA = sumArray(a, n);
	int sumRoot = sumArray(root->a, root->n);
	if (sumA > sumRoot)
		removeHelp(root->pRight, a, n);
	else if (sumA < sumRoot)
		removeHelp(root->pLeft, a, n);
	else
	{
		if (n > root->n)
			removeHelp(root->pRight, a, n);
		else if (n < root->n)
			removeHelp(root->pLeft, a, n);
		else
		{
			if (priority(createNode(a, n), root->a))
				if (root->pLeft == NULL && root->pRight == NULL)
				{
					delete[] root->a;
					delete root;
					root = NULL;
				}
				else if (root->pLeft == NULL)
				{
					Node *temp = root;
					root = root->pRight;
					delete[] temp->a;
					delete temp;
					temp = NULL;
				}
				else if (root->pRight == NULL)
				{
					Node *temp = root;
					root = root->pLeft;
					delete[] temp->a;
					delete temp;
					temp = NULL;
				}
				else
				{
					Node *temp = root->pRight;
					while (temp->pLeft != NULL)
						temp = temp->pLeft;
					copyArray(root, temp->a, temp->n);
					removeHelp(root->pRight, temp->a, temp->n);
				}
			else
				removeHelp(root->pLeft, a, n);
		}
	}
}

void remove(Node*& pRoot, char *a, int n)
{
	if (pRoot == NULL)
		return;
	removeHelp(pRoot, a, n);
	rebalance(pRoot);
}
*/
void removeAll(Node *&root)
{
	if (root == NULL)
		return;
	removeAll(root->pLeft);
	removeAll(root->pRight);
	delete root;
	root = NULL;
}

long long power(long long a, long long b)
{
	long long res = 1;
	for (long long i = 0; i < b; i++)
	{
		res *= a;
		res %= (long long)pow(10, 9) + 7;
	}
	return res;
}

long long sumCha(string name)
{
	long long sum = 0;
	for (int i = 0; i < name.size(); i++)
	{
		if (name[i] < 'A' || name[i] > 'Z')
			continue;
		if (name[i] < 'a' || name[i] > 'z')
			continue;
		int temp = (int)name[i] - 65;
		sum += temp;
	}
	return sum;
}

long long sumDigit(int n)
{
	long long sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int abcd(Player p) {
	return p.height + p.weight + 1000 + p.year;
}

long long HashFunction(Player p)
{
	long long hash = 0;
	long long m = pow(10, 9) + 7;

	hash = power(p.day, sumCha(p.name)) * power(p.month, p.day) * power(sumDigit(p.year), p.month) * power(sumCha(p.name), sumDigit(p.year));
	hash = hash % m;
	return hash;
}

void Insert(Player *&hash_table, Player p, int size)
{
	long long hash = HashFunction(p) % 3000;
	while (hash_table[hash].name != "")
	{
		if (hash_table[hash].name == p.name)
			break;
		hash = (hash + 1) % 3000;
	}
	hash_table[hash] = p;
}

Player *createHash(string filename, int &size)
{
	ifstream ifs(filename, ios::in);
	if (!ifs)
	{
		cout << "Khong mo duoc file hash";
		return NULL;
	}
	string line;
	Player data;
	Player *hash_table = new Player[size];
	getline(ifs, line, '\n');
	while (getline(ifs, line, '\n'))
	{
		stringstream ss(line);
		getline(ss, data.name, ',');
		ss >> data.day;
		ss.ignore();
		ss >> data.month;
		ss.ignore();
		ss >> data.year;
		ss.ignore();
		ss >> data.height;
		if (data.height < 175)
			continue;
		ss.ignore();
		ss >> data.weight;
		ss.ignore();
		getline(ss, data.nation, ',');
		getline(ss, data.club, '\n');
		Insert(hash_table, data, size);
	}
	ifs.close();
	return hash_table;
}

void printHashtable(Player* hashTable, int size)
{
	for (int i = 0; i < size; i++)
		if (hashTable[i].name != "")
			cout << i << ": " << hashTable[i].name << " " << hashTable[i].day << " " << hashTable[i].month << " " << hashTable[i].year << " " << hashTable[i].height << " " << hashTable[i].weight << " " << hashTable[i].nation << " " << hashTable[i].club << "\n";
}

Player search(Player *hashTable, Player P)
{
	long long hash = HashFunction(P) % 3000;
	while (hashTable[hash].name != "")
	{
		if (hashTable[hash].name == P.name)
			return hashTable[hash];
		hash = (hash + 1) % 3000;
	}
	return Player();
}

void Remove(Player *hashTable, Player P)
{
	int index = HashFunction(P);
	while (hashTable[index].name != "")
	{
		if (hashTable[index].name == P.name)
			break;
		index++;
		if (index == 2500)
			index = 0;
	}
	if (hashTable[index].name == "")
		return;
	while (hashTable[index].name != "")
	{
		hashTable[index] = hashTable[(index + 1 == 2500 ? 0 : index + 1)];
		index = (index + 1 == 2500 ? 0 : index + 1);
	}
}


int main() {

	system("pause");
	return 0;
}
