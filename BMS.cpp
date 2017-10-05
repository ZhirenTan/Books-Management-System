#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class reader
{
	string reader_ID;
	string name;
	string classification;
	string PassWord;
public:
	reader *next;
	reader(string S, string n, string c, string p)
	{
		reader_ID = S;
		name = n;
		classification = c;
		PassWord = p;
	}
	void setreader_ID(int s_r)
	{
		reader_ID = s_r;
	}
	string getreader_ID()
	{
		return reader_ID;
	}
	void setName(string s_N)
	{
		name = s_N;
	}
	string getName()
	{
		return name;
	}
	void setClassification(string s_C)
	{
		classification = s_C;
	}
	string getClassification()
	{
		return classification;
	}
	void setPassWord(string s_P)
	{
		PassWord = s_P;
	}
	string getPassWord()
	{
		return PassWord;
	}
};
class book
{
	int Book_ID;
	string classification_ID;
	string name;
	string author;
	string publishing_company;
	int publication_date;
	string ISBN;
	int edition_number;
	int price;
	string book_condition ;
public:
	book *next;
	book(int b, string c, string n, string a, string p, int p_d, string I, int e, int pr)
	{
		Book_ID = b;
		classification_ID = c;
		name = n;
		author = a;
		publishing_company = p;
		publication_date = p_d;
		ISBN = I;
		edition_number = e;
		price = pr;
		book_condition = '0';
	}
	void setBook_ID(int s_ID)
	{
		Book_ID = s_ID;
	}
	int getBook_ID()
	{
		return Book_ID;
	}
	void setclassification_ID(string s_cID)
	{
		classification_ID = s_cID;
	}
	string getclassification_ID()
	{
		return classification_ID;
	}
	void setname(string s_n)
	{
		name = s_n;
	}
	string getname()
	{
		return name;
	}
	void setauthor(string s_a)
	{
		author = s_a;
	}
	string getauthor()
	{
		return author;
	}
	void setpublishing_company(string s_c)
	{
		publishing_company = s_c;
	}
	string getpublishing_company()
	{
		return publishing_company;
	}
	void setpublication_date(int s_d)
	{
		publication_date = s_d;
	}
	int getpublication_date()
	{
		return publication_date;
	}
	void setISBN(int isbn)
	{
		ISBN = isbn;
	}
	string getISBN()
	{
		return ISBN;
	}
	void setedition_number(int s_num)
	{
		edition_number = s_num;
	}
	int getedition_number()
	{
		return edition_number;
	}
	void setprice(int s_p)
	{
		price = s_p;
	}
	int getprice()
	{
		return price;
	}
	void setbook_condition(string s_c)
	{
		book_condition = s_c;
	}
	string getbook_condition()
	{
		return book_condition;
	}
};
class relationship
{
public:
	reader *nextReader ;
	book *nextBook ;
	relationship *nextRelationship ;
	relationship *borrownextBook ;
	relationship()
	{
		nextReader=NULL;
		nextBook=NULL;
		nextRelationship=NULL;
		borrownextBook=NULL;
	}
};
void menu();
reader *readerHead = NULL;
book *bookHead = NULL;
relationship *relationshipHead = NULL;
string reader_ID[20];
string PassWord[20];
int sum = 0;
void administratorMenu();
void readerMenu(string account);
void bookDataRecoverry()
{
	ifstream inf("C:\\data\\book.txt", ios::in);
	while (!inf.eof())
	{
		int Book_ID;
		string classification_ID;
		string name;
		string author_s;
		string publishing_company;
		int publication_date;
		string ISBN;
		int edition_number;
		int price;
		inf >> Book_ID;
		inf >> classification_ID;
		inf >> name;
		inf >> author_s;
		inf >> publishing_company;
		inf >> publication_date;
		inf >> ISBN;
		inf >> edition_number;
		inf >> price;
		book *x = NULL;
		x=new book(Book_ID, classification_ID, name, author_s, publishing_company, publication_date, ISBN, edition_number,price);
		if (bookHead == NULL)
		{
			bookHead = x;
			x->next = NULL;
		}
		else
		{
			book * p = bookHead;
			book * q = NULL;
			while (p != NULL)
			{
				q = p;
				p = p->next;
			}
			//插入到链表最后
			q->next = x;
			q = q->next;
			q->next = NULL;
		}
	}
	inf.close();
	return;
}
void readerDataRecovery()
{
	ifstream in("C:\\data\\reader.txt", ios::in);
	while (!in.eof())
	{
		string reader_ID;
		string name;
		string classification;
		string PassWord;
		in >> reader_ID;
		in >> name;
		in >> classification;
		in >> PassWord;
		reader *x = new reader(reader_ID, name, classification, PassWord);
		if (readerHead == NULL)
		{
			readerHead = x;
			x->next = NULL;
		}
		else
		{
			reader * p = readerHead;
			reader * q = NULL;
			while (p != NULL)
			{
				q = p;
				p = p->next;
			}
			//插入到链表最后
			q->next = x;
			q = q->next;
			q->next = NULL;
		}
	}
	in.close();
	/*
	reader *k;
	k = readerHead;
	while (k)
	{
		cout << k->getreader_ID() << endl;
		cout << k->getName() << endl;
		k = k->next;
	}*/
}
void saveBookdata()
{
	ofstream out("C:\\data\\book.txt", ios::out);
	book *bookhead = bookHead;
	while (bookhead)
	{
		out << bookhead->getBook_ID() << endl;
		out << bookhead->getclassification_ID() << endl;
		out << bookhead->getname() << endl;
		out << bookhead->getauthor() << endl;
		out << bookhead->getpublishing_company() << endl;
		out << bookhead->getpublication_date() << endl;
		out << bookhead->getISBN() << endl;
		out << bookhead->getedition_number() << endl;
		out << bookhead->getprice()<< endl;
		bookhead = bookhead->next;
	}
	return;
}
void saveReaderdata()
{
	ofstream out("C:\\data\\reader.txt", ios::out);
	reader *readerhead = readerHead;
	while (readerhead)
	{
		out << readerhead->getreader_ID() << endl;
		out << readerhead->getName() << endl;
		out << readerhead->getClassification() << endl; 
		out << readerhead->getPassWord() << endl;
		readerhead = readerhead->next;
	}
	return;
}
void saveBorrowdata()
{
	ofstream out("C:data\\borrowdata.txt", ios::out);
	relationship *rs = relationshipHead;
	while (rs)
	{
		if (rs->nextReader!=NULL)
		out << rs->nextReader->getName() << endl;
		if (rs->nextBook != NULL)
			out << rs->nextBook->getname() << endl;
		if (rs->borrownextBook != NULL)
		{
			out << rs->borrownextBook->nextRelationship->nextBook->getname() << endl;
			rs = rs->nextRelationship;
		}
		rs = rs->nextRelationship;
	}
}
void addBook()
{
	system("cls");
	int Book_ID;
	string classification_ID;
	string name;
	string author;
	string publishing_company;
	int publication_date;
	string ISBN;
	int edition_number;
	int price;
	cout << "请输入图书编号：" << endl;
	cin >> Book_ID;
	cout << "中图分类号：" << endl;
	cin >> classification_ID;
	cout << "书名：" << endl;
	cin >> name;
	cout << "作者：" << endl;
	cin >> author;
	cout << "出版社：" << endl;
	cin >> publishing_company;
	cout << "出版日期" << endl;
	cin >> publication_date;
	cout << "ISBN" << endl;
	cin >> ISBN;
	cout << "版次" << endl;
	cin >> edition_number;
	cout << "定价" << endl;
	cin >> price;
	book *s = new book(Book_ID, classification_ID, name, author, publishing_company, publication_date, ISBN, edition_number, price);
	if (bookHead == NULL)
	{
		bookHead = s;
		s->next = NULL;
		cout << "添加图书成功" << endl;
	}
	else
	{
		book * p = bookHead;
		book * q = NULL;
		while (p != NULL)
		{
			q = p;
			p = p->next;
		}
		//插入到链表最后
		q->next = s;
		q = q->next;
		q->next = NULL;
		cout << "添加图书成功" << endl;
	}
	book *q = bookHead;
	while (q)
	{
		cout << q->getBook_ID() << endl;
		q = q->next;
	}
	system("pause");
	administratorMenu();
}
void deleteBook()
{
	system("cls");
	cout << "请输入需要删除图书的编号：" << endl;
	int book_ID;
	cin >> book_ID;
	book *p;
	if (bookHead->getBook_ID() == book_ID)
	{
		p = bookHead;
		bookHead = bookHead->next;
		delete p;
		p = NULL;
		cout << "图书删除成功" << endl;
		system("pause");
		administratorMenu();
	}
	for (book *q = bookHead; q->next; q = q->next)
	{
		if (q->next->getBook_ID() == book_ID)
		{
			p = q->next;
			q->next = p->next;
			delete p;
			p = NULL;
			cout << "图书删除成功" << endl;
			system("pause");
			administratorMenu();
		}
	}
	cout << "输入有误，不存在该图书" << endl;
	system("pause");
	administratorMenu();
}
void inquiryBook()
{
	system("cls");
	cout << "请选择以下方式进行查询：" << endl;
	cout << "1.图书编号" << endl;
	cout << "2.中图分类号" << endl;
	cout << "3.书名" << endl;
	cout << "4.作者" << endl;
	cout << "5.出版社" << endl;
	cout << "6.出版日期" << endl;
	cout << "7.ISBN" << endl;
	cout << "8.版次" << endl;
	cout << "9.定价" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << "请输入需要查询的图书编号：" << endl;
		int book_ID;
		cin >> book_ID;
		book *p = bookHead;
		while (p)
		{
			if (p->getBook_ID() == book_ID)
			{
				cout << p->getBook_ID() << endl;
				cout << p->getclassification_ID() << endl;
				cout << p->getname() << endl;
				cout << p->getauthor() << endl;
				cout << p->getpublishing_company() << endl;
				cout << p->getpublication_date() << endl;
				cout << p->getISBN() << endl;
				cout << p->getedition_number() << endl;
				cout << p->getprice() << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				p = p->next;
			}
		}
	}
	else
	if (choice == 2)
	{
		cout << "请输入需要查询的图书中图分类号：" << endl;
		string classification_ID;
		cin >> classification_ID;
		book *p = bookHead;
		while (p)
		{
			if (p->getclassification_ID() == classification_ID)
			{
				cout << p->getBook_ID() << endl;
				cout << p->getclassification_ID() << endl;
				cout << p->getname() << endl;
				cout << p->getauthor() << endl;
				cout << p->getpublishing_company() << endl;
				cout << p->getpublication_date() << endl;
				cout << p->getISBN() << endl;
				cout << p->getedition_number() << endl;
				cout << p->getprice() << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				p = p->next;
			}
		}
	}
	else
	if (choice == 3)
	{
		cout << "请输入需要查询的图书书名：" << endl;
		string name;
		cin >> name;
		book *p = bookHead;
		while (p)
		{
			if (p->getname() == name)
			{
				cout << p->getBook_ID() << endl;
				cout << p->getclassification_ID() << endl;
				cout << p->getname() << endl;
				cout << p->getauthor() << endl;
				cout << p->getpublishing_company() << endl;
				cout << p->getpublication_date() << endl;
				cout << p->getISBN() << endl;
				cout << p->getedition_number() << endl;
				cout << p->getprice() << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				p = p->next;
			}
		}
	}
	else
	if (choice == 4)
	{
		cout << "请输入需要查询的图书作者：" << endl;
		string author;
		cin >> author;
		book *p = bookHead;
		while (p)
		{
			if (p->getauthor() == author)
			{
				cout << p->getBook_ID() << endl;
				cout << p->getclassification_ID() << endl;
				cout << p->getname() << endl;
				cout << p->getauthor() << endl;
				cout << p->getpublishing_company() << endl;
				cout << p->getpublication_date() << endl;
				cout << p->getISBN() << endl;
				cout << p->getedition_number() << endl;
				cout << p->getprice() << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				p = p->next;
			}
		}
	}
	else
	if (choice == 5)
	{
		cout << "请输入需要查询的图书出版社：" << endl;
		string publishing_company;
		cin >> publishing_company;
		book *p = bookHead;
		while (p)
		{
			if (p->getpublishing_company() == publishing_company)
			{
				cout << p->getBook_ID() << endl;
				cout << p->getclassification_ID() << endl;
				cout << p->getname() << endl;
				cout << p->getauthor() << endl;
				cout << p->getpublishing_company() << endl;
				cout << p->getpublication_date() << endl;
				cout << p->getISBN() << endl;
				cout << p->getedition_number() << endl;
				cout << p->getprice() << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				p = p->next;
			}
		}
	}
	else
	if (choice == 6)
	{
		cout << "请输入需要查询的图书出版日期：" << endl;
		int publication_date;
		cin >> publication_date;
		book *p = bookHead;
		while (p)
		{
			if (p->getpublication_date() == publication_date)
			{
				cout << p->getBook_ID() << endl;
				cout << p->getclassification_ID() << endl;
				cout << p->getname() << endl;
				cout << p->getauthor() << endl;
				cout << p->getpublishing_company() << endl;
				cout << p->getpublication_date() << endl;
				cout << p->getISBN() << endl;
				cout << p->getedition_number() << endl;
				cout << p->getprice() << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				p = p->next;
			}
		}
	}
	else
	if (choice == 7)
	{
		cout << "请输入需要查询的图书的ISBN：" << endl;
		string ISBN;
		cin >> ISBN;
		book *p = bookHead;
		while (p)
		{
			if (p->getISBN() == ISBN)
			{
				cout << p->getBook_ID() << endl;
				cout << p->getclassification_ID() << endl;
				cout << p->getname() << endl;
				cout << p->getauthor() << endl;
				cout << p->getpublishing_company() << endl;
				cout << p->getpublication_date() << endl;
				cout << p->getISBN() << endl;
				cout << p->getedition_number() << endl;
				cout << p->getprice() << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				p = p->next;
			}
		}
	}
	else
	if (choice == 8)
	{
		cout << "请输入需要查询的图书版次：" << endl;
		int edition_number;
		cin >> edition_number;
		book *p = bookHead;
		while (p)
		{
			if (p->getedition_number() == edition_number)
			{
				cout << p->getBook_ID() << endl;
				cout << p->getclassification_ID() << endl;
				cout << p->getname() << endl;
				cout << p->getauthor() << endl;
				cout << p->getpublishing_company() << endl;
				cout << p->getpublication_date() << endl;
				cout << p->getISBN() << endl;
				cout << p->getedition_number() << endl;
				cout << p->getprice() << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				p = p->next;
			}
		}
	}
	else
	if (choice == 9)
	{
		cout << "请输入需要查询的图书价格：" << endl;
		int price;
		cin >> price;
		book *p = bookHead;
		while (p)
		{
			if (p->getprice() == price)
			{
				cout << p->getBook_ID() << endl;
				cout << p->getclassification_ID() << endl;
				cout << p->getname() << endl;
				cout << p->getauthor() << endl;
				cout << p->getpublishing_company() << endl;
				cout << p->getpublication_date() << endl;
				cout << p->getISBN() << endl;
				cout << p->getedition_number() << endl;
				cout << p->getprice() << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				p = p->next;
			}
		}
	}
	system("pause");
}
void changeBook()
{
	system("cls");
	cout << "请输入需要修改的图书编号：" << endl;
	int book_ID;
	cin >> book_ID;
	book *p = bookHead;
	while (p)
	{
		if (p->getBook_ID() == book_ID)
		{
			cout << p->getBook_ID() << endl;
			cout << p->getclassification_ID() << endl;
			cout << p->getname() << endl;
			cout << p->getauthor() << endl;
			cout << p->getpublishing_company() << endl;
			cout << p->getpublication_date() << endl;
			cout << p->getISBN() << endl;
			cout << p->getedition_number() << endl;
			cout << p->getprice() << endl;
			cout << endl;
			break;
		}
		else
			p = p->next;
	}
	cout << "请选择需要修改的内容：" << endl;
	cout << "1.图书编号" << endl;
	cout << "2.中图分类号" << endl;
	cout << "3.书名" << endl;
	cout << "4.作者" << endl;
	cout << "5.出版社" << endl;
	cout << "6.出版日期" << endl;
	cout << "7.ISBN" << endl;
	cout << "8.版次" << endl;
	cout << "9.定价" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		book *q = bookHead;
		while (q)
		{
			if (q->getBook_ID() == book_ID)
			{
				cout << "请输入新的图书编号：" << endl;
				int book_id;
				cin >> book_id;
				q->setBook_ID(book_id);
				cout << "修改成功" << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				q = q->next;
			}
		}
	}
	if (choice == 2)
	{
		book *q = bookHead;
		while (q)
		{
			if (q->getBook_ID() == book_ID)
			{
				cout << "请输入新的中图分类号：" << endl;
				string classification_id;
				cin >> classification_id;
				q->setclassification_ID(classification_id);
				cout << "修改成功" << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				q = q->next;
			}
		}
	}
	if (choice == 3)
	{
		book *q = bookHead;
		while (q)
		{
			if (q->getBook_ID() == book_ID)
			{
				cout << "请输入新的书名：" << endl;
				string name;
				cin >> name;
				q->setname(name);
				cout << "修改成功" << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				q = q->next;
			}
		}
	}
	if (choice == 4)
	{
		book *q = bookHead;
		while (q)
		{
			if (q->getBook_ID() == book_ID)
			{
				cout << "请输入新的作者名字：" << endl;
				string author;
				cin >> author;
				q->setauthor(author);
				cout << "修改成功" << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				q = q->next;
			}
		}
	}
	if (choice == 5)
	{
		book *q = bookHead;
		while (q)
		{
			if (q->getBook_ID() == book_ID)
			{
				cout << "请输入新的出版社：" << endl;
				string publishing_company;
				cin >> publishing_company;
				q->setpublishing_company(publishing_company);
				cout << "修改成功" << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				q = q->next;
			}
		}
	}
	if (choice == 6)
	{
		book *q = bookHead;
		while (q)
		{
			if (q->getBook_ID() == book_ID)
			{
				cout << "请输入新的出版日期：" << endl;
				int publication_date;
				cin >> publication_date;
				q->setpublication_date(publication_date);
				cout << "修改成功" << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				q = q->next;
			}
		}
	}
	if (choice == 7)
	{
		book *q = bookHead;
		while (q)
		{
			if (q->getBook_ID() == book_ID)
			{
				cout << "请输入新的ISBN：" << endl;
				int ISBN;
				cin >> ISBN;
				q->setISBN(ISBN);
				cout << "修改成功" << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				q = q->next;
			}
		}
	}
	if (choice == 8)
	{
		book *q = bookHead;
		while (q)
		{
			if (q->getBook_ID() == book_ID)
			{
				cout << "请输入新的出版号：" << endl;
				int edition_number;
				cin >> edition_number;
				q->setedition_number(edition_number);
				cout << "修改成功" << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				q = q->next;
			}
		}
	}
	if (choice == 9)
	{
		book *q = bookHead;
		while (q)
		{
			if (q->getBook_ID() == book_ID)
			{
				cout << "请输入新的价格：" << endl;
				int price;
				cin >> price;
				q->setprice(price);
				cout << "修改成功" << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				q = q->next;
			}
		}
	}
}
void addReader()
{
	system("cls");
	string reader_ID;
	string name;
	string classification;
	string PassWord;
	cout << "请输入借书证号：" << endl;
	cin >> reader_ID;
	cout << "名字：" << endl;
	cin >> name;
	cout << "读者类别：" << endl;
	cin >> classification;
	cout << "密码：" << endl;
	reader *s = new reader(reader_ID, name, classification, PassWord);
	if (readerHead == NULL)
	{
		readerHead = s;
		s->next = NULL;
	}
	else
	{
		reader * p = readerHead;
		reader * q = NULL;
		while (p != NULL)
		{
			q = p;
			p = p->next;
		}
		//插入到链表最后
		q->next = s;
		q = q->next;
		q->next = NULL;
	}
	reader *q = readerHead;
	while (q)
	{
		cout << q->getreader_ID() << endl;
		q = q->next;
	}
	system("pause");
	administratorMenu();
}
void deleteReader()
{
	system("cls");
	cout << "请输入需要删除读者的编号：" << endl;
	string reader_ID;
	cin >> reader_ID;
	reader *p;
	if (readerHead->getreader_ID() == reader_ID)
	{
		p = readerHead;
		readerHead = readerHead->next;
		delete p;
		p = NULL;
		cout << "读者删除成功" << endl;
		system("pause");
		menu();
	}
	for (reader *q = readerHead; q->next; q = q->next)
	{
		if (q->next->getreader_ID() == reader_ID)
		{
			p = q->next;
			q->next = p->next;
			delete p;
			p = NULL;
			cout << "读者删除成功" << endl;
			system("pause");
			menu();
		}
	}
	cout << "输入有误，不存在该图书" << endl;
	system("pause");
	administratorMenu();
}
void inquiryReader()
{
	cout << "请选择以下方式进行查询：" << endl;
	cout << "1.读者编号" << endl;
	cout << "2.读者姓名" << endl;
	cout << "3.读者类别" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << "请输入需要查询的读者编号：" << endl;
		string reader_ID;
		cin >> reader_ID;
		reader *p = readerHead;
		while (p)
		{
			if (p->getreader_ID() == reader_ID)
			{
				cout << "读者信息如下：" << endl;
				cout << p->getreader_ID() << endl;
				cout << p->getName() << endl;
				cout << p->getClassification() << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				p = p->next;
			}
		}
	}
	else
	if (choice == 2)
	{
		cout << "请输入需要查询的读者名字：" << endl;
		string name;
		cin >> name;
		reader *p = readerHead;
		while (p)
		{
			if (p->getName() == name)
			{
				cout << "读者信息如下：" << endl;
				cout << p->getreader_ID() << endl;
				cout << p->getName() << endl;
				cout << p->getClassification() << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				p = p->next;
			}
		}
	}
	else
	if (choice == 3)
	{
		cout << "请输入需要查询的读者类别：" << endl;
		string classification;
		cin >> classification;
		reader *p = readerHead;
		while (p)
		{
			if (p->getClassification() == classification)
			{
				cout << "读者信息如下：" << endl;
				cout << p->getreader_ID() << endl;
				cout << p->getName() << endl;
				cout << p->getClassification() << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				p = p->next;
			}
		}
	}
}
void changeReader()
{
	cout << "请输入你要修改的读者编号：" << endl;
	string reader_ID;
	cin >> reader_ID;
	reader *p = readerHead;
	while (p)
	{
		if (p->getreader_ID() == reader_ID)
		{
			cout << p->getreader_ID() << endl;
			cout << p->getName() << endl;
			cout << p->getClassification();
			cout << endl;
			break;
		}
	}
	cout << "请输入需要需要修改的内容：" << endl;
	cout << "1.读者编号" << endl;
	cout << "2.读者姓名" << endl;
	cout << "3.读者类别" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		reader *q = readerHead;
		while (q)
		{
			if (q->getreader_ID() == reader_ID)
			{
				cout << "请输入新的读者编号：" << endl;
				int reader_id;
				cin >> reader_id;
				q->setreader_ID(reader_id);
				cout << "修改成功" << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				q = q->next;
			}
		}
	}
	else
	if (choice == 2)
	{
		reader *q = readerHead;
		while (q)
		{
			if (q->getreader_ID() == reader_ID)
			{
				cout << "请输入新的读者姓名：" << endl;
				string name;
				cin >> name;
				q->setName(name);
				cout << "修改成功" << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				q = q->next;
			}
		}
	}
	else
	if (choice == 3)
	{
		reader *q = readerHead;
		while (q)
		{
			if (q->getreader_ID() == reader_ID)
			{
				cout << "请输入新的读者类别：" << endl;
				string classification;
				cin >> classification;
				q->setClassification(classification);
				cout << "修改成功" << endl;
				system("pause");
				administratorMenu();
			}
			else
			{
				q = q->next;
			}
		}
	}
}
void returnBooks(string account)
{
	relationship *rs = relationshipHead;
	while (rs)
	{
		if (rs->nextReader->getreader_ID() == account)
		{
			book *bh = bookHead;
			cout << "请输入你要归还的图书名字：" << endl;
			string bookname;
			cin >> bookname;
			while (bh)
			{
				if (bh->getname() == bookname)
					bh->setbook_condition("0");
				if (rs->nextBook->getname() == bookname)
				{
					rs->nextBook = NULL;
					cout << "还书成功" << endl;
					break;
				}
				bh = bh->next;
			}
		}
		rs = rs->nextRelationship;
	}
	while (rs)
	{
		cout << "读者" << rs->nextReader->getName() << endl;
		if (rs->nextBook != NULL)
			cout << "借阅的图书:" << rs->nextBook->getname() << endl;
		if (rs->borrownextBook != NULL)
			cout << rs->borrownextBook->nextBook->getname() << endl;
		rs = rs->nextRelationship;
	}
	system("pause");
	readerMenu(account);
}
void borrowBooks(string account)
{
	int judge = 0, i = 0;
	book *b = bookHead;
	reader *r = readerHead;
	relationship *rs = relationshipHead;
	cout << "请输入需要借阅图书的书名：" << endl;
	string bookName;
	cin >> bookName;
	relationship *p = new relationship;
	while (rs)
	{
		if (rs->nextReader->getreader_ID() == account)
		{
			judge = 1;
			while (b)
			{
				if (b->getname() == bookName)
				if (b->getbook_condition() == "0")
				{
					if (rs->nextBook != NULL)
					{
						p->nextBook = b;
						rs->borrownextBook = p;
						cout << "借书成功" << endl;
						b->setbook_condition(account);
						system("pause");
						rs = relationshipHead;
						while (rs)
						{
							cout << "读者" << rs->nextReader->getName() << endl;
							cout << "借阅的图书:" << rs->nextBook->getname() << endl;
							if (rs->borrownextBook != NULL)
								cout << rs->borrownextBook->nextBook->getname() << endl;
							rs = rs->nextRelationship;
						}
						readerMenu(account);
					}
				}
				else
				{
					cout << "该书已被读者" << b->getbook_condition() << "借阅或预约" << endl;
					system("pause");
					readerMenu(account);
					break;
				}
				else
					b = b->next;
			}
		}
		else
			rs = rs->nextRelationship;
	}
	if (judge == 0)
	{
		r = readerHead;
		while (r&&i != 1)
		{
			if (r->getreader_ID() == account)
			{
				p->nextReader = r;
				b = bookHead;
				while (b)
				{
					if (b->getname() == bookName)
					{
						if (b->getbook_condition() != "0")
						{
							cout << "该书已被读者" << b->getbook_condition() << "借阅或预约" << endl;
							system("pause");
							readerMenu(account);
						}
						else
						{
							p->nextBook = b;
							p->nextBook->setbook_condition(account);
							i = 1;
							break;
						}
					}
					else
						b = b->next;
				}
			}
			else
				r = r->next;
		}
	}
	if (relationshipHead == NULL)
	{
		relationshipHead = p;
	}
	else
	{
		relationship * k = relationshipHead;
		relationship * q = NULL;
		while (k != NULL)
		{
			q = k;
			k = k->nextRelationship;
		}
		//插入到链表最后
		q->nextRelationship = p;
		q = q->nextRelationship;
		q->nextRelationship = NULL;
	}
	relationship *q = relationshipHead;
	while (q)
	{
		if (q->nextReader != NULL)
			cout << q->nextReader->getName() << endl;
		if (q->nextBook != NULL)
			cout << q->nextBook->getname() << endl;
		if (q->borrownextBook != NULL)
			cout << q->borrownextBook->nextBook->getname() << endl;
		q = q->nextRelationship;
	}
	system("pause");
	readerMenu(account);
}
void redisterBooks(string account)
{
	book *bh = bookHead;
	string bookname;
	cout << "请输入你想要预约的书：" << endl;
	cin >> bookname;
	while (bh)
	{
		if (bh->getname() == bookname)
		{
			if (bh->getbook_condition() == "0")
			{
				bh->setbook_condition(account);
				cout << "预约成功" << endl;
				system("pause");
				readerMenu(account);
				break;
			}
			else
			{
				cout << "该书已被用户" << bh->getbook_condition() << "预约" << endl;
				system("pause");
				readerMenu(account);
			}
		}
		bh = bh->next;
	}
}
void readerMenu(string account)
{
	system("cls");
	cout << "\t\t\t\t  欢迎  \t\t\t\t" << endl;
	cout << "\t\t\t\t1.借书\t\t\t\t\t" << endl;
	cout << "\t\t\t\t2.还书\t\t\t\t\t" << endl;
	cout << "\t\t\t\t3.预约\t\t\t\t\t" << endl;
	cout << "\t\t\t\t4.返回\t\t\t\t\t" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: borrowBooks(account); break;
	case 2: returnBooks(account); break;
	case 3: redisterBooks(account); break;
	case 4: menu(); break;
	}
}
void borrowAndReturn()
{
	relationship *rs = relationshipHead;
	while (rs)
	{
		cout << "读者" << rs->nextReader->getName() << endl;
		if (rs->nextBook != NULL)
			cout << "借阅的图书:" << rs->nextBook->getname() << endl;
		if (rs->borrownextBook != NULL)
			cout << rs->borrownextBook->nextBook->getname() << endl;
		rs = rs->nextRelationship;
	}
	system("pause");
	administratorMenu();
}
void administratorMenu()
{
	system("cls");
	cout << "\t\t\t\t 管理员菜单" << endl;
	cout << "\t\t\t\t1.读者管理" << endl;
	cout << "\t\t\t\t2.图书管理" << endl;
	cout << "\t\t\t\t3.借阅管理" << endl;
	cout << "\t\t\t\t4.返回" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << "\t\t\t\t   读者管理\t\t\t\t\t" << endl;
		cout << "\t\t\t\t 1.添加读者\t\t\t\t\t" << endl;
		cout << "\t\t\t\t 2.删除读者\t\t\t\t\t" << endl;
		cout << "\t\t\t\t 3.查询读者\t\t\t\t\t" << endl;
		cout << "\t\t\t\t 4.修改信息\t\t\t\t\t" << endl;
		int x;
		cin >> x;
		switch (x)
		{
		case 1:addReader();
			break;
		case 2:deleteReader();
			break;
		case 3:inquiryReader();
			break;
		case 4:changeReader();
			break;
		}
	}
	else
	if (choice == 2)
	{
		system("cls");
		cout << "\t\t\t\t   图书管理\t\t\t\t\t" << endl;
		cout << "\t\t\t\t 1.添加图书\t\t\t\t\t" << endl;
		cout << "\t\t\t\t 2.删除图书\t\t\t\t\t" << endl;
		cout << "\t\t\t\t 3.查询图书\t\t\t\t\t" << endl;
		cout << "\t\t\t\t 4.修改图书\t\t\t\t\t" << endl;
		int x;
		cin >> x;
		switch (x)
		{
		case 1:addBook();
			break;
		case 2:deleteBook();
			break;
		case 3:inquiryBook();
			break;
		case 4:changeBook();
			break;
		}
	}
	else
	if (choice == 3)
	{
		system("cls");
		cout << "\t借阅管理\t" << endl;
		cout << "以下是所有读者的借阅情况：" << endl;
		borrowAndReturn();
	}
	else
	if (choice == 4)
	{
		system("cls");
		menu();
	}
}
/*
void dataRetention()
{

}*/
void menu()
{
	system("cls");
	cout << "\t\t\t\t欢迎进入图书管理系统\t\t\t\t" << endl;
	cout << "\t\t\t\t    1.管理员登陆\t\t\t\t\t" << endl;
	cout << "\t\t\t\t    2.读者登陆\t\t\t\t\t" << endl;
	cout << "\t\t\t\t    3.保存数据\t\t\t\t\t" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		string account, password;
		string account_s, password_s;
	loop:
		{
			cout << "管理员账号:" << endl;
			cout << "密码:" << endl;
			cin >> account >> password;
			ifstream in("C:\\data\\administrator.txt");
			in >> account_s;
			in >> password_s;
		}
		if (account == account_s&&password == password_s)
			administratorMenu();
		else
		{
			cout << "输入错误,请重新输入" << endl;
			goto loop;
		}
	}
	else
	if (choice == 2)
	{
		cout << "读者ID:" << endl;
		cout << "密码：" << endl;
		string account, password;
		string account_s, password_s;
		cin >> account >> password;
		for (int i = 0; i < sum; i++)
		{
			if (account == reader_ID[i] && password == PassWord[i])
			{
				readerMenu(account);
			}
		}
	}
	else
	if (choice == 3)
	{
		saveBookdata();
		saveReaderdata();
		saveBorrowdata();
	}
}
void account_password()
{
	int i = 0;
	ifstream in("C:\\data\\reader.txt");
	while (!in.eof())
	{
		string name;
		string classification;
		in >> reader_ID[i];
		in >> name;
		in >> classification;
		in >> PassWord[i];
		i++;
	}
	sum = i;
	in.close();
}
int main()
{
	/*数据恢复*/	
	readerDataRecovery();
    bookDataRecoverry();
	account_password();
	menu();
}
