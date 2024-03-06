//第六次作业第一题：
//#include<iostream>
//using namespace std;
//class Deque {
//public:
//	int deque[100];
//	int front = 0;
//	int tail = 0;
//	void IsEmpty() {
//		if (tail == 0) {
//			cout << "YES!" << endl;
//		}
//		else {
//			cout << "NO!" << endl;
//		}
//	}
//	void IsFull() {
//		if (tail == 100) {
//			cout << "YES!" << endl;
//		}
//		else {
//			cout << "NO" << endl;
//		}
//	}
//	void AddLeft(int num) {
//		if (tail==100) {
//			cout << "FULL!" << endl;
//		}
//		else {
//			for (int i = tail; i > 0; i--) {
//				deque[i] = deque[i - 1];
//			}
//			tail++;
//			deque[0] = num;
//			print();
//		}
//	}
//	void AddRight(int num) {
//		if (tail==100) {
//			cout << "FULL!" << endl;
//		}
//		else {
//			deque[tail] = num;
//			tail++;
//			print();
//		}
//	}
//	void DeleteLeft() {
//		if (tail==0) {
//			cout << "Empty!" << endl;
//		}
//		else {
//			for (int i = 0; i < tail-1; i++) {
//				deque[i] = deque[i + 1];
//			}
//			tail--;
//			print();
//		}
//	}
//	void DeleteRight() {
//		if(tail==0) {
//			cout << "Empty!" << endl;
//		}
//		else {
//			tail--;
//			print();
//		}
//	}
//	void print() {
//		for (int i = 0; i < tail-1; i++) {
//			cout << deque[i] << ' ';
//		}
//		if(tail!=0)
//			cout << deque[tail-1] << endl;
//	}
//};
//int main() {
//	string str="";
//	Deque* d1 = new Deque();
//	while (str != "End") {
//		cin >> str;
//		if (str == "IsEmpty") {
//			d1->IsEmpty();
//		}
//		else if (str == "IsFull") {
//			d1->IsFull();
//		}
//		else if (str == "AddLeft") {
//			int num;
//			cin >> num;
//			d1->AddLeft(num);
//		}
//		else if (str == "AddRight") {
//			int num;
//			cin >> num;
//			d1->AddRight(num);
//		}
//		else if (str == "DeleteLeft") {
//			d1->DeleteLeft();
//		}
//		else if (str == "DeleteRight") {
//			d1->DeleteRight();
//		}
//		else
//			continue;
//	}
//}

//第六次作业第二题：
//#include<iostream>
//#include<iomanip>
//using namespace std;
//
////中缀表达式转后缀表达式
//string MiddletoBack(string str) {
//	int i = 0;
//	int ib = 0;
//	char* strBack = new char();
//	char* array = new char();
//	int ia = 0;
//	while (str[i] != NULL) {
//		if (str[i] >= 'a' && str[i] <= 'z') {
//			strBack[ib] = str[i];
//			ib++;
//			i++;
//		}//遇到操作数，直接输出
//		else {//遇到操作符，需要先放到栈中（此时用array代替）
//			if (str[i] == '(') {
//				//遇到左括号，入栈（array相当于栈，ia记录其中元素编号）
//				array[ia] = str[i];
//				ia++;
//				i++;
//			}
//			else if (str[i] == ')') {
//				//遇到右括号，弹出直至遇到左括号
//				int j;
//				for (j = ia - 1; j >= 0 && array[j] != '('; j--) {
//					strBack[ib] = array[j];
//					ib++;
//				}
//				ia = j;//更新ia的值
//				i++;
//			}
//			else if (str[i] == '*' || str[i] == '/') {
//				if (ia - 1 >= 0) {//此时要弹出的编号是array[ia-1]这里是判断存不存在
//					if (array[ia - 1] == '+' || array[ia - 1] == '-') {
//						array[ia] = str[i];
//						ia++;
//						i++;
//					}
//					else if (array[ia - 1] == '*' || array[ia - 1] == '/') {
//						strBack[ib] = array[ia - 1];
//						ib++;
//						i++;
//						array[ia] = str[i];
//					}
//				}
//				else {//不存在的话该操作符直接入栈就好了，不用管栈中的其他元素
//					array[ia] = str[i];
//					ia++;
//					i++;
//				}
//			}//“*”和“\”优先级较大，可直接压入栈中（array）
//			else {
//				if (ia - 1 >= 0 && array[ia - 1] != '(') {
//					strBack[ib] = array[ia - 1];
//					ib++;
//					ia--;
//				}
//				array[ia] = str[i];
//				i++;
//				ia++;
//			}//“+”“-”优先级较低，需看情况入栈还是输出
//		}
//	}
//	while (ia != 0) {//最后还剩下的栈中的元素进入后缀表达式中
//		strBack[ib] = array[ia - 1];
//		ib++;
//		ia--;
//	}
//	strBack[ib] = '\0';
//
//	for (int i = 0; strBack[i] != NULL; i++)
//		cout << strBack[i] << ' ' ;
//	cout << endl;
//	return strBack;
//}
//class binaryTreeNode {
//public:
//	char element;
//	binaryTreeNode* leftchild;
//	binaryTreeNode* rightchild;
//	binaryTreeNode() {
//		this->element = 0;
//		leftchild = NULL;
//		rightchild = NULL;
//	}
//	binaryTreeNode(char element) {
//		this->element = element;
//		leftchild = NULL;
//		rightchild = NULL;
//	}
//	binaryTreeNode(char element, binaryTreeNode* leftchild, binaryTreeNode* rightchild) {
//		this->element = element;
//		this->leftchild = leftchild;
//		this->rightchild = rightchild;
//	}
//};
//int Depth(binaryTreeNode* get) {
//	int depth1 = 1;
//	int depth2 = 1;
//	binaryTreeNode* temp1 = get;
//	binaryTreeNode* temp2 = get;
//	while (temp1 ->leftchild != NULL) {
//		depth1++;
//		temp1 = temp1->leftchild;
//	}
//	while (temp2->rightchild != NULL) {
//		depth2++;
//		temp2 = temp2->rightchild;
//	}
//	return depth1 > depth2 ? depth1: depth2;
//}
//void print(binaryTreeNode* get, int depth) {
//	if (get != NULL) {
//		print(get->rightchild, depth + 1);
//		cout << setw(3 * depth) << " ";
//		cout << get->element << endl;
//		print(get->leftchild, depth + 1);
//	}
//}//这个非常有特点，可以好好看看
////后缀表达式转换为二叉树
//void BacktoTree(string strBack) {
//	int i = 0;
//	binaryTreeNode** array = new binaryTreeNode*();
//	int ia = 0;
//	binaryTreeNode* get = new binaryTreeNode();
//	int depth = 1;
//	while (strBack[i] != NULL) {
//		binaryTreeNode* newbinaryTreeNode = new binaryTreeNode(strBack[i]);
//		//用后缀表达式中的元素创建节点 
//		//后面只需要进行连接即可
//		if (strBack[i] >= 'a' && strBack[i] <= 'z') {
//			//后缀表达式中是字母
//			array[ia] = newbinaryTreeNode;
//			i++;
//			ia++;
//		}
//		else {
//			//后缀表达式中是表达符号
//			if (ia - 1 >= 0) {
//				newbinaryTreeNode->rightchild = array[ia - 1];
//				ia--;
//			}
//			if (ia - 1 >= 0) {
//				newbinaryTreeNode->leftchild = array[ia - 1];
//				ia--;
//			}
//			array[ia] = newbinaryTreeNode;
//			ia++;
//			i++;
//		}
//		get = newbinaryTreeNode;
//	}
//	depth = Depth(get);
//	print(get, depth);
//}
//int main() {
//	string strMiddle;
//	cin >> strMiddle;
//	string strBack=MiddletoBack(strMiddle);
//	BacktoTree(strBack);
//}

//第六次作业第三题：
#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
class binaryTreeNode {
public:
	char element;
	binaryTreeNode* leftchild;
	binaryTreeNode* rightchild;
	binaryTreeNode() {
		this->element = 0;
		leftchild = NULL;
		rightchild = NULL;
	}
	binaryTreeNode(char element) {
		this->element = element;
		leftchild = NULL;
		rightchild = NULL;
	}
	binaryTreeNode(char element, binaryTreeNode* leftchild, binaryTreeNode* rightchild) {
		this->element = element;
		this->leftchild = leftchild;
		this->rightchild = rightchild;
	}
};
int Depth(binaryTreeNode* get) {
	int depth1 = 1;
	int depth2 = 1;
	binaryTreeNode* temp1 = get;
	binaryTreeNode* temp2 = get;
	while (temp1->leftchild != NULL) {
		depth1++;
		temp1 = temp1->leftchild;
	}
	while (temp2->rightchild != NULL) {
		depth2++;
		temp2 = temp2->rightchild;
	}
	return depth1 > depth2 ? depth1 : depth2;
}
binaryTreeNode* BacktoTree(string strBack) {
	int i = 0;
	binaryTreeNode** array = new binaryTreeNode * ();
	int ia = 0;
	binaryTreeNode* get = new binaryTreeNode();
	while (strBack[i] != NULL) {
		binaryTreeNode* newbinaryTreeNode = new binaryTreeNode(strBack[i]);
		if (strBack[i] >= 'a' && strBack[i] <= 'z') {
			array[ia] = newbinaryTreeNode;
			i++;
			ia++;
		}
		else {
			if (ia - 1 >= 0) {
				newbinaryTreeNode->rightchild = array[ia - 1];
				ia--;
			}
			if (ia - 1 >= 0) {
				newbinaryTreeNode->leftchild = array[ia - 1];
				ia--;
			}
			array[ia] = newbinaryTreeNode;
			ia++;
			i++;
		}
		get = newbinaryTreeNode;
	}
	return get;
}
int leavesnumber(binaryTreeNode* get) {
	int number = 0;
	if (get!= NULL) {
		number+=leavesnumber(get->rightchild);
		number += leavesnumber(get->leftchild);
		if (get->leftchild == NULL && get->rightchild == NULL)
			number++;
	}
	return number;
}
void change(binaryTreeNode* get) {
	if (get != NULL) {
		change(get->leftchild);
		change(get->rightchild);
		binaryTreeNode* temp = get->rightchild;
		get->rightchild = get->leftchild;
		get->leftchild = temp;
	}
}
class Queue {
public:
	int front;
	int rear;
	binaryTreeNode* data[100];
};

void print(binaryTreeNode* get) {
	Queue* q = new Queue();
	binaryTreeNode* temp = new binaryTreeNode();
	q->front = -1;
	q->rear = -1;
	q->data[++q->rear] = get;
	while (q->front!=q->rear) {
		temp = q->data[++q->front];
		cout << temp->element <<' ';
		
		if (temp->leftchild != NULL)
			q->data[++q->rear] = temp->leftchild;
		if (temp->rightchild != NULL)
			q->data[++q->rear] = temp->rightchild;
	}
	cout << endl;
}
void print1(binaryTreeNode* get, int depth) {
	if (get != NULL) {
		print1(get->rightchild, depth + 1);
		cout << setw(3 * depth) << " ";
		cout << get->element << endl;
		print1(get->leftchild, depth + 1);
	}
}
int maxwidth(binaryTreeNode* get) {
	//宽度：各层节点数目的最大值
	if (get == NULL)
		return 0;
	int max = 0;
	queue<binaryTreeNode*>q;
	q.push(get);
	while (!q.empty()) {
		int width = q.size();
		for (int i = 0; i < width; i++) {
			binaryTreeNode* temp = q.front();
			q.pop();
			if (temp->leftchild)
				q.push(temp->leftchild);
			if (temp->rightchild)
				q.push(temp->rightchild);
		}
		max = max > width ? max : width;
	}
	return max;
}
int main() {
	string str;
	cin >> str;
	binaryTreeNode* get = BacktoTree(str);
	cout << "二叉树层次遍历为：" << endl;
	print(get);
	cout << "令该二叉树向左转90度：" << endl;
	print1(get,Depth(get));
	change(get);
	cout << "交换该二叉树左右两子树后得到的新二叉树（层次遍历）：" << endl;
	print(get);
	cout << "令该二叉树向左转90度后：" << endl;
	print1(get,Depth(get));
	cout << "该二叉树叶子节点有： " ;
	cout << leavesnumber(get) << endl;
	cout << "该二叉树的宽度为：" ;
	cout << maxwidth(get);

}