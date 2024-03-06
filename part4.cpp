//作业4第一题
//#include<iostream>
//using namespace std;
//class Node {
//public:
//	int addr = 0;
//	Node* next = NULL;
//	Node() { addr = 0; next = NULL; };
//	Node(int i) {
//		addr = i;
//		next = NULL;
//	}
//};
//class linkedNode {
//public:
//	Node* head=new Node(1);
//	linkedNode(int nummonkey) {
//		Node* temp = head;
//		for (int i = 1; i < nummonkey; i++) {
//			Node* newone = new Node(i+1);
//			temp->next = newone;
//			temp = newone;
//		}
//		temp->next = head;
//	}
//	void search(int num,int nummonkey) {
//		Node* count = head;
//		for (int j = 1; j < nummonkey; j++) {
//			for (int i = 1; i < num; i++) {
//				count = count->next;
//			}
//			Node* find = count;
//			while (find->next != count)
//				find = find->next;
//			find->next = count->next;
//			cout << count->addr << ' ';
//			count = count->next;
//		}
//		cout << count->addr;
//	}
//};
//int main() {
//	int nummonkey;
//	int num;
//	cin >> num >> nummonkey;
//	if (3 < nummonkey && nummonkey < 100 && num>1) {
//		linkedNode* monkey = new linkedNode(nummonkey);
//		monkey->search(num, nummonkey);
//	}
//	else
//		cout << "WRONG!";
//}

//作业4第二题
#include<iostream>
using namespace std;
class Stack {
public:
	int stacktop = 0;
	char* stack=new char();
	int arraylength = 20;
	Stack() {
		stacktop = 0;
		arraylength = 20;
	}
	bool empty() {
		if (!stacktop)
			return 1;
		return 0;
	}
	Stack* push(char theElement) {
		if (stacktop == arraylength)
			cout << "FULL!";
		else {
			stack[stacktop] = theElement;
			stacktop++;
		}
		return this;
	}
	char pop() {
		if (empty())
			return 0;
		else {
			stacktop--;
			return stack[stacktop];
		}
	}
	void print() {
		for (int i = 0; i < stacktop; i++) {
			cout << stack[i] << ' ';
		}
		cout << endl;
	}
};
void delete_all(Stack* a,char Char) {
	if (a->empty())cout << "EMPTY!" << endl;
	else {
		Stack* b = new Stack();
		for (int i = 0; !a->empty(); i++) {
			char temp = a->pop();
			if (temp != Char) {
				b->push(temp);
			}
		}
		Stack* c = new Stack();
		for (int i = 0; !b->empty(); i++)
			c->push(b->pop());
		for (int i = 0; !c->empty(); i++) {
			a->push(c->pop());
		}
		cout << "删除" << Char << "后该栈中元素为：";
		a->print();
	}
}
int main() {
	Stack* a = new Stack();
	delete_all(a, 'a');
	a->push('a');
	a->push('b');
	a->push('c');
	a->push('d');
	a->push('g');
	a->push('b');
	a->push('g');
	a->push('b');
	a->print();
	a->pop();
	a->print();
	delete_all(a, 'a');
	delete_all(a, 'b');
}