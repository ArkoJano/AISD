#include <iostream>
struct Node {
        int element;
        Node* left;
        Node* right;
        int height;

        
        //sprawdza czy jest lisciem
        bool isLeafNode() const{
            return !(left || right);
        }

        
};

class AVLTree {
    private:
        

        Node *root = nullptr;

        int max(int a, int b);

        // zwraca wysokość danego wezla
        int getHeight(Node *node);
        void updateHeight(Node* node);
        Node* right_rotation(Node* parent);
        Node* left_rotation(Node* parent);
       


    public: 
        AVLTree();  // konstruktor domyslny
        AVLTree(const AVLTree& t);  //konstruktor kopiujacy
        AVLTree(AVLTree && t);      //konstruktor
        ~AVLTree(); //destruktor
        const int & findMin() const; //zwraca WARTOSC najmniejszego elementu
        const int & findMax() const; //zwraca WARTOSC najwiekszego elementu
        Node* findMin(Node *t) const; //zwraca WSKAZNIK najmniejszego elementu
        Node* findMax(Node *t) const; //zwraca WSKAZNIK najwiekszego elementu

        // sprawdza, czy element o podanej wartosci wystepuje w drzewie
        bool contains(const int& element) const;
       
        // sprawdza, czy element o podanej wartosci wystepuje w poddrzewie
        // o korzeniu w wezle podanym przez wskaznik t
        bool contains(const int& element, Node* t) const;
        Node* findElement(const int& element, Node* t);

        int getBalanceFactor(Node* node);

        Node* getRoot();
        Node*& getRefRoot();
        Node* newNode(int element);
        void setRoot(Node* newRoot);
        void makeEmpty(Node** node );
        Node* copy(Node* node);

        bool isEmpty();
        Node* insert(Node *node, int element);
        Node* remove(int element);
        Node* remove(int element, Node* t);
        void printTreeInOrder(Node *t);
        void printTreePreOrder(Node *t);
        void printTreePostOrder(Node *t);


        // Node* clone (Node* t); // zwraca wskaznik do skopiowanego podrzewa

        AVLTree & operator=(const AVLTree& t);
        AVLTree & operator=(AVLTree&& t);

};