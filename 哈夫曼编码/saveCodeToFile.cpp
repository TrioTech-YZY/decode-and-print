#include"HuffmanTree.h"

//�������ƣ��ļ�������������뺯��
//������������ÿ���ַ������Ӧ�Ĺ��������뱣�浽�ļ���
//Ԥ�����������ڹ���������
//�����б��ַ���������ӳ�伯�ϣ��ļ�·��
//�����������ļ��б����ַ������Ӧ����
void HuffmanTree::saveCodeToFile(unordered_map<char, string> code, string filename) {

    std::ofstream outfile(filename);

    // ����ļ��Ƿ�򿪳ɹ�
    if (!outfile.is_open()) {
        std::cout << "Error: failed to open file.\n";
        return ;
    }

    // ��unordered_map����д���ļ�
    for (const auto& pair : code) {
        outfile << pair.first << "|" << pair.second << "\n";
    }

    // �ر��ļ���
    outfile.close();



}