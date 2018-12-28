# InfoRush

##Instruction compilation
#Ajout librairie
Télécharger librairie SFML : https://www.sfml-dev.org/download/sfml/2.5.1/
Ouvrir Visual Studio :
	- Propriété du projet
		- Propriété de configuration
			- C/C++
				-Général
					Toutes configurations
						Autre répértoire Include
							- Ajout du dossier SFML/Include
			- Editeur de lien
				-General
					Toutes configurations
						Repertoire de bibliothèque supplémentaire
							- Ajout du dossier SFML/lib
				-Entrée
					Release
						Dependances supplémentaires
							Ajouter : 	sfml-system.lib
										sfml-graphics.lib
										sfml-window.lib
										sfml-audio.lib
					Debug
						Dependances supplémentaires
							Ajouter :	sfml-graphics-d.lib
										sfml-window-d.lib
										sfml-system-d.lib
										sfml-audio-d.lib
Ajouter les fichiers "sfml-graphics-d.lib, sfml-window-d.lib, sfml-system-d.lib, sfml-audio-d.lib" dans le dossier Debug du projet

#Compilation
Lors de la compilation avec visual studio, un executable va se créer dans le dossier Debug du projet
Il vous suffira de lancer cet executable pour commencer à jouer !

##librairies
SFML 2.5.1

##Plateformes
VisualStudio 
Windows 10