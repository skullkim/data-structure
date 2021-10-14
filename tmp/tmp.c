#include <stdio.h>
#include <stdlib.h>

//트리에서 하나의 노드에 해당하는 구조체
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

//데이터를 삽입하는 함수
Node* insertData(int data, Node* currentNode){
	//더이상 들어갈 노드가 없으면 그 위치에 새로운 데이터에 해당하는 노드 삽입
	if(currentNode == NULL) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	//새로 넣을 데이터가 현재 노드보다 작으면
	if(currentNode->data > data){
		//노드의 왼쪽 자식에 삽입
		currentNode->left = insertData(data, currentNode->left);
	}
	//새로 넣을 데이터가 현재 노드보다 크거나 같으면
	else{
		//노드의 오른쪽 자식에 삽입
		currentNode->right = insertData(data, currentNode->right);
	}
	return currentNode;
}

//데이터(target)이 트리에 존재하는지 확인
//존재한다면 1을, 없다면 0을 반환
int isExistData(int target, Node* currentNode) {
	//존재 여부를 판단할 변수
	int exist = 0;
	while(1) {
		//데이터가 존재하지 않다면 루프를 끝낸다
		if(currentNode == NULL) break;
		//데이터가 존재한다면 exist에 1을 할당하고
		//루프를 끝낸다
		else if(currentNode->data == target) {
			exist = 1;
			break;
		}
		//2진 건색 트리를 사용했기 때문에 검사할 데이터가 현재 노드의 
		//데이터보다 작다면 왼쪽 자식 트리를 검색
		else if(target < currentNode->data) currentNode = currentNode->left;
		//크거나 같다면 오른쪽 자식 트리를 검색
		else if(target >= currentNode->data) currentNode = currentNode->right;
	}
	return exist;
}

int main(void) {
	FILE* pFile = fopen("test.txt", "r"); //read mode 
	int intTemp = -1;
	Node * root = NULL;

	if (pFile == NULL)
	{
		printf("File does not exist\n");
		return 0;
	}

	// 파일 읽기 성공
	while (1) {
		fscanf(pFile, "%d", &intTemp);
		if (intTemp < 0) break;
		// 트리생성
		root = insertData(intTemp, root);
		// 생성된 트리에서 키 검색
		printf("%d\n", isExistData(intTemp, root));
		//printf("%d ", intTemp);
	}

	//파일 형태로 반환

	fclose(pFile);          //close file
	return 0;
}
