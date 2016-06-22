#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <iomanip>
#include <stdlib.h>

using namespace std;
#define SIZE 1000

ifstream fin("homework4/large_data.txt");

class value{
public:
  string name;
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

void  insert_name_and_score(value* val,int vertex_num){
  string name;
  
  for(int i=0;i < vertex_num;i++){
    getline(fin,name);
    val[i].name = name;
    val[i].score = 100.0;
    val[i].pro_score = 0.0;
  }
}

void insert_neighbar(value* val,int vertex_num){
  string num,edge_from,edge_to;
  int total_edge;

  getline(fin,num);
  total_edge = atoi(num.c_str());

  for(int j=0;j< total_edge;j++){
    
    getline(fin,edge_from,' ');
    getline(fin,edge_to);

    int from = 0,to = 0;
    from = search(edge_from,vertex_num,val);
    to = search(edge_to,vertex_num,val);
    
    val[from].neighbar.push_back(&val[to]);
  }

}

void insert(int vertex_num,value *val){

  insert_name_and_score(val,vertex_num);
  insert_neighbar(val,vertex_num);
}

 


void culculate_pro_score(value* val,int vertex_num){

  for (int i=0;i< vertex_num;i++){
    int neighbar_num = val[i].neighbar.size();
    double share = val[i].score*1.0/neighbar_num;
    
    for(int j =0;j < neighbar_num;j++){
      val[i].neighbar[j]->pro_score += share;
    }
  }


}

void  update_score(value* val,int vertex_num){
  //   int total=0;

   for(int l=0;l< vertex_num;l++){
     val[l].score = val[l].pro_score;
     //      total += val[l].score;
     val[l].pro_score =0.0;
     cout<<val[l].name<<"'s score:"<< fixed << setprecision(1)<<val[l].score<<endl;
   }
   // cout<<"total:"<< fixed << setprecision(2)<<total<<endl;
   // cout<<"true value:"<<vertex_num*100.0<<endl;


}


void pagerank(value* val,int vertex_num){

  culculate_pro_score(val,vertex_num);
  update_score(val,vertex_num);
    
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
 
  //  cout << vertex_num<<endl;

  insert(vertex_num,val);

  for(int i=0;i < 1;i++){
   cout<<i+1<<"回目"<<endl;
   pagerank(val,vertex_num);
  }

 fin.close();

  return 0;

}
