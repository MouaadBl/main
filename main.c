#include <stdio.h>
#include <stdlib.h>
#include <string.h>

									// TIC TAC TOE GAME   :  (MORPION).
									
/********************************************************
**            Jeu du Morpion ( X , O)                  **
** - Editeur               : Mouaad BOULHANA           **
** - Email                 : Mouaadblhn@Gmail.com      **
** - Date de Creation      : 01/03/2019                **
** - Dernière Mise à Jour  : 05/04/2019                **
*********************************************************/


	// Structure Pour La Représentation d’un Joueur.
typedef struct {         
	char nom[20];
	short age;
	short nvect;       // Nombre de Victoires.
	short npart;       // Nombre de Parties Jouées.
}Joueur;


// La Strucure Jeux.
typedef struct {
	int id;              // L'identifiant.
	Joueur player1;
	Joueur player2;
	short npose;         // Le nombre de poses de chacun des joueurs.
	short jactif;        // Un entier représentant le joueur actif.
	short Jgagne;        // Joueur Gagnant.
}Jeux;


	// Une fonction qui initialise la grille du jeu.
void GrilleDuJeu (char grille[3][3]) {
	short n,m;
	char i = '0';
	for (n=0;n<3;n++)
	{
		for (m=0;m<3;m++)
		{
			grille[n][m] = i;
			i++;
		}
	}
}


	// Une fonction qui indique si la grille est pleine.
int GrillePleine (char grille[3][3]) {
	short n,m,i=0;
	for (n=0;n<3;n++)
	{
		for (m=0;m<3;m++)
		{
			if (grille[n][m] == 'X' || grille[n][m] == 'O')
				i++;
		}
	}
	if (i == 9)					// si : i=9   -->  les 9 cases est pleine.
		return 1;
	else 
		return 0;
}


	// Une fonction qui permet de tester si une case de la grille est vide.
int EtatCase (char grille[3][3], int a, int b) {  			// int a pour les lignes et int b pour les ligne.
	if (grille[a][b] == 'X' || grille[a][b] == 'O')
		return 1;
	else
		return 0;
}


	//Une fonction qui permet qui permet de placer un jeton sur une case particulière de la grille.
void PlacerJeton (char grille[3][3], char choix) {
	int cln = -1;
	int lgn = -1;
	char ret;
	printf("\n\n");
	while (cln < 1 || cln > 3)
	{
		printf("\t \t .. Colone (1-3) :\t");
		scanf("%s",&ret);
		cln = atoi(&ret);
		if (cln < 1 || cln > 3)
			printf("\n\t\t\t---> Value Incorrect !\n");
	}
	while (lgn < 1 || lgn > 3)
	{
		printf("\n\t \t .. Ligne (1-3) :\t");
		scanf("%s",&ret);
		lgn = atoi(&ret);
		
		if (lgn < 1 || lgn > 3)
			printf("\n\t\t\t---> Value Incorrect !\n");
	}
	if (grille[lgn-1][cln-1] != 'X' && grille[lgn-1][cln-1] != 'O')
		grille[lgn-1][cln-1] = choix;
	else
		PlacerJeton(grille, choix);
}


	// Une fonction permettant l’affichage de la grille.
void AffichageGrille (char grille[3][3]) {
	printf("\n\n");
	printf("\t\t\t\t          (1)       (2)        (3)     \n");
	printf("\t\t\t\t     --------------------------------\n");
	printf("\t\t\t\t               |          |          \n");
	printf("\t\t\t\t  (1)     %c    |    %c     |    %c    \n",grille[0][0],grille[0][1],grille[0][2]);
	printf("\t\t\t\t               |          |          \n");
	printf("\t\t\t\t     --------------------------------\n");
	printf("\t\t\t\t               |          |          \n");
	printf("\t\t\t\t  (2)     %c    |    %c     |    %c    \n",grille[1][0],grille[1][1],grille[1][2]);
	printf("\t\t\t\t               |          |          \n");
	printf("\t\t\t\t     --------------------------------\n");
	printf("\t\t\t\t               |          |          \n");
	printf("\t\t\t\t  (3)     %c    |    %c     |    %c    \n",grille[2][0],grille[2][1],grille[2][2]);
	printf("\t\t\t\t               |          |          \n");
	printf("\t\t\t\t     --------------------------------\n");
	printf("\n");	
}


// Une fonction qui permet de tester s’il y a un gagnant ou non.
int Gagnant(char grille[3][3]){
	int i,j;
	
	/******* HORIZONTAL ******/
    for (i=0;i<3;i++)
    {
        if (grille[i][0] == grille[i][1] && grille[i][1] == grille[i][2])
            return 1;
    }
	/*************************/
	
	/******* VERTICAL ******/
    for (j=0;j<3;j++)
    {
        if (grille[0][j] == grille[1][j] && grille[1][j] == grille[2][j])
            return 1;
    }
	/***********************/

	/******* DIAGONAL ******/
    if ((grille[0][0] == grille[1][1] && grille[1][1] == grille[2][2]) || (grille[0][2] == grille[1][1] && grille[1][1] == grille[2][0]))
		return 1;
	/***********************/	
	return (0);
}

	// menu.
void menu ()
	{
		printf("\t\t\t*************************************************************************\n");
		printf("\t\t\t***********                                                   ***********\n");
		printf("\t\t\t**                                                                     **\n");
		printf("\t\t\t**                   ----> TIC TAC TOE GAME : <----                    **\n");
		printf("\t\t\t******                                                             ******\n");
		printf("\t\t\t***********                                                   ***********\n");
		printf("\t\t\t*************************************************************************\n");
	}
	
int main()
{	
	char grille[3][3];
	int	i = 0;
	short n = 0;
	char	ret;
	Joueur	player1;
	Joueur	player2;
	int npart=0;   // numero du partie joue.

	menu ();
	
	printf("\n\n\t\t** Informations du Joueurs : \n\n");
	
	/* LES INFOS DU JOUEUR 2 */
	printf("\t\t\t --> Joueur 1 :\n");
	printf("\t - NOM :\t");
	scanf("%s",player1.nom);
	printf("\t - AGE :\t");
	scanf("%s",&ret);
	player1.age = atoi(&ret);
	
	/*************************/
	
	
	/* LES INFOS DU JOUEUR 1 */
	printf("\t\t\t --> Joueur 2 :\n");
	printf("\t - NOM :\t");
	scanf("%s",player2.nom);
	printf("\t - AGE :\t");
	scanf("%s",&ret);
	player2.age = atoi(&ret);
	/*************************/
	
	
	/**************** Debut du Jeu ****************/
	while (n != 1) 
	{
	GrilleDuJeu (grille);
	while (i < 9)
	{
		char choix = (i % 2 == 0 ? 'X' : 'O');
		if (i % 2 == 0) 
			printf("\t-- %s ,C'est votre tour :\n",player1.nom);
		else 
			printf("\t-- %s ,C'est votre tour :\n",player2.nom);
			
		PlacerJeton (grille, choix);
		AffichageGrille(grille);
		if (Gagnant(grille) && i % 2 == 0) {
					// Cette condition est testée si le joueur 1 est gagne ou non.
			printf("\n\n\t\t\t\a ------> !!! %s GAGNE !!! <------\n\n",player1.nom);
			player1.nvect++;		// Nombre de Victoires du joueur 1.
			break;
		}
		if (Gagnant(grille) && i % 2 != 0) {
					// Cette condition est testée si le joueur 2 est gagne ou non.
			printf("\n\n\t\t\t\a ------> !!! %s GAGNE !!! <------\n\n",player2.nom);
			player2.nvect++;		// Nombre de Victoires du joueur 2.
			break;
		}
		i++;
	}
	if (i == 9 && GrillePleine(grille) == 1)
		printf("Egaliter\n");
	npart++;
	i=0;
	printf("\n\n\t\t ---> Pour quitter le jeu, cliquez sur 1 !\n");
	printf("\n\n\t\t ---> Pour continuer, cliquez sur 2 !\n\n");
	printf("\n\n\t\t\t -- Votre Choix :\t");
	scanf("%s",&ret);
	n = atoi(&ret);
    }
    
    player1.npart=npart;
    player2.npart=npart;
    
	/***************************************** STATISTIQUES DU JEU *************************************/
	
    	printf("\n\n\t------------------------ STATISTIQUES DU JEU ------------------------\n\n");
    		if (player1.nvect > player2.nvect)
    			printf("\t\t\t !! %s GAGNE !!\n",player1.nom);
    			
    		else {
    			if (player1.nvect < player2.nvect)
    				printf("\t\t\t !! %s GAGNE !!\n",player2.nom);
    			else
    				printf("\t\t\t !! Egaliter !!\n");
				}
	
    	printf("\n\t-----------------------------------------------------------------------\n");
    	printf("\t\t >>>>     Joueur 1 :     <<<<\n\n");
    	printf("\t\t\t - NOM          : %s\n",player1.nom);
    	printf("\t\t\t - AGE          : %d\n",player1.age);
    	printf("\t\t\t - N. VICTOIRES : %d\n",player1.nvect);
    	printf("\t\t\t - N. PARTIES   : %d\n",player1.npart);
    	printf("\t-----------------------------------------------------------------------\n");
    	printf("\t\t >>>>     Joueur 2 :     <<<<\n\n");
    	printf("\t\t\t - NOM          : %s\n",player2.nom);
    	printf("\t\t\t - AGE          : %d\n",player2.age);
    	printf("\t\t\t - N. VICTOIRES : %d\n",player2.nvect);
    	printf("\t\t\t - N. PARTIES   : %d\n",player2.npart);
    	printf("\t-----------------------------------------------------------------------\n");
    	
    /***************************************************************************************************/
    
    system("pause");
	return 0;
}
