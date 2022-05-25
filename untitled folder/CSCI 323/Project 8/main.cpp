#include <iostream>
#include <fstream>
using namespace std;

class AStarNode {
public:
    /* gStar - # moves from initial state to current
       hStar - estimated distance from curr to goal node
       fStar - gStar + hStar
    */ 

    string config;
    int gStar, hStar, fStar;
    AStarNode * next;
    AStarNode * parent;

    AStarNode(string c){
        config = c;
        gStar = 0;
        hStar = 0;
        fStar = gStar + hStar;
        next = NULL;
        parent = NULL;
    }

    void printNode(){
        if(parent != NULL)
            cout << "<" << fStar << "::" << config << "::"
            << parent->fStar << "::" << parent->config 
            << ">";
        else
            cout << "<" << fStar << "::" << config 
            << "::NULL::NULL>";
    }
};

class AStar {
    AStarNode startNode, goalNode;
    AStarNode * open; //sort ll, ordered by fStar
    AStarNode * close; //unsort ll, processed nodes

    AStarNode * childList; //ll stack for expend node children
    
    int table[9][9]; 

    

};

int main(int argc, char ** argv){
    if(argc < 5){
        cout << "Not enough files!" << endl;
        return 1; 
    }

    ifstream infile1, infile2;
    ofstream outfile1, outfile2;

    infile1.open(argv[1]);
    infile2.open(argv[2]);
    outfile1.open(argv[3]);
    outfile2.open(argv[4]);

    string initialConfig, goalConfig;
    char temp;
    while(infile1 >> temp)
        initialConfig += temp;

    while(infile2 >> temp)
        goalConfig += temp;
    

    AStarNode h = * new AStarNode (goalConfig);
    h.printNode();


    return 0;
}