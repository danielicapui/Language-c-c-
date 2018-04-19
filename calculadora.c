 #include <stdio.h>

int main()
{  double x,y,m;
    char n;
    printf("Digite dois números reais: S para substrair,\n M para multiplicar\n ,D para dividir\n ");
    scanf("%lf %lf %c",&x,&y,&n);

     switch(n){

     case 'S':
     case 's':
     printf("%lf + %lf = %.4lf",x,y,m=x+y);
       break;
     case 'M':
     case 'm':
      printf("%lf X %lf = %.4lf",x,y,m=x*y);
       break;
      case 'D':
      case 'd':
if(x==0){
      printf("Não podemos realizar com 0. ");}
     if(y==0){
       printf("Não podemos realizar com 0");break;}
       printf("%lf X %lf = %.4f",x,y,m=x/y);
       break;
       default:
       printf("erro");
       }
    return 0;
}
