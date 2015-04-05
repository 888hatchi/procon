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
