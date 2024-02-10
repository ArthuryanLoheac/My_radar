# My_radar

Compiler :  
> make

2 types d'entités :  
- les avions,  
- les tours de contrôle.

Les règles de base de my_radar sont les suivantes :  
- les avions volent d'un endroit donné à un autre.  
- les avions apparaissent sur le panneau de simulation lorsqu'ils décollent.  
- les avions disparaissent du panneau de simulation lorsqu'ils atterrissent.  
- les avions se déplacent en ligne droite à des vitesses constantes données.  
- Les avions qui entrent en collision avec un autre sont détruits et disparaissent du panneau de simulation.  
- Les zones de contrôle permettent aux avions d'entrer en collision les uns avec les autres sans être détruits et de poursuivre leur route.  
- les tours de contrôle ne se déplacent pas et ont des zones de contrôle sur la carte.  
- les tours de contrôle apparaissent sur le panneau de simulation lors du lancement.

pour changer la visibilité des hitboxes et des zones appuyez sur la touche 'L'.  
pour changer la visibilité des sprites des entités appuyez sur la touche 'S'.  

Lancer programme :
> ./my_radar fichier_de_données

Fichier :  
> Un espace entre chaque paramètre et un espace entre 2 objets  
> Avions :  
> A [x] [y] [x_fin] [y_fin] [vitesse] [delay]     
> Tour :  
> T [x] [y] [rayon]  
