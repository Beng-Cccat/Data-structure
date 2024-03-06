////作业3第一题
//#include<iostream>
//using namespace std;
//class upperTriangularMatrix {
//public:
//	upperTriangularMatrix(int size = 3) { n = size; d = new int[n]; };
//	upperTriangularMatrix& Store(const int& x, int i, int j) {
//		if (i<1 || j<1 || i>n || j>n)cout << "输入不合法";
//		else if (i > j && x != 0)cout << "不！这一定是0！";
//		else d[ (i - 1) * (2 * n - i + 1)*1/2 + j - 1] = x;
//		return *this;
//	}
//	int Retrieve(int i, int j)const {
//		if (i<1 || j<1 || i>n || j>n)cout << "输入不合法";
//		else if (i > j)return 0;
//		else return d[(i - 1) * (2 * n - i + 1) * 1 / 2 + j - 1];
//	}
//	void print() {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j < i; j++) {
//				cout << 0 << ' ';
//			}
//			for (int j = i; j <= n; j++) {
//				cout << d[(i - 1) * (2 * n - i + 1) * 1 / 2 + j - 1] << ' ';
//			}
//			cout << endl;
//		}
//	}
//private:
//	int n;
//	int* d;
//};
//class lowerTriangularMatrix:public upperTriangularMatrix {
//public:
//	lowerTriangularMatrix(int size = 3) { n = size; d = new int[n]; };
//	lowerTriangularMatrix& Store(const int& x, int i, int j) {
//		if (i<1 || j<1 || i>n || j>n)cout << "输入不合法" << endl;
//		else if (i < j && x != 0)cout << "不！这一定是0！" << endl;
//		else d[i * (i - 1) * 1 / 2 + j - 1] = x;
//		return *this;
//	}
//	int Retrieve(int i, int j)const {
//		if (i<1 || j<1 || i>n || j>n)cout << "输入不合法" << endl;
//		else if (i < j)return 0;
//		else return d[i * (i - 1) * 1 / 2 + j - 1];
//	}
//	upperTriangularMatrix& Transpose() {
//		upperTriangularMatrix u;
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= i; j++) {
//				int data = Retrieve(i, j);
//				u.Store(data, j, i);
//			}
//		}
//		u.print();
//		return u;
//	}
//
//private:
//	int n;
//	int* d;
//};
//int main() {
//	lowerTriangularMatrix ll;
//	ll.Store(1, 1, 1);
//	ll.Store(2, 2, 1);
//	ll.Store(3, 2, 2);
//	ll.Store(4, 3, 1);
//	ll.Store(5, 3, 2);
//	ll.Store(6, 3, 3);
//	ll.Transpose();
//}

//作业3第二题
//#include<iostream>
//using namespace std;
//class Term {
//public:
//	int col=0, row=0;
//	int value=0;
//};
//class SparseMatrix:public Term {
//	friend istream& operator>>(istream&in, SparseMatrix&x) {//输入矩阵的行数、列数和非零元素个数，以及所有非零元素，非零元素包括每个元素的行号、列号、元素值。
//		cout << "Enter numbers of rows,columns and terms" << endl;
//		in >> x.rows >> x.cols >> x.terms;
//		if (x.terms > x.MaxTerms)cout << "输入有问题！";
//		for (int i = 0; i < x.terms; i++) {
//			cout << "Enter row, column and value of term" << (i + 1) << endl;
//			in >> x.a[i].row >> x.a[i].col >> x.a[i].value;
//		}
//		return in;
//	}
//	friend ostream& operator<<(ostream&out, const SparseMatrix& x) {
//		out << "rows = " << x.rows << " columns = "<< x.cols << endl;
//		out << "nonzero terms = " << x.terms << endl;
//		for (int i = 0; i < x.terms; i++)
//			out << "a(" << x.a[i].row << ',' << x.a[i].col<< ") = " << x.a[i].value << endl;
//		return out;
//	};
//public:
//	SparseMatrix(int maxTerms = 10) {
//		if (maxTerms < 1)cout << "输入有问题！";
//		MaxTerms = maxTerms;
//		a = new Term[MaxTerms];
//		terms = 0; rows = 0; cols = 0;
//	};
//	int SearchValue(int x, int y) {
//		for (int i = 0; i < terms; i++) {
//			if (a[i].row == x && a[i].col == y)
//				return a[i].value;
//		}
//		return 0;
//	}
//	int SearchTerm(int x, int y) {
//		for (int i = 0; i < terms; i++) {
//			if (a[i].row == x && a[i].col == y)
//				return i;
//		}
//		return -1;
//	}
//	void multiplication(const SparseMatrix& b,SparseMatrix &c) const{
//		SparseMatrix ss;
//		if (b.cols != c.rows)cout << "无法相乘！";
//		else {
//			int location = 0;
//			for (int i = 0; i < b.terms; i++) {
//				int b_col = b.a[i].col;
//				int b_row = b.a[i].row;
//				for (int j = 1; j <= c.cols; j++) {
//					if (c.SearchValue(b_col, j) != 0) {
//						if (ss.SearchTerm(b_row, j) != -1) {
//							ss.a[ss.SearchTerm(b_row, j)].value += c.SearchValue(b_col, j) * b.a[i].value;
//						}
//						else {
//							ss.a[location].value = c.SearchValue(b_col, j) * b.a[i].value;
//							ss.a[location].col = j;
//							ss.a[location].row = b_row;
//							location++;
//							ss.terms = location;
//						}
//					}
//				}
//			}
//			for (int i = 0; i < location; i++) {
//				if (ss.cols < ss.a[i].col)
//					ss.cols = ss.a[i].col;
//				if (ss.rows < ss.a[i].row)
//					ss.rows = ss.a[i].row;
//			}
//		}
//		cout << ss;
//	};
//private:
//	int rows=0, cols=0;
//	int terms=0;
//	Term* a;
//	int MaxTerms;
//};
//int main() {
//	SparseMatrix s1,s2;
//	cin >> s1;
//	cin >> s2;
//	SparseMatrix s3;
//	s3.multiplication(s1, s2);
//}

//作业3第三题
//#include<iostream>
//using namespace std;
//class rowElement {
//public:
//	int col = 0;
//	int value = 0;
//	rowElement* next = NULL;
//	rowElement() {};
//	rowElement(int col, int value) {
//		this->col = col;
//		this->value = value;
//	}
//};
//class extendedChain {
//public:
//	rowElement * head = new rowElement();
//	rowElement * tail = head;
//	int cols = 0;
//	extendedChain() {};
//};
//class headerElement {
//public:
//	int row = 0;
//	extendedChain *rowChain=new extendedChain();
//	headerElement* next = NULL;
//	headerElement() {
//		row = 0;
//		rowChain = new extendedChain();
//	};
//	headerElement(int row) { this->row = row; }
//};//linkedMatrix的首元素链表
//class linkedMatrix {
//public:
//	int rows = 0;
//	headerElement* head = new headerElement();
//	headerElement* tail = head;
//
//	linkedMatrix* add(int row,int col,int value) {
//		headerElement* temp = head;
//		rowElement* row_new = new rowElement(col, value);
//		for (int i = 0; i < rows; i++) {
//			temp = temp->next;
//			if (temp->row == row ) {
//				rowElement* row_temp = temp->rowChain->head;
//				for (int j = 0; j < temp->rowChain->cols-1; j++) {
//					if (row_temp->next->col > col ) {
//						row_new->next = row_temp->next;
//						row_temp->next = row_new;
//						temp->rowChain->cols++;
//						return this;
//					}
//					row_temp = row_temp->next;
//					if (row_temp->col < col && col < row_temp->next->col &&j<temp->rowChain->cols-1) {
//						row_new->next = row_temp->next;
//						row_temp->next = row_new;
//						temp->rowChain->cols++;
//						return this;
//					}
//					if (row_temp->value == col)
//						row_temp->value += value;
//				}
//				if (row_temp->next->col < col) {
//					temp->rowChain->tail->next = row_new;
//					temp->rowChain->tail = row_new;
//					temp->rowChain->cols++;
//					return this;
//				}
//				else if (row_temp->next->col > col) {
//					row_new->next = row_temp->next;
//					row_temp->next = row_new;
//					temp->rowChain->cols++;
//					return this;
//				}
//				else {
//					row_temp->value += value;
//				}
//			}
//			else if (temp->row > row) {
//				headerElement* temp_previous = head;
//				while (temp_previous->next != temp) {
//					temp_previous = temp_previous->next;
//				}
//				headerElement* newone = new headerElement(row);
//				temp_previous->next = newone;
//				newone->next = temp;
//				newone->rowChain->head->next = row_new;
//				newone->rowChain->tail = row_new;
//				newone->rowChain->cols++;
//				rows++;
//				return this;
//			}
//		}
//		headerElement* newone = new headerElement(row);
//		temp->next = newone;
//		tail = newone;
//
//		newone->rowChain->head->next = row_new;
//		newone->rowChain->tail = row_new;
//		newone->rowChain->cols++;
//		rows++;
//		return this;
//	}
//
//	int get(int row, int col) {
//		headerElement* temp = head;
//		for (int i = 0; i < rows; i++) {
//			temp = temp->next;
//			if (temp->row == row) {
//				rowElement* row_temp = temp->rowChain->head;
//				for (int j = 0; j < temp->rowChain->cols; j++) {
//					row_temp = row_temp->next;
//					if (row_temp->col == col)
//						return row_temp->value;
//				}
//			}
//		}
//		return 0;
//	}
//
//	linkedMatrix* addition(linkedMatrix* b) {
//		linkedMatrix* c = new linkedMatrix();
//		headerElement* temp_me = head;
//		headerElement* temp_it = b->head;
//		for (int i = 0; i < min(rows, b->rows); i++) {
//			temp_me = temp_me->next;
//			temp_it = temp_it->next;
//			rowElement* row_tempme = temp_me->rowChain->head;
//			rowElement* row_tempit = temp_it->rowChain->head;
//			for (int j = 0; j < temp_me->rowChain->cols; j++) {
//				row_tempme = row_tempme->next;
//				if (row_tempme->value + b->get(temp_me->row, row_tempme->col))
//					c->add(temp_me->row, row_tempme->col, row_tempme->value + b->get(temp_me->row, row_tempme->col));
//
//			}
//			for (int j = 0; j < temp_it->rowChain->cols; j++) {
//				row_tempit = row_tempit->next;
//				if (this->get(temp_it->row, row_tempit->col) == 0)
//					c->add(temp_it->row, row_tempit->col, b->get(temp_it->row, row_tempit->col));
//
//			}
//		}
//		if (rows < b->rows) {
//			for (int i = 0; i < b->rows - rows; i++) {
//				temp_it = temp_it->next;
//				rowElement* row_tempit = temp_it->rowChain->head;
//				for (int j = 0; j < temp_it->rowChain->cols; j++) {
//					row_tempit = row_tempit->next;
//					c->add(temp_it->row, row_tempit->col, b->get(temp_it->row, row_tempit->col));
//				}
//			}
//		}
//		else {
//			for (int i = 0; i < rows - b->rows; i++) {
//				temp_me = temp_me->next;
//				rowElement* row_tempme = temp_me->rowChain->head;
//				for (int j = 0; j < temp_me->rowChain->cols; j++) {
//					row_tempme = row_tempme->next;
//					c->add(temp_me->row, row_tempme->col, this->get(temp_me->row, row_tempme->col));
//				}
//			}
//		}
//		return c;
//	}
//
//	linkedMatrix* subtraction(linkedMatrix* b) {
//		linkedMatrix* c = new linkedMatrix();
//		headerElement* temp_me = head;
//		headerElement* temp_it = b->head;
//		for (int i = 0; i < min(rows, b->rows); i++) {
//			temp_me = temp_me->next;
//			temp_it = temp_it->next;
//			rowElement* row_tempme = temp_me->rowChain->head;
//			rowElement* row_tempit = temp_it->rowChain->head;
//			for (int j = 0; j < temp_me->rowChain->cols; j++) {
//				row_tempme = row_tempme->next;
//				if (row_tempme->value - b->get(temp_me->row, row_tempme->col))
//					c->add(temp_me->row, row_tempme->col, row_tempme->value - b->get(temp_me->row, row_tempme->col));
//
//			}
//			for (int j = 0; j < temp_it->rowChain->cols; j++) {
//				row_tempit = row_tempit->next;
//				if (this->get(temp_it->row, row_tempit->col) == 0)
//					c->add(temp_it->row, row_tempit->col, -b->get(temp_it->row, row_tempit->col));
//
//			}
//		}
//		if (rows < b->rows) {
//			for (int i = 0; i < b->rows - rows; i++) {
//				temp_it = temp_it->next;
//				rowElement* row_tempit = temp_it->rowChain->head;
//				for (int j = 0; j < temp_it->rowChain->cols; j++) {
//					row_tempit = row_tempit->next;
//					c->add(temp_it->row, row_tempit->col, -b->get(temp_it->row, row_tempit->col));
//				}
//			}
//		}
//		else {
//			for (int i = 0; i < rows - b->rows; i++) {
//				temp_me = temp_me->next;
//				rowElement* row_tempme = temp_me->rowChain->head;
//				for (int j = 0; j < temp_me->rowChain->cols; j++) {
//					row_tempme = row_tempme->next;
//					c->add(temp_me->row, row_tempme->col, this->get(temp_me->row, row_tempme->col));
//				}
//			}
//		}
//		return c;
//	}
//
//	linkedMatrix* multiplication(linkedMatrix* b) {
//		cout << "请确认：a的列数和b的行数一样，否则无法相乘，现在a和b相乘后的结果为：" << endl;
//		linkedMatrix* c = new linkedMatrix();
//		headerElement* temp_me = head;
//		for (int i = 0; i < rows; i++) {
//			temp_me = temp_me->next;
//			rowElement* row_tempme = temp_me->rowChain->head;
//			for (int j = 0; j < temp_me->rowChain->cols; j++) {
//				row_tempme = row_tempme->next;
//				if (b->get(row_tempme->col, temp_me->row))
//					c->add(temp_me->row, row_tempme->col, b->get(row_tempme->col, temp_me->row) * row_tempme->value);
//			}
//		}
//		return c;
//	}
//	void print() {
//		cout << "矩阵的非0元素为：" << endl;
//		headerElement* temp = head;
//		for (int i = 0; i < rows; i++) {
//			temp = temp->next;
//			rowElement* col_temp = temp->rowChain->head;
//			for (int j = 0; j < temp->rowChain->cols; j++) {
//				col_temp = col_temp->next;
//				cout << "(" << temp->row << "," << col_temp->col << "," << col_temp->value << ")" ;
//			}
//			cout << endl;
//		}
//	}
//};
//int main() {
//	linkedMatrix* a = new linkedMatrix();
//	a->add(2, 2, 2);
//	a->add(2, 3, 3);
//	a->add(2, 1, 1);
//	a->add(3, 2, 3);
//	a->add(1, 2, 2);
//	a->add(2, 5, 4);
//	a->add(1, 1, 1);
//	a->print();
//	cout << endl;
//	cout << a->get(2, 2) << endl;
//
//	linkedMatrix* b = new linkedMatrix();
//	b->add(1, 1, 1);
//	b->add(2,1,-1);
//	b->add(8, 8, 8);
//	b->print();
//	cout << endl;
//	a->addition(b)->print();
//	cout << endl;
//
//	a->subtraction(b)->print();
//	cout << endl;
//
//	a->multiplication(b)->print();
//}