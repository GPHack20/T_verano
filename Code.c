//1767  20

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	int cod;
	char N_I[250];
	char N_R[250];
	char Cod_g[250];
	int Cod_U;
	char FormP[250];
	char Organ[250];
	char Tipo[250];
	char Perio[250];
	char Dom[250];
	char TeleNZ[250];
	char Email[250];
	char NombreJNZ[250];
	char PosicionJ_NZ[250];
}DATOS;

void buscar_valores(int cod,int row, DATOS *M);
void read_csv(int row, int col, char *filename, DATOS *data);

int main(int argc, char const *argv[])
{
	setlocale(LC_CTYPE, "ukr");
	if (argc < 3){
		printf("Please specify the CSV file as an input.\n");
		exit(0);
	}
	int row     = atoi(argv[1]);
	int col     = atoi(argv[2]);
	char fname[256];	strcpy(fname, argv[3]);

	DATOS *Datos;

	Datos=(DATOS *)malloc((row) * sizeof(DATOS));
	read_csv(row,col,fname,Datos);
	int codigo;
	int op=0;
	do{
		printf("\n1 Просмотр\n");
		printf("2 Поиск\n");
		printf("3 Ввход\n");
		printf("Option: ");
		scanf("%i",&op);
		getchar();
		switch (op) {
			case 1:
				for(int c=1;c<row;c++){
					printf("\nКод НЗ: %d",Datos[c].cod);
					printf("\nПовна назва НЗ (установи): %s",Datos[c].N_I);
					printf("\nСкор.назва: %s",Datos[c].N_R);
					printf("\nКод гол. НЗ: %s",Datos[c].Cod_g);
					printf("\nКод ЄДРПОУ: %d",Datos[c].Cod_U);
					printf("\nФорма власності: %s",Datos[c].FormP);
					printf("\nОрган управління: %s",Datos[c].Organ);
					printf("\nТип установи: %s",Datos[c].Tipo);
					printf("\nРегіон: %s",Datos[c].Perio);
					printf("\nЮридична адреса: %s",Datos[c].Dom);
					printf("\nТелефон НЗ: %s",Datos[c].TeleNZ);
					printf("\nEmail НЗ: %s",Datos[c].Email);
					printf("\nПІБ керівника НЗ: %s",Datos[c].NombreJNZ);
					printf("\nПосада керівника НЗ: %s",Datos[c].PosicionJ_NZ);
					printf("\n");
				}
			break;
			case 2:
			printf("Enter Код НЗ: ");
			scanf("%d",&codigo);
			buscar_valores(codigo,row,Datos);
			break;
		}
	}while(op!=3);
	return 0;
}

/*
int busquedaBinaria(DATOS *arreglo, int tamano, int clave)
{
  int Iarriba = tamano-1;
  int Iabajo = 0;
  int Icentro;
  while (Iabajo <= Iarriba)
    {
      Icentro = (Iarriba + Iabajo)/2;
      if (arreglo[Icentro].cod == clave)
 return Icentro;
      else
 if (clave < arreglo[Icentro].cod)
   Iarriba=Icentro-1;
 else
   Iabajo=Icentro+1;
    }
  return -1;
}
*/

void buscar_valores(int cod,int row, DATOS *Datos){
		int ent=0;

	  for(int c=1;c<row;c++){
		if(Datos[c].cod==cod){
		//int c=busquedaBinaria(Datos,row,cod);
		//if(c!=-1){
			printf("\nКод НЗ: %d",Datos[c].cod);
			printf("\nПовна назва НЗ (установи): %s",Datos[c].N_I);
			printf("\nСкор.назва: %s",Datos[c].N_R);
			printf("\nКод гол. НЗ: %s",Datos[c].Cod_g);
			printf("\nКод ЄДРПОУ: %d",Datos[c].Cod_U);
			printf("\nФорма власності: %s",Datos[c].FormP);
			printf("\nОрган управління: %s",Datos[c].Organ);
			printf("\nТип установи: %s",Datos[c].Tipo);
			printf("\nРегіон: %s",Datos[c].Perio);
			printf("\nЮридична адреса: %s",Datos[c].Dom);
			printf("\nТелефон НЗ: %s",Datos[c].TeleNZ);
			printf("\nEmail НЗ: %s",Datos[c].Email);
			printf("\nПІБ керівника НЗ: %s",Datos[c].NombreJNZ);
			printf("\nПосада керівника НЗ: %s",Datos[c].PosicionJ_NZ);
			printf("\n");
			ent=1;
			int save;
			printf("\nDo you want to save as a text file?(1/0):");
			scanf("%d",&save);
			if(save==1){
				char nameFile[250];
				printf("Enter the file name: ");
				scanf("%s", nameFile);
				FILE *F=fopen(nameFile,"w");
				fprintf(F,"Код НЗ: %d\n",Datos[c].cod);
				fprintf(F,"Повна назва НЗ (установи): %s\n",Datos[c].N_I);
				fprintf(F,"Скор.назва: %s\n",Datos[c].N_R);
				fprintf(F,"Код гол. НЗ: %s\n",Datos[c].Cod_g);
				fprintf(F,"Код ЄДРПОУ: %d\n",Datos[c].Cod_U);
				fprintf(F,"Форма власності: %s\n",Datos[c].FormP);
				fprintf(F,"Орган управління: %s\n",Datos[c].Organ);
				fprintf(F,"Тип установи: %s\n",Datos[c].Tipo);
				fprintf(F,"Регіон: %s\n",Datos[c].Perio);
				fprintf(F,"Юридична адреса: %s\n",Datos[c].Dom);
				fprintf(F,"Телефон НЗ: %s\n",Datos[c].TeleNZ);
				fprintf(F,"Email НЗ: %s\n",Datos[c].Email);
				fprintf(F,"ПІБ керівника НЗ: %s\n",Datos[c].NombreJNZ);
				fprintf(F,"Посада керівника НЗ: %s\n",Datos[c].PosicionJ_NZ);
				fclose(F);
			}
		//}
		//else{
			//printf("\nDoes not exist!\n");
		//}
		}
	}
	if(ent==0){
		printf("\nDoes not exist!\n");
	}
}

void read_csv(int row, int col, char *filename, DATOS *data){
	FILE *file;
	file = fopen(filename, "r");

	int i = 0,j;
    char line[6000];
	while (fgets(line, 6000, file) && (i < row))
    {
      char* tmp = strdup(line);

      const char s[2] = ";";
      char *token;
      token = strtok(tmp, s);
			j=0;
      while( token != NULL && j<col && i>0 && strcmp(token,"\n")!=0) {
				switch (j) {
					case 0:
					data[i].cod=atoi(token);
					break;
					case 1:
					strcpy(data[i].N_I,token);
					break;
					case 2:
					strcpy(data[i].N_R,token);
					break;
					case 3:
					strcpy(data[i].Cod_g,token);
					break;
					case 4:
					data[i].Cod_U=atoi(token);
					break;
					case 5:
					strcpy(data[i].FormP,token);
					break;
					case 6:
					strcpy(data[i].Organ,token);
					break;
					case 7:
					strcpy(data[i].Tipo,token);
					break;
					case 8:
					strcpy(data[i].Perio,token);
					break;
					case 9:
					strcpy(data[i].Dom,token);
					break;
					case 10:
					strcpy(data[i].TeleNZ,token);
					break;
					case 11:
					strcpy(data[i].Email,token);
					break;
					case 12:
					strcpy(data[i].NombreJNZ,token);
					break;
					case 13:
					strcpy(data[i].PosicionJ_NZ,token);
					break;
				}
        token = strtok(NULL, s);
				j++;
      }
      free(tmp);

      i++;
    }
}
