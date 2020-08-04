
#include <stdio.h>
#include <stdlib.h>

//Ficheiro actualizado no branch 1
int main()
{
	FILE *fp,*fw;
	char caracter;
	char url[]="http://www.kidsmathgamesonline.com/images/pictures/numbers600/number";
	short int acumulador[10];
	short int i,total;
	short N;
	N=25000        
    printf("Acumulador decimais de pi");
   

	// Crear o ficheiro de entrada
	fp = fopen ( "/home/mint/Escritorio/pi/pi.txt", "r" );        
	if (fp==NULL) {fputs ("File error",stderr); exit (1);}
	// Crear o ficheiro de saida
	fw = fopen ( "/home/mint/Escritorio/pi/piAcumulado.txt", "w+" );        
	if (fw==NULL) {fputs ("File error",stderr); exit (1);}
	
	//Escribir cabeceira
	fputs("Numero\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n", fw);
	
	//Escribir url imaxes
	fputs("Imaxe\t", fw);
	
	for(i=0;i<10;i++) {
		fputs(url,fw);
		fprintf(fw,"%d.jpg\t",i);
	}
		fputs("\n", fw);
	
	
	
	for(i=0;i<10;i++) acumulador[i]=0;
	
	total=0;
	while (total!=N) {
	
	for(i=0;i<10;i++) 
		{		
				caracter=fgetc(fp);
				//Sumamos os acumulados de cada cifra
				while(caracter != ' ') {	
					
					switch(caracter) {
						case '0': acumulador[0]++;
							break;
						case '1': acumulador[1]++;
							break;					  
						case '2': acumulador[2]++;
							break;
						case '3': acumulador[3]++;
							break;
						case '4': acumulador[4]++;
							break;
						case '5': acumulador[5]++;
							break;
						case '6': acumulador[6]++;
							break;
						case '7': acumulador[7]++;
							break;
						case '8': acumulador[8]++;
							break;							
						case '9': acumulador[9]++;
							break;
						default: puts("Error");
					}
					caracter=fgetc(fp);
				}
			}
			total=total+100;
			fprintf(fw,"%d", total);
			for(i=0;i<10;i++) {
				
				fputs("\t", fw);
				fprintf(fw,"%d",acumulador[i]);
				}
			fputs("\n",fw);
			
			while (caracter != '\n') caracter=fgetc(fp);
		}
	
	fclose ( fp );
	fclose ( fw );
	return 0;

}
