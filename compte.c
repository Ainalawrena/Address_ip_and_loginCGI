#include <stdio.h>
void head();
void body();
int main()
{   
    head();
    body();
    return 0;
}
void head()
{   
    printf("Content-Type: text/html\n\n");
    printf("<html>");
    printf("<head>");
    printf("<meta charset=\"UTF-8\">");
    printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
    printf("<title>");
    printf("formulaire");
    printf("</title>");
    printf("<style>");
    printf("body{");
    printf("    background-color:#a3d5d3;"
                "margin:0;"
                "height:100vh;"
            "}");
    printf(".plan {");
    printf("border: 2px solid gray;"
                "padding: 10px;"                /* Ajoute de l'espace interne pour éviter que le contenu touche les bordures */
                "box-sizing: border-box;"       /* Inclut le padding et la bordure dans la largeur totale */
                "border-radius: 15px;"          /* Assure que les coins sont arrondis, si ce n'est pas déjà le cas */
                "margin: 10px 0;"
                "background-color:#f0f0f0;"
                "height:500;");  
    printf("}"); 
    printf(" label{"); 
    printf("display:block;"                     /*mampidina block ambany*/
                "margin:top;"                   /* pour eviter les collages*/
                "margin-bottom: 5px;"
                "padding-top: 15px;"
                "font-family: serif;"            /*espace entre*/             
        "}"); 
    printf("input[type=text]{");
    printf("width:530;"
            "display:block;"
            "text-indent: 15px;"
            "font-size: 15px;"                  /*agrandis la police du placeholder*/
            "height: 40px;"                     /*hauteur*/
            "-webkit-appearance: none;"
            "border:2px solid black;"
            "border-radius: 15px;"
            "background-color:pink;"
            
            "}");
    printf("input[type=password]{");
    printf("width:530;"
            "display:block;"
            "text-indent: 15px;"
            "font-size: 15px;"                  /*agrandis la police du placeholder*/
            "height: 40px;"                     /*hauteur*/
            "-webkit-appearance: none;"
            "border:2px solid black;"
            "border-radius: 15px;"
            "background-color:pink;"
            "}");    
    printf("form{");
    printf("max-width: 600px;"
                "margin:0 auto;"
                "padding:20px;"
                "box-sizing:border-box;"
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
    printf("h1{");
    printf("font-family:serif;"
            "}");      
    printf("</style>");
    printf("</head>");
}
void body()
{   
    printf("<body><br>");
    printf("<form action=\"inscription.cgi\" method=\"get\">");
    printf("<div class=\"plan\">"); 
    printf("<h1><center>Creer votre compte</center></h1>");
    printf("<label for=\"nom\">Identifiant:</label>");
    printf("<input type=\"text\" name=\"Nom\" placeholder=\"votre nom...\"/><br><br> ");
    printf("<label for=\"prenom\">Mot de passe:</label>");
    printf("<input type=\"password\" name=\"motdepasse\" placeholder=\"votre mot de passe...\"/><br><br>");
    printf("<br><br>");
    printf("<button type=\"submit\" class=\"custom-button\">se connecter</button>"); 
    printf("</form>");
    printf("<form action=\"choix.cgi\" method=\"get\">");
    printf("<button type=\"submit\" class=\"custom-button\">retour</button>"); 
    printf("</form>");
    printf("</div>");
    printf("</body>");
    printf("</html>");
}
