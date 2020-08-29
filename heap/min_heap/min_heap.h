template <typename T>
class MinHeap{
public:
	//method
	MinHeap();
	MinHeap(T _data);
	~MinHeap();
	void swap(MinHeap*);
	void insertData(T _data);
	void deleteData(void);
	T returnMinValue(void);
	void printAllData(MinHeap* curr_node);
private:
	//member value
	T data;
	MinHeap* left;
	MinHeap* right;
	MinHeap* parent;
	static T root;
	//method
	void remakeHeap(void);
	MinHeap* findLeafParent(MinHeap* curr_node);
};
