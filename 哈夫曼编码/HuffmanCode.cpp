#include"HuffmanTree.h"

//�������ƣ����������뺯��
//�������������ݴ����Ĺ�������������ÿ���ַ��Ĺ���������
//Ԥ����������һ�Ź�������
//�����б���
//������������unordered_map<char, string>��ʽ�����ַ��������Ķ�Ӧ��ϵ
unordered_map<char, string> HuffmanTree::CreateHFMcode() {
	unordered_map<char, string> HFCode;
	string temp;
	stack<string> st;		//����ջʵ����һ��char����strcpy�ķ���
	int cur = 0, father = 0;
	for (int i = 1; i <= start[0].weight; i++) {
		cur = i;
		father = start[i].parent;
		while (father != 0)
		{
			if (start[father].LChild == cur) st.push("0");
			else st.push("1");
			cur = father;
			father = start[father].parent;
		}
		while (!st.empty()) {
			temp += st.top();
			st.pop();
		}
		HFCode[start[i].data] = temp;
		temp.erase();	//�����ڴ�
	}
	return HFCode;
}