template <typename T>
class BiTree{
public:
	BiTree();
	BiTree(T _data);
	void insertData(T _data);
	BiTree<T>* getLeftTree(void);
	BiTree<T>* getRightTree(void);
	T getRoot(void);
	void preorderSearch(BiTree<T>* curr_node);
	void inorderSearch(BiTree<T>* curr_node);
	void postorderSearch(BiTree<T>* curr_node);
private:
	T data;
	BiTree* left;
	BiTree* right;
	BiTree* parent;
	static BiTree* root;
};
