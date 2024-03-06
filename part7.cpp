//#include<iostream>
//using namespace std;
//class maxHeap {
//public:
//	int arrayLength;
//	int heapSize ;
//	int* heap ;
//	maxHeap() {
//
//		arrayLength = 100;
//		heapSize = 0;
//		heap = new int[100]();
//		heap[0] = 0;
//	}
//	bool IsFull() {
//		if (heapSize == arrayLength-1)
//			return true;
//		return false;
//	}
//	void push(int theElement) {
//		if (IsFull())
//			return;
//		else {
//			//先插进去，再一个一个比较
//			heapSize++;
//			int i =heapSize / 2 ;
//			heap[heapSize] = theElement;
//			int tt = heapSize;
//			for (; i !=0; i /= 2) {
//				if (theElement > heap[i]) {
//					int temp = heap[i];
//					heap[i] = theElement;
//					heap[tt] = temp;
//					tt /= 2;
//				}
//			}
//			//先不插进去，通过比较找到应该插入的位置，在比较过程中父节点也到了他该有的位置
//			//int i = ++heapSize;
//			//while (i != 1 && theElement > heap[i / 2]) {
//			//	heap[i] = heap[i / 2];
//			//	i /= 2;
//			//}
//			//heap[i] = theElement;
//		}
//	}
//	bool IsEmpty() {
//		if (heapSize == 0)
//			return true;
//		return false;
//	}
//	void pop() {
//		if (IsEmpty())
//			return;
//		int i = 1;
//		int target = heap[heapSize];
//		while(i<heapSize-1) {
//			if (target > max(heap[i * 2], heap[i * 2 + 1])) {
//				heap[i] = target;
//				break;
//			}
//			else {
//				heap[i] = heap[i * 2] < heap[i * 2 + 1] ? heap[i * 2 + 1] : heap[i * 2];
//				if (heap[i * 2] > heap[i * 2 + 1]) {
//					heap[i] = heap[2 * i];
//					i *= 2;
//				}
//				else {
//					heap[i] = heap[2 * i + 1];
//					i = 2 * i + 1;
//				}
//			}
//		}
//		heapSize--;
//		heap[i] = target;
//
//		//if (IsEmpty())
//		//	return;
//		//int y = heap[heapSize--];
//		//int i = 1, ci = 2;
//		//while (ci <= heapSize) {
//		//	if (ci < heapSize && heap[ci] < heap[ci + 1])
//		//		ci++;//使ci的值指向两个孩子中的最大者
//		//	if (y >= heap[ci])break;//target可以放在这里，不需要继续重组
//		//	//target需要继续向下判断
//		//	heap[i] = heap[ci];//大于父节点的孩子节点上升
//		//	i = ci;
//		//	ci *= 2;
//		//}
//		//heap[i] = y;
//	}
//	void initialize(int* theheap, int heapSize) {
//		heap = theheap;
//		this->heapSize = heapSize;
//		int start = heapSize/2;
//		
//		for (; start >= 1; start--) {
//			//从子树开始向上遍历直至start==0时停止（该程序首元素序列号为1）
//			int target = heap[start];
//			int i = start;
//			while (2 * i < heapSize) {
//				//每一层都要调整顺序
//				if (target > max(heap[2 * i], heap[2 * i + 1])) {
//					break;
//				}
//				else {
//					if (heap[2 * i + 1] > heap[2 * i]) {
//						heap[i] = heap[2 * i + 1];
//						heap[2 * i + 1] = target;
//						i = 2 * i + 1;
//					}
//					else {
//						heap[i] = heap[2 * i];
//						heap[2 * i] = target;
//						i = 2 * i;
//						//不断向下调整顺序直至满足大根堆的条件
//					}
//				}
//			}
//		}
//
//		/*this->heapSize = heapSize;
//		heap = theheap;
//		for (int root = heapSize / 2; root >= 1; root--) {
//			int rootElement = heap[root];
//			int child = 2 * root;
//			while (child <= heapSize) {
//				if (child < heapSize && heap[child] < heap[child + 1])
//					child++;
//				if (rootElement >= heap[child])
//					break;
//				heap[child / 2] = heap[child];
//				child *= 2;
//			}
//			heap[child / 2] = rootElement;
//		}*/
//	}
//	void print() {
//		for (int i = 1; i <= heapSize; i++) {
//			cout << heap[i] << ' ';
//		}
//		cout << endl;
//	}
//};
//int main() {
//	maxHeap* mh = new maxHeap();
//	mh->push(5);
//	mh->push(7);
//	mh->push(9);
//	mh->push(78);
//	mh->push(6);
//	mh->push(3);
//	mh->push(10);
//	mh->push(8);
//	mh->print();
//
//	mh->pop();
//	mh->print();
//
//	int* theheap=new int[100]();
//	for (int i = 1; i <= 9; i++) {
//		theheap[i] = i + 1;
//	}
//	maxHeap* ui = new maxHeap();
//	ui->initialize(theheap,9);
//	ui->print();
//}

#include<iostream>
#include<queue>
using namespace std;
//定义哈曼夫树的结构
typedef struct {
    int weight;//data域存储权值
    int parent, lchild, rchild;//双亲与孩子
} HTNode, * HuffmanTree;

void InitHuffmanTree(HuffmanTree H, int weight, int parent, int lchild, int rchild)
{
    //HT = (HuffmanTree)malloc(n*sizeof(HTNode));//空间分配
    H->lchild = lchild;
    H->rchild = rchild;
    H->parent = parent;
    H->weight = weight;
}

//建立哈夫曼树！
void CreateHuffmanTree(HuffmanTree& HT, int n, int* W)
{
    //叶子结点的初始化，相当于n棵树，每颗树只有一个结点，那么最后构造过程总的结点个数为：2*n-1 
    //n-1+n = 2*n-1 

    HT = new HTNode[2 * n - 1];//n个叶子结点的哈夫曼树结点是2n-1;
    for (int i = 0; i < n; i++) {
        InitHuffmanTree(HT + i, W[i], -1, -1, -1);//节点值赋值位-1
    }
    //开始寻找最小的两个叶子结点，构造哈夫曼树
    for (int i = n; i < 2 * n - 1; i++) { //我们构造n-1个度为2的结点
        int min1 = INT_MAX, min2 = INT_MAX;//这里的两个数分别代表第一小，第二小
        int x1 = -1, x2 = -1;//用来记录下标
        for (int j = 0; j < i; j++) {
            if ((HT + j) != nullptr)
                if ((HT + j)->parent == -1)//表示叶子结点没有父母
                    if ((HT + j)->weight < min1) {
                        min2 = min1;
                        min1 = (HT + j)->weight;
                        x2 = x1;
                        x1 = j;
                    }
                    else if ((HT + j)->weight < min2) {
                        min2 = (HT + j)->weight;
                        x2 = j;

                    }
        }//循环后min1为最小的，min2为第二小的
        //合并两个叶子，让他们有同一个双亲
        if ((HT + x1) != nullptr)
            (HT + x1)->parent = i;
        if ((HT + x2) != nullptr)
            (HT + x2)->parent = i;
        //然后我们让HT[i]指向这两个孩子，为了后来的逆序哈夫曼编码
        InitHuffmanTree(HT + i, min2 + min1, -1, x1, x2);//父结点构造 
    }
}
//完成哈夫曼树的生成；

//获得哈夫曼编码，n是指叶子个数，path是我们要获得的字符的编码 
void HuffmanTreeCode(HuffmanTree HT, char* str, int n, int path, int& e)
{
    int i = 0, j = 0, m = 0;
    int child = path;//假设我们现在在叶子结点为child索引的地方，如1

    int parent = (HT + child)->parent;//获取第一个叶子结点的父节点的值 
    //printf("leafe node is:%d \n",(HT+child)->data);

    //开始逆序寻找根节点，及生成编码
    for (i = n - 1; parent != -1; i--)  //当前结点不是根结点 ,逆序
        if ((HT + parent)->lchild == child) { //他的双亲指向的左孩子是不是我们当前遍历的这个叶子
            str[j++] = '0';//左子树编码为0
            child = parent;///此时parent！=-1 ，表示还有父节点 
            parent = (HT + child)->parent;
        }
        else {
            str[j++] = '1';//实现编码，右子树编码为1
            child = parent;
            parent = (HT + child)->parent;
        }
    //注意此时str中是从叶子节点中倒着存的，输出是也应该倒着输出才能是正着的编码
    e = j;//表示一个叶子结点的编码结束，记录此时编码尾的索引
}
int main()
{

    int i, n;
    int* w, e;
    string text;
    cout << "请输入需要编码的字母：" << endl;
    cin >> text;
    HuffmanTree HT;
    //printf("Node Number:");
    //printf("Input weights:");
    w = new int[text.size()];
    n = text.size();

    cout << "请依次输入字母权值：" << endl;
    for (i = 0; i < n; i++) //录入权值
    {
        cin >> w[i];
    }

    cout << "请输入需要编码的字符串：" << endl;
    string a = " ";
    cin >> a;
    CreateHuffmanTree(HT, n, w);
    //printf("the first node is:%d\n",HT->data);
    //printf("create sussessfully\n");
    //定义一个数组存储哈夫曼编码;
    char str[100] = {};
    char uu[100][100] = {};//初始化防止乱码
    int ans = 0;
    cout << "字符经过哈夫曼编码后为：" << endl;
    for (int k = 0; k < n; k++) {
        cout << text[k] << ":";
        uu[k][0] = text[k];
        ans = 1;
        HuffmanTreeCode(HT, str, n, k, e);
        for (int j = e - 1; j >= 0; j--)
        {
            cout << str[j];
            uu[k][ans] = str[j];
            ans++;
            if (j == 0)
                uu[k][ans] = '/0';
        }
        cout << endl;
    }
    cout << "字符串编码为：" << endl;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < text.size(); j++)
        {
            if (uu[j][0] == a[i])
            {
                for (int k = 1; k < strlen(uu[j])-1; k++)
                    cout << uu[j][k];
            }
        }
    }
    delete HT;
    return 0;
}