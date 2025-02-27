#include<stdio.h>
int add(int a , int b) {
    return a+b;
}
int sub(int a , int b) {
    return a-b;
}
int mul(int a , int b) {
    return a*b;
}
int div(int a , int b) {
    if (b == 0) {
        printf("not divisble by 0!!\n");
        return 1;
    }
    return a/b;

}
// define jump tables and its keys
int (*jump_tables[])(int , int) = {add,sub,mul,div};
int main() {
    int choice ;
    printf("enter the choice 0 ->add , 1->sub , 2-> mul , 3-> div : %d\n",&choice);
    scanf("%d",&choice);
    if (choice < 0 || choice > 3) {
        printf("Invalid choice\n");
        return 1;
    }

        int result = jump_tables[choice](4 ,5);

    printf("%d\n",result);
    return 0;
}