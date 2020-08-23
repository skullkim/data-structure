#include "binary_tree.cpp"

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	BiTree<int>* tree = new BiTree<int>(1);
	tree->insertData(2);
	cout << tree->getRoot() << endl;
	tree->insertData(3);
	tree->insertData(5);
	cout << "left tree preorder:" << endl;
	tree->preorderSearch(tree->getLeftTree());
	cout << endl;
	cout << "right tree preorder:" << endl;
	tree->preorderSearch(tree->getRightTree());
	cout << endl;
	cout << "preorder:" << endl;
	tree->preorderSearch(tree);
	cout << endl;
	cout << "inorder:" << endl;
	tree->inorderSearch(tree);
	cout << endl;
	cout << "postorder:" << endl;
	tree->postorderSearch(tree);
	cout << endl;
}
