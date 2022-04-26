#include "AVLTree.h"
#include "iostream"

AVLTree::AVLTree() {
    root = nullptr;
}

// konstruktor z argumentem jako rvalue referencji
AVLTree::AVLTree(AVLTree && tree){
    root = tree.root;
} 

// konstruktor Node tylko dla funkcji copy
Node* new_Node(int element, Node* left,
                        Node* right, int height = 1){
    Node* node = new Node();
    node->element = element;
    node->left = left;
    node->right = right;
    node->height = height;
    return (node);
}

// funkcja kopiujaca drzewo
Node* AVLTree::copy(Node* node){
    if ( node != NULL )
    {
        Node* left = copy( node->left );
        Node* right = copy( node->right );
        return new_Node(node->element, left, right, node->height);
    }
    else
    {
        return NULL;
    }
}

// konstruktor kopiujacy
AVLTree::AVLTree(const AVLTree& tree){
    root = copy(tree.root);
}

// destruktor
AVLTree::~AVLTree(){
    makeEmpty(&root);
}

AVLTree & AVLTree::operator=(const AVLTree& tree){
    if(this != &tree){
        this->makeEmpty(&root);
        root = copy(tree.root);
    }
    return *this;
}

AVLTree & AVLTree::operator=(AVLTree&& tree){
    if(this != &tree){
        this->makeEmpty(&root);
        root = copy(tree.root);
    }
    return *this;
}


// funkcja zwracajaca root
Node* AVLTree::getRoot(){
    return root;
}
// funkcja zwracajaca referencje do root
Node*& AVLTree::getRefRoot(){
    return root;
};

// funkcja ustawiajaca nowa wartosc root
void AVLTree::setRoot(Node* newRoot){
    root = newRoot;
}

// funkcja pomocnicza do czyszczenia drzewa
// usuwa rekurencyjnie wszystkie elementy na galeziach
void _makeEmpty(Node *node ){
    if ( node == NULL) return; 
    
    _makeEmpty ( node -> left ) ;
    _makeEmpty ( node -> right ) ;
    delete node;
    
    // delete node;
}

// funkcja usuwajaca cale drzewo
// _makeEmpty usuwa galezie
// a makeEmpty ustawia root na NULL
void AVLTree::makeEmpty(Node **node ){
    _makeEmpty(*node);
    *node = NULL;
}

// tworzenie nowego wezla
Node* AVLTree::newNode(int element){
    Node* node = new Node();
    node->element = element;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}


int AVLTree::max(int a, int b) {
    return (a > b) ? a : b;
}

int AVLTree::getHeight(Node *node){
    if (node == nullptr)
    return 0;

    // if	(node->isLeafNode())
    //     return 0;

    return node->height;
}

void AVLTree::updateHeight(Node* node)
{
    // if (!node->isLeafNode())
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    // else node->height = 0;
}

// obliczanie wskaznika balansu dla 
// danego wezla
int AVLTree::getBalanceFactor(Node* node){
    if (!root || root->isLeafNode())
			return 0;

		return getHeight(root->left) - getHeight(root->right);
}

Node* AVLTree::left_rotation(Node* parent){
    Node* new_parent, *tmp;
    new_parent = parent->right;
    tmp = new_parent->left;
    parent->right = tmp;
    new_parent->left = parent;

    updateHeight(parent);
    updateHeight(new_parent);

    return new_parent;
}

Node* AVLTree::right_rotation(Node* parent){
    Node *new_parent, *tmp;
    
    new_parent = parent->left;
    tmp = new_parent->right;
    new_parent->right = parent;
    parent->left = tmp;   

    updateHeight(parent);
    updateHeight(new_parent);
    
return new_parent;
}

// funkcja wstawiajaca nowy element do drzewa
Node* AVLTree::insert(Node* node, int element){
    
    // jesli dany wezel jest pusty
    // to utworzyc nowy 
    if (node == NULL) 
        return(newNode(element)); 

    // jesli element ktory chcemy wstawic jest
    // mniejszy od aktualnie rozpatrywanego
    // wezla to rekurencyjnie przechdzimy 
    // drzewo po lewych galeziach
    if (element < node->element) 
        node->left = insert(node->left, element); 
    
    // jesli element jest wiekszy to 
    // idziemy w prawo 
    else if (element > node->element) 
        node->right = insert(node->right, element); 

    // nie mozna dodac elementu o tej samej 
    // wartosci w drzewie BST, wiec zwracamy po 
    // prostu podany wezel
    else 
        return node; 

    // aktualizujemy wysokosc danego
    // wezla
    updateHeight(node);


    int balance = getBalanceFactor(node); 


    // Balansowanie drzewa

    // Left Left Case 
    if (balance > 1 && element < node->left->element) 
        return right_rotation(node); 

    // Right Right Case 
    if (balance < -1 && element > node->right->element) 
        {
            return left_rotation(node); 
        }
    // Left Right Case 
    if (balance > 1 && element > node->left->element) 
    {   
        node->left = left_rotation(node->left); 
        return right_rotation(node); 
    } 

    // Right Left Case 
    if (balance < -1 && element < node->right->element) 
    { 
        node->right = right_rotation(node->right); 
        return left_rotation(node); 
    } 

    // zwracamy niezmieniony wskaznik
    return node; 
}
// najpierw odwiedzamy lewe poddrzewo, korzen 
// i odpiero prawe
void AVLTree::printTreeInOrder(Node* tree){
    if (tree == NULL)
      return;
      printTreeInOrder(tree->left);
      std::cout << tree->element << " ";
      printTreeInOrder(tree->right);
} 

// przejscie zaczynajac od korzenia
// a nastepnie po kolei wszystkie elementy
// idac w lewo, wracajac do poprzedniego i 
// dopiero w prawo
void AVLTree::printTreePreOrder(Node* tree){
    if (tree == NULL)
      return;
      std::cout << tree->element << " ";
      printTreePreOrder(tree->left);
      printTreePreOrder(tree->right);
} 
// najpierw przechodzimy lewe poddrzewo, pozniej prawe
// a na samym koncu korzen
void AVLTree::printTreePostOrder(Node* tree){
    if (tree == NULL)
      return;
      printTreePostOrder(tree->left);
      printTreePostOrder(tree->right);
      std::cout << tree->element << " ";
} 

bool AVLTree::isEmpty(){
    return (root == nullptr);
}

//zwraca WSKAZNIK najmniejszego elementu
Node* AVLTree::findMin(Node *t) const{
    Node* current = t;

    // z racji ze to jest drzewo BTS to 
    // najmniejsza wartosc znajdziemy w 
    // najnizszej galezi po lewej
    while (current->left != nullptr){
        current = current->left;
    }
    return current;
}

//zwraca WSKAZNIK najwiekszego elementu
Node* AVLTree::findMax(Node *t) const{
    Node* current = t;

    
    // z racji ze to jest drzewo BTS to 
    // najwieksza wartosc znajdziemy w 
    // najnizszej galezi po prawej
    while (current->right != nullptr){
        current = current->right;
    }
    return current;
}

//zwraca WARTOSC najmniejszego elementu
const int & AVLTree::findMin() const {
    return findMin(root)->element;
}
//zwraca WARTOSC najwiekszego elementu
const int & AVLTree::findMax() const{
    return findMax(root)->element;
}

// sprawdza, czy element o podanej wartosci wystepuje w poddrzewie
// o korzeniu w wezle podanym przez wskaznik t
bool AVLTree::contains(const int& element, Node* node) const{
    // jeśli podany Node jest pusty
    if (node == nullptr){
        return false;

    // jeśli znaleźliśmy element 
    } else if (node->element == element) {
        return true;

    // jeśli element jest mniejszy od aktualnie
    // rozpatrywanego, idź na lewo w poszukiwaniu mniejszego
    } else if (node->element > element)  {
        return contains(element, node->left);

    // jeśli element jest większy lub równy od aktualnie
    // rozpatrywanego, idź na prawo w poszukiwaniu większego
    } else {
        return contains(element, node->right);
    }
}

bool AVLTree::contains(const int& element) const{
    return contains(element, root);
}

// znajdowanie elementu w drzewie i zwracanie do niego wskaznika
Node* AVLTree::findElement(const int& element, Node* node){
    // jeśli podany Node jest pusty
    if (node == nullptr){
        return nullptr;

    // jeśli znaleźliśmy element 
    } else if (node->element == element) {
        return node;

    // jeśli element jest mniejszy od aktualnie
    // rozpatrywanego, idź na lewo w poszukiwaniu mniejszego
    } else if (node->element > element)  {
        return findElement(element, node->left);

    // jeśli element jest większy lub równy od aktualnie
    // rozpatrywanego, idź na prawo w poszukiwaniu większego
    } else {
        return findElement(element, node->right);
    }
}


Node* AVLTree::remove(int element, Node* node){

        if (node == NULL) // jesli node jest pusty 
            return node;  // to nie ma czego usuwać

        // szukamy rekurencyjnie elementu w drzewie

        // jesli element jest mniejszy to idziemy na lewo
        if ( element < node->element ) 
            node->left = remove(element, node->left); 

        // jesli element jest mniejszy to idziemy na lewo
        else if( element > node->element ) 
            node->right = remove(element, node->right); 

        // jesli element jest rowny temu w wezle
        // to znaczy ze to jest wezel do usuniecia
        else
        { 
            // przypadek gdzie mamy jedno lub zero dzieci 
            if( (node->left == NULL) ||
                (node->right == NULL) ) 
            { 
                // sprawdzamy czy jest lewe dziecko
                // jesli jest to przypisujemy do temp
                // jesli nie ma to przypisujemy prawe
                Node *temp = node->left ? 
                            node->left : 
                            node->right; 

                // jesli nie ma dziecka 
                if (temp == NULL) 
                { 
                    temp = node; 
                    node = NULL; 
                } 
                // jesli jest jedno dziecko
                else 
                *node = *temp; // przepisujemy cala zawartosc
                               // dziecka

                free(temp);    // i zwalniamy pamiec
            } 
            else
            { 
                // przypadek gdzie mamy dwójkę dzieci
              
                // szukamy najmniejszego elementu w
                // prawym podrzewie podanego wezła  
                Node* temp = findMin(node->right); 

                // przepisujemy jego wartość do elementu
                node->element = temp->element; 

                // usuwamy rekurencyjnie 
                node->right = remove(temp->element, node->right); 
            } 
        } 

        if (node == NULL) 
        return node; 

        updateHeight(node);

        int balance = getBalanceFactor(node);

        if (balance > 1 &&
            getBalanceFactor(node->left) >= 0)
            return right_rotation(node);
    
        // Left Right Case
        if (balance > 1 &&
            getBalanceFactor(node->left) < 0)
        {
            node->left = left_rotation(node->left);
            return right_rotation(node);
        }
    
        // Right Right Case
        if (balance < -1 &&
            getBalanceFactor(node->right) <= 0)
            return left_rotation(node);
    
        // Right Left Case
        if (balance < -1 &&
            getBalanceFactor(node->right) > 0)
        {
            node->right = right_rotation(node->right);
            return left_rotation(node);
        }
    
    return node;
    
    

}

