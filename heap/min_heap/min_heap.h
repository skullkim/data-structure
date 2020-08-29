template <typename T>
class MinHeap{
public:
	MinHeap();
	MinHeap(T _data);
	~MinHeap();
	void swap(MinHeap*);
	MinHeap* findLeafParent(MinHeap* curr_node);
	void insertData(T _data);
	void remakeHeap(void);
	void deleteData(void);
	T returnMinValue(void);
	void printAllData(MinHeap* curr_node);
private:
	T data;
	MinHeap* left;
	MinHeap* right;
	MinHeap* parent;
	static T root;
};
