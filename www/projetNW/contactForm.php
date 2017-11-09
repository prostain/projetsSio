<?php include 'connectBase.php'; ?>

<!DOCTYPE html>
<html lang="en" class="full-height">

<head>

    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta http-equiv="x-ua-compatible" content="ie=edge">

    <title>Material Design Bootstrap</title>

    <!-- Font Awesome -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">

    <!-- Bootstrap core CSS -->
    <link href="css/bootstrap.min.css" rel="stylesheet">

    <!-- Material Design Bootstrap -->
    <link href="css/mdb.min.css" rel="stylesheet">

    <link href="css/style.css" rel="stylesheet">

</head>

<body class="index" >

<div id="mainContent">
<?php
 if(isset($_POST['submit'])) {

      // qui nous permettra de savoir si une erreur de champ vide à été trouvé
   $error = false;
   // Vérification des champs vides

    $email = htmlspecialchars($_POST['email']);
   $objet = htmlspecialchars($_POST['objet']);
   $message = htmlspecialchars($_POST['message']);
$ip=$_SERVER['REMOTE_ADDR'];
}

?>
  <div id="formulaire_contact">

<form name='formulaire' action='' method='post'>
  <h3>Formulaire de contact</h3>
<table>
<tr><td>Votre email</td><td><input name='email' type='text' size='32'>
<?php if(filter_var($email, FILTER_VALIDATE_EMAIL) === FALSE) {
      echo "Votre email n'est pas valide!";
      $error = true;
   }
?></td></tr>
<tr><td>Le motif de votre message</td><td><SELECT name="objet" size="1">
    <OPTION>Partenariat
    <OPTION>Problème technique
    <OPTION>Renseignement
    <OPTION>Autre motif
    </SELECT>
<?php if(empty($objet)){
      echo "Veuillez indiquer votre nom!";
      $error = true;
   }
?>
</td></tr>
<tr><td>Votre message</td><td><textarea name='message' cols='25' rows='5'></textarea>
<?php if(empty($message)){
      echo "Veuillez saisir votre message!";
      $error = true;
   }
?>
</td></tr>
<tr><td>    </td><td><input name='annuler' type='reset' value='Annuler'><input name='submit' type='submit' value='Envoyer'></td></tr>
</table>
</form>

<?php  


 if($error == false) {
    if($cnx->query('insert into message( objet, email, message, ip) values ( "'.$objet.'", "'.$email.'", "'.$message.'", "'.$ip.'")'))
                        {
      echo "Votre message a bien été envoyé!";
      include 'mails/emailContactForm.php';
}
}
?>
</div>
    <!-- JQuery -->
    <script type="text/javascript" src="js/jquery-3.1.1.min.js"></script>

    <!-- Bootstrap dropdown -->
    <script type="text/javascript" src="js/popper.min.js"></script>

    <!-- Bootstrap core JavaScript -->
    <script type="text/javascript" src="js/bootstrap.min.js"></script>

    <!-- MDB core JavaScript -->
    <script type="text/javascript" src="js/mdb.min.js"></script>


</body>

</html>