#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void head();
FILE* open_file();
char *allocation();
void query(); 
void ip(char *nom,char *mdp);
int main()
{   
    head();
    query();
    return 0;
}


void head() 
{
    printf("Content-Type: text/html\n\n");
    printf("<html>\n");
    printf("    <head>\n");
    printf("<meta charset=\"UTF-8\">");
    printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
    printf("        <title> Adresse IP </title>\n");                
    printf("<style>");
    printf("body{");
    printf("    background-color:#a3d5d3;"
                "margin:0;"
                "height:100vh;"
                "display:flex;"
                "justify-content:center;"
                "align-items:center;"
            "}");
    printf(".plan {");
    printf("    border: 2px solid gray;"); 
    printf("    padding: 30px;"); 
    printf("    border-radius: 15px;"); 
    printf("    margin-left: auto;"); 
    printf("    margin-right: auto;"); 
    printf("    height: 300px;"); 
    printf("    width: 500px;"); 
    printf("    background-color: #f0f0f0;"); 
    printf("    display: flex;");
    printf("    flex-direction: column;"); 
    printf("    align-items: center;");
    printf("    justify-content: center;");
    printf("    text-align: center;");
    printf("}");
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
    printf("p{"
                "border:2px;"
                "color:black;"
                "background-color:pink;"
                "padding: 15px 32px;"
                "border-radius:15px;"
                "text-align:center;"
                "width:300;"
                "margin-left:auto;"
                "margin-right:auto;"
                "align-items: center;"
            "}");
      
    printf("</style>");        
    printf("    </head>\n");
}

char *allocation() 
{
    char *chaine = malloc(100 * sizeof(char));
    if (chaine == NULL) {
        printf("<p>erreur de l'allocation !</p>");
        exit(1);
    }
    return chaine;
}

FILE* open_file() 
{   
    FILE *fic = fopen("lis.txt", "a+");
    if (fic == NULL) {
        printf("<p>erreur d'ouverture du fichier !</p>");
        exit(1); 
    }
    return fic;
}

void query() 
{  
    FILE *fic = open_file(); 
    //char nom[100];
    //char mdp[100];
    char *nom = allocation();
    char *mdp= allocation();
    char *get = getenv("QUERY_STRING");
    printf("<body>");
    if (get == NULL) 
    {
        printf("<p>Erreur: QUERY_STRING manquant.</p>");
        fclose(fic);
        exit(1);
    }
    sscanf(get, "Nom=%99[^&]&motdepasse=%99s", nom, mdp);
    
    fprintf(fic,"\n%s:%s\n",nom,mdp);
    ip(nom,mdp);
    free(nom);
    free(mdp);
    fclose(fic);
}

void ip(char *nom,char *mdp)
{   
    int len=strlen(nom);
    int lan=strlen(mdp);
    if(len==0 || lan==0)
    {
        printf("<div class=\"plan\">");
        printf("<p>identifiant ou mot de passe vide</p>");
        printf("<form action=\"compte.cgi\" method=\"get\">");
        printf("<button type=\"submit\" class=\"custom-button\">ressaisir</button>"); 
        printf("</form>"); 
        printf("</div>");
        printf("</body></html>");
    }
    else{ 
        printf("<div class=\"plan\">");
        printf("<p>Bienvenue %s ! vous etes maintenant sur la liste des identifiants</p>",nom);
        printf("</form>");
        printf("<form action=\"class_ip2.cgi\" method=\"get\">");
        printf("<button type=\"submit\" class=\"custom-button\">Classe adresse ip</button>"); 
        printf("</form>");
        printf("</form>");
        printf("<form action=\"compte.cgi\" method=\"get\">");
        printf("<button type=\"submit\" class=\"custom-button\">retour</button>"); 
        printf("</form>"); 
        printf("</div>");
        printf("</body></html>");
    }
}




