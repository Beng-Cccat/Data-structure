//Fibonacci的递归输出：
//#include<iostream>
//using namespace std;
//long long Fibonacci(int n,long long b[]) {
//	if (n == 0)return 0;
//	else if (n == 1)return 1;
//	else if (b[n] != 0)return b[n];
//	else
//		return Fibonacci(n - 1,b) + Fibonacci(n - 2,b);
//}
//int main() {
//	int n;
//	cin >> n;
//	long long result[100]={0};
//	for (int i = 0; i < 50; i++) {
//		result[i] = Fibonacci(i,result);
//	}
//	if (n < 0 || n>90)cout << "WRONG!" << endl;
//	else if (n >= 0 && n < 50)cout << result[n] << endl;
//	else cout << Fibonacci(n,result) << endl;
//}

//查找前n个字母的子集：
//#include<iostream>
//using namespace std;
//void printsubset(int n,int a[]) {
//	int space = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i] == 1) {
//			space++;
//			if (space == 2) {
//				cout << ' ';
//				space = 1;
//			}
//			cout << char(i + 'a');
//		}
//	}
//	cout << endl;
//}
//void plus_(int n) {
//	int a[30] = { 0 };
//	int end = 1;
//	while (end) {
//		printsubset(n, a);
//		int way = 0;
//		for (; way < n; way++) {
//			if (a[way] == 0)
//				break;
//		}
//		if (way == n)end = 0;
//		else {
//			a[0]++;
//			for (int i = 0; i < n; i++) {
//				if (a[i] == 2) {
//					a[i + 1]++;
//					a[i]-=2;
//				}
//			}
//		}
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	if (n < 1 || n>26)cout << "WRONG!";
//	else {
//		plus_(n);
//	}
//}