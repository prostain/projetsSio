<?php 

// Récupération des variables nécessaires au mail de confirmation	
 
 
 
// Insertion de la clé dans la base de données (à adapter en INSERT si besoin)

	// Préparation du mail contenant le lien d'activation
$destinataire ="peterson.rostain@gmail.com" ;
$sujet = "Activer votre compte" ;
$entete = "From: newWorld@newWorld.com" ;
 
// Le lien d'activation est composé du login(log) et de la clé(cle)
$message = 'Bienvenue sur new World,
 
Pour activer votre compte, veuillez cliquer sur le lien ci dessous
ou copier/coller dans votre navigateur internet.
 
<a>http://petersonr.hol.es/newWorld/mails/activationClient.php?email='.urlencode($email).'&confirmKey='.urlencode($key).'</a>
 
 
---------------
Ceci est un mail automatique, Merci de ne pas y répondre.';
 
 
mail($destinataire, $sujet, $message, $entete) ; // Envoi du mail
 
//...	
// Fermeture de la connexion	
//...
// Votre code
//...




?>