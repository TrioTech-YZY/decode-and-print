#include"HuffmanTree.h"

//�������ƣ��ļ�������������뺯��
//�������������ļ��ж�ȡ�ַ������Ӧ�Ĺ���������
//Ԥ���������ļ���Ϊ��
//�����б��ļ�·��
//�����������ڴ��д����ַ������Ӧ�����ӳ���ϵ
unordered_map<char, string> HuffmanTree::readCodeFromFile(string filename) {
    std::unordered_map<char, string> code;

    // ����һ�������ļ�������
    std::ifstream infile(filename);

    // ����ļ��Ƿ�򿪳ɹ�
    if (!infile.is_open()) {
        std::cout << "Error: failed to open file.\n";
        return {};
    }

    // ��ȡ�ļ��е����ݣ����洢��unordered_map������
    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        char key;
        string value;
        //��������getline������Ϊ��ȥ���м��"|"
        if (ss >> key && std::getline(ss, value, '|') && std::getline(ss, value)) {
            code[key] = value;
        }
    }

    // �ر��ļ���
    infile.close();
    return code;


}