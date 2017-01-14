#include <stdio.h>


double calculate_tq(double a,double b,double c){
	return ((b+c-a)*(a+b-c)*(c+a-b))/(a*b*c);
}

int main(int argc, char const *argv[])
{
	int cases;
	double a,b,c;

	scanf("%d",&cases);

	for (int i = 0; i < cases; ++i)
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		double tq = calculate_tq(a,b,c);
		if(tq == 1){
			printf("%s\n", "equilateral");
		}else if(tq > 0.5 && tq < 1){
			printf("%s\n", "good");
		}else if(tq > 0 && tq <= 0.5){
			printf("%s\n", "bad");
		}
	}

}