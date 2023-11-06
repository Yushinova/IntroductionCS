#include <iostream>
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
	int DepthTree()
	{
		return DepthTree(Root);
	}
	int DepthTree(Element* Root)
	{
		int leftDepth, rightDepth;
		if (Root == nullptr) return 0;
		leftDepth = DepthTree(Root->pLeft);
		rightDepth = DepthTree(Root->pRight);
		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
		/*if (leftDepth > rightDepth) return leftDepth + 1;
		else return rightDepth + 1;*/
	}
	void PrintDepth(int depth, int var)
	{
		PrintDepth(Root, depth, var);
	}
	void PrintDepth(Element* Root, int depth, int var)
	{
		/*int temp = DepthTree() - depth + 1;*/
		if (Root == nullptr) return;
		PrintDepth(Root->pLeft, depth+1, var);
		PrintDepth(Root->pRight, depth+1, var);
		if (depth == var) cout << Root->Data << "\t";	
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
	void BalanceTree()
	{
		BalanceTree(Root);
	}
	void BalanceTree(Element*& Root)//если левая или правая сторона имеют разную глубину
	{
		int temp = Root->Data;
		if (Root == nullptr) return;
		if (DepthTree(Root->pLeft) != DepthTree(Root->pRight))
		{
			DellElement(temp);
			insert(temp);
		}
		if(DepthTree(Root->pLeft) < DepthTree(Root->pRight)) BalanceTree(Root->pRight);
		if(DepthTree(Root->pLeft) > DepthTree(Root->pRight)) BalanceTree(Root->pLeft);
	}
	void BalanceTree(vector<int> &bufer)
	{
		BalanceTree(Root, bufer);
	}
	void BalanceTree(Element* &Root, vector <int> &bufer)//для полностью вырожденного дерева
	{
		if (Root == nullptr) return;
		BalanceTree(Root->pLeft, bufer);
		BalanceTree(Root->pRight, bufer);
		bufer.push_back(Root->Data);
		
		if (bufer.size() == CountTree())
		{
			DellTree();
			do
			{
				int first = bufer[bufer.size() / 2];
				bufer.erase(bufer.begin() + bufer.size() / 2);
				insert(first);
			} while (bufer.size()!=0);
			BalanceTree(Root->pLeft);
			BalanceTree(Root->pRight);
		}		
	}
	auto SpeedPrint()
	{
		auto start = chrono::system_clock::now();
		PrintTree(60, 12);
		auto end = chrono::system_clock::now();
		cout << "Print tree: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisec" << endl;
	}
	auto SpeedDellTree(Tree &obj)
	{
		auto start = chrono::system_clock::now();
		obj.DellTree();
		auto end = chrono::system_clock::now();
		cout << "Dell tree: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisec" << endl;
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

//#define SUMPLE_TREE
//#define BALANCE1
#define BALANCE2
//#define SPEED
void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
#ifdef SUMPLE_TREE

	Tree tree;
	for (size_t i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
		/*tree.printElement(tree.getRoott());
		Sleep(400);*/
	}
	tree.printElement();
	cout << endl;
	cout << "Min: " << tree.MinData() << endl;
	cout << "Max: " << tree.MaxData() << endl;
	cout << "Summ: " << tree.SummData() << endl;
	cout << "Count: " << tree.CountTree() << endl;
	cout << "Avg: " << tree.AvgTree() << endl;
	cout << "Depth: " << tree.DepthTree() << endl;
	tree.DellTree();
#endif

	UniqueTree treeU;
	n = 8;
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
	treeU.printElement();
	cout << endl;
	cout << "Min: " << treeU.MinData() << endl;
	cout << "Max: " << treeU.MaxData() << endl;
	cout << "Summ: " << treeU.SummData() << endl;
	cout << "Count: " << treeU.CountTree() << endl;
	cout << "Avg: " << treeU.AvgTree() << endl;
	cout << "Depth: " << treeU.DepthTree() << endl;
	treeU.DellElement(62);
	treeU.printElement();
	cout << endl;
	cout << "Depth 3: ";
	treeU.PrintDepth(1,3);
	treeU.PrintTree(15, 12);
#ifdef BALANCE1
	treeU.BalanceTree();
	treeU.PrintTree(60, 12);
#endif // BALANCE1
#ifdef BALANCE2
	vector <int> bufer;//для вырожденного дерева
	treeU.BalanceTree(bufer);
	cout << endl;
	treeU.PrintTree(60, 12);
#endif // BALANCE2
#ifdef SPEED
	//измерение скорости методов
	treeU.SpeedPrint();
	treeU.SpeedDellTree(treeU);//если раскомментировать все вызовы диструкторов, то 36 милисек 
#endif // SPEED	
	setCursor(50, 50);
	
}