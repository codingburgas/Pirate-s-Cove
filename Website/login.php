<?php

session_start();

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ERROR);
include_once "inc/raintpl/rain.tpl.class.php";
$install_path="";
$sm = new RainTPL();

//RAIN TPL ===============================================
raintpl::$tpl_dir = $install_path."templates/"; // template directory
raintpl::$cache_dir = $install_path."cache/"; // cache directory

if(isset($_GET["error"])) {
	if ($_GET["error"] == "invalidlogin") {
		$msg = "<p class='error'>Wrong email/password.</p>";
	}
}

$sm->assign("msg", $msg);	
$sm->assign("session",$_SESSION);
$sm->display("login.html");