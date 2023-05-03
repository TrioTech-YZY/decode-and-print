/*
*�ļ����ƣ�				HuffmanTree.h
*��Ŀ���ƣ�				����������
*�����ߣ�				����
*����ʱ�䣺				2023.5.2
*����޸�ʱ�䣺			2023.5.3
*���ܣ�					��δ�����ļ�������ļ����ж�ȡ��ͨ��������������ļ����б�������룬������Ӧ������浽�ļ���
*�ļ��е�����ṹ�壺	���ṹ��͹���������
*�������ļ���������ϵ��	���к��������ڶ�Ӧ������cpp�У�����ʹ����main.cpp
*/

#pragma once
#include<iostream>
#include<fstream>
#include <sstream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

//�ṹ�����ƣ�HFT
//����ýṹ���Ŀ�ģ������������
typedef struct HFT{
	char data;
	int weight;
	int LChild, RChild, parent;
}HFT, * PHFT;

//�����ƣ�		  HuffmanTree
//��������Ŀ�ģ����й�����������ز���
//�����ԣ�		  ������������ʼ��ַָ��start
//���к��������ܣ�
//1.���캯�����������������캯����ʼ��startָ��Ϊ�գ����������ͷŹ���������
//2.InitHFT()���ն˳�ʼ���ֶμ���Ȩֵ��������������
//3.InitHFTFromFile()���ļ��ж����ַ�����Ȩֵ��������������
//4.CreateHFMcode()������ÿ���ַ��Ĺ��������룬���ַ��ͱ���Ķ�Ӧ��ϵ��unordered_map��ʽ����
//5.saveCodeToFile()����ÿ���ַ�������뱣�浽�ļ���
//6.readCodeFromFile()�����ļ��ж�ȡ�ַ�������������룬���浽�ڴ��unordered_map��
//7.show()��չʾ����������

class HuffmanTree{
private:
	PHFT  start;
	void select(PHFT start, int end, int& max1, int& max2);
public:
	HuffmanTree();
	~HuffmanTree();
	void InitHFT();     
	void InitHFTFromFile(string filename);   
	unordered_map<char, string> CreateHFMcode(); 
	void saveCodeToFile(unordered_map<char, string> code, string filename);  
	unordered_map<char, string> readCodeFromFile(string filename);   
	void show();
	//��Ҫ���ʹ��������ľ�̬����������Ҫһ��get����
	PHFT get_start() {
		return start;
	}
};





