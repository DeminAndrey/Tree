//программа для создания дерева упорядоченных элементов
#include <iostream>

using namespace std;

//шаблонный класс - узла дерева
template<typename T=int>
class Node
{
private:
    T value;
public:
    Node* l; //адрес левой части дерева
    Node* r; //адрес правой части дерева
    Node(T x) //в конструкторе присваиваем элементы значение переданное в параметр
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

//шаблонная функция для вывода значений дерева
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

//шаблонная функция удаления дерева
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

//шаблонная функция добавления звена в дерево
template<typename X>
void addTree(X a, Node<X>*& tree)
{
    if(tree==nullptr) //если звеньев дерево пустое присваиваем значение полю первоого звена дерева
    {
        tree=new Node<X>(a);
        return;
    }
    if(a<tree->getValue())
    {
        if(tree->l!=nullptr) //записываем элемент в левую часть дерева
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
        if(tree->r!=nullptr) //записываем элемент в правую часть дерева
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
    //заполняем левую часть дерева элементами
    for(int i=10; i>5; --i)
    {
        addTree(i, tree);
    }
    //заполняем правую часть дерева элементами
    for(int i=11; i<16; ++i)
    {
        addTree(i, tree);
    }
    //выводим элементы
    Show(tree);
    cout<<endl;
    //удаляем дерево
    delTree(tree);

    return 0;
}
