////第五次作业第一题：
//#include<iostream>
//using namespace std;
//class HashTable {
//public:
//	HashTable(int divisor_input=11) {//除数
//		divisor = divisor_input;
//		ht = new int[divisor];
//		neverused = new bool[divisor];//是否被使用过
//		empty = new bool[divisor];//是否为空
//		for (int i = 0; i < divisor; i++) {
//			neverused[i] = true;
//			empty[i] = true;
//		}//初始化
//	};
//	int hSearch(int k) {
//		//找到相应应该插入或者删除的位置
//		int i = k % divisor;
//		int j = i;
//		do {
//			if (empty[j]&&neverused[j] || ht[j] == k)
//				return j;//如果搜索到的这个为空且没有用过或者已经有了该值
//			j = (j + 1) % divisor;//否则向后查找
//		} while (j != i);//防止重复寻找
//		return j;
//	}
//	HashTable Insert(const int& e) {
//		int k = e;
//		int b = hSearch(k);//b为其应插入的位置
//		if (empty[b]||ht[b]==k) {
//			empty[b] = false;
//			ht[b] = e;
//			neverused[b] = false;
//			return *this;
//		}
//		else cout << "FULL!";
//		return *this;
//	}
//	void print() {
//		for (int i = 0; i < divisor; i++) {
//			if (!empty[i])
//				cout << "第"<<i<<"个为"<<ht[i] << endl;
//		}
//		cout << endl;
//	}
//	void rebuild() {
//		int* ht_rebuild = new int[divisor];
//		int a = 0;
//		for (int i = 0; i < divisor; i++) {
//			if (!empty[i]) {
//				//收集所有元素同时置empty
//				ht_rebuild[a] = ht[i];
//				ht[i] = 0;
//				empty[i] = true;
//				a++;
//			}
//		}
//		for (int i = 0; i < divisor; i++) {
//			neverused[i] = true;
//		}//把所有元素置成neverused
//		for (int i = 0; i < a; i++) {
//			Insert(ht_rebuild[i]);
//		}//重新插入
//		cout << "该序列已重排" << endl;
//		delete[]ht_rebuild;
//	}
//	void delete_Hash(int e) {
//		int k = e;
//		int b = hSearch(k);//hSearch对应的是两个状态
//		if (!empty[b]) {
//			ht[b] = 0;
//			empty[b] = true;
//		}
//		else
//			cout << "不存在这个值！不可删除！" << endl;
//		int l = 0;
//		for (int i = 0; i < divisor; i++) {
//			if (empty[i] && !neverused[i])
//				l++;
//		}//判断有多少用过但此时为空的元素
//		if (l >= int(divisor * 0.6)) {
//			rebuild();
//		}
//
//	}
//	int divisor;
//	int* ht;
//	bool* empty;//指针要初始化！
//	bool* neverused;//指针要初始化
//};
//
//int main() {
//	HashTable* hashtable = new HashTable();
//	hashtable->Insert(13);
//	hashtable->Insert(24);
//	hashtable->Insert(35);
//	hashtable->Insert(46);
//	hashtable->Insert(56);
//	hashtable->Insert(58);
//	hashtable->Insert(57);
//	hashtable->Insert(60);
//	hashtable->Insert(68);
//	hashtable->Insert(79);
//	hashtable->print();
//
//	hashtable->delete_Hash(13);
//	hashtable->delete_Hash(24);	
//	hashtable->delete_Hash(35);
//	hashtable->delete_Hash(46);
//	hashtable->delete_Hash(57);
//	hashtable->print();
//
//	hashtable->delete_Hash(60);
//	hashtable->print();
//}


////第五次作业第二题：
#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};

class hashChainsWithTail {
public:
	Node* HT[11];//每一个的开头元素
	Node* tail;//共享的尾元素
	hashChainsWithTail() {
		tail = new Node();
		tail->next = NULL;
		tail->data = 0;
		for (int i = 0; i < 11; i++) {
			HT[i] = new Node();
			HT[i]->next = tail;
		}
	}
	~hashChainsWithTail() {
		delete tail;
		for (int i = 0; i < 100; i++) {
			delete[]HT[i];
		}
	}
	bool find(int num) {
		int i = num % 11;
		Node* temp = HT[i];
		if (HT[i]->next == tail) {
			return false;
		}
		else {
			for (int j = 0; temp->next != tail; j++) {
				temp = temp->next;
				if (temp->data == num) {
					return true;
				}
			}
			return false;
		}
	}
	void insert(int num) {
		if (find(num)) {
			cout << "该变量已存在，不需要重复赋值！" << endl;
		}
		else {
			Node* newNode = new Node();
			newNode->data = num;
			int index = num % 11;
			if (HT[index]->next == tail) {
				HT[index]->next = newNode;
				newNode->next = tail;
			}
			else {
				Node* temp = HT[index];
				Node* temp_temp = temp;
				for (int i = 0; temp->next != tail; i++) {
					temp_temp = temp;
					temp = temp->next;
					if (temp->data > num) {
						temp_temp->next = newNode;
						newNode->next = temp;
						break;
					}
					if (temp->next == tail) {
						temp->next = newNode;
						newNode->next = tail;
					}
				}
			}
		}
	}
	void remove(int num) {
		if (!find(num))
			cout << "抱歉没有查找到该元素 请检查您的输入！";
		else {
			int index = num % 11;
			Node* temp = HT[index];
			for (int i = 0; temp->next != tail; i++) {
				Node* temp_temp = temp;
				temp = temp->next;
				if (temp->data == num) {
					temp_temp->next = temp->next;
					delete temp;
					break;
				}
			}
		}
	}
	void print() {
		for (int i = 0; i < 11; i++) {
			Node* temp = HT[i];
			cout << "HT[" << i << "]: ";
			for (int j = 0; temp->next != tail; j++) {
				temp = temp->next;
				cout << temp->data << ' ';
			}
			cout << endl;
		}
	}

};
int main() {
	hashChainsWithTail* hash = new hashChainsWithTail();
	hash->insert(2);
	hash->insert(4);
	hash->insert(5);
	hash->insert(6);
	hash->insert(8);
	hash->insert(9);
	hash->insert(3);
	hash->insert(14);
	hash->insert(25);
	hash->insert(36);
	hash->insert(47);
	hash->print();

	cout << endl;
	hash->remove(6);
	hash->remove(14);
	hash->print();
}