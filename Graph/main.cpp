#include <iostream>
#include <string>
#include <vector>

int unique_number = 0;
class Vertex
{
        int number = unique_number;
    public:
        int weight;
        std::string label;
        Vertex(int n) : weight(n) {
            unique_number++;
        };
        int Number() const {
            return number;
        };
}; 

template <typename T>
class Iterator
{
public:
    virtual ~Iterator (){};
    Iterator(){};
    virtual bool IsDone () = 0;
    virtual T & operator * () = 0;
    virtual void operator ++ () = 0;
}; 


class Edge
{
    protected:
        Vertex* v0;
        Vertex* v1;
    public:
        int weight = 0;
        std::string label;
        Edge (Vertex *V0, Vertex* V1) : v0(V0), v1(V1){
            weight++;
        };
        Vertex* V0 (){return v0;};
        Vertex* V1 (){return v1;};
        Vertex* Mate (Vertex *v){
            if (v == v0) return v1;
            else return v0;
        };
}; 

class GraphAsMatrix
{
    std::vector<Vertex *> vertices;
    std::vector< std::vector<Edge *> > adjacencyMatrix;
    bool isDirected;
    int numberOfVertices;
    int numberOfEdges=0;


    public:
        GraphAsMatrix (int n, bool b)
        {
            isDirected = b;
            numberOfVertices = n;
            for(int i=0; i<numberOfVertices; i++)
            {
                vertices.push_back(new Vertex(i));
            }
            std::vector< std::vector<Edge *> > tmp_matrix(numberOfVertices, std::vector<Edge *>( numberOfVertices, nullptr));
            adjacencyMatrix = tmp_matrix;

        }
        int NumberOfVertices() {return numberOfVertices;}
        bool IsDirected() { return isDirected; }
        void SetDirected(bool value) {
            isDirected = value;
            }
        int NumberOfEdges() { return numberOfEdges; }
        bool IsEdge(int u, int v){
            if (adjacencyMatrix[u][v] != nullptr){
                return true;
            }
            return false;
        }

        void print_matrix(){
            for(int i = 0; i <numberOfVertices; i++){
                for(int j = 0; j <numberOfVertices; j++){
                    std::cout<<adjacencyMatrix[i][j]<< " ";
                }
                std::cout<<std::endl;
            }
        }
        
        void MakeNull(){
            for (std::vector<Edge *> v : adjacencyMatrix){
                for(Edge* e: v){
                    delete e;
                }
                v.clear();

            }
            numberOfEdges = 0;
        }
        void AddEdge (int u, int v){
            if( adjacencyMatrix[u][v] != nullptr ){
                std::cout<<"Adding edge ("<<u <<", "<< v<<"): Edge already exists"<<std::endl;
            } else {
                if(isDirected == false){
                    adjacencyMatrix[u][v] = new Edge( vertices[u], vertices[v]);
                    adjacencyMatrix[v][u] = new Edge( vertices[v], vertices[u]);
                    std::cout<<"Adding edge ("<<u <<", "<< v<<"): Succes"<<std::endl;
                    std::cout<<"Adding edge ("<<v <<", "<< u<<"): Succes"<<std::endl;
                    

                } else {
                    adjacencyMatrix[u][v] = new Edge( vertices[u], vertices[v] );
                    std::cout<<"Adding edge ("<<u <<", "<< v<<"): Succes"<<std::endl;
                }
                numberOfEdges++;
            }
        }
        void AddEdge (Edge* edge){
            Vertex* vertex0 = edge->V0();
            Vertex* vertex1 = edge->V1();
            int zero =  vertex0->Number();
            int one =  vertex1->Number();
            if( adjacencyMatrix[zero][one] != nullptr ){
                std::cout<<"Adding edge Error: Edge already exists"<<std::endl;
            } else {
                if(isDirected == false){
                    adjacencyMatrix[zero][one] = edge;
                    adjacencyMatrix[one][zero] = new Edge( vertices[one], vertices[zero]);
                    
                    
                } else {
                    adjacencyMatrix[zero][one] = edge;
                }
                numberOfEdges++;
            }
        }
        Edge * SelectEdge (int u, int v){
            return adjacencyMatrix[u][v];
        }
        Vertex * SelectVertex(int v){
            return vertices[v];
        }



    class AllVerticesIter: public Iterator<Vertex>{
        GraphAsMatrix & owner;
        int current;
    public:
        // int numb_of_ver = owner.NumberOfVertices();
        std::vector<Vertex *> data;
        AllVerticesIter(GraphAsMatrix &owner) : owner{owner}, current{0}{ 

            for(int i = 0; i < owner.NumberOfVertices(); i++){
                data.push_back(owner.SelectVertex(i));
            }
        }
        bool IsDone(){
            return current == data.size();
        }
        Vertex & operator*(){
            return (*data[current]);
        }
        void operator++(){
            current++;
        }
    };
    class AllEdgesIter: public Iterator<Edge>{
        GraphAsMatrix & owner;
        int row;
        int col;
        public:
            void next(){ 
                bool condition = false;
                if (row != 0 && col != 0) col++;
                if (row == (owner.NumberOfVertices() - 1) && (col >= owner.NumberOfVertices() - 1) ){
                    row = owner.NumberOfVertices();
                    col = owner.NumberOfVertices();
                }

                for (int i = row; i < owner.NumberOfVertices(); i++){
                    if (condition) break;
                    for (int j = col; j < owner.NumberOfVertices(); j++){
                        if (owner.adjacencyMatrix[i][j] != nullptr) {

                            row = i;
                            col = j;
                            condition = true;
                            break;
                        }
                        if(j == owner.NumberOfVertices() - 1){
                            col = 0;
                        }
                    }
                }
            }
            AllEdgesIter(GraphAsMatrix &owner) : row{0}, col{0} , owner{owner}{
                next();
                std::cout<<"Stworzono Iterator po wszystkich krawędziach!"<<std::endl;
            }
            bool IsDone(){
                return (row == owner.NumberOfVertices() && col == owner.NumberOfVertices());
            };
            Edge & operator*(){
                return (*owner.SelectEdge(row, col));
            }
            void operator++(){next();}
        };

    class EmanEdgesIter: public Iterator<Edge>
    {
        GraphAsMatrix & owner;
        int row;
        int col;
        public:
            void next(){ 
                    for (int i = col; i < owner.NumberOfVertices()-1; i++){
                        
                        if (owner.adjacencyMatrix[row][i+1] != nullptr) {
                                col = i+1;
                                break;
                            }
                        }
                    }
            EmanEdgesIter(GraphAsMatrix &owner, int v): owner{owner}, row{v}, col{0} {
                next();
                std::cout<<"Stworzono Iterator po krawędziach wychodzacych z "<< row <<std::endl;
            }
            bool IsDone(){
                    return (row == owner.NumberOfVertices() && col == owner.NumberOfVertices());
                };
                Edge & operator*(){
                    return (*owner.SelectEdge(row, col));
                }
            void operator++(){next();}
    };
    class InciEdgesIter: public Iterator<Edge>
    {
        GraphAsMatrix & owner;
        int row;
        int col;
        public:
        
            void next(){ 
                    for (int i = row; i < owner.NumberOfVertices()-1; i++){
                        
                        if (owner.adjacencyMatrix[i+1][col] != nullptr) {
                                row = i+1;
                                break;
                            }
                        }
                    }
            InciEdgesIter(GraphAsMatrix &owner, int v): owner{owner}, col{v}, row{0} {
                next();
                std::cout<<"Stworzono Iterator po krawędziach dochodzących do "<< col <<std::endl;
            }
            bool IsDone(){
                    return (row == owner.NumberOfVertices() && col == owner.NumberOfVertices());
                };
                Edge & operator*(){
                    return (*owner.SelectEdge(row, col));
                }
            void operator++(){next();}
    };

    Iterator<Vertex> & VerticesIterator(){
        return *(new AllVerticesIter(*this));
    }
    Iterator<Edge> & EdgesIterator(){
        return *(new AllEdgesIter(*this));
    }
    Iterator<Edge> & EmanEdgesIterator(int v){
        return *(new EmanEdgesIter(*this, v));
    }
    Iterator<Edge> & InciEdgesIterator(int v){
        return *(new InciEdgesIter(*this, v));
    }
};

int main(){

    int directed;
    bool type;
    
    std::cout<<"Wybierz rodzaj:"<<std::endl;
    std::cout<<"1. Skierowany"<<std::endl;
    std::cout<<"2. Nieskierowany"<<std::endl;
    std::cin >> directed;

    if (directed == 1){ 
        type = true;
        std::cout<<"-----------------------------SKIEROWANY-----------------------------"<<std::endl;
    } else if (directed == 2){
        type = false;
        std::cout<<"-----------------------------NIESKIEROWANY-----------------------------"<<std::endl;
    } else {
        std::cout<<"Niepoprawna opcja";
        exit(1);
    }


    GraphAsMatrix graph(10, type);
    std::cout<<"Amount of Verices: "<<graph.NumberOfVertices()<<std::endl;
    std::cout<<"Amount of Edges: "<<graph.NumberOfEdges()<<std::endl;
    
    Vertex* v = graph.SelectVertex(2);
    std::cout<<"V: "<<v->Number()<<std::endl;
    v->weight = v->Number() * v->Number();
    std::cout<<"V: "<<v->weight<<std::endl;


    graph.AddEdge(1,2);
    graph.AddEdge(1,2);
    graph.AddEdge(2,3);
    graph.AddEdge(3,4);
    graph.AddEdge(9,9);

    std::cout<<"Amount of Verices: "<<graph.NumberOfVertices()<<std::endl;
    std::cout<<"Amount of Edges: "<<graph.NumberOfEdges()<<std::endl;
    
    std::cout<<"Is exists (1, 1): "<<(graph.IsEdge(1, 1) ? "True": "False")<<std::endl;
    std::cout<<"Is exists (1, 2): "<<(graph.IsEdge(1, 2) ? "True": "False")<<std::endl;
    std::cout<<"Is exists (2, 1): "<<(graph.IsEdge(2, 1) ? "True": "False")<<std::endl;
    
    Edge* e = graph.SelectEdge(1, 2);
    std::cout<<"Selected Vertice ("<<1<<", "<<2<<")"<<std::endl;
    std::cout<<"V0 e: "<<e->V0() << " |Number: " << e->V0()->Number() <<" | Weight: "<< e->V0()->weight << std::endl;
    std::cout<<"V1 e: "<<e->V1() << " |Number: " << e->V1()->Number() <<" | Weight: "<< e->V1()->weight <<std::endl;
    std::cout<<"Mate V0 e: "<<e->Mate(e->V0())<< " : " << e->Mate(e->V0())->Number() <<std::endl;
    std::cout<<"Mate V1 e: "<<e->Mate(e->V1())<< " : " << e->Mate(e->V1())->Number() <<std::endl;

    e->weight = e->V0()->weight + e->V1()->weight;
    std::cout<<"Weight e: "<<e->weight<<std::endl;

    Edge* e1 = graph.SelectEdge(2, 3);
    std::cout<<"Selected Vertice ("<<2<<", "<<3<<")"<<std::endl;
    std::cout<<"V0 e: "<<e1->V0() << " |Number: " << e1->V0()->Number() <<" | Weight: "<< e1->V0()->weight << std::endl;
    std::cout<<"V1 e: "<<e1->V1() << " |Number: " << e1->V1()->Number() <<" | Weight: "<< e1->V1()->weight <<std::endl;
    std::cout<<"Mate V0 e: "<<e1->Mate(e->V0())<< " : " << e1->Mate(e1->V0())->Number() <<std::endl;
    std::cout<<"Mate V1 e: "<<e1->Mate(e->V1())<< " : " << e1->Mate(e1->V1())->Number() <<std::endl;

    e1->weight = e1->V0()->weight + e1->V1()->weight;
    std::cout<<"Weight e: "<<e->weight<<std::endl;

    Edge *e2 = graph.SelectEdge(3, 4);
    std::cout<<"Selected Vertice ("<<3<<", "<<4<<")"<<std::endl;
    std::cout<<"V0 e: "<<e2->V0() << " |Number: " << e2->V0()->Number() <<" | Weight: "<< e2->V0()->weight << std::endl;
    std::cout<<"V1 e: "<<e2->V1() << " |Number: " << e2->V1()->Number() <<" | Weight: "<< e2->V1()->weight <<std::endl;
    std::cout<<"Mate V0 e: "<<e2->Mate(e2->V0())<< " : " << e2->Mate(e2->V0())->Number() <<std::endl;
    std::cout<<"Mate V1 e: "<<e2->Mate(e->V1())<< " : " << e2->Mate(e2->V1())->Number() <<std::endl;

    e2->weight = e2->V0()->weight + e2->V1()->weight;
    std::cout<<"Weight e: "<<e2->weight<<std::endl;

    Edge* e3 = graph.SelectEdge(9, 9);
    std::cout<<"Selected Vertice ("<<9<<", "<<9<<")"<<std::endl;
    std::cout<<"V0 e: "<<e3->V0() << " |Number: " << e3->V0()->Number() <<" | Weight: "<< e3->V0()->weight << std::endl;
    std::cout<<"V1 e: "<<e3->V1() << " |Number: " << e3->V1()->Number() <<" | Weight: "<< e3->V1()->weight <<std::endl;
    std::cout<<"Mate V0 e: "<<e3->Mate(e3->V0())<< " : " << e3->Mate(e3->V0())->Number() <<std::endl;
    std::cout<<"Mate V1 e: "<<e3->Mate(e3->V1())<< " : " << e3->Mate(e3->V1())->Number() <<std::endl;

    e3->weight = e3->V0()->weight + e3->V1()->weight;
    std::cout<<"Weight e: "<<e3->weight<<std::endl;

    GraphAsMatrix::AllVerticesIter AllVerticesIterator(graph);

    while(!AllVerticesIterator.IsDone()){
        std::cout<<"Number: "<<(*AllVerticesIterator).Number()<<std::endl;
        std::cout<<"Weight: "<<(*AllVerticesIterator).weight<<std::endl;
        ++AllVerticesIterator;
        std::cout<<std::endl;
    }

    
    graph.AddEdge(3,5);
    graph.AddEdge(8,3);
    graph.AddEdge(5,2);

    GraphAsMatrix::AllEdgesIter AllEdgesIterator(graph);

    
    while(!AllEdgesIterator.IsDone()){
        std::cout<<std::endl;
        std::cout<<"V0: "<<(*AllEdgesIterator).V0()->Number()<<std::endl;
        std::cout<<"V1: "<<(*AllEdgesIterator).V1()->Number()<<std::endl;
        ++AllEdgesIterator;
    }
    
    GraphAsMatrix::EmanEdgesIter EmanEdgesIterator(graph, 3);

     // krawedz (0,0) jest niemożliwa i numerujemy od 1 więc nigdy nie powstanie
    Edge tmp = *(new Edge(graph.SelectVertex(0), graph.SelectVertex(0)));
    Edge current = (*EmanEdgesIterator);
    while(!EmanEdgesIterator.IsDone()){
        std::cout<<std::endl;
        current = (*EmanEdgesIterator);

        if ( current.V1()->Number() == tmp.V1()->Number() ) break;
        std::cout<<"V0: "<<(*EmanEdgesIterator).V0()->Number()<<std::endl;
        std::cout<<"V1: "<<(*EmanEdgesIterator).V1()->Number()<<std::endl;
        tmp = (*EmanEdgesIterator);
        ++EmanEdgesIterator;
    }

    GraphAsMatrix::InciEdgesIter InciEdgesIterator(graph, 2);

     // krawedz (0,0) jest niemożliwa i numerujemy od 1 więc nigdy nie powstanie
    tmp = *(new Edge(graph.SelectVertex(0), graph.SelectVertex(0)));
    current = (*InciEdgesIterator);
    while(!InciEdgesIterator.IsDone()){
        std::cout<<std::endl;
        current = (*InciEdgesIterator);

        if ( current.V0()->Number() == tmp.V0()->Number() ) break;
        std::cout<<"V0: "<<(*InciEdgesIterator).V0()->Number()<<std::endl;
        std::cout<<"V1: "<<(*InciEdgesIterator).V1()->Number()<<std::endl;
        tmp = (*InciEdgesIterator);
        ++InciEdgesIterator;
    }

}