#include<iostream>
#include<queue>
using namespace std;
class AVLTreeNode {
public:
	int key;
	int height;
	AVLTreeNode* lc;
	AVLTreeNode* rc;
	AVLTreeNode(int key, AVLTreeNode* lc, AVLTreeNode* rc) {
		this->key = key;
		this->lc = lc;
		this->rc = rc;
	}
};
class AVLTree {
private:
	AVLTreeNode* root;
public:
	AVLTree() {
		root = NULL;
	}
	int height() {
		return height(root);
	};
	int Height() {
		return Height(root);
	}
	bool search(int key) {
		return search(root, key);
	}
	void insert(int key) {
		insert(root, key);
	}
	void preorder() {
		preorder(root);
	};
	void returnkey() {
		returnkey(root);
	}
private:
	void preorder(AVLTreeNode* node) {
		if (node == NULL)
			return;
		cout << node->key << ' ';
		preorder(node->lc);
		preorder(node->rc);
	}
	int height(AVLTreeNode* node) {
		return node == NULL ? 0 : node->height;
	}
	int Height(AVLTreeNode* node) {
		if (node == NULL) {
			return 0;
		}
		int height1 = Height(node->lc);
		int Height2 = Height(node->rc);
		return max(height1, Height2)+1;
	}
	bool search(AVLTreeNode* node, int key) {
		if (node == NULL)
			return false;
		else if (node->key == key)
			return true;
		else if (key < node->key)
			search(node->lc, key);
		else if (key > node->key)
			search(node->rc, key);
	}
	AVLTreeNode* insert(AVLTreeNode*& node, int key) {
		if (node == NULL) {
			node = new AVLTreeNode(key, NULL, NULL);
		}
		else if (key < node->key) {
			node->lc = insert(node->lc, key);
			if (height(node->lc) - height(node->rc) == 2) {
				if (key < node->lc->key)
					node = ll(node);
				else
					node = lr(node);
			}
		}
		else if (key > node->key) {
			node->rc = insert(node->rc, key);
			if (height(node->rc) - height(node->lc) == 2) {
				if (key > node->rc->key)
					node = rr(node);
				else
					node = rl(node);
			}
		}
		else {
			cout << "添加失败，不能添加相同节点" << endl;
		}
		node->height = max(height(node->lc), height(node->rc)) + 1;
		return node;
	}
	void returnkey(AVLTreeNode* node) {
		queue<AVLTreeNode*> Q;
		AVLTreeNode* vn;
		int num = 1;
		Q.push(node);
		if (node->lc == NULL && node->rc == NULL) {
			cout << node->key << ' ';
			return;
		}
		while (!Q.empty()) {
			int num1 = num;
			num = 0;
			AVLTreeNode* vw;
			bool back = false;
			for (int i = 0; i < num1;i++) {
				vn = Q.front();
				Q.pop();
				vw = vn->lc;
				if (vw->lc == NULL && vw->rc == NULL) {
					cout << vw->key << ' ';
					back = true;
				}
				Q.push(vw);
				num++;
				vw = vn->rc;
				if (vw->lc == NULL && vw->rc == NULL) {
					cout << vw->key << ' ';
					back = true;
				}
				Q.push(vw);
				num++;

			}
			if (back)
				break;
		}
		return;
	}
private:
	AVLTreeNode* ll(AVLTreeNode*& node) {
		AVLTreeNode* newnode = node->lc;
		node->lc = newnode->rc;
		newnode->rc = node;
		node->height = max(height(newnode->lc), height(newnode->rc)) + 1;
		newnode->height = max(height(newnode->lc), node->height) + 1;
		return newnode;
	}
	AVLTreeNode* rr(AVLTreeNode*& node) {
		AVLTreeNode* newnode = node->rc;
		node->rc = newnode->lc;
		newnode->lc = node;
		node->height = max(height(node->lc), height(node->rc)) + 1;
		newnode->height = max(height(newnode->rc), node->height) + 1;
		return newnode;
	}
	AVLTreeNode* lr(AVLTreeNode*& node) {
		node->lc = rr(node->lc);
		return ll(node);
	}
	AVLTreeNode* rl(AVLTreeNode*& node) {
		node->rc = ll(node->rc);
		return rr(node);
	}
};
int main() {
	AVLTree tree;
	tree.insert(3);
	tree.preorder();
	cout << endl;

	tree.insert(2);
	tree.preorder();
	cout << endl;

	tree.insert(1);
	tree.preorder();
	cout << endl;

	tree.insert(4);
	tree.preorder();
	cout << endl;

	tree.insert(5);
	tree.preorder();
	cout << endl;

	tree.insert(6);
	tree.preorder();
	cout << endl;

	tree.insert(7);
	tree.preorder();
	cout << endl;

	tree.insert(16);
	tree.preorder();
	cout << endl;

	tree.insert(15);
	tree.preorder();
	cout << endl;

	cout << "树高为：";
	cout << tree.Height();
	cout << endl;
	cout << "离根节点最近的叶子节点的节点：";
	tree.returnkey();
}