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
    printf("<title>formulaire</title>"); 
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
    printf("    background-color: cyan;");
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
                "font-size:20px;"
                "cursor:pointer;"
                "border-radius:20px;"
                "}");
    printf(".custom-button:hover{");
    printf("background-color :pink;"
                "}");

    printf("h1 {");
    printf("    font-size: 28px;"); 
    printf("    margin: 20px 0;"); 
    printf("}"); 
    
    
    printf("form {");
    printf("    margin: 0;"); 
    printf("    padding: 20px;"); 
    printf("    width: 100%;");
    
    printf("</style>");
    printf("</head>");
}

void body()
{   
    printf("<body>");
    printf("<div class=\"plan\">"); 
    printf("<h1>Selectionner votre choix</h1>");
    printf("<form action=\"connect.cgi\" method=\"get\">");
    printf("<button type=\"submit\" class=\"custom-button\">se conneter</button>"); 
    printf("</form>");
    printf("<form action=\"compte.cgi\" method=\"get\">");
    printf("<button type=\"submit\" class=\"custom-button\">creer un compte</button>"); 
    printf("</form>");
    printf("</div>");
    printf("</body>");
    printf("</html>");
}
