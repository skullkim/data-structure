template <typename T>
class SinglyList{
public:
	SinglyList();
	SinglyList(T _data);
	void pushBack(T _data);
	void pushNextTo(T prev_data, T target);
	void deleteData(T target);
	int printSize(void);
	void printData(void);
private:
	T data;
	static int size;
	SinglyList* next;
	SinglyList* last;
};
