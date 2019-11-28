#include <iostream>
#include <list>

struct Node
{
    int data;
    Node *next;//Estamos criando um ponteiro para nossa estrutra
};

class LinkList
{
    private:
        Node *head, *tail;//Criando dois ponteiro para a estruta do node
    public:
        LinkList()
        {
            //atribuimos o valor deles como null, null = 0.
            head = 0;
            tail = 0;
        }
        void createNode(int number);
        void displayNode();
        void eraseNode(int number);
        Node *searchNode(int number);
        inline int notEmpty();
};

void LinkList::createNode(int number)
{
    Node *temp = new Node;//Criamos um ponteiro e passamos para ele a instancia do Node
    temp -> data = number;//Atribuimos ao bloco da memória data o valor do nosso parametro
    /*
    Next sempre apontara para uma memória, ja essa é a primeira instacia de node,
    nao temos outro node para apontar, logo ele apontará para NULL;
    */    
    temp -> next = 0;
    if(head == 0)//pq 0x00 == 0; não é permitido fazer bitwise?
    {
        head = temp;
        tail = temp;
        temp = 0;
    }
    else
    {
        tail -> next = temp;
        tail = temp;
    }
}

void LinkList::displayNode()
{
    Node *temp = new Node;
    temp = head;
    while(temp != NULL)
    {
        printf("%d", temp -> data);
        temp = temp -> next;
    }
    puts("\n");
}

//retornamos o a memoria do node que o numero esta presente
Node *LinkList::searchNode(int number)
{
    Node *temp = new Node;
    temp = head;
    //comparações entre verdadeiro e falso, 0 ou 1; melhor se usa de bitwise do que comparado lógico
    while( (temp -> next != 0) & (temp -> data != number) ) { temp = temp -> next; }
    //se chego no fim da list e o valor não for igual, null sera retornado
    if(temp -> data == number) { return temp; }
    else { return 0; }
}

void LinkList::eraseNode(int number)
{
    Node *found = searchNode(number);
    //se o valor for null logo return para não ocorre erro de memoria
    if(found == 0){ return; }
    
    Node *temp = head;
    if(temp == found) { head = temp -> next; }
    else
    {
        while( (temp -> next) != found) { temp = temp -> next; }
        temp -> next = found -> next;
        int a = 0;
    }
}

/*
funções inline é uma keyword que perfomiza a função, falando para o intepretador não fazer jmp,
a função é executada como se fosse um macro
*/
inline int LinkList::notEmpty() { return head == 0; }

int main()
{
    LinkList ae;
    
    std::cout << ae.notEmpty() << std::endl;
    ae.createNode(2);
    ae.createNode(4);
    
    std::cout << ae.notEmpty() << std::endl;
    ae.createNode(6);
    ae.createNode(9);
    ae.createNode(8);
    ae.displayNode();

    std::cout << ae.searchNode(6) << std::endl;    
    ae.eraseNode(2);
    ae.displayNode();

    // std::list<int> lista = {1,2,3,4};
    // for(int x: lista)
    // {
    //     std::cout << x << std::endl;
    // }
}