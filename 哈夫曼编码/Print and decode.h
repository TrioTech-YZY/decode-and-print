#include"HuffmanTree.h"
#include<fstream>
#include<iostream>
#include <sstream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;



//函数名称：打印函数
//函数功能描述：打印CodeFile.bin中的字符，并写入到CodePrint.txt中
//函数调用之前的预备条件：CodeFile.bin中已经存有字符
//参数列表：无
//后置条件：CodePrint.txt中写入数据
void Print() {
	//打开CodeFile.bin二进制文件
	ifstream in("CodeFile.bin", ios::binary);
	if (!in) {//打开失败
		cout << "Cannot open input file.\n";
		abort();
	}
	//打开CodePrint.txt文本文件
	ofstream fout("CodePrint.txt", ios::out);
	if (!fout) {//打开失败
		cout << "Cannot open output file." << endl;
		exit(1);
	}

	char ch;//文件读取的字符放入ch
	int ct = 0;//用于记录读取的字符数

	while (in.read((char*)&ch, sizeof(ch))) {//从CodeFile.bin中每次读取一个字符
		cout << ch;//显示该字符
		if (ch == '1' || ch == '0') {
			ct++;//自加1
			if (ct % 50 == 0) { cout << endl; }//每读取五十个有效字符，换行
		}
		fout << ch;//将字符写入到CodePrint.txt中
	};
	//关闭两文件
	fout.close();
	in.close();

}


//函数名称：编码函数
//函数功能描述：根据record.txt中字母对应的编码规则，将ToBeTran.txt中数据编码，写入CodeFile.bin中
//函数调用之前的预备条件：record.txt中已经保存有字母的编码规则
//参数列表：无
//后置条件：CodeFile.bin二进制文件中写入内容
void Decode() {
	HuffmanTree hf;//实例化一个哈夫曼树对象

	unordered_map<char, string> map;//定义一个哈希表map
	map = hf.readCodeFromFile("record.txt");//调用函数得到字母和二进制串的对应关系，放入map中
	//读ToBeTran.txt文本文件
	ifstream infile;
	infile.open("ToBeTran.txt", ios::in);
	if (!infile) {//打开文件失败
		cout << "Cannot open the file.\n";
		exit(1);
	}
	//写CodeFile.bin二进制文件
	ofstream outfile;
	outfile.open("CodeFile.bin", ios::out | ios::binary);
	if (!outfile) {//打开文件失败
		cerr << "Cannot open the file.\n";
		exit(1);
	}

	char ch;
	while ((ch = infile.get()) != EOF) {//每次从ToBeTran.txt中读取一个字符放入ch中
		//cout << ch;
		if (ch == ' ') { continue; }//为空格则跳到下次循环
		string str = map[ch];
		char *s=(char*)str.data();//将string类型变为char类型
		outfile.write((char*)s, sizeof(s));//将二进制串写入CodeFile.bin文件中
	}
	//关闭文件
	infile.close();
	outfile.close();
}


