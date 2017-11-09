<?php 

/*
 * 		activation de la variable $_SESSION
 */
session_start();

/* 
 * 		connection à la base utilisateurs
 */
if (!($cnx = mysqli_connect("mysql.hostinger.fr", "u747752631_world", "Bushido1", "u747752631_new"))) {
	echo ("connection impossible ".$cnx->connect_error);
	return false;
}
	
$cnx->query("SET NAMES utf8");

/*  
 * 	variables de configuration
 */
 
 $url_home = "index.php";

?>
