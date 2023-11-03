#include <iostream>
#include <Windows.h>
using namespace std;
class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "ECtor: " << this << endl;
		}
		~Element()
		{
			cout << "EDistr: " << this << endl;
		}
		friend class Tree;
	}*Root;
public:
	Tree()
	{
		Root = nullptr;
		cout << "TCtor: " << this << endl;
	}
	~Tree()
	{
		cout << "TDistr: " << this << endl;
	}
	Element* getRoott()
	{
		return Root;
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
	void printElement(Element* Root) const
	{
		if (Root == nullptr) return;
		printElement(Root->pLeft);
		cout << Root->Data << "\t";
		printElement(Root->pRight);
	}
	int MinData(Element* Root)
	{
		if (Root == nullptr) return 0;
		if (Root->pLeft == nullptr) return Root->Data;
		else MinData(Root->pLeft);
	}
	int MaxData(Element* Root)
	{
		if (Root == nullptr) return 0;
		if (Root->pRight == nullptr) return Root->Data;
		else MaxData(Root->pRight);
	}
	int SummData(Element* Root)
	{
		if (Root == nullptr) return 0;
		return (Root->Data + SummData(Root->pLeft) + SummData(Root->pRight));
	}
	int CountTree(Element* Root)
	{
		int count = 0;
		if (Root == nullptr) return 0;
		if (Root->pLeft != nullptr) count++;
		if (Root->pRight != nullptr) count++;
		return (1 + CountTree(Root->pLeft) + CountTree(Root->pRight));
	}
	double AvgTree(Element* Root)
	{
		return double(SummData(this->Root)) / CountTree(this->Root);
	}
	void DellTree(Element* Root)
	{
		if (Root == nullptr) return;
		DellTree(Root->pLeft);
		DellTree(Root->pRight);
		delete Root;
		this->Root = nullptr;		
	}
	void DellElement(Element* Root, int var)
	{
		if (var < Root->Data)DellElement(Root->pLeft, var);
		if (var > Root->Data)DellElement(Root->pRight, var);
		else
		{
			if (Root->pLeft == nullptr && Root->pRight == nullptr)//диструктор сработал, но дерево поломалось
			{
				delete Root;
				Root->pLeft = nullptr;
				Root->pRight = nullptr;
			}
		}
		
	}
};
void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	Tree tree;
	for (size_t i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.getRoott());
		/*tree.printElement(tree.getRoott());
		Sleep(400);*/
	}
	tree.printElement(tree.getRoott());
	cout << endl;
	cout << "Min: " << tree.MinData(tree.getRoott()) << endl;
	cout << "Max: " << tree.MaxData(tree.getRoott()) << endl;
	cout << "Summ: " << tree.SummData(tree.getRoott()) << endl;
	cout << "Count: " << tree.CountTree(tree.getRoott()) << endl;
	cout << "Avg: " << tree.AvgTree(tree.getRoott()) << endl;
	tree.DellTree(tree.getRoott());
	n = 5;
	for (size_t i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.getRoott());
		/*tree.printElement(tree.getRoott());
		Sleep(400);*/
	}
	tree.printElement(tree.getRoott());
	cout << endl;
	tree.DellElement(tree.getRoott(), 64);
	tree.printElement(tree.getRoott());
}