<nav class="navbar navbar-expand-lg navbar-dark fixed-top scrolling-navbar">
    <div class="container">
        <a class="navbar-brand" href="#">NW</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav mr-auto">
                <li class="nav-item active">
                    <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="acheter.php">Acheter</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="produire.php">Produire</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="distribution.php">Distribuer</a>
                </li>
                
            </ul>

            <form class="form-inline">
<?php 
var_dump($_SESSION);
    
if(isset($_SESSION['email']))
{
?>
    <ul class="navbar-nav mr-auto">
                <li class="nav-item">
    <a class="connexion" href="deconnexion.php">déconnexion</a>;
                    </li>
            </ul>
<?php
}
else
{
?>
                <ul class="navbar-nav mr-auto">
                <li class="nav-item">
                    <a class="nav-link" href="register.php">Connection/Inscription</a>
                </li>
            </ul>
<?php
}
?>
            </form>
        </div>
    </div>
</nav>