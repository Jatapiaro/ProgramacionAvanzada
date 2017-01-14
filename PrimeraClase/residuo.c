#include <stdio.h>

int residuo(int a, int b){
    if(a<b){
        return a;
    }else{
        return residuo(a-b,b);
    }
}

int main(){
    
    int a, b;
    scanf("%d %d",&a,&b);
    printf("Residuo de %d/%d = %d\n",a,b,residuo(a,b));

}
