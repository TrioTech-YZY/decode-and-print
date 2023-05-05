#include"HuffmanTree.h"

//�������ƣ��ն˳�ʼ������
//����������ͨ���ն������ַ�����Ȩֵ������һ�Ź�������
//Ԥ���������������������2
//�����б���
//������������������һ�Ź�������
void HuffmanTree::InitHFT() {
	cout << "�������ַ�������" << endl;
	int n;
	cin >> n;
	if (n <= 1) {
		cout << "��������ַ����������Ϸ���" << endl;
		return;
	}
	start = new HFT[2 * n];
	start[0].weight = n;
	for (int i = 1; i < 2 * n; i++) {
		start[i].data = '#';
		start[i].weight = 0;
		start[i].lchild = 0;
		start[i].rchild = 0;
		start[i].parent = 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << "�������ַ���" << endl;
		char c;
		cin >> c;
		start[i].data = c;
		cout << "�������ַ�Ȩֵ��" << endl;
		int w;
		cin >> w;
		start[i].weight = w;
	}
	for (int i = n + 1; i < 2 * n; i++) {
		int min1, min2;
		select(start, i, min1, min2);
		start[min1].parent = i;
		start[min2].parent = i;
		start[i].lchild = min1;
		start[i].rchild = min2;
		start[i].weight = start[min1].weight + start[min2].weight;
	}
}
