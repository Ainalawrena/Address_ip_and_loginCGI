#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void head();
void body();
int main()
{
	head();
	body();
	return (0);
}
void head()
{   
    printf("Content-Type: text/html\n\n");
    printf("<html>");
    printf("<head>");
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
    printf("    border: 2px solid gray;"
				"width: 500px;"
				"margin: 100px auto;"
                "padding: 30px;"                /* Ajoute de l'espace interne pour éviter que le contenu touche les bordures */
                "box-sizing: border-box;"       /* Inclut le padding et la bordure dans la largeur totale */
                "border-radius: 20px;"  
				"background-color: cyan;"        
                );  
    printf("}"); 
    printf(" label{"); 
    printf("display:block;"                     /*mampidina block ambany*/
                "margin:top;"                   /* pour eviter les collages*/
                "margin-bottom: 5px;"
                "padding-top: 15px;"           
        "}"); 
    printf("input[type=text]{");
    printf("    width: 400;"
                "display: block;"
                "text-indent: 15px;"
                "font-size: 15px;"              /*agrandis la police du placeholder*/
                "height: 40px;"                 /*hauteur*/
                "-webkit-appearance: none;"
                "border: 2px solid black;"
                "border-radius: 15px;"
				"background-color: pink;"
            "}"); 
    printf("form{");
    printf("    max-width: 600px;"
                "padding: 20px;"
                "box-sizing: border-box;"
            "}");
	
    printf("h{"
				"font-size: 20px;"
				"color: red;"
				"border: 2px solid black;"
				"border-radius: 10px;"
				"padding: 15px;"
				"margin: 20px auto;"
				"height: 100px;"
				"withd: 300px;"
                "margin-left:85;"
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
    printf("</head>");
}
void body()
{
	 printf("<body>"
			"<div class=\"plan\">"
			"<h>Entrer votre addresse ip</h><br>"
			"<form action=\"resultat2.cgi\" method=\"get\">"
			"<label for=\"nom\">==> Addresse ip</label>"
			    "<input type=\"text\" name=\"ip\"  placeholder=\"ex: 123.143.012.111\"/><br>"
			    "<button type=\"submit\" class=\"custom-button\">tester</button>"
			"</form>"
            "</form>"
            "<form action=\"compte.cgi\" method=\"get\">"
            "<button type=\"submit\" class=\"custom-button\">retour</button>"
            "</form>"
			"</div>"
            
			"</body>"
		"</html>"
	"\n");
}