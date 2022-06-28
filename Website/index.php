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

if(isset($_GET["mail"])) {
	if ($_GET["mail"] == "sended") {
		$msg = "<p class='mail-sended'>You have successfully sent us an email!</p>";
	}
}

$sm->assign("msg", $msg);
$sm->assign("session",$_SESSION);
$sm->display("index.html");