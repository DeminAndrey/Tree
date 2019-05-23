//��������� ��� �������� ������ ������������� ���������
#include <iostream>

using namespace std;

//��������� ����� - ���� ������
template<typename T=int>
class Node
{
private:
    T value;
public:
    Node* l; //����� ����� ����� ������
    Node* r; //����� ������ ����� ������
    Node(T x) //� ������������ ����������� �������� �������� ���������� � ��������
    {
        cout<<"create: "<<this<<endl;
        value=x;
        l=nullptr;
        r=nullptr;
    }
    T getValue() const
    {
        return value;
    }
    ~Node(){}
    Node()=delete;
    Node(const Node&)=delete;
    Node(Node&&)=delete;
};

//��������� ������� ��� ������ �������� ������
template<typename X>
void Show(Node<X>*& tree)
{
    if(tree!=nullptr)
    {
        Show(tree->l);
        cout<<tree->getValue()<<'\t';
        Show(tree->r);
    }
}

//��������� ������� �������� ������
template<typename X>
void delTree(Node<X>*& tree)
{
    if(tree!=nullptr)
    {
        delTree(tree->l);
        delTree(tree->r);
        delete tree;
    }
}

//��������� ������� ���������� ����� � ������
template<typename X>
void addTree(X a, Node<X>*& tree)
{
    if(tree==nullptr) //���� ������� ������ ������ ����������� �������� ���� �������� ����� ������
    {
        tree=new Node<X>(a);
        return;
    }
    if(a<tree->getValue())
    {
        if(tree->l!=nullptr) //���������� ������� � ����� ����� ������
        {
            addTree(a, tree->l);
        }
        else
        {
            tree->l=new Node<X>(a);
        }
    }
    else if(a>tree->getValue())
    {
        if(tree->r!=nullptr) //���������� ������� � ������ ����� ������
        {
            addTree(a, tree->r);
        }
        else
        {
            tree->r=new Node<X>(a);
        }
    }
    else return;
}

int main()
{
    Node<>* tree=nullptr;
    //��������� ����� ����� ������ ����������
    for(int i=10; i>5; --i)
    {
        addTree(i, tree);
    }
    //��������� ������ ����� ������ ����������
    for(int i=11; i<16; ++i)
    {
        addTree(i, tree);
    }
    //������� ��������
    Show(tree);
    cout<<endl;
    //������� ������
    delTree(tree);

    return 0;
}
