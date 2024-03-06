//大佬救助代码作业2第一题
//#include<iostream>
//using namespace std;
//
//class node
//{
//public:
//    int data;
//    node* next;
//    node()
//    {
//        data = 0;
//        next = NULL;
//    }
//    node(int n)
//    {
//        data = n;
//        next = NULL;
//    }
//
//};
//class extendedChain
//{
//private:
//    node* head;
//public:
//    node* Creation(int num)
//    {
//        head = new node();
//        node* temp = head;
//        for (int i = 0; i < num; i++)
//        {
//            node* a = new node(i + 1);
//            temp->next = a;
//            temp = temp->next;
//        }
//        return head;
//    }
//    int length(node* head)
//    {
//        int bas = 0;
//        node* a = head;
//        while (a->next)
//        {
//            a = a->next;
//            bas++;
//        }
//        return bas;
//    }
//    node* getshead()
//    {
//        return head;
//    }
//    void print(node* head)
//    {
//        node* p = head;
//        while (p->next)
//        {
//            p = p->next;
//            cout << p->data << " ";
//        }
//    }
//
//};
//node* meld(extendedChain a, extendedChain b)
//{
//    int a1 = a.length(a.getshead());
//    int b1 = b.length(b.getshead());
//    bool ans = (a1 >= b1);
//    extendedChain c;
//    c.Creation(a1 + b1);
//    for (int i = 0; i < (a1 + b1); i++)
//    {
//        node* c0 = c.getshead();
//        while (c0->next)
//        {
//            c0->data = 0;
//            c0 = c0->next;
//        }
//    }
//    node* temp = new node();
//    if (ans)
//    {
//        node* d = c.getshead();
//        d = d->next;
//        node* e = a.getshead();
//        e = e->next;
//        node* f = b.getshead();
//        f = f->next;
//        for (int i = 0; i < b1; i++)
//        {
//            d->data = e->data;
//            d->next->data = f->data;
//            d = d->next->next;
//            e = e->next;
//            f = f->next;
//
//        }
//        for (int i = 0; (a1 - b1) && i < a1 - b1; i++)
//        {
//            d->data = e->data;
//            d = d->next;
//            e = e->next;
//        }
//    }
//    return c.getshead();
//}
//
//int main()
//{
//    extendedChain a;
//    extendedChain b;
//    int an1, an2;
//    cin >> an1 >> an2;
//    a.Creation(an1);
//    b.Creation(an2);
//    a.print(meld(a, b));
//
//}

//代码作业2第一题
#include<iostream>
using namespace std;
class Node {
public:
	int value = 0;
	Node* next = NULL;
	Node() { value = 0; next = NULL; }
	Node(int value) { this->value = value; this->next = NULL; }
	Node(int value, Node* next) {
		this->value = value;
		this->next = next;
	}
};
class extendedChain {
public:
	Node* head = new Node(0);
	Node* tail = head;
	int num = 0;
	void get(int n) {
		Node* temp = new Node(n);
		tail->next = temp;
		tail = temp;
		num++;
	}
	void print() {
		Node* temp = head;
		for (int i = 0; i < num; i++) {
			temp = temp->next;
			cout << temp->value << ' ';
		}
	}
};
void meld(extendedChain& a, extendedChain& b) {
	extendedChain* c = new extendedChain();
	c->num = a.num + b.num;
	Node* temp_a = a.head;
	Node* temp_b = b.head;
	for (int i = 0; i < min(a.num, b.num); i++) {

		temp_a = temp_a->next;
		temp_b = temp_b->next;
		Node* tempa = new Node(temp_a->value);
		Node* tempb = new Node(temp_b->value);
		c->tail->next = tempa;
		c->tail = tempa;
		c->tail->next = tempb;
		c->tail = tempb;
	}
	if (a.num < b.num) {
		for (int i = a.num; i < b.num; i++) {
			temp_b = temp_b->next;
			Node* tempb = new Node(temp_b->value);
			c->tail->next = tempb;
			c->tail = tempb;
		}
	}
	else if (a.num > b.num) {
		for (int i = b.num; i < a.num; i++) {
			temp_a = temp_a->next;
			Node* tempa = new Node(temp_a->value);
			c->tail->next = tempa;
			c->tail = tempa;
		}
	}
	c->print();
}
int main() {
	extendedChain a, b;
	a.get(1);
	b.get(8);
	a.get(3);
	b.get(6);
	a.get(5);
	b.get(4);
	a.get(7);
	a.get(9);

	meld(a, b);
}

//大佬救助代码作业2第二题（1）
//#include<iostream>
//using namespace std;
//
//class node
//{
//public:
//    int data;
//    node* next;
//    node* pre;
//    node()
//    {
//        data = 0;
//        next = pre = NULL;
//    }
//    node(int n)
//    {
//        data = n;
//        next = pre = NULL;
//    }
//
//};
//class extendedChain
//{
//private:
//    node* head;
//public:
//    extendedChain() { head = NULL; }
//    node* Creation(int num)
//    {
//        head = new node();
//        node* temp = head;
//        for (int i = 0; i < num; i++)
//        {
//            node* a = new node(i + 1);
//            temp->next = a;
//            a->pre = temp;
//            temp = temp->next;
//        }
//        temp->next = head->next;
//        return head;
//    }
//    int length(node* head)
//    {
//        int bas = 1;
//        node* a = head->next->next;
//        node* b = head->next;
//        while (a != b)
//        {
//            a = a->next;
//            bas++;
//        }
//        return bas;
//    }
//    node* getshead()
//    {
//        return head;
//    }
//    void print(node* head)
//    {
//        node* p = head;
//        while (p->next)
//        {
//            p = p->next;
//            cout << p->data << " ";
//        }
//    }
//    node** split()
//    {
//        extendedChain a, b;
//        a.Creation(0);
//        b.Creation(0);
//        node* tol[] = { a.getshead(), b.getshead() };
//        node* ch = this->getshead();
//        node* ah = a.getshead();
//        node* bh = b.getshead();
//        int j = this->length(ch);
//        for (int i = 0; i < j; i++)
//        {
//            ch = ch->next;
//            if (ch->data % 2)
//            {
//                node* t = new node(ch->data);
//                ah->next = t;
//                ah = ah->next;
//            }
//            else
//            {
//                node* v = new node(ch->data);
//                bh->next = v;
//                bh = bh->next;
//            }
//
//        }
//        return tol;
//    }
//
//
//};
//node** split(extendedChain c)
//{
//    extendedChain a, b;
//    a.Creation(0);
//    b.Creation(0);
//    node* tol[] = { a.getshead(), b.getshead() };
//    node* ch = c.getshead();
//    node* ah = a.getshead();
//    node* bh = b.getshead();
//    int j = c.length(ch);
//    for (int i = 0; i < j; i++)
//    {
//        ch = ch->next;
//        if (ch->data % 2)
//        {
//            node* t = new node(ch->data);
//            ah->next = t;
//            ah = ah->next;
//        }
//        else
//        {
//            node* v = new node(ch->data);
//            bh->next = v;
//            bh = bh->next;
//        }
//
//    }
//    return tol;
//}
//
//int main()
//{
//    extendedChain a;
//    a.Creation(15);
//    node** pos = a.split();
//    node* ah = pos[0];
//    node* bh = pos[1];
//    a.print(ah);
//    cout << endl;
//    a.print(bh);
//}

//代码作业2第二题（1）
//#include<iostream>
//using namespace std;
//class Node {
//public:
//	int value = 0;
//	Node* next = NULL;
//	Node* previous = NULL;
//	Node() { value = 0; next = NULL; previous = NULL; }
//	Node(int value) { this->value = value; this->next = NULL; previous = NULL; }
//	Node(int value, Node* next, Node* previous) {
//		this->value = value;
//		this->next = next;
//		this->previous = previous;
//	}
//	Node(int value, Node* previous) {
//		this->value = value;
//		this->previous = previous;
//	}
//};
//class extendedChain {
//public:
//	Node* head = new Node(0);
//	Node* tail = head;
//	int num = 0;
//	void get(int n) {
//		Node* temp = new Node(n);
//		tail->next = temp;
//		temp->previous = tail;
//		tail = temp;
//		num++;
//	}
//	void print() {
//		Node* temp = head;
//		for (int i = 0; i < num; i++) {
//			temp = temp->next;
//			cout << temp->value << ' ';
//		}
//	}
//};
//void meld(extendedChain& a, extendedChain& b) {
//	extendedChain* c = new extendedChain();
//	c->num = a.num + b.num;
//	Node* temp_a = a.head;
//	Node* temp_b = b.head;
//	for (int i = 0; i < min(a.num, b.num); i++) {
//
//		temp_a = temp_a->next;
//		temp_b = temp_b->next;
//		Node* tempa = new Node(temp_a->value);
//		Node* tempb = new Node(temp_b->value);
//		c->tail->next = tempa;
//		c->tail = tempa;
//		c->tail->next = tempb;
//		c->tail = tempb;
//	}
//	if (a.num < b.num) {
//		for (int i = a.num; i < b.num; i++) {
//			temp_b = temp_b->next;
//			Node* tempb = new Node(temp_b->value);
//			c->tail->next = tempb;
//			c->tail = tempb;
//		}
//	}
//	else if (a.num > b.num) {
//		for (int i = b.num; i < a.num; i++) {
//			temp_a = temp_a->next;
//			Node* tempa = new Node(temp_a->value);
//			c->tail->next = tempa;
//			c->tail = tempa;
//		}
//	}
//	c->print();
//}
//void split(extendedChain& c) {
//	Node* temp = c.head->next;
//	extendedChain* a = new extendedChain();
//	extendedChain* b = new extendedChain();
//	for (int i = 0; i < c.num; i += 2) {
//
//		a->get(temp->value);
//		if (temp->next) {
//			temp = temp->next;
//			b->get(temp->value);
//			temp = temp->next;
//		}
//	}
//	cout << "该序列的奇数索引为：";
//	a->print();
//	cout << endl;
//	cout << "该序列的其他值为：";
//	b->print();
//	cout << endl;
//}
//int main() {
//	extendedChain a, b;
//	a.get(0);
//	b.get(1);
//	a.get(2);
//	b.get(3);
//	a.get(4);
//	b.get(5);
//	a.get(6);
//	a.get(7);
//	a.print();
//	cout << endl;
//	split(a);
//	b.print();
//	cout << endl;
//	split(b);
//}

//大佬救助代码作业2第二题（2）
//#include<iostream>
//using namespace std;
//
//class node
//{
//public:
//    int data;
//    node* next;
//    node* pre;
//    node()
//    {
//        data = 0;
//        next = pre = NULL;
//    }
//    node(int n)
//    {
//        data = n;
//        next = pre = NULL;
//    }
//
//};
//class extendedChain
//{
//private:
//    node* head;
//public:
//    extendedChain() { head = NULL; }
//    node* Creation(int num)
//    {
//        head = new node();
//        node* temp = head;
//        for (int i = 0; i < num; i++)
//        {
//            node* a = new node(i + 1);
//            temp->next = a;
//            a->pre = temp;
//            temp = temp->next;
//        }
//        temp->next = head->next;
//        return head;
//    }
//    int length(node* head)
//    {
//        int bas = 1;
//        node* a = head->next->next;
//        node* b = head->next;
//        while (a != b)
//        {
//            a = a->next;
//            bas++;
//        }
//        return bas;
//    }
//    node* getshead()
//    {
//        return head;
//    }
//    void print(node* head)
//    {
//        node* p = head;
//        while (p->next)
//        {
//            p = p->next;
//            cout << p->data << " ";
//        }
//    }
//
//};
//node** split(extendedChain c)
//{
//    extendedChain a, b;
//    a.Creation(0);
//    b.Creation(0);
//    node* tol[] = { a.getshead(), b.getshead() };
//    node* ch = c.getshead();
//    node* ah = a.getshead();
//    node* bh = b.getshead();
//    int j = c.length(ch);
//    for (int i = 0; i < j; i++)
//    {
//        ch = ch->next;
//        if (ch->data % 2)
//        {
//            node* t = new node(ch->data);
//            ah->next = t;
//            ah = ah->next;
//        }
//        else
//        {
//            node* v = new node(ch->data);
//            bh->next = v;
//            bh = bh->next;
//        }
//
//    }
//    return tol;
//}
//
//int main()
//{
//    extendedChain a;
//    a.Creation(15);
//    node** pos = split(a);
//    node* ah = pos[0];
//    node* bh = pos[1];
//    a.print(ah);
//    cout << endl;
//    a.print(bh);
//}

//代码作业2第二题（2）
//#include<iostream>
//using namespace std;
//class Node {
//public:
//	int value = 0;
//	Node* next = NULL;
//	Node* previous = NULL;
//	Node() { value = 0; next = NULL; previous = NULL; }
//	Node(int value) { this->value = value; this->next = NULL; previous = NULL; }
//	Node(int value, Node* next, Node* previous) {
//		this->value = value;
//		this->next = next;
//		this->previous = previous;
//	}
//	Node(int value, Node* previous) {
//		this->value = value;
//		this->previous = previous;
//	}
//};
//class extendedChain {
//public:
//	Node* head = new Node(0);
//	Node* tail = head;
//	int num = 0;
//	void get(int n) {
//		Node* temp = new Node(n);
//		tail->next = temp;
//		temp->previous = tail;
//		tail = temp;
//		num++;
//	}
//	void print() {
//		Node* temp = head;
//		for (int i = 0; i < num; i++) {
//			temp = temp->next;
//			cout << temp->value << ' ';
//		}
//	}
//	void getNode(Node* thisnode) {
//		num++;
//		tail->next = thisnode;
//		tail = thisnode;
//	}
//	Node* takeNode() {
//		Node* temp = head->next;
//		head->next = temp->next;
//		num--;
//		return temp;
//	}
//};
//void meld(extendedChain& a, extendedChain& b) {
//	extendedChain* c = new extendedChain();
//	c->num = a.num + b.num;
//	Node* temp_a = a.head;
//	Node* temp_b = b.head;
//	for (int i = 0; i < min(a.num, b.num); i++) {
//
//		temp_a = temp_a->next;
//		temp_b = temp_b->next;
//		Node* tempa = new Node(temp_a->value);
//		Node* tempb = new Node(temp_b->value);
//		c->tail->next = tempa;
//		c->tail = tempa;
//		c->tail->next = tempb;
//		c->tail = tempb;
//	}
//	if (a.num < b.num) {
//		for (int i = a.num; i < b.num; i++) {
//			temp_b = temp_b->next;
//			Node* tempb = new Node(temp_b->value);
//			c->tail->next = tempb;
//			c->tail = tempb;
//		}
//	}
//	else if (a.num > b.num) {
//		for (int i = b.num; i < a.num; i++) {
//			temp_a = temp_a->next;
//			Node* tempa = new Node(temp_a->value);
//			c->tail->next = tempa;
//			c->tail = tempa;
//		}
//	}
//	c->print();
//}
//void split(extendedChain& c) {
//	int c_num = c.num;
//	extendedChain* a = new extendedChain();
//	extendedChain* b = new extendedChain();
//	for (int i = 0; i < c_num; i += 2) {
//		a->getNode(c.takeNode());
//		if (c.num) {
//			b->getNode(c.takeNode());
//		}
//	}
//	cout << "该序列的奇数索引为：";
//	a->print();
//	cout << endl;
//	cout << "该序列的其他值为：";
//	b->print();
//	cout << endl;
//}
//int main() {
//	extendedChain a, b;
//	a.get(0);
//	b.get(1);
//	a.get(2);
//	b.get(3);
//	a.get(4);
//	b.get(5);
//	a.get(6);
//	a.get(7);
//	a.print();
//	cout << endl;
//	split(a);
//	b.print();
//	cout << endl;
//	split(b);
//}