#include"HuffmanTree.h"


//�������ƣ�չʾ����
//������������������������Ϣ���ն�չʾ
//Ԥ���������������������
//�����б���
//�����������ն˴�ӡ������Ϣ
void HuffmanTree::show() {
	int m = 2 * start[0].weight - 1;
	for (int i = 1; i <= m; i++) {
		cout << "��" << i << "���" << "\t�ַ�Ϊ��" << start[i].data
			<< "\tweightΪ:" << start[i].weight << "\tparentΪ��" <<
			start[i].parent << "\tLChildΪ��" << start[i].LChild
			<< "\tLChildΪ��" << start[i].RChild << endl;
	}
}