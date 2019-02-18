#include <iostream>
#include <vector>
#include <cstdio> 
#include <cstdlib> 
#define MAXN 100
using namespace std;

struct ArcNode {//边结点 
    int adjvex; //有向边的另一个邻接点的序号
    ArcNode *nextarc;
};
struct VNode { //顶点 
    int data; //顶点信息
    ArcNode* headout;    //出边表的表头指针 
    ArcNode* headin;     //入边表的表头指针
};
struct LGraph {//图的邻接表存储结构 
    VNode vertexs[MAXN];//顶点数组
    int vexnum;
    int arcnum; //顶点数和边数 
};
LGraph lg; //图(邻接表存储)

void createLG(int v, vector<pair<int,int>> e) {
    lg.vexnum = v;
    lg.arcnum = e.size();
    for(int i = 0; i < lg.vexnum; i++) {
        lg.vertexs[i].headin = NULL;
        lg.vertexs[i].headout = NULL;
    }

    for(int i = 0; i < lg.arcnum; i++) {
        ArcNode* pi = new ArcNode();
        int start = e[i].first - 1;
        int end = e[i].second - 1;
        pi -> adjvex = end;
        pi -> nextarc = lg.vertexs[start].headout;
        lg.vertexs[start].headout = pi;

        pi = new ArcNode();
        pi -> adjvex = start;
        pi -> nextarc = lg.vertexs[end].headin;
        lg.vertexs[end].headin = pi;
    }
}

void deteleLG() {
    ArcNode* pi;
    for(int i = 0; i < lg.vexnum; i++) {
        pi = lg.vertexs[i].headin;
        while(pi != NULL) {
            lg.vertexs[i].headin = pi -> nextarc;
            delete pi;
            pi = lg.vertexs[i].headin; 
        }

        pi = lg.vertexs[i].headout;
        while(pi != NULL) {
            lg.vertexs[i].headout = pi -> nextarc;
            delete pi;
            pi = lg.vertexs[i].headout; 
        }
    }
}

int main() {
    
    int numv;
    int nume;
    
    while(1) {
        int id = 0;
        int od = 0;
        cin >> numv >> nume;
        if(!numv) {
            break;
        }
        vector<pair<int, int>> e(nume, {-1, -1});
        for(int i = 0; i < nume; i++) {
            cin >> e[i].first >> e[i].second;
        }
        createLG(numv, e);
        for(int i = 0; i < lg.vexnum; i++) {
            ArcNode* pi;
            pi = lg.vertexs[i].headout;
            while(pi != NULL) {
                od++;
                pi = pi -> nextarc;
            }
            if(i) {
                cout << " " << od;
            }
            else {
                cout << od;
            }
            od = 0;
        }
        cout << endl;

        for(int i = 0; i < lg.vexnum; i++) {
            ArcNode* pi;
            pi = lg.vertexs[i].headin;
            while(pi != NULL) {
                id++;
                pi = pi -> nextarc;
            }
            if(i) {
                cout << " " << id;
            }
            else {
                cout << id;
            }
            id = 0;
        }
        cout << endl;
        deteleLG();
    }
    return 0;
}