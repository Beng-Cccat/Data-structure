#include<iostream>
using namespace std;
class bsTree {
public:
	virtual void ascend() = 0;
};
class RBTNode {
public:
	bool color;
	int key;
	RBTNode* left;
	RBTNode* right;
	RBTNode* parent;
};
class RBTree :public bsTree{
private:
	RBTNode* Nil;
	RBTNode* root;

public:
	RBTree() {
		Nil = getNode();
		root = Nil;
		Nil->color = false;
	}

	RBTNode* Find(RBTNode* root, int key) {
		if (root == Nil)
			return Nil;
		if (root->key == key)
			return root;
		else if (root->key < key)
			return Find(root->right, key);
		else
			return Find(root->left, key);
	}
	
	//插入：
	//1.BST方式插入
	//2.调整平衡
	bool Insert(int value) {
		if (Find(root, value) != Nil)
			return false;
		RBTNode* pr = Nil;
		RBTNode* s = root;
		while (s != Nil) {
			if (value == s->key)
				return false;
			pr = s;
			if (value < s->key)
				s = s->left;
			else
				s = s->right;
		}
		s = getNode(value);
		if (pr == Nil) {
			root = s;
			root->parent = pr;
		}
		else {
			if (value < pr->key)
				pr->left = s;
			else
				pr->right = s;
			s->parent = pr;
		}
		Insert_fix(s);
		return true;
		
	}

	//删除节点：先查找，再删除，还要变换一下红黑
	void remove(int key) {
		RBTNode* t;
		if ((t = Find(root, key)) != Nil)
			Remove(t);
		else
			cout << "Key is not exit!" << endl;
	}
	//删除函数

	void inorder() { 
		Inorder(root);
	}
	//中序遍历输出

	void InorderPrint() {
		InorderPrint(root);
	}

	void ascend() {
		Inorder(root);
	}
	
private:
	RBTNode* parentof(RBTNode* node) {
		return (node==NULL?NULL:node->parent);
	}
	RBTNode* getNode(int value=int()) {
		RBTNode* s = new RBTNode ();
		s->color = true;
		s->left = s->right = s->parent = Nil;
		s->key = value;
		return s;
	}
	RBTNode* Minimum(RBTNode* x) {
		if (x->left == Nil)
			return x;
		return Minimum(x->left);
	}
	void l(RBTNode* node) {
		RBTNode* y = node->right;
		node->right = y->left;
		if (y->left != Nil)
			y->left->parent = node;
		y->parent = node->parent;
		if (root == node)
			root = y;
		else if (node == parentof(node)->left)
			node->parent->left = y;
		else
			node->parent->right = y;
		y->left = node;
		node->parent = y;
	}
	void r(RBTNode* node) {
		RBTNode* y = node->left;
		node->left = y->right;
		if (y->right != Nil)
			y->right->parent = node;
		y->parent = node->parent;
		if (root == node)
			root = y;
		else if (node == parentof(node)->left)
			node->parent->left = y;
		else
			node->parent->right = y;
		y->right = node;
		node->parent = y;
	}
	void Transplant(RBTNode* x, RBTNode* y) {
		if (parentof(x) == Nil)
			root = y;
		else if (x == parentof(x)->left)
			x->parent->left = y;
		else {
			x->parent->right = y;
		}
		y->parent = parentof(x);
	}
	void Insert_fix(RBTNode* node) {
		RBTNode* uncle;
		while (parentof(node)->color==true) {
			if (parentof(node) == parentof(parentof(node))->left) {
				uncle = parentof(parentof(node))->right;//叔叔节点
				if (uncle->color == true) {//情况一：叔叔节点是红色的
					//根据性质三，对各节点进行变色
					parentof(node)->color = false;
					//对父节点进行变色：变为黑色
					uncle->color = false;
					//令叔叔节点为黑色
					parentof(parentof(node))->color = true;
					//令祖父节点为红色
					node = parentof(parentof(node));
					//向上判断祖父节点，继续调整
				}
				else {
					if (node == parentof(node)->right) {
						//情况三：叔叔节点为黑色，并且局部呈现三角形
						//（自己和父节点相对于各自的父节点位于不同方向的子树上）
						//此时父节点位于左子树，自己位于右子树
						node = parentof(node);
						l(node);
						//将父节点向自己的另一方向旋转（即父节点自己的方向）
						//最后旋转成一条直线，转化成情况四的情形
					}
					//情况四：叔叔节点为黑色，并且局部呈现直线
					//（自己和父节点都位于各自父节点的同一方向子树上面，此时均位于左边）
					//步骤一：对父节点和祖父节点进行变色
					parentof(node)->color = false;
					//将父节点变色为黑色
					parentof(parentof(node))->color = true;
					//将祖父节点变色为红色
					r(parentof(parentof(node)));
					//步骤二：旋转，此时该直线朝左，向右旋转
				}
			}
			else {
				if (parentof(node)==parentof(parentof(node))->right) {
					uncle = parentof(parentof(node))->left;
					if (uncle->color == true) {
						parentof(node)->color = false;
						uncle->color = false;
						parentof(parentof(node))->color = true;
						node = parentof(parentof(node));
					}
					else {
						if (node == parentof(node)->left) {
							node = parentof(node);
							r(node);
						}
						parentof(node)->color = false;
						parentof(parentof(node))->color = true;
						l(parentof(parentof(node)));
					}
				}
			}
		}
		root->color = false;
	}
	void Inorder(RBTNode* root) {
		if (root != Nil) {
			Inorder(root->left);
			cout << root->key << ' ';
			Inorder(root->right);
		}
	}
	void InorderPrint(RBTNode* node) {
		if (node == Nil)
			return;
		if (node->left != NULL) {
			InorderPrint(node->left);
		}
		cout << node->key << "(" << ((node->color == true) ? "RED" : "BLACK") << ")"<<" ";
		if (node->right != Nil)
			InorderPrint(node->right);
	}
	void Remove(RBTNode* node) {
		RBTNode* x = Nil;
		RBTNode* y = node;
		bool ycolor = y->color;
		if (node->left == Nil && node->right == Nil) {
			Transplant(node, Nil);
			return;
		}
		if (node->left == Nil) {
			x = node->right;
			Transplant(node, node->right);
		}
		else if (node->right == Nil) {
			x = node->left;
			Transplant(node, node->left);
		}
		else {
			y = Minimum(node->right);//y是要删除节点中一直向左孩子走的节点
			ycolor = y->color;
			x = y->right;
			if (y->parent == node)
				x->parent = y;
			else {
				Transplant(y, y->right);
				y->right = node->right;
				y->right->parent = y;
			}
			Transplant(node, y);
			y->left = node->left;
			node->left->parent = y;
			y->color = node->color;
		}
		if (ycolor == false)
			Remove_fix(x);
	}
	void Remove_fix(RBTNode* node) {
		while (node != root && node->color == false) {
			if (node == node->parent->left) {//删除节点位于左子树上
				RBTNode* x = parentof(node)->right;
				if (x->color == true) {//情况一：兄弟节点为红色
					x->color = false;
					node->parent->color = true;
					//步骤一：将兄弟节点和父节点颜色对调
					l(node->parent);
					//步骤二：对父节点进行左旋
					x = parentof(node)->right;
					//步骤三：将node的父节点的右子节点设为新的x
				}
				if (x->left->color == false && x->right->color == false) {//情况二：兄弟节点的子节点均为黑色
					x->color = true;
					//将兄弟节点颜色变为红色保持黑高
					//此时由于兄弟节点父节点也为红色，所以不满足不能有两个红色连在一起的条件
					//应该将风险上移至兄弟节点的父节点，继续进行变色操作
					//直至node节点为红色或者node节点为根节点为止（while的循环条件）
					//退出后再将node变为黑色节点，保证不会出现相邻的红色节点
					node = parentof(node);
				}
				else {//情况三/四：兄弟节点其中一个子节点为红色
					if (x->right->color == false) {//情况三：兄弟节点的子节点左红右黑
						x->color = true;
						x->left->color = false;
						//步骤一：交换兄弟节点和兄弟节点左子节点的颜色
						r(x);
						//步骤二：对兄弟节点进行右旋
						x = parentof(node)->right;
						//步骤三：将兄弟节点的父节点变为新的兄弟节点，此时变为情况四：兄弟节点的右子节点为红色
					}
					//情况四：兄弟节点的子节点左黑右红
					x->color = parentof(x)->color;
					//步骤一：将兄弟节点变色为和父节点同色
					x->parent->color = false;
					x->right->color = false;
					//步骤二：将node的父节点和兄弟节点的右子节点均变为黑色
					l(parentof(node));
					//步骤三：将node的父节点进行左旋
					node = root;
				}
			}
			else {//删除节点位于右子树上
				RBTNode* x = parentof(node)->left;
				if (x->color == true) {
					x->parent->color = true;
					x->color = false;
					r(parentof(node));
					x = parentof(node)->left;
				}
				if (x->left->color == false && x->right->color == false) {
					x->color = true;
					node = parentof(node);
				}
				else {
					if (x->left->color == false) {
						x->right->color = false;
						x->color = true;
						l(x);
						x = parentof(node)->left;
					}
					x->color = parentof(node)->color;
					node->parent->color = false;
					x->left->color = false;
					r(parentof(node));
					node = root;
				}
			}
		}
		node->color = false;
	}
};
int main() {
	RBTree rb;
	rb.Insert(10);
	rb.Insert(10);
	rb.Insert(7);
	rb.Insert(8);
	rb.Insert(15);
	rb.Insert(5);
	rb.Insert(6);
	rb.Insert(11);
	rb.Insert(13);
	rb.Insert(12);

	rb.inorder();
	cout << endl;
	rb.InorderPrint();
	cout << endl;

	rb.remove(21);

	rb.remove(12);
	rb.remove(6);
	rb.remove(11);
	rb.remove(10);
	rb.remove(8);
	rb.InorderPrint();

}