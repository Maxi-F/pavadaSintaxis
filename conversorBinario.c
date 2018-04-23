#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/*preguntar si no vinieron archivos, o vino una canitdad impar de archivos
	(No cumple con consigna) */
	if ((argc % 2 == 0) || argc == 1){
    printf("ERROR: Se ingreso una cantidad erronea de archivos");
		return 0;
	}

  FILE *fTexto, *fBinario;
  int i = 1;

  while(argc > i) // Control de archivos existentes, los abre en modo lectura para verificar que existen.
  {

    fTexto = fopen(argv[i], "r");
    fBinario = fopen(argv[i+1], "r");

    if(!(fTexto && fBinario)) {
      if(!fTexto)
        printf("ERROR: el archivo de texto en la posicion %d no existe", i);
      else if(!fBinario)
        printf("ERROR: el archivo binario en la posicion %d no existe", i+1);
      fclose(fTexto);
      fclose(fBinario);
      return 0;
    }
    i = i+2;
    fclose(fTexto);
    fclose(fBinario);

  }

	char *cadena = malloc(2);
  i = 1;

	fTexto = fopen(argv[i], "r");
	fBinario = fopen(argv[i+1], "ab");

	while(fTexto && fBinario){

    while(fscanf(fTexto, "%c", cadena) != EOF)
    {
        fwrite(cadena, sizeof(cadena), 1, fBinario);
    };

		i = i+2;
		fclose(fTexto);
		fclose(fBinario);
    if(argc > i) {
      fTexto = fopen(argv[i], "r");
      fBinario = fopen(argv[i+1], "ab");
    }
    else{
      fTexto = NULL;
      fBinario = NULL;
    }
	}
	printf("Los archivos se copiaron correctamente.");

	return 0;
}
