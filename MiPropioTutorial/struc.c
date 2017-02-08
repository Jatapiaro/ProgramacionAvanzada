#include <stdio.h>

typedef struct favs{
	char *food;
	char *friend;
}favs;

typedef struct dog{
	const char *pname;
	const char *pbreed;
	int avHeightCm;
	int avgWwightLbs;
	struct favs favoriteThings;
}dog;

void getDogInfo(struct dog aDog){
	printf("Name %s - %s, %d - %d\n",
	aDog.pname,aDog.pbreed,aDog.avHeightCm,
	aDog.avgWwightLbs);
}

void getMemoryLocs(dog aDog){
	printf("-----------\n",aDog.pname);
	printf("Name location %d\n",aDog.pname);
	printf("Breed location %d\n",aDog.pbreed);
	printf("h location %d\n",&aDog.avHeightCm);
	printf("w location %d\n",&aDog.avgWwightLbs);
}

void getDogFavs(dog d){
	printf("%s loves %s and his friend is %s\n",
	 d.pname,d.favoriteThings.food,
	 d.favoriteThings.friend);
}

void setDogW(dog *pdog,int w){
	//(*pdog).avgWwightLbs = w; is the same as:

	pdog->avgWwightLbs = w;

}

int main(int argc, char const *argv[]){

	/*dog cujo = {
		"Cujo","SALCHICHA",90,264};

	dog cujo2 = cujo;

	getDogInfo(cujo);
	getMemoryLocs(cujo);
	getMemoryLocs(cujo2);
	return 0;*/

	dog jacobo = {"jack","Beagle",178,80,{"Caca","Chucho"}};
	setDogW(&jacobo,10);
	getDogInfo(jacobo);
}