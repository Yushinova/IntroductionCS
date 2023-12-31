﻿#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <io.h>
#include <vector>
#include <time.h>
#include <chrono>
using namespace std;
//#define DISTR
enum Color
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown,
	LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, Esc = 27 };
void setCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}
class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DISTR

			cout << "ECtor: " << this << endl;
#endif
		}
		~Element()
		{
#ifdef DISTR
			cout << "EDistr: " << this << endl;

#endif // DISTR
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Tree()
	{
		Root = nullptr;
#ifdef DISTR
		cout << "TCtor: " << this << endl;
#endif // DISTR

	}
	~Tree()
	{
#ifdef DISTR
		cout << "TDistr: " << this << endl;
#endif // DISTR
		DellTree();
	}
public:
	Element* getRoott()
	{
		return Root;
	}
	void insert(int Data)
	{
		insert(Data, Root);
	}
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr) this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr) Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr) Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	void printElement()const
	{
		printElement(Root);
	}
	void printElement(Element* Root) const
	{
		if (Root == nullptr) return;
		printElement(Root->pLeft);
		cout << Root->Data << "\t";
		printElement(Root->pRight);
	}
	int MinData()const
	{
		return MinData(Root);
	}
	int MinData(Element* Root)const
	{
		if (Root == nullptr) return 0;
		if (Root->pLeft == nullptr) return Root->Data;
		else return MinData(Root->pLeft);
	}
	int MaxData() const
	{
		return MaxData(Root);
	}
	int MaxData(Element* Root) const
	{
		if (Root == nullptr) return 0;
		if (Root->pRight == nullptr) return Root->Data;
		else return MaxData(Root->pRight);
	}
	int SummData()const
	{
		return SummData(Root);
	}
	int SummData(Element* Root) const
	{
		/*if (Root == nullptr) return 0;
		return (Root->Data + SummData(Root->pLeft) + SummData(Root->pRight));*/
		return Root == nullptr ? 0 : Root->Data + SummData(Root->pLeft) + SummData(Root->pRight);//тернарник
	}
	int CountTree() const
	{
		return CountTree(Root);
	}
	int CountTree(Element* Root) const
	{
		/*if (Root == nullptr) return 0;
		return (1 + CountTree(Root->pLeft) + CountTree(Root->pRight));*/
		return Root == nullptr ? 0 : 1 + CountTree(Root->pLeft) + CountTree(Root->pRight);
	}
	double AvgTree() const
	{
		return AvgTree(Root);
	}
	double AvgTree(Element* Root) const
	{
		return double(SummData(this->Root)) / CountTree(this->Root);
	}
	void DellTree()
	{
		DellTree(Root);
	}
	void DellTree(Element* Root)
	{
		if (Root == nullptr) return;
		DellTree(Root->pLeft);
		DellTree(Root->pRight);
		delete Root;
		this->Root = nullptr;
	}
	void DellElement(int var)
	{
		DellElement(Root, var);
	}
	void DellElement(Element*& Root, int var)
	{
		if (Root == nullptr)return;
		if (var == Root->Data)
		{
			if (Root->pLeft == Root->pRight)
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (CountTree(Root->pLeft) > CountTree(Root->pRight))
				{
					Root->Data = MaxData(Root->pLeft);
					DellElement(Root->pLeft, MaxData(Root->pLeft));
				}
				else
				{
					Root->Data = MinData(Root->pRight);
					DellElement(Root->pRight, MinData(Root->pRight));
				}
			}
		}
		if (Root)DellElement(Root->pLeft, var);
		if (Root)DellElement(Root->pRight, var);
	}
	int DepthTree()const
	{
		return DepthTree(Root);
	}
	int DepthTree(Element* Root) const
	{
		int leftDepth, rightDepth;
		if (Root == nullptr) return 0;
		leftDepth = DepthTree(Root->pLeft)+1;
		rightDepth = DepthTree(Root->pRight)+1;
		return leftDepth > rightDepth ? leftDepth : rightDepth;//возвращаем глубину самой длинной ветки
		/*if (leftDepth > rightDepth) return leftDepth + 1;
		else return rightDepth + 1;*/
	}
	void PrintDepth(int depth, int var)const
	{
		PrintDepth(Root, depth, var);
	}
	void PrintDepth(Element* Root, int depth, int var)const
	{
		if (Root == nullptr) return;
		PrintDepth(Root->pLeft, depth+1, var);//потому что передаем первую глубину, а следующий шаг, это в любом случае +1
		PrintDepth(Root->pRight, depth+1, var);
		if (depth == var) cout << Root->Data << "\t";	
	}
	void PrintDepth(int depth)const
	{
		PrintDepth(this->Root, depth);
	}
	void PrintDepth(Element* Root, int depth)const
	{
		if (Root == nullptr) return;
		
		PrintDepth(Root->pLeft, depth - 1);//потому что передаем первую глубину, а следующий шаг, это в любом случае +1
		PrintDepth(Root->pRight, depth - 1);	
		if (depth == 1) cout << Root->Data << "\t";
	}
	void PrintTree(int X, int Y)
	{
		PrintTree(Root, X, Y);
	}
	int size = 4;
	void PrintTree(Element* Root, int X, int Y)
	{
		int tempX = X;
		int tempY = Y;
		if (Root == nullptr)return;
		if (Root->pRight == nullptr && Root->pLeft == nullptr)
		{
			setColor(Black, LightGreen);
		}	
		else setColor(Black, Brown);
		setCursor(X, Y);
		cout << Root->Data << endl;
		if (Root->pLeft != nullptr)
		{
			setColor(Red, Black);
			for (size_t i = 0; i < size; i++)
			{
				setCursor(X - 1, Y + 1);
				cout << "/" << endl;
				X--;
				Y++;
			}
			setCursor(X, Y + 1);
			setColor(White, Black);
		}
		if (Root->pRight != nullptr)
		{
			setColor(Red, Black);
			for (size_t i = 0; i < size; i++)
			{
				setCursor(tempX + 1, tempY + 1);
				cout << "\\" << endl;
				tempX++;
				tempY++;
			}
			setCursor(tempX, tempY + 1);
			setColor(White, Black);
		}
		size = 6;
		PrintTree(Root->pLeft, X, Y);
		PrintTree(Root->pRight, tempX, tempY);
		size--;
		if (size == 1) size = 6;
		setColor(White, Black);
	}
	void BalanceTreeCount()
	{
		BalanceTreeCount(Root);
	}
	void BalanceTreeCount(Element*& Root)//ВЕРНОЕ РЕШЕНИЕ
	{
		int temp = Root->Data;
		while (abs(CountTree(Root->pLeft) - CountTree(Root->pRight)) > 1)
		{
			temp = Root->Data;
			if (Root == nullptr) return;
			if (abs(CountTree(Root->pLeft) - CountTree(Root->pRight)) < 2) return;
			else
			{
				DellElement(temp);
				insert(temp);
			}
			BalanceTreeCount(Root->pRight);
			BalanceTreeCount(Root->pLeft);
		}
	}
};
class UniqueTree :public Tree
{
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
public:
	void insert(int Data)
	{
		insert(Data, Root);
	}
};
double Speed(const Tree &obj, int (Tree::* ptr)()const)//функция измерения скорости
{
	clock_t start = clock();
	double var = (obj.*ptr)();
	//cout<<"Result: "<< (obj->*ptr)() <<"\t";//работает дольше с cout
	clock_t end = clock();
	return double(end - start) / CLOCKS_PER_SEC;//возвращает в секундах
}
double Speed(const Tree &obj, void (Tree::* ptr)()const)//функция измерения void без аргументов
{
	clock_t start = clock();
	(obj.*ptr)();
	clock_t end = clock();
	return double(end - start) / CLOCKS_PER_SEC;
}
//#define SUMPLE_TREE
#define UNIQUE_TREE
#define BALANCE1
//#define BALANCE2
#define SPEED
void main()
{
	setlocale(LC_ALL, "");
	int n = 10;
	
#ifdef SUMPLE_TREE

	Tree tree;
	for (size_t i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
		/*tree.printElement(tree.getRoott());
		Sleep(400);*/
	}
	//tree.printElement();
	cout << endl;
	cout << "Min: " << tree.MinData() << endl;
	cout << "Max: " << tree.MaxData() << endl;
	cout << "Summ: " << tree.SummData() << endl;
	cout << "Count: " << tree.CountTree() << endl;
	cout << "Avg: " << tree.AvgTree() << endl;
	cout << "Depth: " << tree.DepthTree() << endl;
#ifdef SPEED
	//измерение скорости методов
	//int (Tree:: * ptr)()const;
	cout << "Min: " << Speed(tree, &Tree::MinData) << " sek" << endl;
	cout << "Max: " << Speed(tree, &Tree::MaxData) << " sek" << endl;
	cout << "Summ: " << Speed(tree, &Tree::SummData) << " sek" << endl;
	cout << "Count: " << Speed(tree, &Tree::CountTree) << " sek" << endl;
	cout << "DephTree: " << Speed(tree, &Tree::DepthTree) << " sek" << endl;
	void (Tree:: * ptr2)()const;
	ptr2 = &Tree::printElement;
	cout << "Print: " << Speed(tree, ptr2) << " sek" << endl;
#endif // SPEED	
	tree.DellTree();
#endif
#ifdef UNIQUE_TREE
	UniqueTree treeU;
	n = 10;
	int k = 1;
	for (size_t i = 0; i < n; i++)
	{
#ifdef BALANCE1
		treeU.insert(rand() % 100);
#endif //BALANCE1		
#ifdef BALANCE2
		treeU.insert(k);
		k++;
#endif // BALANCE2
		/*treeU.printElement();
		Sleep(400);*/
	}
#ifdef BALANCE1
	treeU.printElement();
	cout << endl;
	//измерение скорости методов
	//int (Tree:: * ptr)()const;
	cout << "Min: " << Speed(treeU, &Tree::MinData) << " sek" << endl;
	cout << "Max: " << Speed(treeU, &Tree::MaxData) << " sek" << endl;
	cout << "Summ: " << Speed(treeU, &Tree::SummData) << " sek" << endl;
	cout << "Count: " << Speed(treeU, &Tree::CountTree) << " sek" << endl;
	cout << "DephTree: " << Speed(treeU, &Tree::DepthTree) << " sek" << endl;
	void (Tree:: * ptr2)()const;
	ptr2 = &Tree::printElement;
	cout << "Print: " << Speed(treeU, ptr2) << " sek" << endl;
	cout << "Depth 3: ";
	treeU.PrintDepth(3);
	treeU.PrintTree(15, 12);
	treeU.BalanceTreeCount();
	treeU.PrintTree(60, 12);
#endif // BALANCE1
#ifdef BALANCE2
	treeU.printElement();
	treeU.PrintTree(15, 12);
	treeU.BalanceTreeCount();
	cout << endl;
	treeU.PrintTree(60, 12);
#endif // BALANCE2

#endif // UNIQUE_TREE

	setCursor(50, 50);
	
}