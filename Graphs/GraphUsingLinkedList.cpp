#include<bits/stdc++.h>
using namespace std;


class Graph{

    private:
        int V;  // This represents the number of Vertices in the graph
        list<int> *l;  // This is to create the array list of a list that will hold those nodes which has edges to the provided vertex. 

    public:

        // Constructor to create intialise the array list.
        Graph(int V){
            this->V = V;
            l = new list<int>[V];
        }    

        // This is create the edge between two vertices.
        void addEdge(int x, int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        
        // This function will print the graph.
        void printGraph(){
            for(int i=0; i<V; i++){
                cout<<"Vertex "<<i<<"->";
                for(int nbr: l[i]){
                    cout<<nbr<<", ";
                }
                cout<<endl;
            }
        }

};


int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,4);

    g.printGraph();

    return 0;
}
