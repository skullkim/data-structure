template <typename T>
class Stack{
public:
	Stack();
	Stack(T _data);
	void pushData(T _data);
	void popData(void);
	int returnSize(void);
	bool emptyStack(void);
	T topData(void);
	void print(void);
private:
	T data;
	Stack* next;
	Stack* previous;
	static Stack* last;
	static int size;
};
