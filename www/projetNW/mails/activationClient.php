<?php
 
include '../connectBase.php';
 
 
// Récupération des variables nécessaires à l'activation
$email = $_GET['email'];
$key = $_GET['confirmKey'];
 
// Récupération de la clé correspondant au $email dans la base de données
$resultI=$cnx->query("SELECT etatIns FROM utilisateur WHERE email='$email'");
$resultK=$cnx->query("SELECT confirmKey FROM utilisateur WHERE email='$email'");
$keybdd=$resultK['confirmKey'];
  
 
 
// On teste la valeur de la variable $etatIns récupéré dans la BDD
if($resultI == '1') // Si le compte est déjà actif on prévient
  {
     echo "Votre compte est déjà actif !";
  }
else // Si ce n'est pas le cas on passe aux comparaisons
  {
     if($key == $keybdd) // On compare nos deux clés	
       {
          // Si elles correspondent on active le compte !	
          echo "Votre compte a bien été activé !";
 
          // La requête qui va passer notre champ actif de 0 à 1
        $cnx->query("UPDATE utilisateur SET confirmKey = 1 WHERE email='$email' ");
       }
     else // Si les deux clés sont différentes on provoque une erreur...
       {
          echo "Erreur ! Votre compte ne peut être activé...";
       }
  }

 ?>