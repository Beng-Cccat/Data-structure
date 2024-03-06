//第十次作业第一题：
//#include<iostream>
//#include <queue>
//using namespace std;
//int* BFS(int start, int target) {
//	queue<int> q;
//	int n;//元素个数
//	int* visit = new int[n + 1] {};//初始化为0
//	int* path = new int[n + 1];
//	for (int i = 0; i < n + 1; i++)
//		path[i] = -1;
//	int temp;
//	q.push(start);
//	while (!q.empty()) {
//		int temp1 = q.front();
//		q.pop();
//		for (int i = 0; i < temp1能去到的值的个数; i++) {
//			temp = temp1;//temp1能够接到的不重复的值
//			if (temp == target)
//				return path;
//			if (visit[temp] == 0) {//未被访问过
//				q.push(temp);
//				path[i] = temp1;
//			}
//		}
//	}
//	return NULL;
//}

////第十次作业第二题：
////判断一个无向图是否连通：
////从任意一个节点开始dfs或者bfs，若所有节点都被标记为已到达顶点，则为连通
//// 
////构件标记问题：
//// 当两个顶点属于同一构件时，具有相同的标记
////从每一个未做标记的顶点开始进行搜索，并用新的标号标记新到达的顶点
//// 
////用构件策略标记好之后，若i和j的标记相同并且没有i和j之间的边，则tc[i][j]=1
////如果存在i和j直接相连的边，则将边断开，寻找是否可以通过其他路径到达，如果没有则tc[i][j]=0，否则置1
//#include<iostream>
//#include <stack>
//#include <queue>
//using namespace std;
//class graph {
//public:
//	int** rec;
//	int** tc;//传递闭包
//	int n;//记录节点数
//	graph(int n) {
//
//		this->n = n;
//		rec = new int* [n + 1];
//		tc = new int* [n + 1];
//		for (int i = 1; i < n + 1; i++) {
//			rec[i] = new int [n + 1] {};
//			tc[i] = new int[n + 1] {};
//		};
//	}
//	void undirectedTC() {
//		int label = 2;//因为矩中含有1和0，故此时标记从2开始
//		int* isvisit = new int[n + 1] {};//节点是否被标记过，初始化为0
//		for (int i = 1; i < n + 1; i++) {
//			if (isvisit[i] == 0) {
//				isvisit[i] = label;//未被访问过，开始标记
//				dfs(i, isvisit, label);
//				label++;//使用新的标记
//			}
//		}
//		for (int i = 1; i < n + 1; i++) {
//			for (int j = 1; j < n + 1; j++) {
//				if (i != j && isvisit[i] == isvisit[j]) {
//					//isvisit相等说明在同一个连通中，i！=j说明是同一个连通中的两个顶点
//					if (rec[i][j] == 0)
//						//不存在相连的边又在一个连通图中时，肯定会有一条路径边大于1来连接
//						tc[i][j] = tc[j][i] = 1;
//					else
//						//两者相连，则把相连的边置0，找是否有其他路径可以到达
//					{
//						rec[i][j] = 0;
//						if (findpath(i, j) != NULL) {
//							//有其他路径可以到达，则符合题意
//							tc[i][j] = 1;
//							tc[j][i] = 1;
//						}
//						rec[i][j] = 1;//同时把该边恢复，以免影响别的判断
//					}
//				}
//			}
//		}//填充闭包矩阵
//	};//返回传递闭包
//	void add(int i, int j) {
//		if (i<1 || j<1 || i == j || i>n || j>n) {
//			cout << "要添加的边不符合要求！" << endl;
//			return;
//		}
//		rec[i][j] = rec[j][i] = 1;//i和j相连同时j和i相连
//	};//添加边
//	void deleteedge(int i, int j) {
//		if(i<1 || j<1 || i == j || i>n || j>n) {
//			cout << "要删除的边不存在！" << endl;
//			return;
//		}
//		rec[i][j] = rec[j][i] = 0;
//	};//删除两个链接关系（i和j的和j和i的都要删除）
//	void print() {
//		for (int row = 1; row < n + 1; row++) {
//			cout << "与顶点" << row << "相连的有：" << endl;
//			for (int col = 1; col < n + 1; col++) {
//				if (rec[row][col] != 0)
//					cout << col << ' ';
//			}
//			cout << endl;
//		}
//	};//打印顶点链接关系
//	void dfs(int source, int* isvisit, int label) {
//		stack<int>s;
//		s.push(source);
//		int i;
//		while (!s.empty()) {
//			i = s.top();
//			s.pop();
//			for (int j = 1; j < n + 1; j++) {
//				if (rec[i][j]== 1 && isvisit[j] == 0) {
//					isvisit[j] = label;
//					s.push(j);
//				}
//			}
//		}
//	};//对属于同一个连通分支的节点进行标记
//	int* findpath(int source, int destination) {
//		int* path = new int[n + 1];//记录路径中每个节点的上一个节点
//		for (int i = 0; i < n + 1; i++)
//			path[i] = -1;//说明还没走到
//		queue<int>q;
//		q.push(source);
//		int index;
//		while (!q.empty()) {
//			index = q.front();
//			q.pop();
//			if (index == destination)
//				return path;//走到终点，返回路径
//			for (int j = 1; j < n + 1; j++) {
//				if (j != source && rec[index][j] == 1 && path[j] == -1) {//两者相连且没有走回去
//					q.push(j);
//					path[j] = index;
//				}
//			}
//		}
//		return NULL;
//	};
//};
//int main() {
//	int m, n, i, j;
//	cout << "请输入测试次数：" << endl;
//	cin >> m;
//	for (int q = 0; q < m; q++) {
//		cout << "请输入节点数：" << endl;
//		cin >> n;
//		graph g(n);
//		cout << "依次输入图中无向边的起点和终点，输入-1时停止：" << endl;
//		cin >> i;
//		while (i != -1) {
//			cin >> j;
//			g.add(i, j);
//			cin >> i;
//		}
//		cout << "图中节点的连接关系：" << endl;
//		g.print();
//		cout << "是否存在要删除的节点？是则输入1；否则输入-1：" << endl;
//		cin >> i;
//		if (i == 1) {
//			cout << "" << endl;
//			cin >> i;
//			while (i != -1) {
//				cin >> j;
//				g.deleteedge(i, j);
//				cin >> i;
//			}
//			cout << "调整后图中节点的连接关系：" << endl;
//			g.print();
//		}
//		cout << "该图形成的闭包为：" << endl;
//		g.undirectedTC();
//		for (int i = 1; i < n + 1; i++) {
//			for (int j = 1; j < n + 1; j++)
//				cout << g.tc[i][j] << ' ';
//			cout << endl;
//		}
//	}
//	return 0;
//}