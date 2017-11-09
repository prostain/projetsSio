<?php include 'connectBase.php'; ?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta http-equiv="x-ua-compatible" content="ie=edge">

    <title>New World</title>

    <!-- Font Awesome -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">

    <!-- Bootstrap core CSS -->
    <link href="css/bootstrap.min.css" rel="stylesheet">

    <!-- Material Design Bootstrap -->
    <link href="css/mdb.min.css" rel="stylesheet">

    <link href="css/style.css" rel="stylesheet">

<script>function validerMdp() {
if (document.monForm.password.value != document.monForm.passverif.value) {
document.getElementById("msg").innerHTML = "les deux mots de passe doivent êtrent identiques";

return false;

}

if (document.monForm.password.value.length < 8) {

document.getElementById("msg").innerHTML = "le mot de passe doit comporter au moins 6 caractères";

return false;

}

return true;

}
</script>
</head>
<body>
<main class="inscrip">
<?php include 'header.php'; ?>
<div class="topCentre sizeBandeau1 border2 bg1 box2 centrage"> 
		<h2>Inscription</h2>
	</div>
<?php
//On verifie que le formulaire a ete envoye
if(isset($_POST['email'],$_POST['password']))
{
	
	// Vérification de l'identité des pwd
	if($_POST['password']==$_POST['passverif']) {
		// vérification de la longueur du mot de passe
		if(strlen($_POST['password'])>=6) {
				// echappement des variables pour pouvoir les mettre dans une requette SQL
				$firstName = $_POST['firstName'];
				$lastName = $_POST['lastName'];
				$rue = $_POST['rue'];
				$cp = $_POST['cp'];
				$ville = $_POST['ville'];
				$tel = $_POST['tel'];
				$password = $_POST['password'];
				$password = password_hash($password, PASSWORD_DEFAULT);
				$email = $_POST['email'];
				$dateTime= date("Y-m-d H:i:s");
				$role= $_GET['role'];
				$ipUser = $_SERVER['REMOTE_ADDR'];
				// vérification de l'absence d'utilisateur inscrit sous ce pseudo
				$result = $cnx->query('select idUser from utilisateur where email="'.$email.'"');
				if ($result === false OR $result->num_rows < 1) {

						// enregistrement des informations
						if($cnx->query('insert into utilisateur( firstName, lastName, password, email, rue, cp, ville, tel, role, dateIns, ipUser) values ( "'.$firstName.'", "'.$lastName.'", "'.$password.'", "'.$email.'","'.$rue.'","'.$cp.'", "'.$ville.'", "'.$tel.'", "'.$role.'","'.$dateTime.'", "'.$ipUser.'")'))
						{
							$form = false;
							$message ="Vous avez été inscrit. Vous pouvez vous connecter";
							if($_GET["role"]=="client")
							{
								include 'mails/confirmInsClient.php';
							}
						}
						else {
							$form = true;
							$message = "Une erreur est survenue lors de l'inscription.";
						}
				}
				else {
					$form = true;
					$message = 'Identifiant déjà assigné.';
				}
		}
		else {
			$form = true;
			$message = 'Le mot de passe que vous avez entré contient moins de 8 caractères.';
		}
	}
	else {
		$form = true;
		$message = 'Les mots de passe que vous avez entré ne sont pas identiques.';
	}
}
else {
	$form = true;
}
if($form) {
	//On affiche un message sil y a lieu
	if(isset($message))
	{
			echo '<div class="bottomLeft message alignL">'.$message.'</div>';
	}
	//On affiche le formulaire
?>
<div class="card inscrip-size">
<div id="gauche" class="col-lg-8">
    <form action="#" method="POST">
        <fieldset><legend>Données de connexion</legend>
            <label for="lastName" class="alignL"><pre>Nom        </pre></label>
            <input type="text" name="lastName"><br>
            <label for="firstName" class="alignL"><pre>Prénom        </pre></label>
            <input type="text" name="firstName"><br>
            <label for="password" class="alignL"><pre>Mot de passe       </pre></label>
            <input type="password" name="password"  placeholder="8 caractères min."><br>
            <label for="passverif" class="alignL"><pre> Vérification du mot de passe      </pre></label>
            <input type="password" name="passverif" placeholder="vérification"><br>
            <label for="email" class="alignL"><pre>Email          </pre></label>
            <input type="text"  name="email">
            <label for="rue" class="rue"><pre>Rue        </pre></label>
            <input type="text" name="rue"><br>
            <label for="cp" class="alignL"><pre>Code postal        </pre></label>
            <input type="text" name="cp"><br>
            <label for="ville" class="alignL"><pre>Ville        </pre></label>
            <input type="text" name="ville"><br>
            <label for="tel" class="alignL"><pre>Téléphone        </pre></label>
            <input type="text" name="tel"><br>
            <input type="submit" class="alignR" value="Envoyer">
		</fieldset>
    </form>
</div>
</div>
<?php
}
?>

		<div class="bottomCentre size1 border2 bg1 box2 centrage"><a href="index.php">Retour à l'accueil</a></div>
</main>
<footer>
	<?php include 'footer.php'; ?>
</footer>
</body>
</html>

