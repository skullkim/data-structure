template <typename T>
class Deque{
public:
	Deque();
	Deque(T _data);
	bool isEmpty(void);
	void addFront(T _data);
	void addEnd(T _data);
	void removeFront(void);
	void removeEnd(void);
	T returnFrontData(void);
	T returnEndData(void);
	void printAllData(void);
private:
	T data;
	Deque* next;
	Deque* previous;
	static Deque* first;
	static Deque* last;
	static T size;
};
