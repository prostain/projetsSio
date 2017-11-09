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
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/css/bootstrap.min.css" integrity="sha384-/Y6pD6FV/Vv2HJnA6t+vslU6fwYXjCFtcEpHbNJ0lyAFsXTsjBbfaDjzALeQsN6M" crossorigin="anonymous">

</head>

<body class="index" >



<main class"size-main">



    <div class="col-md-6">

                    <!--Modal: Login & Register tabs-->
                    <div class="modal-dialog cascading-modal" role="document">
                        <!--Content-->
                        <div class="modal-content">

                            <!--Modal cascading tabs-->
                            <div class="modal-c-tabs">

                                <!-- Nav tabs -->
                                <ul class="nav nav-tabs tabs-2 light-blue darken-3" role="tablist">
                                    <li class="nav-item waves-effect waves-light">
                                        <a class="nav-link active" data-toggle="tab" href="#panel1" role="tab" aria-expanded="true"><i class="fa fa-user mr-1"></i> connexion</a>
                                    </li>
                                    <li class="nav-item waves-effect waves-light">
                                        <a class="nav-link" data-toggle="tab" href="#panel2" role="tab" aria-expanded="false"><i class="fa fa-user-plus mr-1"></i> inscription</a>
                                    </li>
                                </ul>

                                <!-- Tab panels -->
                                <div class="tab-content">
                                    <!--Panel 1-->
                                    <div class="tab-pane fade in active show" id="panel1" role="tabpanel" aria-expanded="true">

                                        <!--Body-->
                                        <div class="modal-body mb-1">
                                            <?php
/*          Utilisateur connecté
 *   déconnexion en supprimant les variables de session
 */

if(isset($_SESSION['email']))
{
    unset($_SESSION['email'], $_SESSION['idUser'], $_SESSION['role']);
    echo "<div class=\"bottomLeft message alignL\">Vous avez été déconnecté</div>";
}
else
{
    $email = '';

    // Traitement du formulaire 
    if(isset($_REQUEST['btn']))
    {
        $email = $cnx->escape_string($_REQUEST['email']);
        $pass = $_REQUEST['pass'];
        // récupération du mot de passe utilisateur
        $result = $cnx->query('select idUser, password, role, etatIns from utilisateur where email="'.$email.'"');
        if ($result=== false OR $result->num_rows<1) {
                $form = true;
                $message = 'Utilisateur inconnu';
        }
        else {
            $ligne = $result->fetch_array();
            $hash= $ligne['password'];
 $passverif=substr($hash,0,-1);


            // comparaison des mots de passe
            $validPassword = password_verify($ligne['password'] , $passverif);

            if ($passverif)
            {
                if($ligne['etatIns']>=1)
                {
                // utilisateur reconnu, pas de formulaire à afficher
                $form = false;
                // màj du username et identifiant dans la session
                $_SESSION['email'] = $_REQUEST['email'];
                $_SESSION['idUser'] = $ligne['idUser'];
                    $_SESSION['admin'] = $ligne['role'];
                
                echo "<div>Vous êtes connecté.</div>";
            }
     
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
        if(isset($message)) {
            echo '<div class="bottomLeft message alignL">'.$message.'</div>';
        }
        // Affichage du formulaire
?>
<div class="centreMiddle size3c border2 bg1 box2 centrage">
    <form action="" method="POST">
        <legend>Identifiants</legend> <br><br>
            <label for="email" ><pre class="alignL">email </pre></label>
            <input type="text" name="email" id="email" required autofocus><br><br><br>
            <label for="pass" class="alignL"><pre>Mot de passe</pre></label>
            <input type="password" name="pass" id="pass" required><br><br><br>
            <input type="submit" name="btn" value="Connection"><br><br>
        
    </form>
</div>
                                        </div>
                                        <?php
    }
}
?>
                                        <!--Footer-->
                                        <div class="modal-footer display-footer">
                                            <div class="options text-center text-md-right mt-1">
                                                <a href="<?php echo $url_home; ?>">Retour à l'accueil</a>
                                                <p>Not a member? <a href="#" class="blue-text">Sign Up</a></p>
                                                <p>Forgot <a href="#" class="blue-text">Password?</a></p>
                                            </div>
                                        
                                        </div>

                                    </div>
                                    <!--/.Panel 1-->

                                    <!--Panel 2-->
                                    <div class="tab-pane fade" id="panel2" role="tabpanel" aria-expanded="false">

                                        <!--Body-->
                                        <div class="modal-body">

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
                                        <?php } ?>
                                    </div>
                                    <!--/.Panel 2-->
                                </div>

                            </div>
                        </div>
                        <!--/.Content-->
                    </div>
                    <!--/Modal: Login & Register tabs-->

                </div>


 </main>
     <!--Footer-->
    <footer class="page-footer center-on-small-only">

  <?php include 'footer.php'; ?>

    </footer>
    <!--/.Footer-->


    <!-- SCRIPTS -->

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