#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void head();
void condition_vraie(int a);
void execution(int a,int b,int c,int d);
void retour();
void exec();

int main()
{   
    exec();
    return (0);
}

void head()
{
    printf("Content-Type: text/html \n\n");
    printf("<html>\n");
    printf("    <head>\n");
    printf("<meta charset=\"UTF-8\">");
    printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
    printf("        <title> Adresse ip </title>\n");
    printf("<style>");
    printf("body{");
    printf("    background-color:#a3d5d3;"
                "margin:0;"
                "height:100vh;"
            "}");
    printf(".plan {");
    printf("    border: 2px solid gray;"
				"width: 500px;"
				"margin: 100px auto;"
                "padding: 30px;"                /* Ajoute de l'espace interne pour éviter que le contenu touche les bordures */
                "box-sizing: border-box;"       /* Inclut le padding et la bordure dans la largeur totale */
                "border-radius: 20px;"  
				"background-color: cyan;"        
                );  
    printf("}");  
    printf("input[type=\"submit\"] {"
                "display: block;"
                "margin-top: 20px;" /* Espace au-dessus du bouton d'envoi */
            "}");
    printf("h{"
				"font-size: 20px;"
				"color: red;"
				"border: 2px solid black;"
				"border-radius: 10px;"
				"padding: 15px;"
				"margin: 20px auto;"
				"height: 50px;"
				"width: 300px;"
                "margin-left:160;"
				"text-align: center;" 
				"background-color: white;"
		"}");
     printf("p{"
				"font-size: 18px;"
				"color: red;"
				"border: 2px solid black;"
				"border-radius: 10px;"
				"padding: 15px;"
				"margin: 20px auto;"
				"height: 30px;"
				"width: 300px;"
                "margin-left:40;"
				"text-align: center;" 
				"background-color: white;"
		"}");
    printf(".custom-button{");
    printf("   background-color:#4CAF50;"
                "border:none;"
                "color:black;"
                "padding: 15px 32px;"
                "text-decoration:none;"
                "font-size:14px;"
                "cursor:pointer;"
                "border-radius:20px;"
                "}");
    printf(".custom-button:hover{");
    printf("background-color :#45a049;"
                "}");              
    printf("</style>");
    printf("    </head>\n");
}

void condition_vraie(int a)
{   
    if(a>=0 && a<=127)
    {
        printf("<p>votre adresse ip est de classe A</p><br>\n");
    }
    else if(a>127 && a<=191)
    {
        printf("<p>votre adresse ip est de classe B</p><br>");
    }
    else if(a>191 && a<=223)
    {
        printf("<p>votre adresse ip est de classe C</p><br>");
    }
    else if(a>223 && a<=239)
    {
        printf("<p>votre adresse ip est de classe D</p><br>");
    }
    else if(a>239 && a<=255)
    {
        printf("<p>votre adresse ip est de classe E</p><br>");
    }
}

void execution(int a, int b, int c, int d)
{  
    printf("<body>");
    if(a >= 0 && a <= 255 && b >= 0 && b <= 255 && c >= 0 && c <= 255 && d >= 0 && d <= 255)
    {
        condition_vraie(a);
    }
    else
    {
        printf("<p>ce n'est pad un adresse ip</p>");
    }  
}

void retour()
{
    printf("<form action=\"connect.cgi\" method=\"get\">");
    printf("<button type=\"submit\" class=\"custom-button\">se deconnecter</button>");
    printf("</form>");
    printf("    </body>\n</html>\n");
}
void exec()
{   
    head();    
    int a,b,c,d;
    char *chain = getenv("QUERY_STRING");
    sscanf(chain,"ip=%d.%d.%d.%d",&a,&b,&c,&d); 
    printf("<div class=\"plan\">"); 
    printf("<h>Resultat</h>");  
    execution(a,b,c,d);
    retour();
    printf("</div>");
}
