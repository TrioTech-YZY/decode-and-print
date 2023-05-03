#include"HuffmanTree.h"

//�������ƣ����캯��
//������������������������ʼָ���ÿ�
//Ԥ����������
//�����б���
//������������
HuffmanTree::HuffmanTree() {
	start = NULL;
}

//�������ƣ���������
//�����������Ӷ���ɾ������������
//Ԥ����������
//�����б���
//������������������������ռ��ͷ�
HuffmanTree::~HuffmanTree() {
	delete[] start;
}

//�������ƣ�ѡ����
//�����������ڹ�����ɭ���У�ѡ������Ȩֵ��С����
//Ԥ�����������ٴ���������
//�����б���
//�������������ı��ͨ�����÷�ʽ����
void HuffmanTree::select(PHFT start, int end, int& min1, int& min2) {
	for (int i = 1; i < end; i++) {
		if (start[i].parent == 0) {
			min1 = i;
			break;
		}
	}
	for (int i = min1 + 1; i < end; i++) {
		if (start[i].weight < start[min1].weight && start[i].parent == 0)
			min1 = i;
	}
	for (int j = 1; j < end; j++) {
		if (start[j].parent == 0 && j != min1) {
			min2 = j;
			break;
		}
	}
	for (int j = min2 + 1; j < end && j != min1; j++) {
		if (start[j].weight < start[min2].weight && start[j].parent == 0)
			min2 = j;
	}
}




