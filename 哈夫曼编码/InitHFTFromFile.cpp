#include"HuffmanTree.h"

//�������ƣ��ļ������ʼ������
//�������������ļ��ж�ȡ�ַ�����Ȩֵ�������������
//Ԥ���������ļ���Ϊ��
//�����б��ļ�·��
//��������������������������
void HuffmanTree::InitHFTFromFile(string filename) {

    std::unordered_map<char, int> cw; //char_weight ���ļ��ж�ȡ���ַ���Ȩֵ���浽cw��

    // ����һ�������ļ�������
    std::ifstream infile(filename);

    // ����ļ��Ƿ�򿪳ɹ�
    if (!infile.is_open()) {
        std::cout << "Error: failed to open file.\n";
        return;
    }

    // ��ȡ�ļ��е����ݣ����洢��unordered_map������
    std::string line;
    while (std::getline(infile, line)) {
        char key = line[0];
        int value = std::stoi(line.substr(2));
        cw[key] = value; 
    }
    int n = cw.size();
	start = new HFT[2 * n];
	start[0].weight = n;
	for (int i = 1; i < 2 * n; i++) {
		start[i].data = '#';
		start[i].weight = 0;
		start[i].lchild = 0;
		start[i].rchild = 0;
		start[i].parent = 0;
	}
	int i = 1;
	for (auto it = cw.begin(); it != cw.end(); ++it) {
		start[i].data = it->first;
		start[i].weight = it->second;
		++i;
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