#include <stdio.h>
#include <algorithm>
using namespace std;

char map[26][26];
int c=0,house[6250] = {10000,},a;
void input(){
    int i;
    scanf("%d",&a);
    for(i=0; i<a; i++){
        scanf("%s",map[i]);
    }
  //  printf("\n");

}
void sv2(int n,int m){
        map[n][m] = '0';
        if(map[n+1][m] == '1'){
            house[c]++;
            sv2(n+1,m);
        }
        if(map[n-1][m] == '1'){
            house[c]++;
            sv2(n-1,m);
        }
        if(map[n][m+1] == '1'){
            house[c]++;
            sv2(n,m+1);
        }
        if(map[n][m-1] == '1'){
            house[c]++;
            sv2(n,m-1);
        }
}

void solve(){
    int i,j;
    for(i=0; i<a; i++){
        for(j=0; j<a; j++){
        //        printf("%c",map[i][j]);

            if(map[i][j] == '1'){
                house[c]=1;
                sv2(i,j);
                c++;
            }
        }
      //  printf("\n");
    }

}

int main()
{
    input();
    solve();
    printf("%d \n",c);
    sort(house,house+c);
    for(int i=0; i<c; i++){
        printf("%d \n",house[i]);
    }
    return 0;
}
