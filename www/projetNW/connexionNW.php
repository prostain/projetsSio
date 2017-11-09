<?php
include('connectBase1.php');
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="style/style.css">
	<title>Accueil du site</title>
	<style>
		label {
		    display: initial;
		    width: initial;
		    text-align: left;
		    box-sizing: border-box;
		}
		pre {display : inline;}		
		.message {
				border-radius:20px;
				padding:20px;
				margin:auto;
				width:500px;
				background:url('images/black_40p.png');
				color:#ffffff;
				text-align:center;
				font-weight:bold;
				margin-top:20px;
			}
		.sizeMain { width:40%; height: 35%; }			
	</style>
</head>
<?php include 'header.php';?>
<?php include 'menu.php';?>
<body class="bg5">
<div class="contenu background_contenu align1" >
<div class="bg9">
	<div class="topCentre sizeBandeau1 border2 bg1 box2 centrage"> 
		<h2>Connexion / Déconnexion</h2>
	</div>
<?php
/* 			Utilisateur connecté
 *   déconnexion en supprimant les variables de session
 */

if(isset($_SESSION['username']))
{
	unset($_SESSION['username'], $_SESSION['userid'], $_SESSION['admin']);
	echo "<div class=\"bottomLeft message alignL\">Vous avez été déconnecté</div>";
}
else
{
	$username = '';

	// Traitement du formulaire 
	if(isset($_REQUEST['btn']))
	{
		$username = $cnx->escape_string($_REQUEST['username']);
		$password = $_REQUEST['password'];
		// récupération du mot de passe utilisateur
		$result = $cnx->query('select idUser, password, admin from user where nomUser="'.$username.'"');
		if ($result=== false OR $result->num_rows<1) {
				$form = true;
				$message = 'Utilisateur inconnu';
		}
		else {
			$ligne = $result->fetch_array();
			
			// comparaison des mots de passe
			if (password_verify(!$password == $ligne['password']))
			{
				// utilisateur reconnu, pas de formulaire à afficher
				$form = false;
				// màj du username et identifiant dans la session
				$_SESSION['username'] = $_REQUEST['username'];
				$_SESSION['userid'] = $ligne['idUser'];
				if ($ligne['admin'] == 1){
					$_SESSION['admin'] = true;
				}
				
				echo "<div>Vous êtes connecté.</div>";

				//header("location: $url_home");
			}
			else
			{
				// combinaison fausse, message d'avertissement et formulaire
				$form = true;
				$message = 'Identifiants non reconnus !';
			}
		}
	}
	else
	{
		$form = true;
	}
	if($form)
	{
		// affichage éventuel d'un message sil y a lieu
		if(isset($message))	{
			echo '<div class="bottomLeft message alignL">'.$message.'</div>';
		}
		// Affichage du formulaire
?>
<div class="centreMiddle size3c border2 bg1 box2 centrage">
    <form action="" method="post">
        <legend>Identifiants</legend> <br><br>
            <label for="username" ><pre class="alignL">Identifiant </pre></label>
            <input type="text" name="username" id="username" required autofocus><br><br><br>
            <label for="password" class="alignL"><pre>Mot de passe</pre></label>
            <input type="password" name="password" id="password" required><br><br><br>
            <input type="submit" name="btn" value="Connection"><br><br>
		
    </form>
</div>


<?php
	}
}
?>
<br><br>
<div class=""><a href="<?php echo $url_home; ?>">Retour à l'accueil</a></div>
</div>
</div>
<?php include 'footer.php';?>
	</body>
</html>