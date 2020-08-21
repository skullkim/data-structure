template <typename T>
class Queue{
public:
	Queue();
	Queue(T _data);
	bool emptyQueue(void);
	int returnSize(void);
	void PushEle(T _data);
	void popEle(void);
	T frontEle(void);
	T backEle(void);
	void printQueue(void);
private:
	T data;
	Queue* next;
	Queue* previous;
	static Queue* last;
	static int size;
};
