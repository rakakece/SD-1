#include<bits/stdc++.h>
using namespace std;
 
struct edge{
  	//src : source
  	//des : destination
  	int src,des, weight;
    // edge = {0, 1, 5} vertex awal, vertex tujuan, bobot
};
 
edge createEdge(int src,int des, int weight){
  	//buat edge baru
  	edge temp;
  	temp.src = src;
  	temp.des = des;
  	temp.weight = weight;
  	return temp;
}
 
void bellmanFord(vector<edge> e, int nV, int source){
    int distance[nV];
    // inisialisasi array jarak dengan tak hingga

    for(int i = 0; i < nV; i++){
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    // ulang langkah sampai n-1
    for(int i = 0; i < nV-1; i++){
        // iterasi setiap edge
        for(int j = 0; j < e.size(); j++){
            int src = e[j].src;
            int des = e[j].des;

            // skip jika source belum ada nilai distancenya
            if(distance[src] == INT_MAX) continue;

            // update distance kalau ketemu sama yang lebih kecil
            if(distance[src] + e[j].weight < distance[des]){
                distance[des] = distance[src] + e[j].weight;
            }
        }
    }

	
	//print
	cout<<"Jarak terdekat dari vertex "<<source<<endl;
	for (int i=0;i<nV;i++)
	{
		if (i==source) continue;
		cout<<i<<" : "<<distance[i]<<endl;
	}
}

int main() 
{ 
	int nV = 5;
	edge temp;
    vector<edge> e;
    e.push_back(createEdge(0,1,5));
    e.push_back(createEdge(0,3,3));
    e.push_back(createEdge(1,2,2));
    e.push_back(createEdge(1,4,15));
    e.push_back(createEdge(3,0,1));
    e.push_back(createEdge(3,1,1));
    e.push_back(createEdge(4,4,3));
    bellmanFord(e,nV,0);
    return 0; 
}