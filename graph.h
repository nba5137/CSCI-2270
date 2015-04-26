#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>

#define  IN
#define OUT
#define INOUT
using namespace std;

// we worked together on the first part like struct.

// I worked on int getVertexIndex(IN const vertexNametype vertexName);
//             int getVertexNumber();
//             vertexNametype getData(IN int index);

template <typename weight>
struct Edge 
{
    int nDestVertex;//the start vertex
    weight edgeWeight;
    Edge<weight> *pNextEdge;//all edges of the start vertex

    Edge(int d, weight c, Edge<weight> *p = NULL)
        :nDestVertex(d), edgeWeight(c), pNextEdge(p)
    {}
};

template <typename vertexNametype, typename weight>
struct Vertex
{
    vertexNametype vertexName;
    Edge<weight> *pAdjEdges;

    Vertex(vertexNametype x, Edge<weight> *p = NULL)
        :vertexName(x), pAdjEdges(p)
    {}
};

//adjacency list based graph
template <typename vertexNametype, typename weight>
class ALGraph
{
public:
    explicit ALGraph();
    ~ALGraph();
    //plug vertex into graph
    bool insertAVertex(IN const vertexNametype vertexName);
	//plug an edge
    bool insertAEdge(IN const vertexNametype vertexName1, IN const vertexNametype vertexName2, IN const weight edgeWeight);
	//delete an edge
    bool removeAEdge(IN const vertexNametype vertexName1, IN const vertexNametype vertexName2, IN const weight edgeWeight);
	//gert index of vertex
    int getVertexIndex(IN const vertexNametype vertexName);
	//get number of vertex
    int getVertexNumber();
	//get the vertex of index
    vertexNametype getData(IN int index);
	//get the all edges of the start vertex
	bool showRelate(IN const vertexNametype vertexName, vector<vertexNametype>& ret);
	//output the whole graph
    friend ostream& operator<<(OUT ostream &out, IN const ALGraph<vertexNametype,weight> &graphInstance);   

public:
	//store all vertex
    vector<Vertex<vertexNametype, weight> > m_vertexArray;
};

template<typename vertexNametype, typename weight>
ALGraph<vertexNametype, weight>::ALGraph()
{
    if (!m_vertexArray.empty())
    {
        m_vertexArray.clear();
    }
    
}

template<typename vertexNametype, typename weight>
ALGraph<vertexNametype, weight>::~ALGraph()
{
    vector< Vertex<vertexNametype, weight> >::iterator iter;
	//to all vertex through graph
    for(iter = m_vertexArray.begin(); iter != m_vertexArray.end(); iter++)
    {
		//delete all edges
        Edge<weight> *p = iter->pAdjEdges;
        while(NULL != p)
        {
            iter->pAdjEdges = p->pNextEdge;
            delete p;
            p = iter->pAdjEdges;
        }
    }
	//clear vector
    if (!m_vertexArray.empty())
    {
        m_vertexArray.clear();
    }
}

template<typename vertexNametype, typename weight>
bool ALGraph<vertexNametype, weight>::insertAVertex(IN const vertexNametype vertexName)
{
    Vertex<vertexNametype, weight> VertexInstance(vertexName, NULL);
	//put vertex to vector
    m_vertexArray.push_back(VertexInstance);

    return true;
}

template<typename vertexNametype, typename weight>
bool ALGraph<vertexNametype, weight>::insertAEdge(IN const vertexNametype vertexName1, 
                            IN const vertexNametype vertexName2, IN const weight edgeWeight)
{
	//the first, next vertex
    int v1 = getVertexIndex(vertexName1);
    if (-1 == v1)
    {
        cerr << "There is no movie" << endl;
        return false;
    }
	//the second, next vertex
    int v2 = getVertexIndex(vertexName2);
    if (-1 == v2)
    {
        cerr << "There is no movie" << endl;
        return false;
    }
	//create edge
    Edge<weight> *p = m_vertexArray.at(v1).pAdjEdges;
    while(p != NULL && p->nDestVertex != v2)
    {
        p = p->pNextEdge;
    }

    if (NULL == p)
    {
        p = new Edge<weight>(v2, edgeWeight, m_vertexArray.at(v1).pAdjEdges);
        m_vertexArray.at(v1).pAdjEdges = p;
        return true;
    }
    if (v2 == p->nDestVertex)
    {
        Edge<weight> *q = p;
        p = new Edge<weight>( v2, edgeWeight, q->pNextEdge );
        q->pNextEdge = p;
        return true;
    }
    
    return false;
}

template<typename vertexNametype, typename weight>
bool ALGraph<vertexNametype, weight>::removeAEdge(IN const vertexNametype vertexName1, 
                                          IN const vertexNametype vertexName2, IN const weight edgeWeight)
{
	//the first, next vertex
    int v1 = getVertexIndex(vertexName1);
    if (-1 == v1)
    {
        cerr << "There is no movie" << endl;
        return false;
    }
	//the second, next vertex
    int v2 = getVertexIndex(vertexName2);
    if (-1 == v2)
    {
        cerr << "There is no movie" << endl;
        return false;
    }

	//delete edge 
    Edge<weight> *p = m_vertexArray.at(v1).pAdjEdges;
    Edge<weight> *q = NULL;
    while(p != NULL && p->nDestVertex != v2 )
    {
        q = p;
        p = p->pNextEdge;
    }
    if (NULL == p)
    {
        cerr << "Edge is not found" << endl;
        return false;
    }
    while( edgeWeight != p->edgeWeight && p->nDestVertex == v2)
    {
        q = p;
        p = p->pNextEdge;
    }
    if (v2 != p->nDestVertex)
    {
        cerr << "Edge is not found" << endl;
        return false;
    }
    q->pNextEdge = p->pNextEdge;
    delete p;

    return true;
}

template<typename vertexNametype, typename weight>
bool ALGraph<vertexNametype, weight>::showRelate(IN const vertexNametype vertexName, vector<vertexNametype>& ret){
	
	//the next vertex
	int i = getVertexIndex(vertexName);
    if (-1 == i)
    {
        return false;
    }
	else
	{
		ret.clear();
        Edge<weight> *p = m_vertexArray.at(i).pAdjEdges;
		//get the edge of current vertex and put in vector
		while (NULL != p)
		{
			ret.push_back(getData(p->nDestVertex));
			p = p->pNextEdge;
		}
		return true;
	}
}

template<typename vertexNametype, typename weight>
int ALGraph<vertexNametype, weight>::getVertexIndex(IN const vertexNametype vertexName)
{
	//to get the next vertex
    for (int i = 0; i <(int) m_vertexArray.size(); i++)
    {
        if (vertexName == getData(i))
        {
            return i;
        }
    }
    return -1;
}

template<typename vertexNametype, typename weight>
int ALGraph<vertexNametype, weight>::getVertexNumber()
{
    return m_vertexArray.size();
}

template<typename vertexNametype, typename weight>
vertexNametype ALGraph<vertexNametype, weight>::getData(IN int index)
{
    return m_vertexArray.at(index).vertexName;
}

template<typename vertexNametype, typename weight>   
ostream& operator<<(OUT ostream &out, IN  ALGraph<vertexNametype,weight> &graphInstance)
{
    int vertexNo = graphInstance.getVertexNumber();
	//to edges of all vertex through graph
    for(int i = 0; i < vertexNo; i++)
    {
		//if not yet, don't out put
		if(graphInstance.m_vertexArray.at(i).pAdjEdges == NULL){
			continue;
		}
        vertexNametype x1 = graphInstance.getData(i);
        out << x1 << ":  " << endl;
		//after all, output
        Edge<weight> *p = graphInstance.m_vertexArray.at(i).pAdjEdges;
        while (NULL != p)
        {
            out << "(" << x1 << "," << graphInstance.getData(p->nDestVertex) << "," << p->edgeWeight << ")  " << endl;
            p = p->pNextEdge;
        }
        out << endl;
    }
    return out;
}


#endif
