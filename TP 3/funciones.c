#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int agregarPelicula(EMovie *movie)
{
    FILE *bMovieList;
    int numOfElements;

    system("cls");
    printf("Ingrese El Titulo De La Pelicula: \n");
    fflush(stdin);
    scanf("%[^\n]", movie->titulo);
    system("cls");
    printf("Ingrese El Genero De La Pelicula: \n");
    fflush(stdin);
    scanf("%[^\n]", movie->genero);
    system("cls");
    printf("Ingrese La Duracion De La Pelicula: \n");
    scanf("%d", &movie->duracion);
    system("cls");
    printf("Ingrese Una Descripcion Para La Pelicula: \n");
    fflush(stdin);
    scanf("%[^\n]", movie->descripcion);
    system("cls");
    printf("Ingrese Un Puntaje Para La Pelicula: \n");
    scanf("%d", &movie->puntaje);
    system("cls");
    printf("Ingrese Un Link Para Cargar Una Imagen De La Pelicula: \n");
    fflush(stdin);
    scanf("%[^\n]", movie->linkImagen);




    if((bMovieList = fopen("movie_list.dat", "ab")) == NULL)
    {
        system("cls");
        printf("\t\t\tERROR !\n\n\nNo Se Pudo Abrir El Archivo");
        printf("\n\n\nINGRESE <ENTER> PARA CONTINUAR");
        system("pause");
        return 0;
    }

   numOfElements = fwrite(movie, sizeof(EMovie), 1, bMovieList);
   if(numOfElements!=1)
   {
       system("cls");
        printf("\t\t\tERROR !\n\n\nNo Se Pudo Cargar La Pelicula");
        printf("\n\n\nINGRESE <ENTER> PARA CONTINUAR");
        system("pause");
        return 0;
   }

   fclose(bMovieList);



    return 1;
}

int borrarPelicula()
{
    FILE *bMovieList;
    FILE *bTempList;
    EMovie auxMovie;


    int numOfElements=0, found=0;
    char auxTitulo[80];

    system("cls");
    printf("\t\t\t -------\n\t\t\t|TITULOS|\n\t\t\t -------\n\n\n");
    if((bMovieList=fopen("movie_list.dat", "rb"))==NULL)
    {
        system("cls");
        printf("\t\t\t -------\n\t\t\t|TITULOS|\t\t\t\n -------\n\n\n");
        printf("ERROR AL ABRIR EL ARCHIVO. ES POSIBLE QUE ESTE NO EXISTA");
        system("pause");
        return 0;
    }

    rewind(bMovieList);

    while(!feof(bMovieList))
    {
        numOfElements = fread(&auxMovie, sizeof(EMovie), 1, bMovieList);
        if(numOfElements!=1)
        {
            if(feof(bMovieList))
            {
                break;
            }
            else
            {
                system("cls");
                printf("\t\t\t -------\n\t\t\t|TITULOS|\n\t\t\t -------\n\n\n");
                printf("Error. No Se Leyo El Ultimo Registro");
                break;
            }
        }

        printf("- %s\n", auxMovie.titulo);

    }

    printf("\n\nIngrese El Titulo De La Pelicula Que Desea Eliminar\n(Respete Los Espacios Y Las Mayusculas)\n\n- ");
    fflush(stdin);
    scanf("%[^\n]", auxTitulo);

    if((bTempList=fopen("temp_list.dat", "wb"))==NULL)
    {
        system("cls");
        printf("\t\t\t -------\n\t\t\t|TITULOS|\n\t\t\t -------\n\n\n");
        printf("ERROR AL CREAR EL ARCHIVO");
        system("pause");
        return 0;
    }
    rewind(bMovieList);

    while(!feof(bMovieList))
    {
        numOfElements = fread(&auxMovie, sizeof(EMovie), 1, bMovieList);
        if(numOfElements!=1)
        {
            if(feof(bMovieList))
            {
                break;
            }
            else
            {
                system("cls");
                printf("\t\t\t -------\n\t\t\t|TITULOS|\n\t\t\t -------\n\n\n");
                printf("Error. No Se Leyo El Ultimo Registro");
                break;
            }
        }

        if(strcmp(auxTitulo, auxMovie.titulo)==0)
        {
            system("cls");
            printf("\t\t\t -------\n\t\t\t|TITULOS|\n\t\t\t -------\n\n\n");
            found=1;
            printf("\nTitulo hallado y eliminado del registro\n");
        }
        else
        {
            fwrite(&auxMovie, sizeof(EMovie), 1, bTempList);
        }

    }

    if (found==0)
    {
        system("cls");
        printf("\t\t\t -------\n\t\t\t|TITULOS|\n\t\t\t -------\n\n\n");
		printf("No se encontró ninguna pelicula titulada %s.\n\n", auxTitulo);
	}

	fclose(bMovieList);
	fclose(bTempList);

	remove("movie_list.dat");
	rename("temp_list.dat", "movie_list.dat");


	system("pause");


    return 1;

}

int modificarPelicula()
{
    FILE* bMovieList;
    FILE* bTempList;
    EMovie auxMovie;
    int auxPunt, auxDur, numOfElements, found=0, opcion=0;
    char auxDesc[400], auxTit[80], auxLink[400], auxGen[80], auxTitulo[80], pregunta;

    system("cls");
    printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
    if((bMovieList=fopen("movie_list.dat", "rb"))==NULL)
       {
           system("cls");
           printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
           printf("Error Al Abrir movie_list.dat !!\n(Es Posible Que El Archivo No Exista)");
           system("pause");
           return 0;
       }

    while(!feof(bMovieList))
    {
        numOfElements = fread(&auxMovie, sizeof(EMovie), 1, bMovieList);
        if(numOfElements!=1)
        {
            if(feof(bMovieList))
            {
                break;
            }
            else
            {
                system("cls");
                printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                printf("Error. No Se Leyo El Ultimo Registro");
                break;
            }
        }

        printf("- %s\n", auxMovie.titulo);

    }

    printf("\n\nIngrese El Titulo De La Pelicula Que Desea Modificar\n(Respete El Uso De Mayusculas)\n\n- ");
    fflush(stdin);
    scanf("%[^\n]", auxTitulo);

    if((bTempList=fopen("temp_list.dat", "wb"))==NULL)
    {
        system("cls");
        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
        printf("ERROR AL CREAR EL ARCHIVO");
        system("pause");
        return 0;
    }
    rewind(bMovieList);

    while(!feof(bMovieList))
    {
        numOfElements = fread(&auxMovie, sizeof(EMovie), 1, bMovieList);
        if(numOfElements!=1)
        {
            if(feof(bMovieList))
            {
                break;
            }
            else
            {
                system("cls");
                printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                printf("Error. No Se Leyo El Ultimo Registro");
                break;
            }
        }

        if(strcmp(auxTitulo, auxMovie.titulo)==0)
        {
            found=1;
            system("cls");
            printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
            printf("\nQue Dato De %s Desea Modificar?\n\n", auxTitulo);
            printf("\n\t1 - Titulo\n\t2 - Genero\n\t3 - Duracion\n\t4 - Descripcion\n\t5 - Puntaje\n\t6 - Link De La Imagen");
            scanf("%d", &opcion);

            switch(opcion)
            {

                case 1:
                    system("cls");
                    printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                    printf("Ingrese Un Nuevo Titulo Para %s\n\n", auxTitulo);
                    fflush(stdin);
                    scanf("%[^\n]", auxTit);
                    printf("\n\n\nEsta seguro de que desea realizar esta modificacion?[s/n]");
                    fflush(stdin);
                    scanf("%c", &pregunta);
                    while(pregunta != 's' && pregunta != 'S' && pregunta != 'n' && pregunta != 'N')
                    {
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("ERROR. Por favor, ingrese 's' para SI o 'n' para NO\n\n");
                        printf("Cambiar '%s' Por '%s'\n", auxTitulo, auxTit);
                        printf("\n\nEsta seguro de que desea realizar esta modificacion?[s/n]");
                        scanf("%c", &pregunta);

                    }
                    if(pregunta == 's' || pregunta == 'S')
                    {
                        strcpy(auxMovie.titulo, auxTit);
                        if((numOfElements=fwrite(&auxMovie, sizeof(EMovie), 1, bTempList)) != 1)
                        {

                            system("cls");
                            printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                            printf("\n\n\t\tERROR. No Se Pudo Modificar El Archivo.");
                            fclose(bMovieList);
                            fclose(bTempList);
                            remove("temp_list.dat");
                            exit(1);
                        }
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("Modificacion Realizada Con Exito !\n\n\n\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("Accion Cancelada Por El Usuario");
                        if((numOfElements=fwrite(&auxMovie, sizeof(EMovie), 1, bTempList)) != 1)
                        {
                            system("cls");
                            printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                            printf("\n\n\t\tERROR. No Se Pudo Modificar El Archivo.");
                            fclose(bMovieList);
                            fclose(bTempList);
                            remove("temp_list.dat");
                            exit(1);
                        }

                        system("pause");
                        break;
                    }
                    break;

                case 2:
                    system("cls");
                    printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                    printf("Ingrese Un Nuevo Genero Para %s\n\n", auxTitulo);
                    fflush(stdin);
                    scanf("%[^\n]", auxGen);
                    printf("\n\nEsta seguro de que desea realizar esta modificacion?[s/n]");
                    fflush(stdin);
                    scanf("%c", &pregunta);
                    while(pregunta != 's' && pregunta != 'S' && pregunta != 'n' && pregunta != 'N')
                    {
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("ERROR. Por favor, ingrese 's' para SI o 'n' para NO\n\n");
                        printf("Cambiar '%s' Por '%s'\n", auxMovie.genero, auxGen);
                        printf("\n\nEsta seguro de que desea realizar esta modificacion?[s/n]");
                        scanf("%c", &pregunta);

                    }
                    if(pregunta == 's' || pregunta == 'S')
                    {
                        strcpy(auxMovie.genero, auxGen);
                        if((numOfElements=fwrite(&auxMovie, sizeof(EMovie), 1, bTempList)) != 1)
                        {
                            system("cls");
                            printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                            printf("\n\n\t\tERROR. No Se Pudo Modificar El Archivo.");
                            fclose(bMovieList);
                            fclose(bTempList);
                            remove("temp_list.dat");
                            exit(1);
                        }
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("Modificacion Realizada Con Exito !\n\n\n\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("Accion Cancelada Por El Usuario");
                        if((numOfElements=fwrite(&auxMovie, sizeof(EMovie), 1, bTempList)) != 1)
                        {
                            system("cls");
                            printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                            printf("\n\n\t\tERROR. No Se Pudo Modificar El Archivo.");
                            fclose(bMovieList);
                            fclose(bTempList);
                            remove("temp_list.dat");
                            exit(1);
                        }

                        system("pause");
                        break;
                    }
                    break;

                case 3:

                    system("cls");
                    printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                    printf("Ingrese Una Nueva Duracion Para %s\n\n", auxTitulo);
                    fflush(stdin);
                    scanf("%d", &auxDur);
                    printf("\n\nEsta seguro de que desea realizar esta modificacion?[s/n]");
                    fflush(stdin);
                    scanf("%c", &pregunta);
                    while(pregunta != 's' && pregunta != 'S' && pregunta != 'n' && pregunta != 'N')
                    {
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("ERROR. Por favor, ingrese 's' para SI o 'n' para NO\n\n");
                        printf("Cambiar '%d' Por '%d'\n", auxMovie.duracion, auxDur);
                        printf("\n\nEsta seguro de que desea realizar esta modificacion?[s/n]");
                        scanf("%c", &pregunta);

                    }
                    if(pregunta == 's' || pregunta == 'S')
                    {
                        auxMovie.duracion = auxDur;
                        if((numOfElements=fwrite(&auxMovie, sizeof(EMovie), 1, bTempList)) != 1)
                        {
                            system("cls");
                            printf("\n\n\t\tERROR. No Se Pudo Modificar El Archivo.");
                            fclose(bMovieList);
                            fclose(bTempList);
                            remove("temp_list.dat");
                            exit(1);
                        }
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("Modificacion Realizada Con Exito !\n\n\n\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("Accion Cancelada Por El Usuario");
                        if((numOfElements=fwrite(&auxMovie, sizeof(EMovie), 1, bTempList)) != 1)
                        {
                            system("cls");
                            printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                            printf("\n\n\t\tERROR. No Se Pudo Modificar El Archivo.");
                            fclose(bMovieList);
                            fclose(bTempList);
                            remove("temp_list.dat");
                            exit(1);
                        }

                        system("pause");
                        break;
                    }
                    break;

                case 4:
                    system("cls");
                    printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                    printf("Ingrese Una Nueva Descripcion Para %s\n\n", auxTitulo);
                    fflush(stdin);
                    scanf("%[^\n]", auxDesc);
                    printf("\n\nEsta seguro de que desea realizar esta modificacion?[s/n]");
                    fflush(stdin);
                    scanf("%c", &pregunta);
                    while(pregunta != 's' && pregunta != 'S' && pregunta != 'n' && pregunta != 'N')
                    {
                        system("cls");
                        printf("ERROR. Por favor, ingrese 's' para SI o 'n' para NO\n\n");
                        printf("Cambiar '%s'\n\n Por\n\n '%s'\n", auxMovie.descripcion, auxDesc);
                        printf("\n\nEsta seguro de que desea realizar esta modificacion?[s/n]");
                        scanf("%c", &pregunta);

                    }
                    if(pregunta == 's' || pregunta == 'S')
                    {
                        strcpy(auxMovie.descripcion, auxDesc);
                        if((numOfElements=fwrite(&auxMovie, sizeof(EMovie), 1, bTempList)) != 1)
                        {
                            printf("\n\n\t\tERROR. No Se Pudo Modificar El Archivo.");
                            fclose(bMovieList);
                            fclose(bTempList);
                            remove("temp_list.dat");
                            exit(1);
                        }
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("Modificacion Realizada Con Exito !\n\n\n\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("Accion Cancelada Por El Usuario");
                        if((numOfElements=fwrite(&auxMovie, sizeof(EMovie), 1, bTempList)) != 1)
                        {
                            printf("\n\n\t\tERROR. No Se Pudo Modificar El Archivo.");
                            fclose(bMovieList);
                            fclose(bTempList);
                            remove("temp_list.dat");
                            exit(1);
                        }
                        system("pause");
                        break;
                    }
                    break;

                case 5:
                    system("cls");
                    printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                    printf("Ingrese Un Nuevo Puntaje Para %s\n\n", auxTitulo);
                    fflush(stdin);
                    scanf("%d", &auxPunt);
                    printf("\n\nEsta seguro de que desea realizar esta modificacion?[s/n]");
                    fflush(stdin);
                    scanf("%c", &pregunta);
                    while(pregunta != 's' && pregunta != 'S' && pregunta != 'n' && pregunta != 'N')
                    {
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("ERROR. Por favor, ingrese 's' para SI o 'n' para NO\n\n");
                        printf("Cambiar '%d' Por '%d'\n", auxMovie.puntaje, auxPunt);
                        printf("\n\nEsta seguro de que desea realizar esta modificacion?[s/n]");
                        scanf("%c", &pregunta);

                    }
                    if(pregunta == 's' || pregunta == 'S')
                    {
                        auxMovie.puntaje = auxPunt;
                        if((numOfElements=fwrite(&auxMovie, sizeof(EMovie), 1, bTempList)) != 1)
                        {
                            printf("\n\n\t\tERROR. No Se Pudo Modificar El Archivo.");
                            fclose(bMovieList);
                            fclose(bTempList);
                            remove("temp_list.dat");
                            exit(1);
                        }
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("Modificacion Realizada Con Exito !\n\n\n\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("Accion Cancelada Por El Usuario");
                        if((numOfElements=fwrite(&auxMovie, sizeof(EMovie), 1, bTempList)) != 1)
                        {
                            printf("\n\n\t\tERROR. No Se Pudo Modificar El Archivo.");
                            fclose(bMovieList);
                            fclose(bTempList);
                            remove("temp_list.dat");
                            exit(1);
                        }
                        system("pause");
                        break;
                    }
                    break;

                case 6:

                    system("cls");
                    printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                    printf("Ingrese Un Nuevo Link Para La Imagen De %s\n\n", auxTitulo);
                    fflush(stdin);
                    scanf("%[^\n]", auxLink);
                    printf("\n\nEsta seguro de que desea realizar esta modificacion?[s/n]");
                    fflush(stdin);
                    scanf("%c", &pregunta);
                    while(pregunta != 's' && pregunta != 'S' && pregunta != 'n' && pregunta != 'N')
                    {
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("ERROR. Por favor, ingrese 's' para SI o 'n' para NO\n\n");
                        printf("Cambiar %s\n\nPor\n\n %s\n", auxMovie.linkImagen, auxLink);
                        printf("\n\nEsta seguro de que desea realizar esta modificacion?[s/n]");
                        scanf("%c", &pregunta);

                    }
                    if(pregunta == 's' || pregunta == 'S')
                    {
                        strcpy(auxMovie.linkImagen, auxLink);
                        if((numOfElements=fwrite(&auxMovie, sizeof(EMovie), 1, bTempList)) != 1)
                        {
                            printf("\n\n\t\tERROR. No Se Pudo Modificar El Archivo.");
                            fclose(bMovieList);
                            fclose(bTempList);
                            remove("temp_list.dat");
                            exit(1);
                        }
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("Modificacion Realizada Con Exito !\n\n\n\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                        printf("Accion Cancelada Por El Usuario");
                        if((numOfElements=fwrite(&auxMovie, sizeof(EMovie), 1, bTempList)) != 1)
                        {
                            printf("\n\n\t\tERROR. No Se Pudo Modificar El Archivo.");
                            fclose(bMovieList);
                            fclose(bTempList);
                            remove("temp_list.dat");
                            exit(1);
                        }
                        system("pause");
                        break;
                    }
                    break;

                default:
                    system("cls");
                    printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
                    printf("Error. El Numero Ingresado No Corresponde A Ninguna Opcion Disponible\n\n\n");
                    system("pause");

            }


        }
        else
        {
            fwrite(&auxMovie, sizeof(EMovie), 1, bTempList);
        }

    }

    if (found==0)
    {
        system("cls");
        printf("\t\t\t ------------------\n\t\t\t|MODIFICAR PELICULA|\n\t\t\t ------------------\n\n\n");
		printf("No se encontró ninguna pelicula titulada %s\n\n", auxTitulo);
	}

	fclose(bMovieList);
	fclose(bTempList);

	remove("movie_list.dat");
	rename("temp_list.dat", "movie_list.dat");

	system("pause");

    return 1;
}

void generarPagina()
{
    FILE* bMovieList;
    FILE* htmlList;
    EMovie auxMovie;
    int numOfElements;

    htmlList = fopen("movie_list.html", "w");
    bMovieList = fopen("movie_list.dat", "rb");

    fprintf(htmlList, "<!DOCTYPE html>"
"<!-- Template by Quackit.com -->"
"<html lang='en'>"
"<head>"
"    <meta charset='utf-8'>"
"    <meta http-equiv='X-UA-Compatible' content='IE=edge'>"
"    <meta name='viewport' content='width=device-width, initial-scale=1'>"
"    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
"    <title>Lista peliculas</title>"
"   <!-- Bootstrap Core CSS -->"
"    <link href='css/bootstrap.min.css' rel='stylesheet'>"
"    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
"    <link href='css/custom.css' rel='stylesheet'>"
"    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
"    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
"    <!--[if lt IE 9]>"
"        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
"        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
"    <![endif]-->"
"</head>"
"<body>"
"    <div class='container'>"
"        <div class='row'>");


    for( ; ; )
    {

        numOfElements = fread(&auxMovie, sizeof(EMovie), 1, bMovieList);

        if(numOfElements!=1)
        {
            if(feof(bMovieList))
            {
                break;
            }
            else
            {
                printf("ERROR. No Se Leyo El Ultimo Elemento");
                system("pause");
                break;
            }
        }

        fseek(htmlList, 0L, SEEK_END);
        fprintf(htmlList, "<article class='col-md-4 article-intro'>"
"<a href='#'>"
"<img class='img-responsive img-rounded' src='%s'"
"alt='' width='300'>"
"                </a>"
"                <h3>"
                    "<a href='#'>"
"%s"
"</a>"
"                </h3>"
"<ul>"
"<li>Genero:"
"%s"
"</li>"
"<li>Puntaje:"
"%d"
"</li>"
"<li>Duracion:"
"%d"
"</li>"
"</ul>"
"                <p>"
"%s"
"</p>"
"</article>", auxMovie.linkImagen, auxMovie.titulo, auxMovie.genero, auxMovie.puntaje, auxMovie.duracion, auxMovie.descripcion);


    }

    fseek(htmlList, 0L, SEEK_END);
    fprintf(htmlList, "</div>"
"        <!-- /.row -->"
"    </div>"
"    <!-- /.container -->"
"    <!-- jQuery -->"
"    <script src='js/jquery-1.11.3.min.js'></script>"
"    <!-- Bootstrap Core JavaScript -->"
"    <script src='js/bootstrap.min.js'></script>"
"	<!-- IE10 viewport bug workaround -->"
"	<script src='js/ie10-viewport-bug-workaround.js'></script>"
"	<!-- Placeholder Images -->"
"	<script src='js/holder.min.js'></script>"
"</body>"
"</html>");



    fclose(bMovieList);
    fclose(htmlList);

    system("cls");
    printf("\t\t\t ---------------------------\n\t\t\t|PAGINA GENERADA CON EXITO !|\n\t\t\t ---------------------------\n\n\n");
    system("pause");




}
