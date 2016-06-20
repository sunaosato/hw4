#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;
#define SIZE 20


ifstream fin("homework4/small_data.txt");

typedef struct value{
  string name;
  // char neighbar[SIZE];
  vector<value> neighbar;
  double score ;
  double pro_score ;
}value;

int insert_map(int vertex_num){
  //  map<std::string, value> pagerank_Map;
  string num,name,edge_from,edge_to;
  int edge_num;
  value val[SIZE];
 
  for(int i=0;i < vertex_num;i++){
    getline(fin,name);
    val[i].name = name;
  }

  getline(fin,num);
  edge_num = atoi(num.c_str());
   cout << edge_num<<endl;
  for(int j=0;j< edge_num;j++){
      
    getline(fin,edge_from,' ');
    cout<<"From:"<<edge_from<<endl;

    
    getline(fin,edge_to);
    cout<<"To:"<<edge_to<<endl;
    
    /*   for(int k=0;k< vertex_num;k++){

      
	 }*/
  }
     
  return 0;
}

int main(){

  int vertex_num;
  string str;

 if(!fin){
    cout << "Fail to open file.\n";
    return -1;
  }

 getline(fin,str);
 vertex_num = atoi(str.c_str());
 
 cout << vertex_num<<endl;

 insert_map(vertex_num);

 fin.close();

  return 0;

}

