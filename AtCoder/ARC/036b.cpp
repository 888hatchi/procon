//次のコンテスト用に〜！
//pythonでの入力
//m, d = map(int, raw_input().split())

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, tmp, s, t, u, tmph=0, max = 0, i;
    int flag = 1;
    cin >> n;
    for(i=1; i<=n; i++){
        cin >> tmp;
        if(i == 1){ s = i; t = tmp; u = i; continue; }

        if(flag > 0){
            if(t < tmp){ t = tmp; u = i;}
            else{ flag = -1; u = i; t = tmp; continue; }
        }else{
            if(t > tmp){ t = tmp; u = i; }
            else{
                tmph = u - s + 1;
                if(max < tmph) max = tmph;
                flag = 1;
                s = i - 1, t = tmp, u = i;
            }
        }
    }
    
    tmph = u - s + 1;
    if(max < tmph) max = tmph;
    
    cout << max << endl;
}

//const int MAXN = 200;
//
//typedef struct node{
//    const char* name;
//    int depth;
//    struct node* child;
//    struct node* next;
//} node_t;
//
//void append(const char* name, node_t* parent, node_t* node){
//    node->name = name;
//    node->depth = 0;
//    node->child = NULL;
//    node->next = NULL;
//    if(parent == NULL) return;
//    node->depth = parent->depth + 1;
//    if(parent->child == NULL){ parent->child = node; }
//    else{
//        node_t* last = parent->child;
//        while(last->next != NULL){
//            last = last->next;
//        }
//        last->next = node;
//    }
//}
//
//node_t* search(const char* name, node_t* node){
//    if(node->name != name){
//        search(name, node->child);
//        search(name, node->next);
//        return NULL;
//    }else return node;
//}
//
//struct input{
//    int m;
//    string large, small;
//    
//    //構造体の内部に演算子オーバーロードで比較関数を定義する
//    bool operator<(const input& another) const {
//        return m > another.m;
//    }
//};
//
//
//int main(){
//    int n;
//    cin >> n;
//    string lar, sml;
//    int m;
//    node_t data, tmp;
//    append(NULL, NULL, NULL);
//    for(int i=0; i<n; i++){
//        cin >> lar >> m >> sml;
//        tmp.name = sml.c_str();
//        tmp.depth = m;
//        node_t* pl = search(lar.c_str(), &data);
//        if(pl == NULL) append(lar.c_str(), &data, &tmp);
//        else append(sml.c_str(), pl, &tmp);
//    }
//    
//    
//    vector<input> inp(MAXN);
//    for(int i=0; i<n; i++){
//        cin >> inp[i].large >> inp[i].m >> inp[i].small;
//    }
//    //降順に並べる
//    sort(inp.begin(), inp.end());
//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            if(inp[i].large == inp[j].small){
//                inp[j].small = inp[i].small;
//                inp[j].m *= inp[i].m;
//            }
//        }
//    }
//    int max = 0, tmp;
//    for(int i=0; i<n; i++){
//        if(inp[i].m > max){ tmp = i; max = inp[i].m; }
//        //cout << inp[i].large << ' ' << inp[i].m << ' ' << inp[i].small << endl;
//    }
//    
//    cout << '1' << inp[tmp].large << '=' << max << inp[tmp].small << endl;
//    return 0;
//}
//
