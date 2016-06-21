#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;
#define SIZE 1000

//value val[SIZE];


ifstream fin("homework4/medium_data.txt");

class value{
public:
  string name;
  // char neighbar[SIZE];
  vector<value*> neighbar;
  double score ;
  double pro_score ;
};

int search(string name,int vertex_num,value *val){
  int num = 0;
  while(num < vertex_num ){
    if(name == val[num].name){
      break;
    }else{
      num++;
    }
  }
  return num;
}

void insert(int vertex_num,value *val){
  //  map<std::string, value> pagerank_Map;
  string num,name,edge_from,edge_to;
  int total_edge;

 
  for(int i=0;i < vertex_num;i++){
    getline(fin,name);
    val[i].name = name;
    val[i].score = 100.0;
    val[i].pro_score = 0.0;
  }
 
  getline(fin,num);
  total_edge = atoi(num.c_str());
  // cout << total_edge<<endl;

  for(int j=0;j< total_edge;j++){
    
    getline(fin,edge_from,' ');
    //  cout<<"From:"<<edge_from<<endl;

    getline(fin,edge_to);
    // cout<<"To:"<<edge_to<<endl;

    int from = 0,to = 0;
    from = search(edge_from,vertex_num,val);
    to = search(edge_to,vertex_num,val);
    
    val[from].neighbar.push_back(&val[to]);
  }
}
 



void pagerank(value* val,int vertex_num){

  for (int i=0;i< vertex_num;i++){
    int neighbar_num = val[i].neighbar.size();
    int share = val[i].score/neighbar_num;
    // cout<<val[i].neighbar.size()<<","<<share<<endl;
    
    for(int j =0;j < neighbar_num;j++){
      val[i].neighbar[j]->pro_score += share;
    }
  }

   int total=0;
    for(int l=0;l< vertex_num;l++){
     

    val[l].score = val[l].pro_score;
    total += val[l].score;
    val[l].pro_score =0.0;
    cout<<val[l].name<<"'s score:"<<val[l].score<<endl;
    }
    cout<<"total:"<<total<<endl;
    cout<<"true value:"<<vertex_num*100.0<<endl;
    
}




int main(){

  value val[SIZE];
  int vertex_num;
  string str;

 if(!fin){
    cout << "Fail to open file.\n";
    return -1;
  }

 getline(fin,str);
 vertex_num = atoi(str.c_str());
 
  cout << vertex_num<<endl;

  insert(vertex_num,val);

  for(int i=0;i < 3;i++){
   cout<<i+1<<"回目"<<endl;
 pagerank(val,vertex_num);
 }

 fin.close();

  return 0;

}
