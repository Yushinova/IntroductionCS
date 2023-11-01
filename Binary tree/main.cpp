#include <iostream>
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
	void printElement(Element *Root) const
	{
		if (Root == nullptr) return;
		printElement(Root->pLeft);
		cout << Root->Data << "\t";
		printElement(Root->pRight);
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
	}
	tree.printElement(tree.getRoott());
	cout << endl;
}