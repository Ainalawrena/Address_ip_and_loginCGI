#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void head();
void recherche(FILE *fic, char *nom, char *mdp);
FILE* open_file();
char *allocation();
void info_correct();
void info_incorrect();
void query();

int main() {
    head();
    query();
    return 0;
}

void head() {
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
                "width:200;"
                "margin-left:auto;"
                "margin-right:auto;"
                "align-items: center;"
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
    printf("</style>");                      
    printf("    </head>\n");
}

char *allocation() {
    char *chaine = malloc(100 * sizeof(char));
    if (chaine == NULL) {
        printf("<p>erreur de l'allocation !</p>");
        exit(1);
    }
    return chaine;
}

FILE* open_file() 
{   
    FILE *fic = fopen("lis.txt", "r");
    if (fic == NULL) 
    {
        printf("<p>erreur d'ouverture du fichier !</p>");
        exit(1); 
    }
    return fic;
}

void query() 
{  
    FILE *fic = open_file(); 
    char nom[100];
    char mdp[100];
    char *chaine = allocation();
    char *get = getenv("QUERY_STRING");

    if (get == NULL) {
        printf("<p>Erreur: QUERY_STRING manquant.</p>");
        fclose(fic);
        exit(1);
    }
    sscanf(get, "Nom=%99[^&]&motdepasse=%99s", nom, mdp);

    recherche(fic, nom, mdp);

    free(chaine);
    fclose(fic);
    
    printf("</body></html>");
}

void recherche(FILE *fic, char *nom, char *mdp) {   
    char line[100];
    char *name;
    char *mot;
    int found = 0;

    while (fgets(line, sizeof(line), fic) != NULL) {   
        line[strcspn(line, "\n")] = 0;  
        char *token = strtok(line, ":");
        if (token != NULL) {
            name = token;
            token = strtok(NULL, ":");
            if (token != NULL) 
            {
                mot = token;
                if (strcmp(nom, name) == 0 && strcmp(mdp, mot) == 0)
                {
                    info_correct();
                    found = 1;
                    break;
                }
            }
        }    
    }
    if (!found) 
    {
          info_incorrect();
    }
}
void info_correct()
{
    printf("<div class=\"plan\">");
    printf("<p>Connexion avec succees</p>");
    printf("</form>");
    printf("<form action=\"class_ip.cgi\" method=\"get\">");
    printf("<button type=\"submit\" class=\"custom-button\">Classe adresse ip</button>"); 
    printf("</form>");
    printf("</form>");
    printf("<form action=\"connect.cgi\" method=\"get\">");
    printf("<button type=\"submit\" class=\"custom-button\">retour</button>"); 
    printf("</form>"); 
    printf("</div>");
}
void info_incorrect()
{
    printf("<div class=\"plan\">");
    printf("<p>Mot de passe ou login incorrect</p>");
    printf("</form>");
    printf("</form>");
    printf("<form action=\"connect.cgi\" method=\"get\">");
    printf("<button type=\"submit\" class=\"custom-button\">retour</button>"); 
    printf("</form>"); 
    printf("</div>");
}